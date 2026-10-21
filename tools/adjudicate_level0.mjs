#!/usr/bin/env node
/** Prints each distinct level0-400 shape with its current labels and the engine result. */
import { readFileSync, readdirSync, writeFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";
const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\Program Files\LLVM\bin\clang++.exe";
const { analyseCppFunctionsInDocument } = await import(pathToFileURL(join(root, "analyzer", "dist", "index.js")).href);

const lines = [];
const files = readdirSync(join(root, "datasets")).filter((n) => n.startsWith("cpp-pack-level0-400-") && n.endsWith(".manifest.json")).sort();
const shapes = new Map();
for (const name of files) {
  const manifest = JSON.parse(readFileSync(join(root, "datasets", name), "utf8"));
  const source = readFileSync(join(root, "datasets", name.replace(".manifest.json", ".cpp")), "utf8");
  const body = source.slice(source.indexOf("int pack_level0_400_pack_main()"));
  if (!shapes.has(body)) shapes.set(body, { cases: [], source });
  shapes.get(body).cases.push({ name, manifest });
}
let index = 0;
for (const [body, group] of shapes) {
  const manifest = group.cases[0].manifest;
  const source = group.source;
  const results = analyseCppFunctionsInDocument(source, manifest.cases.map((c) => c.symbol));
  const actual = results.get(manifest.cases[0].symbol);
  const labels = {};
  for (const { manifest: m } of group.cases) {
    const c = m.cases[0];
    const key = `${c.time} / ${c.space} / ${c.confidence}`;
    labels[key] = (labels[key] ?? 0) + 1;
  }
  lines.push(`SHAPE ${index} | ${group.cases.length} cases | labels: ${JSON.stringify(labels)}`);
  lines.push(`ENGINE: ${actual?.worstCaseTime} / ${actual?.auxiliarySpace} / ${actual?.confidence} | ${(actual?.proof?.[0] ?? "").slice(0, 80)}`);
  lines.push(`CODE: ${body.replace(/\s+/g, " ").slice(0, 450)}`);
  lines.push("");
  index += 1;
}
writeFileSync(join(root, ".scratch", "level0-adjudication.txt"), lines.join("\n"));
console.log(`${shapes.size} shapes written`);
