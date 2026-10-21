import { parseBound, boundsEqual } from "../../src/bound.js";

/**
 * Semantic bound comparison shared by generated test files: equivalent
 * spellings (O((n + q) log n) vs O(n log n + q log n), O(nm) vs O(n m))
 * match; different dimensions, exponents, or logarithms never do.
 */
export function equivalent(actual: string, label: string): boolean {
  if (actual === label) return true;
  try {
    const a = parseBound(actual);
    const b = parseBound(label);
    if (a && b && boundsEqual(a, b)) return true;
  } catch {
    // fall through to presentation comparison
  }
  const norm = (v: string) => /^O\((.*)\)$/.exec(v)?.[1]?.replace(/\s+/g, "").replace(/[·*]/g, "");
  const l = norm(actual);
  const r = norm(label);
  return l !== undefined && l === r;
}
