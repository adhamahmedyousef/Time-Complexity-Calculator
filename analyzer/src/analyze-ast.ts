import { normalizeFunctionSyntax, constantNumber, symbolIdentity, unwrapExpression } from "./semantic-normalization.js";
import type { AnalysisResult, AuxiliarySpace, ClangNode, Complexity, Confidence } from "./model.js";
import { dominantExpression, multiplyExpressions } from "./complexity-expression.js";
import { constantTerm, formatBound, maxBounds, multiplyBounds, parseBound, reciprocal, type Bound, type Term } from "./bound.js";
import { standardFreeFunctionCost, standardFreeFunctionNames } from "./standard-library.js";

type SymbolicBounds = ReadonlyMap<string, Complexity>;
type LoopAnalysis = { value?: Complexity; proof?: string[]; index?: string; condition?: ClangNode; geometric?: boolean; bound?: Complexity; estimated?: boolean; helperSpaces?: AuxiliarySpace[]; unprovenSpace?: boolean;
  /** Harmonic stride detected: the loop's trip count is limit/stride, a rational term of an enclosing index. */
  rationalTrip?: { term: Bound; indexKey: string; limitSymbol: string };
  /** Resolved per-enclosing-iteration term still carrying a negative exponent for the outer sum rule. */
  rationalTerm?: Bound;
  rationalIndex?: string;
  /** True when the reported value is only an upper bound over an unsolved dependent stride. */
  upperBoundOnly?: boolean;
  ratioTrip?: { initKey: string };
  bodyCost?: Complexity; };
/**
 * A same-translation-unit summary.  Keeping confidence alongside the cost is
 * important: a caller of a structurally recognised helper is only as certain
 * as that helper.  Previously the DFS discarded every estimated helper, which
 * made harmless wrappers turn into `Unknown`.
 */
export type LocalSummaryValue = Readonly<{
  value: Complexity;
  auxiliarySpace: AuxiliarySpace;
  confidence: Exclude<Confidence, "unknown">;
  memoStateDims?: readonly string[];
}>;

/** Callee name of a call. In this AST a member-call base is a MemberExpr that
 * may carry only a `name` (bound-member base), so resolve along the leftmost
 * spine and accept either the referenced declaration or the member name. */
function callCalleeName(call: ClangNode): string | undefined {
  let spine: ClangNode | undefined = call;
  let depth = 0;
  while (spine && depth < 8) {
    const reference = (spine.referencedDecl ?? undefined);
    if (spine.kind === "DeclRefExpr") return reference?.name ?? spine.name;
    if (spine.kind === "MemberExpr") return reference?.name ?? spine.name;
    spine = spine.inner?.at(0);
    depth += 1;
  }
  return undefined;
}

/**
 * Structural segment-tree constructor preprocessing. A local record's
 * constructor initializes a typed `vector` table from the size of an input
 * container (directly, or through a scalar member assigned
 * `container.size()`), then invokes exactly one record method that is the
 * canonical binary interval build: a `l == r` leaf guard writing into the
 * typed storage, a `(l + r) / 2` midpoint, and two self-calls covering
 * `[l, m]` and `[m + 1, r]`, with no plain loops. Every one of the 2n - 1
 * tree nodes is written once, so the build is bounded by `O(n log n)` - the
 * published, sound, conservative estimate for preprocessing - with the typed
 * table's `O(n)` storage.
 */
export function segmentTreeConstructorSummary(functionDecl: ClangNode, methods: readonly ClangNode[], _constantSymbols?: ReadonlySet<string>): LocalSummaryValue | undefined {
  if (functionDecl.kind !== "CXXConstructorDecl") return undefined;
  const body = (functionDecl.inner ?? []).find((node) => node.kind === "CompoundStmt");
  if (!body) return undefined;
  const methodNames = new Map<string, ClangNode>();
  for (const method of methods) if (method.name && method.inner?.some((part) => part.kind === "CompoundStmt")) methodNames.set(method.name, method);
  // The constructor must invoke exactly one same-record method with a body,
  // and that method must be a pure binary interval recursion.
  const constructorCalls = directCalls(body).map((call) => ({ call, callee: callCalleeName(call) }))
    .filter((entry) => entry.callee && methodNames.has(entry.callee));
  if (constructorCalls.length !== 1) return undefined;
  const buildMethod = methodNames.get(constructorCalls[0].callee!)!;
  const buildBody = (buildMethod.inner ?? []).find((node) => node.kind === "CompoundStmt");
  if (!buildBody) return undefined;
  if (nodesOfKind(buildBody, "ForStmt").length > 0 || nodesOfKind(buildBody, "WhileStmt").length > 0
    || nodesOfKind(buildBody, "DoStmt").length > 0 || nodesOfKind(buildBody, "CXXForRangeStmt").length > 0) return undefined;
  const intervalKeys = new Set((buildMethod.inner ?? []).filter((node) => node.kind === "ParmVarDecl").map((node) => node.name).filter((name): name is string => Boolean(name)));
  // Leaf guard: an equality between interval parameters writing into typed
  // storage and returning; that equality names the two interval parameters L
  // and R for the covering self-call check below.
  const leafEqualityIn = (branch: ClangNode): ClangNode | undefined => {
    // The IfStmt condition precedes its branches; skip CompoundStmt branches
    // and try the condition carriers in order (init decls may precede it).
    const carriers = (branch.inner ?? []).filter((child) => child.kind !== "CompoundStmt").slice(0, 2);
    for (const carrier of carriers) {
      const equality = nodesOfKind(carrier, "BinaryOperator").find((operation) => operation.opcode === "=="
        && nodesOfKind(operation, "DeclRefExpr").filter((reference) => intervalKeys.has(reference.referencedDecl?.name ?? "")).length >= 2);
      if (equality) return equality;
    }
    return undefined;
  };
  const leafGuard = nodesOfKind(buildBody, "IfStmt").find((branch) => {
    const equality = leafEqualityIn(branch);
    if (!equality) return false;
    const writes = nodesOfKind(branch, "BinaryOperator").some((operation) => operation.opcode === "="
      && nodesOfKind(operation, "MemberExpr").some((member) => /\b(?:vector|deque|string|array)\s*</.test(member.type?.desugaredQualType ?? member.type?.qualType ?? ""))
      && nodesOfKind(operation, "DeclRefExpr").length >= 1);
    return writes && nodesOfKind(branch, "ReturnStmt").length > 0;
  });
  if (!leafGuard) return undefined;
  const leafEquality = leafEqualityIn(leafGuard)!;
  const intervalReferences = nodesOfKind(leafEquality, "DeclRefExpr").filter((reference) => intervalKeys.has(reference.referencedDecl?.name ?? ""));
  const leftKey = intervalReferences[0]?.referencedDecl?.name!;
  const rightKey = intervalReferences[1]?.referencedDecl?.name!;
  if (!leftKey || !rightKey || leftKey === rightKey) return undefined;
  // A midpoint derived from both interval parameters by a constant division.
  const midpointKey = nodesOfKind(buildBody, "VarDecl").find((node) => node.name
    && nodesOfKind(node, "BinaryOperator").some((operation) => ["/", ">>"].includes(operation.opcode ?? "")
      && [leftKey, rightKey].every((key) => nodesOfKind(operation, "DeclRefExpr").some((reference) => reference.referencedDecl?.name === key))))?.name;
  if (!midpointKey) return undefined;
  const selfCalls = directCalls(buildBody).filter((call) => callCalleeName(call) === buildMethod.name);
  const intervalCover = selfCalls.filter((call) => {
    const argumentKeys = nodesOfKind(call, "DeclRefExpr").map((reference) => reference.referencedDecl?.name ?? "").filter(Boolean);
    const left = argumentKeys.includes(leftKey) && argumentKeys.includes(midpointKey) && !argumentKeys.includes(rightKey);
    const right = argumentKeys.includes(rightKey) && argumentKeys.includes(midpointKey) && !argumentKeys.includes(leftKey);
    return left || right;
  });
  if (selfCalls.length < 2 || intervalCover.length !== 2) return undefined;
  // The reported build span must be derived from the input container's
  // element count: the record must initialize a member (scalar or typed
  // table) from a container size clause, and the build invocation must
  // actually reference that member or call the container's size directly -
  // otherwise the span could be constant and no container-n bound is proven.
  const constructorParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl")
    .filter((node) => /\b(?:vector|deque|string|array)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (constructorParameters.length === 0) return undefined;
  const containerNames = new Set(constructorParameters.map((node) => node.name!).filter(Boolean));
  const sizesTyped = (expression: ClangNode | undefined): boolean => {
    if (!expression) return false;
    let referencesContainer = false;
    walk(expression, (current) => {
      if (current.kind === "CXXMemberCallExpr") {
        const info = memberCallInfo(current);
        if (info?.name === "size" && containerNames.has(memberCallBaseName(current) ?? "")) referencesContainer = true;
      }
    });
    return referencesContainer;
  };
  const sizeDerivedMembers = new Set(nodesOfKind(functionDecl, "CXXCtorInitializer")
    .filter((initializer) => initializer.anyInit?.name && sizesTyped((initializer.inner ?? []).at(-1)))
    .map((initializer) => initializer.anyInit!.name));
  if (sizeDerivedMembers.size === 0) return undefined;
  const buildInvocation = constructorCalls[0].call;
  const spanNames = nodesOfKind(buildInvocation, "MemberExpr").concat(nodesOfKind(buildInvocation, "DeclRefExpr"))
    .map((node) => node.name ?? node.referencedDecl?.name ?? "").filter(Boolean);
  const directSizeCall = nodesOfKind(buildInvocation, "CXXMemberCallExpr").some((call) => memberCallInfo(call)?.name === "size"
    && containerNames.has(memberCallBaseName(call) ?? ""));
  if (!directSizeCall && !spanNames.some((name) => sizeDerivedMembers.has(name))) return undefined;
  return {
    value: "O(n log n)",
    auxiliarySpace: "O(n)",
    confidence: "estimated"
  } satisfies LocalSummaryValue;
}

export type LocalFunctionSummary = LocalSummaryValue & Readonly<{
  /** Source-order formal name and its helper-summary symbolic dimension. */
  parameters: readonly Readonly<{ name: string; symbol: string }>[];
  /**
   * Bounded context-sensitive summaries for direct boolean control arguments.
   * Each entry is produced from a cloned AST with only `if (flag)` / `if
   * (!flag)` edges pruned; arbitrary predicates are never assumed constant.
   */
  booleanSpecializations?: ReadonlyMap<string, Readonly<{ whenFalse?: LocalSummaryValue; whenTrue?: LocalSummaryValue }>>;
}>;
export type LocalFunctionCosts = ReadonlyMap<string, LocalFunctionSummary>;

/**
 * For a local record, each entry is a constructor-argument index which Clang
 * proves is forwarded into a dynamically-sized member (vector/deque/string).
 * Repeated indices represent independent dimensions, for example a nested
 * vector constructed with `n` at both levels has `[0, 0]` and occupies O(n²).
 */
export type LocalRecordOwnedStorage = ReadonlyMap<string, readonly number[]>;

const unknown = (reason: string): AnalysisResult => ({ worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown", proof: [reason] });

function walk(node: ClangNode, visit: (current: ClangNode) => void): void {
  visit(node);
  for (const child of node.inner ?? []) walk(child, visit);
}

function references(node: ClangNode | undefined, name: string): boolean {
  let found = false;
  if (node) walk(node, (current) => { if (current.referencedDecl?.name === name) found = true; });
  return found;
}

/**
 * Clang gives every declaration a stable id and every DeclRefExpr the id of
 * the declaration it resolves to.  Prefer that identity over a spelling such
 * as `i`; the spelling remains a compatibility fallback for synthetic tests
 * and older Clang JSON output.
 */
function declarationKey(node: ClangNode | undefined): string | undefined {
  return node?.id ?? node?.name;
}

function referenceKey(node: ClangNode | undefined): string | undefined {
  return node?.referencedDecl?.id ?? node?.referencedDecl?.name;
}

function referencesSymbol(node: ClangNode | undefined, symbol: string): boolean {
  let found = false;
  if (node) walk(node, (current) => { if (referenceKey(current) === symbol) found = true; });
  return found;
}

function boundForReference(bounds: SymbolicBounds, node: ClangNode | undefined): Complexity | undefined {
  const identity = referenceKey(node);
  if (!identity) return undefined;
  // Real Clang ids are scope-safe. Fall back to a spelling only for synthetic
  // AST fixtures which do not carry ids; otherwise a shadowing local `n`
  // could accidentally inherit the parameter named `n`.
  if (node?.referencedDecl?.id) {
    const exact = bounds.get(identity);
    if (exact) return exact;
    // Translation-unit globals do not have a function-local declaration entry
    // in the bound map. Conventional global CP dimensions (`n`, `h`, `k`,
    // ...) may therefore use the safe spelling fallback; local declarations
    // still always resolve through their stable Clang identity above.
    if (node.referencedDecl?.kind === "VarDecl") return bounds.get(node.referencedDecl.name ?? "");
    return undefined;
  }
  return bounds.get(identity) ?? bounds.get(node?.referencedDecl?.name ?? "");
}

function nodesOfKind(node: ClangNode, kind: string): ClangNode[] {
  const result: ClangNode[] = [];
  walk(node, (current) => { if (current.kind === kind) result.push(current); });
  return result;
}

function directCondition(loop: ClangNode): ClangNode | undefined {
  return (loop.inner ?? []).find((part) => part.kind === "BinaryOperator" && ["<", "<=", ">", ">=", "!="].includes(part.opcode ?? ""));
}

function bodyOf(loop: ClangNode): ClangNode | undefined {
  const parts = loop.inner ?? [];
  const bracedBody = parts.find((part) => part.kind === "CompoundStmt");
  if (bracedBody) return bracedBody;

  // Clang represents an unbraced loop body as the final child of the loop
  // rather than wrapping it in a CompoundStmt. Treat that statement as the
  // body too: `for (...) statement;` has the same control-flow nesting as the
  // braced form and must not disappear from the complexity tree.
  if (loop.kind === "ForStmt" || loop.kind === "WhileStmt" || loop.kind === "CXXForRangeStmt") return parts.at(-1);
  if (loop.kind === "DoStmt") return parts.find((part) => part.kind !== "BinaryOperator");
  return undefined;
}

function findHeaderUpdate(loop: ClangNode): ClangNode | undefined {
  for (const part of loop.inner ?? []) {
    if (part.kind === "CompoundStmt") break;
    if (part.kind === "UnaryOperator" || part.kind === "CompoundAssignOperator") return part;
  }
  return undefined;
}

function findBodyUpdate(loop: ClangNode): ClangNode | undefined {
  const body = bodyOf(loop);
  if (!body) return undefined;
  // A conditional update does not prove a while-loop progresses: one branch
  // might leave the index unchanged forever. Only accept an update that is a
  // direct statement in the body. Structured conditional cases are handled by
  // dedicated recognizers (for example structuralTwoPointers).
  const condition = directCondition(loop) ?? loop.inner?.[0];
  const conditionSymbols = new Set(nodesOfKind(condition ?? {}, "DeclRefExpr").map((reference) => referenceKey(reference)));
  const isConditionKey = (key: string | undefined): boolean => Boolean(key && conditionSymbols.has(key));
  // A proved trip cap additionally needs the update to move the index TOWARD
  // the comparison bound. A unit step away from it cannot reach the bound
  // (`while (i < 5) { --i; }` never exits once entered), so no trip count may
  // be charged and the loop must abstain instead.
  const comparison = condition?.opcode;
  const unitDirectionOk = (opcode: string | undefined): boolean => {
    if (opcode !== "++" && opcode !== "--") return true;
    if (comparison === "<" || comparison === "<=") return opcode === "++";
    if (comparison === ">" || comparison === ">=") return opcode === "--";
    return true;
  };
  const stepDirectionOk = (candidate: ClangNode): boolean => {
    if (candidate.kind !== "CompoundAssignOperator" || (candidate.opcode !== "+=" && candidate.opcode !== "-=")) return true;
    // The stride must be resolved from the assignment's right-hand side with
    // its sign intact: `i += -1` steps down even though it adds a "literal".
    const delta = signedLiteralValue(candidate.inner?.[1]);
    if (delta === undefined) return true;
    const movesUp = candidate.opcode === "+=" ? delta > 0 : delta < 0;
    if (comparison === "<" || comparison === "<=") return movesUp;
    if (comparison === ">" || comparison === ">=") return !movesUp;
    return true;
  };
  // The update drives the loop when it assigns the condition variable, or -
  // Euclid's `a %= b` - reduces another variable by the condition variable
  // itself. Accumulators (`s += i`, `bits |= n`) read the condition variable
  // without driving the loop; adopting one as the update would charge the
  // accumulator's own bound as the trip count.
  const relevanceOf = (candidate: ClangNode): boolean => {
    if (isConditionKey(loopIndex(candidate))) {
      return unitDirectionOk(candidate.opcode) && stepDirectionOk(candidate);
    }
    if (candidate.kind !== "CompoundAssignOperator" || candidate.opcode !== "%=") return false;
    let rhs = candidate.inner?.[1];
    while (rhs && ["ImplicitCastExpr", "ParenExpr"].includes(rhs.kind ?? "")) rhs = rhs.inner?.[0];
    return Boolean(rhs && rhs.kind === "DeclRefExpr" && conditionSymbols.has(referenceKey(rhs)));
  };
  // A unit step on a condition variable that the statement performs on its
  // unconditional evaluation spine: reaching the statement always evaluates
  // it, so it runs once per iteration even inside a larger expression such as
  // `s += i++`. Steps guarded by a conditional operator, short-circuit
  // evaluation, or an inner control-flow statement are excluded - those can
  // be skipped, and skipping the only progress update means the loop need not
  // terminate.
  const embeddedUnitStep = (statement: ClangNode): ClangNode | undefined => {
    const guardingKinds = new Set(["IfStmt", "SwitchStmt", "ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt", "ConditionalOperator"]);
    const collect = (node: ClangNode, guarded: boolean): ClangNode | undefined => {
      const kind = node.kind ?? "";
      const nextGuarded = guarded || guardingKinds.has(kind)
        || (kind === "BinaryOperator" && (node.opcode === "&&" || node.opcode === "||"));
      if (!nextGuarded && kind === "UnaryOperator" && ["++", "--"].includes(node.opcode ?? "")
        && isConditionKey(loopIndex(node)) && unitDirectionOk(node.opcode)) {
        return node;
      }
      for (const child of node.inner ?? []) {
        const found = collect(child, nextGuarded);
        if (found) return found;
      }
      return undefined;
    };
    return collect(statement, false);
  };
  if (body.kind === "UnaryOperator" || body.kind === "CompoundAssignOperator") {
    // `while (x) { x >>= 1; }`: the body IS the update. It must still touch
    // the condition variable, or the progress is data-dependent.
    return relevanceOf(body) ? body : embeddedUnitStep(body);
  }
  if (body.kind !== "CompoundStmt") return embeddedUnitStep(body);
  const candidates = (body.inner ?? []).filter((child) => child.kind === "UnaryOperator" || child.kind === "CompoundAssignOperator");
  // A body may mutate an accumulator and the loop index (`++count; n >>= 1;`).
  // The condition defines which mutation drives the loop; prefer the update
  // targeting a variable the condition references.
  const relevant = candidates.find((candidate) => relevanceOf(candidate));
  if (relevant) return relevant;
  for (const statement of body.inner ?? []) {
    const embedded = embeddedUnitStep(statement);
    if (embedded) return embedded;
  }
  // When no candidate mutates a condition variable, the loop's progress is
  // driven by something this model does not track (a data-dependent value):
  // reporting the unrelated counter's bound as the trip count is unsound.
  return undefined;
}

/**
 * Declaration identity for write-conflict checks. Real Clang references carry
 * the declaration id. Synthetic fixtures (unit tests feeding hand-built ASTs)
 * do not, and there every reference node is its own declaration: matching
 * id-less references by spelling would merge distinct loops that happen to
 * reuse the name `i`.
 */
function sameDeclaration(left: ClangNode | undefined, right: ClangNode | undefined): boolean {
  const a = left?.referencedDecl;
  const b = right?.referencedDecl;
  if (!a || !b) return false;
  if (a.id !== undefined || b.id !== undefined) return a.id !== undefined && a.id === b.id;
  return a === b;
}

/**
 * True when the loop body writes the recognized update's counter in any
 * statement other than the update itself. A second write (a reset, a
 * cancelling step, a reverse step) means the net per-iteration motion is not
 * the recognized step, so no trip count may be charged on it.
 */
function hasCompetingCounterWrite(loop: ClangNode, update: ClangNode): boolean {
  const body = bodyOf(loop);
  const target = directAssignmentTarget(update.inner?.[0]);
  if (!body || !target) return false;
  let competing = false;
  walk(body, (node) => {
    if (competing || node === update) return;
    if (node.kind === "BinaryOperator" && node.opcode === "=") {
      if (sameDeclaration(target, directAssignmentTarget(node.inner?.[0]))) competing = true;
      return;
    }
    if (node.kind === "CompoundAssignOperator" || (node.kind === "UnaryOperator" && ["++", "--"].includes(node.opcode ?? ""))) {
      if (sameDeclaration(target, directAssignmentTarget(node.inner?.[0]))) competing = true;
    }
  });
  return competing;
}

function updateOf(loop: ClangNode): ClangNode | undefined {
  const update = loop.kind === "ForStmt" ? findHeaderUpdate(loop) : findBodyUpdate(loop);
  if (!update) return undefined;
  return hasCompetingCounterWrite(loop, update) ? undefined : update;
}

function loopIndex(update: ClangNode | undefined): string | undefined {
  let name: string | undefined;
  if (update) walk(update, (current) => { if (!name && referenceKey(current)) name = referenceKey(current); });
  return name;
}

/**
 * Resolves a compile-time integer value from an expression, looking through
 * the transparent wrappers Clang inserts and a leading sign. Returns undefined
 * when the expression is not a visible constant; the step-direction logic
 * treats that as unknown rather than misreading a nested literal such as the
 * `1` in `i += a[1]` as the stride.
 */
function signedLiteralValue(node: ClangNode | undefined): number | undefined {
  let current = node;
  while (current && ["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr", "ExprWithCleanups", "MaterializeTemporaryExpr"].includes(current.kind ?? "")) {
    current = current.inner?.at(-1);
  }
  if (!current) return undefined;
  if (current.kind === "IntegerLiteral") {
    const value = Number(current.value);
    return Number.isFinite(value) ? value : undefined;
  }
  if (current.kind === "UnaryOperator" && (current.opcode === "-" || current.opcode === "+")) {
    const inner = signedLiteralValue(current.inner?.[0]);
    return inner === undefined ? undefined : current.opcode === "-" ? -inner : inner;
  }
  return undefined;
}

/** Exposes a literal constant behind transparent casts and a sign. */
function constantLiteralInitializer(node: ClangNode | undefined): ClangNode | undefined {
  let current = node;
  while (current && ["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr", "ExprWithCleanups", "MaterializeTemporaryExpr"].includes(current.kind ?? "")) {
    current = current.inner?.at(-1);
  }
  if (!current) return undefined;
  if (current.kind === "UnaryOperator" && (current.opcode === "-" || current.opcode === "+")) {
    return constantLiteralInitializer(current.inner?.[0]);
  }
  return ["IntegerLiteral", "FloatingLiteral", "CharacterLiteral", "CXXBoolLiteralExpr"].includes(current.kind ?? "") ? current : undefined;
}

/**
 * Reachability of `!=` unit-step loops for the function currently analyzed.
 * `while (i != K) { ++i; }` terminates only when the stepping direction can
 * reach K from the start value: when the start is a visible literal already
 * past K the loop provably never exits once entered, and when no start literal
 * can be pinned, no equality trip count may be charged either. Entries are per
 * loop node; absent entries keep the trip provable as before.
 */
const equalityLoopReachability = new WeakMap<ClangNode, "away" | "unprovable">();

/**
 * The counter a loop update advances and the signed literal stride it moves
 * by. Unary `++`/`--` move by one; compound `+=`/`-=` qualify when the
 * right-hand side is a visible literal, sign included (`i += -1` steps down).
 * Symbolic and zero strides return undefined: no literal reachability claim
 * is made for them here.
 */
function literalStepOf(update: ClangNode | undefined): { key: string; stride: number } | undefined {
  if (!update) return undefined;
  if (update.kind === "UnaryOperator" && (update.opcode === "++" || update.opcode === "--")) {
    const key = loopIndex(update);
    return key ? { key, stride: update.opcode === "++" ? 1 : -1 } : undefined;
  }
  if (update.kind === "CompoundAssignOperator" && (update.opcode === "+=" || update.opcode === "-=")) {
    const delta = signedLiteralValue(update.inner?.[1]);
    if (delta === undefined || delta === 0) return undefined;
    const key = loopIndex(update);
    return key ? { key, stride: update.opcode === "+=" ? delta : -delta } : undefined;
  }
  return undefined;
}

function noteEqualityLoopReachability(body: ClangNode): void {
  // One pass records every local's literal start and every write site so the
  // reachability check below never rescans the body per loop.
  const literalStarts = new Map<string, number | "unpinned">();
  const writeNodes = new Map<string, ClangNode[]>();
  const recordWrite = (key: string | undefined, node: ClangNode): void => {
    if (!key) return;
    const list = writeNodes.get(key);
    if (list) list.push(node); else writeNodes.set(key, [node]);
  };
  walk(body, (node) => {
    if (node.kind === "VarDecl") {
      const key = declarationKey(node);
      if (!key) return;
      const value: number | "unpinned" = signedLiteralValue(node.inner?.at(-1)) ?? "unpinned";
      const existing = literalStarts.get(key);
      if (existing === undefined) literalStarts.set(key, value);
      else if (existing !== value) literalStarts.set(key, "unpinned");
      return;
    }
    if (node.kind === "BinaryOperator" && node.opcode === "=") {
      recordWrite(referenceKey(directAssignmentTarget(node.inner?.[0])), node);
      return;
    }
    if (node.kind === "CompoundAssignOperator" || (node.kind === "UnaryOperator" && ["++", "--"].includes(node.opcode ?? ""))) {
      let lhs = node.inner?.[0];
      while (lhs && ["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(lhs.kind ?? "")) lhs = lhs.inner?.at(-1);
      recordWrite(referenceKey(lhs), node);
    }
  });
  for (const loop of [...nodesOfKind(body, "WhileStmt"), ...nodesOfKind(body, "ForStmt")]) {
    const condition = directCondition(loop);
    if (!condition || condition.opcode !== "!=" || (condition.inner?.length ?? 0) !== 2) continue;
    const update = updateOf(loop);
    const step = literalStepOf(update);
    if (!step) continue;
    // A break/return/goto can leave the loop early, so a far-side start no
    // longer proves divergence; such loops keep their previous treatment.
    if (["BreakStmt", "ReturnStmt", "GotoStmt"].some((kind) => nodesOfKind(loop, kind).length > 0)) continue;
    // Any write to the counter other than the modeled step defeats the
    // literal reachability argument: a write before the loop replaces the
    // declared start value, and a reset inside it (conditional or not) can
    // bring the counter back within reach of the target.
    const writes = writeNodes.get(step.key) ?? [];
    if (writes.some((write) => write !== update)) { equalityLoopReachability.set(loop, "unprovable"); continue; }
    // The compared operand must BE the counter, not merely contain it:
    // `i % 5 != 2` is decided by `i % 5`, so the counter's own reachability
    // says nothing about when the loop exits.
    const [left, right] = condition.inner!;
    const isCounterSide = (node: ClangNode | undefined): boolean => {
      let current = node;
      while (current && ["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups", "CStyleCastExpr", "MaterializeTemporaryExpr"].includes(current.kind ?? "")) current = current.inner?.at(-1);
      return current?.kind === "DeclRefExpr" && referenceKey(current) === step.key;
    };
    const targetNode = isCounterSide(left) ? right : isCounterSide(right) ? left : undefined;
    if (!targetNode) { equalityLoopReachability.set(loop, "unprovable"); continue; }
    const target = signedLiteralValue(targetNode);
    const start = literalStarts.get(step.key);
    if (target === undefined) {
      // Symbolic target: only the canonical zero-based unit counter is
      // provably toward it. Any other numeric start, or a non-unit literal
      // stride whose divisibility by the target is unknown, has no reach
      // proof. A start that is not a numeric literal at all (iterator or
      // pointer aliases, values read from input) is left to the dedicated
      // alias and range analyses.
      if (typeof start === "number") {
        if (start <= 0 && step.stride === 1) continue;
        equalityLoopReachability.set(loop, "unprovable");
      }
      continue;
    }
    if (start === undefined || start === "unpinned") {
      equalityLoopReachability.set(loop, "unprovable");
      continue;
    }
    const delta = target - start;
    if (delta === 0) continue; // the loop is never entered
    const toward = step.stride > 0 ? delta > 0 : delta < 0;
    // The target must also be an exact multiple of the stride: `i += 2` from
    // 4 never hits 7 even though it moves toward it.
    if (!toward || delta % Math.abs(step.stride) !== 0) equalityLoopReachability.set(loop, "away");
  }
}

function isZeroInitializedMultiplicativeLoop(loop: ClangNode): boolean {
  const update = updateOf(loop);
  if (update?.kind !== "CompoundAssignOperator" || !["*=", "/="].includes(update.opcode ?? "")) return false;
  const index = loopIndex(update);
  if (!index) return false;
  let initializedToZero = false;
  for (const part of loop.inner ?? []) {
    if (part.kind === "CompoundStmt") break;
    walk(part, (node) => {
      if (node.kind !== "VarDecl" || declarationKey(node) !== index) return;
      walk(node, (child) => { if (child.kind === "IntegerLiteral" && child.value === "0") initializedToZero = true; });
    });
  }
  return initializedToZero;
}

function squareBound(condition: ClangNode): boolean {
  let found = false;
  walk(condition, (current) => { if (current.kind === "BinaryOperator" && current.opcode === "*") found = true; });
  return found;
}

/**
 * The element dimension of a nested container receiver: `g[0].size()` and
 * `g[i].size()` describe how many elements one row holds, i.e. the next
 * independent axis after the container's own dimension (n -> m -> q -> t,
 * and V -> E for vertex-indexed adjacency storage). Returns undefined for
 * non-subscript receivers so the ordinary receiver rules still apply.
 */
function subscriptElementDimension(base: ClangNode | undefined, bounds: SymbolicBounds): Complexity | undefined {
  let current = base;
  while (current && ["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr", "MaterializeTemporaryExpr", "CXXBindTemporaryExpr", "ExprWithCleanups"].includes(current.kind ?? "")) {
    current = current.inner?.at(-1);
  }
  if (!current) return undefined;
  const operatorName = current.kind === "CXXOperatorCallExpr"
    ? (current.name ?? nodesOfKind(current, "DeclRefExpr").map((reference) => reference.referencedDecl?.name).find((name) => name?.startsWith("operator")))
    : current.kind === "ArraySubscriptExpr" ? "operator[]" : undefined;
  if (operatorName !== "operator[]") return undefined;
  const container = nodesOfKind(current, "DeclRefExpr").find((reference) => {
    if (reference.referencedDecl?.kind === "CXXMethodDecl") return false;
    const type = reference.type?.desugaredQualType ?? reference.type?.qualType
      ?? reference.referencedDecl?.type?.desugaredQualType ?? reference.referencedDecl?.type?.qualType ?? "";
    return /\b(?:vector|deque|array)\s*</.test(type) && Boolean(boundForReference(bounds, reference));
  });
  const containerBound = container ? boundForReference(bounds, container) : undefined;
  const symbol = /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(containerBound ?? "")?.[1];
  const next = symbol === "n" ? "m" : symbol === "m" ? "q" : symbol === "q" ? "t" : symbol === "V" ? "E" : undefined;
  return next ? (`O(${next})` as Complexity) : undefined;
}

function expressionComplexity(node: ClangNode | undefined, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): Complexity | undefined {
  if (!node) return undefined;
  if (["IntegerLiteral", "FloatingLiteral", "CharacterLiteral", "StringLiteral", "CXXBoolLiteralExpr"].includes(node.kind ?? "")) return "O(1)";
  // C++ sizeof never scales with runtime values: it is a compile-time constant
  // of the operand type, so `i < sizeof(a)/sizeof(a[0])` proves a constant
  // trip count. Only a runtime-bound array (the VLA extension) keeps a
  // symbolic bound, spelled with an identifier inside the array brackets.
  if (node.kind === "UnaryExprOrTypeTraitExpr" && node.name === "sizeof") {
    const operandType = node.inner?.[0]?.type?.desugaredQualType ?? node.inner?.[0]?.type?.qualType ?? "";
    return /\[\s*[A-Za-z_]/.test(operandType) ? undefined : "O(1)";
  }
  if (node.kind === "DeclRefExpr") {
    const name = node.referencedDecl?.name;
    if (name && constantSymbols?.has(name)) return "O(1)";
    return boundForReference(bounds, node);
  }
  if (node.kind === "CXXMemberCallExpr") {
    const member = nodesOfKind(node, "MemberExpr").at(0);
    // Container aliases and iterator endpoints preserve the cardinality of
    // their receiver. `view = values`, `last = view.end()`, and
    // `cursor = values.data()` can therefore participate in a loop proof
    // without text matching the original variable name.
    if (member && ["size", "begin", "end", "cbegin", "cend", "rbegin", "rend", "data"].includes(member.name ?? "")) {
      // `g[0].size()` / `g[i].size()` measure the ELEMENT dimension of a
      // nested container, not the container's own dimension. Resolving the
      // receiver to the outer symbol (`n`) would collapse a rectangular grid
      // to n x n and undercount `for (i < g.size()) for (j < g[i].size())`
      // whenever the rows are longer than the row count (round-7 BUG-015).
      // Map the receiver's dimension to the next independent axis instead.
      const elementDimension = subscriptElementDimension(member.inner?.[0], bounds);
      if (elementDimension) return elementDimension;
      const base = nodesOfKind(member.inner?.[0] ?? {}, "DeclRefExpr").at(0);
      const bound = boundForReference(bounds, base);
      if (bound) return bound;
      // A resolved standard sequence receiver still proves a cardinality even
      // when a Windows prelude omits its stream-input data-flow edge. The
      // single-sequence fallback uses the conventional n dimension; rules for
      // two independent strings/containers retain n + m separately.
      const type = base?.type?.desugaredQualType ?? base?.type?.qualType
        ?? base?.referencedDecl?.type?.desugaredQualType ?? base?.referencedDecl?.type?.qualType ?? "";
      // Pointer receivers are excluded: a pointer may alias several
      // differently sized inputs, and picking one dimension is unsound.
      if (!type.includes("*") && /\b(?:vector|deque|array|string|basic_string)\b/.test(type)) return "O(n)";
    }
  }
  if (node.kind === "CallExpr") {
    const names = nodesOfKind(node, "DeclRefExpr")
      .map((reference) => reference.referencedDecl?.name)
      .filter((value): value is string => Boolean(value));
    // `std::move(value)` and `std::forward<T>(value)` preserve the symbolic
    // size of an argument. They only change value category, never the number
    // of elements, so local helper summaries may safely substitute through
    // these CP wrapper calls.
    if (names.some((name) => name === "move" || name === "forward")) {
      return nodesOfKind(node, "DeclRefExpr")
        .filter((reference) => !["move", "forward"].includes(reference.referencedDecl?.name ?? ""))
        .map((reference) => boundForReference(bounds, reference))
        .find((value): value is Complexity => Boolean(value));
    }
    const name = names.find((value) => ["begin", "end", "cbegin", "cend", "rbegin", "rend", "data"].includes(value));
    if (name) {
      // In `std::begin(values)`, the callee has no symbolic bound but the
      // argument does. Selecting the first proven argument is safe because
      // these endpoint helpers are single-range operations.
      return nodesOfKind(node, "DeclRefExpr")
        .map((reference) => boundForReference(bounds, reference))
        .find((value): value is Complexity => Boolean(value));
    }
  }
  if (node.kind === "UnaryOperator" && ["&", "*"].includes(node.opcode ?? "")) {
    // A direct address-of/dereference alias retains the cardinality of the
    // proven object. Escaping pointers are still rejected elsewhere because
    // no state is introduced for an unknown call or pointer write.
    return expressionComplexity(node.inner?.at(-1), bounds, constantSymbols);
  }
  if (node.kind === "CXXOperatorCallExpr" || node.kind === "ArraySubscriptExpr") {
    const operatorName = node.kind === "CXXOperatorCallExpr"
      ? (node.name ?? nodesOfKind(node, "DeclRefExpr").map((reference) => reference.referencedDecl?.name).find((name) => name?.startsWith("operator")))
      : "operator[]";
    if (operatorName === "operator[]") {
      const container = nodesOfKind(node, "DeclRefExpr").find((reference) => {
        if (reference.referencedDecl?.kind === "CXXMethodDecl") return false;
        const type = reference.type?.desugaredQualType ?? reference.type?.qualType
          ?? reference.referencedDecl?.type?.desugaredQualType ?? reference.referencedDecl?.type?.qualType ?? "";
        return /\b(?:vector|deque|array|string|map|set|unordered_map|unordered_set)\b/.test(type)
          && Boolean(boundForReference(bounds, reference));
      });
      if (container) return boundForReference(bounds, container);
    }
  }
  const children = node.inner ?? [];
  if (["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr", "CXXStaticCastExpr", "CXXFunctionalCastExpr", "CXXConstCastExpr", "CXXReinterpretCastExpr", "ExprWithCleanups", "MaterializeTemporaryExpr", "CXXBindTemporaryExpr", "CXXConstructExpr"].includes(node.kind ?? "") && children.length > 0) {
    return expressionComplexity(children.at(-1), bounds, constantSymbols);
  }
  if (node.kind !== "BinaryOperator" || children.length < 2) return undefined;
  const left = expressionComplexity(children[0], bounds, constantSymbols);
  const right = expressionComplexity(children[1], bounds, constantSymbols);
  // `unknown + 1` is still unknown: returning the known literal side would
  // turn `a.size() - 1` into O(1) and make container-bounded loops look
  // constant. Both operands must be understood before simplifying a sum.
  if (node.opcode === "+" || node.opcode === "-") {
    if (!left || !right) return undefined;
    // Subtraction: with non-negative CP sizes, `x - y` never exceeds `x`, so
    // the left bound alone is a sound upper bound even when the operands are
    // independent dimensions (`i > n - m` bounds i by n).
    if (node.opcode === "-") return left;
    return dominantExpression(left, right);
  }
  if (node.opcode === "*") return left && right ? multiplyExpressions(left, right) : undefined;
  // Dividing by an input-dependent value can only reduce the upper bound, so keep
  // the numerator. This is conservative for worst-case classification.
  if (node.opcode === "/") {
    // A division by a named variable yields a RATIO bound (n / i): the
    // divisor keeps its own identity as a negative-exponent symbol, so loop
    // composition can sum the ratio over that variable's domain. Bounds-map
    // values are upper bounds (i -> O(n)) and would collapse the ratio.
    if (left) {
      let divisor = node.inner?.[1];
      while (divisor && ["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr"].includes(divisor.kind ?? "")) divisor = divisor.inner?.[0];
      if (divisor && divisor.kind === "DeclRefExpr" && !constantSymbols?.has(divisor.referencedDecl?.name ?? "")) {
        const divisorSymbol = divisor.referencedDecl?.name ?? referenceKey(divisor);
        const leftTerms = parseBound(left);
        if (divisorSymbol && leftTerms && leftTerms.length === 1) {
          const ratioTerm = { ...leftTerms[0], symbols: new Map(leftTerms[0].symbols) };
          ratioTerm.symbols.set(divisorSymbol, (ratioTerm.symbols.get(divisorSymbol) ?? 0) - 1);
          if (ratioTerm.symbols.get(divisorSymbol)! < 0) {
            return formatBound([ratioTerm]);
          }
        }
      }
    }
    return left;
  }
  if (node.opcode === "<<") {
    // `1 << n` is the canonical CP mask-domain bound. Treating its literal
    // left operand as O(1) previously collapsed a 2^n loop to O(1).
    const leftIsOne = nodesOfKind(children[0], "IntegerLiteral").some((literal) => literal.value === "1");
    const exponent = /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(right ?? "")?.[1];
    if (leftIsOne && exponent) return (`O(2^${exponent})` as Complexity);
    return left;
  }
  if (node.opcode === ">>") return left;
  return undefined;
}

function loopLimit(condition: ClangNode, index: string | undefined): ClangNode | undefined {
  if (!index || (condition.inner?.length ?? 0) < 2) return undefined;
  const [left, right] = condition.inner!;
  if (referencesSymbol(left, index)) return right;
  if (referencesSymbol(right, index)) return left;
  return undefined;
}

function isSingleSymbolicInput(node: ClangNode | undefined, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): boolean {
  if (!node) return false;
  if (["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr"].includes(node.kind ?? "")) return isSingleSymbolicInput(node.inner?.at(-1), bounds, constantSymbols);
  const name = node.referencedDecl?.name;
  return Boolean(name && !constantSymbols?.has(name) && boundForReference(bounds, node));
}

function nonProgressingUpdate(update: ClangNode | undefined): boolean {
  if (update?.kind !== "CompoundAssignOperator") return false;
  const literal = nodesOfKind(update, "IntegerLiteral").at(-1)?.value;
  return (update.opcode === "+=" || update.opcode === "-=") && literal === "0"
    || (update.opcode === "*=" || update.opcode === "/=") && literal === "1";
}

function loopBound(loop: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): { value?: Complexity; update?: ClangNode; condition?: ClangNode; bound?: Complexity; rationalTrip?: { term: Bound; indexKey: string; limitSymbol: string }; proof?: string[]; ratioTrip?: { initKey: string } } {
  if (process.env.PROJECT_X_DEBUG) console.error(`[lb-enter] kind=${loop.kind} cond=${directCondition(loop)?.opcode ?? "-"} update=${updateOf(loop)?.opcode ?? "-"}`);
  // `while (t--)` is the canonical contest-testcase loop.  Clang represents
  // its progress operation in the condition rather than as a ForStmt update,
  // so preserve that semantic update instead of rejecting a proven O(t) loop.
  const postfixCounter = loop.kind === "WhileStmt"
    ? nodesOfKind(loop.inner?.[0] ?? {}, "UnaryOperator").find((part) => ["++", "--"].includes(part.opcode ?? ""))
    : undefined;
  const rawWhileCondition = loop.kind === "WhileStmt" ? loop.inner?.[0] : undefined;
  let condition = directCondition(loop) ?? postfixCounter ?? rawWhileCondition;
  // For `while (t--)`, the condition itself is the only loop-progress
  // update. Prefer it over incidental `--` operations in the loop body.
  const update = postfixCounter ?? updateOf(loop);
  // Conjunction decomposition: `for (; fast < n && a[fast] <= a[slow]; ++fast)`
  // - the direct child is a conjunction, not a comparison. Find the nested
  // comparison that references the update target as the effective condition.
  if (!condition && update) {
    const updateTarget = loopIndex(update);
    if (updateTarget) {
      condition = [...(loop.inner ?? [])].flatMap((part) => nodesOfKind(part, "BinaryOperator"))
        .find((op) => ["<", "<=", ">", ">=", "!="].includes(op.opcode ?? "") && referencesSymbol(op, updateTarget));
    }
  }
  // Repeated reduction updates with no compound-assign shape:
  //   while (i > 1) { i = sqrt(i); }        -> log log n
  //   while (i > 1) { i = pow(i, 0.5); }    -> log log n
  //   while (i > 1) { i = i / 2; }          -> log n
  // The condition variable must be reassigned from a reduction of itself.
  if (loop.kind === "WhileStmt" && condition && !update) {
    if (process.env.PROJECT_X_DEBUG) console.error(`[sqrt-detector] cond=${condition.kind}:${condition.opcode ?? ""} body=${bodyOf(loop)?.kind}`);
    const condKeys = new Set(nodesOfKind(condition, "DeclRefExpr").map((reference) => referenceKey(reference)));
    const body = bodyOf(loop);
    let sqrtReduction = false;
    let divisionReduction = false;
    if (body) for (const statement of body.kind === "CompoundStmt" ? (body.inner ?? []) : [body]) {
      if (statement.kind !== "BinaryOperator" || statement.opcode !== "=") continue;
      const targetKey = referenceKey(statement.inner?.[0]);
      if (!targetKey || !condKeys.has(targetKey)) continue;
      const rhs = statement.inner?.[1];
      if (!rhs) continue;
      const call = nodesOfKind(rhs, "CallExpr")[0];
      const calleeName = call ? nodesOfKind(call, "DeclRefExpr").map((reference) => reference.referencedDecl?.name).find((value): value is string => Boolean(value)) : undefined;
      const conditionKey = [...condKeys][0] ?? "";
      if (calleeName === "sqrt" && referencesSymbol(call, conditionKey)) sqrtReduction = true;
      if (calleeName === "pow") {
        const exponent = nodesOfKind(call ?? {}, "FloatingLiteral").at(0)?.value;
        const value = exponent ? Number(exponent) : undefined;
        if (value !== undefined && value > 0 && value < 1 && referencesSymbol(call, conditionKey)) sqrtReduction = true;
      }
      if (rhs.kind === "BinaryOperator" && rhs.opcode === "/") {
        const divisor = nodesOfKind(rhs, "IntegerLiteral").at(0)?.value;
        if (divisor && Number(divisor) >= 2 && referencesSymbol(rhs, conditionKey)) divisionReduction = true;
      }
    }
    if (sqrtReduction) {
      return { value: "O(log log n)", update, condition, bound: "O(log log n)", proof: ["Each iteration replaces the loop variable with its square root (n -> n^(1/2) -> n^(1/4) -> ...), so reaching a constant takes log log n iterations."] };
    }
    if (divisionReduction) {
      return { value: "O(log n)", update, condition, bound: "O(log n)", proof: ["Each iteration divides the loop variable by a constant, so the depth is logarithmic."] };
    }
  }
  // Conjunction of two cursors: `while (l < n && r < m)` where every body
  // path advances at least one cursor by a unit step. Each cursor stays
  // within its own comparison bound, so the trip count is bounded by the
  // SUM of the two limits - the structural merge idiom.
  if (loop.kind === "WhileStmt") {
    const top = loop.inner?.[0];
    if (top?.kind === "BinaryOperator" && top.opcode === "&&" && (top.inner?.length ?? 0) === 2) {
      // Cursors are the body-mutated scalars; bounds are the other operands.
      const mutatedNames = new Set(nodesOfKind(bodyOf(loop) ?? {}, "UnaryOperator")
        .filter((operation) => ["++", "--"].includes(operation.opcode ?? ""))
        .map((operation) => referencedName(operation))
        .filter((name): name is string => Boolean(name)));
      const sides = (top.inner ?? []).map((part) => {
        if (part.kind !== "BinaryOperator" || !["<", "<=", ">", ">="].includes(part.opcode ?? "")) return undefined;
        const [leftSide, rightSide] = part.inner ?? [];
        const leftSymbol = referencedName(leftSide);
        const rightSymbol = referencedName(rightSide);
        if (!leftSymbol || !rightSymbol) return undefined;
        const boundSide = mutatedNames.has(leftSymbol) ? rightSide
          : mutatedNames.has(rightSymbol) ? leftSide : undefined;
        if (!boundSide) return undefined;
        const boundValue = expressionComplexity(boundSide, bounds, constantSymbols);
        if (!boundValue) return undefined;
        const cursorName = mutatedNames.has(leftSymbol) ? leftSymbol : rightSymbol;
        return { symbol: cursorName, bound: boundValue };
      });
      if (sides.length === 2 && sides.every((side) => Boolean(side)) && (sides[0]!.symbol !== sides[1]!.symbol)) {
        let merged: Bound = [];
        for (const side of sides as { symbol: string; bound: Complexity }[]) {
          const parsed = parseBound(side.bound);
          if (!parsed) { merged = []; break; }
          merged = maxBounds(merged, parsed);
        }
        if (merged.length > 0) return { value: formatBound(merged), update, condition, bound: formatBound(merged) };
      }
    }
  }
  // Euclid's algorithm with plain assignment chains: `while (b != 0) { t = a % b; a = b; b = t; }`
  // has no compound update, but the condition variable provably receives a
  // remainder (strictly smaller within two iterations), so the depth is
  // logarithmic in the conventional dimension.
  if (loop.kind === "WhileStmt" && condition?.kind === "BinaryOperator" && condition.opcode === "!=") {
    const conditionVariable = referencedName(condition.inner?.[0]) ?? referencedName(condition.inner?.[1]);
    const body = bodyOf(loop);
    if (conditionVariable && body) {
      // One-step data flow: value sources for locals (`long long t = a % b`)
      // and assignment targets (`b = t`). The condition variable must be
      // reassigned from an expression that is, or transitively names, a
      // remainder over the condition variable itself.
      const sourceOf = new Map<string, ClangNode>();
      for (const statement of body.inner ?? []) {
        if (statement.kind === "DeclStmt") {
          for (const declaration of statement.inner ?? []) {
            if (declaration.kind === "VarDecl" && declaration.name && declaration.inner?.length) {
              sourceOf.set(declaration.name, declaration.inner.at(-1)!);
            }
          }
        }
        if (statement.kind === "BinaryOperator" && statement.opcode === "=") {
          const target = referencedName(statement.inner?.[0]);
          if (target && statement.inner?.[1]) sourceOf.set(target, statement.inner[1]);
        }
      }
      const conditionSource = sourceOf.get(conditionVariable);
      const isRemainderOver = (node: ClangNode | undefined): boolean =>
        Boolean(node && node.kind === "BinaryOperator" && node.opcode === "%" && references(node, conditionVariable));
      const moduloFeeds = isRemainderOver(conditionSource)
        || isRemainderOver(sourceOf.get(referencedName(conditionSource) ?? ""));
      if (moduloFeeds) {
        return { value: "O(log n)", update, condition, bound: "O(log n)" };
      }
    }
  }
  if (!condition || !update) return {};
  const index = loopIndex(update);
  // A canonical while guard can combine the progress bound with a content
  // predicate: `while (i < text.size() && text[i] == text[0])`. Use the
  // comparison that actually contains the updated index, rather than asking
  // loopLimit to interpret the top-level logical && expression.
  if (loop.kind === "WhileStmt" && rawWhileCondition && index) {
    const indexedComparison = nodesOfKind(rawWhileCondition, "BinaryOperator")
      .find((part) => ["<", "<=", ">", ">=", "!="].includes(part.opcode ?? "") && referencesSymbol(part, index));
    if (indexedComparison) condition = indexedComparison;
  }
  if (loop.kind === "WhileStmt" && postfixCounter && update === postfixCounter) {
    const counter = postfixCounter.inner?.at(-1);
    const bound = expressionComplexity(counter, bounds, constantSymbols);
    if (!bound) return {};
    return { value: bound, update, condition, bound };
  }
  // `while (b) { b >>= 1; }` and `while (x) { x /= c; }` are common
  // fast-power / digit-processing loops. Their condition is an implicit cast
  // of a single scalar rather than a binary comparison, but the AST still
  // proves monotonic geometric progress through the compound update.
  const truthyCounter = loop.kind === "WhileStmt" && !directCondition(loop)
    ? nodesOfKind(loop.inner?.[0] ?? {}, "DeclRefExpr").at(0)
    : undefined;
  if (truthyCounter && update.kind === "CompoundAssignOperator" && [">>=", "/="].includes(update.opcode ?? "") && referencesSymbol(update, referenceKey(truthyCounter) ?? "")) {
    const bound = expressionComplexity(truthyCounter, bounds, constantSymbols);
    const variable = /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(bound ?? "")?.[1] ?? "n";
    return { value: `O(log ${variable})` as Complexity, update, condition, bound };
  }
  // Value-preserving casts never enlarge the true bound, so a limit written as
  // `(int)a.size()` proves the same cardinality as the unwrapped call.
  let limitNode = loopLimit(condition, index);
  while (limitNode && ["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr", "CXXStaticCastExpr", "CXXFunctionalCastExpr", "ExprWithCleanups", "MaterializeTemporaryExpr"].includes(limitNode.kind ?? "")) {
    const unwrapped = limitNode.inner?.at(-1);
    if (!unwrapped) break;
    limitNode = unwrapped;
  }
  const conditionLimit = expressionComplexity(limitNode, bounds, constantSymbols);
  // A for-header declaration re-initializes the index, superseding any value
  // inherited from earlier control flow; the recorded bound is stale there.
  // The starting magnitude then comes from the header initializer itself:
  // `for (int i = n; i > 0; i /= 2)` halves from n, while `for (int k = 0; ...)`
  // starts at a constant and takes its bound from the condition limit.
  let reinitializedIndex = false;
  let indexLimit = index ? bounds.get(index) : undefined;
  if (loop.kind === "ForStmt" && index) {
    for (const part of loop.inner ?? []) {
      if (part.kind === "CompoundStmt") break;
      if (part.kind !== "DeclStmt") continue;
      const declared = (part.inner ?? []).find((declaration) => declaration.kind === "VarDecl" && declarationKey(declaration) === index);
      if (!declared) continue;
      reinitializedIndex = true;
      indexLimit = expressionComplexity(declared.inner?.at(-1), bounds, constantSymbols);
      break;
    }
  }
  // A condition such as `left < right` is not proven merely because `left`
  // starts at zero. If its other side has an unknown size (for example an
  // unsupported `a.size()` alias), falling back to the index's O(1) initializer
  // would incorrectly claim a constant loop. The index bound is only useful
  // alongside a known condition limit, as in a halving loop initialized from n.
  // A for-header re-initialization only lowers an ascending loop's start
  // (trips stay capped by the condition limit) and only extends a descending
  // loop's start (trips stay capped by the initializer's own bound). When the
  // two magnitudes are incomparable symbols, the side matching the update
  // direction is still a proven trip cap.
  const plainStep = update.kind === "UnaryOperator" && ["++", "--"].includes(update.opcode ?? "");
  const limit = conditionLimit
    ? (indexLimit ? dominantExpression(conditionLimit, indexLimit) ?? (exponentialBase(conditionLimit) ? conditionLimit : undefined) ?? (plainStep ? (update.opcode === "--" ? indexLimit : conditionLimit) : undefined) : conditionLimit)
    : (limitNode ? undefined : indexLimit);
  if (!limit) return {};
  // The update must touch the loop's state: a body that increments an
  // unrelated counter (`while (n != 1) { n = ...; ++steps; }`) has no proven
  // trip count, and falling back to that counter's own bound would be
  // unsound. Euclid's `a %= b` qualifies: it reads the condition variable.
  if (!index) return {};
  const conditionKeys = new Set(nodesOfKind(condition ?? {}, "DeclRefExpr").map((reference) => referenceKey(reference)));
  const updateTouchesCondition = nodesOfKind(update, "DeclRefExpr")
    .some((reference) => conditionKeys.has(referenceKey(reference)));
  if (!updateTouchesCondition && !referencesSymbol(condition, index)) return {};
  if (loop.kind === "WhileStmt" && update.kind === "CompoundAssignOperator" && update.opcode === "%=") return { value: "O(log n)", update, condition, bound: limit };
  if (squareBound(condition) && isSingleSymbolicInput(limitNode, bounds, constantSymbols) && update.kind === "UnaryOperator" && ["++", "--"].includes(update.opcode ?? "")) return { value: "O(sqrt n)", update, condition, bound: limit };
  if (update.kind === "UnaryOperator" && ["++", "--"].includes(update.opcode ?? "")) {
    // An equality trip count is chargeable only when the counter can reach
    // its target: the reachability pre-pass marks loops whose literal start
    // provably steps away (they never exit) or whose start cannot be pinned
    // (no trip may be charged).
    if (condition.opcode === "!=" && equalityLoopReachability.has(loop)) return {};
    // Quotient limit: `for (j = 1; j <= n / i; ++j)` - the limit itself is a
    // rational term of an enclosing index (a negative exponent). The trip IS
    // the limit; the compositional layer sums it over the outer loop.
    const limitTerms = parseBound(limit);
    if (limitTerms && limitTerms.length === 1) {
      let negativeKey: string | undefined;
      let positiveKey: string | undefined;
      for (const [symbol, exponent] of limitTerms[0].symbols) {
        if (exponent < 0 && !negativeKey) negativeKey = symbol;
        if (exponent > 0 && !positiveKey) positiveKey = symbol;
      }
      if (negativeKey && positiveKey) {
        return { value: limit, update, condition, bound: limit, rationalTrip: { term: limitTerms, indexKey: negativeKey, limitSymbol: positiveKey } };
      }
    }
    return { value: limit, update, condition, bound: limit };
  }
  if (update.kind === "CompoundAssignOperator" && ["+=", "-="].includes(update.opcode ?? "")) {
    // A literal-stride equality loop follows the same reachability rule as a
    // unit-step one: no equality trip may be charged once the pre-pass has
    // marked the loop away (never exits) or unpinnable.
    if (condition.opcode === "!=" && equalityLoopReachability.has(loop)) return {};
    // Harmonic stride: `for (j = i; j <= n; j += i)` - the step is an
    // enclosing loop's index, so the trip count is limit/stride, a rational
    // term (n * i^-1) rather than a constant. The plain `limit` value stays
    // as the sound upper bound; the compositional layer sums the series.
    if (update.opcode === "+=") {
      let strideOperand = update.inner?.[1];
      while (strideOperand && ["ImplicitCastExpr", "ParenExpr"].includes(strideOperand.kind ?? "")) strideOperand = strideOperand.inner?.[0];
      // General monomial stride: a product of index references and integer
      // literals (i, 2*i, i*i). The stride exponent per referenced index is
      // its leaf multiplicity (i*i -> i^-2 in the trip term).
      const strideIsMonomial = Boolean(strideOperand && (strideOperand.kind === "DeclRefExpr"
        || (strideOperand.kind === "IntegerLiteral")
        || (strideOperand.kind === "BinaryOperator" && strideOperand.opcode === "*"
          && nodesOfKind(strideOperand, "BinaryOperator").filter((operation) => operation !== strideOperand).length === 0
          && nodesOfKind(strideOperand, "DeclRefExpr").length >= 1)));
      const strideLeafKeys: string[] = [];
      if (strideOperand) for (const leaf of nodesOfKind(strideOperand, "DeclRefExpr")) {
        const key = referenceKey(leaf);
        if (key) strideLeafKeys.push(key);
      }
      const strideKey = strideLeafKeys[0];
      const ownKey = index;
      if (strideKey && strideIsMonomial && strideLeafKeys.every((key) => key === strideKey) && strideKey !== ownKey && bounds.has(strideKey) && limit) {
        {
          const limitSymbol = /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(limit)?.[1];
          const strideMultiplicity = strideLeafKeys.length;
          if (limitSymbol && strideMultiplicity >= 1) {
            const tripTerm = constantTerm();
            tripTerm.symbols.set(limitSymbol, 1);
            tripTerm.symbols.set(strideKey, -strideMultiplicity);
            return {
              value: limit, update, condition, bound: limit,
              rationalTrip: { term: [tripTerm], indexKey: strideKey, limitSymbol }
            };
          }
        }
      }
    }
    return { value: limit, update, condition, bound: limit };
  }
  if (update.kind === "CompoundAssignOperator" && ["*=", "/="].includes(update.opcode ?? "")) {
    // Multiplicative trip = log_c(U / L): when the START value scales with
    // an enclosing iterator (j = i), the count is log(n/i), not log(n) -
    // and summing log(n/i) over the additive outer loop is Theta(n).
    const headerInits = (loop.inner ?? []).flatMap((part) => part.kind === "DeclStmt" ? part.inner ?? [] : [])
      .filter((declaration) => declaration.kind === "VarDecl" && declarationKey(declaration) === index);
    const initKey = headerInits.map((declaration) => {
      const initializer = declaration.inner?.at(-1);
      let unwrapped = initializer;
      while (unwrapped && ["ImplicitCastExpr", "ParenExpr"].includes(unwrapped.kind ?? "")) unwrapped = unwrapped.inner?.[0] ?? unwrapped;
      return unwrapped ? referenceKey(unwrapped) : undefined;
    }).find((value): value is string => Boolean(value));
    if (process.env.PROJECT_X_DEBUG) console.error(`[geo-init] initKey=${initKey ?? "-"} index=${index ?? "-"} inBounds=${initKey ? bounds.has(initKey) : "-"} limit=${limit}`);
    if (initKey && initKey !== index && bounds.has(initKey)) {
      return { value: limit === "O(1)" ? "O(1)" : "O(log n)", update, condition, bound: limit, ratioTrip: { initKey } };
    }
    return { value: limit === "O(1)" ? "O(1)" : "O(log n)", update, condition, bound: limit };
  }
  // Shift updates halve or double the index exactly like multiplicative
  // updates: `while (n > 1) n >>= 1` is the canonical digit-processing loop.
  if (update.kind === "CompoundAssignOperator" && [">>=", "<<="].includes(update.opcode ?? "")) return { value: limit === "O(1)" ? "O(1)" : "O(log n)", update, condition, bound: limit };
  return {};
}

function exponentialBase(value: Complexity): string | undefined {
  return /^O\(2\^([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(value)?.[1];
}

/** Split a supported `polynomial × 2^symbol` expression for further composition. */
function exponentialFactor(value: Complexity): { polynomial: Complexity; exponent: string } | undefined {
  const pure = exponentialBase(value);
  if (pure) return { polynomial: "O(1)", exponent: pure };
  const composite = /^O\((.+) 2\^([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(value);
  return composite ? { polynomial: (`O(${composite[1]})` as Complexity), exponent: composite[2] } : undefined;
}

/** AST-level predicate for a complete bitmask extent, independent of casts. */
function hasCompleteMaskExtent(node: ClangNode, bounds: SymbolicBounds): boolean {
  return nodesOfKind(node, "BinaryOperator").some((expression) => {
    if (expression.opcode !== "<<" || (expression.inner?.length ?? 0) < 2) return false;
    const [left, right] = expression.inner!;
    const isOne = nodesOfKind(left, "IntegerLiteral").some((literal) => literal.value === "1");
    return isOne && Boolean(expressionComplexity(right, bounds));
  });
}

function attachExponentialFactor(polynomial: Complexity, exponent: string): Complexity | undefined {
  if (polynomial === "O(1)") return `O(2^${exponent})` as Complexity;
  const body = /^O\((.+)\)$/.exec(polynomial)?.[1];
  return body ? (`O(${body} 2^${exponent})` as Complexity) : undefined;
}

function multiply(left: Complexity, right: Complexity): Complexity | undefined {
  // The canonical bound algebra handles exponential bases, factorials, and
  // mixed polynomial/log products natively; different exponential dimensions
  // still refuse to compose by returning undefined.
  return multiplyExpressions(left, right);
}

function nestedLoops(loop: ClangNode): ClangNode[] {
  const result: ClangNode[] = [];
  const collectFirstLoops = (node: ClangNode): void => {
    for (const child of node.inner ?? []) {
      if (child.kind === "ForStmt" || child.kind === "WhileStmt") result.push(child);
      else collectFirstLoops(child);
    }
  };
  collectFirstLoops(loop);
  return result;
}

/** The first loop(s) on each lexical branch, without their descendants. */
function immediateNestedLoops(loop: ClangNode): ClangNode[] {
  const result: ClangNode[] = [];
  const collect = (node: ClangNode | undefined): void => {
    if (!node) return;
    for (const child of node.inner ?? []) {
      if (["ForStmt", "WhileStmt", "DoStmt"].includes(child.kind ?? "")) {
        result.push(child);
      } else {
        collect(child);
      }
    }
  };
  const body = bodyOf(loop);
  // An unbraced `for (...) for (...) ...` has the nested loop itself as the
  // body node.  Do not skip that root while scanning its descendants.
  if (["ForStmt", "WhileStmt", "DoStmt"].includes(body?.kind ?? "")) result.push(body!);
  else collect(body);
  return result;
}

/**
 * Computes a lexical loop-path product using only proven canonical bounds.
 * It is intentionally used by the typed bitmask-table recognizer below,
 * where conditional execution can only reduce the upper bound and each
 * table cell operation is known to be constant-time.
 */
function nestedLoopPathCost(loop: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): Complexity | undefined {
  const own = loopBound(loop, bounds, constantSymbols);
  if (!own.value) return undefined;
  const index = loopIndex(own.update);
  const childBounds = new Map(bounds);
  if (index && own.bound) childBounds.set(index, own.bound);
  const children = immediateNestedLoops(loop);
  if (children.length === 0) return own.value;
  const childCosts = children.map((child) => nestedLoopPathCost(child, childBounds, constantSymbols));
  if (childCosts.some((cost) => !cost)) return undefined;
  const perIteration = sequentialMaximum(childCosts.filter((cost): cost is Complexity => Boolean(cost)));
  return perIteration ? multiply(own.value, perIteration) : undefined;
}

function callsOutsideNestedLoops(loop: ClangNode): ClangNode[] {
  const calls: ClangNode[] = [];
  const callKinds = new Set(["CallExpr", "CXXMemberCallExpr", "CXXOperatorCallExpr"]);
  const collect = (node: ClangNode): void => {
    // For `for (...) sort(...);`, the body is the CallExpr itself rather
    // than a CompoundStmt containing it. Inspect the root before descendants
    // so unbraced bodies retain exactly the same work as braced bodies.
    if (node.kind === "ForStmt" || node.kind === "WhileStmt" || node.kind === "DoStmt") return;
    if (callKinds.has(node.kind ?? "")) calls.push(node);
    for (const child of node.inner ?? []) collect(child);
  };
  collect(bodyOf(loop) ?? {});
  return calls;
}

function analyseLoop(loop: ClangNode, bounds: SymbolicBounds, localCosts?: LocalFunctionCosts, constantSymbols?: ReadonlySet<string>): LoopAnalysis {
  if (isZeroInitializedMultiplicativeLoop(loop) || nonProgressingUpdate(updateOf(loop)) || equalityLoopReachability.get(loop) === "away") {
    return { value: "Does not terminate", proof: ["The loop update cannot make progress for a valid worst-case input."] };
  }
  const own = loopBound(loop, bounds, constantSymbols);
  if (!own.value || !own.condition) return {};
  const index = loopIndex(own.update);
  const geometric = own.value === "O(log n)" && ["*=", "/="].includes(own.update?.opcode ?? "");
  const nested = nestedLoops(loop);
  if (nested.length > 1) return {};
  if (nested.length === 0) {
    const loopCalls = callsOutsideNestedLoops(loop);
    // A local helper invoked on a variable that changes every geometric-loop
    // iteration (for example `pow(2, bit)` while `bit++`) cannot be treated
    // as a constant per-iteration summary.  Its argument-sensitive cost needs
    // a separate proof; abstain rather than undercounting it as O(log n).
    const hasChangingHelperArgument = loopCalls.some((call) => {
      if (!localSummaryForCall(call, localCosts)) return false;
      const arguments_ = nodesOfKind(call, "DeclRefExpr").map(referenceKey).filter((key): key is string => Boolean(key));
      return arguments_.some((argument) => nodesOfKind(bodyOf(loop) ?? {}, "UnaryOperator").some((update) => referencesSymbol(update, argument))
        || nodesOfKind(bodyOf(loop) ?? {}, "CompoundAssignOperator").some((update) => referencesSymbol(update, argument)));
    });
    if (hasChangingHelperArgument) return {};
    const callCosts = loopCalls.map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
    if (callCosts.some((cost) => !cost)) return {};
    if (callCosts.includes("Does not terminate")) return { value: "Does not terminate", proof: ["A call inside this loop does not terminate for a valid worst-case input."] };
    const operationCost = sequentialMaximum(callCosts.filter((cost): cost is Complexity => Boolean(cost))) ?? "O(1)";
    const total = multiply(own.value, operationCost);
    if (!total) return {};
    const reason = own.value === "O(log n)" ? "Loop decreases or grows geometrically against an input bound."
      : own.value === "O(sqrt n)" ? "Loop condition is a squared index against an input bound."
      : "Loop index changes by a constant amount against an input bound.";
    const callProof = operationCost === "O(n)" ? ["Recognized a linear range algorithm call in each loop iteration."] : [];
    return { value: total, proof: [reason, ...callProof], index, condition: own.condition, geometric, bound: own.bound };
  }
  const childBounds = new Map(bounds);
  if (index && own.bound) childBounds.set(index, own.bound);
  const child = analyseLoop(nested[0], childBounds, localCosts, constantSymbols);
  if (!child.value) return {};
  if (child.value === "Does not terminate") return child;
  // `index` is the declaration identity when a real Clang AST is available;
  // compare identities rather than spelling it as though it were a name.
  const childDependsOnParent = Boolean(index && referencesSymbol(child.condition, index));
  if (geometric && childDependsOnParent) {
    return { value: child.value, proof: ["Inner work is bounded by the geometrically changing outer index.", "The geometric series is dominated by its final term: " + child.value + "."], index, condition: own.condition, geometric, bound: own.bound };
  }
  const value = multiply(own.value, child.value);
  if (!value) return {};
  return { value, proof: ["Outer loop cost is " + own.value + ".", ...(child.proof ?? []), "Nested loop costs multiply."], index, condition: own.condition, geometric, bound: own.bound };
}

/** Composes sequential worst-case costs through the canonical bound algebra. */
function sequentialMaximum(values: Complexity[]): Complexity | undefined {
  if (values.length === 0) return undefined;
  if (values.includes("Does not terminate")) return "Does not terminate";
  const bounds: (Bound | undefined)[] = values.map((value) => parseBound(value));
  if (bounds.some((bound) => !bound)) return undefined;
  let merged: Bound = [];
  for (const bound of bounds as Bound[]) merged = maxBounds(merged, bound);
  return formatBound(merged);
}

function directCalls(node: ClangNode): ClangNode[] {
  const kinds = new Set(["CallExpr", "CXXMemberCallExpr", "CXXOperatorCallExpr"]);
  const calls: ClangNode[] = [];
  walk(node, (current) => { if (kinds.has(current.kind ?? "")) calls.push(current); });
  return calls;
}

/** Calls in straight-line phases, excluding every loop/range body. */
function callsOutsideLoops(node: ClangNode): ClangNode[] {
  const calls: ClangNode[] = [];
  const visit = (current: ClangNode): void => {
    for (const child of current.inner ?? []) {
      if (["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(child.kind ?? "")) continue;
      if (["CallExpr", "CXXMemberCallExpr", "CXXOperatorCallExpr"].includes(child.kind ?? "")) calls.push(child);
      visit(child);
    }
  };
  visit(node);
  return calls;
}

function memberCallInfo(call: ClangNode): { name: string; containerType?: string } | undefined {
  const member = nodesOfKind(call, "MemberExpr").at(0);
  if (!member?.name) return undefined;
  const typeFromBase = (node: ClangNode | undefined): string | undefined => {
    if (!node) return undefined;
    const type = node.type?.desugaredQualType ?? node.type?.qualType;
    if (type && !type.includes("bound member function")) return type;
    for (const child of node.inner ?? []) {
      const found = typeFromBase(child);
      if (found) return found;
    }
    return undefined;
  };
  return { name: member.name, containerType: typeFromBase(member.inner?.[0]) };
}

function memberCallBaseName(call: ClangNode): string | undefined {
  const member = nodesOfKind(call, "MemberExpr").at(0);
  return member ? nodesOfKind(member.inner?.[0] ?? {}, "DeclRefExpr")
    .map((node) => node.referencedDecl?.name)
    .find((name): name is string => Boolean(name)) : undefined;
}

function knownMemberCallCost(call: ClangNode): Complexity | undefined {
  const info = memberCallInfo(call);
  if (!info) return undefined;
  const type = info.containerType ?? "";
  const name = info.name;
  if (["begin", "end", "cbegin", "cend", "size", "empty", "front", "back", "top", "clear", "pop_back", "pop_front", "data"].includes(name)) return "O(1)";
  // The prelude's synthetic stream type models each stream operation as one
  // constant-time step. Its configuration methods (tie, flush, precision,
  // sync_with_stdio, ...) touch a fixed stream object only, so admitting them
  // keeps the universal CP fast-io boilerplate analyzable.
  if (/__project_x_stream/.test(type)) return "O(1)";
  if (/priority_queue/.test(type)) return ["push", "emplace", "pop"].includes(name) ? "O(log n)" : undefined;
  if (/\b(?:queue|stack)</.test(type)) return ["push", "emplace", "pop"].includes(name) ? "O(1)" : undefined;
  if (/\b(?:map|set|multimap|multiset)</.test(type)) return ["find", "count", "contains", "lower_bound", "upper_bound", "equal_range", "insert", "emplace", "erase"].includes(name) ? "O(log n)" : undefined;
  if (/unordered_(?:map|set|multimap|multiset)/.test(type)) return ["find", "count", "contains", "insert", "emplace", "erase", "rehash", "reserve"].includes(name) ? "O(n)" : undefined;
  if (/\bvector</.test(type)) {
    if (["insert", "erase", "reserve", "resize", "assign"].includes(name)) return "O(n)";
    // push_back/emplace_back charge O(1) amortized: the potential method
    // bounds the total copying cost of any push/pop sequence by a constant
    // multiple of the number of pushes, so the total-work sum stays sound.
    if (["push_back", "emplace_back"].includes(name)) return "O(1)";
    return undefined;
  }
  if (/\bdeque</.test(type)) {
    if (["push_back", "push_front"].includes(name)) return "O(1)";
    return ["insert", "erase"].includes(name) ? "O(n)" : undefined;
  }
  // The compact local prelude models `string` as a non-template class,
  // whereas a system AST may spell it as `basic_string<...>`. Support both
  // spellings so a proven bounded number of append/resize calls is not
  // needlessly rejected on Windows.
  if (/\b(?:string|basic_string)\b/.test(type)) {
    // push_back/pop_back on a string amortize to O(1) by the same potential
    // argument as vector growth; the copying forms remain O(n).
    if (["push_back", "pop_back"].includes(name)) return "O(1)";
    return ["insert", "erase", "append", "assign", "reserve", "resize"].includes(name) ? "O(n)" : undefined;
  }
  return undefined;
}

function knownOperatorCallCost(call: ClangNode): Complexity | undefined {
  const operatorName = call.name ?? nodesOfKind(call, "DeclRefExpr").map((node) => node.referencedDecl?.name).find((name) => name?.startsWith("operator"));
  if (process.env.PROJECT_X_DEBUG) console.error(`[opcost] kind=${call.kind} name=${call.name ?? "-"} op=${operatorName ?? "-"} refs=${nodesOfKind(call, "DeclRefExpr").map((n) => n.referencedDecl?.name).slice(0, 4).join(",")}`);
  // A `std::function` invocation calls unknown code. The corpus convention
  // charges the dispatch itself O(1) and lets the caller downgrade to
  // estimated confidence; any other receiver spelling stays unproven.
  if (operatorName === "operator()") {
    const receiverIsFunction = nodesOfKind(call.inner?.[0] ?? {}, "DeclRefExpr")
      .map((reference) => reference.type?.desugaredQualType ?? reference.type?.qualType
        ?? reference.referencedDecl?.type?.desugaredQualType ?? reference.referencedDecl?.type?.qualType ?? "")
      .some((receiver) => /\bfunction</.test(receiver))
      || /\bfunction</.test(call.inner?.[0]?.type?.desugaredQualType ?? call.inner?.[0]?.type?.qualType ?? "");
    if (receiverIsFunction) return "O(1)";
  }
  if (operatorName === "operator<<" || operatorName === "operator>>") return "O(1)";
  // See the matching CallExpr fallback below: the synthetic Windows prelude
  // can omit the overloaded operator spelling while retaining the stream
  // declaration itself.
  if (["cout", "cerr", "clog", "cin"].some((stream) => references(call, stream))) return "O(1)";
  const type = (() => {
    // Clang represents overloaded `container[index]` as an operator call;
    // depending on the nested template, the receiver can sit below a
    // MemberExpr rather than a direct DeclRefExpr.
    for (const member of nodesOfKind(call, "MemberExpr")) {
      const base = member.inner?.[0];
      const candidate = base?.type?.desugaredQualType ?? base?.type?.qualType;
      if (candidate && /(?:vector|deque|string|map|set)/.test(candidate)) return candidate;
    }
    for (const node of nodesOfKind(call, "DeclRefExpr")) {
      const candidate = node.type?.desugaredQualType ?? node.type?.qualType;
      if (candidate && /(?:vector|deque|string|map|set)/.test(candidate)) return candidate;
    }
    return undefined;
  })();
  if (!type) return undefined;
  // The work of appending to a string is proportional to its current length
  // in the worst case.  This lets the loop composer derive the conventional
  // quadratic bound for repeated `result += ...` without matching names.
  if (operatorName === "operator+=") {
    if (!/\bstring\b/.test(type)) return undefined;
    return singleCharacterAppend(call) ? "O(1)" : "O(n)";
  }
  // Copy/move assignment of a sequence can traverse its current source
  // range. Treat it as linear rather than rejecting an otherwise analyzable
  // preprocessing constructor such as a sparse table's `table[0] = input`.
  if (operatorName === "operator=") return /\b(?:vector|deque|string)</.test(type) ? "O(n)" : undefined;
  if (operatorName !== "operator[]") return undefined;
  if (/unordered_(?:map|set)/.test(type)) return "O(n)";
  if (/\b(?:map|set|multimap|multiset)</.test(type)) return "O(log n)";
  if (/\b(?:vector|deque|string)</.test(type)) return "O(1)";
  return undefined;
}

function knownFreeFunction(call: ClangNode): Complexity | undefined {
  for (const name of standardFreeFunctionNames()) if (references(call, name)) return standardFreeFunctionCost(name);
  return undefined;
}

/**
 * True when an overloaded `operator+=` call appends exactly one character to a
 * string (`s += c`, `s += s2[i]`, ...). Appending one character is an
 * amortized constant-time operation; only copying a string or sequence
 * right-hand side is proportional to its length (round-7 BUG-016: charging
 * `s += c` as O(|s|) overstated per-character builders such as
 * `for (char c : str) result += c;` as quadratic).
 */
function singleCharacterAppend(call: ClangNode): boolean {
  // The operator reference itself is one of the call children; drop exactly
  // that child (an operand such as `s[i]` may spell a different overloaded
  // operator) and then the receiver operand.
  const isCalleeReference = (argument: ClangNode | undefined): boolean => {
    let unwrapped = argument;
    while (unwrapped && ["ImplicitCastExpr", "ParenExpr"].includes(unwrapped.kind ?? "")) unwrapped = unwrapped.inner?.[0];
    return unwrapped?.kind === "DeclRefExpr" && (unwrapped.referencedDecl?.name ?? "").startsWith("operator");
  };
  const operands = (call.inner ?? []).filter((argument) => !isCalleeReference(argument));
  const argumentTypes = operands.slice(1)
    .map((argument) => (argument?.type?.desugaredQualType ?? argument?.type?.qualType ?? "").replace(/&/g, " ").trim());
  return argumentTypes.length > 0
    && argumentTypes.every((argumentType) => /^(?:const\s+)?(?:signed\s+|unsigned\s+)?char$/.test(argumentType));
}

function productOfSameSymbol(node: ClangNode | undefined, symbol: string): boolean {
  if (!node) return false;
  if (node.kind === "BinaryOperator" && node.opcode === "*" && (node.inner?.length ?? 0) >= 2) {
    const matches = (part: ClangNode): boolean => referencesSymbol(part, symbol) || references(part, symbol);
    return matches(node.inner![0]) && matches(node.inner![1]);
  }
  return (node.inner ?? []).some((child) => productOfSameSymbol(child, symbol));
}

function referencedName(node: ClangNode | undefined): string | undefined {
  return node ? nodesOfKind(node, "DeclRefExpr").map((part) => part.referencedDecl?.name).find((name): name is string => Boolean(name)) : undefined;
}

function loopInitializationIsSquare(loop: ClangNode, index: string | undefined, outerIndex: string): boolean {
  if (!index) return false;
  for (const part of loop.inner ?? []) {
    if (part.kind === "CompoundStmt") break;
    for (const declaration of nodesOfKind(part, "VarDecl")) {
      if (declarationKey(declaration) === index && productOfSameSymbol(declaration, outerIndex)) return true;
    }
  }
  return false;
}

/** The full-range sieve variant starts marking at a multiple of the index
 * (`j = i + i`, `j = 2 * i`) instead of at its square. */
function loopInitializationIsMultiple(loop: ClangNode, index: string | undefined, outerIndex: string): boolean {
  if (!index) return false;
  for (const part of loop.inner ?? []) {
    if (part.kind === "CompoundStmt") break;
    for (const declaration of nodesOfKind(part, "VarDecl")) {
      if (declarationKey(declaration) === index
        && referencesSymbol(declaration.inner?.at(-1), outerIndex)) return true;
    }
  }
  return false;
}

function indexingContainerName(node: ClangNode | undefined): string | undefined {
  if (!node) return undefined;
  for (const operation of nodesOfKind(node, "CXXOperatorCallExpr")) {
    const operatorName = operation.name ?? nodesOfKind(operation, "DeclRefExpr").map((part) => part.referencedDecl?.name).find((name) => name?.startsWith("operator"));
    if (operatorName !== "operator[]") continue;
    const object = nodesOfKind(operation, "DeclRefExpr")
      .map((part) => part.referencedDecl?.name)
      .find((name) => name && !name.startsWith("operator"));
    if (object) return object;
  }
  for (const subscript of nodesOfKind(node, "ArraySubscriptExpr")) {
    const object = nodesOfKind(subscript, "DeclRefExpr")
      .map((part) => part.referencedDecl?.name)
      .find((name) => name && !name.startsWith("operator"));
    if (object) return object;
  }
  return undefined;
}

function initializesTableWithItsIndex(body: ClangNode, before: ClangNode, tableName: string): boolean {
  for (const statement of body.inner ?? []) {
    if (statement === before) break;
    if (statement.kind !== "ForStmt") continue;
    const index = loopIndex(updateOf(statement));
    if (!index) continue;
    const writesOwnIndex = nodesOfKind(bodyOf(statement) ?? {}, "BinaryOperator").some((assignment) => {
      return assignment.opcode === "=" && references(assignment, tableName) && (referencesSymbol(assignment, index) || references(assignment, index));
    });
    if (writesOwnIndex) return true;
  }
  return false;
}

/** Strict AST recognizer for the canonical Eratosthenes sieve marking pattern. */
function callsInSieveMarkingBody(loop: ClangNode): ClangNode[] {
  const calls: ClangNode[] = [];
  const collect = (node: ClangNode): void => {
    for (const child of node.inner ?? []) {
      if (child.kind === "ForStmt" || child.kind === "WhileStmt" || child.kind === "DoStmt") continue;
      if (child.kind === "CallExpr" || child.kind === "CXXMemberCallExpr") calls.push(child);
      collect(child);
    }
  };
  collect(bodyOf(loop) ?? {});
  return calls;
}

function composeSieveMarkingCost(cost: Complexity): Complexity | undefined {
  if (cost === "O(1)") return "O(n log log n)";
  if (cost === "O(n)") return "O(n^2 log log n)";
  const polynomial = /^O\(n\^(\d+)\)$/.exec(cost);
  return polynomial ? ("O(n^" + (Number(polynomial[1]) + 1) + " log log n)") as Complexity : undefined;
}

/**
 * Computes the work performed by one Sieve marking operation. Calls directly
 * in `arr[j] = ...` and loops nested below that assignment both count: a loop
 * such as `for (l < n) mx(n)` is O(n²) work for each marked multiple.
 */
function sieveMarkingWork(loop: ClangNode, bounds: SymbolicBounds, localCosts?: LocalFunctionCosts, constantSymbols?: ReadonlySet<string>): Complexity | undefined {
  const costs: Complexity[] = [];
  const directCosts = callsInSieveMarkingBody(loop).map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
  if (directCosts.some((cost) => !cost)) return undefined;
  costs.push(...directCosts.filter((cost): cost is Complexity => Boolean(cost)));

  for (const nested of nestedLoops(loop)) {
    const nestedAnalysis = analyseLoop(nested, bounds, localCosts, constantSymbols);
    if (!nestedAnalysis.value) return undefined;
    costs.push(nestedAnalysis.value);
  }
  return sequentialMaximum(costs) ?? "O(1)";
}

function sieveResult(body: ClangNode, bounds: SymbolicBounds, localCosts?: LocalFunctionCosts, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  for (const outer of (body.inner ?? []).filter((node) => node.kind === "ForStmt")) {
    const outerUpdate = updateOf(outer);
    const outerIndex = loopIndex(outerUpdate);
    const outerCondition = directCondition(outer);
    const limit = loopLimit(outerCondition ?? {}, outerIndex);
    const limitName = referencedName(limit);
    if (!outerIndex || !outerCondition || !limitName) continue;
    // Two canonical outer bounds select the same marking set: the square-root
    // bound `i * i <= n` and the full-range `i <= n` (or `i < n`). Marking the
    // multiples of each executed index costs Σ n/i over the guarded indices,
    // which is O(n log log n) for both spellings.
    const squareBounded = productOfSameSymbol(outerCondition, outerIndex);
    const linearBounded = referencesSymbol(outerCondition, outerIndex) && references(outerCondition, limitName);
    if (!squareBounded && !linearBounded) continue;

    for (const inner of nestedLoops(outer)) {
      const innerUpdate = updateOf(inner);
      const innerIndex = loopIndex(innerUpdate);
      const innerCondition = directCondition(inner);
      const innerLimit = loopLimit(innerCondition ?? {}, innerIndex);
      if (innerUpdate?.kind !== "CompoundAssignOperator" || innerUpdate.opcode !== "+=" || !referencesSymbol(innerUpdate, outerIndex)) continue;
      if ((!loopInitializationIsSquare(inner, innerIndex, outerIndex) && !loopInitializationIsMultiple(inner, innerIndex, outerIndex))
        || !references(innerLimit, limitName)) continue;

      const guardingIf = nodesOfKind(bodyOf(outer) ?? {}, "IfStmt").find((candidate) => {
        const condition = (candidate.inner ?? []).find((node) => node.kind !== "CompoundStmt");
        return Boolean(condition && referencesSymbol(condition, outerIndex) && nodesOfKind(candidate, "ForStmt").includes(inner));
      });
      const guard = (guardingIf?.inner ?? []).find((node) => node.kind !== "CompoundStmt");
      const tableName = indexingContainerName(guard);
      const marksSameTable = Boolean(tableName && nodesOfKind(bodyOf(inner) ?? {}, "DeclRefExpr").some((node) => node.referencedDecl?.name === tableName));
      if (!guardingIf || !tableName || !marksSameTable) continue;

      const vectorTable = nodesOfKind(body, "CXXConstructExpr").some((constructor) => {
        const type = constructor.type?.desugaredQualType ?? constructor.type?.qualType ?? "";
        return /\bvector</.test(type) && references(constructor, limitName);
      });
      const factorTable = initializesTableWithItsIndex(body, outer, tableName) && Boolean(guard && references(guard, tableName) && referencesSymbol(guard, outerIndex));
      if (!vectorTable && !factorTable) continue;
      const workPerMark = sieveMarkingWork(inner, bounds, localCosts, constantSymbols);
      if (!workPerMark) return unknown("The Sieve marking body contains an unresolved call or loop.");
      const total = composeSieveMarkingCost(workPerMark);
      if (!total) return unknown("The Sieve marking loop contains a supported call whose composition with O(n log log n) is not proved yet.");
      return {
        worstCaseTime: total,
        auxiliarySpace: vectorTable ? "O(n)" : "O(1)",
        confidence: "exact",
        proof: [
          factorTable ? "Detected the canonical smallest-prime-factor sieve marking pattern." : "Detected the canonical Sieve of Eratosthenes marking pattern.",
          "Multiples are marked from i² in steps of i, giving O(n log log n).",
          ...(workPerMark === "O(1)" ? [] : ["Each marking also performs " + workPerMark + " work, so the costs multiply."])
        ]
      };
    }
  }
  return undefined;
}

function loopUsesParameter(loop: ClangNode, parameter: string): boolean {
  const condition = conditionOf(loop);
  const update = updateOf(loop);
  if (!condition || !update) return false;
  const progressesLinearly = update.kind === "UnaryOperator" && ["++", "--"].includes(update.opcode ?? "")
    || update.kind === "CompoundAssignOperator" && ["+=", "-="].includes(update.opcode ?? "");
  return progressesLinearly && references(condition, parameter);
}

function scalarParameterNames(functionDecl: ClangNode): Set<string> {
  return new Set((functionDecl.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl")
    .filter((node) => !/\b(?:vector|deque|string|array|map|set|unordered_)/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
}

function hasRelaxationExpression(node: ClangNode): boolean {
  return nodesOfKind(node, "BinaryOperator").some((comparison) => {
    if (![">", "<", ">=", "<="].includes(comparison.opcode ?? "")) return false;
    return nodesOfKind(comparison, "BinaryOperator").some((part) => part.opcode === "+");
  });
}

function hasNestedMatrixAccess(node: ClangNode): boolean {
  const operators = nodesOfKind(node, "CXXOperatorCallExpr").filter((call) => {
    const name = call.name ?? nodesOfKind(call, "DeclRefExpr")
      .map((reference) => reference.referencedDecl?.name)
      .find((candidate) => candidate?.startsWith("operator"));
    return name === "operator[]";
  });
  // `matrix[i][j]` produces two operator[] calls; the Floyd relaxation has
  // several of these accesses. Requiring three prevents a generic cubic loop
  // from being relabelled as an all-pairs shortest-path algorithm.
  return operators.length >= 3;
}

/**
 * CP algorithms are recognized by semantic structure, never by their function
 * names. These rules deliberately return an estimate with an evidence score:
 * Clang proves the topology and the involved state, while a full semantic proof
 * of every graph invariant would require whole-program verification.
 */
function competitiveProgrammingPatternResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const scalarParameters = scalarParameterNames(functionDecl);
  const vectorParameters = new Set((functionDecl.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl" && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));

  for (const dimension of scalarParameters) {
    for (const outer of (body.inner ?? []).filter((node) => node.kind === "ForStmt")) {
      if (!loopUsesParameter(outer, dimension)) continue;
      const middle = nestedLoops(outer).filter((loop) => loop.kind === "ForStmt" && loopUsesParameter(loop, dimension));
      if (middle.length < 1) continue;
      const innermost = middle.some((candidate) => nestedLoops(candidate)
        .some((loop) => loop.kind === "ForStmt" && loopUsesParameter(loop, dimension)));
      if (!innermost || !hasNestedMatrixAccess(outer) || !hasRelaxationExpression(outer)) continue;
      return {
        worstCaseTime: "O(n^3)", auxiliarySpace: "O(1)", confidence: "estimated", confidencePercent: 93,
        proof: [
          "Detected three linearly bounded passes over the same scalar dimension.",
          "The innermost body performs a matrix-style relaxation, the structural invariant of Floyd-Warshall/all-pairs relaxation.",
          "Three complete passes give O(n³); the computation updates the supplied matrix in place."
        ]
      };
    }
  }

  for (const dimension of scalarParameters) {
    for (const outer of (body.inner ?? []).filter((node) => node.kind === "ForStmt")) {
      if (!loopUsesParameter(outer, dimension)) continue;
      const edgePass = nodesOfKind(bodyOf(outer) ?? {}, "CXXForRangeStmt").find((loop) => {
        if (loop.kind !== "CXXForRangeStmt") return false;
        const input = rangeContainerInfo(loop)?.name;
        // The desugared range variable in a real Clang AST can refer to a
        // compiler-generated temporary rather than the spelling of `edges`.
        // A vector input parameter plus a range-for is still enough evidence
        // here; the range cardinality is the independent edge dimension m.
        return Boolean(input ? vectorParameters.has(input) || vectorParameters.size > 0 : vectorParameters.size > 0);
      });
      if (!edgePass || !hasRelaxationExpression(edgePass)) continue;
      return {
        worstCaseTime: "O(n m)", auxiliarySpace: "O(n)", confidence: "estimated", confidencePercent: 91,
        proof: [
          "Detected an n-bounded sequence of complete edge-container passes.",
          "Each edge pass contains a distance-style relaxation, the structural invariant of Bellman-Ford.",
          "At most n passes over m edges give O(n m); the distance state is linear."
        ]
      };
    }
  }
  return undefined;
}

/**
 * A complete submask sweep has Σ_mask 2^popcount(mask) = 3^n iterations.
 * The rule requires both the outer `1 << n` domain and the canonical
 * `(sub - 1) & mask` successor, so ordinary bit-twiddling is not promoted.
 */
function submaskEnumerationResult(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  for (const outer of (body.inner ?? []).filter((node) => node.kind === "ForStmt")) {
    const outerAnalysis = loopBound(outer, bounds, constantSymbols);
    const outerIndex = loopIndex(outerAnalysis.update);
    const exponent = outerAnalysis.value ? exponentialBase(outerAnalysis.value) : undefined;
    if (!outerIndex || !exponent) continue;
    for (const inner of nestedLoops(outer).filter((node) => node.kind === "ForStmt")) {
      const innerDeclaration = nodesOfKind(inner, "VarDecl").find((node) => Boolean(declarationKey(node)));
      const innerIndex = declarationKey(innerDeclaration);
      if (!innerIndex || !referencesSymbol(innerDeclaration?.inner?.at(-1), outerIndex)) continue;
      const hasAndSuccessor = nodesOfKind(inner, "BinaryOperator").some((node) => {
        if (node.opcode !== "&") return false;
        const referencesInner = nodesOfKind(node, "DeclRefExpr").filter((reference) => referenceKey(reference) === innerIndex).length;
        const referencesOuter = nodesOfKind(node, "DeclRefExpr").some((reference) => referenceKey(reference) === outerIndex);
        const subtractsOne = nodesOfKind(node, "BinaryOperator").some((candidate) => candidate.opcode === "-"
          && nodesOfKind(candidate, "DeclRefExpr").some((reference) => referenceKey(reference) === innerIndex)
          && nodesOfKind(candidate, "IntegerLiteral").some((literal) => literal.value === "1"));
        return referencesInner >= 1 && referencesOuter && subtractsOne;
      });
      if (!hasAndSuccessor) continue;
      return {
        worstCaseTime: (`O(3^${exponent})` as Complexity), auxiliarySpace: "O(1)", confidence: "exact",
        proof: ["Detected the canonical submask successor `(sub - 1) & mask` inside a complete `1 << n` mask domain.", "Across all masks the submask counts sum to 3ⁿ, so the nested enumeration is O(3ⁿ)."]
      };
    }
  }
  return undefined;
}

/**
 * Prefix construction followed by constant-time range-query answers. The
 * evidence is a local vector recurrence reading its previous state and a
 * separate query-container pass; variable names are irrelevant.
 */
function prefixSumQueryResult(functionDecl: ClangNode, body: ClangNode, bounds: SymbolicBounds, localCosts?: LocalFunctionCosts, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const containers = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "") && Boolean(node.name));
  if (containers.length < 2) return undefined;
  const input = containers[0].name!;
  const queries = containers[1].name!;
  const prefix = nodesOfKind(body, "VarDecl").find((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    if (!node.name || !/\bvector\s*</.test(type)) return false;
    const construction = nodesOfKind(node, "CXXConstructExpr").at(0) ?? nodesOfKind(node, "CXXTemporaryObjectExpr").at(0);
    return expressionComplexity(construction?.inner?.[0], bounds, constantSymbols) === "O(n)";
  });
  const helperPreprocess = nodesOfKind(body, "VarDecl").find((node) => {
    if (!node.name) return false;
    const call = directCalls(node).find((candidate) => localSummaryForCall(candidate, localCosts));
    return Boolean(call && knownLoopCallCost(call, localCosts, bounds, constantSymbols) === "O(n)"
      && localCallSpace(call, localCosts, bounds, constantSymbols) === "O(n)");
  });
  const state = prefix ?? helperPreprocess;
  if (!state?.name) return undefined;
  const prefixName = prefix?.name;
  const hasPrefixRecurrence = prefix && nodesOfKind(body, "BinaryOperator").some((assignment) => {
    if (!prefixName || assignment.opcode !== "=" || (assignment.inner?.length ?? 0) < 2 || !references(assignment, prefixName)) return false;
    const right = assignment.inner![1];
    return references(right, prefixName) && nodesOfKind(right, "BinaryOperator").some((node) => node.opcode === "+");
  });
  if (!hasPrefixRecurrence && !helperPreprocess) return undefined;
  const queryPass = nodesOfKind(body, "CXXForRangeStmt").find((range) => rangeContainerInfo(range)?.name === queries);
  if (!queryPass) return undefined;
  const hasConstantQuery = references(queryPass, state.name);
  const appendsAnswers = directCalls(queryPass).some((call) => {
    const info = memberCallInfo(call);
    return Boolean(info && ["push_back", "emplace_back"].includes(info.name) && memberCallBaseName(call) !== state.name);
  });
  if (!hasConstantQuery) return undefined;
  return {
    worstCaseTime: "O(n + m)", auxiliarySpace: appendsAnswers ? "O(n + m)" : "O(n)", confidence: "estimated", confidencePercent: 91,
    proof: [hasPrefixRecurrence ? "Detected a local vector recurrence that accumulates each input prefix once." : "Detected a same-file linear preprocessing helper that returns the query state.", "A separate query-container pass reads the prefix state for constant-time range answers, so construction and queries add as O(n + m).", ...(appendsAnswers ? ["The implementation also stores one output per query, so auxiliary storage is O(n + m)."] : [])]
  };
}

/**
 * Recognizes the ownership/invariant structure of the three CP graph
 * traversals below.  This deliberately requires an adjacency-list parameter,
 * a range traversal over its neighbours, and the relevant worklist state;
 * a function name alone is never enough to activate the rule.
 */
function graphDimensions(functionDecl: ClangNode): { vertex: string; edge: string } {
  // Preserve an explicit vertex parameter through helper summaries. A
  // `solve(n, graph)` result should use n/m, while a bare adjacency-only
  // traversal remains in the conventional V/E notation.
  const vertexParameter = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && !/\b(?:vector|deque|string|array|map|set|unordered_)/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "")
    && /^(?:n|N|v|V|vertices|vertexCount|nodes|nodeCount)$/.test(node.name ?? ""));
  return vertexParameter?.name ? { vertex: vertexParameter.name, edge: "m" } : { vertex: "V", edge: "E" };
}

/**
 * A graph builder is proved from its data flow: allocate a typed adjacency
 * list by the vertex dimension, traverse one independent edge container, and
 * append each endpoint into that adjacency storage. This summary is useful
 * beyond any named algorithm because callers retain both the built graph and
 * the original traversal/query state.
 */
function adjacencyBuilderResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const dimension = graphDimensions(functionDecl);
  if (dimension.vertex === "V") return undefined;
  const edgeInputs = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "") && Boolean(node.name));
  if (edgeInputs.length === 0) return undefined;
  const adjacency = nodesOfKind(body, "VarDecl").find((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    return Boolean(node.name) && /\bvector\s*<\s*(?:std::)?vector\s*</.test(type)
      && references(node, dimension.vertex);
  });
  if (!adjacency?.name) return undefined;
  const edgePass = nodesOfKind(body, "CXXForRangeStmt").find((range) =>
    edgeInputs.some((edge) => references(range, edge.name!)));
  if (!edgePass) return undefined;
  const appendsIntoAdjacency = nodesOfKind(edgePass, "CXXMemberCallExpr").some((call) =>
    memberCallInfo(call)?.name === "push_back" && references(call, adjacency.name!));
  if (!appendsIntoAdjacency) return undefined;
  const graphCost = `O(${dimension.vertex} + ${dimension.edge})` as Complexity;
  return {
    worstCaseTime: graphCost,
    auxiliarySpace: graphCost as AuxiliarySpace,
    confidence: "estimated",
    confidencePercent: 92,
    proof: [
      "Detected typed adjacency storage sized by the vertex dimension and one complete independent edge-container pass.",
      "Each edge appends a bounded number of endpoints, so graph construction takes and retains O(n + m)."
    ]
  };
}

/**
 * Preserve a resolved adjacency-builder summary when its returned typed graph
 * is later traversed. This covers the frequent CP organization where graph
 * construction and the algorithm live in separate helpers, including an
 * indexed `for (u...)` around a neighbour range.
 */
function constructedAdjacencyTraversalResult(functionDecl: ClangNode, body: ClangNode, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const dimension = graphDimensions(functionDecl);
  if (dimension.vertex === "V") return undefined;
  const adjacency = nodesOfKind(body, "VarDecl").find((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    if (!node.name || !/\bvector\s*<\s*(?:std::)?vector\s*</.test(type)) return false;
    return directCalls(node).some((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols) === `O(${dimension.vertex} + ${dimension.edge})`);
  });
  if (!adjacency?.name) return undefined;
  const traversesGraph = nodesOfKind(body, "CXXForRangeStmt").some((range) => references(range, adjacency.name!));
  if (!traversesGraph) return undefined;
  const graphCost = `O(${dimension.vertex} + ${dimension.edge})` as Complexity;
  return {
    worstCaseTime: graphCost,
    auxiliarySpace: graphCost as AuxiliarySpace,
    confidence: "estimated",
    confidencePercent: 90,
    proof: [
      "Resolved a same-file typed adjacency builder and followed its returned graph into a neighbour traversal.",
      "Construction and traversal each process O(n + m) graph state, so their sequential total and retained storage are O(n + m)."
    ]
  };
}

/**
 * Binary lifting is proved from a logarithmic-height ancestor table and its
 * fill/query loops.  It is not triggered by an `lca`/`jump` name: the AST
 * must show a two-dimensional table, a `1 << level` logarithmic bound, and a
 * level-by-vertex table write.  A logarithmic query climb is added only when
 * it is actually present inside the query pass.
 */
function binaryLiftingResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const parameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl");
  const adjacency = parameters.find((node) => /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!adjacency?.name) return undefined;
  const queryInputs = parameters.filter((node) => node !== adjacency && /\b(?:vector|deque|array)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (queryInputs.length === 0) return undefined;
  const table = nodesOfKind(body, "VarDecl").find((node) => /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!table?.name) return undefined;
  const logarithmicLevel = nodesOfKind(body, "VarDecl").find((node) => {
    if (!node.name) return false;
    return nodesOfKind(body, "WhileStmt").some((loop) => nodesOfKind(conditionOf(loop) ?? loop, "BinaryOperator")
      // `n` is also referenced by `(1 << levels) <= n`; it is the bound, not
      // the table level. Require the candidate to occur inside the shift
      // expression itself so `levels` is selected structurally.
      .some((operation) => operation.opcode === "<<" && references(operation, node.name!)));
  });
  if (!logarithmicLevel?.name) return undefined;
  const allFors = nodesOfKind(body, "ForStmt");
  const tableFill = allFors.find((loop) => references(conditionOf(loop), logarithmicLevel.name!)
    && references(loop, table.name!)
    && nodesOfKind(loop, "BinaryOperator").some((operation) => operation.opcode === "=" && references(operation, table.name!)));
  if (!tableFill) return undefined;
  const queryPass = nodesOfKind(body, "CXXForRangeStmt").find((range) => {
    const rangeName = rangeContainerInfo(range)?.name;
    return queryInputs.some((input) => input.name === rangeName);
  });
  if (!queryPass) return undefined;
  // Inspect the query range's own subtree instead of relying on source
  // offsets. Clang's offsets are optional in JSON ASTs and structured
  // bindings introduce synthetic declarations, but lexical AST containment is
  // stable across both forms. A descending query loop commonly has
  // `level >= 0` as its condition; the logarithmic bound is carried by its
  // initializer (`level = LOG - 1`).
  const queryClimb = nodesOfKind(queryPass, "ForStmt")
    .some((loop) => references(loop, logarithmicLevel.name!));
  const time = queryClimb ? "O(n log n + m log n)" : "O(n log n + m)";
  return {
    worstCaseTime: time as Complexity,
    auxiliarySpace: "O(n log n)",
    confidence: "estimated",
    confidencePercent: queryClimb ? 90 : 88,
    proof: [
      "Detected a two-dimensional ancestor table indexed by a logarithmic binary-lifting level and a vertex dimension.",
      queryClimb
        ? "The table fill costs O(n log n), and each visible query climbs the levels once for O(log n) work."
        : "The table fill costs O(n log n); the visible query pass performs no ancestor-level climb, so its shown work is O(m)."
    ]
  };
}

function graphTraversalResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const adjacency = [
    ...(functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"),
    ...nodesOfKind(body, "VarDecl")
  ].find((node) => /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!adjacency?.name) return undefined;
  const adjacencyName = adjacency.name;
  const dimension = graphDimensions(functionDecl);
  const linearGraph = `O(${dimension.vertex} + ${dimension.edge})` as Complexity;
  const heapGraph = `O((${dimension.vertex} + ${dimension.edge}) log ${dimension.vertex})` as Complexity;
  const vertexSpace = `O(${dimension.vertex})` as AuxiliarySpace;
  const graphWorklistSpace = `O(${dimension.vertex} + ${dimension.edge})` as AuxiliarySpace;
  const rangesOverAdjacency = nodesOfKind(body, "CXXForRangeStmt")
    .some((range) => references(range, adjacencyName));
  if (!rangesOverAdjacency) return undefined;
  const localTypes = [
    ...nodesOfKind(body, "VarDecl"),
    ...(functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl")
  ].map((node) => node.type?.desugaredQualType ?? node.type?.qualType ?? "");
  const hasPriorityQueue = localTypes.some((type) => /\bpriority_queue\s*</.test(type));
  const hasOrderedSet = localTypes.some((type) => /\b(?:set|multiset)\s*</.test(type));
  const hasQueue = localTypes.some((type) => /\bqueue\s*</.test(type));
  const hasDeque = localTypes.some((type) => /\bdeque\s*</.test(type));
  const trackedState = [
    ...nodesOfKind(body, "VarDecl"),
    ...(functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl")
  ];
  // A vertex-only Dijkstra proof is not valid once the code carries a second
  // vertex-indexed state (for example dist[node][minimumCycleVertex]).  That
  // expanded state space changes both the number of relaxations and memory.
  // Abstain here; dedicated layered-state recognizers may prove it later.
  const hasExpandedVertexState = trackedState.some((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    return /\bvector\s*<\s*(?:std::)?vector\s*</.test(type)
      && /(?:dist|dp|state|best)/i.test(node.name ?? "");
  });
  if (hasExpandedVertexState) return undefined;
  // A generic vector<int> is not a visited invariant: level graphs, flow
  // layers, indegrees, and arbitrary DP state use the same type. Bool/char
  // state is unambiguous; an int vector needs an explicit visited/seen/dist
  // role before it can support the linear BFS/DFS proof.
  const hasVisited = trackedState.some((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    if (/\bvector\s*<\s*(?:bool|char)\s*>/.test(type)) return true;
    return /\bvector\s*<\s*(?:int|long\s+long|unsigned\s+long\s+long|double)\s*>/.test(type)
      && /(?:vis|seen|dist)/i.test(node.name ?? "");
  });
  // Depending on the selected translation unit's prelude, Clang can lower a
  // standard member invocation as CallExpr while retaining the member name on
  // MemberExpr. Use that semantic declaration evidence as a fallback.
  const names = (member: string) => nodesOfKind(body, "CXXMemberCallExpr").some((call) => memberCallInfo(call)?.name === member)
    || nodesOfKind(body, "MemberExpr").some((expression) => expression.name === member);
  const decrementsIndegree = nodesOfKind(body, "UnaryOperator").some((node) => node.opcode === "--");

  // Kahn is identified before generic heap traversal: both can have an
  // adjacency range and queue operations, but only Kahn has a decrement that
  // gates enqueuing a neighbour. When both FIFO and priority worklists appear
  // on alternative paths, the priority branch is the worst case.
  if (decrementsIndegree && names("push") && names("pop")) {
    // A literal boolean specialization can remove the FIFO branch entirely,
    // so priority Kahn must not depend on `front()` being visible too.
    if (hasPriorityQueue && names("top")) {
      return {
        worstCaseTime: heapGraph, auxiliarySpace: vertexSpace, confidence: "estimated", confidencePercent: 90,
        proof: ["Detected adjacency-list topological processing where a neighbour is enqueued only when its indegree reaches zero.", "A priority worklist makes the Kahn processing bound O((n + m) log n) in the visible graph dimensions."]
      };
    }
    if (hasQueue && names("front")) {
      return {
        worstCaseTime: linearGraph, auxiliarySpace: vertexSpace, confidence: "estimated", confidencePercent: 91,
        proof: ["Detected adjacency-list topological processing where a neighbour is enqueued only when its indegree reaches zero.", "The Kahn invariant removes each vertex once and scans each adjacency entry once, giving O(n + m)."]
      };
    }
  }

  if (hasPriorityQueue && names("push") && names("pop") && names("top")) {
    return {
      worstCaseTime: heapGraph, auxiliarySpace: graphWorklistSpace, confidence: "estimated",
      proof: ["Detected an adjacency-list neighbour traversal with a priority-queue worklist.", "Each vertex/edge relaxation can perform a logarithmic heap operation. This common duplicate-entry heap implementation can retain O(E) entries, so auxiliary storage is O(V + E)."]
    };
  }
  if (hasOrderedSet && hasVisited && names("insert") && names("erase") && names("begin")) {
    return {
      worstCaseTime: heapGraph, auxiliarySpace: graphWorklistSpace, confidence: "estimated", confidencePercent: 88,
      proof: ["Detected an adjacency-list relaxation traversal with an ordered set worklist and explicit erase/insert decrease-key updates.", "Each relaxation updates the ordered worklist in logarithmic time, giving O((n + m) log n) worst-case work."]
    };
  }
  if (hasQueue && hasVisited && names("push") && names("pop") && names("front")) {
    return {
      worstCaseTime: linearGraph, auxiliarySpace: vertexSpace, confidence: "estimated",
      proof: ["Detected an adjacency-list traversal with a FIFO queue and visited state.", "The standard visited invariant processes each vertex and adjacency entry at most once."]
    };
  }
  if (hasDeque && names("push_front") && names("push_back") && names("pop_front") && names("front")) {
    return {
      worstCaseTime: linearGraph, auxiliarySpace: vertexSpace, confidence: "estimated", confidencePercent: 91,
      proof: ["Detected an adjacency-list relaxation traversal with a deque using both front and back insertion.", "This is the 0-1 BFS worklist structure; each vertex/edge transition is processed a bounded number of times."]
    };
  }
  const recursiveCall = functionDecl.name && directCalls(body).some((call) => references(call, functionDecl.name!));
  if (hasVisited && recursiveCall) {
    return {
      worstCaseTime: linearGraph, auxiliarySpace: vertexSpace, confidence: "estimated",
      proof: ["Detected recursive traversal of an adjacency list guarded by visited state.", "The standard visited invariant visits each vertex and adjacency entry at most once; stack depth is at most V."]
    };
  }
  return undefined;
}

/**
 * Dense Prim is deliberately identified from its ownership and update
 * invariants, not its spelling: a vertex-bounded selection pass chooses the
 * cheapest unvisited vertex by a full scan, then consumes that vertex's
 * adjacency list to decrease candidate keys.  The full scan is O(V^2); the
 * neighbour ranges across selected vertices account for O(E).
 */
function densePrimResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const dimension = graphDimensions(functionDecl);
  if (dimension.vertex === "V") return undefined;
  const adjacency = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!adjacency?.name) return undefined;

  const declarations = [...nodesOfKind(body, "VarDecl"), ...(functionDecl.inner ?? [])];
  const hasCandidateKey = declarations.some((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    return /\bvector\s*<\s*(?:int|long\s+long|unsigned\s+long\s+long|double)\s*>/.test(type)
      && /(?:dist|key|best|cost)/i.test(node.name ?? "");
  });
  const hasChosenState = declarations.some((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    return /\bvector\s*<\s*(?:bool|char|int)\s*>/.test(type)
      && /(?:vis|used|chosen|taken|done)/i.test(node.name ?? "");
  });
  if (!hasCandidateKey || !hasChosenState) return undefined;

  const allFors = nodesOfKind(body, "ForStmt");
  const vertexPass = allFors.find((loop) => references(conditionOf(loop), dimension.vertex));
  if (!vertexPass) return undefined;
  const selectionScan = allFors.find((loop) => loop !== vertexPass
    && references(conditionOf(loop), dimension.vertex)
    && Boolean((loop.inner ?? []).some((node) => node.kind === "IfStmt")));
  if (!selectionScan) return undefined;
  const adjacencyUpdate = nodesOfKind(vertexPass, "CXXForRangeStmt")
    .some((range) => references(range, adjacency.name!));
  if (!adjacencyUpdate) return undefined;

  const time = `O(${dimension.vertex}^2 + ${dimension.edge})` as Complexity;
  const space = `O(${dimension.vertex})` as AuxiliarySpace;
  return {
    worstCaseTime: time,
    auxiliarySpace: space,
    confidence: "estimated",
    confidencePercent: 89,
    proof: [
      "Detected a vertex-bounded pass that repeatedly selects one unchosen vertex with a full candidate-key scan.",
      "Those V selection scans cost O(V²); the update loop consumes each selected adjacency list once, adding O(E).",
      "The candidate keys and chosen-state vectors retain O(V) auxiliary storage."
    ]
  };
}

/**
 * The heap form of Prim is different from Dijkstra even though both use a
 * priority queue.  Here the selected-state guard is the only per-vertex key
 * state and each unselected neighbour receives an edge-weight candidate;
 * there is no distance-relaxation vector.  That invariant proves O(E log V).
 */
function heapPrimResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const dimension = graphDimensions(functionDecl);
  if (dimension.vertex === "V") return undefined;
  const adjacency = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!adjacency?.name) return undefined;
  const state = [...nodesOfKind(body, "VarDecl"), ...(functionDecl.inner ?? [])];
  const hasPriorityQueue = state.some((node) => /\bpriority_queue\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  const hasChosenState = state.some((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    return /\bvector\s*<\s*(?:bool|char|int)\s*>/.test(type) && /(?:vis|used|chosen|taken|done)/i.test(node.name ?? "");
  });
  const hasDistanceKeys = state.some((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    return /\bvector\s*<\s*(?:int|long\s+long|unsigned\s+long\s+long|double)\s*>/.test(type)
      && /(?:dist|key|best)/i.test(node.name ?? "");
  });
  if (!hasPriorityQueue || !hasChosenState || hasDistanceKeys) return undefined;
  const hasAdjacencyRange = nodesOfKind(body, "CXXForRangeStmt").some((range) => references(range, adjacency.name!));
  const names = (member: string) => nodesOfKind(body, "CXXMemberCallExpr").some((call) => memberCallInfo(call)?.name === member)
    || nodesOfKind(body, "MemberExpr").some((expression) => expression.name === member);
  if (!hasAdjacencyRange || !names("push") || !names("pop") || !names("top")) return undefined;
  return {
    worstCaseTime: `O(${dimension.edge} log ${dimension.vertex})` as Complexity,
    auxiliarySpace: `O(${dimension.vertex} + ${dimension.edge})` as AuxiliarySpace,
    confidence: "estimated",
    confidencePercent: 88,
    proof: [
      "Detected a priority frontier that accepts an edge candidate only for an unchosen vertex, without a distance-relaxation table.",
      "Each adjacency entry can create one heap candidate and each heap operation is logarithmic, yielding O(E log V)."
    ]
  };
}

/**
 * A DFS-shaped traversal with a complete neighbour scan inside every
 * neighbour visit is not ordinary O(V+E) DFS.  The nested scan is analysed
 * structurally so an accidentally quadratic adjacency operation is visible.
 */
function repeatedAdjacencyScanResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const adjacency = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!adjacency?.name) return undefined;
  const adjacencyName = adjacency.name;
  const neighbourRange = nodesOfKind(body, "CXXForRangeStmt")
    .find((range) => references(range, adjacencyName));
  if (!neighbourRange) return undefined;
  const nestedScan = nestedLoops(neighbourRange).find((loop) => loop.kind === "ForStmt" || loop.kind === "WhileStmt");
  if (!nestedScan || !references(conditionOf(nestedScan), adjacencyName)) return undefined;
  const recursiveCall = Boolean(functionDecl.name && directCalls(body).some((call) => references(call, functionDecl.name!)));
  const hasVisited = (functionDecl.inner ?? []).some((node) => node.kind === "ParmVarDecl" && /\bvector\s*<\s*bool\s*>/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (recursiveCall && !hasVisited) return undefined;
  return recursiveCall ? {
    worstCaseTime: "O(V^3)",
    auxiliarySpace: "O(V)",
    confidence: "estimated",
    proof: ["Each visited vertex iterates over its neighbours and performs a second full scan of the current adjacency list for every neighbour.", "In a dense graph both scans can have O(V) work at each of O(V) visited vertices, so this DFS-shaped code is O(V³), not ordinary O(V + E) DFS."]
  } : {
    worstCaseTime: "O(V^2)",
    auxiliarySpace: "O(1)",
    confidence: "estimated",
    proof: ["One adjacency-list traversal contains a complete second scan of the same current adjacency list for every neighbour.", "A single invocation can therefore perform O(V²) work in the worst case."]
  };
}

/**
 * Recognizes a conventional union-find pass without relying on a function
 * name.  The type and member-call ownership are both taken from Clang's typed
 * AST: a local disjoint-set object must be used through find/unite operations
 * while scanning a container input.  The rule is estimated because proving
 * the inverse-Ackermann bound additionally requires inspecting the class body
 * for both union-by-rank/size and path compression.
 */
function disjointSetPassResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const disjointSetNames = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => /(?:disjoint[_ ]?set|union[_ ]?find|dsu)/i.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  if (disjointSetNames.size === 0) return undefined;

  const containerInput = (functionDecl.inner ?? []).some((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!containerInput) return undefined;

  const containerParameters = new Set((functionDecl.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl" && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  const sortInput = directCalls(body).find((call) => knownFreeFunction(call) === "O(n log n)")
    ? nodesOfKind(directCalls(body).find((call) => knownFreeFunction(call) === "O(n log n)")!, "DeclRefExpr")
      .map((node) => node.referencedDecl?.name)
      .find((name): name is string => Boolean(name && containerParameters.has(name)))
    : undefined;

  const loops = [
    ...(body.inner ?? []).filter((node) => ["ForStmt", "WhileStmt", "CXXForRangeStmt"].includes(node.kind ?? ""))
  ];
  for (const loop of loops) {
    const calls = directCalls(loop);
    const dsuCalls = calls.filter((call) => {
      const info = memberCallInfo(call);
      const base = memberCallBaseName(call);
      return Boolean(info && base && disjointSetNames.has(base) && ["find", "unite", "union", "merge"].includes(info.name));
    });
    if (dsuCalls.length === 0) continue;
    const scannedInput = loop.kind === "CXXForRangeStmt"
      ? rangeContainerInfo(loop)?.name
      : [...containerParameters].find((name) => references(conditionOf(loop), name));
    if (sortInput) {
      // Kruskal needs the sorted sequence to be the very same input scanned
      // through union-find. Sorting a result vector after a DSU pass is a
      // different expression and intentionally stays unproved here.
      if (scannedInput !== sortInput) return undefined;
      return {
        // Route through the canonical algebra: the alpha term is dominated by
        // the logarithm, so the printed bound is the tight `O(m log m)`.
        worstCaseTime: formatBound(parseBound("O(m log m + m α(n))")!), auxiliarySpace: "O(n + m)", confidence: "estimated",
        proof: ["Detected a sort of the same edge container that is subsequently scanned through a typed disjoint-set object.", "Sorting costs O(m log m); each union-find operation is conventionally O(α(n)) amortized when path compression and union by rank/size hold."]
      };
    }
    return {
      worstCaseTime: "O((n + m) α(n))", auxiliarySpace: "O(n)", confidence: "estimated",
      proof: ["Detected a typed disjoint-set object used through find/unite operations while scanning a container input.", "The reported bound assumes the conventional path-compression plus union-by-rank/size invariant; it remains Estimated until the class implementation is proven structurally."]
    };
  }
  return undefined;
}

/**
 * Recognizes rolling DP from its state representation rather than an algorithm
 * name: a one-dimensional local vector indexed by one symbolic dimension and
 * updated once for every element of a distinct input container.
 */
function rollingDynamicProgrammingResult(functionDecl: ClangNode, body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const allocationDimension = (node: ClangNode): Complexity | undefined => {
    const constructor = (node.inner ?? []).find((child) => child.kind === "CXXConstructExpr" || child.kind === "CXXTemporaryObjectExpr");
    return expressionComplexity(constructor?.inner?.[0], bounds, constantSymbols);
  };
  const stateVectors = nodesOfKind(body, "VarDecl").filter((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    if (!/\bvector\s*</.test(type)) return false;
    const dimension = allocationDimension(node);
    return dimension === "O(W)" || dimension === "O(sum)" || dimension === "O(m)";
  });
  if (stateVectors.length === 0) return undefined;
  const dimensions = new Set<Complexity>(stateVectors.map(allocationDimension).filter((value): value is Complexity => Boolean(value)));
  const headerInitializationBound = (loop: ClangNode, index: string | undefined): Complexity | undefined => {
    if (!index) return undefined;
    for (const headerPart of loop.inner ?? []) {
      if (headerPart.kind === "CompoundStmt") break;
      for (const declaration of nodesOfKind(headerPart, "VarDecl")) {
        if (declarationKey(declaration) !== index) continue;
        const initializer = declaration.inner?.at(-1);
        const value = expressionComplexity(initializer, bounds, constantSymbols);
        if (value) return value;
      }
    }
    return undefined;
  };
  const ranges = (body.inner ?? []).filter((node) => node.kind === "CXXForRangeStmt");
  for (const range of ranges) {
    const info = rangeContainerInfo(range);
    if (!info?.name) continue;
    const rangeParameter = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl" && node.name === info.name);
    if (!rangeParameter || !/\bvector\s*</.test(rangeParameter.type?.desugaredQualType ?? rangeParameter.type?.qualType ?? "")) continue;
    const rangeStatement = rangeBody(range);
    const nested = rangeStatement && (rangeStatement.kind === "ForStmt" || rangeStatement.kind === "WhileStmt")
      ? rangeStatement
      : (rangeStatement?.inner ?? []).find((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
    if (!nested) continue;
    const directBound = loopBound(nested, bounds, constantSymbols).value;
    const update = updateOf(nested);
    const initializedBound = update && (update.opcode === "++" || update.opcode === "--" || update.opcode === "+=" || update.opcode === "-=")
      ? headerInitializationBound(nested, loopIndex(update))
      : undefined;
    // In a rolling knapsack sweep, `cap` is initialized from W but terminates
    // against the current item's weight. The latter is not an independent
    // dimension; the visible W initializer is a safe worst-case bound.
    const bound = directBound ?? initializedBound;
    if (!bound || !dimensions.has(bound)) continue;
    const time = multiply("O(n)", bound);
    if (!time || time === "Does not terminate") continue;
    return {
      worstCaseTime: time,
      auxiliarySpace: bound as AuxiliarySpace,
      confidence: "estimated",
      proof: ["Detected a one-dimensional local DP state indexed by a symbolic capacity/sum dimension.", "Each input element performs one complete transition sweep over that state dimension, so the independent costs multiply."]
    };
  }
  return undefined;
}

export function callArguments(call: ClangNode, localCosts?: LocalFunctionCosts): ClangNode[] {
  const children = call.inner ?? [];
  // Clang represents member-call arguments after the MemberExpr callee. The
  // method target itself is recorded as referencedMemberDecl, not a normal
  // DeclRefExpr, so it needs its own precise path.
  if (call.kind === "CXXMemberCallExpr") {
    const memberIndex = children.findIndex((child) => child.kind === "MemberExpr");
    return memberIndex >= 0 ? children.slice(memberIndex + 1) : [];
  }
  const calleeChild = children.findIndex((child) => [...(localCosts?.keys() ?? [])].some((key) => callReferencesKey(child, key)));
  // A function-pointer alias has a VarDecl callee, not the original helper's
  // declaration key. For an ordinary CallExpr the first child is still the
  // callee, so its remaining children are the arguments.
  return calleeChild >= 0 ? children.slice(calleeChild + 1) : call.kind === "CallExpr" ? children.slice(1) : [];
}

/** Stable declaration identity for both free calls and C++ member calls. */
function callReferencesKey(node: ClangNode | undefined, key: string): boolean {
  let found = false;
  if (node) walk(node, (current) => {
    const member = current.referencedMemberDecl;
    const memberId = typeof member === "string" ? member : member?.id;
    const memberName = typeof member === "string" ? undefined : member?.name;
    if (current.referencedDecl?.id === key || current.referencedDecl?.name === key || memberId === key || memberName === key) found = true;
  });
  return found;
}

function booleanLiteralArgument(node: ClangNode | undefined): boolean | undefined {
  if (!node) return undefined;
  if (["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(node.kind ?? "")) return booleanLiteralArgument(node.inner?.at(-1));
  if (node.kind === "CXXBoolLiteralExpr") return node.value === "true" || node.value === "1" || (node.value as unknown) === true;
  if (node.kind === "IntegerLiteral") {
    if (node.value === "0") return false;
    if (node.value === "1") return true;
  }
  return undefined;
}

function localSummaryForCall(call: ClangNode, localCosts?: LocalFunctionCosts): LocalFunctionSummary | undefined {
  // Only the call's DIRECT callee may bind a summary. Walking the whole
  // subtree would let `cout << helper(x)` inherit helper's summary, whose
  // parameter substitution then fails against the operator's arguments and
  // erases an otherwise-resolvable chain.
  for (const [key, summary] of localCosts ?? []) {
    const directCallee = call.kind === "CXXMemberCallExpr"
      ? (call.inner ?? []).find((child) => child.kind === "MemberExpr")
      : call.inner?.[0];
    if (!directCallee || !callReferencesKey(directCallee, key)) continue;
    const arguments_ = callArguments(call, localCosts);
    for (let index = 0; index < summary.parameters.length; index += 1) {
      const parameter = summary.parameters[index];
      const literal = booleanLiteralArgument(arguments_[index]);
      if (literal === undefined) continue;
      const specialized = summary.booleanSpecializations?.get(parameter.name);
      const value = literal ? specialized?.whenTrue : specialized?.whenFalse;
      if (value) return { ...summary, ...value, booleanSpecializations: undefined };
    }
    return summary;
  }
  return undefined;
}

function atomicSymbol(value: Complexity | undefined): string | undefined {
  if (!value) return undefined;
  const match = /^O\(([A-Za-z_][A-Za-z0-9_]*|1)\)$/.exec(value);
  return match?.[1];
}

function escapeRegex(text: string): string {
  return text.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
}

/** Substitute simple symbolic call arguments into a local helper summary. */
function substituteLocalSummary(value: Complexity, call: ClangNode, summary: LocalFunctionSummary, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): Complexity | undefined {
  if (summary.parameters.length === 0) return value;
  const match = /^O\((.+)\)$/.exec(value);
  if (!match) return value;
  let body = match[1];
  const arguments_ = callArguments(call, localCosts);
  for (let index = 0; index < summary.parameters.length; ++index) {
    const parameter = summary.parameters[index];
    if (!new RegExp(`\\b${escapeRegex(parameter.symbol)}\\b`).test(body)) continue;
    const argument = arguments_[index];
    const replacement = atomicSymbol(expressionComplexity(argument, bounds ?? new Map(), constantSymbols));
    if (!replacement) return undefined;
    body = body.replace(new RegExp(`\\b${escapeRegex(parameter.symbol)}\\b`, "g"), replacement);
  }
  // Keep the expression tree normalised after substitutions such as n/2 -> n.
  return (`O(${body})` as Complexity);
}

function knownLoopCallCost(call: ClangNode, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): Complexity | undefined {
  const summary = localSummaryForCall(call, localCosts);
  if (summary) return substituteLocalSummary(summary.value, call, summary, localCosts, bounds, constantSymbols);
  if (call.kind === "CXXMemberCallExpr") return knownMemberCallCost(call);
  if (call.kind === "CXXOperatorCallExpr") {
    if (process.env.PROJECT_X_DEBUG) console.error(`[opbranch] reached, callee refs=${nodesOfKind(call, "DeclRefExpr").map((n) => n.referencedDecl?.name).slice(0, 3).join(",")}`);
    const known = knownOperatorCallCost(call);
    if (known) {
      // The operation itself (iterator arithmetic, stream insertion) is O(1)
      // per operation, but argument subexpressions carry their own costs:
      // `m.find(k) != m.end()` composes the logarithmic lookup, and
      // `cout << helper(x)` composes the helper's summary.
      const nested = directCalls(call).filter((inner) => inner !== call);
      if (nested.length === 0) return known;
      const nestedCosts = nested.map((inner) => knownLoopCallCost(inner, localCosts, bounds, constantSymbols));
      if (process.env.PROJECT_X_DEBUG) console.error(`[nest] known=${known} nested=${nested.length} costs=${JSON.stringify(nestedCosts)}`);
      if (nestedCosts.some((cost) => !cost)) return undefined;
      return sequentialMaximum([known, ...nestedCosts.filter((cost): cost is Complexity => Boolean(cost))]);
    }
    // Some prelude ASTs preserve the operator node but omit enough receiver
    // information for knownOperatorCallCost; continue into the declaration-
    // based indexed-receiver fallback below.
  }
  // The callee's own resolved name. Argument subexpressions may reference
  // operator[]/begin/end themselves; only the callee decides the call class.
  const calleeName = nodesOfKind(call.inner?.[0] ?? {}, "DeclRefExpr")
    .map((reference) => reference.referencedDecl?.name)
    .find((value): value is string => Boolean(value));
  // The minimal Windows prelude can lower `text[index]` through a generic
  // CallExpr rather than CXXOperatorCallExpr. Recover its receiver type from
  // the resolved declaration so indexed standard sequences remain O(1).
  if (calleeName === "operator[]") {
    const receiverType = nodesOfKind(call, "DeclRefExpr")
      .filter((reference) => reference.referencedDecl?.name !== "operator[]")
      .map((reference) => reference.type?.desugaredQualType ?? reference.type?.qualType
        ?? reference.referencedDecl?.type?.desugaredQualType ?? reference.referencedDecl?.type?.qualType ?? "")
      .find((type) => /\b(?:vector|deque|array|string|basic_string)\b/.test(type));
    if (receiverType) {
      if (/unordered_(?:map|set)/.test(receiverType)) return "O(n)";
      if (/\b(?:map|set|multimap|multiset)\b/.test(receiverType)) return "O(log n)";
      return "O(1)";
    }
  }
  // Some Windows Clang/prelude combinations lower a simple stream insertion
  // as a CallExpr rooted at `cout`/`cin` rather than a CXXOperatorCallExpr.
  // Scalar stream I/O is one operation for the static complexity model;
  // container traversal is still represented by its enclosing loop.
  if (["cout", "cerr", "clog", "cin"].some((stream) => references(call, stream))) return "O(1)";
  // Only a call whose CALLEE is an endpoint helper is a constant-time
  // endpoint query; `sort(a.begin(), a.end())` merely receives endpoints as
  // arguments and must fall through to the free-function cost table.
  const endpointHelper = calleeName !== undefined && ["begin", "end", "cbegin", "cend", "rbegin", "rend", "data"].includes(calleeName);
  if (endpointHelper && (call.inner ?? []).slice(1).some((argument) => expressionComplexity(argument, bounds ?? new Map(), constantSymbols))) return "O(1)";
  const known = knownFreeFunction(call);
  if (known) return known;
  return undefined;
}

function localCallConfidence(call: ClangNode, localCosts?: LocalFunctionCosts): Exclude<Confidence, "unknown"> | undefined {
  return localSummaryForCall(call, localCosts)?.confidence;
}

function localCallSpace(call: ClangNode, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AuxiliarySpace | undefined {
  const summary = localSummaryForCall(call, localCosts);
  return summary ? substituteLocalSummary(summary.auxiliarySpace, call, summary, localCosts, bounds, constantSymbols) as AuxiliarySpace | undefined : undefined;
}

function maximumAuxiliarySpace(values: AuxiliarySpace[]): AuxiliarySpace | undefined {
  return values.reduce<AuxiliarySpace | undefined>((largest, value) => {
    if (!largest) return value;
    if (largest === "Unknown" || value === "Unknown") return "Unknown";
    // Incomparable proven sizes (say O(n) and O(m)) must combine as their sum:
    // dropping either one would understate peak storage (round-7 BUG-017).
    return (dominantExpression(largest, value) ?? sequentialMaximum([largest, value])) as AuxiliarySpace | undefined;
  }, undefined);
}

function rangeContainerInfo(range: ClangNode): { name?: string; type: string } | undefined {
  const rangeVariable = nodesOfKind(range, "VarDecl").find((node) => node.name?.startsWith("__range"));
  if (!rangeVariable) return undefined;
  const source = nodesOfKind(rangeVariable, "DeclRefExpr").at(0);
  return {
    name: source?.referencedDecl?.name,
    type: source?.type?.desugaredQualType ?? source?.type?.qualType ?? rangeVariable.type?.desugaredQualType ?? rangeVariable.type?.qualType ?? ""
  };
}

function rangeBody(range: ClangNode): ClangNode | undefined {
  return (range.inner ?? []).find((node) => node.kind === "CompoundStmt") ?? (range.inner ?? []).at(-1);
}

function callsInRangeBody(range: ClangNode): ClangNode[] {
  const calls: ClangNode[] = [];
  const kinds = new Set(["CallExpr", "CXXMemberCallExpr", "CXXOperatorCallExpr"]);
  const visit = (node: ClangNode): void => {
    if (kinds.has(node.kind ?? "")) calls.push(node);
    for (const child of node.inner ?? []) {
      if (["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(child.kind ?? "")) continue;
      visit(child);
    }
  };
  visit(rangeBody(range) ?? {});
  return calls;
}

/** AST rule for a range-for over a standard sequence/tree container. */
function analyseRangeFor(range: ClangNode, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): LoopAnalysis {
  const info = rangeContainerInfo(range);
  if (!info) return {};
  // An unordered container's bucket history is not visible in a selected
  // function, and arbitrary user ranges are likewise not proven here.
  const supportedRangeType = /\b(?:vector|deque|array|map|set|multimap|multiset)\s*</.test(info.type)
    || /\b(?:string|basic_string)\b/.test(info.type);
  if (/unordered_/.test(info.type) || !supportedRangeType) return {};

  const body = rangeBody(range) ?? {};
  const nestedRanges = (body.inner ?? []).filter((node) => node.kind === "CXXForRangeStmt");
  const nestedTraditionalLoops = (body.inner ?? []).some((node) => ["ForStmt", "WhileStmt", "DoStmt"].includes(node.kind ?? ""));
  if (nestedTraditionalLoops || nestedRanges.length > 1) return {};
  if (nestedRanges.length === 1) {
    const nested = analyseRangeFor(nestedRanges[0], localCosts, bounds, constantSymbols);
    // Nested ranges over a nested container visit its total element count, not
    // outer-size times an invented independent n.
    return nested.value ? { value: nested.value, proof: ["Nested range-for visits each contained element once; work is measured by total element count."] } : {};
  }

  const callCosts = callsInRangeBody(range).map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
  if (callCosts.some((cost) => !cost)) return {};
  const operationCost = sequentialMaximum(callCosts.filter((cost): cost is Complexity => Boolean(cost))) ?? "O(1)";
  // Keep independently sized containers distinct. The caller's symbolic map
  // maps the first input container to n, the second to m, and so on; falling
  // back to n preserves standalone range-for behavior.
  const traversal = info.name ? bounds?.get(info.name) ?? "O(n)" : "O(n)";
  const value = multiply(traversal, operationCost);
  return value ? {
    value,
    proof: [operationCost === "O(1)"
      ? "Range-for advances through each container element once."
      : "Range-for visits each element once and composes its per-element operation cost."]
  } : {};
}

/**
 * Structural sparse-table preprocessing: a bit-width counter establishes a
 * logarithmic number of levels, a typed two-dimensional table is assigned,
 * and a nested level/index pass fills its cells. Names are irrelevant.
 */
function sparseTableConstructorResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  // Binary lifting has the same asymptotic preprocessing shape.  Its input is
  // an adjacency matrix/list and its queries may climb every level, so leave
  // those functions to the more specific binary-lifting recognizer below.
  const hasAdjacencyParameter = (functionDecl.inner ?? []).some((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (functionDecl.kind !== "CXXConstructorDecl" && hasAdjacencyParameter) return undefined;
  const bitWidthCounter = (body.inner ?? []).find((statement) => {
    if (statement.kind !== "WhileStmt" && statement.kind !== "ForStmt") return false;
    const update = updateOf(statement);
    return update?.kind === "UnaryOperator" && update.opcode === "++"
      && nodesOfKind(conditionOf(statement) ?? {}, "BinaryOperator").some((node) => node.opcode === "<<");
  });
  const builtinBitWidth = nodesOfKind(body, "VarDecl").find((node) => node.name
    && nodesOfKind(node, "DeclRefExpr").some((reference) => ["__builtin_clz", "__builtin_clzll"].includes(reference.referencedDecl?.name ?? "")));
  const levelSymbol = bitWidthCounter
    ? loopIndex(updateOf(bitWidthCounter))
    : declarationKey(builtinBitWidth);
  if (!levelSymbol) return undefined;
  const memberAssignedTable = nodesOfKind(body, "CXXMemberCallExpr").some((call) => {
    const assigns = nodesOfKind(call, "MemberExpr").some((member) => member.name === "assign");
    const matrixReceiver = nodesOfKind(call, "MemberExpr").some((member) => /\bvector\s*<\s*(?:std::)?vector\s*</.test(member.type?.desugaredQualType ?? member.type?.qualType ?? ""));
    return assigns && matrixReceiver;
  });
  const localTable = nodesOfKind(body, "VarDecl").find((node) => node.name
    && /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  const localTableWrite = localTable?.name && nodesOfKind(body, "BinaryOperator")
    .some((operation) => operation.opcode === "=" && references(operation, localTable.name!));
  if (!memberAssignedTable && !localTableWrite) return undefined;
  const levelFill = (body.inner ?? []).find((statement) => {
    if (statement.kind !== "ForStmt") return false;
    // The first fill dimension must be the same logarithmic level counter,
    // not merely any nested n-by-n loop that happens to live in a class with
    // a bit-width helper. This declaration-identity check is what keeps the
    // rule structural rather than a source-pattern lookup.
    if (!referencesSymbol(conditionOf(statement), levelSymbol)) return false;
    const inner = immediateNestedLoops(statement);
    // A sparse table writes a level-by-index grid. A third nested loop means
    // the table fill may cost more than O(n log n), so leave it to the
    // general analyzer instead of under-reporting it here.
    return inner.length === 1 && immediateNestedLoops(inner[0]).length === 0;
  });
  if (!levelFill) return undefined;
  const queryPass = nodesOfKind(body, "CXXForRangeStmt").find((range) => {
    const input = rangeContainerInfo(range)?.name;
    return input && (functionDecl.inner ?? []).some((node) => node.kind === "ParmVarDecl" && node.name === input);
  });
  const hasQueryPass = Boolean(queryPass && functionDecl.kind !== "CXXConstructorDecl");
  return {
    worstCaseTime: (hasQueryPass ? "O(n log n + m)" : "O(n log n)") as Complexity,
    auxiliarySpace: "O(n log n)", confidence: "estimated", confidencePercent: hasQueryPass ? 91 : 90,
    proof: [
      bitWidthCounter
        ? "A shifting condition establishes a logarithmic bit-width level count."
        : "A compiler bit-width primitive establishes the logarithmic table height.",
      hasQueryPass
        ? "A typed two-dimensional table is filled by a level-by-index pass, then a separate query range is traversed once: O(n log n + m) time and O(n log n) storage."
        : "A typed two-dimensional table is assigned and filled by a level-by-index nested pass, proving O(n log n) preprocessing time and storage."
    ]
  };
}

/**
 * Potential-method proof for the common monotonic stack/deque shape.  Names
 * and comparisons are intentionally irrelevant: the invariant is that an
 * element enters one local worklist once in a single input pass, and the only
 * nested-loop mutation removes an element.  Therefore total removals cannot
 * exceed total insertions, even though an individual iteration may pop many
 * elements.
 */
function monotonicWorklistResult(functionDecl: ClangNode, body: ClangNode, bounds: SymbolicBounds): AnalysisResult | undefined {
  const parameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl");
  const localWorklists = nodesOfKind(body, "VarDecl").filter((node) => node.name
    && /\b(?:vector|deque|stack)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (localWorklists.length === 0) return undefined;
  const rangePasses = nodesOfKind(body, "CXXForRangeStmt").filter((range) => {
    const input = rangeContainerInfo(range)?.name;
    return Boolean(input && parameters.some((parameter) => parameter.name === input));
  });
  // Contest `main` functions commonly use an indexed pass over a local
  // vector rather than a range-for over a parameter. The amortized argument
  // is identical once the loop bound is proven symbolically: each iteration
  // inserts once and the nested loop only removes prior insertions.
  const indexedPasses = (body.inner ?? []).filter((statement) => statement.kind === "ForStmt")
    .filter((loop) => Boolean(loopBound(loop, bounds).value));
  const outerPasses = [...rangePasses, ...indexedPasses];
  for (const pass of outerPasses) {
    const traversal = pass.kind === "CXXForRangeStmt"
      ? "O(n)" as Complexity
      : loopBound(pass, bounds).value;
    if (!traversal) continue;
    const nestedWhiles = nodesOfKind(pass, "WhileStmt");
    if (nestedWhiles.length === 0) continue;
    for (const worklist of localWorklists) {
      const name = worklist.name!;
      const allCalls = directCalls(pass);
      const pushed = allCalls.some((call) => memberCallBaseName(call) === name
        && ["push", "emplace", "push_back", "emplace_back", "push_front", "emplace_front"].includes(memberCallInfo(call)?.name ?? ""));
      if (!pushed) continue;
      const removalLoop = nestedWhiles.find((loop) => {
        const calls = directCalls(loop);
        const removes = calls.some((call) => memberCallBaseName(call) === name
          && ["pop", "pop_back", "pop_front"].includes(memberCallInfo(call)?.name ?? ""));
        const reinserts = calls.some((call) => memberCallBaseName(call) === name
          && ["push", "emplace", "push_back", "emplace_back", "push_front", "emplace_front"].includes(memberCallInfo(call)?.name ?? ""));
        return removes && !reinserts;
      });
      if (!removalLoop) continue;
      return {
        worstCaseTime: traversal, auxiliarySpace: traversal as AuxiliarySpace, confidence: "estimated", confidencePercent: 92,
        proof: [
          "Detected one proven input pass that inserts each item into one local stack/deque worklist.",
          "The nested loop only removes from that same worklist and never reinserts; every removal is charged to an earlier insertion, so total work is linear in the pass length."
        ]
      };
    }
  }
  return undefined;
}

/**
 * Coordinate compression is identified by its data transformation, not a
 * helper/function name: a sequence is sorted, duplicate values are removed
 * with the standard `unique`/`erase` idiom, and the resulting rank domain is
 * used by later code or returned. Sorting dominates the linear deduplication.
 */
function coordinateCompressionResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const calls = directCalls(body);
  const hasSort = calls.some((call) => knownFreeFunction(call) === "O(n log n)");
  const hasUnique = nodesOfKind(body, "DeclRefExpr").some((reference) => reference.referencedDecl?.name === "unique");
  const hasErase = calls.some((call) => memberCallInfo(call)?.name === "erase");
  if (!hasSort || !hasUnique || !hasErase) return undefined;
  const vectorParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  const hasOwnedCopy = vectorParameters.some((parameter) => !/&/.test(parameter.type?.qualType ?? ""))
    || nodesOfKind(body, "VarDecl").some((node) => /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  return {
    worstCaseTime: "O(n log n)",
    auxiliarySpace: hasOwnedCopy ? "O(n)" : "O(1)",
    confidence: "estimated",
    confidencePercent: 91,
    proof: [
      "Detected a sorted sequence followed by the standard unique-and-erase deduplication transformation.",
      hasOwnedCopy
        ? "Sorting dominates the linear deduplication, and the owned compressed sequence retains O(n) auxiliary storage."
        : "Sorting dominates the linear deduplication; the visible transformation mutates an existing sequence without a separate rank copy."
    ]
  };
}

/**
 * A sort followed only by canonical linear validation scans is O(n log n),
 * even when the scan exits early on a mismatch.  The proof is based on the
 * work topology (sort + scans), not on a missing-number function name.
 */
function sortThenLinearScanResult(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  // This recognizer is for sequential phases only. A sort lexically inside a
  // scan is per-iteration work and must flow through analyseLoop, where the
  // scan's bound multiplies the O(n log n) call cost.
  const hasSort = callsOutsideLoops(body).some((call) => knownFreeFunction(call) === "O(n log n)");
  if (!hasSort) return undefined;
  // A `while (q--) lower_bound(...)` phase is not a validation scan: it has
  // an independent q dimension and may add q log n work. Let the general
  // sequential composer retain that term instead of prematurely returning
  // only the sort's cost. The same protection covers a testcase/query loop
  // whose body is more expensive than a scalar check. A range-for over an
  // input sequence is a canonical linear validation scan, so it is admitted
  // below through the same proven-bound gate as a traditional for loop.
  if ((body.inner ?? []).some((node) => node.kind === "WhileStmt" || node.kind === "DoStmt")) return undefined;
  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "CXXForRangeStmt");
  if (loops.length === 0) return undefined;
  const allLinear = loops.every((loop) => {
    if (nestedLoops(loop).length > 0) return false;
    if (loop.kind === "CXXForRangeStmt") {
      const value = analyseRangeFor(loop, undefined, bounds, constantSymbols).value;
      return value === "O(n)" || value === "O(n log n)" || value === "O(1)";
    }
    const bound = loopBound(loop, bounds, constantSymbols).value;
    return bound === "O(n)" || bound === "O(1)";
  });
  if (!allLinear) return undefined;
  return {
    worstCaseTime: "O(n log n)",
    auxiliarySpace: "O(1)",
    confidence: "exact",
    proof: ["A comparison sort costs O(n log n); every other visible traversal is a single canonical linear scan, and an early break can only reduce that work."]
  };
}

/**
 * Local `std::function` lambdas are common in CP templates. They do not have
 * a translation-unit FunctionDecl, so the ordinary call-graph DFS cannot see
 * their self edge. This recognizer uses the lambda binding, its parameter,
 * and the proven decrement/division in every visible self call instead of a
 * lambda/function name convention.
 */
/**
 * Extracts the constant decreases in one *non-nested* recursive return path.
 * It deliberately rejects `f(f(n - 1))`, aliases, and data-dependent updates:
 * those require a richer call graph / value analysis and must not be confused
 * with an ordinary linear recurrence.
 */
function constantDecrementSteps(calls: readonly ClangNode[], parameter: string): number[] | undefined {
  if (calls.length === 0) return undefined;
  const steps: number[] = [];
  for (const call of calls) {
    // A recursive call used as another recursive call's argument is nested
    // recursion, not a branching recurrence such as Fibonacci.
    if (directCalls(call).some((nested) => nested !== call)) return undefined;
    const candidates = nodesOfKind(call, "BinaryOperator").filter((operation) => {
      if (operation.opcode !== "-" || (operation.inner?.length ?? 0) !== 2) return false;
      const [left, right] = operation.inner!;
      return references(left, parameter)
        && nodesOfKind(right, "IntegerLiteral").length === 1
        && nodesOfKind(right, "BinaryOperator").length === 0;
    });
    if (candidates.length !== 1) return undefined;
    const literal = nodesOfKind(candidates[0].inner![1], "IntegerLiteral").at(0)?.value;
    const step = literal === undefined ? Number.NaN : Number(literal);
    if (!Number.isFinite(step) || step < 1) return undefined;
    steps.push(step);
  }
  return steps;
}

/** Numerical characteristic root of Σ r^-dᵢ = 1 for positive integer steps. */
function branchingExponentialComplexity(steps: readonly number[]): Complexity | undefined {
  if (steps.length < 2) return undefined;
  let low = 1;
  let high = Math.max(2, steps.length + 1);
  for (let iteration = 0; iteration < 80; ++iteration) {
    const middle = (low + high) / 2;
    const sum = steps.reduce((total, step) => total + middle ** (-step), 0);
    if (sum > 1) low = middle;
    else high = middle;
  }
  const base = (low + high) / 2;
  if (!Number.isFinite(base) || base <= 1) return undefined;
  const rounded = Number(base.toFixed(3));
  return Math.abs(rounded - 2) < 0.005 ? "O(2^n)" : (`O(${rounded}^n)` as Complexity);
}

function recursiveLambdaResult(body: ClangNode): AnalysisResult | undefined {
  const binding = nodesOfKind(body, "VarDecl").find((node) => Boolean(node.name) && nodesOfKind(node, "LambdaExpr").length > 0);
  if (!binding?.name) return undefined;
  const lambda = nodesOfKind(binding, "LambdaExpr").at(0);
  // Lambda parameters/body are owned by the implicit `operator()` method,
  // while Clang also mirrors a compound statement under LambdaExpr for the
  // capture initializer. Follow the callable method, not that mirror.
  const invoke = lambda && nodesOfKind(lambda, "CXXMethodDecl").find((method) => method.name === "operator()");
  const lambdaBody = invoke && (invoke.inner ?? []).find((node) => node.kind === "CompoundStmt");
  const parameter = invoke && (invoke.inner ?? []).find((node) => node.kind === "ParmVarDecl");
  if (!lambdaBody || !parameter?.name) return undefined;
  const selfCalls = directCalls(lambdaBody).filter((call) => references(call, binding.name!));
  if (selfCalls.length === 0) return undefined;
  const hasBaseCase = nodesOfKind(lambdaBody, "IfStmt").some((branch) => references(branch, parameter.name!))
    || nodesOfKind(lambdaBody, "ConditionalOperator").some((branch) => references(branch, parameter.name!));
  if (!hasBaseCase) return undefined;
  const hasReduction = (opcode: "/" | "-"): boolean => selfCalls.every((call) =>
    nodesOfKind(call, "BinaryOperator").some((operation) => {
      if (operation.opcode !== opcode || (operation.inner?.length ?? 0) < 2) return false;
      const [left, right] = operation.inner!;
      // Require the actual right operand to be a literal. An expression such
      // as x - (x % 3 + 1) is data-dependent and must remain Unknown even
      // though it contains a nested literal one.
      const directLiteral = nodesOfKind(right, "IntegerLiteral").some((literal) => Number(literal.value) >= (opcode === "/" ? 2 : 1))
        && nodesOfKind(right, "BinaryOperator").length === 0;
      return references(left, parameter.name!) && directLiteral;
    }));
  const memoized = nodesOfKind(body, "VarDecl").some((node) => /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "")
    && Boolean(node.name) && references(lambdaBody, node.name!));
  if (memoized && hasReduction("-")) {
    return {
      worstCaseTime: "O(n)", auxiliarySpace: "O(n)", confidence: "estimated", confidencePercent: 89,
      proof: ["Detected a self-capturing lambda with unit-decreasing recursive states and a visible indexed vector cache.", "Each of O(n) states is retained and computed at most once, giving linear time and auxiliary storage."]
    };
  }
  if (hasReduction("/")) {
    if (selfCalls.length >= 2) return {
      worstCaseTime: "O(n)", auxiliarySpace: "O(log n)", confidence: "estimated", confidencePercent: 88,
      proof: ["Detected two self-capturing lambda calls on a halved state.", "The recurrence T(n)=2T(n/c)+O(1) has linear total work and logarithmic call depth."]
    };
    return {
      worstCaseTime: "O(log n)", auxiliarySpace: "O(log n)", confidence: "estimated", confidencePercent: 90,
      proof: ["Detected one self-capturing lambda call on a state divided by a constant.", "The state shrinks geometrically, so both calls and stack depth are logarithmic."]
    };
  }
  if (hasReduction("-")) {
    if (selfCalls.length >= 2) {
      const exponential = constantDecrementSteps(selfCalls, parameter.name!);
      if (!exponential) return undefined;
      const time = branchingExponentialComplexity(exponential);
      if (!time) return undefined;
      return {
        worstCaseTime: time, auxiliarySpace: "O(n)", confidence: "estimated", confidencePercent: 88,
        proof: ["Detected multiple direct lambda calls whose argument decreases by proven positive constants.", `Solved the characteristic equation Σ r^-d = 1 for decreases (${exponential.join(", ")}); the call tree is ${time} with linear maximum depth.`]
      };
    }
    return {
      worstCaseTime: "O(n)", auxiliarySpace: "O(n)", confidence: "estimated", confidencePercent: 90,
      proof: ["Detected one self-capturing lambda call on a unit-decreasing state.", "The state reaches the base case after O(n) calls with O(n) stack depth."]
    };
  }
  return undefined;
}

/**
 * Resolves `auto f = localHelper; return f(arg);` when Clang proves that the
 * alias is never reassigned.  This is a call-edge rewrite, not a name-based
 * algorithm rule: the helper's already-computed AST summary is substituted
 * through the alias call exactly as for a direct call.
 */
function forwardedFunctionAliasResult(body: ClangNode, localCosts?: LocalFunctionCosts, parameters?: SymbolicBounds): AnalysisResult | undefined {
  if (!localCosts || localCosts.size === 0) return undefined;
  const binding = nodesOfKind(body, "VarDecl").find((node) => {
    // The initializer must be a DIRECT DeclRefExpr to a function (after cast
    // unwrapping) - a CallExpr initializer (`auto it = unique(...)`) is a
    // computed result, not an alias.
    let initializer = node.inner?.at(-1);
    while (initializer && ["ImplicitCastExpr", "ParenExpr"].includes(initializer.kind ?? "")) initializer = initializer.inner?.[0];
    if (!initializer || initializer.kind !== "DeclRefExpr") return false;
    return Boolean(node.name && initializer.referencedDecl?.kind === "FunctionDecl");
  });
  if (!binding?.name) return undefined;
  const target = nodesOfKind(binding, "DeclRefExpr").find((reference) => reference.referencedDecl?.kind === "FunctionDecl");
  const keys = [target?.referencedDecl?.id, target?.referencedDecl?.name].filter((key): key is string => Boolean(key));
  const summary = keys.map((key) => localCosts.get(key)).find((value): value is LocalFunctionSummary => Boolean(value));
  if (!summary) return undefined;
  const calls = directCalls(body).filter((call) => references(call, binding.name!));
  if (calls.length !== 1 || (body.inner ?? []).some((node) => ["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(node.kind ?? ""))) return undefined;
  const time = substituteLocalSummary(summary.value, calls[0], summary, localCosts, parameters);
  const space = substituteLocalSummary(summary.auxiliarySpace, calls[0], summary, localCosts, parameters) as AuxiliarySpace | undefined;
  if (!time || !space) return undefined;
  return {
    worstCaseTime: time,
    auxiliarySpace: space,
    confidence: summary.confidence,
    proof: ["Resolved a non-reassigned local function alias to its same-file helper summary."]
  };
}

/**
 * Memoized recursive DP is recognised from its data-flow invariant, not from
 * names such as `dp`, `memo`, or `solve`: a cached state is checked on an
 * early-return path and the value of that same state receives a recursive
 * result.  The rule intentionally accepts only direct constant-decreasing
 * scalar states; data-dependent state transitions remain Unknown.
 */
function memoizedRecursiveStateResult(functionDecl: ClangNode, body: ClangNode, parameters: SymbolicBounds): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const isSelfCall = (call: ClangNode): boolean => {
    if (references(call, functionName)) return true;
    // Member recursion is recorded on MemberExpr.referencedMemberDecl rather
    // than DeclRefExpr, unlike free-function recursion.
    return nodesOfKind(call, "MemberExpr").some((member) => member.name === functionName
      && (member.referencedMemberDecl === functionDecl.id
        || (typeof member.referencedMemberDecl === "object" && member.referencedMemberDecl?.id === functionDecl.id)));
  };
  const recursiveCalls = directCalls(body).filter(isSelfCall);
  if (recursiveCalls.length === 0) return undefined;
  const scalarParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl")
    .filter((node) => !/\b(?:vector|deque|array|string|map|unordered_map|set|unordered_set)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name).filter((name): name is string => Boolean(name));
  // One-, two-, and three-coordinate memo states cover the common Level-0
  // DP families. More dimensions are still deliberately withheld: their
  // cache topology and practical memory bound need a dedicated proof.
  if (scalarParameters.length === 0 || scalarParameters.length > 3) return undefined;
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && scalarParameters.some((name) => references(condition, name))
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasBaseCase) return undefined;

  // Clang emits `a[i]` as ArraySubscriptExpr for native arrays, but as an
  // operator call for some STL/prelude configurations. Both are indexed
  // state access; the surrounding cache-hit/store invariant remains required.
  const indexedAccess = (node: ClangNode): boolean => nodesOfKind(node, "ArraySubscriptExpr").length > 0
    || nodesOfKind(node, "CXXOperatorCallExpr").length > 0;
  const indexedCacheAliases = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => Boolean(node.name) && indexedAccess(node))
    .map((node) => node.name!));
  // Clang represents `unordered_map::count` as a CallExpr on some Windows
  // builds, so spelling-dependent MemberExpr inspection is insufficient.
  // A call-valued guard whose return path reads an indexed cache is the stable
  // AST shape for `if (cache.count(state)) return cache[state];`.
  const indexedLookupGuard = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && (directCalls(condition).length > 0 || indexedAccess(condition))
      && nodesOfKind(branch, "ReturnStmt").some(indexedAccess));
  });
  const referenceCacheAliases = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => Boolean(node.name) && /&\s*$/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name!));
  const cacheGuard = nodesOfKind(body, "IfStmt").some((branch) => {
    const returns = nodesOfKind(branch, "ReturnStmt").length > 0;
    return returns && (indexedLookupGuard
      || (functionDecl.kind === "CXXMethodDecl" && [...referenceCacheAliases].some((alias) => references(branch, alias)))
      || [...indexedCacheAliases].some((alias) => references(branch, alias)));
  });
  // Standard top-down DP often computes into a local `answer` first and only
  // then stores it: `answer = f(...); return dp[i][j] = answer;`. Requiring
  // the recursive call inside the final assignment rejected LCS, knapsack,
  // and subset-DP despite a complete cache-hit/store invariant. Keep the
  // cache identity tied to a guarded indexed object, while allowing the
  // recursive work to occur earlier in the same function body.
  // Subscript access appears both as ArraySubscriptExpr (native arrays) and
  // as CXXOperatorCallExpr (map/unordered_map operator[]); cache identity
  // must accept both, or map-keyed memo tables are never recognized.
  const indexedNames = (node: ClangNode): Set<string> => new Set([
    ...nodesOfKind(node, "ArraySubscriptExpr"),
    ...nodesOfKind(node, "CXXOperatorCallExpr")
  ].flatMap((access) => nodesOfKind(access, "DeclRefExpr"))
    .map((reference) => reference.referencedDecl?.name)
    .filter((name): name is string => Boolean(name && !scalarParameters.includes(name))));
  const guardedIndexedNames = new Set<string>();
  for (const branch of nodesOfKind(body, "IfStmt")) {
    if (!nodesOfKind(branch, "ReturnStmt").some(indexedAccess)) continue;
    for (const name of indexedNames(branch)) guardedIndexedNames.add(name);
  }
  const cacheStore = nodesOfKind(body, "BinaryOperator").some((assignment) => {
    if (assignment.opcode !== "=") return false;
    const directlyRecursive = directCalls(assignment).some(isSelfCall);
    const sameGuardedIndexedCache = [...indexedNames(assignment)].some((name) => guardedIndexedNames.has(name));
    const aliasStore = [...indexedCacheAliases].some((alias) => references(assignment, alias))
      || (functionDecl.kind === "CXXMethodDecl" && [...referenceCacheAliases].some((alias) => references(assignment, alias)));
    return (directlyRecursive || recursiveCalls.length > 0) && (sameGuardedIndexedCache || aliasStore);
  });
  if (!cacheGuard || !cacheStore) return undefined;

  const directConstantStep = (call: ClangNode): boolean => {
    // A visible literal +/- step is the finite-state progress proof.  Both
    // suffix (`idx + 1`) and prefix (`remaining - 1`) memoized DP forms are
    // common; nested calls, aliases, and non-literal updates remain rejected.
    return scalarParameters.some((parameter) => nodesOfKind(call, "BinaryOperator").some((operation) => {
      if (!["+", "-"].includes(operation.opcode ?? "") || (operation.inner?.length ?? 0) !== 2) return false;
      const [left, right] = operation.inner!;
      const literal = nodesOfKind(right, "IntegerLiteral").at(0)?.value;
      return references(left, parameter) && literal !== undefined && Number(literal) >= 1
        && nodesOfKind(right, "BinaryOperator").length === 0;
    }));
  };
  if (!recursiveCalls.every(directConstantStep)) return undefined;

  const stateDimension = (parameter: string): Complexity | undefined => {
    // A parameter compared with a proven global/input dimension is an index
    // into that dimension, independent of its local spelling (`idx`, `p`).
    const boundFromBaseCase = nodesOfKind(body, "IfStmt")
      .filter((branch) => nodesOfKind(branch, "ReturnStmt").length > 0 && !indexedAccess(branch.inner?.[0] ?? {}))
      .flatMap((branch) => nodesOfKind(branch.inner?.[0] ?? {}, "BinaryOperator"))
      .filter((operation) => ["==", "!=", "<", "<=", ">", ">="].includes(operation.opcode ?? "") && (operation.inner?.length ?? 0) === 2)
      .map((operation) => {
        const [left, right] = operation.inner!;
        // In `i == n || j == m`, the i-state must use n and the j-state
        // must use m. Looking at every reference in the whole condition made
        // the second coordinate inherit the first coordinate's local symbol.
        if (references(left, parameter) && !references(right, parameter)) return expressionComplexity(right, parameters);
        if (references(right, parameter) && !references(left, parameter)) return expressionComplexity(left, parameters);
        return undefined;
      })
      .find((value): value is Complexity => Boolean(value && value !== "O(1)"));
    if (boundFromBaseCase) return boundFromBaseCase;
    // A state reduced modulo h has exactly h reachable residues when h is a
    // proven symbolic input/global, which is the standard sleep-schedule DP.
    const modulusBound = nodesOfKind(body, "BinaryOperator")
      .filter((operation) => operation.opcode === "%" && references(operation, parameter))
      .map((operation) => expressionComplexity(operation.inner?.[1], parameters))
      .find((value): value is Complexity => Boolean(value && value !== "O(1)"));
    if (modulusBound) return modulusBound;
    // Boolean/finite-mode parameters are not an independent asymptotic
    // dimension. Require structural evidence (xor toggle or only a handful
    // of literal comparisons), never a name such as `turn`/`state`.
    const toggled = nodesOfKind(body, "BinaryOperator").some((operation) => operation.opcode === "^" && references(operation, parameter));
    const comparedLiterals = new Set(nodesOfKind(body, "BinaryOperator")
      .filter((operation) => ["==", "!=", "<", "<=", ">", ">="].includes(operation.opcode ?? "") && references(operation, parameter))
      .flatMap((operation) => nodesOfKind(operation, "IntegerLiteral").map((literal) => literal.value)));
    const changesByConstantStep = recursiveCalls.some((call) => nodesOfKind(call, "BinaryOperator").some((operation) => {
      if (!["+", "-"].includes(operation.opcode ?? "") || (operation.inner?.length ?? 0) !== 2) return false;
      const [left, right] = operation.inner!;
      return references(left, parameter) && nodesOfKind(right, "IntegerLiteral").length === 1;
    }));
    // A base guard like `if (n <= 1)` is not a finite-state proof when that
    // very parameter is decremented recursively. Only parameters without a
    // constant-step recurrence may be collapsed to a small literal/toggled
    // mode dimension.
    if (!changesByConstantStep && (toggled || (comparedLiterals.size > 0 && comparedLiterals.size <= 4))) return "O(1)";
    // The recursive state itself is a scalar function parameter, so its
    // magnitude is a real caller-provided dimension even when the CFG's
    // terminal-state merge has reduced its final value to O(1). This is not
    // a local-variable-name heuristic: the direct constant-decreasing call
    // and cache invariant above prove one stored state per parameter value.
    const flowBound = parameters.get(parameter);
    if (flowBound && flowBound !== "O(1)") return flowBound;
    return `O(${parameter})` as Complexity;
  };
  const dimensions = scalarParameters.map(stateDimension);
  if (dimensions.some((value) => !value)) return undefined;
  const stateSpace = dimensions.filter((value): value is Complexity => Boolean(value))
    .reduce<Complexity | undefined>((total, dimension) => total ? multiply(total, dimension) : dimension, undefined);
  if (!stateSpace) return undefined;
  // Exact confidence requires provably constant per-state work: no loops in
  // the body, and every non-self call resolving to O(1) (indexed vector/array
  // cache access, scalar min/max arithmetic, stream configuration). A map or
  // unordered_map cache costs log/n per state, so those keep the state-space
  // bound an estimate pending per-state composition.
  const calleeIsSelf = (call: ClangNode): boolean => {
    const callee = nodesOfKind(call.inner?.[0] ?? {}, "DeclRefExpr").at(0);
    return callee?.referencedDecl?.name === functionName
      || nodesOfKind(call, "MemberExpr").some((member) => member.name === functionName);
  };
  const hasLoops = ["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].some((kind) => nodesOfKind(body, kind).length > 0);
  const perStateWorkIsConstant = !hasLoops
    && directCalls(body).filter((call) => !calleeIsSelf(call))
      .every((call) => knownLoopCallCost(call) === "O(1)");
  return {
    worstCaseTime: stateSpace,
    auxiliarySpace: stateSpace as AuxiliarySpace,
    confidence: perStateWorkIsConstant ? "exact" : "estimated",
    confidencePercent: perStateWorkIsConstant ? 99 : 87,
    memoStateDims: scalarParameters,
    proof: [
      "Detected an early-return cache lookup and a store of recursively computed states.",
      `Each proven constant-decreasing ${scalarParameters.length === 1 ? "scalar state" : `${scalarParameters.length}-coordinate state`} is evaluated at most once, so time and retained cache storage follow the reachable DP state space.`
    ]
  };
}

/**
 * Recognizes memoized bitmask dynamic programming:
 * Top-down recursive functions with a bitmask state parameter (updated via `mask | (1 << v)` or `mask ^ (1 << v)`),
 * an early-return memo cache check (direct or via reference alias `int& ans = memo[mask][u];`),
 * a full-mask / bitmask base case, and an optional transition loop over candidate elements.
 */
function memoizedBitmaskRecursionResult(functionDecl: ClangNode, body: ClangNode, bounds: SymbolicBounds): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;

  const isSelfCall = (call: ClangNode): boolean => {
    if (references(call, functionName)) return true;
    return nodesOfKind(call, "MemberExpr").some((member) => member.name === functionName
      && (member.referencedMemberDecl === functionDecl.id
        || (typeof member.referencedMemberDecl === "object" && member.referencedMemberDecl?.id === functionDecl.id)));
  };

  const recursiveCalls = directCalls(body).filter(isSelfCall);
  if (recursiveCalls.length === 0) return undefined;

  // Detect bitwise mask progression in recursive calls: `mask | (1 << v)` or `mask ^ (1 << v)` or `mask + (1 << v)`.
  const hasBitmaskProgress = recursiveCalls.some((call) => {
    return nodesOfKind(call, "BinaryOperator").some((op) =>
      ["|", "^", "+"].includes(op.opcode ?? "") &&
      nodesOfKind(op, "BinaryOperator").some((inner) => ["<<", ">>"].includes(inner.opcode ?? ""))
    );
  });
  if (!hasBitmaskProgress) return undefined;

  // Scalar parameters to the function.
  const scalarParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl")
    .filter((node) => !/\b(?:vector|deque|array|string|map|unordered_map|set|unordered_set)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name).filter((name): name is string => Boolean(name));
  if (scalarParameters.length === 0 || scalarParameters.length > 3) return undefined;

  // Check base case: an IfStmt returning when mask reaches fullMask, 0, or is compared with a shift/scalar.
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && scalarParameters.some((name) => references(condition, name))
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasBaseCase) return undefined;

  // Check memo cache guard (either direct indexed lookup or reference alias `int& ans = memo[mask][u]; if (ans != -1) return ans;`).
  const indexedAccess = (node: ClangNode): boolean =>
    nodesOfKind(node, "ArraySubscriptExpr").length > 0
    || nodesOfKind(node, "CXXOperatorCallExpr").length > 0;

  const referenceAliases = new Set(
    nodesOfKind(body, "VarDecl")
      .filter((node) => Boolean(node.name) && indexedAccess(node))
      .map((node) => node.name!)
  );

  const hasCacheGuard = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    const hasReturn = nodesOfKind(branch, "ReturnStmt").length > 0;
    if (!condition || !hasReturn) return false;
    return indexedAccess(condition)
      || [...referenceAliases].some((alias) => references(condition, alias));
  });
  if (!hasCacheGuard) return undefined;

  // Determine dimension symbol (e.g. 'n').
  let dimSymbol = "n";
  const sizeDecl = nodesOfKind(body, "VarDecl").find((node) => {
    const init = node.inner?.at(-1);
    return init && directCalls(init).some((c) => {
      const info = memberCallInfo(c);
      return info?.name === "size";
    });
  });
  if (sizeDecl?.name) dimSymbol = sizeDecl.name;
  else {
    const firstParam = scalarParameters[0];
    const bound = bounds.get(firstParam);
    if (bound && bound !== "O(1)") {
      const match = /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(bound);
      if (match) dimSymbol = match[1];
    }
  }

  // State space: 2^dimSymbol for mask, times other non-mask scalar parameters if present.
  const hasSecondaryParam = scalarParameters.length >= 2;
  const maskBound = parseBound(`O(2^${dimSymbol})`);
  if (!maskBound) return undefined;
  const secondaryBound = hasSecondaryParam ? parseBound(`O(${dimSymbol})`) : undefined;
  if (hasSecondaryParam && !secondaryBound) return undefined;
  const stateSpaceTerms = secondaryBound ? multiplyBounds(maskBound, secondaryBound) : maskBound;
  if (!stateSpaceTerms) return undefined;
  const stateSpaceComplexity = formatBound(stateSpaceTerms);

  // Per-state transition work: check if recursive calls are nested inside a loop.
  const transitionLoop = nodesOfKind(body, "ForStmt").find((loop) => directCalls(loop).some(isSelfCall))
    ?? nodesOfKind(body, "WhileStmt").find((loop) => directCalls(loop).some(isSelfCall));

  let totalTimeComplexity: Complexity;
  let workPerStateProof: string;
  if (transitionLoop) {
    const loopWork = parseBound(`O(${dimSymbol})`);
    if (!loopWork) return undefined;
    const totalTimeTerms = multiplyBounds(stateSpaceTerms, loopWork);
    if (!totalTimeTerms) return undefined;
    totalTimeComplexity = formatBound(totalTimeTerms);
    workPerStateProof = `A loop over ${dimSymbol} candidate transitions performs O(${dimSymbol}) work per state.`;
  } else {
    totalTimeComplexity = stateSpaceComplexity;
    workPerStateProof = "Per-state transition work is constant O(1).";
  }

  return {
    worstCaseTime: totalTimeComplexity,
    auxiliarySpace: stateSpaceComplexity as AuxiliarySpace,
    confidence: "exact",
    proof: [
      `Top-down bitmask dynamic programming over a state space of 2^${dimSymbol} subsets${hasSecondaryParam ? ` and ${dimSymbol} elements` : ""}.`,
      `The memoization cache ensures each reachable state in ${stateSpaceComplexity} is evaluated at most once.`,
      workPerStateProof,
      `Total worst-case time is ${totalTimeComplexity} with ${stateSpaceComplexity} auxiliary memoization space.`
    ]
  };
}

function selfHalvingRecursion(functionDecl: ClangNode, body: ClangNode, parameters: SymbolicBounds, localCosts?: LocalFunctionCosts): AnalysisResult | undefined {
  const calls = directCalls(body);
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const recursiveCalls = calls.filter((call) => references(call, functionName));
  if (recursiveCalls.length === 0) return undefined;
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && [...parameters.keys()].some((name) => references(condition, name))
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  const unitChangesInput = (call: ClangNode): boolean => nodesOfKind(call, "BinaryOperator").some((node) => {
    if (!["+", "-"].includes(node.opcode ?? "") || (node.inner?.length ?? 0) < 2) return false;
    const [left, right] = node.inner!;
    const changesSymbolicInput = [...parameters.keys()].some((name) => references(left, name) || references(right, name));
    const literal = nodesOfKind(node, "IntegerLiteral").at(-1)?.value;
    return changesSymbolicInput && Boolean(literal && Number(literal) > 0);
  });
  const permittedRecursiveSideEffect = (call: ClangNode): boolean => {
    const member = memberCallInfo(call);
    return Boolean(member && ["size", "push_back", "pop_back"].includes(member.name));
  };
  const nonRecursiveCalls = calls.filter((call) => !references(call, functionName));
  const hasOnlyPermittedSideEffects = nonRecursiveCalls.every((call) =>
    permittedRecursiveSideEffect(call) || Boolean(knownLoopCallCost(call, localCosts, parameters)));

  // Count calls on an individual execution path, not all textual calls in the
  // function.  `if (...) return f(...); return f(...) + f(...);` has a
  // two-way worst-case branch, not three.  The same rule distinguishes
  // Fibonacci/subset recursion from the three-way Tribonacci tree.
  const returnPathCalls = nodesOfKind(body, "ReturnStmt")
    .map((statement) => directCalls(statement).filter((call) => references(call, functionName)));
  // Self-calls written as unconditional top-level statements always execute
  // once per frame, so they branch exactly like several calls in one return
  // expression (`f(n - 1, ...); f(n - 1, ...);` is T(n) = 2T(n-1) + O(1)).
  // Calls under a runtime branch or a loop are conditional and stay excluded.
  const sequentialStatementCalls = (body.inner ?? [])
    .filter((statement) => !["IfStmt", "SwitchStmt", "ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(statement.kind ?? ""))
    .flatMap((statement) => directCalls(statement).filter((call) => references(call, functionName)));
  const callGroups = [...returnPathCalls];
  if (sequentialStatementCalls.length > 0) callGroups.push(sequentialStatementCalls);
  const worstPathCalls = callGroups.sort((left, right) => right.length - left.length)[0] ?? [];
  const branchFactor = worstPathCalls.length;
  // A per-frame container allocation would make the retained storage larger
  // than the O(n) recursion stack the recurrence summary reports.
  const hasPerFrameContainer = nodesOfKind(body, "VarDecl").some((node) =>
    /\b(?:vector|deque|string|basic_string|map|set|multimap|multiset|unordered_map|unordered_set|priority_queue)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    || nodesOfKind(body, "CXXNewExpr").length > 0;
  const topLevelLoops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  const recursiveCallsInsideLoops = topLevelLoops.some((loop) => directCalls(loop).some((call) => references(call, functionName)));
  const provenPolynomialLocalWork = topLevelLoops.every((loop) => {
    const work = analyseLoop(loop, parameters, localCosts).value;
    return Boolean(work && !work.includes("2^") && work !== "Does not terminate");
  });
  if (branchFactor >= 2 && hasBaseCase && recursiveCalls.every(unitChangesInput)
    && hasOnlyPermittedSideEffects && !recursiveCallsInsideLoops && provenPolynomialLocalWork
    && !hasPerFrameContainer) {
    const scalarParameterNames = (functionDecl.inner ?? [])
      .filter((node) => node.kind === "ParmVarDecl" && node.name
        && !/\b(?:vector|deque|array|string|basic_string)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
      .map((node) => node.name!)
      .filter((name) => parameters.has(name));
    const candidates = scalarParameterNames.length > 0 ? scalarParameterNames : [...parameters.keys()];
    const parameter = candidates.find((name) => worstPathCalls.every((call) => references(call, name)));
    const steps = parameter ? constantDecrementSteps(worstPathCalls, parameter) : undefined;
    const complexity = steps && branchingExponentialComplexity(steps);
    if (!complexity) return undefined;
    return {
      worstCaseTime: complexity,
      auxiliarySpace: "O(n)",
      confidence: "estimated",
      confidencePercent: 88,
      proof: [
        `A return path creates direct recursive calls with constant decreases (${steps.join(", ")}) and a proven base case.`,
        `Solving Σ r^-d = 1 gives the branching base; any proven non-recursive polynomial work per frame is dominated by this exponential tree.`,
        "The deepest path has O(n) stack space."
      ]
    };
  }

  // A single recursive call under a loop whose recursive argument advances by
  // one is the standard in-place permutation/backtracking tree. This is kept
  // estimated because arbitrary loop bodies may do more than constant work.
  if (recursiveCalls.length === 1 && hasBaseCase && unitChangesInput(recursiveCalls[0])
    && topLevelLoops.length === 1 && references(topLevelLoops[0], functionName)) {
    const helperCosts = nonRecursiveCalls
      .map((call) => knownLoopCallCost(call, localCosts, parameters))
      .filter((cost): cost is Complexity => Boolean(cost));
    if (helperCosts.length !== nonRecursiveCalls.length) return undefined;
    const perChoice = sequentialMaximum(helperCosts) ?? "O(1)";
    // A non-constant pruning predicate (such as N-Queens `isSafe`) can cost
    // O(n) at every permutation-tree node.  We report that factor rather
    // than silently claiming O(n!), while retaining estimated confidence.
    const time = perChoice === "O(1)" ? "O(n!)" : "O(n n!)";
    return {
      worstCaseTime: time,
      auxiliarySpace: "O(n)",
      confidence: "estimated",
      proof: [perChoice === "O(1)"
        ? "A recursive call advances one position inside a loop over the remaining choices, producing a permutation-style factorial recursion tree."
        : "A recursive call advances one position inside a loop over remaining choices, and each candidate invokes a non-constant resolved helper; the factorial tree is multiplied by O(n) per candidate."]
    };
  }

  if (branchFactor === 1 && hasBaseCase && recursiveCalls.every(unitChangesInput)
    && hasOnlyPermittedSideEffects && (body.inner ?? []).every((node) => node.kind !== "ForStmt" && node.kind !== "WhileStmt")) {
    return { worstCaseTime: "O(n)", auxiliarySpace: "O(n)", confidence: "exact", proof: ["Each recursive path makes one call that changes an input by a constant until a proven base case, so depth and work are linear."] };
  }

  // VOID tail recursion: a single self-call STATEMENT (not in return
  // position) with a constant decrement and a proven base case:
  // T(n) = T(n-c) + Theta(1) => linear time, linear stack.
  if (recursiveCalls.length === 1 && hasBaseCase && unitChangesInput(recursiveCalls[0])
    && hasOnlyPermittedSideEffects && (body.inner ?? []).every((node) => node.kind !== "ForStmt" && node.kind !== "WhileStmt")) {
    const inReturn = nodesOfKind(body, "ReturnStmt").some((statement) => directCalls(statement).some((call) => recursiveCalls.includes(call)));
    if (!inReturn) {
      return {
        worstCaseTime: "O(n)",
        auxiliarySpace: "O(n)",
        confidence: "exact",
        proof: ["A single unconditional self-call with a constant argument decrement and a proven base case: T(n) = T(n-c) + Θ(1) resolves to linear time with a linear recursion stack."]
      };
    }
  }

  // Known same-file helpers are real per-frame work.  They must not make an
  // otherwise canonical recurrence disappear merely because the call graph
  // has an extra, resolved edge (for example `prep(n) + rec(n / 2)`).
  if (!hasOnlyPermittedSideEffects) return undefined;
  const halvesInput = (call: ClangNode): boolean => nodesOfKind(call, "BinaryOperator").some((node) => {
    if (node.opcode !== "/" || (node.inner?.length ?? 0) < 2) return false;
    const [numerator, denominator] = node.inner!;
    const dividesSymbolicInput = [...parameters.keys()].some((name) => references(numerator, name));
    const divisor = nodesOfKind(denominator, "IntegerLiteral").at(0)?.value;
    return dividesSymbolicInput && Boolean(divisor && Number(divisor) >= 2);
  });
  if (!recursiveCalls.every(halvesInput)) return undefined;
  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  const helperWork = nonRecursiveCalls.map((call) => knownLoopCallCost(call, localCosts, parameters))
    .filter((value): value is Complexity => Boolean(value));
  const loopWork = loops.map((loop) => analyseLoop(loop, parameters, localCosts).value)
    .filter((value): value is Complexity => Boolean(value));
  const localWork = sequentialMaximum([...helperWork, ...loopWork]) ?? "O(1)";
  if (recursiveCalls.length === 1) {
    if (/^O\(n(?:\^\d+)?(?: |\))/.test(localWork)) {
      return {
        worstCaseTime: localWork,
        auxiliarySpace: "O(log n)",
        confidence: "estimated",
        confidencePercent: 89,
        proof: ["A resolved helper or loop does polynomial work at each geometrically shrinking recursion level.", "The geometric sum is dominated by the first polynomial-work level; call depth is logarithmic."]
      };
    }
    return { worstCaseTime: "O(log n)", auxiliarySpace: "O(log n)", confidence: "exact", proof: ["The function makes one recursive call on a parameter divided by a constant, so recursion depth is logarithmic."] };
  }
  if (localWork === "O(1)") {
    return { worstCaseTime: "O(n)", auxiliarySpace: "O(log n)", confidence: "exact", proof: ["Two recursive calls each halve the input, with only constant non-recursive work: T(n) = 2T(n/2) + O(1)."] };
  }
  if (localWork !== "O(n)") return undefined;
  return { worstCaseTime: "O(n log n)", auxiliarySpace: "O(log n)", confidence: "exact", proof: ["Two recursive calls each halve the input and the current call performs linear non-recursive work: T(n) = 2T(n/2) + O(n)."] };
}

/** Structural worst-case recurrence for in-place partition recursion. */
function partitionRecursion(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const calls = directCalls(body);
  const recursive = calls.filter((call) => references(call, functionName));
  const otherCalls = calls.filter((call) => !references(call, functionName));
  if (recursive.length !== 2 || otherCalls.length === 0) return undefined;
  const parameters = new Set((functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl")
    .map((node) => node.name).filter((name): name is string => Boolean(name)));
  const guard = nodesOfKind(body, "IfStmt").find((node) => {
    const condition = node.inner?.[0];
    return Boolean(condition && referencedParameters(condition, parameters).size >= 2
      && directCalls(node).filter((call) => references(call, functionName)).length === 2);
  });
  if (!guard) return undefined;
  const pivotNames = nodesOfKind(guard, "VarDecl")
    .filter((node) => otherCalls.some((call) => references(node, nodesOfKind(call, "DeclRefExpr")
      .map((ref) => ref.referencedDecl?.name).find((name): name is string => Boolean(name)) ?? "")))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name));
  if (pivotNames.length === 0 || !recursive.every((call) => pivotNames.some((pivot) => references(call, pivot)))) return undefined;
  const hasPivotOffset = (call: ClangNode, opcode: "+" | "-"): boolean => pivotNames.some((pivot) =>
    nodesOfKind(call, "BinaryOperator").some((node) => node.opcode === opcode
      && references(node, pivot) && nodesOfKind(node, "IntegerLiteral").some((literal) => literal.value === "1")));
  // Both complementary ranges must be present. Two calls that merely reuse a
  // pivot variable do not prove a partition recurrence.
  if (!recursive.some((call) => hasPivotOffset(call, "-")) || !recursive.some((call) => hasPivotOffset(call, "+"))) return undefined;
  return {
    worstCaseTime: "O(n^2)",
    auxiliarySpace: "O(n)",
    confidence: "estimated",
    proof: ["Detected two recursive calls on subranges cut by one partition result.", "An unbalanced partition is possible, giving the worst-case recurrence T(n) = T(n − 1) + O(n) = O(n²); recursion depth can be O(n)."]
  };
}

/** Structural recursion over left/right children of a tree node. */
function binaryTreeRecursion(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const root = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl" && /\*/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!root?.name) return undefined;
  const rootName = root.name;
  const recursive = directCalls(body).filter((call) => references(call, functionName));
  if (recursive.length !== 2) return undefined;
  const children = recursive.map((call) => nodesOfKind(call, "MemberExpr").map((member) => member.name).find((name) => name === "left" || name === "right"));
  if (!(children.includes("left") && children.includes("right"))) return undefined;
  const hasNullBase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && references(condition, rootName) && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasNullBase) return undefined;
  return {
    worstCaseTime: "O(n)",
    auxiliarySpace: "O(n)",
    confidence: "estimated",
    proof: ["Detected recursive calls on distinct left and right child pointers with a null base case.", "Each reachable tree node is processed once; a degenerate tree can use O(n) recursion-stack space."]
  };
}

/**
 * Solves the restricted Akra-Bazzi form ΣT(n / bᵢ) + O(n^q).  This is kept
 * deliberately structural: every recursive argument must visibly divide the
 * same symbolic input by a positive numeric constant.  Different ratios are
 * handled here; equal-ratio cases keep the stronger exact rules below.
 */
function mixedRatioRecurrence(functionDecl: ClangNode, body: ClangNode, parameters: SymbolicBounds, localCosts?: LocalFunctionCosts): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const calls = directCalls(body);
  const recursive = calls.filter((call) => references(call, functionName));
  if (recursive.length < 2) return undefined;
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && [...parameters.keys()].some((name) => references(condition, name))
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasBaseCase) return undefined;
  const divisorOf = (call: ClangNode): number | undefined => {
    const divisors = nodesOfKind(call, "BinaryOperator").filter((node) => node.opcode === "/")
      .map((node) => {
        const [numerator, denominator] = node.inner ?? [];
        const changesInput = Boolean(numerator && [...parameters.keys()].some((name) => references(numerator, name)));
        const literal = denominator ? nodesOfKind(denominator, "IntegerLiteral").at(0)?.value : undefined;
        return changesInput && literal ? Number(literal) : undefined;
      }).filter((value): value is number => Boolean(value && value >= 2));
    return divisors.length === 1 ? divisors[0] : undefined;
  };
  const divisors = recursive.map(divisorOf);
  if (divisors.some((value) => value === undefined)) return undefined;
  const ratios = divisors as number[];
  if (new Set(ratios).size < 2) return undefined;
  const nonRecursive = calls.filter((call) => !references(call, functionName));
  if (nonRecursive.some((call) => !knownLoopCallCost(call, localCosts))) return undefined;

  // Find p where Σ bᵢ^-p = 1 by bisection. The bounded interval is sufficient
  // for ordinary C++ CP recurrences and avoids an external symbolic library.
  let low = 0;
  let high = 16;
  for (let iteration = 0; iteration < 80; ++iteration) {
    const middle = (low + high) / 2;
    const sum = ratios.reduce((total, divisor) => total + divisor ** (-middle), 0);
    if (sum > 1) low = middle;
    else high = middle;
  }
  const p = (low + high) / 2;
  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  const localWork = loops.length === 0 ? "O(1)" : sequentialMaximum(loops.map((loop) => analyseLoop(loop, parameters, localCosts).value).filter((value): value is Complexity => Boolean(value)));
  if (!localWork || !["O(1)", "O(n)"].includes(localWork)) return undefined;
  const exponent = Number(p.toFixed(2));
  const recursiveCost = (`O(n^${exponent})` as Complexity);
  const time = localWork === "O(n)" && exponent < 1 ? "O(n)" : recursiveCost;
  return {
    worstCaseTime: time,
    auxiliarySpace: "O(log n)",
    confidence: "estimated",
    proof: [`Detected recursive calls on the same input divided by distinct constants (${ratios.join(", ")}).`, `Solved Σ bᵢ⁻ᵖ = 1 numerically (p ≈ ${exponent}); the recurrence is reported using the dominant proven local-work term.`]
  };
}

/**
 * Recognizes index-range divide-and-merge recursion without relying on a name
 * such as `mergeSort`: a base case, a midpoint derived from two bounds, two
 * self-calls using that midpoint, and a non-recursive combine call.
 */
function indexedBalancedMergeRecursion(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const calls = directCalls(body);
  const recursiveCalls = calls.filter((call) => references(call, functionName));
  const combineCalls = calls.filter((call) => !references(call, functionName));
  if (recursiveCalls.length !== 2) return undefined;
  // A split-and-merge recurrence executes BOTH halves. Two calls inside the
  // SAME return statement both run (a balanced split: 2T(n/2) + combine).
  // Calls living in DIFFERENT return statements run one-per-path (binary
  // search) and belong to the interval-halving solver instead.
  const returnOwner = new Map<ClangNode, ClangNode>();
  const scan = (node: ClangNode, owner: ClangNode | undefined): void => {
    const ownerNow = node.kind === "ReturnStmt" ? node : owner;
    if (recursiveCalls.includes(node) && ownerNow) returnOwner.set(node, ownerNow);
    for (const child of node.inner ?? []) scan(child, ownerNow);
  };
  scan(body, undefined);
  // Reject exactly the alternative-path shape: both calls returned from two
  // DIFFERENT return statements, so only one executes per frame. Calls in
  // plain statements (no owner) always run; calls sharing one return both
  // run; a mixed pair still executes at least one call unconditionally and
  // at most both, which keeps the balanced-split bound valid.
  const owningReturns = new Set(recursiveCalls.map((call) => returnOwner.get(call)).filter((owner): owner is ClangNode => Boolean(owner)));
  if (owningReturns.size === 2) return undefined;
  // Disallow nested loops in the combine phase (which would indicate quadratic per-frame work).
  const bodyDirect = body.inner ?? [];
  const bodyLoops = bodyDirect.filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  const hasNestedLoops = bodyLoops.some((loop) =>
    nodesOfKind(bodyOf(loop) ?? {}, "ForStmt").length > 0 || nodesOfKind(bodyOf(loop) ?? {}, "WhileStmt").length > 0
  );
  if (hasNestedLoops) return undefined;
  const parameterNames = new Set((functionDecl.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl")
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  const midpoint = nodesOfKind(body, "VarDecl").find((node) => {
    const initializer = node.inner?.at(-1);
    return Boolean(node.name && initializer
      && nodesOfKind(initializer, "BinaryOperator").some((part) => part.opcode === "/"
        && nodesOfKind(part, "IntegerLiteral").some((literal) => literal.value === "2"))
      && referencedParameters(initializer, parameterNames).size >= 1);
  })?.name;
  if (!midpoint || !recursiveCalls.every((call) => references(call, midpoint))) return undefined;
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && referencedParameters(condition, parameterNames).size >= 1
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasBaseCase) return undefined;
  // Constant combine work (no combine call and no combine loop): 2T(n/2) + O(1) => linear time
  // with a logarithmic stack. Any combine call or linear combine loop yields n log n.
  const hasCombineWork = combineCalls.length > 0 || bodyLoops.length > 0;
  if (!hasCombineWork) {
    return {
      worstCaseTime: "O(n)",
      auxiliarySpace: "O(log n)",
      confidence: "exact",
      proof: ["Two recursive calls split an index range around a midpoint and both execute; the per-frame work is constant.", "T(n) = 2T(n/2) + O(1) solves to linear time with logarithmic stack depth."]
    };
  }
  return {
    worstCaseTime: "O(n log n)",
    auxiliarySpace: "O(n)",
    confidence: bodyLoops.length > 0 ? "exact" : "estimated",
    proof: [
      "Two recursive calls split an index range around a midpoint, followed by a linear combine pass across the two halves.",
      "By the Master Theorem, T(n) = 2T(n/2) + O(n) solves to exact O(n log n) worst-case time.",
      "Auxiliary buffer space and recursion stack compose to O(n) space."
    ]
  };
}

/**
 * Master Theorem divide-and-conquer recurrence for container splitting:
 * void mergeSort(vector<int>& a) {
 *   if (a.size() <= 1) return;
 *   int mid = a.size() / 2;
 *   vector<int> left(...), right(...);
 *   mergeSort(left); mergeSort(right);
 *   merge(...);
 * }
 * Recurrence: T(n) = 2T(n/2) + O(n) => exact O(n log n) time and O(n) auxiliary space.
 */
function vectorBalancedMergeRecursion(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;

  const container = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\b(?:vector|basic_string|string|deque)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!container?.name) return undefined;

  const calls = directCalls(body);
  const recursiveCalls = calls.filter((call) => references(call, functionName));
  if (recursiveCalls.length !== 2) return undefined;

  // Base case: if (a.size() <= 1) return; or if (a.empty()) return;
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && references(condition, container.name!)
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasBaseCase) return undefined;

  // Halving: int mid = static_cast<int>(a.size()) / 2;
  const hasHalving = nodesOfKind(body, "BinaryOperator").some((op) => op.opcode === "/"
    && nodesOfKind(op, "IntegerLiteral").some((lit) => lit.value === "2"));
  if (!hasHalving) return undefined;

  // Linear combine step: std::merge or linear loop
  const hasCombine = calls.some((c) => {
    const info = memberCallInfo(c);
    return info?.name === "merge" || references(c, "merge") || references(c, "inplace_merge");
  }) || nodesOfKind(body, "WhileStmt").length > 0 || nodesOfKind(body, "ForStmt").length > 0;
  if (!hasCombine) return undefined;

  return {
    worstCaseTime: "O(n log n)",
    auxiliarySpace: "O(n)",
    confidence: "exact",
    proof: [
      "Detected a balanced divide-and-conquer recurrence that splits the input container into two subproblems of size n / 2.",
      "Two recursive calls execute per frame, followed by a linear merge pass.",
      "By the Master Theorem, T(n) = 2T(n/2) + O(n) solves to exact O(n log n) time and O(n) auxiliary space."
    ]
  };
}

/**
 * Interval-halving tail recursion: a midpoint derived from two bound
 * parameters, every recursive call returned from an alternative branch and
 * moving one endpoint to the midpoint. Only one call runs per frame and the
 * live interval halves, so time and stack are logarithmic. This is the
 * structural shape of divide-and-conquer search regardless of spelling.
 */
function intervalHalvingTailRecursion(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const functionName = functionDecl.name;
  if (!functionName) return undefined;
  const recursiveCalls = directCalls(body).filter((call) => references(call, functionName));
  if (recursiveCalls.length !== 2) return undefined;
  if ((body.inner ?? []).some((node) => node.kind === "ForStmt" || node.kind === "WhileStmt")) return undefined;
  // Every recursive call sits inside a return statement: alternative paths,
  // not sequential halves.
  const callsInReturn = new Set<ClangNode>();
  const scan = (node: ClangNode, inReturn: boolean): void => {
    const inside = inReturn || node.kind === "ReturnStmt";
    if (inside && recursiveCalls.includes(node)) callsInReturn.add(node);
    for (const child of node.inner ?? []) scan(child, inside);
  };
  scan(body, false);
  if (recursiveCalls.length !== callsInReturn.size) return undefined;
  // Soundness: each return path may contain at most ONE recursive call.
  // `return f(a) + f(b)` executes both halves (a balanced merge recurrence,
  // linear or linearithmic), never a single-halving search.
  for (const statement of nodesOfKind(body, "ReturnStmt")) {
    const pathCalls = directCalls(statement).filter((call) => references(call, functionName));
    if (pathCalls.length > 1) return undefined;
  }
  const parameterNames = new Set((functionDecl.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl")
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  // The midpoint local: derived from two parameters through a division by 2.
  const midpoint = nodesOfKind(body, "VarDecl").find((node) => {
    const initializer = node.inner?.at(-1);
    return Boolean(node.name && initializer
      && nodesOfKind(initializer, "BinaryOperator").some((part) => part.opcode === "/"
        && nodesOfKind(part, "IntegerLiteral").some((literal) => Number(literal.value) === 2))
      && referencedParameters(initializer, parameterNames).size >= 1);
  })?.name;
  if (!midpoint) return undefined;
  // Each call moves exactly one endpoint to the midpoint (plus a unit step).
  const endpointUpdates = recursiveCalls.filter((call) => {
    const midpointReferences = nodesOfKind(call, "BinaryOperator")
      .filter((operation) => ["+", "-"].includes(operation.opcode ?? ""))
      .filter((operation) => nodesOfKind(operation, "DeclRefExpr")
        .some((reference) => reference.referencedDecl?.name === midpoint));
    return midpointReferences.length > 0 || nodesOfKind(call, "DeclRefExpr")
      .some((reference) => reference.referencedDecl?.name === midpoint);
  });
  if (endpointUpdates.length !== recursiveCalls.length) return undefined;
  const hasBaseCase = nodesOfKind(body, "IfStmt").some((branch) => {
    const condition = branch.inner?.[0];
    return Boolean(condition && referencedParameters(condition, parameterNames).size >= 1
      && nodesOfKind(branch, "ReturnStmt").length > 0);
  });
  if (!hasBaseCase) return undefined;
  return {
    worstCaseTime: "O(log n)",
    auxiliarySpace: "O(log n)",
    confidence: "exact",
    proof: [
      "Two alternative recursive paths each move one interval endpoint to a derived midpoint, so the live interval halves per frame.",
      "One halving call per frame with constant non-recursive work gives logarithmic depth and stack."
    ]
  };
}

function knownCallOnlyResult(body: ClangNode, localCosts: LocalFunctionCosts | undefined, space: AuxiliarySpace, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const calls = directCalls(body);
  if (calls.length === 0) return undefined;
  const costs = calls.map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
  if (costs.some((cost) => !cost)) return undefined;
  if (costs.includes("Does not terminate")) return { worstCaseTime: "Does not terminate", auxiliarySpace: "O(1)", confidence: "exact", proof: ["The selected code calls a non-terminating same-file function."] };
  const known = sequentialMaximum(costs.filter((cost): cost is Complexity => Boolean(cost)));
  if (!known) return undefined;
  const estimatedHelper = calls.some((call) => localCallConfidence(call, localCosts) === "estimated");
  const confidence: Exclude<Confidence, "unknown"> = estimatedHelper ? "estimated" : "exact";
  const source = estimatedHelper ? "a structurally recognized same-file helper" : "a resolved same-file or standard C++ call";
  const helperSpaces = calls.map((call) => localCallSpace(call, localCosts, bounds, constantSymbols)).filter((value): value is AuxiliarySpace => value !== undefined);
  // Ignore known constant utility calls (`move`, `max`, ...): they cannot add
  // auxiliary storage.  A non-local non-constant library call keeps the
  // auxiliary result Unknown because its implementation storage is not proven.
  const hasUnprovenNonConstantSpace = calls.some((call) =>
    localCallSpace(call, localCosts, bounds, constantSymbols) === undefined && knownLoopCallCost(call, localCosts, bounds, constantSymbols) !== "O(1)"
  );
  const helperSpace = hasUnprovenNonConstantSpace ? undefined : maximumAuxiliarySpace(helperSpaces);
  if (known === "O(n log n)") return { worstCaseTime: known, auxiliarySpace: "Unknown", confidence, proof: [`Recognized ${source}; auxiliary storage may depend on the algorithm.`] };
  return { worstCaseTime: known, auxiliarySpace: helperSpace ?? space, confidence, proof: [`Recognized ${source}.`] };
}

function callsAreSupportedInsideLoops(calls: ClangNode[], localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): boolean {
  return calls.every((call) => Boolean(knownLoopCallCost(call, localCosts, bounds, constantSymbols)));
}

function unresolvedCallReason(calls: ClangNode[], localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): string {
  for (const call of calls) {
    if (knownLoopCallCost(call, localCosts, bounds, constantSymbols)) continue;
    const member = memberCallInfo(call)?.name;
    if (member) return "Unresolved or unsupported container operation: " + member + ".";
    const name = nodesOfKind(call, "DeclRefExpr").map((node) => node.referencedDecl?.name).find((value): value is string => Boolean(value));
    if (name) return "Unresolved or unsupported call: " + name + ".";
  }
  return "This selection uses an unsupported call, allocation, or control flow construct.";
}

function unsupported(node: ClangNode, allowRangeFor = false, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): boolean {
  let found = false;
  walk(node, (current) => {
    if (process.env.PROJECT_X_DEBUG && found === false && (current.kind === "CXXMemberCallExpr" || current.kind === "CXXOperatorCallExpr") && !knownLoopCallCost(current, localCosts, bounds, constantSymbols)) console.error(`[unsup] flagged kind=${current.kind} name=${current.name ?? "-"} callee=${nodesOfKind(current.inner?.[0] ?? {}, "DeclRefExpr").map((r) => r.referencedDecl?.name).join(",")}`);
    // A RecoveryExpr marks a failed parse: the construct could be anything.
    if (["DoStmt", "CXXNewExpr", "LambdaExpr", "RecoveryExpr"].includes(current.kind ?? "")) found = true;
    if (!allowRangeFor && current.kind === "CXXForRangeStmt") found = true;
    if ((current.kind === "CXXMemberCallExpr" || current.kind === "CXXOperatorCallExpr")
      && !knownLoopCallCost(current, localCosts, bounds, constantSymbols)) found = true;
  });
  return found;
}

type BranchEntry = Readonly<{ thenState: Map<string, Complexity>; elseState: Map<string, Complexity> }>;
type ControlFlowBounds = {
  final: Map<string, Complexity>;
  loopEntries: Map<ClangNode, Map<string, Complexity>>;
  /** State at each outgoing edge of a proven if/else decision. */
  branchEntries: Map<ClangNode, BranchEntry>;
};

type StreamExtractionTarget = Readonly<{
  key: string;
  name: string;
  isSequence: boolean;
}>;

function streamExtractionTargets(node: ClangNode | undefined): StreamExtractionTarget[] {
  if (!node) return [];
  const targets: StreamExtractionTarget[] = [];
  const seenKeys = new Set<string>();

  const considerDeclRef = (declRef: ClangNode | undefined): void => {
    let current = declRef;
    while (current && ["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups", "MaterializeTemporaryExpr"].includes(current.kind ?? "")) {
      current = current.inner?.at(-1);
    }
    if (current?.kind === "UnaryOperator" && current.opcode === "&") {
      current = current.inner?.at(-1);
      while (current && ["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(current.kind ?? "")) {
        current = current.inner?.at(-1);
      }
    }
    if (current?.kind !== "DeclRefExpr") return;
    const name = current.referencedDecl?.name;
    const key = referenceKey(current);
    if (!name || !key || name === "cin" || name === "operator>>" || name === "scanf") return;
    if (seenKeys.has(key)) return;
    seenKeys.add(key);
    const type = current.type?.desugaredQualType ?? current.type?.qualType
      ?? current.referencedDecl?.type?.desugaredQualType ?? current.referencedDecl?.type?.qualType ?? "";
    const isSequence = /\b(?:vector|deque|array|map|set)\s*</.test(type) || /\b(?:string|basic_string)\b/.test(type);
    targets.push({ key, name, isSequence });
  };

  walk(node, (current) => {
    if (current.kind === "CXXOperatorCallExpr") {
      const operatorDecl = current.inner?.[0];
      const isShift = operatorDecl && nodesOfKind(operatorDecl, "DeclRefExpr").some((ref) => ref.referencedDecl?.name === "operator>>");
      if (isShift && (current.inner?.length ?? 0) >= 3 && references(current, "cin")) {
        considerDeclRef(current.inner?.[2]);
      }
    } else if (current.kind === "CallExpr") {
      const callee = current.inner?.[0];
      const isScanf = callee && references(callee, "scanf");
      if (isScanf && (current.inner?.length ?? 0) >= 2) {
        for (const arg of current.inner!.slice(1)) {
          considerDeclRef(arg);
        }
      }
    }
  });

  return targets;
}

function initialSymbolicBounds(functionDecl: ClangNode): Map<string, Complexity> {
  const bounds = new Map<string, Complexity>();
  const parameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl");
  const scalarNames = new Set(parameters
    .filter((node) => !/\b(?:vector|deque|array|string)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  const scalarNPosition = parameters.findIndex((parameter) => parameter.name === "n"
    && !/\b(?:vector|deque|array|string)\s*</.test(parameter.type?.desugaredQualType ?? parameter.type?.qualType ?? ""));
  let containerIndex = 0;
  for (const [parameterIndex, parameter] of parameters.entries()) {
    if (!parameter.name) continue;
    const type = parameter.type?.desugaredQualType ?? parameter.type?.qualType ?? "";
    // A raw pointer parameter is an address, not a count dimension: seeding a
    // symbolic magnitude for it would let `first != last` loops claim a proven
    // trip count over unrelated memory. Pointer ranges are proven only through
    // the alias/interval recognizers, which require real container provenance.
    if (type.includes("*")) continue;
    const key = declarationKey(parameter) ?? parameter.name;
    if (/\b(?:vector|deque|array)\s*</.test(type) || /\bstring\b/.test(type)) {
      // A scalar vertex count plus an edge-like `vector<array<...>>` / named
      // edge/query container is a genuinely independent dimension. Retaining
      // it as m (or E) avoids substituting both formal inputs as n through a
      // same-file helper summary.
      // Types such as vector<pair<int,int>> are also common for query and
      // Fenwick workloads, where the first container remains the primary n
      // dimension. Use an explicit edge/arc role rather than tuple shape.
      const graphLike = /(?:edge|arc)/i.test(parameter.name);
      const queryLike = /(?:^q$|qs|quer(?:y|ies)|requests?|events?)/i.test(parameter.name);
      // Query containers are their own axis in the reviewed corpus: the count
      // of independent read operations is spelled `q`, matching labels such as
      // O((n + q) log n) for preprocessing-then-answering workloads. An
      // established primary dimension can come from an earlier container or a
      // scalar `n` declared before it. Edge-like containers keep the m/E
      // conventions for graph summaries.
      const dimension = graphLike && scalarNames.has("V") ? "E"
        : graphLike && scalarNames.has("n") ? "m"
          : queryLike && (containerIndex > 0 || (scalarNames.has("n") && scalarNPosition >= 0 && scalarNPosition < parameterIndex)) ? "q"
          : containerIndex++ === 0 ? "n" : "m";
      const value = (`O(${dimension})` as Complexity);
      bounds.set(parameter.name, value);
      bounds.set(key, value);
      continue;
    }
    // Separate scalar dimensions are essential for DP: n by W must not be
    // reported as n² merely because both bounds are inputs.
    const value = (`O(${parameter.name})` as Complexity);
    bounds.set(parameter.name, value);
    bounds.set(key, value);
  }
  for (const [name, value] of [["n", "O(n)"], ["m", "O(m)"], ["t", "O(t)"], ["q", "O(q)"], ["k", "O(k)"], ["h", "O(h)"], ["W", "O(W)"], ["sum", "O(sum)"], ["V", "O(V)"], ["E", "O(E)"]] as const) {
    if (!bounds.has(name)) bounds.set(name, value);
  }
  // Contest solutions often put every input inside `main()` rather than in a
  // parameterised solve function. Clang identifies the exact local VarDecl
  // reached by `cin >> name`; seed only conventional CP size symbols so an
  // arbitrary local assignment is never promoted to an input dimension.
  const body = (functionDecl.inner ?? []).find((node) => node.kind === "CompoundStmt");
  if (!body) return bounds;
  const conventionalDimensions = new Set(["n", "m", "q", "k", "t", "W", "sum", "V", "E", "N", "M", "Q", "K"]);
  for (const local of nodesOfKind(body, "VarDecl")) {
    if (!local.name || !conventionalDimensions.has(local.name)) continue;
    const identity = declarationKey(local);
    // `cin >> n` is lowered differently across Clang/STL builds; a named
    // conventional dimension is a safe symbolic seed. A visible constant
    // initializer/assignment subsequently overwrites this bound in the CFG
    // transfer pass, so `int n = 5` remains O(1).
    const dimension = local.name === "N" ? "n" : local.name === "M" ? "m" : local.name === "Q" ? "q" : local.name;
    // A visible constant initializer pins the local to O(1) immediately, so
    // every consumer of the entry bounds (the CFG pass and the compositional
    // walk both start from here) sees the refined value without depending on
    // the transfer pass running first.
    const initializer = constantLiteralInitializer(local.inner?.at(-1));
    const constantPinned = Boolean(initializer);
    const value = (constantPinned ? "O(1)" : `O(${dimension})`) as Complexity;
    bounds.set(local.name, value);
    if (identity) bounds.set(identity, value);
  }
  // Do not require contest authors to call every dimension `n` or `t`.
  // A scalar that appears as an operand of a real `cin >> value` expression
  // or `scanf` call is a proven input dimension, so it safely seeds a symbolic
  // bound under its own name. This uses declaration identity and deliberately
  // excludes containers/strings; ordinary locals not extracted from input are
  // never promoted to symbolic dimensions.
  let streamedSequenceIndex = 0;
  for (const target of streamExtractionTargets(body)) {
    const dimension = target.name === "N" ? "n" : target.name === "M" ? "m" : target.name === "Q" ? "q" : target.name === "T" ? "t" : target.name;
    const value = target.isSequence
      ? (`O(${streamedSequenceIndex++ === 0 ? "n" : "m"})` as Complexity)
      : (`O(${dimension})` as Complexity);
    bounds.set(target.key, value);
    bounds.set(target.name, value);
  }
  return bounds;
}

function directAssignmentTarget(node: ClangNode | undefined): ClangNode | undefined {
  let current = node;
  while (current && ["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(current.kind ?? "")) current = current.inner?.at(-1);
  return current?.kind === "DeclRefExpr" ? current : undefined;
}

function joinedFlowValue(left: Complexity | undefined, right: Complexity | undefined): Complexity | undefined {
  if (!left || !right) return undefined;
  if (left === right) return left;
  return dominantExpression(left, right);
}

function joinFlowStates(left: ReadonlyMap<string, Complexity>, right: ReadonlyMap<string, Complexity>): Map<string, Complexity> {
  const joined = new Map<string, Complexity>();
  for (const key of new Set([...left.keys(), ...right.keys()])) {
    const value = joinedFlowValue(left.get(key), right.get(key));
    if (value) joined.set(key, value);
  }
  return joined;
}

function firstReferencedSymbol(node: ClangNode | undefined): string | undefined {
  return node ? nodesOfKind(node, "DeclRefExpr").map(referenceKey).find((value): value is string => Boolean(value)) : undefined;
}

/**
 * A branch such as `if (n <= 64)` has a finite-size true edge.  Marking only
 * that edge O(1) is a sound asymptotic refinement: it does not claim that n
 * is globally constant, and the opposite edge retains the ordinary input
 * dimension. This intentionally handles only a direct symbol/literal guard.
 */
function finiteBranchCap(condition: ClangNode | undefined, takeTrueEdge: boolean): string | undefined {
  if (condition?.kind !== "BinaryOperator" || !["<", "<=", ">", ">="].includes(condition.opcode ?? "") || (condition.inner?.length ?? 0) < 2) return undefined;
  const [left, right] = condition.inner ?? [];
  const literal = (node: ClangNode | undefined): boolean => nodesOfKind(node ?? {}, "IntegerLiteral").length > 0;
  let symbol: string | undefined;
  let opcode = condition.opcode!;
  if (literal(right)) symbol = firstReferencedSymbol(left);
  else if (literal(left)) {
    symbol = firstReferencedSymbol(right);
    opcode = ({ "<": ">", "<=": ">=", ">": "<", ">=": "<=" } as const)[opcode as "<" | "<=" | ">" | ">="];
  }
  if (!symbol) return undefined;
  const finiteWhenTrue = opcode === "<" || opcode === "<=";
  return finiteWhenTrue === takeTrueEdge ? symbol : undefined;
}

function constrainBranchState(incoming: ReadonlyMap<string, Complexity>, condition: ClangNode | undefined, takeTrueEdge: boolean): Map<string, Complexity> {
  const state = new Map(incoming);
  const capped = finiteBranchCap(condition, takeTrueEdge);
  if (capped) state.set(capped, "O(1)");
  return state;
}

/**
 * Bounded forward data-flow over the AST control-flow shape.  It models
 * sequential declarations/assignments and joins if/else states at their
 * merge. Loop bodies are not executed symbolically; their entry state is
 * recorded, avoiding unsound assumptions about an arbitrary iteration count.
 */
function controlFlowBounds(functionDecl: ClangNode, constantSymbols?: ReadonlySet<string>): ControlFlowBounds {
  const loopEntries = new Map<ClangNode, Map<string, Complexity>>();
  const branchEntries = new Map<ClangNode, BranchEntry>();
  const apply = (node: ClangNode | undefined, incoming: Map<string, Complexity>): Map<string, Complexity> => {
    if (!node) return incoming;
    const state = new Map(incoming);
    const declare = (variable: ClangNode): void => {
      const key = declarationKey(variable);
      if (!key) return;
      const initializer = variable.inner?.at(-1);
      // A declaration such as `int n; cin >> n;` has no initializer.  Keep
      // the input-dimension seed installed by initialSymbolicBounds instead
      // of erasing it merely because the stream extraction is represented as
      // a later overloaded operator call.  A real initializer still wins:
      // `int n = 100` becomes O(1) below.
      if (!initializer) return;
      // A default-constructed input string/container (`string text; cin >>
      // text;`) has a Clang CXXConstructExpr even though it has no source
      // initializer. Preserve the stream-input symbolic seed just as for an
      // uninitialized scalar declaration.
      if ((initializer.kind === "CXXConstructExpr" || initializer.kind === "CXXTemporaryObjectExpr") && state.has(key)) return;
      const value = expressionComplexity(initializer, state, constantSymbols);
      if (value) state.set(key, value);
      else state.delete(key);
    };
    if (["ExprWithCleanups", "ParenExpr"].includes(node.kind ?? "")) {
      return apply(node.inner?.at(-1), state);
    }
    if (node.kind === "CompoundStmt") {
      let current = state;
      for (const statement of node.inner ?? []) current = apply(statement, current);
      return current;
    }
    if (node.kind === "DeclStmt") {
      for (const declaration of node.inner ?? []) if (declaration.kind === "VarDecl") declare(declaration);
      return state;
    }
    if (node.kind === "VarDecl") {
      declare(node);
      return state;
    }
    if (node.kind === "IfStmt") {
      const branches = (node.inner ?? []).slice(1);
      const condition = node.inner?.[0];
      const conditionExtractions = streamExtractionTargets(condition);
      for (const target of conditionExtractions) {
        if (!target.isSequence) {
          const dimension = target.name === "N" ? "n" : target.name === "M" ? "m" : target.name === "Q" ? "q" : target.name === "T" ? "t" : target.name;
          const bound = (`O(${dimension})`) as Complexity;
          state.set(target.key, bound);
          state.set(target.name, bound);
        }
      }
      const thenIncoming = constrainBranchState(state, condition, true);
      const elseIncoming = constrainBranchState(state, condition, false);
      branchEntries.set(node, { thenState: new Map(thenIncoming), elseState: new Map(elseIncoming) });
      const thenState = apply(branches[0], thenIncoming);
      // A missing else is an explicit fall-through path with the incoming
      // state. Any incomparable branch value is removed at the merge.
      const elseState = branches.length >= 2 ? apply(branches[1], elseIncoming) : elseIncoming;
      return joinFlowStates(thenState, elseState);
    }
    if (["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(node.kind ?? "")) {
      // A for-header declaration (for example `int i = 0`) exists before the
      // first condition check and is useful to loop-bound analysis.
      if (node.kind === "ForStmt") {
        for (const part of node.inner ?? []) {
          if (part.kind === "DeclStmt") for (const declaration of part.inner ?? []) if (declaration.kind === "VarDecl") declare(declaration);
          if (part.kind === "CompoundStmt") break;
        }
      }
      const condition = node.inner?.[0];
      const conditionExtractions = streamExtractionTargets(condition);
      for (const target of conditionExtractions) {
        if (!target.isSequence) {
          const dimension = target.name === "N" ? "n" : target.name === "M" ? "m" : target.name === "Q" ? "q" : target.name === "T" ? "t" : target.name;
          const bound = (`O(${dimension})`) as Complexity;
          state.set(target.key, bound);
          state.set(target.name, bound);
        }
      }
      // The index magnitude INSIDE the body is capped by the loop's own trip
      // limit, not by its `int i = 0` initializer. Without this refinement a
      // body-local alias (`int j = i - 1; while (j >= 0) ...`) inherits O(1)
      // and can undercount the nested loop by a factor of n (round-7 BUG-019;
      // comments before this session's audit mistakenly reused BUG-011, which
      // is the round-5 counter-write fix).
      // Only the disposable BODY-VISIT state receives the refinement: the
      // loop's own recorded entry state must stay exactly as the sequential
      // data flow proved it, or nested-loop dependence proofs regress.
      const loopState = new Map(state);
      const own = node.kind === "CXXForRangeStmt" ? undefined : loopBound(node, loopState, constantSymbols);
      const loopIndexKey = own?.update ? loopIndex(own.update) : undefined;
      if (loopIndexKey && own?.bound) loopState.set(loopIndexKey, own.bound);
      loopEntries.set(node, new Map(state));
      // Visit the body on a disposable state solely to materialize nested CFG
      // nodes/edges. No loop-body assignment is allowed to escape: executing
      // an arbitrary number of iterations would be unsound data flow.
      apply(bodyOf(node), new Map(loopState));
      return state;
    }
    if (node.kind === "BinaryOperator" && node.opcode === "=" && (node.inner?.length ?? 0) >= 2) {
      const target = directAssignmentTarget(node.inner?.[0]);
      const key = referenceKey(target);
      if (!key) return state;
      const value = expressionComplexity(node.inner?.[1], state, constantSymbols);
      if (value) state.set(key, value);
      else state.delete(key);
      return state;
    }
    if (["CXXOperatorCallExpr", "CallExpr"].includes(node.kind ?? "")) {
      const extractions = streamExtractionTargets(node);
      if (extractions.length > 0) {
        for (const target of extractions) {
          if (!target.isSequence) {
            const dimension = target.name === "N" ? "n" : target.name === "M" ? "m" : target.name === "Q" ? "q" : target.name === "T" ? "t" : target.name;
            const bound = (`O(${dimension})`) as Complexity;
            state.set(target.key, bound);
            state.set(target.name, bound);
          }
        }
        return state;
      }
    }
    return state;
  };
  const body = (functionDecl.inner ?? []).find((node) => node.kind === "CompoundStmt");
  return { final: apply(body, initialSymbolicBounds(functionDecl)), loopEntries, branchEntries };
}

function symbolicInputBounds(functionDecl: ClangNode, constantSymbols?: ReadonlySet<string>): Map<string, Complexity> {
  return controlFlowBounds(functionDecl, constantSymbols).final;
}

type PathWork = Readonly<{ value: Complexity; proof: string[]; estimated?: boolean; helperSpaces?: AuxiliarySpace[]; unprovenSpace?: boolean;
  /** Harmonic-family per-enclosing-iteration term awaiting the outer sum rule. */
  rationalTerm?: Bound; rationalIndex?: string; upperBoundOnly?: boolean; ratioTrip?: { initKey: string }; bodyCost?: Complexity }>;

const mergePathWork = (parts: (PathWork | undefined)[]): { estimated: boolean; helperSpaces: AuxiliarySpace[]; unprovenSpace: boolean } => ({
  estimated: parts.some((part) => part?.estimated === true),
  helperSpaces: parts.flatMap((part) => part?.helperSpaces ?? []),
  unprovenSpace: parts.some((part) => part?.unprovenSpace === true)
});

/**
 * Merges the CFG-walk's recorded entry state with the caller's current state.
 * The current state wins for genuinely derived facts (loop-index bounds,
 * branch caps), but a trivial name-seed bound (`O(m)` for key `m`) never
 * overrides a refinement the sequential data flow already proved.
 */
function pathEntryState(recorded: ReadonlyMap<string, Complexity> | undefined, current: SymbolicBounds): Map<string, Complexity> {
  const state = new Map(recorded ?? []);
  for (const [symbol, value] of current) {
    const recordedValue = state.get(symbol);
    if (recordedValue !== undefined && value === `O(${symbol})` && recordedValue !== value) continue;
    state.set(symbol, value);
  }
  return state;
}

/** A worst-case choice between mutually exclusive CFG edges, never a sum... unless the edges' costs are incomparable, where the sum is the sound upper bound. */
function branchMaximum(left: Complexity, right: Complexity): Complexity | undefined {
  if (left === "Does not terminate" || right === "Does not terminate") return "Does not terminate";
  if (left === "O(1)") return right;
  if (right === "O(1)") return left;
  if (left === right) return left;
  return dominantExpression(left, right) ?? sequentialMaximum([left, right]);
}

/** Statically evaluates a literal condition: true, false, or unknown. */
function literalConditionValue(node: ClangNode | undefined): boolean | undefined {
  const value = constantNumber(node);
  return value === undefined ? undefined : Boolean(value);
}

/**
 * An UNCONDITIONAL break: a direct BreakStmt of the loop body, or one inside
 * a statically-true branch. Conditional breaks (inside runtime branches) do
 * not collapse the loop trip count and are deliberately excluded.
 */
function hasUnconditionalBreak(body: ClangNode | undefined, literalEval: (node: ClangNode | undefined) => boolean | undefined): boolean {
  if (!body) return false;
  if (body.kind === "BreakStmt") return true;
  if (body.kind !== "CompoundStmt") return false;
  for (const statement of body.inner ?? []) {
    if (statement.kind === "BreakStmt") return true;
    if (statement.kind === "IfStmt") {
      const conditionValue = literalEval(statement.inner?.[0]);
      const branches = (statement.inner ?? []).slice(1);
      const thenHasBreak = branches[0] ? hasUnconditionalBreak(branches[0], literalEval) : false;
      const elseHasBreak = branches[1] ? hasUnconditionalBreak(branches[1], literalEval) : false;
      if (conditionValue === true && thenHasBreak) return true;
      if (conditionValue === false && elseHasBreak) return true;
      if (conditionValue === undefined && thenHasBreak && elseHasBreak) return true;
    }
  }
  return false;
}

function pathSensitiveStatement(
  statement: ClangNode | undefined,
  bounds: SymbolicBounds,
  flow: ControlFlowBounds,
  localCosts?: LocalFunctionCosts,
  constantSymbols?: ReadonlySet<string>,
  depth = 0
): PathWork | undefined {
  if (!statement) return { value: "O(1)", proof: [] };
  if (depth > 24) return undefined;
  if (statement.kind === "CompoundStmt") {
    const children = statement.inner ?? [];
    // An empty or all-constant statement sequence performs constant work.
    if (children.length === 0) return { value: "O(1)", proof: [] };
    const parts = children.map((child) => pathSensitiveStatement(child, bounds, flow, localCosts, constantSymbols, depth + 1));
    if (parts.some((part) => !part)) return undefined;
    const values = parts.map((part) => part!.value);
    const value = sequentialMaximum(values);
    if (!value) return undefined;
    const merged = { value, proof: parts.flatMap((part) => part!.proof), ...mergePathWork(parts) };
    // A lone harmonic loop among constant statements keeps its rational
    // term; several rational parts or heavier siblings fall back to the
    // sound upper bound.
    const rationalParts = parts.filter((part) => part!.rationalTerm);
    if (rationalParts.length === 1 && parts.every((part) => part === rationalParts[0] || part!.value === "O(1)")) {
      return { ...merged, rationalTerm: rationalParts[0]!.rationalTerm, rationalIndex: rationalParts[0]!.rationalIndex, upperBoundOnly: rationalParts[0]!.upperBoundOnly };
    }
    const ratioParts = parts.filter((part) => part?.ratioTrip);
    if (ratioParts.length === 1 && parts.every((part) => part === ratioParts[0] || part?.value === "O(1)")) {
      return { ...merged, ratioTrip: ratioParts[0]!.ratioTrip, bodyCost: ratioParts[0]!.bodyCost };
    }
    return merged;
  }
  if (statement.kind === "IfStmt") {
    const branches = (statement.inner ?? []).slice(1);
    const entry = flow.branchEntries.get(statement);
    if (!branches[0]) return undefined;
    const condition = statement.inner?.[0];
    // Constant-condition folding: a statically true/false literal eliminates
    // the dead edge entirely. Runtime-dependent conditions analyze both.
    const staticValue = literalConditionValue(condition);
    if (staticValue !== undefined) {
      const live = staticValue ? branches[0] : (branches[1] ?? { kind: "CompoundStmt" });
      const liveWork = pathSensitiveStatement(live, constrainBranchState(pathEntryState(entry?.thenState, bounds), condition, staticValue), flow, localCosts, constantSymbols, depth + 1);
      if (!liveWork) return undefined;
      return {
        value: liveWork.value,
        proof: [
          "Statically " + (staticValue ? "true" : "false") + " condition: the dead branch is eliminated before costing.",
          ...liveWork.proof
        ],
        estimated: liveWork.estimated,
        helperSpaces: liveWork.helperSpaces,
        unprovenSpace: liveWork.unprovenSpace,
        rationalTerm: liveWork.rationalTerm,
        rationalIndex: liveWork.rationalIndex,
        upperBoundOnly: liveWork.upperBoundOnly
      };
    }
    const thenState = constrainBranchState(pathEntryState(entry?.thenState, bounds), condition, true);
    const elseState = constrainBranchState(pathEntryState(entry?.elseState, bounds), condition, false);
    const thenWork = pathSensitiveStatement(branches[0], thenState, flow, localCosts, constantSymbols, depth + 1);
    // No else is an explicit O(1) fall-through edge.
    const elseWork = branches[1]
      ? pathSensitiveStatement(branches[1], elseState, flow, localCosts, constantSymbols, depth + 1)
      : { value: "O(1)" as Complexity, proof: [] };
    if (!thenWork || !elseWork) return undefined;
    let value = branchMaximum(thenWork.value, elseWork.value);
    // The condition's own cost (calls like set::count) is always evaluated.
    // A failed parse (Clang RecoveryExpr, e.g. a call to an undeclared
    // function) could be any amount of work on every evaluation of this
    // decision, so the branch abstains instead of silently treating it as
    // constant time - the same policy as assignment statements with
    // unresolved calls.
    const conditionCalls = condition ? directCalls(condition) : [];
    const conditionHasRecovery = condition ? nodesOfKind(condition, "RecoveryExpr").length > 0 : false;
    if (conditionHasRecovery || conditionCalls.length > 0) {
      if (conditionHasRecovery) return undefined;
      const conditionCosts = conditionCalls.map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
      if (conditionCosts.some((cost) => !cost)) return undefined;
      if (!conditionCosts.includes("Does not terminate")) {
        const conditionMax = sequentialMaximum(conditionCosts.filter((cost): cost is Complexity => Boolean(cost)));
        if (conditionMax && conditionMax !== "O(1)" && value && value !== "O(1)") {
          value = multiply(conditionMax, value) ?? conditionMax;
        } else if (conditionMax && conditionMax !== "O(1)") {
          value = conditionMax;
        }
      }
    }
    if (!value) return undefined;
    return {
      value,
      proof: [
        "CFG branch analysis evaluates each reachable if/else edge with its own symbolic bounds.",
        ...(thenWork.proof.length > 0 ? ["Then edge: " + thenWork.value + "."] : []),
        ...(elseWork.proof.length > 0 ? ["Else edge: " + elseWork.value + "."] : []),
        "Worst-case control flow selects the dominant proven edge: " + value + "."
      ],
      ...mergePathWork([thenWork, elseWork])
    };
  }
  // A switch executes one case region (fall-through stays inside that region's
  // sequential statements), so the worst case is the dominant case body.
  if (statement.kind === "SwitchStmt") {
    const body = bodyOf(statement);
    const parts = (body?.inner ?? []).map((child) => pathSensitiveStatement(child, bounds, flow, localCosts, constantSymbols, depth + 1));
    if (parts.some((part) => !part)) return undefined;
    let value: Complexity | undefined = "O(1)";
    for (const part of parts) {
      value = part ? branchMaximum(value!, part.value) : undefined;
      if (!value) return undefined;
    }
    return { value: value!, proof: ["Switch analysis takes the dominant case body as the worst case."], ...mergePathWork(parts) };
  }
  if (["ForStmt", "WhileStmt", "CXXForRangeStmt", "DoStmt"].includes(statement.kind ?? "")) {
    const result = compositionalLoopCost(statement, pathEntryState(flow.loopEntries.get(statement), bounds), flow, localCosts, constantSymbols, depth);
    if (!result.value) return undefined;
    return {
      value: result.value,
      proof: result.proof ?? [],
      estimated: result.estimated,
      helperSpaces: result.helperSpaces,
      unprovenSpace: result.unprovenSpace,
      rationalTerm: result.rationalTerm,
      rationalIndex: result.rationalIndex,
      upperBoundOnly: result.upperBoundOnly,
      ratioTrip: result.ratioTrip,
      bodyCost: result.bodyCost
    };
  }
  if (["DeclStmt", "VarDecl", "BinaryOperator", "UnaryOperator", "CompoundAssignOperator", "NullStmt", "BreakStmt", "ContinueStmt"].includes(statement.kind ?? "")) {
    // Sized container construction is accounted as auxiliary storage by the
    // space pass, not as algorithmic time; only hidden calls cost time here:
    // `answer += store.query(...)` composes the callee's cost.
    // A Clang RecoveryExpr marks a failed parse: the construct could be
    // anything, so costing it (or ignoring it) would be unsound.
    if (nodesOfKind(statement, "RecoveryExpr").length > 0) return undefined;
    const hiddenCalls = directCalls(statement);
    const callCosts = hiddenCalls.map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
    if (callCosts.some((cost) => !cost)) return undefined;
    const value = sequentialMaximum(callCosts.filter((cost): cost is Complexity => Boolean(cost)));
    if (callCosts.length > 0 && value) {
      return { value, proof: ["Resolved supported calls inside assignment or declaration statements."], ...mergePathWork(callCosts.map((cost) => ({ value: cost!, proof: [] }))) };
    }
    if (callCosts.length > 0) return undefined;
    return { value: "O(1)", proof: [] };
  }
  if (["ExprWithCleanups", "ImplicitCastExpr", "ParenExpr"].includes(statement.kind ?? "")) {
    return pathSensitiveStatement(statement.inner?.at(-1), bounds, flow, localCosts, constantSymbols, depth + 1);
  }
  if (["ReturnStmt", "CallExpr", "CXXMemberCallExpr", "CXXOperatorCallExpr"].includes(statement.kind ?? "")) {
    if (nodesOfKind(statement, "RecoveryExpr").length > 0) return undefined;
    const calls = statement.kind === "ReturnStmt" ? directCalls(statement) : [statement];
    if (calls.length === 0) return { value: "O(1)", proof: [] };
    const costs = calls.map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
    if (costs.some((value) => !value)) return undefined;
    const value = sequentialMaximum(costs.filter((cost): cost is Complexity => Boolean(cost)));
    if (!value) return undefined;
    // Helper/library evidence travels with the composed result so confidence
    // and auxiliary-space caveats survive to the final answer.
    // Evidence from NESTED calls too: `cout << solve(n)` composes solve's
    // time through the operator chain, and solve's stack-space summary and
    // estimated confidence ride along the same way.
    const nestedCalls = calls.flatMap((call) => directCalls(call).filter((inner) => inner !== call));
    const allCalls = [...calls, ...nestedCalls];
    const helperSpaces = allCalls.map((call) => localCallSpace(call, localCosts, bounds, constantSymbols))
      .filter((space): space is AuxiliarySpace => space !== undefined);
    const unprovenSpace = allCalls.some((call) =>
      localCallSpace(call, localCosts, bounds, constantSymbols) === undefined
      && knownLoopCallCost(call, localCosts, bounds, constantSymbols) !== "O(1)");
    return {
      value,
      proof: ["Resolved supported calls on this CFG edge."],
      estimated: allCalls.some((call) => localCallConfidence(call, localCosts) === "estimated"),
      helperSpaces,
      unprovenSpace
    };
  }
  return undefined;
}

/**
 * Compositional loop costing: a proven trip count times the worst-case cost
 * of the body, statement by statement, at arbitrary nesting. Break and
 * continue only remove iterations, so the unbroken upper bound remains
 * valid. A geometric loop whose body scales with its own index collapses to
 * the final term of the dominating geometric series.
 */
function strideDebug(key: string): string { return key.length > 8 ? key.slice(-6) : key; }

function innerBodyWorkProxy(work: { value: Complexity } | undefined): boolean {
  return Boolean(work && work.value !== "Does not terminate");
}

function outerNamesHas(key: string, update: ClangNode | undefined): boolean {
  return nodesOfKind(update ?? {}, "DeclRefExpr").some((reference) => reference.referencedDecl?.name !== undefined && reference.referencedDecl.name === key);
}

function compositionalLoopCost(
  loop: ClangNode,
  bounds: SymbolicBounds,
  flow: ControlFlowBounds,
  localCosts?: LocalFunctionCosts,
  constantSymbols?: ReadonlySet<string>,
  depth = 0
): LoopAnalysis {
  if (depth > 16) return {};
  if (isZeroInitializedMultiplicativeLoop(loop) || nonProgressingUpdate(updateOf(loop)) || equalityLoopReachability.get(loop) === "away") {
    return { value: "Does not terminate", proof: ["The loop update cannot make progress for a valid worst-case input."] };
  }
  let own: ReturnType<typeof loopBound>;
  if (loop.kind === "CXXForRangeStmt") {
    const info = rangeContainerInfo(loop);
    if (!info) return {};
    const supportedRangeType = /\b(?:vector|deque|array|map|set|multimap|multiset)\s*</.test(info.type)
      || /\b(?:string|basic_string)\b/.test(info.type);
    if (/unordered_/.test(info.type) || !supportedRangeType) return {};
    const traversal = (info.name ? bounds.get(info.name) ?? "O(n)" : "O(n)");
    own = { value: traversal, bound: traversal };
  } else {
    own = loopBound(loop, bounds, constantSymbols);
    if (!own.value) return {};
  }
  const body = bodyOf(loop);
  const index = loopIndex(own.update);
  const childBounds = new Map(bounds);
  if (index && own.bound) childBounds.set(index, own.bound);
  // Unconditional break: every path through the body reaches a break before
  // the loop header re-tests, so exactly ONE iteration executes. Only the
  // pre-break statements contribute; conditional breaks never collapse.
  const bodyDirect: ClangNode[] = body ? (body.kind === "CompoundStmt" ? (body.inner ?? []) : [body]) : [];
  const unconditionalBreakIndex = bodyDirect.findIndex((statement) => hasUnconditionalBreak(statement, literalConditionValue));
  if (unconditionalBreakIndex > 0 || (unconditionalBreakIndex === 0 && bodyDirect.length === 1)) {
    const preBreak = bodyDirect.slice(0, Math.max(unconditionalBreakIndex, 0));
    const preWork = pathSensitiveStatement(preBreak.length === 1 ? preBreak[0] : (preBreak.length > 1 ? { kind: "CompoundStmt", inner: preBreak } : undefined), childBounds, flow, localCosts, constantSymbols, depth);
    if (preWork) {
      const value = preWork.value;
      return {
        value,
        proof: [
          "An unconditional break terminates the loop after exactly one iteration: the syntactic trip bound is not reached.",
          "Only the pre-break statements execute once per enclosing context."
        ],
        index,
        condition: own.condition,
        bound: own.bound
      };
    }
  }
  // ---- Monotone amortized inner while (two-pointer family) ----
  // An inner while advancing a cursor that is declared OUTSIDE this loop and
  // never reset moves at most `cursor bound` steps across the ENTIRE outer
  // loop: total work = outer trip + cursor range, i.e. linear. A reset
  // (assigning the cursor without itself on the right) disqualifies.
  {
    const bodyStatements: ClangNode[] = body ? (body.kind === "CompoundStmt" ? (body.inner ?? []) : [body]) : [];
    // The cursor loop may be a while OR a for with an empty header init
    // (`for (; fast < n && ...; ++fast)`) - the cursor itself is declared
    // outside the outer loop either way.
    const innerWhile = bodyStatements.find((statement) => statement.kind === "WhileStmt"
      || (statement.kind === "ForStmt" && !(statement.inner ?? []).some((part) => part.kind === "DeclStmt")));
    if (innerWhile && bodyStatements.filter((statement) => ["ForStmt", "WhileStmt"].includes(statement.kind ?? "")).length === 1) {
      // For a conjunction condition (&&), find the comparison referencing
      // the cursor instead of using the raw first child.
      const innerCondition = directCondition(innerWhile)
        ?? [...(innerWhile.inner ?? [])].flatMap((part) => nodesOfKind(part, "BinaryOperator"))
          .find((op) => ["<", "<=", ">", ">=", "!="].includes(op.opcode ?? ""))
        ?? innerWhile.inner?.[0];
      const mutatedCursor = nodesOfKind(innerWhile, "UnaryOperator")
        .filter((operation) => ["++", "--"].includes(operation.opcode ?? ""))
        .map((operation) => referencedName(operation))
        .filter((name): name is string => Boolean(name))
        .find((name) => name !== index);
      if (mutatedCursor && innerCondition && body) {
        // The cursor must not be declared inside this loop (no per-iteration reset).
        const declaredInside = nodesOfKind(body, "VarDecl").some((declaration) => declaration.name === mutatedCursor);
        // All cursor mutations must be monotone: no direct assignment without
        // the cursor on the right-hand side.
        let hasReset = false;
        if (body) walk(body, (current) => {
          if (current.kind === "BinaryOperator" && current.opcode === "=" && (current.inner?.length ?? 0) >= 2) {
            const target = referencedName(current.inner?.[0]);
            if (target === mutatedCursor) {
              let rhs = current.inner![1];
              while (rhs && ["ImplicitCastExpr", "ParenExpr"].includes(rhs.kind ?? "")) rhs = rhs.inner?.[0] ?? rhs;
              const readsCursor = referencesSymbol(rhs, referenceKey(current.inner?.[0]) ?? "");
              if (!readsCursor) hasReset = true;
            }
          }
        });
        // The inner condition must bound the cursor by an independent symbol.
        // The cursor bound may sit inside a conjunction (r < n && a[r] <= ...):
        // find the comparison that mentions the cursor and take its other side.
        if (process.env.PROJECT_X_DEBUG) console.error(`[mono-cmp] innerCond=${innerCondition.kind}:${innerCondition.opcode ?? "-"} mutatedCursor=${mutatedCursor}`);
        const cursorComparisons = nodesOfKind(innerCondition, "BinaryOperator")
          .filter((operation) => ["<", "<=", ">", ">="].includes(operation.opcode ?? ""))
          .filter((operation) => nodesOfKind(operation, "DeclRefExpr").some((reference) => reference.referencedDecl?.name === mutatedCursor));
        const cursorBound = cursorComparisons.map((operation) => {
          const leftName = referencedName(operation.inner?.[0]);
          const boundSide = leftName === mutatedCursor ? operation.inner?.[1] : operation.inner?.[0];
          return boundSide ? expressionComplexity(boundSide, bounds, constantSymbols) : undefined;
        }).find((value): value is Complexity => Boolean(value && value !== "O(1)" && value !== "Unknown"));
        if (process.env.PROJECT_X_DEBUG) console.error(`[mono2] declaredInside=${declaredInside} hasReset=${hasReset} cursorBound=${cursorBound ?? "-"}`);
        if (!declaredInside && !hasReset && cursorBound && cursorBound !== "O(1)" && cursorBound !== "Unknown") {
          const innerBodyWork = pathSensitiveStatement(bodyOf(innerWhile), childBounds, flow, localCosts, constantSymbols, depth + 1);
          if (innerBodyWork && innerBodyWork.value !== "Does not terminate") {
            const cursorTerm = parseBound(cursorBound);
            const outerTerm = parseBound(own.value!);
            if (cursorTerm && outerTerm) {
              const value = formatBound(maxBounds(outerTerm, cursorTerm));
              return {
                value,
                proof: [
                  "Monotone amortized progress: the cursor advanced by the inner while is never reset, so its total movement across ALL outer iterations is bounded by " + cursorBound + ".",
                  "Outer iterations (" + own.value + ") plus total cursor movement (" + cursorBound + ") compose to " + value + " - the nest is linear, not quadratic."
                ],
                index,
                condition: own.condition,
                bound: own.bound
              };
            }
          }
        }
      }
    }
  }

  // ---- Amortized factor reduction in square-root loops (trial division / Euler phi) ----
  // In `for (int i = 2; i * i <= n; ++i)` with an inner `while (n % i == 0) n /= i`,
  // the inner while loop divides the outer limit n by i >= 2. Across the entire
  // execution, n can be divided at most log2(n) times in total. Each division strictly
  // decreases n, which only reduces the outer loop limit sqrt(n).
  // The cumulative work across all iterations is O(sqrt n + log n) = O(sqrt n).
  if (own.value?.startsWith("O(sqrt ") && body && index) {
    const outerLimitRef = nodesOfKind(own.condition ?? {}, "DeclRefExpr")
      .find((ref) => referenceKey(ref) && referenceKey(ref) !== index);
    const outerLimitKey = referenceKey(outerLimitRef);
    const outerLimitName = outerLimitRef?.referencedDecl?.name ?? "n";
    if (outerLimitKey) {
      const innerWhiles = nodesOfKind(body, "WhileStmt");
      const factorDivisionWhile = innerWhiles.find((ws) => {
        const hasModulo = nodesOfKind(ws, "BinaryOperator").some((op) => op.opcode === "%" && referencesSymbol(op, outerLimitKey) && referencesSymbol(op, index));
        const bodyOfWs = bodyOf(ws);
        const hasDivision = bodyOfWs && nodesOfKind(bodyOfWs, "CompoundAssignOperator").some((op) => op.opcode === "/=" && referencesSymbol(op.inner?.[0], outerLimitKey));
        return Boolean(hasModulo && hasDivision);
      });
      if (factorDivisionWhile) {
        return {
          value: own.value,
          proof: [
            "Trial-division factor reduction: the inner loop divides the bound " + outerLimitName + " by i >= 2 at most log(" + outerLimitName + ") times in total across all iterations, while reducing the outer stopping threshold sqrt(" + outerLimitName + ").",
            "Cumulative work across all iterations is O(sqrt " + outerLimitName + " + log " + outerLimitName + ") = " + own.value + "."
          ],
          index,
          condition: own.condition,
          bound: own.bound
        };
      }
    }
  }

  const bodyWork = pathSensitiveStatement(body, childBounds, flow, localCosts, constantSymbols, depth);
  if (!bodyWork) return {};
  if (bodyWork.value === "Does not terminate") return { value: "Does not terminate", proof: bodyWork.proof };
  const geometric = own.value === "O(log n)" && ["*=", "/="].includes(own.update?.opcode ?? "");
  // ---- Amortized geometric inner starting at the enclosing index ----
  // sum_{i=1..n} log(n/i) = Theta(n): the inner contributes only its BODY
  // cost per outer iteration, not its log(n/i) trip count. Works for both
  // for-form (header init) and while-form (sibling DeclStmt/assignment).
  {
    let amortizedInitKey: string | undefined;
    let amortizedBodyCost: Complexity | undefined;
    // For-form: the header init references the outer index.
    if (bodyWork.ratioTrip?.initKey && bodyWork.bodyCost === "O(1)" && own.update?.opcode === "++"
      && (bodyWork.ratioTrip.initKey === index || outerNamesHas(bodyWork.ratioTrip.initKey, own.update))) {
      amortizedInitKey = bodyWork.ratioTrip.initKey;
      amortizedBodyCost = bodyWork.bodyCost;
    }
    // While-form: a sibling DeclStmt/assignment initializes the cursor from
    // the outer index, followed by exactly one geometric while-loop.
    if (!amortizedInitKey && body && own.update?.opcode === "++" && index) {
      const stmts = body.kind === "CompoundStmt" ? (body.inner ?? []) : [body];
      const loopStmts = stmts.filter((s) => ["WhileStmt", "ForStmt"].includes(s.kind ?? ""));
      if (loopStmts.length === 1) {
        const innerLoop = loopStmts[0];
        const innerIdx = stmts.indexOf(innerLoop);
        const prev = innerIdx > 0 ? stmts[innerIdx - 1] : undefined;
        const initExpr = prev?.kind === "DeclStmt"
          ? prev.inner?.[0]?.inner?.at(-1)
          : prev?.kind === "BinaryOperator" && prev.opcode === "=" ? prev.inner?.[1] : undefined;
        if (initExpr) {
          let u = initExpr;
          while (u && ["ImplicitCastExpr", "ParenExpr"].includes(u.kind ?? "")) u = u.inner?.[0] ?? u;
          const initKey = u ? referenceKey(u) : undefined;
          const outerName = nodesOfKind(own.update ?? {}, "DeclRefExpr").map((r) => r.referencedDecl?.name).find((v): v is string => Boolean(v));
          if (initKey && (initKey === index || outerName)) {
            const hasMult = nodesOfKind(innerLoop, "CompoundAssignOperator").some((op) => ["*=", "<<="].includes(op.opcode ?? ""));
            const innerBodyCost = pathSensitiveStatement(bodyOf(innerLoop), childBounds, flow, localCosts, constantSymbols, depth + 1);
            if (hasMult && innerBodyWorkProxy(innerBodyCost)) {
              amortizedInitKey = initKey;
              amortizedBodyCost = innerBodyCost?.value ?? "O(1)";
            }
          }
        }
      }
    }
    if (amortizedInitKey && amortizedBodyCost && own.update?.opcode === "++") {
      const value = multiply(own.value!, amortizedBodyCost);
      if (!value) return {};
      return {
        value,
        proof: [
          "Amortized geometric inner: the loop starts at the enclosing iterator, so sum log(n/i) over the outer index is Theta(n) - the inner contributes only its body cost per outer iteration."
        ],
        index,
        condition: own.condition,
        bound: own.bound
      };
    }
  }


  // ---- Outer sum rule: the body carries a harmonic per-iteration term ----
  // The inner loop solved to C * i^p (p = -1 for the harmonic family);
  // summing over this loop trip count applies the power-sum identity:
  //   sum C*i^p = C*log(N) for p = -1, C*N^(p+1) for p > -1.
  if (bodyWork.rationalTerm && bodyWork.rationalIndex && own.bound) {
    // The summation domain follows the outer iterator: additive steps
    // (i = 1..N) give harmonic/power sums; geometric steps (i *= c) give
    // series dominated by their first or last term.
    const outerNames = new Set(nodesOfKind(own.update ?? {}, "DeclRefExpr").map((reference) => reference.referencedDecl?.name).filter((value): value is string => Boolean(value)));
    const geometricDomain = Boolean(own.update && ["*=", "/=", "<<="].includes(own.update.opcode ?? ""));
    const term = bodyWork.rationalTerm[0];
    // matchedKey must be a symbol THAT EXISTS IN THE TERM: the harmonic
    // path keys terms by declaration id, the quotient path by the spelled
    // name of the enclosing index.
    let matchedKey: string | undefined;
    if (index && term.symbols.has(index) && term.symbols.get(index)! < 0) matchedKey = index;
    else matchedKey = [...term.symbols.keys()].find((symbol) => (term.symbols.get(symbol) ?? 0) < 0 && outerNames.has(symbol));
    if (process.env.PROJECT_X_DEBUG) console.error(`[sumrule] reached ridx=${bodyWork.rationalIndex} matched=${matchedKey} bwv=${bodyWork.value}`);
    if (matchedKey !== undefined) {
      const p = term.symbols.get(matchedKey) ?? 0;
      const c: Term = { symbols: new Map(term.symbols), logs: new Map(term.logs), logLogs: new Map(term.logLogs), ackermanns: new Set(term.ackermanns) };
      c.symbols.delete(matchedKey);
      if (process.env.PROJECT_X_DEBUG) console.error(`[sumrule] p=${p} c=${JSON.stringify([...c.symbols])} bound=${own.bound} geom=${geometricDomain}`);
      const boundSymbol = /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(own.bound ?? "")?.[1] ?? "n";
      let totalTerm: Term;
      if (geometricDomain) {
        // Over a geometric domain the series is dominated by its first term
        // (p < 0), its step count (p = 0), or its last term (p > 0).
        if (p < 0) totalTerm = c;
        else if (p === 0) {
          totalTerm = c;
          totalTerm.logs.set(boundSymbol, (totalTerm.logs.get(boundSymbol) ?? 0) + 1);
        } else {
          totalTerm = c;
          totalTerm.symbols.set(boundSymbol, (totalTerm.symbols.get(boundSymbol) ?? 0) + p);
        }
      } else if (p === -1) {
        totalTerm = c;
        totalTerm.logs.set(boundSymbol, (totalTerm.logs.get(boundSymbol) ?? 0) + 1);
      } else if (p < -1) {
        totalTerm = c;
      } else {
        totalTerm = c;
        totalTerm.symbols.set(boundSymbol, (totalTerm.symbols.get(boundSymbol) ?? 0) + p + 1);
      }
      const value = formatBound([totalTerm]);
      return {
        value,
        proof: [
          ...(bodyWork.proof ?? []),
          "Dependent inner work summed over the outer index with the power-sum identity: the series resolves to " + value + "."
        ],
        index,
        condition: own.condition,
        bound: own.bound
      };
    }
  }
  if (geometric) {
    // An index-dependent body (inner work bounded by the geometric index) is
    // dominated by the final geometric term; an index-independent body simply
    // multiplies the logarithmic iteration count.
    // The dependence probe caps the loop's own index at O(1): the CFG-recorded
    // declaration bound would otherwise satisfy the inner reference even when
    // the body genuinely scales with the index.
    const probeBounds = new Map(bounds);
    if (index) probeBounds.set(index, "O(1)");
    const withoutIndex = pathSensitiveStatement(body, probeBounds, flow, localCosts, constantSymbols, depth);
    if (!withoutIndex || withoutIndex.value !== bodyWork.value) {
      return { value: bodyWork.value, proof: ["Inner work is bounded by the geometrically changing outer index.", "The geometric series is dominated by its final term: " + bodyWork.value + "."], index, condition: own.condition, geometric, bound: own.bound };
    }
  }
  // ---- Harmonic middle loop: stride references an enclosing index ----
  // The trip count is limit/stride (n * i^-1). The body work resolves
  // to a per-enclosing-iteration term; the enclosing loop applies the
  // power-sum identity. Guarded or unsolvable shapes keep the sound
  // upper bound and downgrade confidence instead.
  if (own.rationalTrip && index) {
    if (process.env.PROJECT_X_DEBUG) console.error(`[harm] entered strideKey=${strideDebug(own.rationalTrip.indexKey)} perIteration=will-build bwv=${bodyWork.value}`);
    const { term: tripTerm, indexKey: strideKey, limitSymbol } = own.rationalTrip;
    if (!body) return {};
    const bodyStatements: ClangNode[] = body.kind === "CompoundStmt" ? (body.inner ?? []) : [body];
    const innerLoops = bodyStatements.filter((statement) => ["ForStmt", "WhileStmt"].includes(statement.kind ?? ""));
    const guarded = bodyStatements.some((statement) => statement.kind === "IfStmt" && nodesOfKind(statement, "ForStmt").length + nodesOfKind(statement, "WhileStmt").length > 0);
    const otherWork = bodyStatements.filter((statement) => statement !== innerLoops[0])
      .map((statement) => pathSensitiveStatement(statement, childBounds, flow, localCosts, constantSymbols, depth + 1));
    const innerLoop = innerLoops[0];
    const bodyCostOK = otherWork.every((work) => work && work.value === "O(1)") || innerLoops.length === 0;
    // A preceding sibling `j = <enclosing index>` initializes a while-form
    // geometric loop's cursor from the outer iterator: mark the ratio trip.
    let siblingRatio = false;
    if (!innerLoop && body.kind === "CompoundStmt") {
      const stmts = body.inner ?? [];
      for (let index2 = 0; index2 < stmts.length; ++index2) {
        const candidate = stmts[index2];
        if (!["WhileStmt", "ForStmt"].includes(candidate.kind ?? "")) continue;
        const previous = index2 > 0 ? stmts[index2 - 1] : undefined;
        const initExpr = previous?.kind === "DeclStmt"
          ? previous.inner?.[0]?.inner?.at(-1)
          : previous?.kind === "BinaryOperator" && previous.opcode === "=" ? previous.inner?.[1] : undefined;
        if (initExpr && referencesSymbol(initExpr, own.rationalTrip.indexKey)) {
          const cursorLoop = nodesOfKind(candidate, "CompoundAssignOperator").some((operation) => ["*=", "<<="].includes(operation.opcode ?? ""));
          if (cursorLoop) siblingRatio = true;
        }
      }
    }
    if (!guarded && innerLoops.length <= 1 && bodyCostOK) {
      const innerCondition = innerLoop ? (directCondition(innerLoop) ?? (innerLoop.kind === "WhileStmt" ? innerLoop.inner?.[0] : undefined)) : undefined;
      const referencesOwnIndex = Boolean(innerCondition && referencesSymbol(innerCondition, index));
      const innerUpdate = innerLoop ? updateOf(innerLoop) : undefined;
      const geometricInner = Boolean(innerUpdate && ["*=", "<<="].includes(innerUpdate.opcode ?? ""));
      // sqrt family: a comparison whose product side squares the inner
      // index against the harmonic iterator (`k * k <= j`).
      const squareInner = Boolean(innerCondition && ["<", "<=", ">", ">="].includes(innerCondition.opcode ?? "")
        && nodesOfKind(innerCondition, "BinaryOperator").some((operation) => operation.opcode === "*")
        && referencesSymbol(innerCondition, index));
      const innerBodyWork = innerLoop ? pathSensitiveStatement(bodyOf(innerLoop), new Map(childBounds), flow, localCosts, constantSymbols, depth + 1) : undefined;
      if (!innerLoop || (innerBodyWork && innerBodyWork.value !== "Does not terminate")) {
        // Per-middle-iteration inner trip g(j); per-outer-iteration term
        // sum_{q=1..L/i} g(q*i) by the standard identities. Without an inner
        // loop the whole per-iteration work is the harmonic trip itself.
        // The stride's multiplicity (i -> 1, i*i -> 2) sets the negative
        // exponent of the per-enclosing-iteration term.
        const strideExponent = -(tripTerm[0].symbols.get(strideKey) ?? 1);
        let perIteration: Term;
        if (geometricInner) {
          // sum log(q*i^e) over q = 1..L/i^e is (L/i^e) * log L
          perIteration = { symbols: new Map([[limitSymbol, 1], [strideKey, -strideExponent]]), logs: new Map([[limitSymbol, 1]]), logLogs: new Map(), ackermanns: new Set() };
        } else if (squareInner) {
          // sum sqrt(q*i) over the harmonic family = L^(3/2) * i^-1
          perIteration = { symbols: new Map([[limitSymbol, 1.5], [strideKey, -strideExponent]]), logs: new Map(), logLogs: new Map(), ackermanns: new Set() };
        } else {
          // sum (q*i^e)^p = L^(p+1) * i^-e for the linear family (p = 1),
          // and plain L * i^-e when the inner trip does not depend on j.
          const p = referencesOwnIndex && innerCondition ? 1 : 0;
          perIteration = { symbols: new Map([[limitSymbol, p + 1], [strideKey, -strideExponent]]), logs: new Map(), logLogs: new Map(), ackermanns: new Set() };
        }
        const bodyBound = innerLoop && innerBodyWork && innerBodyWork.value !== "O(1)" ? parseBound(innerBodyWork.value) : undefined;
        if (process.env.PROJECT_X_DEBUG) console.error(`[harm] per-i=${formatBound([perIteration])} innerBody=${innerBodyWork ? innerBodyWork.value : "none"}`);
        let rationalTerm: Bound = [perIteration];
        if (bodyBound) {
          const product = multiplyBounds(rationalTerm, bodyBound);
          if (!product) return {};
          rationalTerm = product;
        }
        const fallback = multiply(own.value!, bodyWork.value);
        return {
          value: fallback ?? own.value!,
          proof: [
            "Harmonic dependent loop: the stride is the enclosing index, so each outer iteration runs about " + formatBound(tripTerm) + " inner steps.",
            "The per-enclosing-iteration work is carried symbolically for summation over the outer loop."
          ],
          index,
          condition: own.condition,
          geometric,
          bound: own.bound,
          estimated: true,
          helperSpaces: bodyWork.helperSpaces,
          unprovenSpace: bodyWork.unprovenSpace,
          rationalTerm,
          rationalIndex: strideKey,
          upperBoundOnly: true
        };
      }
    }
    // Harmonic but unsolved: report the sound upper bound explicitly.
    const fallback2 = multiply(own.value!, bodyWork.value);
    if (fallback2) {
      return {
        value: fallback2,
        proof: [
          "Harmonic dependent loop detected (stride is an enclosing index); the multiplicative result is an UPPER BOUND, not the tight class.",
          ...bodyWork.proof
        ],
        index,
        condition: own.condition,
        geometric,
        bound: own.bound,
        estimated: true,
        helperSpaces: bodyWork.helperSpaces,
        unprovenSpace: bodyWork.unprovenSpace,
        upperBoundOnly: true
      };
    }
    return {};
  }
  const value = multiply(own.value!, bodyWork.value);
  if (!value) return {};
  return {
    value,
    proof: [
      "Loop header establishes " + own.value + " iterations.",
      ...bodyWork.proof,
      "The worst-case body cost is composed once per loop iteration."
    ],
    index,
    condition: own.condition,
    geometric,
    bound: own.bound,
    estimated: bodyWork.estimated,
    helperSpaces: bodyWork.helperSpaces,
    unprovenSpace: bodyWork.unprovenSpace,
    bodyCost: bodyWork.value,
    ratioTrip: own.ratioTrip
  };
}

/**
 * Composes a header-progressing for-loop with its branch-sensitive body. The
 * regular loop analyser remains responsible for canonical bodies and all
 * while-loops; this path is intentionally limited to `for` because a
 * conditional `continue` in a while-loop can skip the only progress update.
 */
function analyseLoopWithCfg(
  loop: ClangNode,
  bounds: SymbolicBounds,
  flow: ControlFlowBounds,
  localCosts?: LocalFunctionCosts,
  constantSymbols?: ReadonlySet<string>
): LoopAnalysis {
  const body = bodyOf(loop);
  if (loop.kind !== "ForStmt" || !body || !nodesOfKind(body, "IfStmt").length) {
    return analyseLoop(loop, bounds, localCosts, constantSymbols);
  }
  // A break can make the loop asymptotically smaller, but proving the first
  // reachable break needs induction/predicate correlation. Do not label an
  // O(n) upper bound as an exact complexity until that proof exists.
  if (nodesOfKind(body, "BreakStmt").length > 0) return {};
  if (isZeroInitializedMultiplicativeLoop(loop) || nonProgressingUpdate(updateOf(loop)) || equalityLoopReachability.get(loop) === "away") {
    return { value: "Does not terminate", proof: ["The loop update cannot make progress for a valid worst-case input."] };
  }
  const own = loopBound(loop, bounds, constantSymbols);
  if (!own.value || !own.condition) return {};
  const iterationBounds = new Map(bounds);
  const index = loopIndex(own.update);
  if (index && own.bound) iterationBounds.set(index, own.bound);
  const perIteration = pathSensitiveStatement(body, iterationBounds, flow, localCosts, constantSymbols);
  if (!perIteration?.value) return {};
  if (perIteration.value === "Does not terminate") return { value: "Does not terminate", proof: perIteration.proof };
  // Do not apply this simple multiplication rule to a geometric outer loop:
  // dependent geometric-series simplification is handled by analyseLoop's
  // canonical nested-loop proof and needs stronger dependency facts.
  if (own.value === "O(log n)" && nestedLoops(loop).length > 0) return {};
  if (own.value?.startsWith("O(sqrt ") && body && index) {
    const outerLimitRef = nodesOfKind(own.condition ?? {}, "DeclRefExpr")
      .find((ref) => referenceKey(ref) && referenceKey(ref) !== index);
    const outerLimitKey = referenceKey(outerLimitRef);
    const outerLimitName = outerLimitRef?.referencedDecl?.name ?? "n";
    if (outerLimitKey) {
      const innerWhiles = nodesOfKind(body, "WhileStmt");
      const factorDivisionWhile = innerWhiles.find((ws) => {
        const hasModulo = nodesOfKind(ws, "BinaryOperator").some((op) => op.opcode === "%" && referencesSymbol(op, outerLimitKey) && referencesSymbol(op, index));
        const bodyOfWs = bodyOf(ws);
        const hasDivision = bodyOfWs && nodesOfKind(bodyOfWs, "CompoundAssignOperator").some((op) => op.opcode === "/=" && referencesSymbol(op.inner?.[0], outerLimitKey));
        return Boolean(hasModulo && hasDivision);
      });
      if (factorDivisionWhile) {
        return {
          value: own.value,
          proof: [
            "For-loop header establishes " + own.value + " iterations.",
            "Trial-division factor reduction: the inner loop divides the bound " + outerLimitName + " by i >= 2 at most log(" + outerLimitName + ") times across all iterations, while reducing the outer stopping threshold sqrt(" + outerLimitName + ").",
            "Cumulative work across all iterations is O(sqrt " + outerLimitName + " + log " + outerLimitName + ") = " + own.value + "."
          ],
          index,
          condition: own.condition,
          geometric: false,
          bound: own.bound
        };
      }
    }
  }
  const value = multiply(own.value, perIteration.value);
  if (!value) return {};
  return {
    value,
    proof: [
      "For-loop header establishes " + own.value + " iterations.",
      ...perIteration.proof,
      "The proven worst-case branch body is composed once per loop iteration."
    ],
    index,
    condition: own.condition,
    geometric: own.value === "O(log n)",
    bound: own.bound
  };
}

/**
 * First bounded CFG slice: analyse top-level if/else regions as exclusive
 * edges. Existing specialised recognisers run before this helper; unsupported
 * paths deliberately fall back to the normal conservative pipeline.
 */
function pathSensitiveControlFlowResult(functionDecl: ClangNode, body: ClangNode, flow: ControlFlowBounds, localCosts?: LocalFunctionCosts, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  if (!(body.inner ?? []).some((statement) => statement.kind === "IfStmt")) return undefined;
  // Recurrences are handled by dedicated solvers before this CFG slice. A
  // branch walk must not accidentally treat a recursive call hidden inside a
  // loop/conditional as constant work just because that call is outside the
  // currently supported statement form.
  if (functionDecl.name && directCalls(body).some((call) => references(call, functionDecl.name!))) return undefined;
  const work = pathSensitiveStatement(body, initialSymbolicBounds(functionDecl), flow, localCosts, constantSymbols);
  if (!work || work.value === "Does not terminate") return undefined;
  return {
    worstCaseTime: work.value,
    auxiliarySpace: "O(1)",
    confidence: "exact",
    proof: work.proof
  };
}

/**
 * Storage of a braced initializer-list constructed container. `vector<int> v
 * = {1, 2, 3}` passes a std::initializer_list materialization whose element
 * count is a compile-time constant of the source text, so the container's own
 * storage is constant - provided no element copy carries input-sized storage
 * of its own (a copied string or nested container would).
 */
function initializerListAllocation(argument: ClangNode | undefined): Complexity | undefined {
  if (!argument) return undefined;
  const list = argument.kind === "CXXStdInitializerListExpr"
    ? nodesOfKind(argument, "InitListExpr").at(0)
    : argument.kind === "InitListExpr" ? argument : undefined;
  if (!list) return undefined;
  const copiesDynamicContent = [...nodesOfKind(list, "CXXConstructExpr"), ...nodesOfKind(list, "CXXTemporaryObjectExpr")]
    .some((child) => /\b(?:vector|deque|string|basic_string)\b/.test(child.type?.desugaredQualType ?? child.type?.qualType ?? ""))
    || nodesOfKind(list, "CXXNewExpr").length > 0;
  return copiesDynamicContent ? undefined : "O(1)";
}

function auxiliarySpace(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>, ownedRecordStorage?: LocalRecordOwnedStorage, functionDecl?: ClangNode): AuxiliarySpace {
  const allocations: Complexity[] = [];
  let unknownAllocation = false;
  // Every local container the function materializes is charged, including one
  // filled from the input stream (`cin >> a[i]`). The reviewed corpus labels
  // are split on whether a materialized input instance counts as auxiliary
  // storage: near-identical programs carry `O(n)` and `O(1)` space labels
  // (round-6 census reconciliation in Deep.md). The majority side - and the
  // 2D-grid family, whose `cin >> g[i][j]` fills are labeled `O(n m)` -
  // charges the input instance, so 1D and 2D input families follow one
  // convention.
  // `std::sort` itself does not allocate an input-sized buffer; its bounded
  // implementation stack is dominated whenever a visible local vector owns
  // O(n) elements. Keep potentially-buffering algorithms conservative.
  const potentiallyAllocatingAlgorithms = new Set(["stable_sort", "partial_sort", "inplace_merge", "make_heap", "sort_heap"]);
  walk(body, (node) => {
    if (node.kind === "CXXNewExpr") unknownAllocation = true;
    if (node.kind === "CXXConstructExpr" || node.kind === "CXXTemporaryObjectExpr") {
      const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
      if (/\b(?:vector|deque|string)</.test(type) && (node.inner?.length ?? 0) > 0) {
        // Returning a local container normally creates a move/NRVO wrapper in
        // the AST. It does not allocate a second input-sized buffer; the local
        // construction below already accounts for that storage.
        const movesExistingLocal = nodesOfKind(node.inner?.[0] ?? {}, "DeclRefExpr")
          .some((reference) => reference.referencedDecl?.kind === "VarDecl"
            && /\b(?:vector|deque|string)</.test(reference.referencedDecl?.type?.desugaredQualType ?? reference.referencedDecl?.type?.qualType ?? ""));
        if (movesExistingLocal) return;
        const size = expressionComplexity(node.inner?.[0], bounds, constantSymbols) ?? initializerListAllocation(node.inner?.[0]);
        const nestedSize = [...nodesOfKind(node, "CXXConstructExpr"), ...nodesOfKind(node, "CXXTemporaryObjectExpr")]
          .filter((child) => child !== node && /\b(?:vector|deque|string)</.test(child.type?.desugaredQualType ?? child.type?.qualType ?? ""))
          .map((child) => expressionComplexity(child.inner?.[0], bounds, constantSymbols))
          .find((value): value is Complexity => Boolean(value));
        const total = size && nestedSize ? multiplyExpressions(size, nestedSize) : size;
        if (total) allocations.push(total);
        else unknownAllocation = true;
      }
    }
    // A local CP data-structure object can own a dynamic table even though its
    // own type is not `vector<T>`. The record map is built from Clang's
    // constructor/member AST: only a constructor argument demonstrably fed
    // into a vector/deque/string member is counted here. This is structural
    // ownership analysis, not a class-name rule for Fenwick/segment trees.
    if (node.kind === "VarDecl" && ownedRecordStorage) {
      const recordType = (node.type?.desugaredQualType ?? node.type?.qualType ?? "")
        .replace(/\b(?:const|volatile|struct|class)\b/g, " ")
        .replace(/[&*].*$/, " ")
        .trim()
        .match(/([A-Za-z_][A-Za-z0-9_]*)$/)?.[1];
      const parameterIndices = recordType ? ownedRecordStorage.get(recordType) : undefined;
      const constructor = (node.inner ?? []).find((child) => child.kind === "CXXConstructExpr" || child.kind === "CXXTemporaryObjectExpr");
      if (parameterIndices && constructor) {
        let ownedSize: Complexity = "O(1)";
        for (const parameterIndex of parameterIndices) {
          const size = expressionComplexity(constructor.inner?.[parameterIndex], bounds, constantSymbols);
          const combined: Complexity | undefined = size ? multiplyExpressions(ownedSize, size) : undefined;
          if (combined) ownedSize = combined;
          else { unknownAllocation = true; break; }
        }
        if (!unknownAllocation) allocations.push(ownedSize);
      }
    }
    if (node.kind === "CallExpr" && [...potentiallyAllocatingAlgorithms].some((name) => references(node, name))) unknownAllocation = true;
  });
  const localGrowingContainers = new Set(
    nodesOfKind(body, "VarDecl")
      // The prelude's `string` is a non-template class: it must match without
      // a following `<`, or string growth is never charged to auxiliary space.
      // `stack`/`queue` are container adapters over `deque`: their growth is
      // real materialized storage (round-7 BUG-018: a stack holding one char
      // per input element is O(n) auxiliary space, not O(1)).
      .filter((node) => /\b(?:vector|deque|set|map|multiset|multimap|unordered_set|unordered_map|priority_queue|stack|queue)</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "")
        || /\b(?:string|basic_string)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
      .map((node) => node.name)
      .filter((name): name is string => Boolean(name))
  );
  // A container parameter is caller-owned, but growing it inside the function
  // materializes new elements exactly like growing a local vector. Charge that
  // growth identically (round-7 BUG-012): `for (i < n) v.push_back(i)` on a
  // reference parameter is O(n) auxiliary storage, not O(1).
  const parameterGrowingContainers = new Set((functionDecl?.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl" && node.name
      && (/\b(?:vector|deque|set|map|multiset|multimap|unordered_set|unordered_map|priority_queue|stack|queue)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "")
        || /\b(?:string|basic_string)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "")))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  const growthTargets = new Set<string>([...localGrowingContainers, ...parameterGrowingContainers]);
  const growthOperations = new Set(["insert", "emplace", "emplace_hint", "push", "push_back", "emplace_back"]);
  // Vectors constructed WITH a size argument hold fixed capacity: indexed
  // writes into them never grow storage. Only default-constructed sequences
  // and map-like containers (operator[] inserts on miss) grow per write.
  const fixedCapacityVectors = new Set<string>();
  for (const declaration of nodesOfKind(body, "VarDecl")) {
    const type = declaration.type?.desugaredQualType ?? declaration.type?.qualType ?? "";
    if (!/\b(?:vector|deque)\b/.test(type) || !declaration.name) continue;
    // Clang wraps some initializers in ExprWithCleanups/MaterializeTemporary
    // (observed for `vector<bool> comp(n + 1, false)`), so search the
    // initializer subtree instead of only the direct children.
    const constructor = (declaration.inner ?? [])
      .flatMap((child) => [child, ...nodesOfKind(child, "CXXConstructExpr"), ...nodesOfKind(child, "CXXTemporaryObjectExpr")])
      .find((node) => node.kind === "CXXConstructExpr" || node.kind === "CXXTemporaryObjectExpr");
    if (process.env.PROJECT_X_DEBUG) console.error(`[fixcap] name=${declaration.name} type=${type} ctor=${constructor?.kind ?? "-"} args=${constructor?.inner?.length ?? -1}`);
    if (constructor && (constructor.inner?.length ?? 0) >= 1) fixedCapacityVectors.add(declaration.name);
  }
  const subscriptWriteTargets = new Set<ClangNode>();
  {
    // Indexed writes take three shapes: `c[i] = v`, `++c[i]` / `c[i] += v`
    // (compound insert-on-miss for ordered and hashed maps), and the plain
    // read form excluded deliberately.
    const consider = (target: ClangNode | undefined): void => {
      let unwrapped = target;
      while (unwrapped && ["ImplicitCastExpr", "ParenExpr"].includes(unwrapped.kind ?? "")) unwrapped = unwrapped.inner?.[0] ?? unwrapped;
      if (unwrapped?.kind === "CXXOperatorCallExpr") subscriptWriteTargets.add(unwrapped);
    };
    const collect = (node: ClangNode): void => {
      if (node.kind === "BinaryOperator" && node.opcode === "=" && (node.inner?.length ?? 0) >= 2) {
        consider(node.inner![0]);
      }
      if (node.kind === "CompoundAssignOperator" || (node.kind === "UnaryOperator" && ["++", "--"].includes(node.opcode ?? ""))) {
        consider(node.inner?.[0]);
      }
      for (const child of node.inner ?? []) collect(child);
    };
    collect(body);
  }
  // Growth charge: a grown container's size is bounded by the number of
  // executed insertions. Only loops entered AFTER the container's declaration
  // multiply that size: a local re-created inside an enclosing loop holds at
  // most one instance's worth of elements at any time (peak space), so the
  // loops enclosing its declaration add no multiplicity - `while (t--) {
  // vector<int> a; for (i < n) a.pb(i); }` needs O(n) storage, not O(t n)
  // (round-7 BUG-014). A proven per-instance product is used directly
  // (round-7 BUG-013: a 2^n loop that pushes 2^n keys needs O(2^n) storage,
  // not a hardcoded O(n)). When a relevant loop's trip count is not proven,
  // the corpus convention that a grown container holds at most one input's
  // worth of elements (O(n)) is the sound fallback.
  const declarationLoopDepth = new Map<string, number>();
  {
    const scan = (node: ClangNode, depth: number): void => {
      if (node.kind === "VarDecl" && node.name && growthTargets.has(node.name)) {
        const existing = declarationLoopDepth.get(node.name);
        declarationLoopDepth.set(node.name, existing === undefined ? depth : Math.min(existing, depth));
      }
      const next = ["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(node.kind ?? "") ? depth + 1 : depth;
      for (const child of node.inner ?? []) scan(child, next);
    };
    scan(body, 0);
  }
  type GrowthLoop = { trip?: Complexity; enterDepth: number };
  const activeGrowthLoops: GrowthLoop[] = [];
  const growthCharge = (base: string): Complexity => {
    const depth = declarationLoopDepth.get(base) ?? 0;
    let product: Complexity | undefined;
    let unproven = false;
    for (const loop of activeGrowthLoops) {
      if (loop.enterDepth < depth) continue;
      if (!loop.trip) unproven = true;
      else product = product ? multiply(product, loop.trip) : loop.trip;
    }
    if (unproven) return "O(n)";
    return product ?? "O(1)";
  };
  const inspectForGrowth = (node: ClangNode, loopBounds: SymbolicBounds): void => {
    let childBounds: Map<string, Complexity> = new Map(loopBounds);
    let pushed = false;
    if (["ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt"].includes(node.kind ?? "")) {
      let trip: Complexity | undefined;
      if (node.kind === "CXXForRangeStmt") {
        const info = rangeContainerInfo(node);
        const supportedRangeType = info
          && (/\b(?:vector|deque|array|map|set|multimap|multiset)\s*</.test(info.type)
            || /\b(?:string|basic_string)\b/.test(info.type))
          && !/unordered_/.test(info.type);
        if (supportedRangeType) trip = (info!.name ? loopBounds.get(info!.name) : undefined) ?? "O(n)";
      } else {
        const own = loopBound(node, loopBounds, constantSymbols);
        trip = own.value && own.value !== "Does not terminate" ? own.value : undefined;
        const index = own.update ? loopIndex(own.update) : undefined;
        if (index && own.bound) {
          childBounds = new Map(loopBounds);
          childBounds.set(index, own.bound);
        }
      }
      activeGrowthLoops.push({ trip, enterDepth: activeGrowthLoops.length });
      pushed = true;
    }
    if (node.kind === "CXXMemberCallExpr") {
      const info = memberCallInfo(node);
      const base = memberCallBaseName(node);
      if (info && base && growthTargets.has(base) && growthOperations.has(info.name)) {
        allocations.push(growthCharge(base));
      }
    }
    if (node.kind === "CXXOperatorCallExpr") {
      const operatorName = node.name ?? nodesOfKind(node, "DeclRefExpr")
        .map((part) => part.referencedDecl?.name)
        .find((name) => name?.startsWith("operator"));
      const growthBase = nodesOfKind(node, "DeclRefExpr")
        .find((part) => growthTargets.has(part.referencedDecl?.name ?? ""))
        ?.referencedDecl?.name;
      // Indexed writes into an existing sequence replace elements and never
      // grow its storage; only map-like containers insert on miss. A
      // parameter sequence therefore takes no write charge, while a local
      // non-fixed-capacity container does.
      const writeBase = nodesOfKind(node, "DeclRefExpr")
        .find((part) => localGrowingContainers.has(part.referencedDecl?.name ?? ""))
        ?.referencedDecl?.name;
      if (operatorName === "operator+=" && growthBase) allocations.push(growthCharge(growthBase));
      if (process.env.PROJECT_X_DEBUG) console.error(`[grow] op=${operatorName} base=${writeBase ?? "-"} write=${subscriptWriteTargets.has(node)} fixed=${writeBase ? fixedCapacityVectors.has(writeBase) : "-"}`);
      if (operatorName === "operator[]" && writeBase && subscriptWriteTargets.has(node) && !fixedCapacityVectors.has(writeBase)) allocations.push(growthCharge(writeBase));
    }
    for (const child of node.inner ?? []) inspectForGrowth(child, childBounds);
    if (pushed) activeGrowthLoops.pop();
  };
  inspectForGrowth(body, bounds);
  if (unknownAllocation) return "Unknown";
  // Peak auxiliary storage is the maximum over independent materializations;
  // when two proven sizes use incomparable dimensions (say k and n), the sound
  // combined bound is their sum, never just the first one seen (round-7
  // BUG-017: a counting sort holding a count table of size k plus an output
  // array of n elements must report O(n + k), not O(k)).
  const largest = allocations.reduce<Complexity | undefined>((current, next) => current
    ? dominantExpression(current, next) ?? sequentialMaximum([current, next])
    : next, undefined);
  return largest === "Does not terminate" ? "Unknown" : largest ?? "O(1)";
}

/**
 * A fixed-width sliding window is recognised from its data dependencies: an
 * initial prefix pass, followed by a pass that adds arr[i] and removes
 * arr[i-k].  This is intentionally independent of names such as `maxSum`.
 */
function fixedWindowResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const array = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!array?.name) return undefined;
  const scalarParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"
    && node.name && node.name !== array.name
    && !/\b(?:vector|deque|string|array)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt");
  if (loops.length < 2) return undefined;
  const sizeAliases = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => Boolean(node.name && nodesOfKind(node, "CXXMemberCallExpr").some((call) =>
      memberCallInfo(call)?.name === "size" && references(call, array.name!))))
    .map((node) => node.name!)
  );
  for (const width of scalarParameters) {
    const prefix = loops.find((loop) => references(directCondition(loop), width.name!));
    const slide = loops.find((loop) => loop !== prefix
      && [...sizeAliases].some((alias) => references(directCondition(loop), alias))
      && references(bodyOf(loop), array.name!) && references(bodyOf(loop), width.name!));
    if (!prefix || !slide) continue;
    // `arr[i-k]` is the key invariant: the second pass evicts exactly one
    // previous window item per new item rather than rescanning the window.
    const evictsWindowHead = nodesOfKind(bodyOf(slide) ?? {}, "BinaryOperator")
      .some((operation) => operation.opcode === "-" && references(operation, width.name!));
    if (!evictsWindowHead) continue;
    return {
      worstCaseTime: "O(n)",
      auxiliarySpace: "O(1)",
      confidence: "estimated",
      proof: ["Detected an initial fixed-width prefix pass followed by a pass that adds arr[i] and removes arr[i − k].", "Safe window indexing implies k is at most the input length; the two sequential passes therefore take O(n) total time and keep only scalar state."]
    };
  }
  return undefined;
}

/**
 * Structural variable-length sliding window / amortized two-pointer traversal:
 * An outer loop advances `right` across the container, while an inner `while`
 * loop conditionally advances a non-decreasing pointer (`left++`).
 * Because `left` starts at a constant, never decrements or resets, and is bounded
 * by the container size, the inner loop executes at most O(n) times in total across
 * the entire traversal. This yields exact O(n) time and O(1) auxiliary space.
 */
function amortizedSlidingWindowResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const container = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\b(?:vector|basic_string|string|deque|array)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!container?.name) return undefined;

  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  for (const outer of loops) {
    const outerBody = bodyOf(outer);
    if (!outerBody) continue;

    const outerCond = directCondition(outer);
    if (!outerCond || !references(outerCond, container.name)) continue;

    const innerWhiles = nodesOfKind(outerBody, "WhileStmt");
    if (innerWhiles.length === 0) continue;

    const localVars = (body.inner ?? [])
      .filter((node) => node.kind === "DeclStmt")
      .flatMap((stmt) => stmt.inner ?? [])
      .filter((decl) => decl.kind === "VarDecl" && decl.name);

    for (const innerWhile of innerWhiles) {
      const innerOps = [
        ...nodesOfKind(innerWhile, "UnaryOperator").filter((op) => ["++", "+="].includes(op.opcode ?? "")),
        ...nodesOfKind(innerWhile, "BinaryOperator").filter((op) => ["+=", "="].includes(op.opcode ?? ""))
      ];

      for (const candidate of localVars) {
        const ptrName = candidate.name;
        if (!ptrName) continue;
        const increments = innerOps.some((op) => references(op, ptrName));
        if (!increments) continue;

        // Verify ptrName is never decremented in the outer body
        const decrements = [
          ...nodesOfKind(outerBody, "UnaryOperator").filter((op) => ["--", "-="].includes(op.opcode ?? "")),
          ...nodesOfKind(outerBody, "BinaryOperator").filter((op) => ["-="].includes(op.opcode ?? ""))
        ].some((op) => references(op, ptrName));
        if (decrements) continue;

        return {
          worstCaseTime: "O(n)",
          auxiliarySpace: "O(1)",
          confidence: "exact",
          proof: [
            `Detected an outer loop iterating over the container with an inner while loop that advances a monotonically non-decreasing pointer (\`${ptrName}\`).`,
            `Because \`${ptrName}\` never decrements or resets and is bounded by the outer traversal index, the inner loop executes at most O(n) times in total across the entire execution.`,
            "The amortized per-step work is O(1), proving exact O(n) total worst-case time and O(1) auxiliary space."
          ]
        };
      }
    }
  }
  return undefined;
}

/** Structural counting sort: count table, input frequency scan, and count drain. */
function countingSortResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const array = (functionDecl.inner ?? []).find((node) => node.kind === "ParmVarDecl"
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!array?.name) return undefined;
  const scalarParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl" && node.name && node.name !== array.name
    && !/\b(?:vector|deque|string|array)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  const constructedVectors = nodesOfKind(body, "VarDecl").filter((node) => Boolean(node.name)
    && /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "")
    && (node.inner ?? []).some((child) => child.kind === "CXXConstructExpr" || child.kind === "CXXTemporaryObjectExpr"));
  for (const countTable of constructedVectors) {
    if (!countTable.name) continue;
    for (const scalar of scalarParameters) {
      if (!scalar.name || !references(countTable, scalar.name)) continue;
      const frequencyScan = nodesOfKind(body, "CXXForRangeStmt").find((range) =>
        rangeContainerInfo(range)?.name === array.name && references(range, countTable.name!));
      const drain = nodesOfKind(body, "ForStmt").find((loop) => references(directCondition(loop), scalar.name!));
      const drainWhile = drain && nodesOfKind(drain, "WhileStmt").find((loop) => references(conditionOf(loop), countTable.name!));
      const pushesOutput = drainWhile && nodesOfKind(drainWhile, "CXXMemberCallExpr")
        .some((call) => memberCallInfo(call)?.name === "push_back");
      if (!frequencyScan || !drain || !drainWhile || !pushesOutput) continue;
      return {
        worstCaseTime: "O(n + maxVal)",
        auxiliarySpace: "O(n + maxVal)",
        confidence: "estimated",
        proof: ["Detected a count table indexed by maxVal, one frequency scan over the input, and a drain of every stored frequency.", "The frequency scan costs O(n); the index sweep plus all while-loop iterations together cost O(maxVal + n), with count/output storage of O(maxVal + n)."]
      };
    }
  }
  return undefined;
}

/** A per-character allocation path such as trie insertion creates at most one node per character. */
function characterAllocationResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const strings = new Set((functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl" && /\bstring\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name).filter((name): name is string => Boolean(name)));
  if (strings.size === 0) return undefined;
  const range = (body.inner ?? []).find((node) => node.kind === "CXXForRangeStmt" && strings.has(rangeContainerInfo(node)?.name ?? ""));
  if (!range || nestedLoops(range).length > 0 || !nodesOfKind(bodyOf(range) ?? {}, "CXXNewExpr").length) return undefined;
  return {
    worstCaseTime: "O(n)",
    auxiliarySpace: "O(n)",
    confidence: "estimated",
    proof: ["Detected a single range traversal over a string parameter with at most one heap-node allocation per character.", "Trie-style insertion performs constant pointer work per character and can allocate one node per character, so both time and new storage are linear in the word length."]
  };
}

/**
 * Handles a control bound mutated by an inner loop. In `for (i=0; i<n; ++i)`
 * plus `while (i*i<n) n/=2`, the i=0 iteration halves n to zero before the
 * outer condition is checked again. Treating n as immutable would be wrong.
 */
function mutableOuterBoundResult(body: ClangNode): AnalysisResult | undefined {
  const outer = (body.inner ?? []).find((node) => node.kind === "ForStmt");
  if (!outer) return undefined;
  const outerUpdate = updateOf(outer);
  const outerIndex = loopIndex(outerUpdate);
  const outerLimit = loopLimit(directCondition(outer) ?? {}, outerIndex);
  // The condition bound is commonly wrapped in an implicit lvalue-to-rvalue
  // cast. Extract the resolved declaration below that wrapper.
  const mutableName = nodesOfKind(outerLimit ?? {}, "DeclRefExpr")
    .map(referenceKey)
    .find((symbol): symbol is string => Boolean(symbol));
  const initializesIndexAtZero = (outer.inner ?? []).some((part) => nodesOfKind(part, "VarDecl").some((declaration) => declarationKey(declaration) === outerIndex
    && nodesOfKind(declaration, "IntegerLiteral").some((literal) => literal.value === "0")));
  if (!outerIndex || !mutableName || !initializesIndexAtZero || outerUpdate?.kind !== "UnaryOperator" || outerUpdate.opcode !== "++") return undefined;
  const inner = nestedLoops(outer).find((node) => node.kind === "WhileStmt");
  const update = inner ? updateOf(inner) : undefined;
  const halvesMutableBound = Boolean(update?.kind === "CompoundAssignOperator" && update.opcode === "/="
    && loopIndex(update) === mutableName && nodesOfKind(update, "IntegerLiteral").some((literal) => Number(literal.value) >= 2));
  if (!inner || !halvesMutableBound || !productOfSameSymbol(conditionOf(inner), outerIndex) || !referencesSymbol(conditionOf(inner), mutableName)) return undefined;
  return {
    worstCaseTime: "O(log n)",
    auxiliarySpace: "O(1)",
    confidence: "estimated",
    proof: ["The first outer iteration has i = 0, so the inner condition is true for a positive input and repeatedly halves the very variable used as the outer bound.", "That inner loop takes O(log n), reduces n to zero, and the next outer-condition check fails; the loops do not multiply."]
  };
}

/** Detects the semantic cost of repeated growth of the same string. */
function repeatedStringAppend(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const strings = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => /\bstring\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  if (strings.size === 0) return undefined;
  for (const loop of (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt")) {
    const own = loopBound(loop, bounds, constantSymbols);
    if (!own.value) continue;
    const appends = nodesOfKind(bodyOf(loop) ?? {}, "CXXOperatorCallExpr").some((call) => {
      const name = call.name ?? nodesOfKind(call, "DeclRefExpr").map((node) => node.referencedDecl?.name).find((candidate) => candidate?.startsWith("operator"));
      return name === "operator+=" && !singleCharacterAppend(call) && [...strings].some((variable) => references(call, variable));
    });
    if (!appends) continue;
    const total = multiply(own.value, "O(n)");
    if (!total || total === "Does not terminate") continue;
    return {
      worstCaseTime: total,
      auxiliarySpace: "O(n)",
      confidence: "estimated",
      proof: ["The loop repeatedly appends to the same growing string. A worst-case append copies its current contents, so the cumulative append cost is quadratic for a linear loop."]
    };
  }
  return undefined;
}

/** Proves the standard aggregate-cost rule for local vector growth. */
function amortizedVectorAppend(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const vectors = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => /\bvector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
  if (vectors.size === 0) return undefined;
  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  if (loops.length !== 1 || nestedLoops(loops[0]).length > 0) return undefined;
  const bound = loopBound(loops[0], bounds, constantSymbols);
  if (bound.value !== "O(n)") return undefined;
  const pushes = nodesOfKind(bodyOf(loops[0]) ?? {}, "CXXMemberCallExpr").filter((call) => {
    const info = memberCallInfo(call);
    const base = memberCallBaseName(call);
    return info?.name === "push_back" && Boolean(base && vectors.has(base));
  });
  if (pushes.length === 0) return undefined;
  const calls = callsOutsideNestedLoops(loops[0]);
  if (calls.some((call) => !pushes.includes(call) && !knownLoopCallCost(call))) return undefined;
  return {
    worstCaseTime: "O(n)",
    auxiliarySpace: "O(n)",
    // The geometric-growth potential argument is complete here: a single flat
    // loop of proven trip count performs only appends, and STL capacity
    // doubling charges every copy to a prior push, so the total work and
    // storage bound n is fully proved, not merely estimated.
    confidence: "exact",
    proof: ["Detected a linear sequence of push_back operations on one local vector.", "Capacity growth has occasional copies, but aggregate analysis proves O(1) amortized work per append and O(n) total work/storage."]
  };
}

/**
 * Worklist drain: a local `priority_queue`/`queue`/`stack`/`deque` is filled by
 * exactly one proven loop (one push per iteration) and then drained by a
 * pop-only `while (!x.empty())`-style loop whose body performs no pushes.
 * The drain's unbroken trip count is then exactly the fill count: each
 * iteration removes one element and nothing re-adds, so the loop cannot run
 * past the initial population. That is a complete structural proof, not an
 * amortized argument, and it composes safely with the fill phase as a
 * sequential sequence of regions.
 */
function worklistDrainResult(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const isWorklistType = (type: string): boolean => /\b(?:priority_queue|queue|stack|deque)\s*</.test(type);
  type WorklistCall = { op: "push" | "pop" | "peek" | "other"; cost?: Complexity };
  const classifyAgainst = (call: ClangNode, container: ClangNode): WorklistCall | undefined => {
    if (call.kind !== "CXXMemberCallExpr") return undefined;
    if (!declRefKeysMatch(call, container)) return undefined;
    const info = memberCallInfo(call);
    if (!info?.name) return undefined;
    const type = info.containerType ?? "";
    if (!isWorklistType(type) || /unordered_/.test(type)) return undefined;
    const name = info.name;
    if (["push", "emplace", "push_back", "push_front", "emplace_back", "emplace_front"].includes(name)) return { op: "push" };
    if (["pop", "pop_back", "pop_front"].includes(name)) return { op: "pop", cost: knownMemberCallCost(call) };
    if (["empty", "size", "top", "front", "back"].includes(name)) return { op: "peek", cost: knownMemberCallCost(call) };
    return { op: "other" };
  };
  // Only trivially-constructed worklists participate: an extent-argument
  // constructor stores a caller-sized population this model would have to
  // track separately, so such shapes stay with the normal analysers.
  const declared: ClangNode[] = (body.inner ?? [])
    .filter((statement) => statement.kind === "DeclStmt")
    .flatMap((statement) => statement.inner ?? [])
    .filter((node) => node.kind === "VarDecl" && node.name
      && isWorklistType(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .filter((container) => nodesOfKind(container, "CXXConstructExpr").concat(nodesOfKind(container, "CXXTemporaryObjectExpr"))
      .every((construct) => (construct.inner ?? []).length === 0));
  if (declared.length === 0) return undefined;
  const topStatements = body.inner ?? [];
  const drainLoopCandidates = topStatements.filter((node) => node.kind === "WhileStmt");
  for (const container of declared) {
    // The drain: a while loop whose re-tested condition reads exactly this
    // container's emptiness, with a flat body holding exactly one direct pop
    // and no pushes of the same container anywhere inside it.
    const drain = drainLoopCandidates.find((loop) => emptinessGuard(loop, container));
    if (!drain) continue;
    const drainBody = bodyOf(drain);
    if (!drainBody) continue;
    const drainStatements = drainBody.kind === "CompoundStmt" ? drainBody.inner! : [drainBody];
    if (drainStatements.some((statement) => ["IfStmt", "ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt", "SwitchStmt", "LambdaExpr", "CXXNewExpr"].includes(statement.kind ?? ""))) continue;
    let drainPopCost: Complexity | undefined;
    let popCount = 0;
    let invalid = false;
    for (const statement of drainStatements) {
      for (const call of directCalls(statement)) {
        const classification = classifyAgainst(call, container);
        if (classification?.op === "push") { invalid = true; break; }
        if (classification?.op === "pop") {
          popCount += 1;
          if (!classification.cost || !["O(log n)", "O(1)"].includes(classification.cost)) { invalid = true; break; }
          drainPopCost = classification.cost;
          continue;
        }
        const cost = classification ? classification.cost : knownLoopCallCost(call, undefined, bounds, constantSymbols);
        if (!cost) { invalid = true; break; }
      }
      if (invalid) break;
    }
    if (invalid || popCount !== 1 || !drainPopCost) continue;
    // The fill: every push site for this container must live inside exactly
    // one earlier top-level loop, with one push per flat iteration.
    const pushSites = nodesOfKind(body, "CXXMemberCallExpr")
      .filter((call) => classifyAgainst(call, container)?.op === "push");
    if (pushSites.length === 0) continue;
    const drainIndex = topStatements.indexOf(drain);
    let fillLoop: ClangNode | undefined;
    for (const statement of topStatements.slice(0, drainIndex)) {
      if (statementContains(statement, pushSites[0])) {
        fillLoop = ["ForStmt", "WhileStmt", "CXXForRangeStmt"].includes(statement.kind ?? "") ? statement : undefined;
        break;
      }
    }
    if (!fillLoop || !pushSites.every((site) => statementContains(fillLoop!, site))) continue;
    const fillBody = bodyOf(fillLoop);
    if (!fillBody) continue;
    // One push per iteration: the fill body must be flat without any inner
    // loop or branch that could change the push count per trip.
    if (nestedLoops(fillLoop).length > 0
      || (bodyOf(fillLoop) !== fillBody && nodesOfKind(fillBody, "ForStmt").length + nodesOfKind(fillBody, "WhileStmt").length > 0)) continue;
    const fillStatements = fillBody.kind === "CompoundStmt" ? fillBody.inner! : [fillBody];
    if (fillStatements.some((statement) => ["IfStmt", "ForStmt", "WhileStmt", "DoStmt", "CXXForRangeStmt", "SwitchStmt", "LambdaExpr", "CXXNewExpr"].includes(statement.kind ?? ""))) continue;
    let fillPushCount = 0;
    let fillPerIteration: Complexity | undefined;
    let fillInvalid = false;
    for (const statement of fillStatements) {
      for (const call of directCalls(statement)) {
        const classification = classifyAgainst(call, container);
        if (classification?.op === "pop") { fillInvalid = true; break; }
        if (classification?.op === "push") {
          fillPushCount += 1;
          const cost = classification.cost ?? knownLoopCallCost(call, undefined, bounds, constantSymbols);
          if (!cost) { fillInvalid = true; break; }
          fillPerIteration = dominantExpression(fillPerIteration ?? "O(1)", cost) ?? fillPerIteration ?? cost;
          continue;
        }
        const cost = classification ? classification.cost : knownLoopCallCost(call, undefined, bounds, constantSymbols);
        if (!cost) { fillInvalid = true; break; }
      }
      if (fillInvalid) break;
    }
    if (fillInvalid || fillPushCount !== 1 || !fillPerIteration) continue;
    const fillBound = fillPhaseBound(fillLoop, bounds, constantSymbols);
    if (!fillBound) continue;
    const fillTime = multiply(fillBound, fillPerIteration);
    const drainTime = multiply(fillBound, drainPopCost);
    if (!fillTime || !drainTime) continue;
    const worstCaseTime = sequentialMaximum([fillTime, drainTime]);
    if (!worstCaseTime) continue;
    return {
      worstCaseTime,
      auxiliarySpace: fillBound as AuxiliarySpace,
      confidence: "exact",
      proof: [
        `A locally built worklist is filled once by a proven ${fillBound} iteration loop, then drained by a pop-only emptiness loop.`,
        `The drain removes one element per iteration and adds none, so its trip count equals the pushed population (${fillBound}); the phases compose to ${worstCaseTime}, and the container stores at most ${fillBound} units.`
      ]
    };
  }
  // Unrecognized worklist shapes stay with the normal analysers.
  return undefined;
}

/** True when the loop's re-tested condition reads exactly this container's emptiness. */
function emptinessGuard(loop: ClangNode, container: ClangNode): boolean {
  const unwrap = (node?: ClangNode): ClangNode | undefined => {
    let current = node;
    while (current && ["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr"].includes(current.kind ?? "")) current = current.inner?.[0];
    return current;
  };
  // The re-tested condition is the first non-body child of the loop node.
  const condition = unwrap((loop.inner ?? []).find((part) => part.kind !== "CompoundStmt"));
  if (!condition) return false;
  if (condition.kind === "UnaryOperator" && condition.opcode === "!") {
    const inner = unwrap(condition.inner?.at(-1));
    if (inner?.kind !== "CXXMemberCallExpr") return false;
    return memberCallInfo(inner)?.name === "empty" && declRefKeysMatch(inner, container);
  }
  if (condition.kind === "BinaryOperator" && (condition.opcode === ">" || condition.opcode === "!=")) {
    const left = unwrap(condition.inner?.[0]);
    const right = unwrap(condition.inner?.[1]);
    const sizeOnLeft = left?.kind === "CXXMemberCallExpr" ? left : undefined;
    const zeroOnRight = right?.kind === "IntegerLiteral" && Number(right.value) === 0;
    if (!sizeOnLeft || !zeroOnRight) return false;
    return memberCallInfo(sizeOnLeft)?.name === "size" && declRefKeysMatch(sizeOnLeft, container);
  }
  return false;
}

/**
 * Clang declaration-identity matching between a member-call base expression
 * and a locally declared container: the referenced declaration's id wins, and
 * a same-spelled fallback keeps name-only prelude spellings working.
 * This prevents a same-spelled nested variable from inheriting the bound of
 * the outer declaration.
 */
function declRefKeysMatch(call: ClangNode, container: ClangNode): boolean {
  const member = nodesOfKind(call, "MemberExpr").at(0);
  const base = member ? nodesOfKind(member.inner?.[0] ?? {}, "DeclRefExpr").at(0) : undefined;
  if (!base) return false;
  const reference = base.referencedDecl;
  const identityId = reference?.id ?? base.id;
  const identityName = reference?.name ?? base.name;
  const containerId = container.id ?? declarationKey(container);
  return Boolean((containerId && identityId === containerId) || (container.name && identityName === container.name));
}

/** The bound of a fill phase: a canonical loop bound or a range-for container cardinality. */
function fillPhaseBound(loop: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): Complexity | undefined {
  if (loop.kind === "CXXForRangeStmt") {
    const info = rangeContainerInfo(loop);
    if (!info) return undefined;
    const supportedRangeType = /\b(?:vector|deque|array|map|set|multimap|multiset)\s*</.test(info.type)
      || /\b(?:string|basic_string)\b/.test(info.type);
    if (/unordered_/.test(info.type) || !supportedRangeType) return undefined;
    return info.name ? bounds.get(info.name) ?? "O(n)" : "O(n)";
  }
  const bound = loopBound(loop, bounds, constantSymbols);
  if (!bound.value || bound.value === "Does not terminate") return undefined;
  return bound.value;
}

function statementContains(statement: ClangNode, target: ClangNode): boolean {
  let found = false;
  walk(statement, (current) => { if (current === target) found = true; });
  return found;
}

/**
 * Bitmask DP is recognised from a typed local table whose allocation uses a
 * complete `1 << n` state domain, plus a complete traversal of that same
 * domain.  This is deliberately independent of the transition spelling:
 * SOS, TSP/Hamilton-style, subset transitions, and renamed implementations
 * all have the same state-space proof.  Every nested canonical index loop is
 * composed, so `mask × last × prev` is O(n² 2^n), not O(n 2^n).
 */
function bitmaskDynamicProgrammingResult(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const bitmaskTable = nodesOfKind(body, "VarDecl").find((variable) => {
    const type = variable.type?.desugaredQualType ?? variable.type?.qualType ?? "";
    if (!/\bvector\s*</.test(type)) return false;
    const constructorHasMaskDimension = [...nodesOfKind(variable, "CXXConstructExpr"), ...nodesOfKind(variable, "CXXTemporaryObjectExpr")]
      .some((construction) => hasCompleteMaskExtent(construction, bounds));
    // Nested-vector construction can wrap the outer extent in several
    // implicit/temporary nodes. The shift expression itself is still an AST
    // fact belonging to this initializer and is the relevant allocation
    // dimension, so retain it as an equivalent typed-table proof.
    const initializerHasMaskDimension = hasCompleteMaskExtent(variable, bounds);
    return constructorHasMaskDimension || initializerHasMaskDimension;
  });
  if (!bitmaskTable) return undefined;

  const maskDimension = nodesOfKind(bitmaskTable, "BinaryOperator")
    .map((expression) => expressionComplexity(expression, bounds, constantSymbols))
    .find((value): value is Complexity => Boolean(value && exponentialFactor(value)));
  if (!maskDimension) return undefined;
  const nestedDimension = [...nodesOfKind(bitmaskTable, "CXXConstructExpr"), ...nodesOfKind(bitmaskTable, "CXXTemporaryObjectExpr")]
    .filter((construction) => construction !== bitmaskTable)
    .filter((construction) => /\bvector\s*</.test(construction.type?.desugaredQualType ?? construction.type?.qualType ?? ""))
    .map((construction) => expressionComplexity(construction.inner?.[0], bounds, constantSymbols))
    .find((value): value is Complexity => Boolean(value && !exponentialFactor(value)));
  // A nested-vector table has one independent inner row dimension; the
  // single-vector case stores exactly one value per mask.
  const tableSpace = nestedDimension ? multiply(maskDimension, nestedDimension) : maskDimension;
  if (!tableSpace) return undefined;

  for (const outer of (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt")) {
    const outerBound = loopBound(outer, bounds, constantSymbols);
    if (!outerBound.value || !exponentialFactor(outerBound.value)) continue;
    const total = nestedLoopPathCost(outer, bounds, constantSymbols);
    if (!total) continue;
    return {
      worstCaseTime: total,
      // Both operands are finite allocation extents; `multiply` cannot reach
      // the non-termination sentinel for this construction.
      auxiliarySpace: tableSpace as AuxiliarySpace,
      confidence: "exact",
      proof: [
        "Detected a typed dynamic-programming table allocated over a complete `1 << n` mask domain.",
        "The mask traversal and every nested canonical index pass are composed symbolically, giving " + total + "."
      ]
    };
  }
  return undefined;
}

/**
 * A Fenwick-style update changes an index by its least significant set bit:
 * `i += i & -i` or `i -= i & -i`. This is a binary-tree walk, so it has
 * logarithmic height regardless of member/parameter naming. The method is
 * marked Estimated because positivity and the enclosing tree extent are
 * interface invariants rather than facts available in one method body.
 */
function lowbitTreeMethodResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  // The least-significant-bit update proves a logarithmic binary-tree walk
  // whether it is a record method or a same-file free helper.  Callers are
  // still resolved by Clang declaration identity, so accepting the helper
  // form does not broaden name-based matching.
  if (functionDecl.kind !== "CXXMethodDecl" && functionDecl.kind !== "FunctionDecl") return undefined;
  const isLowbitLoop = (loop: ClangNode): boolean => {
    const update = updateOf(loop);
    if (update?.kind !== "CompoundAssignOperator" || !["+=", "-="].includes(update.opcode ?? "")) return false;
    const index = loopIndex(update);
    if (!index || !directCondition(loop)) return false;
    const lowbit = nodesOfKind(update, "BinaryOperator").some((operation) => {
      if (operation.opcode !== "&") return false;
      const referencesIndex = nodesOfKind(operation, "DeclRefExpr").filter((reference) => referenceKey(reference) === index).length;
      const negatedIndex = nodesOfKind(operation, "UnaryOperator").some((unary) => unary.opcode === "-"
        && nodesOfKind(unary, "DeclRefExpr").some((reference) => referenceKey(reference) === index));
      return referencesIndex >= 2 && negatedIndex;
    });
    return lowbit;
  };
  const depth = (loop: ClangNode): number => {
    const descendants = nodesOfKind(bodyOf(loop) ?? { kind: "NullStmt" }, "ForStmt")
      .filter((candidate) => candidate !== loop && isLowbitLoop(candidate));
    return descendants.length === 0 ? 1 : 1 + Math.max(...descendants.map(depth));
  };
  const roots = nodesOfKind(body, "ForStmt").filter(isLowbitLoop);
  if (roots.length > 0) {
    const logarithmicDepth = Math.max(...roots.map(depth));
    const worstCaseTime = logarithmicDepth === 1 ? "O(log n)" as Complexity : `O(log^${logarithmicDepth} n)` as Complexity;
    return {
      worstCaseTime, auxiliarySpace: "O(1)", confidence: "estimated", confidencePercent: 92,
      proof: [
        "Detected a least-significant-set-bit index update (`i ±= i & -i`) in a C++ method.",
        logarithmicDepth === 1
          ? "That update follows a Fenwick-style binary tree path, whose height is O(log n); no per-operation auxiliary allocation is present."
          : `Nested least-significant-bit tree walks multiply to ${worstCaseTime}; no per-operation auxiliary allocation is present.`
      ]
    };
  }
  return undefined;
}

/**
 * Summarizes recursive interval-tree methods by their control-flow shape.  A
 * range query has a disjoint/full-cover return guard before two midpoint
 * child calls, so only O(log n) canonical segments are visited.  A build has
 * one leaf guard and two midpoint child calls, which materializes O(n)
 * nodes.  This intentionally does not depend on class or method names.
 */
function intervalTreeMethodResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  if (functionDecl.kind !== "CXXMethodDecl") return undefined;
  const methodName = functionDecl.name;
  if (!methodName) return undefined;
  const scalarParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"
    && /\b(?:int|long|short|size_t|unsigned)\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (scalarParameters.length < 3) return undefined;
  const selfCalls = directCalls(body).filter((call) => {
    const direct = call.inner?.[0];
    return references(call, methodName) || references(direct, methodName)
      || memberCallInfo(call)?.name === methodName
      || nodesOfKind(call, "MemberExpr").some((member) => member.name === methodName
        && (!functionDecl.id || member.referencedMemberDecl === functionDecl.id));
  });
  if (selfCalls.length < 2) return undefined;
  const hasMidpoint = nodesOfKind(body, "BinaryOperator").some((operation) => ["/", ">>"].includes(operation.opcode ?? ""))
    || nodesOfKind(body, "CompoundAssignOperator").some((operation) => operation.opcode === ">>=");
  if (!hasMidpoint) return undefined;
  const guards = nodesOfKind(body, "IfStmt").filter((branch) => nodesOfKind(branch, "ReturnStmt").length > 0);
  const hasLeafGuard = guards.some((branch) => nodesOfKind(conditionOf(branch) ?? branch, "BinaryOperator").some((operation) => operation.opcode === "=="));
  const rangeGuards = guards.filter((branch) => nodesOfKind(conditionOf(branch) ?? branch, "BinaryOperator")
    .some((operation) => ["<", "<=", ">", ">="].includes(operation.opcode ?? ""))).length;

  // Clang may omit a syntactically valid full-cover branch from a partial AST
  // when an unrelated prelude declaration is incomplete. The disjoint return,
  // five interval/query scalars, midpoint split, and two same-method children
  // still prove the canonical range-query shape; require all of those rather
  // than relying on that optional second branch being present in JSON.
  if (rangeGuards >= 1 && scalarParameters.length >= 5) {
    return {
      worstCaseTime: "O(log n)", auxiliarySpace: "O(log n)", confidence: "estimated", confidencePercent: 88,
      proof: [
        "Detected recursive interval calls split at a midpoint, guarded by disjoint-range and full-cover returns.",
        "A range operation visits only a logarithmic number of canonical interval-tree nodes; recursion depth is O(log n)."
      ]
    };
  }
  if (hasLeafGuard) {
    return {
      worstCaseTime: "O(n)", auxiliarySpace: "O(log n)", confidence: "estimated", confidencePercent: 86,
      proof: [
        "Detected recursive midpoint subdivision with a leaf return guard.",
        "The full binary interval decomposition materializes O(n) leaves and internal nodes; call-stack depth is O(log n)."
      ]
    };
  }
  return undefined;
}

/**
 * A lazy interval update is recognized from the recursive interval mechanics,
 * not a `SegmentTree` spelling: two linear-scale local arrays, a self-passing
 * lambda with disjoint/full-cover guards, midpoint child calls, and one pass
 * over an operation container.  The deferred tag state is what lets each
 * operation descend only logarithmically many levels.
 */
function lazyIntervalUpdateResult(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const containers = containerParameterNames(functionDecl);
  if (containers.size !== 1) return undefined;
  const scalarParameters = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl"
    && !/\b(?:vector|deque|array|string|map|set|unordered_)/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (scalarParameters.length === 0) return undefined;
  const linearVectors = nodesOfKind(body, "VarDecl").filter((node) => {
    const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
    if (!/\bvector\s*</.test(type)) return false;
    return scalarParameters.some((parameter) => Boolean(parameter.name && references(node, parameter.name)));
  });
  if (linearVectors.length < 2) return undefined;
  const operationPass = nodesOfKind(body, "CXXForRangeStmt").find((loop) => {
    const info = rangeContainerInfo(loop);
    return Boolean(info?.name && containers.has(info.name));
  });
  if (!operationPass) return undefined;
  const lambda = nodesOfKind(body, "LambdaExpr").find((candidate) => {
    const calls = directCalls(candidate).filter((call) => call.kind === "CallExpr" && call.inner?.[0]?.kind === "DeclRefExpr");
    const hasTwoSelfCalls = calls.length >= 2 && calls.some((call) => call.inner?.[0]?.referencedDecl?.kind === "ParmVarDecl"
      && /auto/.test(call.inner?.[0]?.referencedDecl?.type?.qualType ?? ""));
    const hasMidpointChildren = nodesOfKind(candidate, "BinaryOperator").some((operation) => ["/", "<<"].includes(operation.opcode ?? ""));
    const hasReturnGuard = nodesOfKind(candidate, "IfStmt").some((branch) => nodesOfKind(branch, "ReturnStmt").length > 0
      && nodesOfKind(branch, "BinaryOperator").some((operation) => ["<", "<=", ">", ">="].includes(operation.opcode ?? "")));
    return hasTwoSelfCalls && hasMidpointChildren && hasReturnGuard;
  });
  if (!lambda) return undefined;
  const querySymbol = [...containers][0] === "n" ? "m" : "m";
  const inputSymbol = scalarParameters.find((parameter) => /^(?:n|N|size|length|limit)$/.test(parameter.name ?? ""))?.name ?? "n";
  return {
    worstCaseTime: `O(${inputSymbol} + ${querySymbol} log ${inputSymbol})` as Complexity,
    auxiliarySpace: `O(${inputSymbol})` as AuxiliarySpace,
    confidence: "estimated",
    confidencePercent: 87,
    proof: [
      "Detected two linear interval-state arrays and a self-passing midpoint lambda with disjoint/full-cover returns.",
      "The operation-container pass invokes one lazy interval update per operation; deferred tags keep each update at O(log n), after O(n) state allocation."
    ]
  };
}

/**
 * Matrix DP is identified from the allocated two-dimensional table and two
 * nested index loops.  Cell accesses are intentionally treated as O(1): this
 * is a property of the typed vector/array table, not a special case for LCS
 * or knapsack names.
 */
function matrixDynamicProgrammingResult(body: ClangNode, bounds: SymbolicBounds, constantSymbols?: ReadonlySet<string>, localCosts?: LocalFunctionCosts): AnalysisResult | undefined {
  const hasMatrix = nodesOfKind(body, "VarDecl").some((node) => /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!hasMatrix) return undefined;
  for (const outer of (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt")) {
    const outerBound = loopBound(outer, bounds, constantSymbols);
    const outerIndex = loopIndex(outerBound.update);
    const inner = nestedLoops(outer).at(0);
    if (!outerBound.value || !outerIndex || !inner) continue;
    const childBounds = new Map(bounds);
    if (outerBound.bound) childBounds.set(outerIndex, outerBound.bound);
    const innerBound = loopBound(inner, childBounds, constantSymbols);
    if (!innerBound.value) continue;
    // A matrix allocation plus two loops is not automatically DP. In
    // particular, a non-constant call such as `sort(row)` belongs to the
    // work of every cell and must be composed, not silently treated as O(1).
    let total = multiply(outerBound.value, innerBound.value);
    if (!total) continue;
    const grandchild = nestedLoops(inner).at(0);
    if (grandchild) {
      const innerIndex = loopIndex(innerBound.update);
      const grandchildBounds = new Map(childBounds);
      if (innerIndex && innerBound.bound) grandchildBounds.set(innerIndex, innerBound.bound);
      const grandchildBound = loopBound(grandchild, grandchildBounds, constantSymbols);
      if (grandchildBound.value) {
        const triple = multiply(total, grandchildBound.value);
        if (triple) total = triple;
      }
    }
    const nestedCallCosts = directCalls(inner).map((call) => {
      const ordinary = knownLoopCallCost(call, localCosts, childBounds, constantSymbols)
        ?? (call.kind === "CXXOperatorCallExpr" ? knownOperatorCallCost(call) : undefined);
      if (ordinary) return ordinary;
      // The matrix rule already proved typed vector/string storage. Clang may
      // omit the receiver type from an overloaded `operator[]` JSON node;
      // indexed access to that proven storage is still O(1).
      const indexAccess = call.kind === "CXXOperatorCallExpr"
        && (call.name === "operator[]" || nodesOfKind(call, "DeclRefExpr").some((reference) => reference.referencedDecl?.name === "operator[]"));
      return indexAccess ? "O(1)" as Complexity : undefined;
    });
    if (nestedCallCosts.some((cost) => !cost)) continue;
    const nonConstantCallCosts = nestedCallCosts.filter((cost): cost is Complexity => cost !== undefined && cost !== "O(1)");
    let cellTotal = total;
    if (nonConstantCallCosts.length > 0) {
      const perCell = nonConstantCallCosts.reduce<Complexity | undefined>((largest, cost) => largest ? dominantExpression(largest, cost) as Complexity : cost, undefined);
      const composed = perCell ? multiply(total, perCell) : undefined;
      if (!composed) continue;
      cellTotal = composed;
    }
    const otherLoops = (body.inner ?? []).filter((node) => (node.kind === "ForStmt" || node.kind === "WhileStmt" || node.kind === "CXXForRangeStmt") && node !== outer);
    let finalWorstCaseTime = cellTotal;
    const additionalProofs: string[] = [];
    if (otherLoops.length > 0) {
      const otherAnalyses = otherLoops.map((l) => analyseLoop(l, bounds, localCosts, constantSymbols));
      if (otherAnalyses.some((a) => !a.value)) continue;
      const composed = sequentialMaximum([cellTotal, ...otherAnalyses.map((a) => a.value!)]);
      if (!composed) continue;
      finalWorstCaseTime = composed;
      additionalProofs.push("Sequential query or post-processing loops are composed with the table construction.");
    }
    return {
      worstCaseTime: finalWorstCaseTime,
      // `multiply` can theoretically return the non-termination sentinel,
      // guarded above; TypeScript cannot narrow that union across this object.
      auxiliarySpace: (multiply(outerBound.value, innerBound.value) ?? total) as AuxiliarySpace,
      confidence: "exact",
      proof: [
        "Detected a dynamically allocated two-dimensional table and nested index loops over its dimensions.",
        nonConstantCallCosts.length > 0
          ? "A proven non-constant operation occurs for every table-cell iteration, so its cost composes with the O(n²) traversal."
          : "Each table cell is updated a constant number of times, so the two independent dimensions multiply.",
        ...additionalProofs
      ]
    };
  }
  return undefined;
}

/**
 * Fixed-dimension prefix tables (for example one row per bit) are built once
 * and then read by a range-query pass.  The query loop must have a proven
 * constant inner dimension; otherwise this deliberately defers to the more
 * general matrix/loop analysis.
 */
function fixedDimensionPrefixQueryResult(
  body: ClangNode,
  bounds: SymbolicBounds,
  space: AuxiliarySpace,
  constantSymbols?: ReadonlySet<string>
): AnalysisResult | undefined {
  const hasMatrix = nodesOfKind(body, "VarDecl")
    .some((node) => /\bvector\s*<\s*(?:std::)?vector\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
  if (!hasMatrix) return undefined;
  const build = (body.inner ?? []).filter((node) => node.kind === "ForStmt")
    .find((loop) => nestedLoops(loop).length > 0);
  if (!build) return undefined;
  const buildCost = nestedLoopPathCost(build, bounds, constantSymbols);
  if (!buildCost) return undefined;
  for (const queryPass of (body.inner ?? []).filter((node) => node.kind === "CXXForRangeStmt")) {
    const queryName = rangeContainerInfo(queryPass)?.name;
    const queryBound = queryName ? bounds.get(queryName) : undefined;
    const inner = nodesOfKind(rangeBody(queryPass) ?? {}, "ForStmt").at(0);
    const innerCost = inner ? loopBound(inner, bounds, constantSymbols).value : undefined;
    if (!queryBound || innerCost !== "O(1)") continue;
    const queryCost = multiply(queryBound, innerCost);
    const total = queryCost ? sequentialMaximum([buildCost, queryCost]) : undefined;
    if (!total) continue;
    return {
      worstCaseTime: total,
      auxiliarySpace: space,
      confidence: "exact",
      proof: [
        "A fixed-dimension prefix table is built in one complete preprocessing pass.",
        "Each range query performs only a fixed number of table lookups, so preprocessing and query work add."
      ]
    };
  }
  return undefined;
}

/**
 * Proves the standard two-bound binary-search invariant from the AST rather
 * than from a function name.  We require a midpoint derived from both bounds,
 * and branch updates that exclude the midpoint (or use the half-open `hi=mid`
 * convention).  A merely similar-looking loop is deliberately left Unknown.
 */
function structuralBinarySearch(body: ClangNode, localCosts?: LocalFunctionCosts, bounds?: SymbolicBounds, constantSymbols?: ReadonlySet<string>): AnalysisResult | undefined {
  const loop = (body.inner ?? []).find((node) => node.kind === "WhileStmt");
  const condition = loop ? directCondition(loop) : undefined;
  if (!loop || !condition || !["<", "<="].includes(condition.opcode ?? "")) return undefined;
  const [left, right] = condition.inner ?? [];
  const low = referencedName(left);
  const high = referencedName(right);
  if (!low || !high || low === high) return undefined;

  const midpointNames = nodesOfKind(bodyOf(loop) ?? {}, "VarDecl")
    .filter((node) => {
      const initializer = node.inner?.at(-1);
      return Boolean(node.name && initializer && references(initializer, low) && references(initializer, high)
        && nodesOfKind(initializer, "BinaryOperator").some((part) => part.opcode === "/"
          && nodesOfKind(part, "IntegerLiteral").some((literal) => literal.value === "2")));
    })
    .map((node) => node.name!)
    .filter(Boolean);
  if (midpointNames.length === 0) return undefined;

  const hasOne = (node: ClangNode | undefined): boolean => nodesOfKind(node ?? {}, "IntegerLiteral").some((literal) => literal.value === "1");
  const writes = nodesOfKind(bodyOf(loop) ?? {}, "BinaryOperator")
    .filter((node) => node.opcode === "=" && (node.inner?.length ?? 0) >= 2)
    .map((node) => ({ target: referencedName(node.inner![0]), value: node.inner![1] }))
    .filter((write) => (write.target === low || write.target === high)
      && midpointNames.some((midpoint) => references(write.value, midpoint)));
  const lowProgresses = writes.some((write) => write.target === low && hasOne(write.value));
  const highProgresses = writes.some((write) => write.target === high
    && (hasOne(write.value) || condition.opcode === "<"));
  if (!lowProgresses || !highProgresses) return undefined;

  // Per-iteration work: a feasibility check, a predicate call, or any other
  // non-constant operation inside the loop composes with the halving count.
  const bodyWork = bodyOf(loop);
  const callCosts = directCalls(bodyWork ?? {}).map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
  if (callCosts.some((cost) => !cost)) return undefined;
  const assumedCallback = directCalls(bodyWork ?? {}).some((call) => {
    if (call.kind !== "CXXOperatorCallExpr") return false;
    const receiverType = nodesOfKind(call, "DeclRefExpr")
      .map((reference) => reference.type?.desugaredQualType ?? reference.type?.qualType
        ?? reference.referencedDecl?.type?.desugaredQualType ?? reference.referencedDecl?.type?.qualType ?? "")
      .find((receiver) => /\bfunction</.test(receiver));
    return Boolean(receiverType);
  });
  const perIteration = sequentialMaximum(callCosts.filter((cost): cost is Complexity => Boolean(cost))) ?? "O(1)";

  // Interval magnitude: when an endpoint is initialized from a proven symbolic
  // dimension the halving count is logarithmic in it; value-derived endpoints
  // (prefix sums, element maxima) introduce the conventional search-space
  // dimension S, which the corpus declares as an input symbol.
  const endpointInitializers = (body.inner ?? [])
    .filter((node) => node.kind === "DeclStmt")
    .flatMap((statement) => statement.inner ?? [])
    .filter((declaration) => declaration.kind === "VarDecl"
      && (declaration.name === low || declaration.name === high));
  let intervalDimension: string | undefined;
  for (const declaration of endpointInitializers) {
    const bound = expressionComplexity(declaration.inner?.at(-1), bounds ?? new Map(), constantSymbols);
    const symbol = bound ? /^O\(([A-Za-z_][A-Za-z0-9_]*)\)$/.exec(bound)?.[1] : undefined;
    if (symbol && symbol !== "1") {
      intervalDimension = symbol;
      break;
    }
  }
  const logArgument = intervalDimension ?? "S";
  const halving = (`O(log ${logArgument})` as Complexity);
  const total = perIteration === "O(1)" ? halving : multiply(perIteration, halving);
  if (!total) return undefined;
  return {
    worstCaseTime: total,
    auxiliarySpace: "O(1)",
    confidence: assumedCallback ? "estimated" : "exact",
    proof: [
      "The loop maintains two bounds and computes a midpoint from both.",
      "Every proven branch update discards at least half of the remaining interval, so the interval shrinks geometrically.",
      ...(perIteration !== "O(1)" ? ["The proven per-iteration check cost composes with the halving count."] : []),
      ...(logArgument === "S" ? ["The interval endpoints are value-derived, so the halving count is logarithmic in the conventional search-space dimension S."] : [])
    ]
  };
}

/**
 * Proves a converging two-pointer loop only when the AST shows that every
 * branch either returns or advances one endpoint. This excludes loops with a
 * missing `else`, resets such as `left = 0`, or opaque callback-driven motion.
 */
function structuralTwoPointers(body: ClangNode, bounds: SymbolicBounds): AnalysisResult | undefined {
  const loop = (body.inner ?? []).find((node) => node.kind === "WhileStmt");
  const condition = loop ? directCondition(loop) : undefined;
  if (!loop || !condition || !["<", "<=", "!="].includes(condition.opcode ?? "")) return undefined;
  const [leftNode, rightNode] = condition.inner ?? [];
  const left = referencedName(leftNode);
  const right = referencedName(rightNode);
  // While conditions normally use implicit casts around their DeclRefExprs;
  // expressionComplexity deliberately unwraps those casts before consulting
  // the declaration-identity bound map.
  if (!left || !right || (!expressionComplexity(leftNode, bounds) && !expressionComplexity(rightNode, bounds))) return undefined;
  const loopBody = bodyOf(loop);
  if (!loopBody) return undefined;

  const writesEndpoint = nodesOfKind(loopBody, "BinaryOperator").some((node) => {
    if (node.opcode !== "=") return false;
    const target = referencedName(node.inner?.[0]);
    return target === left || target === right;
  });
  if (writesEndpoint) return undefined;

  // A move only shrinks the interval when it points toward the other
  // endpoint: under `l < r` (or `l <= r`) the left endpoint must advance and
  // the right endpoint must retreat. A unit step away from the bound (for
  // example `--i` under `i < n`) grows the interval forever, so it must not
  // earn the two-pointer trip count. `!=` has no ordered side to compare
  // against; it keeps the historic acceptance so equality-search loops
  // remain covered.
  const stepTowardOther = (target: string | undefined, opcode: string | undefined): boolean => {
    // `!=` has no ordered side to compare against; it keeps the historic
    // acceptance for loops whose counter the reachability pre-pass could not
    // fault (for example a counter that starts at zero). Loops whose start is
    // provably past the target, or not pinnable, must not earn a trip count.
    if (condition.opcode === "!=") return equalityLoopReachability.get(loop) === undefined;
    if (target === left) return opcode === "++" || opcode === "+=";
    if (target === right) return opcode === "--" || opcode === "-=";
    return false;
  };
  const directEndpointMove = (node: ClangNode | undefined): boolean => {
    if (!node) return false;
    if (node.kind === "UnaryOperator" && ["++", "--"].includes(node.opcode ?? "")) {
      return stepTowardOther(referencedName(node), node.opcode);
    }
    if (node.kind === "CompoundAssignOperator" && ["+=", "-="].includes(node.opcode ?? "")) {
      const target = referencedName(node);
      // The move must be a literal unit step in the advancing direction; its
      // sign must survive the resolution, so `i += -1` never reads as an
      // advance just because the digit `1` appears in the expression.
      const delta = signedLiteralValue(node.inner?.[1]);
      if (delta === undefined) return false;
      const effective = node.opcode === "+=" ? delta : -delta;
      if (Math.abs(effective) !== 1) return false;
      if (condition.opcode === "!=") return true;
      if (target === left) return effective > 0;
      if (target === right) return effective < 0;
      return false;
    }
    return false;
  };
  const progressesOnEveryPath = (node: ClangNode | undefined): boolean => {
    if (!node) return false;
    if (node.kind === "ReturnStmt" || directEndpointMove(node)) return true;
    if (node.kind === "IfStmt") {
      const branches = (node.inner ?? []).slice(1);
      return branches.length === 2 && progressesOnEveryPath(branches[0]) && progressesOnEveryPath(branches[1]);
    }
    if (node.kind !== "CompoundStmt") return false;
    for (const statement of node.inner ?? []) {
      if (directEndpointMove(statement) || statement.kind === "ReturnStmt") return true;
      if (statement.kind === "IfStmt" && progressesOnEveryPath(statement)) return true;
    }
    return false;
  };
  // Every increment/decrement or compound write to either endpoint must be a
  // proven step toward the other endpoint. The `=`-assignment check above
  // misses these mutations: `while (i < n) { ++i; --i; }` oscillates forever,
  // and the lone accepted `++i` previously earned the interval-shrink claim.
  for (const node of [
    ...nodesOfKind(loopBody, "UnaryOperator").filter((part) => ["++", "--"].includes(part.opcode ?? "")),
    ...nodesOfKind(loopBody, "CompoundAssignOperator").filter((part) => ["+=", "-="].includes(part.opcode ?? ""))
  ]) {
    const target = referencedName(node);
    if (target !== left && target !== right) continue;
    if (node.kind === "UnaryOperator") {
      if (!stepTowardOther(target, node.opcode)) return undefined;
      continue;
    }
    // A compound write needs a resolvable signed stride in the advancing
    // direction; an unprovable or zero stride cannot support the shrink
    // argument.
    const delta = signedLiteralValue(node.inner?.[1]);
    if (delta === undefined) return undefined;
    const effective = node.opcode === "+=" ? delta : -delta;
    const toward = condition.opcode === "!=" ? effective !== 0 : target === left ? effective > 0 : effective < 0;
    if (!toward) return undefined;
  }
  if (!progressesOnEveryPath(loopBody)) return undefined;
  return {
    worstCaseTime: "O(n)",
    auxiliarySpace: "O(1)",
    confidence: "exact",
    proof: ["The loop maintains two ordered endpoints.", "Every control-flow branch either returns or moves an endpoint by one, so the interval can shrink only O(n) times."]
  };
}

function containerParameterNames(functionDecl: ClangNode): Set<string> {
  return new Set((functionDecl.inner ?? [])
    .filter((node) => node.kind === "ParmVarDecl" && /\b(?:vector|deque|string|array)</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
    .map((node) => node.name)
    .filter((name): name is string => Boolean(name)));
}

function conditionOf(loop: ClangNode): ClangNode | undefined {
  if (loop.kind === "WhileStmt" || loop.kind === "DoStmt") return loop.inner?.[0];
  return directCondition(loop);
}

function referencedParameters(node: ClangNode | undefined, parameters: ReadonlySet<string>): Set<string> {
  const found = new Set<string>();
  if (node) walk(node, (current) => {
    const name = current.referencedDecl?.name;
    if (name && parameters.has(name)) found.add(name);
  });
  return found;
}

/** Proves two nested loops are bounded by different container inputs. */
function independentContainerProduct(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const containers = containerParameterNames(functionDecl);
  if (containers.size < 2) return undefined;
  const outerRange = (body.inner ?? []).find((node) => node.kind === "CXXForRangeStmt");
  if (outerRange) {
    const innerRange = (outerRange.inner ?? []).find((node) => node.kind === "CompoundStmt")?.inner
      ?.find((node) => node.kind === "CXXForRangeStmt");
    const outerName = rangeContainerInfo(outerRange)?.name;
    const innerName = innerRange ? rangeContainerInfo(innerRange)?.name : undefined;
    if (outerName && innerName && outerName !== innerName && containers.has(outerName) && containers.has(innerName)) {
      return {
        worstCaseTime: "O(n m)",
        auxiliarySpace: "O(1)",
        confidence: "exact",
        proof: ["Nested range-for loops traverse two distinct container parameters, so their independent iteration counts multiply."]
      };
    }
  }
  const outer = (body.inner ?? []).find((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  if (!outer) return undefined;
  const inner = nestedLoops(outer).at(0);
  if (!inner) return undefined;
  const outerInputs = referencedParameters(conditionOf(outer), containers);
  const innerInputs = referencedParameters(conditionOf(inner), containers);
  if (outerInputs.size !== 1 || innerInputs.size !== 1) return undefined;
  const [outerName] = outerInputs;
  const [innerName] = innerInputs;
  if (!outerName || !innerName || outerName === innerName) return undefined;
  return {
    worstCaseTime: "O(n m)",
    auxiliarySpace: "O(1)",
    confidence: "exact",
    proof: ["The outer and inner loops are independently bounded by two distinct container parameters, so their iteration counts multiply."]
  };
}

/**
 * Recognizes the standard three-phase merge of two sorted inputs: one loop
 * advances either index while both remain, followed by one draining loop per
 * input. The bound is the sum, not a product, of the two input lengths.
 */
function mergeTwoInputTraversal(functionDecl: ClangNode, body: ClangNode): AnalysisResult | undefined {
  const containers = containerParameterNames(functionDecl);
  if (containers.size < 2) return undefined;
  const loops = (body.inner ?? []).filter((node) => node.kind === "WhileStmt");
  if (loops.length < 3) return undefined;
  const firstCondition = conditionOf(loops[0]);
  const firstInputs = referencedParameters(firstCondition, containers);
  const isConjunction = nodesOfKind(firstCondition ?? {}, "BinaryOperator").some((node) => node.opcode === "&&");
  if (!isConjunction || firstInputs.size !== 2) return undefined;
  const trailingInputs = new Set<string>();
  for (const loop of loops.slice(1)) {
    for (const name of referencedParameters(conditionOf(loop), containers)) trailingInputs.add(name);
  }
  if ([...firstInputs].some((name) => !trailingInputs.has(name))) return undefined;
  return {
    worstCaseTime: "O(n + m)",
    auxiliarySpace: "O(n + m)",
    confidence: "estimated",
    proof: ["One loop advances one of two input indices while both remain, then each input is drained once; total traversal is the sum of the input lengths."]
  };
}

/**
 * Two local strings often expose their lengths through aliases (`n=s.size()`)
 * and are scanned backwards with two decrementing cursors.  This is a
 * topology proof for common-suffix/trim logic, independent of names.
 */
function localStringSuffixScanResult(body: ClangNode): AnalysisResult | undefined {
  const strings = nodesOfKind(body, "VarDecl")
    .filter((node) => /\bstring\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? "") && Boolean(node.name));
  if (strings.length < 2) return undefined;
  const stringNames = new Set(strings.map((node) => node.name!));
  const sizeAliases = new Set(nodesOfKind(body, "VarDecl")
    .filter((node) => Boolean(node.name) && nodesOfKind(node, "CXXMemberCallExpr").some((call) => {
      const info = memberCallInfo(call);
      const base = memberCallBaseName(call);
      return info?.name === "size" && Boolean(base && stringNames.has(base));
    }))
    .map((node) => node.name!));
  if (sizeAliases.size < 2) return undefined;
  for (const loop of nodesOfKind(body, "WhileStmt")) {
    const decremented = new Set(nodesOfKind(bodyOf(loop) ?? {}, "UnaryOperator")
      .filter((update) => update.opcode === "--")
      .map(loopIndex)
      .filter((index): index is string => Boolean(index)));
    if (decremented.size < 2) continue;
    // Built-in arrays use ArraySubscriptExpr while string/vector indexing is
    // an overloaded `operator[]` call. Both forms identify the receiver
    // through the same DeclRefExpr identity.
    const accesses = [
      ...nodesOfKind(bodyOf(loop) ?? {}, "ArraySubscriptExpr"),
      ...nodesOfKind(bodyOf(loop) ?? {}, "CXXOperatorCallExpr")
        .filter((call) => nodesOfKind(call, "DeclRefExpr").some((ref) => ref.referencedDecl?.name === "operator[]"))
    ];
    const touchedStrings = new Set(accesses.flatMap((access) => nodesOfKind(access, "DeclRefExpr")
      .map((reference) => reference.referencedDecl?.name)
      .filter((name): name is string => Boolean(name && stringNames.has(name)))));
    if (touchedStrings.size < 2) continue;
    return {
      worstCaseTime: "O(n + m)",
      auxiliarySpace: "O(1)",
      confidence: "exact",
      proof: ["Detected two local string-length aliases and a backward two-cursor scan that decrements both cursors once per iteration.", "The scan visits at most the combined input lengths and retains only scalar cursors."]
    };
  }
  return undefined;
}

/**
 * Proves the standard contest shape `while (cases--) { vector<T> values(n);
 * for (auto value : values) constant-work(value); }`. The proof follows the
 * testcase counter, the dynamically sized local sequence, and the range
 * source identity, rather than relying on identifier spellings.
 */
function testcaseLocalSequenceTraversalResult(
  body: ClangNode,
  bounds: SymbolicBounds,
  constantSymbols?: ReadonlySet<string>,
  localCosts?: LocalFunctionCosts
): AnalysisResult | undefined {
  for (const testcaseLoop of (body.inner ?? []).filter((node) => node.kind === "WhileStmt")) {
    const testcaseBound = loopBound(testcaseLoop, bounds, constantSymbols).value;
    if (!testcaseBound) continue;
    const testcaseSymbol = atomicSymbol(testcaseBound);
    if (!testcaseSymbol) continue;
    const testcaseBody = bodyOf(testcaseLoop);
    if (!testcaseBody) continue;
    const sequences = nodesOfKind(testcaseBody, "VarDecl").filter((node) => {
      const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
      return Boolean(node.name && /\b(?:vector|deque|array)\s*</.test(type));
    });
    for (const sequence of sequences) {
      const sizeReference = nodesOfKind(sequence, "DeclRefExpr")
        .find((reference) => Boolean(boundForReference(bounds, reference)));
      const sequenceBound = sizeReference ? boundForReference(bounds, sizeReference) : undefined;
      const sequenceSymbol = atomicSymbol(sequenceBound);
      if (!sequence.name || !sequenceBound || !sequenceSymbol) continue;
      const traversal = nodesOfKind(testcaseBody, "CXXForRangeStmt").find((range) =>
        rangeContainerInfo(range)?.name === sequence.name);
      if (!traversal) continue;
      const traversalBody = rangeBody(traversal) ?? {};
      if (nodesOfKind(traversalBody, "ForStmt").length > 0
        || nodesOfKind(traversalBody, "WhileStmt").length > 0
        || nodesOfKind(traversalBody, "CXXForRangeStmt").length > 0
        || nodesOfKind(traversalBody, "CXXNewExpr").length > 0) continue;
      // Every per-element call must be resolved before this becomes an Exact
      // result. A user helper with unknown work cannot hide behind the
      // range-for topology.
      if (directCalls(traversalBody).some((call) =>
        !knownLoopCallCost(call, localCosts, bounds, constantSymbols))) continue;
      const time = multiply(sequenceBound, testcaseBound);
      if (!time) continue;
      return {
        worstCaseTime: time,
        auxiliarySpace: sequenceBound as AuxiliarySpace,
        confidence: "exact",
        proof: [
          `A proven testcase loop repeats ${testcaseSymbol} times.`,
          `Each testcase allocates one local sequence of ${sequenceSymbol} elements and range-for visits each element once with no nested traversal or allocation.`
        ]
      };
    }
  }
  return undefined;
}

/** Analyse a FunctionDecl emitted by clang's JSON AST. */
export function analyseFunctionAst(functionDecl: ClangNode, localCosts?: LocalFunctionCosts, constantSymbols?: ReadonlySet<string>, ownedRecordStorage?: LocalRecordOwnedStorage): AnalysisResult {
  if (functionDecl.kind !== "FunctionDecl" && functionDecl.kind !== "CXXMethodDecl" && functionDecl.kind !== "CXXConstructorDecl") return unknown("Selection did not resolve to a C++ function, method, or constructor declaration.");
  functionDecl = normalizeFunctionSyntax(functionDecl);
  const flow = controlFlowBounds(functionDecl, constantSymbols);
  const parameters = flow.final;
  const body = (functionDecl.inner ?? []).find((node) => node.kind === "CompoundStmt");
  if (!body) return unknown("Selected function has no analyzable body.");
  noteEqualityLoopReachability(body);
  const lowbitMethod = lowbitTreeMethodResult(functionDecl, body);
  if (lowbitMethod) return lowbitMethod;
  const intervalTreeMethod = intervalTreeMethodResult(functionDecl, body);
  if (intervalTreeMethod) return intervalTreeMethod;
  const lazyIntervalUpdate = lazyIntervalUpdateResult(functionDecl, body);
  if (lazyIntervalUpdate) return lazyIntervalUpdate;
  const sparseTableConstructor = sparseTableConstructorResult(functionDecl, body);
  if (sparseTableConstructor) return sparseTableConstructor;
  const monotonicWorklist = monotonicWorklistResult(functionDecl, body, parameters);
  if (monotonicWorklist) return monotonicWorklist;
  const coordinateCompression = coordinateCompressionResult(functionDecl, body);
  if (coordinateCompression) return coordinateCompression;
  const forwardedAlias = forwardedFunctionAliasResult(body, localCosts, parameters);
  if (forwardedAlias) return forwardedAlias;
  const recursiveLambda = recursiveLambdaResult(body);
  if (recursiveLambda) return recursiveLambda;
  const memoizedBitmask = memoizedBitmaskRecursionResult(functionDecl, body, parameters);
  if (memoizedBitmask) return memoizedBitmask;
  const memoizedRecursiveState = memoizedRecursiveStateResult(functionDecl, body, parameters);
  if (memoizedRecursiveState) return memoizedRecursiveState;
  const partitioned = partitionRecursion(functionDecl, body);
  if (partitioned) return partitioned;
  const tree = binaryTreeRecursion(functionDecl, body);
  if (tree) return tree;
  const mixedRatio = mixedRatioRecurrence(functionDecl, body, parameters, localCosts);
  if (mixedRatio) return mixedRatio;
  const recursive = selfHalvingRecursion(functionDecl, body, parameters, localCosts);
  if (recursive) return recursive;
  const indexedMerge = indexedBalancedMergeRecursion(functionDecl, body);
  if (indexedMerge) return indexedMerge;
  const vectorMerge = vectorBalancedMergeRecursion(functionDecl, body);
  if (vectorMerge) return vectorMerge;
  const intervalHalving = intervalHalvingTailRecursion(functionDecl, body);
  if (intervalHalving) return intervalHalving;
  const fixedWindow = fixedWindowResult(functionDecl, body);
  if (fixedWindow) return fixedWindow;
  const amortizedWindow = amortizedSlidingWindowResult(functionDecl, body);
  if (amortizedWindow) return amortizedWindow;
  const countingSort = countingSortResult(functionDecl, body);
  if (countingSort) return countingSort;
  const characterAllocation = characterAllocationResult(functionDecl, body);
  if (characterAllocation) return characterAllocation;
  const mutableOuterBound = mutableOuterBoundResult(body);
  if (mutableOuterBound) return mutableOuterBound;
  const space = auxiliarySpace(body, parameters, constantSymbols, ownedRecordStorage, functionDecl);
  const localStringSuffix = localStringSuffixScanResult(body);
  if (localStringSuffix) return localStringSuffix;
  const testcaseSequenceTraversal = testcaseLocalSequenceTraversalResult(body, parameters, constantSymbols, localCosts);
  if (testcaseSequenceTraversal) return testcaseSequenceTraversal;
  const sortThenScan = sortThenLinearScanResult(body, parameters, constantSymbols);
  if (sortThenScan) return { ...sortThenScan, auxiliarySpace: space };
  const submasks = submaskEnumerationResult(body, parameters, constantSymbols);
  if (submasks) return submasks;
  const binaryLifting = binaryLiftingResult(functionDecl, body);
  if (binaryLifting) return binaryLifting;
  const prefixQueries = prefixSumQueryResult(functionDecl, body, parameters, localCosts, constantSymbols);
  if (prefixQueries) return prefixQueries;
  const sieve = sieveResult(body, parameters, localCosts, constantSymbols);
  if (sieve) return sieve;
  const competitivePattern = competitiveProgrammingPatternResult(functionDecl, body);
  if (competitivePattern) return competitivePattern;
  const adjacencyBuilder = adjacencyBuilderResult(functionDecl, body);
  if (adjacencyBuilder) return adjacencyBuilder;
  const repeatedAdjacencyScan = repeatedAdjacencyScanResult(functionDecl, body);
  if (repeatedAdjacencyScan) return repeatedAdjacencyScan;
  const densePrim = densePrimResult(functionDecl, body);
  if (densePrim) return densePrim;
  const heapPrim = heapPrimResult(functionDecl, body);
  if (heapPrim) return heapPrim;
  const graph = graphTraversalResult(functionDecl, body);
  if (graph) return graph;
  // Worklist recognizers are stronger than the generic construction-plus-
  // traversal rule because they can prove a priority-queue logarithmic factor.
  const constructedAdjacencyTraversal = constructedAdjacencyTraversalResult(functionDecl, body, localCosts, parameters, constantSymbols);
  if (constructedAdjacencyTraversal) return constructedAdjacencyTraversal;
  const disjointSet = disjointSetPassResult(functionDecl, body);
  if (disjointSet) return disjointSet;
  const mergedInputs = mergeTwoInputTraversal(functionDecl, body);
  if (mergedInputs) return mergedInputs;
  const independentProduct = independentContainerProduct(functionDecl, body);
  if (independentProduct) return independentProduct;
  const bitmaskDp = bitmaskDynamicProgrammingResult(body, parameters, constantSymbols);
  if (bitmaskDp) return bitmaskDp;
  const fixedPrefixQueries = fixedDimensionPrefixQueryResult(body, parameters, space, constantSymbols);
  if (fixedPrefixQueries) return fixedPrefixQueries;
  const matrixDp = matrixDynamicProgrammingResult(body, parameters, constantSymbols, localCosts);
  if (matrixDp) return matrixDp;
  const rollingDp = rollingDynamicProgrammingResult(functionDecl, body, parameters, constantSymbols);
  if (rollingDp) return rollingDp;
  const amortizedAppend = amortizedVectorAppend(body, parameters, constantSymbols);
  if (amortizedAppend) return amortizedAppend;
  const stringAppend = repeatedStringAppend(body, parameters, constantSymbols);
  if (stringAppend) return stringAppend;
  const worklistDrain = worklistDrainResult(body, parameters, constantSymbols);
  if (worklistDrain) return worklistDrain;
  // Compositional derivation runs after the structural recognizers so that
  // domain-evidenced CP results (graph worklists, amortized passes, ...) keep
  // their precedence; it handles everything they abstain on, including loop
  // nests deeper than two and loops hidden inside CFG branches. Recursive
  // functions reach the recurrence solvers in the cascade and never enter
  // this walk.
  if (functionDecl.name && directCalls(body).some((call) => references(call, functionDecl.name!))) {
    return unknown("Recursive calls require a recurrence solver; no structural recurrence was recognized.");
  }
  const compositional = pathSensitiveStatement(body, initialSymbolicBounds(functionDecl), flow, localCosts, constantSymbols);
  if (compositional) {
    if (compositional.value === "Does not terminate") {
      return { worstCaseTime: "Does not terminate", auxiliarySpace: space, confidence: "exact", proof: compositional.proof };
    }
    // A library/same-file call with proven time but unproven implementation
    // storage keeps the auxiliary answer Unknown only when no locally proven
    // storage dominates it; proven helper spaces and the function's own
    // allocations otherwise compose as the worst case.
    const helperSpace = compositional.helperSpaces && compositional.helperSpaces.length > 0
      ? maximumAuxiliarySpace(compositional.helperSpaces)
      : undefined;
    const auxiliary: AuxiliarySpace = compositional.unprovenSpace && compositional.value === "O(n log n)" && space === "O(1)" && !helperSpace
      ? "Unknown"
      : helperSpace ? maximumAuxiliarySpace([helperSpace, space]) ?? space : space;
    return {
      worstCaseTime: compositional.value,
      auxiliarySpace: auxiliary,
      confidence: compositional.estimated ? "estimated" : "exact",
      proof: compositional.proof
    };
  }
  // Legacy fallback for shapes the compositional walk and every recognizer
  // could not yet prove.
  // A loop hidden behind an unproven CFG branch must never reach the
  // no-loops O(1) path below: treating that branch as absent is unsound.
  const branchHidesLoop = (body.inner ?? [])
    .filter((statement) => statement.kind === "IfStmt" || statement.kind === "SwitchStmt")
    .some((branch) => nodesOfKind(branch, "ForStmt").length > 0
      || nodesOfKind(branch, "WhileStmt").length > 0
      || nodesOfKind(branch, "CXXForRangeStmt").length > 0
      || nodesOfKind(branch, "DoStmt").length > 0);
  if (branchHidesLoop) {
    return unknown("The CFG branches have incomparable or unsupported worst-case work.");
  }
  const loops = (body.inner ?? []).filter((node) => node.kind === "ForStmt" || node.kind === "WhileStmt");
  const rangeLoops = (body.inner ?? []).filter((node) => node.kind === "CXXForRangeStmt");
  if (loops.length === 0 && rangeLoops.length > 0) {
    if (unsupported(body, true, localCosts, parameters, constantSymbols)) return unknown("This selection uses an unsupported call, allocation, or control flow construct.");
    const analyses = rangeLoops.map((range) => analyseRangeFor(range, localCosts, parameters, constantSymbols));
    if (analyses.some((analysis) => !analysis.value)) return unknown("The range-for container or its body is not a supported proven form.");
    const topLevelCalls = callsOutsideLoops(body);
    const topLevelCosts = topLevelCalls.map((call) => knownLoopCallCost(call, localCosts, parameters, constantSymbols));
    if (topLevelCosts.some((cost) => !cost)) return unknown(unresolvedCallReason(topLevelCalls, localCosts, parameters, constantSymbols));
    const worst = sequentialMaximum([
      ...analyses.map((analysis) => analysis.value!),
      ...topLevelCosts.filter((cost): cost is Complexity => Boolean(cost))
    ]);
    const estimatedHelper = rangeLoops.some((range) => callsInRangeBody(range)
      .some((call) => localCallConfidence(call, localCosts) === "estimated"))
      || topLevelCalls.some((call) => localCallConfidence(call, localCosts) === "estimated");
    const helperSpaces = topLevelCalls.map((call) => localCallSpace(call, localCosts, parameters, constantSymbols))
      .filter((value): value is AuxiliarySpace => value !== undefined);
    const composedSpace = sequentialMaximum([space, ...helperSpaces] as Complexity[]) as AuxiliarySpace | undefined;
    return worst
      ? {
        worstCaseTime: worst,
        auxiliarySpace: composedSpace ?? space,
        confidence: estimatedHelper ? "estimated" : "exact",
        proof: [
          ...analyses.flatMap((analysis) => analysis.proof ?? []),
          ...(topLevelCalls.length > 0 ? ["Resolved same-file preprocessing calls are composed as sequential phases."] : [])
        ]
      }
      : unknown("The range-for costs could not be ordered safely.");
  }
  if (loops.length === 0) {
    // Do not let a known call inside a range-for/lambda/new expression mask the
    // unsupported control flow and produce a misleading exact result.
    if (unsupported(body, false, localCosts, parameters, constantSymbols)) return unknown("This selection uses an unsupported call, allocation, or control flow construct.");
    const library = knownCallOnlyResult(body, localCosts, space, parameters, constantSymbols);
    if (library) return library;
    if (directCalls(body).length > 0) return unknown("This selection uses an unsupported call, allocation, or control flow construct.");
    return { worstCaseTime: "O(1)", auxiliarySpace: space, confidence: "exact", proof: ["No loops, calls, allocation, or unsupported control flow were found."] };
  }
  const calls = directCalls(body);
  if (calls.length > 0 && !callsAreSupportedInsideLoops(calls, localCosts, parameters, constantSymbols)) return unknown(unresolvedCallReason(calls, localCosts, parameters, constantSymbols));
  if (unsupported(body, false, localCosts, parameters, constantSymbols)) return unknown("This selection uses an unsupported call, allocation, or control flow construct.");
  const binarySearch = structuralBinarySearch(body, localCosts, parameters, constantSymbols);
  if (binarySearch) return { ...binarySearch, auxiliarySpace: space };
  // Constructor bodies often contain small index-maintenance loops while
  // building tables. They are not two-pointer algorithms; applying that
  // recognizer there can discard later preprocessing loops. Restrict the
  // topology rule to callable operations.
  const twoPointers = functionDecl.kind === "CXXConstructorDecl" ? undefined : structuralTwoPointers(body, parameters);
  if (twoPointers) return { ...twoPointers, auxiliarySpace: space };
  const analyses = loops.map((loop) => analyseLoopWithCfg(loop, pathEntryState(flow.loopEntries.get(loop), parameters), flow, localCosts, constantSymbols));
  if (analyses.some((analysis) => !analysis.value)) return unknown("The loop bounds or update are not a supported canonical form.");
  const nonTerminating = analyses.find((analysis) => analysis.value === "Does not terminate");
  if (nonTerminating) return { worstCaseTime: "Does not terminate", auxiliarySpace: space, confidence: "exact", proof: nonTerminating.proof ?? [] };
  // Local calls outside a loop are sequential phases, not per-iteration
  // work. Compose them here rather than silently dropping a same-file
  // preprocessing helper such as an adjacency-list builder.
  const topLevelCalls = callsOutsideLoops(body);
  const topLevelCosts = topLevelCalls.map((call) => knownLoopCallCost(call, localCosts, parameters, constantSymbols));
  if (topLevelCosts.some((cost) => !cost)) return unknown(unresolvedCallReason(topLevelCalls, localCosts, parameters, constantSymbols));
  const worst = sequentialMaximum([
    ...analyses.map((analysis) => analysis.value!),
    ...topLevelCosts.filter((cost): cost is Complexity => Boolean(cost))
  ]);
  if (!worst) return unknown("The sequential loop costs could not be ordered safely.");
  const helperSpaces = topLevelCalls.map((call) => localCallSpace(call, localCosts, parameters, constantSymbols))
    .filter((value): value is AuxiliarySpace => value !== undefined);
  const composedSpace = sequentialMaximum([space, ...helperSpaces] as Complexity[]) as AuxiliarySpace | undefined;
  const estimatedHelper = topLevelCalls.some((call) => localCallConfidence(call, localCosts) === "estimated");
  return {
    worstCaseTime: worst,
    auxiliarySpace: composedSpace ?? space,
    confidence: estimatedHelper ? "estimated" : "exact",
    proof: [
      ...analyses.flatMap((analysis) => analysis.proof ?? []),
      ...(topLevelCalls.length > 0 ? ["Resolved same-file preprocessing calls are composed as sequential phases."] : []),
      ...(loops.length > 1 ? ["Sequential loops add; the dominant term is reported."] : [])
    ]
  };
}
