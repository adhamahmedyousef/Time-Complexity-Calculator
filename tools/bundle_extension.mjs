#!/usr/bin/env node

import { cpSync, existsSync, mkdirSync, rmSync, writeFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath } from "node:url";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const analyzerDist = join(root, "analyzer", "dist");
const extensionDist = join(root, "extension", "dist");

if (!existsSync(analyzerDist)) {
  console.error("analyzer/dist does not exist. Run npm run build first.");
  process.exit(1);
}

mkdirSync(extensionDist, { recursive: true });

// Ensure no stray package.json in extension/dist exists (which would force CommonJS extension.js into ESM)
const strayPkg = join(extensionDist, "package.json");
if (existsSync(strayPkg)) {
  rmSync(strayPkg, { force: true });
}

// Copy analyzer distribution to extension/dist/analyzer
const targetAnalyzer = join(extensionDist, "analyzer");
cpSync(analyzerDist, targetAnalyzer, { recursive: true });

// Scoped package.json inside analyzer/ to declare it as ES Module without affecting extension.js
writeFileSync(join(targetAnalyzer, "package.json"), `{\n  "type": "module"\n}\n`, "utf8");

// Create analyzer-cli.mjs as explicit ESM wrapper
const mjsCli = join(extensionDist, "analyzer-cli.mjs");
writeFileSync(mjsCli, `#!/usr/bin/env node\nimport "./analyzer/cli.js";\n`, "utf8");

console.log("Successfully bundled analyzer into extension/dist/analyzer and extension/dist/analyzer-cli.mjs");
