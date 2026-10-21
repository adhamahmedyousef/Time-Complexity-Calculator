import io

# Fix 1: enum constants in translationUnitConstants
path = "src/index.ts"
text = io.open(path, encoding="utf-8").read()
old = """  for (const node of ast.inner ?? []) {
    if (node.kind !== "VarDecl" || !node.name) continue;"""
new = """  for (const node of ast.inner ?? []) {
    // Enum constants: `enum { SIZE = 100 }` - the EnumConstantDecl is a
    // compile-time constant usable as a loop bound.
    if (node.kind === "EnumDecl") {
      for (const constant of node.inner ?? []) {
        if (constant.kind === "EnumConstantDecl" && constant.name) constants.add(constant.name);
      }
      continue;
    }
    if (node.kind !== "VarDecl" || !node.name) continue;"""
assert old in text, "enum anchor"
text = text.replace(old, new, 1)

# Fix 2: restrict forwardedFunctionAliasResult to DIRECT DeclRefExpr initializers.
path2 = "src/analyze-ast.ts"
text2 = io.open(path2, encoding="utf-8").read()
old2 = """  const binding = nodesOfKind(body, "VarDecl").find((node) => {
    const target = nodesOfKind(node, "DeclRefExpr").find((reference) => reference.referencedDecl?.kind === "FunctionDecl");
    return Boolean(node.name && target);
  });"""
new2 = """  const binding = nodesOfKind(body, "VarDecl").find((node) => {
    // The initializer must be a DIRECT DeclRefExpr to a function (after cast
    // unwrapping) - a CallExpr initializer (`auto it = unique(...)`) is a
    // computed result, not an alias.
    let initializer = node.inner?.at(-1);
    while (initializer && ["ImplicitCastExpr", "ParenExpr"].includes(initializer.kind ?? "")) initializer = initializer.inner?.[0];
    if (!initializer || initializer.kind !== "DeclRefExpr") return false;
    return Boolean(node.name && initializer.referencedDecl?.kind === "FunctionDecl");
  });"""
assert old2 in text2, "alias anchor"
text2 = text2.replace(old2, new2, 1)

# Fix 3: IfStmt condition cost - calls in the condition count toward the branch.
old3 = """    const value = branchMaximum(thenWork.value, elseWork.value);
    if (!value) return undefined;
    return {
      value,
      proof: [
        "CFG branch analysis evaluates each reachable if/else edge with its own symbolic bounds.","""
new3 = """    let value = branchMaximum(thenWork.value, elseWork.value);
    // The condition's own cost (calls like set::count) is always evaluated.
    const conditionCalls = directCalls(condition);
    if (conditionCalls.length > 0) {
      const conditionCosts = conditionCalls.map((call) => knownLoopCallCost(call, localCosts, bounds, constantSymbols));
      if (conditionCosts.every((cost) => cost) && !conditionCosts.includes("Does not terminate")) {
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
        "CFG branch analysis evaluates each reachable if/else edge with its own symbolic bounds.","""
assert old3 in text2, "branch cost anchor"
text2 = text2.replace(old3, new3, 1)

io.open(path, "w", encoding="utf-8", newline="\n").write(text)
io.open(path2, "w", encoding="utf-8", newline="\n").write(text2)
print("all 3 fixes applied")
