#!/usr/bin/env node

/**
 * Offline C++ Complexity Analyzer CLI
 * Analyzes C++ code for worst-case time complexity, auxiliary space, and confidence.
 */
import { existsSync, readFileSync } from "node:fs";
import { resolve } from "node:path";
import { analyseCppFunctionsInDocument, analyseCppSelection } from "./index.js";

function confidencePercent(confidence: "exact" | "estimated" | "unknown"): number {
  return confidence === "exact" ? 99 : confidence === "estimated" ? 85 : 0;
}

function printHelp(): void {
  console.log(`
Time Complexity Calculator - Offline C++ Static Complexity Analyzer

Usage:
  project-x-analyzer [options] [file.cpp]
  cat file.cpp | project-x-analyzer

Options:
  --symbol <name>   Analyze a specific function symbol in the file
  --human           Display human-readable formatted output instead of JSON
  --json            Output structured JSON (default)
  --help, -h        Show this help message
  --version, -v     Show version number

Examples:
  project-x-analyzer solution.cpp --symbol solve --human
  project-x-analyzer --human < snippet.cpp
`);
}

const args = process.argv.slice(2);

if (args.includes("--help") || args.includes("-h")) {
  printHelp();
  process.exit(0);
}

if (args.includes("--version") || args.includes("-v")) {
  console.log("1.0.0");
  process.exit(0);
}

const isHuman = args.includes("--human");
const symbolIndex = args.indexOf("--symbol");
const symbolArg = symbolIndex !== -1 ? args[symbolIndex + 1] : undefined;
const fileArgs = args.filter((arg, index) => !arg.startsWith("-") && (index === 0 || args[index - 1] !== "--symbol"));

let raw = "";
let filename = "<stdin>";

if (fileArgs.length > 0 && existsSync(fileArgs[0])) {
  filename = resolve(fileArgs[0]);
  raw = readFileSync(filename, "utf8");
} else {
  try {
    raw = readFileSync(0, "utf8");
  } catch {
    printHelp();
    process.exit(1);
  }
}

if (!raw.trim()) {
  printHelp();
  process.exit(1);
}

let selection = raw;
let document = raw;

try {
  const request = JSON.parse(raw) as { selection?: unknown; document?: unknown };
  if (typeof request.selection === "string") selection = request.selection;
  if (typeof request.document === "string") document = request.document;
} catch {
  // Plain source input
}

if (symbolArg) {
  const map = analyseCppFunctionsInDocument(document, [symbolArg]);
  const result = map.get(symbolArg);
  if (!result) {
    console.error(`Error: Symbol '${symbolArg}' not found or could not be analyzed in ${filename}`);
    process.exit(1);
  }
  outputResult(result, isHuman, symbolArg);
} else {
  const result = analyseCppSelection(selection, document);
  outputResult(result, isHuman);
}

function outputResult(result: any, human: boolean, symbol?: string): void {
  const confPercent = result.confidencePercent ?? confidencePercent(result.confidence);
  const enriched = { ...result, confidencePercent: confPercent };

  if (human) {
    console.log("==================================================");
    console.log(`Complexity Analysis Result${symbol ? ` for '${symbol}'` : ""}:`);
    console.log("==================================================");
    console.log(`Worst-Case Time:   ${result.worstCaseTime}`);
    console.log(`Auxiliary Space:   ${result.auxiliarySpace}`);
    console.log(`Confidence:        ${result.confidence} (${confPercent}%)`);
    if (result.proof && result.proof.length > 0) {
      console.log("\nProof & Reasoning:");
      for (const line of result.proof) {
        console.log(`  • ${line}`);
      }
    }
    console.log("==================================================");
  } else {
    process.stdout.write(JSON.stringify(enriched) + "\n");
  }
}
