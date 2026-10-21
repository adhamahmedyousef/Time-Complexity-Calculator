#!/usr/bin/env node

/** One-off style report: precision/coverage split by label origin kind. */
import { readdirSync, readFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const datasetsDir = join(root, "datasets");
const analyzerPath = pathToFileURL(join(root, "analyzer", "dist", "index.js")).href;
const boundPath = pathToFileURL(join(root, "analyzer", "dist", "bound.js")).href;
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const { analyseCppFunctionsInDocument } = await import(analyzerPath);
const { parseBound, boundsEqual } = await import(boundPath);

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
const rank = { exact: 2, estimated: 1, unknown: 0 };

const stats = new Map();
const bump = (kind, field) => {
  if (!stats.has(kind)) stats.set(kind, { cases: 0, covered: 0, profileOk: 0, matched: 0, under: 0, wrong: 0 });
  return stats.get(kind)[field] += 1;
};

for (const name of readdirSync(datasetsDir).filter((n) => n.endsWith(".manifest.json")).sort()) {
  const manifest = JSON.parse(readFileSync(join(datasetsDir, name), "utf8"));
  const source = readFileSync(join(datasetsDir, name.replace(".manifest.json", ".cpp")), "utf8");
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((c) => c.symbol));
  for (const testCase of manifest.cases) {
    const kind = testCase.origin?.kind ?? "unknown-origin";
    const actual = results.get(testCase.symbol);
    if (!actual) continue;
    bump(kind, "cases");
    const abstained = actual.confidence === "unknown";
    if (abstained) continue;
    bump(kind, "covered");
    const timeOk = equivalent(actual.worstCaseTime, testCase.time);
    const spaceOk = equivalent(actual.auxiliarySpace, testCase.space);
    const profileOk = timeOk && spaceOk;
    if (profileOk) bump(kind, "profileOk");
    const confOk = actual.confidence === testCase.confidence;
    if (profileOk && confOk) bump(kind, "matched");
    else if (profileOk && (rank[actual.confidence] ?? 0) < (rank[testCase.confidence] ?? 0)) bump(kind, "under");
    else bump(kind, "wrong");
  }
}

console.log("origin      cases  covered  profileOk  matched  underclaim  wrong");
for (const [kind, s] of [...stats.entries()].sort((a, b) => b[1].cases - a[1].cases)) {
  const pct = (n, d) => d === 0 ? "  -  " : `${((100 * n) / d).toFixed(0)}%`.padStart(5);
  console.log(kind.padEnd(11), String(s.cases).padStart(5), String(s.covered).padStart(8), `${pct(s.profileOk, s.cases).trim()} (${s.profileOk})`.padStart(10), String(s.matched).padStart(8), String(s.under).padStart(11), String(s.wrong).padStart(6));
}
