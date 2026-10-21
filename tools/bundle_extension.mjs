#!/usr/bin/env node

import { cpSync, existsSync, mkdirSync, writeFileSync } from "node:fs";
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

// Copy analyzer distribution to extension/dist/analyzer
const targetAnalyzer = join(extensionDist, "analyzer");
cpSync(analyzerDist, targetAnalyzer, { recursive: true });

// Create extension/dist/analyzer-cli.js as entry point
const cliEntry = join(extensionDist, "analyzer-cli.js");
writeFileSync(cliEntry, `#!/usr/bin/env node\nimport "./analyzer/cli.js";\n`, "utf8");
writeFileSync(join(extensionDist, "package.json"), `{\n  "type": "module"\n}\n`, "utf8");

console.log("Successfully bundled analyzer into extension/dist/analyzer and extension/dist/analyzer-cli.js");
