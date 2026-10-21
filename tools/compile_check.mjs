#!/usr/bin/env node
/** Reports generated families whose functions fail to resolve (file-level parse damage). */
import { readFileSync, readdirSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";
const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\Program Files\LLVM\bin\clang++.exe";
const { analyseCppFunctionsInDocument } = await import(pathToFileURL(join(root, "analyzer", "dist", "index.js")).href);
const manifests = readdirSync(join(root, "datasets")).filter((n) => n.startsWith("cpp-axis") && n.endsWith(".manifest.json")).sort();
for (const name of manifests) {
  const manifest = JSON.parse(readFileSync(join(root, "datasets", name), "utf8"));
  const source = readFileSync(join(root, "datasets", name.replace(".manifest.json", ".cpp")), "utf8");
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((c) => c.symbol));
  let missing = 0;
  for (const c of manifest.cases) {
    const r = results.get(c.symbol);
    if (!r || (r.proof[0] ?? "").includes("was not found")) missing += 1;
  }
  if (missing > 0) console.log(`${name}: ${missing}/${manifest.cases.length} symbols missing (file parse damage)`);
}
console.log("compile check done");
