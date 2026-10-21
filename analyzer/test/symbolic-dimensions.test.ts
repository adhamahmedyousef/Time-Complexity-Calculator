import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("independent DP dimensions remain n times W", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int knapsack(const vector<int>& weights, const vector<int>& values, int W) {
      int n = (int)weights.size();
      vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
      for (int i = 1; i <= n; ++i)
        for (int w = 0; w <= W; ++w) dp[i][w] = values[i - 1];
      return dp[n][W];
    }`);
  assert.equal(result.worstCaseTime, "O(n W)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n W)", result.proof.join(" "));
});

test("matrix dynamic programming over two strings remains n times m", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int lcs(const string& a, const string& b) {
      int n = (int)a.size(), m = (int)b.size();
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j];
      return dp[n][m];
    }`);
  assert.equal(result.worstCaseTime, "O(n m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n m)");
});

test("repeated string append parses and composes as quadratic worst-case work", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    string buildString(int n) {
      string result = "";
      for (int i = 0; i < n; ++i) result += "a";
      return result;
    }`);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)", result.proof.join(" "));
});

test("linear unit-decrement recursion is proved", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int recursiveSum(const vector<int>& values, int n) {
      if (n <= 0) return 0;
      return values[n - 1] + recursiveSum(values, n - 1);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)", result.proof.join(" "));
});

test("three-way unit-decrement recursion is distinguished from binary recursion", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long tribonacciNaive(int n) {
      if (n <= 2) return 1;
      return tribonacciNaive(n - 1) + tribonacciNaive(n - 2) + tribonacciNaive(n - 3);
    }`);
  assert.equal(result.worstCaseTime, "O(1.839^n)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});
