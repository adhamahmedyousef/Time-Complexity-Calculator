#!/usr/bin/env node
/*
 * Measurement runner: executes ONE benchmark scenario against ONE analyzer
 * build (dist) in a fresh process and prints a JSON report to stdout.
 *
 * Invoked by benchmarks/harness/bench.mjs; not usually run directly.
 *
 * Cache policy (deterministic, identical for BEFORE and AFTER):
 *   - every "cold" sample first deletes %TEMP%/project-x-ast-cache, forcing a
 *     fresh Clang parse (the dominant cost of one analysis)
 *   - "warm" samples run immediately afterwards on the same source, so they
 *     hit the persisted AST cache (Clang is not re-spawned)
 * Timing is taken with performance.now() around the public API call only.
 */
import { existsSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join, resolve } from "node:path";
import { pathToFileURL } from "node:url";

const cacheDirectory = join(tmpdir(), "project-x-ast-cache");
const args = process.argv.slice(2);
const option = (name, fallback) => {
  const found = args.find((argument) => argument.startsWith(`--${name}=`));
  return found ? found.slice(name.length + 3) : fallback;
};

const distPath = resolve(option("dist", "analyzer/dist/index.js"));
const workloadPath = resolve(option("workloads", "benchmarks/workloads/workloads.json"));
const scenarioId = option("scenario");
if (!existsSync(distPath)) {
  console.error(`dist not found: ${distPath}`);
  process.exit(2);
}
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\\Program Files\\LLVM\\bin\\clang++.exe";

const { analyseCppSelection, analyseCppFunctionsInDocument } = await import(pathToFileURL(distPath).href);
const boundModulePath = pathToFileURL(distPath.replace(/index\.js$/, "bound.js")).href;
const { parseBound, boundsEqual } = await import(boundModulePath);
const { readFileSync } = await import("node:fs");
const workload = JSON.parse(readFileSync(workloadPath, "utf8"));
const scenario = workload.scenarios.find((entry) => entry.id === scenarioId);
if (!scenario) {
  console.error(`scenario not found: ${scenarioId}`);
  process.exit(2);
}

const coldRepeats = Number(option("cold", scenario.coldRepeats ?? 3));
const warmRepeats = Number(option("warm", scenario.warmRepeats ?? 5));
const clearCache = () => {
  try {
    rmSync(cacheDirectory, { recursive: true, force: true });
  } catch {
    /* cache is an optimization only; failure to clear only affects cold timing */
  }
};

const semanticallyEqual = (left, right) => {
  if (left === right) return true;
  try {
    const l = parseBound(left);
    const r = parseBound(right);
    if (l && r) return boundsEqual(l, r);
  } catch {
    /* fall back to string comparison */
  }
  return false;
};

const runOne = (testCase) => {
  if (scenario.kind === "document") return analyseCppFunctionsInDocument(testCase.source, testCase.symbols);
  return { single: analyseCppSelection(testCase.source) };
};

const cases = [];
let errors = 0;
for (const testCase of scenario.cases) {
  const cold = [];
  const warm = [];
  let answer = null;
  let error = null;
  for (let repeat = 0; repeat < coldRepeats; repeat += 1) {
    clearCache();
    const started = performance.now();
    try {
      const result = runOne(testCase);
      cold.push(performance.now() - started);
      answer = scenario.kind === "document" ? result : result.single;
    } catch (problem) {
      cold.push(performance.now() - started);
      error = String(problem && problem.message ? problem.message : problem).slice(0, 300);
      errors += 1;
      break;
    }
  }
  if (!error) {
    for (let repeat = 0; repeat < warmRepeats; repeat += 1) {
      const started = performance.now();
      try {
        const result = runOne(testCase);
        warm.push(performance.now() - started);
        answer = scenario.kind === "document" ? result : result.single;
      } catch (problem) {
        warm.push(performance.now() - started);
        error = String(problem && problem.message ? problem.message : problem).slice(0, 300);
        errors += 1;
        break;
      }
    }
  }
  let observed = null;
  if (answer && !error) {
    if (scenario.kind === "document") {
      const rows = [];
      for (const [symbol, result] of answer) {
        rows.push({ symbol, time: result.worstCaseTime, space: result.auxiliarySpace, confidence: result.confidence });
      }
      observed = { functions: rows };
    } else {
      observed = { time: answer.worstCaseTime, space: answer.auxiliarySpace, confidence: answer.confidence };
    }
  }
  let matches = null;
  if (observed && testCase.expect && observed.time !== undefined) {
    const timeOk = testCase.expect.time === null || semanticallyEqual(observed.time, testCase.expect.time);
    const spaceOk = testCase.expect.space === null || observed.space === null || semanticallyEqual(observed.space, testCase.expect.space);
    const confidenceOk = testCase.expect.confidence === null || observed.confidence === testCase.expect.confidence;
    matches = { time: timeOk, space: spaceOk, confidence: confidenceOk, all: timeOk && spaceOk && confidenceOk };
  }
  cases.push({ id: testCase.id, cold, warm, observed, expect: testCase.expect ?? null, matches, error });
}

const stats = (values) => {
  if (values.length === 0) return null;
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

const coldAll = cases.flatMap((entry) => entry.cold);
const warmAll = cases.flatMap((entry) => entry.warm);
const matched = cases.filter((entry) => entry.matches && entry.matches.all).length;
const judged = cases.filter((entry) => entry.matches).length;
const maxRss = process.resourceUsage().maxRSS > 0 ? process.resourceUsage().maxRSS : null;

const report = {
  scenario: scenario.id,
  kind: scenario.kind,
  dist: distPath,
  node: process.version,
  clang: process.env.PROJECT_X_CLANG,
  coldRepeats,
  warmRepeats,
  maxRssKb: maxRss,
  cases,
  summary: {
    cases: cases.length,
    errors,
    judged,
    matched,
    cold: stats(coldAll),
    warm: stats(warmAll),
    coldTotalMs: coldAll.reduce((acc, value) => acc + value, 0),
    warmTotalMs: warmAll.reduce((acc, value) => acc + value, 0)
  }
};
process.stdout.write(`${JSON.stringify(report)}\n`);
