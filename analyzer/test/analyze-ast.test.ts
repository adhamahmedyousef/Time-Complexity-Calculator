import assert from "node:assert/strict";
import test from "node:test";
import { analyseFunctionAst } from "../src/analyze-ast.js";
import type { ClangNode } from "../src/model.js";

const ref = (name: string): ClangNode => ({ kind: "DeclRefExpr", referencedDecl: { name } });
const loop = (update: string, body: ClangNode[] = []): ClangNode => ({ kind: "ForStmt", inner: [
  { kind: "BinaryOperator", opcode: "<", inner: [ref("i"), ref("n")] },
  { kind: update === "++" ? "UnaryOperator" : "CompoundAssignOperator", opcode: update, inner: [ref("i")] },
  { kind: "CompoundStmt", inner: body }
] });
const fn = (body: ClangNode[]): ClangNode => ({ kind: "FunctionDecl", name: "f", inner: [{ kind: "ParmVarDecl", name: "n" }, { kind: "CompoundStmt", inner: body }] });
const loopWithCondition = (update: string, condition: ClangNode, body: ClangNode[] = []): ClangNode => ({
  kind: "ForStmt", inner: [
    condition,
    { kind: update === "++" ? "UnaryOperator" : "CompoundAssignOperator", opcode: update, inner: [ref("i")] },
    { kind: "CompoundStmt", inner: body }
  ]
});

test("constant work is exact O(1)", () => assert.equal(analyseFunctionAst(fn([])).worstCaseTime, "O(1)"));
test("constant-step for loop is exact O(n)", () => assert.equal(analyseFunctionAst(fn([loop("++")])).worstCaseTime, "O(n)"));
test("multiplicative for loop is exact O(log n)", () => assert.equal(analyseFunctionAst(fn([loop("*=")])).worstCaseTime, "O(log n)"));
test("nested linear loops are exact O(n^2)", () => assert.equal(analyseFunctionAst(fn([loop("++", [loop("++")])])).worstCaseTime, "O(n^2)"));
test("dependent inner bound is O(n^2)", () => {
  const inner = loop("++");
  inner.inner![0] = { kind: "BinaryOperator", opcode: "<", inner: [ref("j"), ref("i")] };
  inner.inner![1].inner = [ref("j")];
  assert.equal(analyseFunctionAst(fn([loop("++", [inner])])).worstCaseTime, "O(n^2)");
});
test("three nested linear loops become O(n^3)", () => assert.equal(analyseFunctionAst(fn([loop("++", [loop("++", [loop("++")])])])).worstCaseTime, "O(n^3)"));
test("a symbolic n times n loop limit is O(n^2)", () => {
  const nSquared = loop("++");
  nSquared.inner![0] = { kind: "BinaryOperator", opcode: "<", inner: [ref("i"), { kind: "BinaryOperator", opcode: "*", inner: [ref("n"), ref("n")] }] };
  assert.equal(analyseFunctionAst(fn([nSquared])).worstCaseTime, "O(n^2)");
});
test("a dependent inner loop retains the symbolic outer n^2 limit", () => {
  const inner = loopWithCondition("++", { kind: "BinaryOperator", opcode: "<", inner: [ref("j"), ref("i")] });
  inner.inner![1].inner = [ref("j")];
  const outer = loop("++", [inner]);
  outer.inner![0] = { kind: "BinaryOperator", opcode: "<", inner: [ref("i"), { kind: "BinaryOperator", opcode: "*", inner: [ref("n"), ref("n")] }] };
  assert.equal(analyseFunctionAst(fn([outer])).worstCaseTime, "O(n^4)");
});
test("linear outside logarithmic is O(n log n)", () => assert.equal(analyseFunctionAst(fn([loop("++", [loop("*=")])])).worstCaseTime, "O(n log n)"));
test("two independent logarithmic loops are O(log^2 n)", () => {
  const inner = loopWithCondition("*=", { kind: "BinaryOperator", opcode: "<", inner: [ref("j"), ref("n")] });
  inner.inner![1].inner = [ref("j")];
  assert.equal(analyseFunctionAst(fn([loop("*=", [inner])])).worstCaseTime, "O(log^2 n)");
});
test("a linear loop inside halving while is O(n) - geometric series collapse", () => {
  const inner = loopWithCondition("++", { kind: "BinaryOperator", opcode: "<", inner: [ref("j"), ref("n")] });
  inner.inner![1].inner = [ref("j")];
  const outer: ClangNode = { kind: "WhileStmt", inner: [
    { kind: "BinaryOperator", opcode: ">", inner: [ref("i"), { kind: "IntegerLiteral", value: "1" }] },
    { kind: "CompoundStmt", inner: [inner, { kind: "CompoundAssignOperator", opcode: "/=", inner: [ref("i")] }] }
  ] };
  const withI: ClangNode = { kind: "FunctionDecl", name: "f", inner: [{ kind: "ParmVarDecl", name: "n" }, { kind: "CompoundStmt", inner: [{ kind: "DeclStmt", inner: [{ kind: "VarDecl", name: "i", inner: [ref("n")] }] }, outer] }] };
  assert.equal(analyseFunctionAst(withI).worstCaseTime, "O(n)");
});
test("geometric outer loop with inner i-bound is O(n)", () => {
  const inner = loopWithCondition("++", { kind: "BinaryOperator", opcode: "<", inner: [ref("j"), ref("i")] });
  inner.inner![1].inner = [ref("j")];
  assert.equal(analyseFunctionAst(fn([loop("*=", [inner])])).worstCaseTime, "O(n)");
});
test("one self call on n divided by a constant is O(log n)", () => {
  const recursive: ClangNode = { kind: "FunctionDecl", name: "halve", inner: [
    { kind: "ParmVarDecl", name: "n" },
    { kind: "CompoundStmt", inner: [{ kind: "CallExpr", inner: [ref("halve"), { kind: "BinaryOperator", opcode: "/", inner: [ref("n"), { kind: "IntegerLiteral", value: "2" }] }] }] }
  ] };
  assert.equal(analyseFunctionAst(recursive).worstCaseTime, "O(log n)");
});
test("recognized std sort is O(n log n) with unknown auxiliary space", () => {
  const sortOnly = fn([{ kind: "CallExpr", inner: [ref("sort")] }]);
  const result = analyseFunctionAst(sortOnly);
  assert.equal(result.worstCaseTime, "O(n log n)");
  assert.equal(result.auxiliarySpace, "Unknown");
});
test("stream output inside a supported loop is treated as constant algorithmic work", () => {
  assert.equal(analyseFunctionAst(fn([loop("++", [{ kind: "CXXOperatorCallExpr", name: "operator<<" }])])).worstCaseTime, "O(n)");
});
test("printf inside a supported loop is treated as constant CP I/O work", () => {
  assert.equal(analyseFunctionAst(fn([loop("++", [{ kind: "CallExpr", inner: [ref("printf")] }])])).worstCaseTime, "O(n)");
});
test("sequential loops report the dominant cost", () => assert.equal(analyseFunctionAst(fn([loop("++"), loop("*=")])).worstCaseTime, "O(n)"));
test("square-bound trial division is O(sqrt n)", () => {
  const squareLoop = loop("++");
  squareLoop.inner![0] = { kind: "BinaryOperator", opcode: "<=", inner: [{ kind: "BinaryOperator", opcode: "*", inner: [ref("i"), ref("i")] }, ref("n")] };
  assert.equal(analyseFunctionAst(fn([squareLoop])).worstCaseTime, "O(sqrt n)");
});
test("Euclidean modulo loop is O(log n)", () => {
  const euclid: ClangNode = { kind: "WhileStmt", inner: [
    { kind: "BinaryOperator", opcode: "!=", inner: [ref("b"), { kind: "IntegerLiteral", value: "0" }] },
    { kind: "CompoundStmt", inner: [{ kind: "CompoundAssignOperator", opcode: "%=", inner: [ref("a"), ref("b")] }] }
  ] };
  const gcd: ClangNode = { kind: "FunctionDecl", name: "gcd", inner: [
    { kind: "ParmVarDecl", name: "a" }, { kind: "ParmVarDecl", name: "b" }, { kind: "CompoundStmt", inner: [euclid] }
  ] };
  assert.equal(analyseFunctionAst(gcd).worstCaseTime, "O(log n)");
});
test("zero multiplied in a loop is detected as non-terminating", () => {
  const stuck: ClangNode = { kind: "ForStmt", inner: [
    { kind: "DeclStmt", inner: [{ kind: "VarDecl", name: "k", inner: [{ kind: "IntegerLiteral", value: "0" }] }] },
    { kind: "BinaryOperator", opcode: "<", inner: [ref("k"), ref("n")] },
    { kind: "CompoundAssignOperator", opcode: "*=", inner: [ref("k")] },
    { kind: "CompoundStmt" }
  ] };
  assert.equal(analyseFunctionAst(fn([stuck])).worstCaseTime, "Does not terminate");
});
test("a zero additive step is detected as non-terminating", () => {
  const stuck = loop("+=");
  stuck.inner![1].inner = [ref("i"), { kind: "IntegerLiteral", value: "0" }];
  assert.equal(analyseFunctionAst(fn([stuck])).worstCaseTime, "Does not terminate");
});
test("calls are unknown rather than guessed", () => assert.equal(analyseFunctionAst(fn([{ kind: "CallExpr" }])).confidence, "unknown"));
test("a local constant loop is proven O(1), not treated as an input size", () => {
  const fixedM: ClangNode = { kind: "FunctionDecl", name: "fixed", inner: [
    { kind: "CompoundStmt", inner: [
      { kind: "DeclStmt", inner: [{ kind: "VarDecl", name: "m", inner: [{ kind: "IntegerLiteral", value: "100" }] }] },
      { kind: "ForStmt", inner: [
        { kind: "BinaryOperator", opcode: "<", inner: [ref("i"), ref("m")] },
        { kind: "UnaryOperator", opcode: "++", inner: [ref("i")] },
        { kind: "CompoundStmt" }
      ] }
    ] }
  ] };
  assert.equal(analyseFunctionAst(fixedM).worstCaseTime, "O(1)");
});

test("Clang declaration ids keep a shadowing local bound separate from its parameter", () => {
  const parameterN: ClangNode = { kind: "ParmVarDecl", id: "param-n", name: "n", type: { qualType: "int" } };
  const localN: ClangNode = { kind: "VarDecl", id: "local-n", name: "n", inner: [{ kind: "IntegerLiteral", value: "100" }] };
  const localI: ClangNode = { kind: "VarDecl", id: "local-i", name: "i", inner: [{ kind: "IntegerLiteral", value: "0" }] };
  const idRef = (id: string, name: string): ClangNode => ({ kind: "DeclRefExpr", referencedDecl: { id, name } });
  const scoped: ClangNode = { kind: "FunctionDecl", name: "scoped", inner: [
    parameterN,
    { kind: "CompoundStmt", inner: [
      { kind: "DeclStmt", inner: [localN] },
      { kind: "ForStmt", inner: [
        { kind: "DeclStmt", inner: [localI] },
        { kind: "BinaryOperator", opcode: "<", inner: [idRef("local-i", "i"), idRef("local-n", "n")] },
        { kind: "UnaryOperator", opcode: "++", inner: [idRef("local-i", "i")] },
        { kind: "CompoundStmt" }
      ] }
    ] }
  ] };
  assert.equal(analyseFunctionAst(scoped).worstCaseTime, "O(1)");
});

test("forward branch data flow proves a loop bound assigned on every compatible path", () => {
  const refId = (id: string, name: string): ClangNode => ({ kind: "DeclRefExpr", referencedDecl: { id, name } });
  const assignment = (left: ClangNode, right: ClangNode): ClangNode => ({ kind: "BinaryOperator", opcode: "=", inner: [left, right] });
  const parameterN: ClangNode = { kind: "ParmVarDecl", id: "param-n", name: "n", type: { qualType: "int" } };
  const limit: ClangNode = { kind: "VarDecl", id: "limit", name: "limit" };
  const index: ClangNode = { kind: "VarDecl", id: "index", name: "i", inner: [{ kind: "IntegerLiteral", value: "0" }] };
  const flow: ClangNode = { kind: "FunctionDecl", name: "flow", inner: [parameterN, { kind: "CompoundStmt", inner: [
    { kind: "DeclStmt", inner: [limit] },
    { kind: "IfStmt", inner: [
      { kind: "DeclRefExpr", referencedDecl: { id: "condition", name: "condition" } },
      assignment(refId("limit", "limit"), refId("param-n", "n")),
      assignment(refId("limit", "limit"), refId("param-n", "n"))
    ] },
    { kind: "ForStmt", inner: [
      { kind: "DeclStmt", inner: [index] },
      { kind: "BinaryOperator", opcode: "<", inner: [refId("index", "i"), refId("limit", "limit")] },
      { kind: "UnaryOperator", opcode: "++", inner: [refId("index", "i")] },
      { kind: "CompoundStmt" }
    ] }
  ] }] };
  assert.equal(analyseFunctionAst(flow).worstCaseTime, "O(n)");
});

test("forward branch data flow abstains when branch bounds are incomparable", () => {
  const refId = (id: string, name: string): ClangNode => ({ kind: "DeclRefExpr", referencedDecl: { id, name } });
  const assignment = (right: ClangNode): ClangNode => ({ kind: "BinaryOperator", opcode: "=", inner: [refId("limit", "limit"), right] });
  const parameterN: ClangNode = { kind: "ParmVarDecl", id: "param-n", name: "n", type: { qualType: "int" } };
  const parameterM: ClangNode = { kind: "ParmVarDecl", id: "param-m", name: "m", type: { qualType: "int" } };
  const divergent: ClangNode = { kind: "FunctionDecl", name: "divergent", inner: [parameterN, parameterM, { kind: "CompoundStmt", inner: [
    { kind: "DeclStmt", inner: [{ kind: "VarDecl", id: "limit", name: "limit" }] },
    { kind: "IfStmt", inner: [{ kind: "DeclRefExpr", referencedDecl: { id: "condition", name: "condition" } }, assignment(refId("param-n", "n")), assignment(refId("param-m", "m"))] },
    { kind: "ForStmt", inner: [
      { kind: "DeclStmt", inner: [{ kind: "VarDecl", id: "index", name: "i", inner: [{ kind: "IntegerLiteral", value: "0" }] }] },
      { kind: "BinaryOperator", opcode: "<", inner: [refId("index", "i"), refId("limit", "limit")] },
      { kind: "UnaryOperator", opcode: "++", inner: [refId("index", "i")] },
      { kind: "CompoundStmt" }
    ] }
  ] }] };
  assert.equal(analyseFunctionAst(divergent).confidence, "unknown");
});
