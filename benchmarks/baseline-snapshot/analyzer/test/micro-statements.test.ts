import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

// Micro one-liner selections are the "highlight one line and ask what it
// costs" flow. Every expectation below is first-principles constant work
// (or the documented corpus convention for the few input-sized shapes), and
// several cases double as regression guards for the loop-progress rules:
//   - an accumulator must never be adopted as the loop driver
//   - an update moving away from the bound must not earn a trip count
//   - a unit step embedded in a larger expression still drives the loop

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const skip = !existsSync(clangPath);

function analyse(source: string) {
  process.env.PROJECT_X_CLANG = clangPath;
  return analyseCppSelection(source);
}

function expectConstant(source: string) {
  const result = analyse(source);
  assert.equal(result.worstCaseTime, "O(1)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)", result.proof.join(" "));
  assert.equal(result.confidence, "exact", result.proof.join(" "));
  return result;
}

test("a single int binding is constant work", { skip }, () => {
  expectConstant("int x = 10;");
});

test("a small arithmetic fold over locals is constant work", { skip }, () => {
  expectConstant("int x = 10; int y = x * 2 + 7;");
});

test("a modular hash update is constant work", { skip }, () => {
  expectConstant("long long h = 123; h = (h * 31 + 7) % 1000000007;");
});

test("bit operations on a scalar are constant work", { skip }, () => {
  expectConstant("int x = 123; x = (x << 3) | (x >> 1);");
});

test("built-in min/max over scalars is constant work", { skip }, () => {
  expectConstant("int a = 3, b = 8; cout << max(a, b) - min(a, b);");
});

test("swapping two scalar locals is constant work", { skip }, () => {
  expectConstant("int x = 1, y = 2; swap(x, y);");
});

test("a literal-bound for loop is constant work", { skip }, () => {
  expectConstant("int s = 0; for (int i = 0; i < 10; ++i) s += i;");
});

test("a while loop with an embedded unit step is constant work", { skip }, () => {
  // `s += i++` performs the increment on its unconditional evaluation spine,
  // so the trip count is the literal bound even though the step is not a
  // statement of its own.
  expectConstant("int s = 0, i = 0; while (i < 5) { s += i++; }");
});

test("a braced vector literal has constant storage", { skip }, () => {
  // `vector<int> v = {1, 2, 3}` materialises a std::initializer_list whose
  // element count is a compile-time constant of the source text.
  expectConstant("vector<int> v = {1, 2, 3}; int x = v[1];");
});

test("pop_back on a braced vector keeps constant storage", { skip }, () => {
  expectConstant("vector<int> v = {1, 2, 3}; v.pop_back();");
});

test("one push_back into an empty vector is amortized constant", { skip }, () => {
  expectConstant("vector<int> v; v.push_back(7); cout << v[0];");
});

test("reading a character of a literal string is constant work", { skip }, () => {
  expectConstant("string s = \"hello\"; cout << s[2];");
});

test("an accumulator next to the driver keeps the bound's trip count", { skip }, () => {
  // Regression guard: `s += i` reads the condition variable but does not
  // drive the loop; adopting it as the update used to report the
  // accumulator's own O(1) bound as the trip count.
  const result = analyse("int n; cin >> n; int i = 0, s = 0; while (i < n) { s += i; ++i; }");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact", result.proof.join(" "));
});

test("a while index stepping by one reaches a symbolic bound linearly", { skip }, () => {
  const result = analyse("int n; cin >> n; int i = 0; int s = 0; while (i < n) { s += i; i += 1; }");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("an update moving away from the bound earns no trip count", { skip }, () => {
  // `--i` never reaches 5 once `i < 5` holds, so no O(1) claim may be made.
  const result = analyse("int i = 0; while (i < 5) { --i; }");
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
  assert.equal(result.confidence, "unknown", result.proof.join(" "));
});
