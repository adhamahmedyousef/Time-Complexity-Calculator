import type { Complexity } from "./model.js";

/**
 * Canonical symbolic bound algebra.
 *
 * A bound is a sum of terms; each term is a product of per-symbol growth
 * components:
 *   - polynomial exponents (fractional for sqrt),
 *   - logarithm exponents (with a chain depth for log log),
 *   - an inverse-Ackermann factor (grows slower than any log),
 *   - one exponential factor base^symbol,
 *   - one factorial factor symbol!.
 *
 * Terms compare by asymptotic domination so max/sum can drop dominated
 * summands. Unlike the historic string-parsed algebra there is no opaque
 * blacklist: 2^n, n!, sqrt n, n log log n, and sums compose like any other
 * bound.
 */

export type LogChain = 1 | 2; // 1 = log, 2 = log log

export interface Term {
  /** Polynomial exponents per symbol; 0.5 encodes sqrt. */
  symbols: Map<string, number>;
  /** log(symbol) exponents. */
  logs: Map<string, number>;
  /** (log log(symbol)) exponents. */
  logLogs: Map<string, number>;
  /** Inverse-Ackermann factors per symbol, e.g. alpha(n). */
  ackermanns: Set<string>;
  /** base^symbol factor when present. */
  exponential?: { base: number; symbol: string };
  /** symbol! factor when present. */
  factorial?: string;
}

export type Bound = Term[];

export const constantTerm = (): Term => ({
  symbols: new Map(), logs: new Map(), logLogs: new Map(), ackermanns: new Set()
});

const isConstant = (term: Term): boolean =>
  term.symbols.size === 0 && term.logs.size === 0 && term.logLogs.size === 0
  && term.ackermanns.size === 0 && !term.exponential && !term.factorial;

const cloneTerm = (term: Term): Term => ({
  symbols: new Map(term.symbols),
  logs: new Map(term.logs),
  logLogs: new Map(term.logLogs),
  ackermanns: new Set(term.ackermanns),
  exponential: term.exponential ? { ...term.exponential } : undefined,
  factorial: term.factorial
});

const roundBase = (base: number): number => Math.round(base * 1000) / 1000;

/** Ranks the slowest-growing "sub-polynomial" component of a term. */
const subPolynomialRank = (term: Term, symbol: string): number => {
  if ((term.logs.get(symbol) ?? 0) > 0) return 3;
  if ((term.logLogs.get(symbol) ?? 0) > 0) return 2;
  if (term.ackermanns.has(symbol)) return 1;
  return 0;
};

/**
 * Whether `candidate` asymptotically dominates `other`. Two terms are
 * comparable only when their growth is driven by a shared symbol dimension;
 * independent dimensions (n versus m) stay incomparable and remain a sum.
 */
export function dominates(candidate: Term, other: Term): boolean {
  if (isConstant(other)) return true;
  if (isConstant(candidate)) return false;
  const candidateSymbols = new Set(candidate.symbols.keys());
  for (const symbol of candidate.logs.keys()) candidateSymbols.add(symbol);
  for (const symbol of candidate.logLogs.keys()) candidateSymbols.add(symbol);
  if (candidate.exponential) candidateSymbols.add(candidate.exponential.symbol);
  if (candidate.factorial) candidateSymbols.add(candidate.factorial);
  for (const symbol of candidate.ackermanns) candidateSymbols.add(symbol);
  const otherSymbols = new Set(other.symbols.keys());
  for (const symbol of other.logs.keys()) otherSymbols.add(symbol);
  for (const symbol of other.logLogs.keys()) otherSymbols.add(symbol);
  if (other.exponential) otherSymbols.add(other.exponential.symbol);
  if (other.factorial) otherSymbols.add(other.factorial);
  for (const symbol of other.ackermanns) otherSymbols.add(symbol);
  // The inverse Ackermann function grows slower than any logarithm, so an
  // alpha factor is dominated whenever the dominating term carries any log
  // factor (on any symbol): m log m dominates m alpha(n).
  const candidateHasAnyLog = candidate.logs.size > 0;
  const otherHasAnyLog = other.logs.size > 0;
  const otherEffectiveSymbols = new Set(otherSymbols);
  if (candidateHasAnyLog) for (const symbol of other.ackermanns) otherEffectiveSymbols.delete(symbol);
  const candidateEffectiveSymbols = new Set(candidateSymbols);
  if (otherHasAnyLog) for (const symbol of candidate.ackermanns) candidateEffectiveSymbols.delete(symbol);
  // Every growth dimension of `other` must be present in `candidate`.
  const shares = [...otherEffectiveSymbols].some((symbol) => candidateEffectiveSymbols.has(symbol));
  if (!shares) return false;
  for (const symbol of otherEffectiveSymbols) {
    if (!candidateEffectiveSymbols.has(symbol)) return false;
    if (candidate.factorial === symbol) continue;
    if (other.factorial === symbol) return false;
    if (candidate.exponential?.symbol === symbol) continue;
    if (other.exponential?.symbol === symbol) {
      if (!candidate.exponential || candidate.exponential.symbol !== symbol) return false;
      if (candidate.exponential.base < other.exponential.base) return false;
      continue;
    }
    // Same symbol, both non-exponential/non-factorial: compare exponents.
    if ((candidate.symbols.get(symbol) ?? 0) < (other.symbols.get(symbol) ?? 0)) return false;
    if ((candidate.symbols.get(symbol) ?? 0) === (other.symbols.get(symbol) ?? 0)) {
      if (subPolynomialRank(candidate, symbol) < subPolynomialRank(other, symbol)) return false;
      if (subPolynomialRank(candidate, symbol) === subPolynomialRank(other, symbol)) {
        if ((candidate.logs.get(symbol) ?? 0) < (other.logs.get(symbol) ?? 0)) return false;
        if ((candidate.logLogs.get(symbol) ?? 0) < (other.logLogs.get(symbol) ?? 0)) return false;
      }
    }
  }
  // Mixed-dimensional domination: a term with extra growing factors dominates
  // a subset term (n m >= n) as long as every shared exponent is >=.
  return true;
}

/** Inverts a pure-monomial term (negates every exponent); else undefined. */
export function reciprocal(term: Term): Term | undefined {
  if (term.exponential || term.factorial || term.logs.size > 0 || term.logLogs.size > 0 || term.ackermanns.size > 0) return undefined;
  const inverted = constantTerm();
  for (const [symbol, exponent] of term.symbols) inverted.symbols.set(symbol, -exponent);
  return inverted;
}

/** Multiplies two terms; undefined when the product cannot be one term. */
export function multiplyTerms(left: Term, right: Term): Term | undefined {
  if (isConstant(left)) return cloneTerm(right);
  if (isConstant(right)) return cloneTerm(left);
  const result = cloneTerm(left);
  for (const [symbol, exponent] of right.symbols) {
    result.symbols.set(symbol, (result.symbols.get(symbol) ?? 0) + exponent);
  }
  for (const [symbol, exponent] of right.logs) {
    result.logs.set(symbol, (result.logs.get(symbol) ?? 0) + exponent);
  }
  for (const [symbol, exponent] of right.logLogs) {
    result.logLogs.set(symbol, (result.logLogs.get(symbol) ?? 0) + exponent);
  }
  for (const symbol of right.ackermanns) result.ackermanns.add(symbol);
  if (right.exponential) {
    if (result.exponential) {
      if (result.exponential.symbol !== right.exponential.symbol) return undefined;
      result.exponential = { base: roundBase(result.exponential.base * right.exponential.base), symbol: result.exponential.symbol };
    } else {
      result.exponential = { ...right.exponential };
    }
  }
  if (right.factorial) {
    if (result.factorial && result.factorial !== right.factorial) return undefined;
    result.factorial = right.factorial;
  }
  return result;
}

/** Removes dominated and duplicate terms so the sum is canonical. */
export function simplify(bound: Bound): Bound {
  const unique: Term[] = [];
  for (const term of bound) {
    if (!unique.some((existing) => sameTerm(existing, term))) unique.push(term);
  }
  return unique.filter((term) =>
    !unique.some((other) => !sameTerm(other, term) && dominates(other, term)));
}

function sameTerm(left: Term, right: Term): boolean {
  const sameMap = (a: Map<string, number>, b: Map<string, number>): boolean => {
    if (a.size !== b.size) return false;
    for (const [key, value] of a) if (b.get(key) !== value) return false;
    return true;
  };
  return sameMap(left.symbols, right.symbols)
    && sameMap(left.logs, right.logs)
    && sameMap(left.logLogs, right.logLogs)
    && left.ackermanns.size === right.ackermanns.size
    && [...left.ackermanns].every((symbol) => right.ackermanns.has(symbol))
    && left.exponential?.base === right.exponential?.base
    && left.exponential?.symbol === right.exponential?.symbol
    && left.factorial === right.factorial;
}

export const constantBound = (): Bound => [constantTerm()];

export const symbolBound = (symbol: string): Bound => {
  const term = constantTerm();
  term.symbols.set(symbol, 1);
  return [term];
};

export function multiplyBounds(left: Bound, right: Bound): Bound | undefined {
  const products: Term[] = [];
  for (const leftTerm of left) {
    for (const rightTerm of right) {
      const product = multiplyTerms(leftTerm, rightTerm);
      if (!product) return undefined;
      products.push(product);
    }
  }
  return simplify(products);
}

/** Union of two worst-case bounds: the sum, simplified by domination. */
export function maxBounds(left: Bound, right: Bound): Bound {
  return simplify([...left, ...right]);
}

const dimensionOrder = (symbol: string): number => {
  const known = ["n", "m", "q", "t", "k", "W", "sum", "V", "E"];
  const index = known.indexOf(symbol);
  return index === -1 ? known.length : index;
};

/** Sorts sum terms by their primary (lowest-ordered) input dimension. */
const termOrder = (term: Term): number => {
  const symbols = [
    ...term.symbols.keys(), ...term.logs.keys(), ...term.logLogs.keys(),
    ...term.ackermanns,
    ...(term.exponential ? [term.exponential.symbol] : []),
    ...(term.factorial ? [term.factorial] : [])
  ];
  return Math.min(...symbols.map(dimensionOrder), Number.MAX_SAFE_INTEGER);
};

/** Groups terms sharing the same log/ackermann/exponential/factorial factor. */
const sharedFactorKey = (term: Term): string =>
  JSON.stringify([
    [...term.logs.entries()].sort(), [...term.logLogs.entries()].sort(),
    [...term.ackermanns].sort(),
    term.exponential ?? null, term.factorial ?? null
  ]);

export function formatBound(bound: Bound): Complexity {
  const simplified = simplify(bound);
  if (simplified.length === 0) return "O(1)";
  // Factor shared sub-polynomial factors: n·log(n) + m·log(n) prints as
  // "(n + m) log n", matching the conventional presentation of batch bounds.
  const groups = new Map<string, Term[]>();
  for (const term of simplified) {
    const key = sharedFactorKey(term);
    if (!groups.has(key)) groups.set(key, []);
    groups.get(key)!.push(term);
  }
  const pieces = [...groups.values()].map((group) => {
    if (group.length === 1 || isConstant(group[0])) return { joined: formatTerm(group[0]), order: termOrder(group[0]) };
    const hasSharedFactor = group[0].logs.size > 0 || group[0].logLogs.size > 0
      || group[0].ackermanns.size > 0 || Boolean(group[0].exponential) || Boolean(group[0].factorial);
    if (!hasSharedFactor) {
      // Bare symbol dimensions share no factor: keep them as plain sum terms.
      return group.map((entry) => ({ joined: formatTerm(entry), order: termOrder(entry) }));
    }
    const symbolOrder = (entry: Term) => termOrder(entry);
    // Entries share the primary dimension here; a full symbol-signature
    // comparison keeps n ahead of equal-ranked m (conventional n-first sums).
    const rank = (entry: Term): number[] => {
      const names = [
        ...entry.symbols.keys(), ...entry.logs.keys(), ...entry.logLogs.keys(),
        ...entry.ackermanns,
        ...(entry.exponential ? [entry.exponential.symbol] : []),
        ...(entry.factorial ? [entry.factorial] : [])
      ];
      return names.sort((left, right) => dimensionOrder(left) - dimensionOrder(right) || left.localeCompare(right)).map((name) => dimensionOrder(name));
    };
    const orderedGroup = [...group].sort((left, right) => symbolOrder(left) - symbolOrder(right)
      || JSON.stringify(rank(left)).localeCompare(JSON.stringify(rank(right)))
      || formatTerm(left).localeCompare(formatTerm(right)));
    const symbolParts = orderedGroup.map((entry) => {
      const symbolsOnly = formatTerm({ ...entry, logs: new Map(), logLogs: new Map(), ackermanns: new Set(), exponential: undefined, factorial: undefined });
      return symbolsOnly;
    });
    const shared = orderedGroup.map((entry) => {
      const head = formatTerm(entry);
      const symbolsOnly = formatTerm({ ...entry, logs: new Map(), logLogs: new Map(), ackermanns: new Set(), exponential: undefined, factorial: undefined });
      return head.startsWith(symbolsOnly) ? head.slice(symbolsOnly.length).trim() : "";
    })[0];
    const joined = `(${symbolParts.join(" + ")})${shared ? " " + shared : ""}`;
    return { joined, order: Math.min(...group.map((entry) => termOrder(entry))) };
  });
  const ordered = pieces
    .flat()
    .sort((left, right) => left.order - right.order || left.joined.localeCompare(right.joined))
    .map((piece) => piece.joined);
  return `O(${ordered.join(" + ")})` as Complexity;
}

function formatTerm(term: Term): string {
  if (isConstant(term)) return "1";
  const numerator: string[] = [];
  const denominator: string[] = [];
  for (const [symbol, exponent] of term.symbols) {
    if (exponent < 0) {
      const magnitude = -exponent;
      denominator.push(magnitude === 1 ? symbol : `${symbol}^${magnitude}`);
    }
  }
  const pieces: string[] = [];
  const symbolOrder = (symbol: string): number => {
    const known = ["n", "m", "q", "t", "k", "W", "sum", "V", "E"];
    const index = known.indexOf(symbol);
    return index === -1 ? known.length : index;
  };
  const symbols = [...term.symbols.entries()].sort((a, b) => symbolOrder(a[0]) - symbolOrder(b[0]) || a[0].localeCompare(b[0]));
  for (const [symbol, exponent] of symbols) {
    if (exponent < 0) continue;
    if (exponent === 0.5) pieces.push(`sqrt ${symbol}`);
    else if (exponent === 1) pieces.push(symbol);
    else pieces.push(`${symbol}^${exponent}`);
  }
  for (const [symbol, exponent] of term.logs) {
    if (exponent === 1) pieces.push(`log ${symbol}`);
    else pieces.push(`log^${exponent} ${symbol}`);
  }
  for (const [symbol, exponent] of term.logLogs) {
    if (exponent === 1) pieces.push(`log log ${symbol}`);
    else pieces.push(`(log log ${symbol})^${exponent}`);
  }
  for (const symbol of term.ackermanns) pieces.push(`α(${symbol})`);
  if (term.exponential) pieces.push(`${formatBase(term.exponential.base)}^${term.exponential.symbol}`);
  if (term.factorial) pieces.push(`${term.factorial}!`);
  const head = pieces.join(" ") || "1";
  return denominator.length > 0 ? `${head} / ${denominator.join(" * ")}` : head;
}

function formatBase(base: number): string {
  const rounded = roundBase(base);
  return String(rounded);
}

/**
 * Parses an `O(...)` complexity string into a canonical bound. Accepts sums,
 * parenthesized sum groups (distributed into their factors), products, sqrt,
 * nested logs, exponentials, factorials, and the inverse Ackermann factor.
 * Returns undefined for opaque values like "Unknown".
 */
export function parseBound(value: string): Bound | undefined {
  const match = /^O\((.+)\)$/.exec(value.trim());
  if (!match) return undefined;
  const body = match[1].trim();
  if (body === "1") return constantBound();
  return parseSum(body);
}

function splitTopLevelPlus(text: string): string[] {
  const parts: string[] = [];
  let depth = 0;
  let start = 0;
  for (let index = 0; index < text.length; index += 1) {
    const character = text[index];
    if (character === "(") depth += 1;
    else if (character === ")") depth -= 1;
    else if (character === "+" && depth === 0) {
      parts.push(text.slice(start, index));
      start = index + 1;
    }
  }
  parts.push(text.slice(start));
  return parts.map((part) => part.trim()).filter((part) => part.length > 0);
}

/** `(a + b) rest` distributes into [a·rest, b·rest]; bare text is one term. */
function parseGroupedProduct(text: string): Term[] | undefined {
  if (!text.startsWith("(")) {
    const term = parseTerm(text);
    return term ? [term] : undefined;
  }
  let depth = 0;
  let close = -1;
  for (let index = 0; index < text.length; index += 1) {
    if (text[index] === "(") depth += 1;
    else if (text[index] === ")") {
      depth -= 1;
      if (depth === 0) {
        close = index;
        break;
      }
    }
  }
  if (close === -1) return undefined;
  const inner = parseSum(text.slice(1, close));
  if (!inner) return undefined;
  const suffix = text.slice(close + 1).trim();
  const suffixTerm = suffix ? parseTerm(suffix) : constantTerm();
  if (!suffixTerm) return undefined;
  const distributed: Term[] = [];
  for (const term of inner) {
    const product = multiplyTerms(term, suffixTerm);
    if (!product) return undefined;
    distributed.push(product);
  }
  return distributed;
}

function parseSum(text: string): Bound | undefined {
  const terms: Term[] = [];
  for (const part of splitTopLevelPlus(text)) {
    const parsed = parseGroupedProduct(part);
    if (!parsed) return undefined;
    terms.push(...parsed);
  }
  return terms;
}

function parseTerm(text: string): Term | undefined {
  // A rational term `numerator / denominator`: the denominator segment's
  // factors carry negative exponents. Log factors belong to the numerator.
  const segments = text.split("/").map((part) => part.trim()).filter((part) => part.length > 0);
  if (segments.length > 1 && segments.every((part) => /^[A-Za-z_0-9^ sqrt*\-+.]+$/.test(part))) {
    const base = parseTerm(segments[0]);
    if (!base) return undefined;
    let result = base;
    for (let index = 1; index < segments.length; index += 1) {
      const divisor = parseTerm(segments[index]);
      if (!divisor) return undefined;
      const inverted = reciprocal(divisor);
      if (!inverted) return undefined;
      const product = multiplyTerms(result, inverted);
      if (!product) return undefined;
      result = product;
    }
    return result;
  }
  const term = constantTerm();
  let rest = text.trim();
  if (rest === "" || rest === "1") return term;
  // Consume one recognized factor at a time from the front of the string.
  // Order matters: `log log x` before `log x`, base^symbol before a bare
  // symbol (they are disjoint by first character, but keep it explicit).
  while (rest) {
    let match: RegExpExecArray | null;
    if ((match = /^([A-Za-z_][A-Za-z0-9_]*)!/.exec(rest))) {
      if (term.factorial && term.factorial !== match[1]) return undefined;
      term.factorial = match[1];
    } else if ((match = /^([0-9]*\.?[0-9]+)\^([A-Za-z_][A-Za-z0-9_]*)/.exec(rest))) {
      const factor: Term["exponential"] = { base: Number(match[1]), symbol: match[2] };
      if (term.exponential) {
        if (term.exponential.symbol !== factor.symbol) return undefined;
        term.exponential = { base: roundBase(term.exponential.base * factor.base), symbol: factor.symbol };
      } else {
        term.exponential = factor;
      }
    } else if ((match = /^log log ([A-Za-z_][A-Za-z0-9_]*)/.exec(rest))) {
      term.logLogs.set(match[1], (term.logLogs.get(match[1]) ?? 0) + 1);
    } else if ((match = /^log\^(\d+) ([A-Za-z_][A-Za-z0-9_]*)/.exec(rest))
      ?? (match = /^log ([A-Za-z_][A-Za-z0-9_]*)/.exec(rest))
      ?? (match = /^log\(([A-Za-z_][A-Za-z0-9_]*)\)/.exec(rest))) {
      term.logs.set(match[2] ?? match[1]!, Number(match[2] ? match[1] : 1));
    } else if ((match = /^(?:α|alpha)\(([A-Za-z_][A-Za-z0-9_]*)\)/.exec(rest))) {
      term.ackermanns.add(match[1]);
    } else if ((match = /^(?:sqrt|√) ?([A-Za-z_][A-Za-z0-9_]*)/.exec(rest))) {
      term.symbols.set(match[1], (term.symbols.get(match[1]) ?? 0) + 0.5);
    } else if ((match = /^([A-Za-z_][A-Za-z0-9_]*)(?:\^(\d+(?:\.\d+)?))?/.exec(rest))) {
      term.symbols.set(match[1], (term.symbols.get(match[1]) ?? 0) + Number(match[2] ?? 1));
    } else {
      return undefined;
    }
    rest = rest.slice(match[0].length).trim();
  }
  return term;
}

/** Structural multiset equality of two simplified bounds. */
export function boundsEqual(left: Bound, right: Bound): boolean {
  if (left.length !== right.length) return false;
  const used = new Set<number>();
  return left.every((term) => {
    const index = right.findIndex((other, otherIndex) => !used.has(otherIndex) && sameTerm(term, other));
    if (index === -1) return false;
    used.add(index);
    return true;
  });
}

/** Convenience: multiply two complexity strings through the canonical algebra. */
export function multiplyComplexities(left: Complexity, right: Complexity): Complexity | undefined {
  const a = parseBound(left);
  const b = parseBound(right);
  if (!a || !b) return undefined;
  const product = multiplyBounds(a, b);
  return product ? formatBound(product) : undefined;
}
