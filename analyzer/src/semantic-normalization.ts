import type { ClangNode } from "./model.js";

const wrappers = new Set(["ImplicitCastExpr", "ParenExpr", "CStyleCastExpr", "CXXStaticCastExpr", "ConstantExpr", "ExprWithCleanups"]);
export function unwrapExpression(node: ClangNode | undefined): ClangNode | undefined {
  while (node && wrappers.has(node.kind ?? "") && node.inner?.length === 1) node = node.inner[0];
  return node;
}
export function symbolIdentity(node: ClangNode | undefined): string | undefined {
  return unwrapExpression(node)?.referencedDecl?.id ?? unwrapExpression(node)?.referencedDecl?.name;
}
export function constantNumber(node: ClangNode | undefined): number | undefined {
  node = unwrapExpression(node);
  if (!node) return undefined;
  if (node.kind === "CXXBoolLiteralExpr") return String(node.value) === "true" || String(node.value) === "1" ? 1 : 0;
  if (["IntegerLiteral", "FloatingLiteral", "CharacterLiteral"].includes(node.kind ?? "")) {
    const value = Number(node.value);
    return Number.isFinite(value) ? value : undefined;
  }
  const a = constantNumber(node.inner?.[0]);
  if (a === undefined) return undefined;
  if (node.kind === "UnaryOperator") {
    if (node.opcode === "!") return Number(!a);
    if (node.opcode === "-") return -a;
    if (node.opcode === "+") return a;
  }
  const b = constantNumber(node.inner?.[1]);
  if (b === undefined || node.kind !== "BinaryOperator") return undefined;
  switch (node.opcode) {
    case "+": return a + b;
    case "-": return a - b;
    case "*": return a * b;
    case "/": return b === 0 ? undefined : Math.trunc(a / b);
    case "%": return b === 0 ? undefined : a % b;
    case "==": return Number(a === b);
    case "!=": return Number(a !== b);
    case "<": return Number(a < b);
    case "<=": return Number(a <= b);
    case ">": return Number(a > b);
    case ">=": return Number(a >= b);
    case "&&": return Number(Boolean(a) && Boolean(b));
    case "||": return Number(Boolean(a) || Boolean(b));
    default: return undefined;
  }
}

/** Normalizes equivalent scalar syntax without mutating the compiler AST. */
export function normalizeFunctionSyntax(fn: ClangNode): ClangNode {
  const written = new Set<string>();
  const scan = (node: ClangNode): void => {
    if (node.kind === "CompoundAssignOperator" || node.kind === "BinaryOperator" && node.opcode === "="
      || node.kind === "UnaryOperator" && ["++", "--", "&"].includes(node.opcode ?? "")) {
      const key = symbolIdentity(node.inner?.[0]);
      if (key) written.add(key);
    }
    if (node.kind === "CXXOperatorCallExpr") {
      let isExtraction = false;
      const checkOp = (c: ClangNode): void => {
        if (c.referencedDecl?.name === "operator>>") isExtraction = true;
        for (const sub of c.inner ?? []) checkOp(sub);
      };
      if (node.inner?.[0]) checkOp(node.inner[0]);
      if (isExtraction && (node.inner?.length ?? 0) >= 3) {
        const collect = (c: ClangNode): void => {
          const k = c.referencedDecl?.id ?? c.referencedDecl?.name;
          if (k && k !== "operator>>" && k !== "cin") written.add(k);
          if (c.kind !== "ArraySubscriptExpr") {
            for (const sub of c.inner ?? []) collect(sub);
          }
        };
        collect(node.inner![2]);
      }
    }
    if (node.kind === "CallExpr") {
      const callee = node.inner?.[0];
      const isScanf = callee?.referencedDecl?.name === "scanf"
        || callee?.inner?.[0]?.referencedDecl?.name === "scanf";
      if (isScanf && (node.inner?.length ?? 0) >= 2) {
        for (const arg of node.inner!.slice(1)) {
          const target = unwrapExpression(arg);
          const operand = target?.kind === "UnaryOperator" && target.opcode === "&" ? target.inner?.[0] : target;
          const k = symbolIdentity(operand);
          if (k) written.add(k);
        }
      }
    }
    for (const child of node.inner ?? []) scan(child);
  };
  scan(fn);
  const pure = (node: ClangNode | undefined): boolean => {
    node = unwrapExpression(node);
    return Boolean(node && (["DeclRefExpr", "IntegerLiteral", "FloatingLiteral", "CXXBoolLiteralExpr"].includes(node.kind ?? "")
      || node.kind === "BinaryOperator" && ["*", "/"].includes(node.opcode ?? "") && node.inner?.every(pure)));
  };
  const visit = (node: ClangNode, incoming: Map<string, ClangNode>): ClangNode => {
    if (node.kind === "DeclRefExpr") return incoming.get(node.referencedDecl?.id ?? node.referencedDecl?.name ?? "") ?? node;
    const aliases = new Map(incoming);
    const children: ClangNode[] = [];
    for (const child of node.inner ?? []) {
      const result = visit(child, aliases);
      children.push(result);
      if (node.kind === "CompoundStmt" && result.kind === "DeclStmt") {
        for (const decl of result.inner ?? []) {
          const key = decl.id ?? decl.name;
          const init = decl.inner?.at(-1);
          // Aliases are scoped to following statements in the same iteration.
          // Any write/address-taking prevents substitution, including hidden resets.
          if (key && !written.has(key) && pure(init) && !/[&*]/.test(decl.type?.qualType ?? "")) aliases.set(key, init!);
        }
      }
    }
    let result = { ...node, ...(node.inner ? { inner: children } : {}) };
    if (result.kind === "BinaryOperator" && result.opcode === "=") {
      const rhs = unwrapExpression(children[1]);
      const key = symbolIdentity(children[0]);
      if (key && rhs?.kind === "BinaryOperator" && ["+", "-", "*", "/", ">>", "<<"].includes(rhs.opcode ?? "")
        && symbolIdentity(rhs.inner?.[0]) === key) {
        result = { ...result, kind: "CompoundAssignOperator", opcode: rhs.opcode + "=", inner: [children[0], rhs.inner![1]] };
      }
    }
    if (result.kind === "IfStmt") {
      const value = constantNumber(result.inner?.[0]);
      if (value !== undefined) return result.inner?.[value ? 1 : 2] ?? { kind: "NullStmt" };
    }
    return result;
  };
  return visit(fn, new Map());
}
