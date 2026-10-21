import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("self-capturing lambda recursion proves halving and branching recurrences", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const logarithmic = analyseCppSelection(`
    long long solve(int n) {
      function<long long(int)> visit = [&](int x) -> long long {
        if (x <= 1) return 1;
        return visit(x / 2) + 1;
      };
      return visit(n);
    }`);
  assert.equal(logarithmic.worstCaseTime, "O(log n)", logarithmic.proof.join(" "));
  assert.equal(logarithmic.auxiliarySpace, "O(log n)");

  const exponential = analyseCppSelection(`
    long long solve(int n) {
      function<long long(int)> visit = [&](int x) -> long long {
        if (x <= 0) return 1;
        return visit(x - 1) + visit(x - 2);
      };
      return visit(n);
    }`);
  assert.equal(exponential.worstCaseTime, "O(1.618^n)", exponential.proof.join(" "));
  assert.equal(exponential.auxiliarySpace, "O(n)");
});

test("self-capturing lambda recursion recognizes visible memoization", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(int n) {
      vector<long long> memo(n + 1, -1);
      function<long long(int)> visit = [&](int x) -> long long {
        if (x <= 1) return 1;
        long long& cached = memo[x];
        if (cached != -1) return cached;
        return cached = visit(x - 1) + visit(x - 2);
      };
      return visit(n);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("data-dependent lambda decrements remain Unknown", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(int n) {
      function<long long(int)> visit = [&](int x) -> long long {
        if (x <= 1) return 1;
        if (x & 1) return visit(x - (x % 3 + 1));
        return visit(x - 1) + visit(x - 2);
      };
      return visit(n);
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
  assert.equal(result.confidence, "unknown");
});
