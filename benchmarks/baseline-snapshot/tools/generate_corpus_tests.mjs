#!/usr/bin/env node

/**
 * Generates analyzer/test/corpus-lock.test.ts — a regression lock over the
 * reviewed corpus.
 *
 * Lock policy:
 *  - Asserted cases (engine answered and the profile + confidence match the
 *    label) are locked EXACTLY: any future change to time, space, or
 *    confidence fails the suite.
 *  - Abstention cases (label Unknown, engine abstained) are locked SOUNDLY:
 *    the engine may either keep abstaining or start answering with a profile
 *    that MATCHES the label — it must never assert a different bound.
 *
 * Regenerate after intentional engine changes with:
 *   node tools/generate_corpus_tests.mjs
 */
import { readdirSync, readFileSync, writeFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const datasetsDir = join(root, "datasets");
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const { analyseCppFunctionsInDocument } = await import(pathToFileURL(join(root, "analyzer", "dist", "index.js")).href);
const { parseBound, boundsEqual } = await import(pathToFileURL(join(root, "analyzer", "dist", "bound.js")).href);

function equivalent(left, right) {
  if (left === right) return true;
  try {
    const a = parseBound(left);
    const b = parseBound(right);
    if (a && b && boundsEqual(a, b)) return true;
  } catch {}
  const norm = (v) => /^O\((.*)\)$/.exec(v)?.[1]?.replace(/\s+/g, "").replace(/[·*]/g, "");
  const l = norm(left);
  const r = norm(right);
  return l !== undefined && l === r;
}

// Only manifests whose labels have been audited join the lock. The axis
// families (generated, first-principles labels) and the authored families are
// audited; the un-adjudicated derived packs are excluded (documented noise).
const AUDITED_PREFIXES = ["cpp-axis-", "cpp-core", "cpp-dp", "cpp-graphs", "cpp-adversarial",
  "cpp-composition", "cpp-binary-search", "cpp-two-pointers", "cpp-stl", "cpp-trees",
  "cpp-recursion", "cpp-number-theory", "cpp-graph-algorithms", "cpp-call-composition",
  "cpp-advanced-graphs", "cpp-range-for", "cpp-amortized", "cpp-recurrence", "cpp-micro", "new10", "cf-batch"];

const manifests = readdirSync(datasetsDir)
  .filter((n) => n.endsWith(".manifest.json"))
  .filter((n) => AUDITED_PREFIXES.some((p) => n.startsWith(p)))
  .sort();

const suites = [];
for (const name of manifests) {
  const manifest = JSON.parse(readFileSync(join(datasetsDir, name), "utf8"));
  const source = readFileSync(join(datasetsDir, name.replace(".manifest.json", ".cpp")), "utf8");
  const symbols = manifest.cases.map((c) => c.symbol);
  const results = analyseCppFunctionsInDocument(source, symbols);
  const locked = [];
  for (const testCase of manifest.cases) {
    const actual = results.get(testCase.symbol);
    if (!actual) continue;
    const abstained = actual.confidence === "unknown" || actual.worstCaseTime === "Unknown";
    const profileOk = equivalent(actual.worstCaseTime, testCase.time) && equivalent(actual.auxiliarySpace, testCase.space);
    if (testCase.confidence === "unknown") {
      // Sound abstention lock: keep abstaining, or answer correctly.
      if (abstained) locked.push({ kind: "abstain", testCase });
      else if (profileOk) locked.push({ kind: "abstain", testCase });
      continue;
    }
    if (abstained) continue;
    if (!profileOk) continue;
    if (actual.confidence !== testCase.confidence) continue;
    locked.push({ kind: "exact", testCase });
  }
  if (locked.length > 0) suites.push({ name, source, locked });
}

const total = suites.reduce((sum, s) => sum + s.locked.length, 0);
const lines = [];
lines.push("/**");
lines.push(" * AUTO-GENERATED regression lock over the reviewed corpus — DO NOT EDIT.");
lines.push(` * ${total} locked cases across ${suites.length} manifests.`);
lines.push(" * Regenerate after intentional engine changes:");
lines.push(" *   node tools/generate_corpus_tests.mjs");
lines.push(" *");
lines.push(" * Lock policy:");
lines.push(" *  - exact: time, space, and confidence are pinned. Any drift fails.");
lines.push(" *  - abstain: the engine must keep abstaining or answer with the");
lines.push(" *    labeled profile; asserting a DIFFERENT bound fails (soundness).");
lines.push(" */");
lines.push('import assert from "node:assert/strict";');
lines.push('import { existsSync, readFileSync } from "node:fs";');
lines.push('import { dirname, join } from "node:path";');
lines.push('import { fileURLToPath } from "node:url";');
lines.push('import test, { describe } from "node:test";');
lines.push('import { analyseCppFunctionsInDocument } from "../src/index.js";');
lines.push('import { equivalent } from "./helpers/bound-equivalence.js";');
lines.push("");
lines.push('const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\\\Program Files\\\\LLVM\\\\bin\\\\clang++.exe";');
lines.push("const datasetsDir = join(dirname(fileURLToPath(import.meta.url)), \"..\", \"..\", \"datasets\");");
lines.push("const clangAvailable = existsSync(clangPath);");
lines.push("");
lines.push("function profileMatches(actual, label) {");
lines.push("  return actual.worstCaseTime === label.time && actual.auxiliarySpace === label.space;");
lines.push("}");
lines.push("");

let suiteIndex = 0;
for (const suite of suites) {
  const varName = `results_${suiteIndex}`;
  const cppFile = suite.name.replace(".manifest.json", ".cpp");
  lines.push(`describe("corpus lock: ${suite.name}", { skip: !clangAvailable }, () => {`);
  lines.push(`  process.env.PROJECT_X_CLANG = clangPath;`);
  lines.push(`  const cases = ${JSON.stringify(suite.locked.map(({ kind, testCase }) => ({ kind, id: testCase.id, symbol: testCase.symbol, time: testCase.time, space: testCase.space, confidence: testCase.confidence })))};`);
  lines.push(`  const results = new Map<string, import("../src/model.js").AnalysisResult>();`);
  lines.push(`  test("setup: parse ${cppFile}", () => {`);
  lines.push(`    const source = readFileSync(join(datasetsDir, ${JSON.stringify(cppFile)}), "utf8");`);
  lines.push(`    const analysis = analyseCppFunctionsInDocument(source, cases.map((c) => c.symbol));`);
  lines.push(`    for (const [symbol, value] of analysis) results.set(symbol, value);`);
  lines.push(`    assert.equal(analysis.size > 0 || cases.length === 0, true);`);
  lines.push("  });");
  for (const { kind, testCase } of suite.locked) {
    if (kind === "exact") {
      lines.push(`  test("${testCase.id}", () => {`);
      lines.push(`    const actual = results.get(${JSON.stringify(testCase.symbol)})!;`);
      lines.push(`    assert.ok(equivalent(actual.worstCaseTime, ${JSON.stringify(testCase.time)}), "time drift");`);
      lines.push(`    assert.ok(equivalent(actual.auxiliarySpace, ${JSON.stringify(testCase.space)}), "space drift");`);
      lines.push(`    assert.equal(actual.confidence, ${JSON.stringify(testCase.confidence)});`);
      lines.push("  });");
    } else {
      lines.push(`  test("${testCase.id} stays sound", () => {`);
      lines.push(`    const actual = results.get(${JSON.stringify(testCase.symbol)})!;`);
      lines.push(`    if (actual.confidence === "unknown") return;`);
      lines.push(`    assert.ok(profileMatches(actual, ${JSON.stringify({ time: testCase.time, space: testCase.space })}), \`asserted \${actual.worstCaseTime}/\${actual.auxiliarySpace} against an Unknown label\`);`);
      lines.push("  });");
    }
  }
  lines.push("});");
  lines.push("");
  suiteIndex += 1;
}

writeFileSync(join(root, "analyzer", "test", "corpus-lock.test.ts"), lines.join("\n") + "\n");
console.log(`corpus lock written: ${total} cases across ${suites.length} manifests`);
