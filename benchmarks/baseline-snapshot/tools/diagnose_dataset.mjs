#!/usr/bin/env node

/**
 * Failure-mode diagnostic for the reviewed Project X corpora.
 * Groups every abstention by its first proof reason and every confident
 * mismatch by failure kind, then ranks the buckets by frequency so engine
 * work targets the largest real-world coverage loss first.
 */
import { readdirSync, readFileSync, writeFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const datasetsDir = join(root, "datasets");
const jsonOut = process.argv.find((argument) => argument.startsWith("--out="))?.slice("--out=".length);
const requestedPrefix = process.argv.find((argument) => argument.startsWith("--prefix="))?.slice("--prefix=".length);
const devOnly = process.argv.includes("--dev");
const holdoutOnly = process.argv.includes("--holdout");
const analyzerPath = pathToFileURL(join(root, "analyzer", "dist", "index.js")).href;
const boundPath = pathToFileURL(join(root, "analyzer", "dist", "bound.js")).href;

const typicalWindowsClang = "C:\\Program Files\\LLVM\\bin\\clang++.exe";
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = typicalWindowsClang;

const { analyseCppFunctionsInDocument } = await import(analyzerPath);
const { parseBound, boundsEqual } = await import(boundPath);

const holdoutManifests = new Set(readFileSync(join(datasetsDir, "holdout-manifests.txt"), "utf8")
  .split(/\r?\n/)
  .map((line) => line.trim())
  .filter((line) => line && !line.startsWith("#")));
const manifestFilter = devOnly ? ((name) => !holdoutManifests.has(name))
  : holdoutOnly ? ((name) => holdoutManifests.has(name))
  : ((name) => true);
const manifests = readdirSync(datasetsDir)
  .filter((name) => name.endsWith(".manifest.json"))
  .filter(manifestFilter)
  .filter((name) => !requestedPrefix || name.startsWith(requestedPrefix))
  .sort();

/** Collapses a proof sentence into a stable bucket key. */
function reasonBucket(reason) {
  const text = (reason ?? "No proof provided").toLowerCase();
  const rules = [
    [/loop bound/, "loop bound not proven"],
    [/canonical form/, "loop bound not proven"],
    [/geometric/, "loop bound not proven"],
    [/non-terminat/, "non-terminating loop shape"],
    [/unresolved call|unsupported call|unknown call/, "unresolved call cost"],
    [/allocation|CXXNewExpr|new expression/, "unsupported allocation"],
    [/recursion|recursive/, "recursion not proven"],
    [/memo|cache/, "memoization not proven"],
    [/branch|incomparable|cfg/, "incomparable CFG branches"],
    [/alias|pointer/, "aliasing not proven"],
    [/lambda/, "lambda not proven"],
    [/selection did not resolve|no analyzable body/, "selection did not resolve to a function"],
    [/space|auxiliary/, "auxiliary space not proven"],
    [/break/, "break inside loop"],
    [/range-for|range for/, "range-for not proven"],
    [/stream|cin|cout/, "stream I/O shape"]
  ];
  for (const [pattern, bucket] of rules) if (pattern.test(text)) return bucket;
  return `other: ${text.slice(0, 80)}`;
}

const totals = { cases: 0, abstained: 0, assertedCorrect: 0, assertedWrong: 0, matched: 0 };
const abstentionBuckets = new Map();
const mismatchKinds = new Map();
const mismatchExamples = new Map();
const perManifest = [];

function normalizedBigO(value) {
  const body = /^O\((.*)\)$/.exec(value)?.[1];
  if (body === undefined) return value;
  const sequenceDimensions = new Map();
  let nextDimension = 0;
  const canonical = body.replace(/\|([A-Za-z_][A-Za-z0-9_]*)\|/g, (_, name) => {
    if (!sequenceDimensions.has(name)) sequenceDimensions.set(name, ["n", "m", "q", "t"][nextDimension++] ?? name);
    return sequenceDimensions.get(name);
  });
  let normalized = canonical.replace(/\s+/g, "").replace(/[·*]/g, "");
  if (normalized.includes("+")) normalized = normalized.split("+").sort().join("+");
  return `O(${normalized})`;
}

function complexityEquivalent(left, right) {
  if (left === right) return true;
  try {
    const leftBound = parseBound(left);
    const rightBound = parseBound(right);
    if (leftBound && rightBound && boundsEqual(leftBound, rightBound)) return true;
  } catch {
    // Fall through to presentation comparison.
  }
  return normalizedBigO(left) === normalizedBigO(right);
}

const bump = (map, key) => map.set(key, (map.get(key) ?? 0) + 1);

for (const manifestName of manifests) {
  const manifest = JSON.parse(readFileSync(join(datasetsDir, manifestName), "utf8"));
  const source = readFileSync(join(datasetsDir, manifestName.replace(".manifest.json", ".cpp")), "utf8");
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((testCase) => testCase.symbol));
  const manifestStats = { name: manifestName, cases: 0, abstained: 0, wrong: 0 };
  for (const testCase of manifest.cases) {
    totals.cases += 1;
    manifestStats.cases += 1;
    const actual = results.get(testCase.symbol);
    if (!actual) throw new Error(`No analyzer result returned for ${testCase.symbol}.`);
    const abstained = actual.confidence === "unknown" || actual.worstCaseTime === "Unknown";
    const profileMatched = complexityEquivalent(actual.worstCaseTime, testCase.time)
      && complexityEquivalent(actual.auxiliarySpace, testCase.space);
    const matched = profileMatched && actual.confidence === testCase.confidence;
    if (matched) totals.matched += 1;
    if (abstained) {
      totals.abstained += 1;
      manifestStats.abstained += 1;
      const bucket = reasonBucket(actual.proof[0]);
      bump(abstentionBuckets, bucket);
      const examples = abstentionBuckets.get(bucket + "\u0000examples") ?? [];
      if (examples.length < 3) examples.push(`${testCase.id} (${manifestName})`);
      abstentionBuckets.set(bucket + "\u0000examples", examples);
    } else if (matched) {
      totals.assertedCorrect += 1;
    } else {
      totals.assertedWrong += 1;
      manifestStats.wrong += 1;
      const timeWrong = !complexityEquivalent(actual.worstCaseTime, testCase.time);
      const spaceWrong = !complexityEquivalent(actual.auxiliarySpace, testCase.space);
      const confidenceWrong = actual.confidence !== testCase.confidence;
      const kinds = [
        timeWrong ? "time value wrong" : null,
        spaceWrong ? "space value wrong" : null,
        !timeWrong && !spaceWrong && confidenceWrong ? `confidence ${testCase.confidence} -> ${actual.confidence}` : null,
        timeWrong && spaceWrong ? "(both)" : null
      ].filter(Boolean);
      const key = kinds.join(" + ");
      bump(mismatchKinds, key);
      if (!mismatchExamples.has(key)) mismatchExamples.set(key, []);
      const examples = mismatchExamples.get(key);
      if (examples.length < 4) examples.push(`${testCase.id}: expected ${testCase.time}/${testCase.space}/${testCase.confidence}, got ${actual.worstCaseTime}/${actual.auxiliarySpace}/${actual.confidence} (${manifestName})`);
    }
  }
  perManifest.push(manifestStats);
}

const percentage = (numerator, denominator) => denominator === 0 ? "n/a" : `${((100 * numerator) / denominator).toFixed(1)}%`;

console.log(`Cases: ${totals.cases}  matched: ${totals.matched} (${percentage(totals.matched, totals.cases)})`);
console.log(`Abstentions (Unknown): ${totals.abstained} (${percentage(totals.abstained, totals.cases)})`);
console.log(`Asserted precision: ${percentage(totals.assertedCorrect, totals.assertedCorrect + totals.assertedWrong)} (${totals.assertedCorrect}/${totals.assertedCorrect + totals.assertedWrong})`);
console.log(`\n== Abstention buckets (by first proof reason) ==`);
for (const [bucket, count] of [...abstentionBuckets.entries()].filter(([key]) => !key.includes("\u0000")).sort((a, b) => b[1] - a[1])) {
  console.log(`${String(count).padStart(5)}  ${bucket}`);
  for (const example of abstentionBuckets.get(bucket + "\u0000examples") ?? []) console.log(`          e.g. ${example}`);
}
console.log(`\n== Confident mismatch kinds ==`);
for (const [kind, count] of [...mismatchKinds.entries()].sort((a, b) => b[1] - a[1])) {
  console.log(`${String(count).padStart(5)}  ${kind}`);
  for (const example of mismatchExamples.get(kind) ?? []) console.log(`          ${example}`);
}
console.log(`\n== Weakest manifests (by abstention rate, min 3 cases) ==`);
for (const stats of perManifest.filter((stats) => stats.cases >= 3).sort((a, b) => (b.abstained / b.cases) - (a.abstained / a.cases)).slice(0, 15)) {
  console.log(`${String(stats.abstained).padStart(4)}/${String(stats.cases).padStart(4)} unknown, ${String(stats.wrong).padStart(3)} wrong  ${stats.name}`);
}

if (jsonOut) {
  writeFileSync(jsonOut, JSON.stringify({ totals, abstentions: Object.fromEntries([...abstentionBuckets.entries()].filter(([key]) => !key.includes("\u0000"))), mismatches: Object.fromEntries(mismatchKinds) }, null, 2));
  console.log(`\nJSON report written to ${jsonOut}`);
}
