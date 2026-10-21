import { readFileSync } from "node:fs";
import { analyseCppSelection } from "./index.js";

function confidencePercent(confidence: "exact" | "estimated" | "unknown"): number {
  // These are intentionally conservative rule grades, not ML probabilities.
  return confidence === "exact" ? 99 : confidence === "estimated" ? 85 : 0;
}

const raw = readFileSync(0, "utf8");
let selection = raw;
let document = raw;
try {
  const request = JSON.parse(raw) as { selection?: unknown; document?: unknown };
  if (typeof request.selection === "string") selection = request.selection;
  if (typeof request.document === "string") document = request.document;
} catch {
  // Backward-compatible plain-source CLI input.
}
const result = analyseCppSelection(selection, document);
process.stdout.write(JSON.stringify({ ...result, confidencePercent: result.confidencePercent ?? confidencePercent(result.confidence) }) + "\n");
