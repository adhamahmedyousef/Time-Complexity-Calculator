import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument, analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const nativeAnalyzerPath = process.env.PROJECT_X_NATIVE_ANALYZER
  ?? "C:\\Users\\j\\.project-x-deps\\project-x-native-build-release\\project-x-native-analyzer.exe";

test("structural Kruskal recognizer requires sorting the scanned DSU input", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct UnionFind { UnionFind(int); bool unite(int, int); };
    struct Edge { int u, v, w; };
    void solve(int n, vector<Edge> edges) {
      sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w < b.w; });
      UnionFind uf(n);
      for (const Edge& e : edges) uf.unite(e.u, e.v);
    }`);
  // The canonical algebra drops the alpha term: alpha(n) = o(log m), so the
  // tight printed bound is O(m log m).
  assert.equal(result.worstCaseTime, "O(m log m)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});

test("structural rolling DP recognizer derives n times W and W storage", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(int W, const vector<pair<int, int>>& items) {
      vector<long long> dp(W + 1, 0);
      for (auto [weight, value] : items)
        for (int cap = W; cap >= weight; --cap) dp[cap] = max(dp[cap], dp[cap - weight] + value);
      return dp[W];
    }`);
  assert.equal(result.worstCaseTime, "O(n W)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(W)");
  assert.equal(result.confidence, "estimated");
});

test("same-file DFS preserves an estimated helper's time and auxiliary space", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    long long knapsack(int W, const vector<pair<int, int>>& items) {
      vector<long long> dp(W + 1, 0);
      for (auto [weight, value] : items)
        for (int cap = W; cap >= weight; --cap) dp[cap] = max(dp[cap], dp[cap - weight] + value);
      return dp[W];
    }
    long long solve(int W, const vector<pair<int, int>>& items) {
      return knapsack(W, items);
    }`, "solve");
  assert.equal(result.worstCaseTime, "O(n W)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(W)");
  assert.equal(result.confidence, "estimated");
});

test("optional LibTooling pass enriches, but does not replace, the JSON-AST result", { skip: !existsSync(clangPath) || !existsSync(nativeAnalyzerPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  process.env.PROJECT_X_NATIVE_ANALYZER = nativeAnalyzerPath;
  const result = analyseCppSelection(`
    int helper(int n) { for (int i = 0; i < n; ++i) {} return 0; }
    int solve(int n) { return helper(n); }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
  assert.match(result.proof.at(-1) ?? "", /LibTooling independently verified.*CFG/);
  delete process.env.PROJECT_X_NATIVE_ANALYZER;
});

test("same-file helper time is specialised to the caller argument dimension", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    int scan(int n) { for (int i = 0; i < n; ++i) {} return 0; }
    int byM(int m) { return scan(m); }
    int byHalfN(int n) { return scan(n / 2); }`;
  const byM = analyseCppFunctionInDocument(source, "byM");
  const byHalfN = analyseCppFunctionInDocument(source, "byHalfN");
  assert.equal(byM.worstCaseTime, "O(m)", byM.proof.join(" "));
  assert.equal(byHalfN.worstCaseTime, "O(n)", byHalfN.proof.join(" "));
});

test("same-file helper auxiliary space is specialised to the caller argument", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    vector<int> build(int n) { vector<int> values(n); return values; }
    vector<int> use(int W) { return build(W); }`, "use");
  assert.equal(result.worstCaseTime, "O(1)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(W)");
});

test("a non-constant call inside a matrix traversal composes with every cell", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int code(int n) {
      vector<vector<int>> arr(n, vector<int>(n));
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          sort(arr[i].begin(), arr[i].end());
          arr[i][j] = i + j;
        }
      return 0;
    }`);
  assert.equal(result.worstCaseTime, "O(n^3 log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n^2)");
  assert.equal(result.confidence, "exact");
});

test("a sort nested in a linear loop multiplies rather than using the sequential-sort shortcut", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void solve(int n) {
      vector<long long> arr(n); vector<int> prefix(n);
      for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i];
        sort(prefix.begin(), prefix.end());
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n^2 log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("an unbraced inner loop keeps its direct sort call", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void solve(int n) {
      vector<int> values(n);
      for (int i = 0; i < n; ++i)
        for (int j = 1; j < n; j *= 2)
          sort(values.begin(), values.end());
    }`);
  assert.equal(result.worstCaseTime, "O(n^2 log^2 n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("top-down LCS cache flow recognises a final store through a local answer", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int n, m; vector<int> left, right; int dp[501][2001];
    int lcs(int i, int j) {
      if (i == n || j == m) return 0;
      if (~dp[i][j]) return dp[i][j];
      int answer = 0;
      if (left[i] == right[j]) answer = max(answer, 1 + lcs(i + 1, j + 1));
      answer = max(answer, lcs(i + 1, j));
      answer = max(answer, lcs(i, j + 1));
      return dp[i][j] = answer;
    }`);
  assert.equal(result.worstCaseTime, "O(n m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n m)");
  // Array-indexed cache, literal-step recursion, no loops, and only O(1)
  // calls: every per-state proof obligation resolves, so the memo state-space
  // bound is exact rather than estimated.
  assert.equal(result.confidence, "exact");
});
