#!/usr/bin/env node

/**
 * Offline selective-precision benchmark for reviewed Project X corpora.
 * Unknown is an abstention, not a correct exact prediction. Precision is
 * calculated only among asserted results; coverage reports proof reach.
 */
import { readdirSync, readFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const datasetsDir = join(root, "datasets");
const strict = process.argv.includes("--strict");
const verbose = process.argv.includes("--verbose");
const summaryOnly = process.argv.includes("--summary");
const devOnly = process.argv.includes("--dev");
const holdoutOnly = process.argv.includes("--holdout");
const requestedManifest = process.argv.find((argument) => argument.startsWith("--manifest="))?.slice("--manifest=".length);
const requestedPrefix = process.argv.find((argument) => argument.startsWith("--prefix="))?.slice("--prefix=".length);
const shardArgument = process.argv.find((argument) => argument.startsWith("--shard="))?.slice("--shard=".length);
const shard = (() => {
  if (!shardArgument) return undefined;
  const match = /^(\d+)\/(\d+)$/.exec(shardArgument);
  if (!match) throw new Error("--shard must use zero-based INDEX/TOTAL form, for example --shard=0/4");
  const index = Number(match[1]);
  const total = Number(match[2]);
  if (!Number.isInteger(index) || !Number.isInteger(total) || total < 1 || index < 0 || index >= total) throw new Error("--shard index must be within its positive total");
  return { index, total };
})();
const analyzerPath = pathToFileURL(join(root, "analyzer", "dist", "index.js")).href;
const boundPath = pathToFileURL(join(root, "analyzer", "dist", "bound.js")).href;

// Keep the offline benchmark usable from a fresh PowerShell, matching the
// extension's documented Windows LLVM auto-detection.
const typicalWindowsClang = "C:\\Program Files\\LLVM\\bin\\clang++.exe";
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = typicalWindowsClang;

let analyseCppFunctionsInDocument;
let parseBound;
let boundsEqual;
try {
  ({ analyseCppFunctionsInDocument } = await import(analyzerPath));
  ({ parseBound, boundsEqual } = await import(boundPath));
} catch (error) {
  console.error("Could not load analyzer/dist/index.js. Run npm run build first.");
  console.error(error instanceof Error ? error.message : String(error));
  process.exitCode = 2;
  process.exit();
}

const selectedManifests = readdirSync(datasetsDir)
  .filter((name) => name.endsWith(".manifest.json"))
  .filter((name) => !requestedManifest || name === requestedManifest)
  .filter((name) => !requestedPrefix || name.startsWith(requestedPrefix))
  .sort();
// The locked family-split holdout (tools/holdout_split.py) is excluded from
// development iterations via --dev and measured in isolation via --holdout.
const holdoutManifests = new Set(readFileSync(join(datasetsDir, "holdout-manifests.txt"), "utf8")
  .split(/\r?\n/)
  .map((line) => line.trim())
  .filter((line) => line && !line.startsWith("#")));
const manifestFilter = devOnly ? ((name) => !holdoutManifests.has(name))
  : holdoutOnly ? ((name) => holdoutManifests.has(name))
  : ((name) => true);
const manifests = shard ? selectedManifests.filter(manifestFilter).filter((_, index) => index % shard.total === shard.index) : selectedManifests.filter(manifestFilter);
if (manifests.length === 0) {
  console.error(requestedManifest
    ? `No manifest named ${requestedManifest} was found in datasets/.`
      : requestedPrefix
        ? `No manifests beginning with ${requestedPrefix} were found in datasets/.`
    : "No dataset manifests were found.");
  process.exitCode = 2;
  process.exit();
}
const confidenceRank = { exact: 2, estimated: 1, unknown: 0 };
const totals = {
  cases: 0,
  matched: 0,
  profileMatched: 0,
  evidenceCompatible: 0,
  abstained: 0,
  assertedCorrect: 0,
  assertedWrong: 0,
  underclaimed: 0
};
const failures = [];

/**
 * Compare presentation-equivalent Big-O products without weakening the
 * benchmark's semantic checks. In particular historic manifests use `O(nm)`
 * while the symbolic engine prints `O(n m)`. This does not equate different
 * dimensions, sums, exponents, or logarithms; it only normalizes product
 * separators and the unambiguous one-letter CP dimensions.
 */
function normalizedBigO(value) {
  const body = /^O\((.*)\)$/.exec(value)?.[1];
  if (body === undefined) return value;
  // Dataset authors naturally write string dimensions as |s| / |t| while
  // the analyzer uses its language-independent n / m symbols. Canonicalize
  // those presentation aliases by first appearance; this does not equate
  // different dimensions or alter any exponent/logarithm semantics.
  const sequenceDimensions = new Map();
  let nextDimension = 0;
  let canonical = body.replace(/\|([A-Za-z_][A-Za-z0-9_]*)\|/g, (_, name) => {
    if (!sequenceDimensions.has(name)) sequenceDimensions.set(name, ["n", "m", "q", "t"][nextDimension++] ?? name);
    return sequenceDimensions.get(name);
  });
  // Presentation aliases for the same growth rate: the square-root radical
  // and the golden-ratio constant are spellings of 1.618..., not different
  // bounds. The engine emits sqrt n / 1.618^n canonically.
  canonical = canonical.replace(/√\s*/g, "sqrt ").replace(/phi\^/g, "1.618^");
  // Graph conventions name the vertex/edge dimensions V and E; the engine
  // prints the first two container dimensions n and m unless the parameters
  // are literally named V/E. The spellings denote the same dimensions.
  canonical = canonical.replace(/\bV\b/g, "n").replace(/\bE\b/g, "m");
  let normalized = canonical.replace(/\s+/g, "").replace(/[·*]/g, "");
  // Sequential Big-O sums are commutative: O(n + q) and O(q + n) describe
  // the same profile. Keep this presentation normalization separate from the
  // analyzer so the benchmark never penalizes a proven result for term order.
  if (normalized.includes("+")) normalized = normalized.split("+").sort().join("+");
  return `O(${normalized})`;
}

function sameComplexity(left, right) {
  if (left === right) return true;
  // Semantic comparison first: the canonical algebra equates equivalent
  // spellings such as O((n + q) log n) and O(n log n + q log n) without
  // ever equating different dimensions, exponents, or logarithms.
  try {
    const leftBound = typeof parseBound === "function" ? parseBound(left) : undefined;
    const rightBound = typeof parseBound === "function" ? parseBound(right) : undefined;
    if (leftBound && rightBound && boundsEqual(leftBound, rightBound)) return true;
  } catch {
    // Fall through to presentation comparison.
  }
  return normalizedBigO(left) === normalizedBigO(right);
}

for (const manifestName of manifests) {
  const manifestPath = join(datasetsDir, manifestName);
  const sourcePath = join(datasetsDir, manifestName.replace(".manifest.json", ".cpp"));
  const manifest = JSON.parse(readFileSync(manifestPath, "utf8"));
  const source = readFileSync(sourcePath, "utf8");
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((testCase) => testCase.symbol));
  for (const testCase of manifest.cases) {
    totals.cases += 1;
    const actual = results.get(testCase.symbol);
    if (!actual) throw new Error(`No analyzer result returned for ${testCase.symbol}.`);
    const expected = { time: testCase.time, space: testCase.space, confidence: testCase.confidence };
    const profileMatched = sameComplexity(actual.worstCaseTime, expected.time)
      && sameComplexity(actual.auxiliarySpace, expected.space);
    const matched = profileMatched
      && actual.confidence === expected.confidence;
    const abstained = actual.confidence === "unknown" || actual.worstCaseTime === "Unknown";
    // A softer-but-correct answer (estimated where the label says exact) is
    // an underclaim, not a wrong assertion: the product promise is that a
    // published answer is never false.
    const underclaimed = profileMatched && !abstained
      && (confidenceRank[actual.confidence] ?? 0) < (confidenceRank[expected.confidence] ?? 0);
    if (matched) totals.matched += 1;
    if (profileMatched) totals.profileMatched += 1;
    if (profileMatched && !abstained) totals.evidenceCompatible += 1;
    if (abstained) totals.abstained += 1;
    else if (matched) totals.assertedCorrect += 1;
    else if (underclaimed) totals.underclaimed += 1;
    else totals.assertedWrong += 1;
    if (!matched && !(profileMatched
      && (confidenceRank[actual.confidence] ?? 0) < (confidenceRank[expected.confidence] ?? 0))) {
      failures.push({
        id: testCase.id,
        symbol: testCase.symbol,
        expected: `${expected.time}; ${expected.space}; ${expected.confidence}`,
        actual: `${actual.worstCaseTime}; ${actual.auxiliarySpace}; ${actual.confidence}`,
        reason: actual.proof[0] ?? "No proof provided"
      });
    }
  }
}

const percentage = (numerator, denominator) => denominator === 0 ? "n/a" : `${((100 * numerator) / denominator).toFixed(1)}%`;
console.log(`Reviewed cases: ${totals.cases}`);
console.log(`Exact manifest matches: ${totals.matched}`);
console.log(`Time/space profile matches (confidence-independent): ${percentage(totals.profileMatched, totals.cases)} (${totals.profileMatched}/${totals.cases})`);
console.log(`Evidence-compatible profile matches: ${percentage(totals.evidenceCompatible, totals.cases)} (${totals.evidenceCompatible}/${totals.cases})`);
console.log(`Asserted-result precision: ${percentage(totals.assertedCorrect, totals.assertedCorrect + totals.assertedWrong)} (${totals.assertedCorrect}/${totals.assertedCorrect + totals.assertedWrong})`);
console.log(`Underclaimed (correct profile, softer confidence): ${totals.underclaimed}`);
console.log(`Coverage (non-Unknown): ${percentage(totals.cases - totals.abstained, totals.cases)} (${totals.cases - totals.abstained}/${totals.cases})`);
console.log(`Abstentions (Unknown): ${totals.abstained}`);
console.log(`Confident mismatches: ${totals.assertedWrong}`);

if (!summaryOnly) {
  const reported = verbose ? failures : failures.slice(0, 20);
  for (const failure of reported) {
    console.log(`\n${failure.id} (${failure.symbol})`);
    console.log(`  expected: ${failure.expected}`);
    console.log(`  actual:   ${failure.actual}`);
    console.log(`  reason:   ${failure.reason}`);
  }
  if (!verbose && failures.length > reported.length) console.log(`\n... ${failures.length - reported.length} additional mismatch(es); pass --verbose to show all.`);
}
if (strict && totals.assertedWrong > 0) process.exitCode = 1;
