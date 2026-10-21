#!/usr/bin/env node

/**
 * Case-by-case adjudication helper: prints the fixture source, the manifest
 * label, and the engine result for every mismatched case of the selected
 * manifests, so a human (or reviewing agent) can decide whether the engine
 * or the label is wrong. Read-only.
 */
import { readdirSync, readFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const datasetsDir = join(root, "datasets");
const prefix = process.argv.find((a) => a.startsWith("--prefix="))?.slice("--prefix=".length) ?? "";
const manifestName = process.argv.find((a) => a.startsWith("--manifest="))?.slice("--manifest=".length);
const limit = Number(process.argv.find((a) => a.startsWith("--limit="))?.slice("--limit=".length) ?? 8);
const analyzerPath = pathToFileURL(join(root, "analyzer", "dist", "index.js")).href;
const boundPath = pathToFileURL(join(root, "analyzer", "dist", "bound.js")).href;

if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const { analyseCppFunctionsInDocument } = await import(analyzerPath);
const { parseBound, boundsEqual } = await import(boundPath);

function complexityEquivalent(left, right) {
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

const confidenceRank = { exact: 2, estimated: 1, unknown: 0 };
const manifests = readdirSync(datasetsDir)
  .filter((n) => n.endsWith(".manifest.json"))
  .filter((n) => (manifestName ? n === manifestName : n.startsWith(prefix)))
  .sort();

let shown = 0;
for (const manifestName2 of manifests) {
  if (shown >= limit) break;
  const manifest = JSON.parse(readFileSync(join(datasetsDir, manifestName2), "utf8"));
  const sourcePath = join(datasetsDir, manifestName2.replace(".manifest.json", ".cpp"));
  const source = readFileSync(sourcePath, "utf8");
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((c) => c.symbol));
  for (const testCase of manifest.cases) {
    if (shown >= limit) break;
    const actual = results.get(testCase.symbol);
    if (!actual) continue;
    const abstained = actual.confidence === "unknown";
    const timeOk = complexityEquivalent(actual.worstCaseTime, testCase.time);
    const spaceOk = complexityEquivalent(actual.auxiliarySpace, testCase.space);
    const confOk = actual.confidence === testCase.confidence;
    if ((timeOk && spaceOk && confOk) || abstained) continue;
    shown += 1;
    console.log("=".repeat(78));
    console.log(`CASE ${testCase.id}  [${manifestName2}]  origin=${testCase.origin?.kind ?? "?"}`);
    console.log(`LABEL : ${testCase.time} / ${testCase.space} / ${testCase.confidence}`);
    console.log(`ENGINE: ${actual.worstCaseTime} / ${actual.auxiliarySpace} / ${actual.confidence}`);
    console.log(`PROOF : ${actual.proof[0] ?? ""}`);
    console.log("-".repeat(78));
    console.log(source.split(/\r?\n/).slice(0, 60).join("\n"));
  }
}
console.log(`\nshown ${shown} mismatched case(s)`);
