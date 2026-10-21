import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("independent preprocessing and query phases retain both symbolic terms", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void solve() {
      int n, q; cin >> n >> q; vector<int> values(n);
      sort(values.begin(), values.end());
      while (q--) { int x; cin >> x; lower_bound(values.begin(), values.end(), x); }
    }`);
  assert.equal(result.worstCaseTime, "O((n + q) log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("standard scalar stream I/O does not hide a resolved helper's complexity", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long prefixTotal(const vector<int>& values) {
      long long total = 0; for (int value : values) total += value; return total;
    }
    void solve() {
      int n, q; cin >> n >> q; vector<int> values(n);
      for (int i = 0; i < n; ++i) cin >> values[i];
      cout << prefixTotal(values) + q << '\\n';
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  // Round-6 convention reversal (census reconciliation, see Deep.md): a
  // container materialized from the input stream is charged to auxiliary
  // space — the corpus labels are split on this, and the majority side (plus
  // the 2D-grid family) charges the input instance.
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("memoized recursion with a cache parameter retains its scalar state extent", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(int n, vector<long long>& cache) {
      if (n <= 1) return 1;
      long long &saved = cache[n];
      if (saved != -1) return saved;
      return saved = solve(n - 1, cache) + 1;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("an indexed pass with a pop-only nested deque loop is amortized linear", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void solve() {
      int n; cin >> n; deque<int> worklist;
      for (int i = 0; i < n; ++i) {
        int value; cin >> value;
        while (!worklist.empty() && worklist.back() > value) worklist.pop_back();
        worklist.push_back(value);
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});
