#!/usr/bin/env node
/*
 * Deterministic workload generator for the Project X analyzer benchmark
 * harness. Writes benchmarks/workloads/workloads.json (the workload artifact
 * that both BEFORE and AFTER runs must consume unchanged) and prints a short
 * summary.
 *
 * Determinism: everything below is either a fixed literal or derived from the
 * recorded seed with a small local PRNG (mulberry32). Re-running this file
 * must reproduce workloads.json byte-for-byte, so before/after runs share
 * exactly the same inputs.
 */
import { writeFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..", "..");
const SEED = 20261017;

function mulberry32(seed) {
  let a = seed >>> 0;
  return function next() {
    a |= 0;
    a = (a + 0x6d2b79f5) | 0;
    let t = Math.imul(a ^ (a >>> 15), 1 | a);
    t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t;
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
  };
}

const scenarios = [];
const add = (scenario) => scenarios.push(scenario);

// ---------------------------------------------------------------------------
// 1. Typical valid inputs: the micro one-liner selections (exact snippets from
//    analyzer/test/micro-statements.test.ts). Adjudicated O(1)|O(1)|exact.
// ---------------------------------------------------------------------------
const expectConst = { time: "O(1)", space: "O(1)", confidence: "exact" };
add({
  id: "typical-selection",
  kind: "selection",
  description: "Typical micro one-liner selections (editor highlight-one-line flow)",
  coldRepeats: 3,
  warmRepeats: 5,
  cases: [
    ["typ-const-int", "int x = 10;"],
    ["typ-arith-fold", "int x = 10; int y = x * 2 + 7;"],
    ["typ-mod-hash", "long long h = 123; h = (h * 31 + 7) % 1000000007;"],
    ["typ-bit-ops", "int x = 123; x = (x << 3) | (x >> 1);"],
    ["typ-min-max", "int a = 3, b = 8; cout << max(a, b) - min(a, b);"],
    ["typ-swap", "int x = 1, y = 2; swap(x, y);"],
    ["typ-for-literal", "int s = 0; for (int i = 0; i < 10; ++i) s += i;"],
    ["typ-while-embedded", "int s = 0, i = 0; while (i < 5) { s += i++; }"],
    ["typ-vector-literal", "vector<int> v = {1, 2, 3}; int x = v[1];"],
    ["typ-vector-pop", "vector<int> v = {1, 2, 3}; v.pop_back();"],
    ["typ-vector-push", "vector<int> v; v.push_back(7); cout << v[0];"],
    ["typ-string-index", "string s = \"hello\"; cout << s[2];"]
  ].map(([id, source]) => ({ id, source, expect: expectConst }))
});

// ---------------------------------------------------------------------------
// 2. Boundary / minimal inputs. Some are deliberately under-specified
//    (undeclared locals) and only require graceful behavior (expect: null).
// ---------------------------------------------------------------------------
add({
  id: "boundary-one-liners",
  kind: "selection",
  description: "Minimal and boundary one-liner inputs, including degenerate selections",
  coldRepeats: 3,
  warmRepeats: 5,
  cases: [
    { id: "bnd-int-zero", source: "int x = 0;", expect: expectConst },
    { id: "bnd-int-long", source: "long long x = 10;", expect: expectConst },
    { id: "bnd-return-zero", source: "return 0;", expect: expectConst },
    { id: "bnd-bool", source: "bool b = true; return b;", expect: expectConst },
    { id: "bnd-overflow-literals", source: "int x = 2147483647; x += 1;", expect: expectConst },
    { id: "bnd-array-literal", source: "int arr[3] = {1, 2, 3}; return arr[0];", expect: expectConst },
    { id: "bnd-undeclared-increment", source: "x++;", expect: null },
    { id: "bnd-single-call", source: "cout << 42;", expect: expectConst }
  ]
});

// ---------------------------------------------------------------------------
// 3. Previously failing inputs: the exact shapes from the loop-progress and
//    initializer-list bug hunts (w4/w8/w9/w15..w23, t1/t3/t7/t8). These are the
//    regression corpus for BUG-001..BUG-005; expectations are adjudicated.
// ---------------------------------------------------------------------------
const nLoop = (body) => `int n; cin >> n; int i = 0, s = 0; while (i < n) { ${body} }`;
add({
  id: "previously-failing",
  kind: "selection",
  description: "Regression shapes: accumulator-as-driver, away-directions, embedded steps, initializer lists",
  coldRepeats: 3,
  warmRepeats: 5,
  cases: [
    { id: "pf-w4", source: nLoop("s += i; ++i;"), expect: { time: "O(n)", space: "O(1)", confidence: "exact" } },
    { id: "pf-w15", source: nLoop("s += i; i++;"), expect: { time: "O(n)", space: "O(1)", confidence: "exact" } },
    { id: "pf-w16", source: nLoop("s += i; i += 1;"), expect: { time: "O(n)", space: "O(1)", confidence: "exact" } },
    { id: "pf-w17", source: "int n; cin >> n; int i = 0, s = 0; while (i <= n) { s += i; ++i; }", expect: { time: "O(n)", space: "O(1)", confidence: "exact" } },
    { id: "pf-w8", source: "int i = 0; while (i < 5) { --i; }", expect: { time: "Unknown", space: null, confidence: "unknown" } },
    { id: "pf-w9", source: "int i = 0, x = 1; while (i < 5) { if (x) ++i; }", expect: { time: "O(1)", space: "O(1)", confidence: "exact" } },
    { id: "pf-w19", source: "int s = 0, i = 0; while (i < 5) { s += i++; }", expect: expectConst },
    { id: "pf-w20", source: nLoop("s += a19(i) + i++;"), expect: null },
    { id: "pf-w21", source: nLoop("s += i; --i;"), expect: { time: "Unknown", space: null, confidence: "unknown" } },
    { id: "pf-w22", source: "int n; cin >> n; int i = 0, s = 0; while (i > n) { s += i; ++i; }", expect: { time: "Unknown", space: null, confidence: "unknown" } },
    { id: "pf-w23", source: "int s = 0, i = 0; while (i < 5) { s += (i++); }", expect: expectConst },
    { id: "pf-t1", source: "vector<int> v = {1, 2, 3}; return (int)v.size();", expect: expectConst },
    { id: "pf-t3", source: "vector<int> v(3, 1); v.pop_back(); return (int)v.size();", expect: expectConst },
    { id: "pf-t7", source: "vector<int> v = {1, 2, 3}; v.pop_back(); return (int)v.size();", expect: expectConst },
    { id: "pf-t8", source: "int a[3] = {1, 2, 3}; return a[0];", expect: expectConst }
  ]
});

// ---------------------------------------------------------------------------
// 4. Adversarial / large shape stressors. Performance-focused (expect: null):
//    they exercise recursion depth, statement counts and expression widths.
// ---------------------------------------------------------------------------
const rnd = mulberry32(SEED);
void rnd; // reserved for future randomized shapes; patterns below are fixed
const deepNest = (() => {
  const lines = ["int advDeepNest() {", "  int s = 0;"];
  for (let d = 0; d < 12; d += 1) lines.push(`  ${"  ".repeat(d)}for (int i${d} = 0; i${d} < 3; ++i${d}) {`);
  lines.push(`  ${"  ".repeat(12)}s += i11 + i0;`);
  for (let d = 11; d >= 0; d -= 1) lines.push(`  ${"  ".repeat(d)}}`);
  lines.push("  return s;", "}");
  return lines.join("\n");
})();
const longChain = (() => {
  const lines = ["int advLongChain() {", "  int s = 0;"];
  for (let i = 0; i < 90; i += 1) lines.push(`  s += ${i + 1};`);
  lines.push("  return s;", "}");
  return lines.join("\n");
})();
const wideSwitch = (() => {
  const lines = ["int advWideSwitch() {", "  int x = 3;", "  int r = 0;", "  switch (x) {"];
  for (let i = 0; i < 50; i += 1) lines.push(`  case ${i}: r = ${i * 7}; break;`);
  lines.push("  default: r = -1; break;", "  }", "  return r;", "}");
  return lines.join("\n");
})();
const manyVars = (() => {
  const lines = ["int advManyVars() {", "  int s = 0;"];
  for (let i = 0; i < 200; i += 1) lines.push(`  int v${i} = ${i};`);
  for (let i = 0; i < 200; i += 5) lines.push(`  s += v${i};`);
  lines.push("  return s;", "}");
  return lines.join("\n");
})();
const bigArray = [
  "int advBigArray() {",
  "  int a[300];",
  "  for (int i = 0; i < 300; ++i) a[i] = i;",
  "  int s = 0;",
  "  for (int i = 0; i < 300; ++i) s += a[i];",
  "  return s;",
  "}"
].join("\n");
const ifChain = (() => {
  const lines = ["int advIfChain() {", "  int x = 40;", "  int s = 0;"];
  for (let i = 0; i < 80; i += 1) lines.push(`  if (x > ${i}) s += ${i};`);
  lines.push("  return s;", "}");
  return lines.join("\n");
})();
add({
  id: "adversarial-shapes",
  kind: "selection",
  description: "Pathological but valid shapes: deep nesting, long chains, wide switch, many locals",
  coldRepeats: 3,
  warmRepeats: 5,
  cases: [
    { id: "adv-deep-nest", source: deepNest, expect: null },
    { id: "adv-long-chain", source: longChain, expect: null },
    { id: "adv-wide-switch", source: wideSwitch, expect: null },
    { id: "adv-many-vars", source: manyVars, expect: null },
    { id: "adv-big-array", source: bigArray, expect: null },
    { id: "adv-if-chain", source: ifChain, expect: null }
  ]
});

// ---------------------------------------------------------------------------
// 5. Invalid-input handling: must never throw; graceful Unknown is acceptable.
// ---------------------------------------------------------------------------
add({
  id: "invalid-inputs",
  kind: "selection",
  description: "Malformed and degenerate inputs — required to fail gracefully, never crash",
  coldRepeats: 3,
  warmRepeats: 3,
  cases: [
    { id: "inv-empty", source: "", expect: null },
    { id: "inv-whitespace", source: "   \n\t  ", expect: null },
    { id: "inv-comment-only", source: "// just a comment\n", expect: null },
    { id: "inv-plain-text", source: "hello world", expect: null },
    { id: "inv-truncated", source: "int f(int n) { for (int i = 0; i < n; i++", expect: null },
    { id: "inv-bad-token", source: "int f() { return @; }", expect: null },
    { id: "inv-duplicate-decls", source: "int f() { return 1; } int f() { return 2; }", expect: null },
    { id: "inv-unicode-comment", source: "// \u4f60\u597d\nint f() { return 0; }", expect: null }
  ]
});

// ---------------------------------------------------------------------------
// 6. Large documents: one Clang parse, many functions (document flow).
// ---------------------------------------------------------------------------
function buildDocument(prefix, count) {
  const parts = ["#include <bits/stdc++.h>", "using namespace std;"];
  for (let i = 0; i < count; i += 1) {
    const shape = i % 6;
    if (shape === 0) parts.push(`int ${prefix}${i}() { int x = ${i}; return x * 3; }`);
    else if (shape === 1) parts.push(`int ${prefix}${i}(int n) { int s = 0; for (int j = 0; j < n; ++j) s += j; return s; }`);
    else if (shape === 2) parts.push(`int ${prefix}${i}(int n) { int j = 0, s = 0; while (j < n) { s += j; ++j; } return s; }`);
    else if (shape === 3) parts.push(`long long ${prefix}${i}(long long x) { long long r = 1; while (x > 0) { r *= x % 10; x /= 10; } return r; }`);
    else if (shape === 4) parts.push(`int ${prefix}${i}(int n) { vector<int> v; for (int j = 0; j < n; ++j) v.push_back(j); return (int)v.size(); }`);
    else parts.push(`int ${prefix}${i}(int n) { int s = 0; for (int j = 0; j < 5; ++j) s += j + n % (j + 1); return s; }`);
  }
  return parts.join("\n");
}
const doc120Symbols = Array.from({ length: 120 }, (_, i) => `doc120_f${i}`);
const doc300Symbols = Array.from({ length: 300 }, (_, i) => `doc300_f${i}`);
add({
  id: "large-document",
  kind: "document",
  description: "Whole-document analysis: one Clang parse, 120/300 functions per document",
  coldRepeats: 2,
  warmRepeats: 3,
  cases: [
    { id: "doc-120", source: buildDocument("doc120_f", 120), symbols: doc120Symbols, expect: null },
    { id: "doc-300", source: buildDocument("doc300_f", 300), symbols: doc300Symbols, expect: null }
  ]
});

// ---------------------------------------------------------------------------
// 7. Sustained-throughput stress: 60 different selections analyzed in sequence
//    (each cold once, then re-analyzed warm from the AST cache).
// ---------------------------------------------------------------------------
const stressCases = [];
for (let i = 0; i < 60; i += 1) {
  const k = (i % 10) + 1;
  const pattern = i % 5;
  if (pattern === 0) stressCases.push({ id: `st-${i}-scalar`, source: `int x = ${k}; int y = x * ${k} + 1;`, expect: expectConst });
  else if (pattern === 1) stressCases.push({ id: `st-${i}-for`, source: `int s = 0; for (int i = 0; i < ${10 + k}; ++i) s += i;`, expect: expectConst });
  else if (pattern === 2) stressCases.push({ id: `st-${i}-while`, source: `int s = 0, i = 0; while (i < ${5 + k}) { s += i++; }`, expect: expectConst });
  else if (pattern === 3) stressCases.push({ id: `st-${i}-vector`, source: `vector<int> v = {${k}, 2, 3}; return (int)v.size();`, expect: expectConst });
  else stressCases.push({ id: `st-${i}-symbolic`, source: nLoop("s += i; ++i;"), expect: { time: "O(n)", space: "O(1)", confidence: "exact" } });
}
add({
  id: "stress-throughput",
  kind: "selection",
  description: "Sustained throughput: 60 distinct selections, one cold + three warm analyses each",
  coldRepeats: 1,
  warmRepeats: 3,
  cases: stressCases
});

const spec = {
  version: 1,
  seed: SEED,
  generator: "benchmarks/workloads/generate.mjs",
  generatedFor: "Project-X analyzer before/after benchmark (task run)",
  scenarios
};
const outPath = join(root, "benchmarks", "workloads", "workloads.json");
writeFileSync(outPath, `${JSON.stringify(spec, null, 1)}\n`, "utf8");
let total = 0;
for (const scenario of scenarios) {
  total += scenario.cases.length;
  console.log(`${scenario.id}: ${scenario.cases.length} cases (${scenario.kind})`);
}
console.log(`total cases: ${total}`);
console.log(`written: ${outPath}`);
