#!/usr/bin/env node
/*
 * Benchmark orchestrator: runs every workload scenario against a given
 * analyzer build (dist) in a fresh child process each, aggregates the samples
 * and writes benchmarks/results/perf-<label>.json.
 *
 * Usage (run from the project root, with nothing else competing for the CPU):
 *   node benchmarks/harness/bench.mjs --dist=benchmarks/baseline-snapshot/analyzer/dist/index.js --label=before
 *   node benchmarks/harness/bench.mjs --dist=analyzer/dist/index.js --label=after
 *
 * The child process isolates peak-RSS per scenario; spawnSync keeps scenarios
 * strictly sequential so samples are not perturbed by sibling processes.
 */
import { mkdirSync, readFileSync, writeFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath } from "node:url";
import { spawnSync } from "node:child_process";

const harnessDir = dirname(fileURLToPath(import.meta.url));
const root = resolve(harnessDir, "..", "..");
const args = process.argv.slice(2);
const option = (name, fallback) => {
  const found = args.find((argument) => argument.startsWith(`--${name}=`));
  return found ? found.slice(name.length + 3) : fallback;
};

const label = option("label", "run");
const dist = resolve(root, option("dist", "analyzer/dist/index.js"));
const workloadPath = resolve(root, option("workloads", "benchmarks/workloads/workloads.json"));
const outPath = resolve(root, option("out", `benchmarks/results/perf-${label}.json`));
const onlyScenario = option("scenario", null);

const workload = JSON.parse(readFileSync(workloadPath, "utf8"));
const scenarios = workload.scenarios.filter((scenario) => !onlyScenario || scenario.id === onlyScenario);
if (scenarios.length === 0) {
  console.error("no matching scenarios");
  process.exit(2);
}

const startedAt = new Date().toISOString();
const reports = [];
for (const scenario of scenarios) {
  process.stdout.write(`[${label}] ${scenario.id} ... `);
  const child = spawnSync(process.execPath, [
    join(harnessDir, "runner.mjs"),
    `--dist=${dist}`,
    `--workloads=${workloadPath}`,
    `--scenario=${scenario.id}`
  ], {
    cwd: root,
    encoding: "utf8",
    maxBuffer: 512 * 1024 * 1024,
    env: { ...process.env, PROJECT_X_CLANG: process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe" }
  });
  if (child.status !== 0) {
    console.error(`\nscenario ${scenario.id} failed (exit ${child.status}).`);
    console.error(child.stderr?.slice(0, 4000) ?? "");
    process.exit(1);
  }
  const report = JSON.parse(child.stdout.trim().split("\n").pop());
  reports.push(report);
  const summary = report.summary;
  process.stdout.write(
    `${summary.cases} cases, cold median ${summary.cold ? summary.cold.median.toFixed(1) : "n/a"} ms, `
    + `warm median ${summary.warm ? summary.warm.median.toFixed(2) : "n/a"} ms, `
    + `matched ${summary.matched}/${summary.judged}, errors ${summary.errors}, peak RSS ${report.maxRssKb ?? "n/a"} KB\n`
  );
}

const finishedAt = new Date().toISOString();
const overall = {
  label,
  dist,
  workloadFile: workloadPath,
  workloadSeed: workload.seed,
  generator: workload.generator,
  startedAt,
  finishedAt,
  node: process.version,
  platform: process.platform,
  clang: process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe",
  scenarios: reports
};
mkdirSync(dirname(outPath), { recursive: true });
writeFileSync(outPath, `${JSON.stringify(overall, null, 1)}\n`, "utf8");
console.log(`\n[${label}] wrote ${outPath}`);
