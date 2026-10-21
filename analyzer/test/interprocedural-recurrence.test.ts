import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("a non-reassigned local alias composes the same-file helper summary", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long helper(int n) {
      if (n <= 0) return 1;
      return helper(n - 1);
    }
    long long solve(int n) {
      auto alias = helper;
      return alias(n);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("a resolved linear helper composes with one halving recursive call", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long prep(int n) {
      long long sum = 0;
      for (int i = 0; i < n; ++i) sum += i;
      return sum;
    }
    long long solve(int n) {
      if (n <= 1) return 1;
      return prep(n) + solve(n / 2);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(log n)");
});

test("a class method with a checked indexed cache is memoized DP", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct Solver {
      vector<long long> memo;
      explicit Solver(int n) : memo(n + 1, -1) {}
      long long solve(int n) {
        if (n <= 1) return 1;
        long long& result = memo[n];
        if (result != -1) return result;
        return result = solve(n - 1) + solve(n - 2);
      }
    };
    long long run(int n) {
      Solver solver(n);
      return solver.solve(n);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("a checked unordered_map cache is memoized scalar DP", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    unordered_map<int, long long> cache;
    long long solve(int n) {
      if (n <= 1) return 1;
      if (cache.count(n)) return cache[n];
      return cache[n] = solve(n - 1) + solve(n - 2);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("move preserves a container dimension when composing a same-file helper", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long consume(vector<int> values) {
      long long total = 0;
      for (int x : values) total += x;
      return total;
    }
    long long run(vector<int> values) {
      return consume(move(values));
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});
