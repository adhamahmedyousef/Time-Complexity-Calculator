import type { Complexity } from "./model.js";
import { boundsEqual, formatBound, maxBounds, multiplyBounds, parseBound } from "./bound.js";

/**
 * Compatibility facade over the canonical bound algebra in bound.ts.
 *
 * The historic implementation parsed a closed subset of complexity strings and
 * kept an explicit opaque blacklist (`2^n`, `n!`, `sqrt n`, `n log log n`,
 * sums, ...) which silently forced Unknown whenever those values reached a
 * product or a domination check. The canonical algebra composes all of them.
 */

export function multiplyExpressions(left: Complexity, right: Complexity): Complexity | undefined {
  const a = parseBound(left);
  const b = parseBound(right);
  if (!a || !b) return undefined;
  const bound = multiplyBounds(a, b);
  return bound ? formatBound(bound) : undefined;
}

/** Returns the dominant term when the two products are comparable. */
export function dominantExpression(left: Complexity, right: Complexity): Complexity | undefined {
  const a = parseBound(left);
  const b = parseBound(right);
  if (!a || !b) return undefined;
  const merged = maxBounds(a, b);
  if (boundsEqual(merged, a)) return left;
  if (boundsEqual(merged, b)) return right;
  return undefined;
}
