#!/usr/bin/env node
/*
 * Compares two benchmarks/harness/bench.mjs result files (BEFORE vs AFTER),
 * recomputes latency statistics from the raw per-case samples, and writes
 * benchmarks/results/comparison.csv plus a human-readable comparison.md.
 *
 * Usage:
 *   node benchmarks/harness/compare.mjs \
 *     --before=benchmarks/results/perf-before.json \
 *     --after=benchmarks/results/perf-after.json
 */
import { mkdirSync, readFileSync, writeFileSync } from "node:fs";
import { dirname, resolve } from "node:path";
import { fileURLToPath } from "node:url";

const harnessDir = dirname(fileURLToPath(import.meta.url));
const root = resolve(harnessDir, "..", "..");
const args = process.argv.slice(2);
const option = (name, fallback) => {
  const found = args.find((argument) => argument.startsWith(`--${name}=`));
  return found ? found.slice(name.length + 3) : fallback;
};

const before = JSON.parse(readFileSync(resolve(root, option("before", "benchmarks/results/perf-before.json")), "utf8"));
const after = JSON.parse(readFileSync(resolve(root, option("after", "benchmarks/results/perf-after.json")), "utf8"));
const csvPath = resolve(root, option("csv", "benchmarks/results/comparison.csv"));
const mdPath = resolve(root, option("md", "benchmarks/results/comparison.md"));

if (before.workloadSeed !== after.workloadSeed || before.workloadFile !== after.workloadFile) {
  console.error("REFUSING to compare: the two runs did not use the same workload definition.");
  console.error(`before: ${before.workloadFile} (seed ${before.workloadSeed})`);
  console.error(`after:  ${after.workloadFile} (seed ${after.workloadSeed})`);
  process.exit(2);
}

const stats = (values) => {
  if (values.length === 0) return { n: 0, median: null, mean: null, p95: null, min: null, max: null };
  const sorted = [...values].sort((a, b) => a - b);
  const sum = sorted.reduce((acc, value) => acc + value, 0);
  const pick = (q) => sorted[Math.min(sorted.length - 1, Math.floor(q * sorted.length))];
  return {
    n: sorted.length,
    min: sorted[0],
    median: sorted.length % 2 === 1 ? sorted[(sorted.length - 1) / 2] : (sorted[sorted.length / 2 - 1] + sorted[sorted.length / 2]) / 2,
    mean: sum / sorted.length,
    p95: pick(0.95),
    max: sorted[sorted.length - 1]
  };
};
const deltaPct = (beforeValue, afterValue) => {
  if (beforeValue === null || afterValue === null || beforeValue === 0) return null;
  return ((beforeValue - afterValue) / beforeValue) * 100;
};
const fmt = (value, digits = 2) => (value === null || value === undefined ? "n/a" : Number(value).toFixed(digits));
const fmtPct = (value) => (value === null ? "n/a" : `${value >= 0 ? "+" : ""}${value.toFixed(1)}%`);

const rows = [];
for (const scenario of before.scenarios) {
  const other = after.scenarios.find((entry) => entry.scenario === scenario.scenario);
  if (!other) {
    console.error(`scenario missing from AFTER run: ${scenario.scenario}`);
    process.exit(2);
  }
  const coldBefore = scenario.cases.flatMap((entry) => entry.cold);
  const coldAfter = other.cases.flatMap((entry) => entry.cold);
  const warmBefore = scenario.cases.flatMap((entry) => entry.warm);
  const warmAfter = other.cases.flatMap((entry) => entry.warm);
  const beforeCold = stats(coldBefore);
  const afterCold = stats(coldAfter);
  const beforeWarm = stats(warmBefore);
  const afterWarm = stats(warmAfter);
  rows.push({
    scenario: scenario.scenario,
    cases: scenario.summary.cases,
    coldBefore, coldAfter, beforeCold, afterCold, beforeWarm, afterWarm,
    coldDeltaPct: deltaPct(beforeCold.median, afterCold.median),
    warmDeltaPct: deltaPct(beforeWarm.median, afterWarm.median),
    rssBefore: scenario.maxRssKb,
    rssAfter: other.maxRssKb,
    rssDeltaPct: deltaPct(scenario.maxRssKb, other.maxRssKb),
    matchedBefore: scenario.summary.matched,
    judgedBefore: scenario.summary.judged,
    matchedAfter: other.summary.matched,
    judgedAfter: other.summary.judged,
    errorsBefore: scenario.summary.errors,
    errorsAfter: other.summary.errors
  });
}

const overallColdBefore = stats(before.scenarios.flatMap((scenario) => scenario.cases.flatMap((entry) => entry.cold)));
const overallColdAfter = stats(after.scenarios.flatMap((scenario) => scenario.cases.flatMap((entry) => entry.cold)));
const overallWarmBefore = stats(before.scenarios.flatMap((scenario) => scenario.cases.flatMap((entry) => entry.warm)));
const overallWarmAfter = stats(after.scenarios.flatMap((scenario) => scenario.cases.flatMap((entry) => entry.warm)));
const totalJudgedBefore = rows.reduce((acc, row) => acc + row.judgedBefore, 0);
const totalMatchedBefore = rows.reduce((acc, row) => acc + row.matchedBefore, 0);
const totalJudgedAfter = rows.reduce((acc, row) => acc + row.judgedAfter, 0);
const totalMatchedAfter = rows.reduce((acc, row) => acc + row.matchedAfter, 0);

const csvHeader = "scenario,cases,cold_before_median_ms,cold_after_median_ms,cold_delta_pct,cold_before_mean_ms,cold_after_mean_ms,cold_before_p95_ms,cold_after_p95_ms,warm_before_median_ms,warm_after_median_ms,warm_delta_pct,rss_before_kb,rss_after_kb,rss_delta_pct,matched_before,judged_before,matched_after,judged_after,errors_before,errors_after";
const csvLines = [csvHeader];
for (const row of rows) {
  csvLines.push([
    row.scenario, row.cases,
    fmt(row.beforeCold.median), fmt(row.afterCold.median), row.coldDeltaPct === null ? "n/a" : row.coldDeltaPct.toFixed(2),
    fmt(row.beforeCold.mean), fmt(row.afterCold.mean), fmt(row.beforeCold.p95), fmt(row.afterCold.p95),
    fmt(row.beforeWarm.median, 3), fmt(row.afterWarm.median, 3), row.warmDeltaPct === null ? "n/a" : row.warmDeltaPct.toFixed(2),
    row.rssBefore ?? "n/a", row.rssAfter ?? "n/a", row.rssDeltaPct === null ? "n/a" : row.rssDeltaPct.toFixed(2),
    row.matchedBefore, row.judgedBefore, row.matchedAfter, row.judgedAfter, row.errorsBefore, row.errorsAfter
  ].join(","));
}
csvLines.push([
  "__overall__", rows.reduce((acc, row) => acc + row.cases, 0),
  fmt(overallColdBefore.median), fmt(overallColdAfter.median),
  (deltaPct(overallColdBefore.median, overallColdAfter.median) ?? 0).toFixed(2),
  fmt(overallColdBefore.mean), fmt(overallColdAfter.mean), fmt(overallColdBefore.p95), fmt(overallColdAfter.p95),
  fmt(overallWarmBefore.median, 3), fmt(overallWarmAfter.median, 3),
  (deltaPct(overallWarmBefore.median, overallWarmAfter.median) ?? 0).toFixed(2),
  "n/a", "n/a", "n/a",
  totalMatchedBefore, totalJudgedBefore, totalMatchedAfter, totalJudgedAfter,
  rows.reduce((acc, row) => acc + row.errorsBefore, 0), rows.reduce((acc, row) => acc + row.errorsAfter, 0)
].join(","));

const mdLines = [];
mdLines.push("# Project-X analyzer performance comparison (BEFORE vs AFTER)");
mdLines.push("");
mdLines.push(`- BEFORE run: ${before.label} \u2014 ${before.startedAt} \u2192 ${before.finishedAt} \u2014 dist \`${before.dist}\``);
mdLines.push(`- AFTER run: ${after.label} \u2014 ${after.startedAt} \u2192 ${after.finishedAt} \u2014 dist \`${after.dist}\``);
mdLines.push(`- Workload file: \`${before.workloadFile}\` (seed ${before.workloadSeed}) \u2014 identical for both runs`);
mdLines.push(`- Node ${after.node}, platform ${after.platform}, clang \`${after.clang}\``);
mdLines.push(`- Cold sample = fresh Clang parse (AST cache cleared); warm sample = cached-AST re-analysis.`);
mdLines.push("");
mdLines.push("| Scenario | Cases | Cold median before | Cold median after | Cold change | Warm median before | Warm median after | Warm change | Peak RSS before | Peak RSS after | Correctness before | Correctness after |");
mdLines.push("|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|");
for (const row of rows) {
  mdLines.push(`| ${row.scenario} | ${row.cases} | ${fmt(row.beforeCold.median, 1)} ms | ${fmt(row.afterCold.median, 1)} ms | ${fmtPct(row.coldDeltaPct)} | ${fmt(row.beforeWarm.median, 2)} ms | ${fmt(row.afterWarm.median, 2)} ms | ${fmtPct(row.warmDeltaPct)} | ${row.rssBefore ?? "n/a"} KB | ${row.rssAfter ?? "n/a"} KB | ${row.matchedBefore}/${row.judgedBefore} | ${row.matchedAfter}/${row.judgedAfter} |`);
}
mdLines.push(`| **overall** | ${rows.reduce((acc, row) => acc + row.cases, 0)} | ${fmt(overallColdBefore.median, 1)} ms | ${fmt(overallColdAfter.median, 1)} ms | ${fmtPct(deltaPct(overallColdBefore.median, overallColdAfter.median))} | ${fmt(overallWarmBefore.median, 2)} ms | ${fmt(overallWarmAfter.median, 2)} ms | ${fmtPct(deltaPct(overallWarmBefore.median, overallWarmAfter.median))} | n/a | n/a | ${totalMatchedBefore}/${totalJudgedBefore} | ${totalMatchedAfter}/${totalJudgedAfter} |`);
mdLines.push("");
mdLines.push("Positive percentages in the change columns mean the AFTER build is faster (lower latency); for RSS they mean lower memory.");
mdLines.push("");

mkdirSync(dirname(csvPath), { recursive: true });
writeFileSync(csvPath, `${csvLines.join("\n")}\n`, "utf8");
writeFileSync(mdPath, `${mdLines.join("\n")}\n`, "utf8");
console.log(mdLines.join("\n"));
console.log(`csv: ${csvPath}`);
console.log(`md:  ${mdPath}`);
