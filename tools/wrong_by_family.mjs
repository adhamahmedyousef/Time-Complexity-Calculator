#!/usr/bin/env node

/** Wrong/underclaim/abstention counts per manifest family — adjudication planning. */
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

const rows = [];
for (const name of readdirSync(datasetsDir).filter((n) => n.endsWith(".manifest.json")).sort()) {
  const manifest = JSON.parse(readFileSync(join(datasetsDir, name), "utf8"));
  const source = readFileSync(join(datasetsDir, name.replace(".manifest.json", ".cpp")), "utf8");
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((c) => c.symbol));
  let wrong = 0, abstain = 0, under = 0, ok = 0;
  const samples = [];
  for (const testCase of manifest.cases) {
    const actual = results.get(testCase.symbol);
    if (!actual) continue;
    const abstained = actual.confidence === "unknown";
    const timeOk = equivalent(actual.worstCaseTime, testCase.time);
    const spaceOk = equivalent(actual.auxiliarySpace, testCase.space);
    const profileOk = timeOk && spaceOk;
    const confOk = actual.confidence === testCase.confidence;
    if (abstained) { abstain += 1; if (samples.length < 3 && testCase.confidence !== "unknown") samples.push(`${testCase.id}: label ${testCase.time} got Unknown`); continue; }
    if (profileOk && confOk) { ok += 1; continue; }
    if (profileOk && (rank[actual.confidence] ?? 0) < (rank[testCase.confidence] ?? 0)) { under += 1; continue; }
    wrong += 1;
    if (samples.length < 3) samples.push(`${testCase.id}: label ${testCase.time} got ${actual.worstCaseTime}`);
  }
  if (wrong > 0) rows.push({ name, wrong, abstain, under, ok, samples });
}
rows.sort((a, b) => b.wrong - a.wrong);
for (const r of rows.slice(0, 25)) {
  console.log(`${String(r.wrong).padStart(4)} wrong ${String(r.abstain).padStart(4)} abstain ${String(r.under).padStart(3)} under ${String(r.ok).padStart(3)} ok   ${r.name}`);
  for (const s of r.samples) console.log(`        ${s}`);
}
console.log(`total wrong: ${rows.reduce((s, r) => s + r.wrong, 0)}`);
