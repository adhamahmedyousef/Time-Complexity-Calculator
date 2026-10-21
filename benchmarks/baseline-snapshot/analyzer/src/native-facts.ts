import { execFileSync } from "node:child_process";
import { existsSync } from "node:fs";

/** Minimal, versioned contract emitted by native-analyzer/ (LibTooling). */
export interface NativeFunctionFact {
  name: string;
  cfgBlocks: number;
  directCalls: number;
  selfRecursiveCalls: number;
  forLoops: number;
  whileLoops: number;
  doLoops: number;
  rangeForLoops: number;
  directCallees: string[];
}

export interface NativeFacts {
  parsed: boolean;
  functionFacts: NativeFunctionFact[];
}

function isNativeFacts(value: unknown): value is NativeFacts {
  if (!value || typeof value !== "object") return false;
  const candidate = value as Partial<NativeFacts>;
  return typeof candidate.parsed === "boolean" && Array.isArray(candidate.functionFacts);
}

/**
 * Optional LibTooling shadow pass. It never replaces a successful JSON-AST
 * result and it never makes the editor fail: users only get this native layer
 * when they explicitly configure a locally built executable.
 */
export function nativeFactsFor(source: string, executable = process.env.PROJECT_X_NATIVE_ANALYZER): NativeFacts | undefined {
  if (!executable?.trim() || !existsSync(executable)) return undefined;
  try {
    const stdout = execFileSync(executable, [], {
      input: source,
      encoding: "utf8",
      stdio: ["pipe", "pipe", "pipe"],
      windowsHide: true,
      maxBuffer: 4 * 1024 * 1024
    });
    const parsed: unknown = JSON.parse(stdout);
    return isNativeFacts(parsed) ? parsed : undefined;
  } catch {
    // Native facts are an optional validation/enrichment pass. The existing
    // local Clang JSON analyzer remains the safe offline fallback.
    return undefined;
  }
}
