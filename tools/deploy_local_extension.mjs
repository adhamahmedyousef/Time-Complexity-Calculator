#!/usr/bin/env node

import { cpSync, existsSync, mkdirSync, rmSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath } from "node:url";
import { homedir } from "node:os";

const root = resolve(dirname(fileURLToPath(import.meta.url)), "..");
const extensionDir = join(root, "extension");
const home = homedir();

const targetDirs = [
  join(home, ".cursor", "extensions", "voidhub.time-complexity-calculator-1.0.0"),
  join(home, ".kiro", "extensions", "voidhub.time-complexity-calculator-1.0.0"),
  join(home, ".vscode", "extensions", "voidhub.time-complexity-calculator-1.0.0")
];

for (const target of targetDirs) {
  const parent = dirname(target);
  if (!existsSync(parent)) continue;

  try {
    if (existsSync(target)) {
      rmSync(target, { recursive: true, force: true });
    }
    mkdirSync(target, { recursive: true });

    // Copy package.json, dist, and metadata
    cpSync(join(extensionDir, "package.json"), join(target, "package.json"));
    cpSync(join(extensionDir, "dist"), join(target, "dist"), { recursive: true });
    if (existsSync(join(root, "README.md"))) {
      cpSync(join(root, "README.md"), join(target, "README.md"));
    }
    if (existsSync(join(root, "LICENSE"))) {
      cpSync(join(root, "LICENSE"), join(target, "LICENSE"));
    }

    console.log(`Installed extension to: ${target}`);
  } catch (err) {
    console.error(`Failed to install into ${target}:`, err.message);
  }
}
