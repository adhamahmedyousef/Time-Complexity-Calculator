import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("a full contest main keeps a conventional cin dimension symbolic", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int main() {
      int n; cin >> n;
      for (int i = 0; i < n; ++i) cout << i;
      return 0;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("a selection containing only commented examples is never misreported as O(1)", () => {
  const result = analyseCppSelection(`
    // int main() { for (int i = 0; i < n; ++i) {} }
    /* void helper() { while (true) {} } */
  `);
  assert.equal(result.worstCaseTime, "Unknown");
  assert.match(result.proof.join(" "), /comments only/i);
});

test("a while(t--) contest loop is linear in the test-case count", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int main() {
      int t; cin >> t;
      while (t--) { long long x, y; cin >> x >> y; cout << (x + y); }
    }`);
  assert.equal(result.worstCaseTime, "O(t)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("global memoized suffix DP recognises an index and finite mode state", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int n; int values[100005]; long long memo[100005][2]; bool seen[100005][2];
    long long best(int index, int parity) {
      if (index == n) return 0;
      if (seen[index][parity]) return memo[index][parity];
      seen[index][parity] = true;
      return memo[index][parity] = best(index + 1, parity ^ (values[index] & 1));
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("a selected statement block receives conventional CP dimensions and macros", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    #define REP(i, bound) for (int i = 0; i < (bound); ++i)
    REP(i, n) cout << i;
    while (t--) cout << t;
  `);
  assert.equal(result.worstCaseTime, "O(n + t)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("a local two-string suffix scan is linear in the combined input lengths", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void solve() {
      string left, right; cin >> left >> right;
      int n = left.size(), m = right.size(), i = n - 1, j = m - 1;
      while (i >= 0 && j >= 0) { if (left[i] != right[j]) break; --i; --j; }
    }`);
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "exact");
});

test("a testcase loop around a local vector range traversal composes n and t", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int main() {
      int t; cin >> t;
      while (t--) { int n; cin >> n; vector<int> values(n); for (auto value : values) cout << value; }
    }`);
  assert.equal(result.worstCaseTime, "O(n t)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "exact");
});

test("a fixed-bit prefix table adds preprocessing and range-query work", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<long long> solve(const vector<int> &values, const vector<pair<int, int>> &queries) {
      vector<vector<int>> prefix(31, vector<int>(values.size() + 1));
      for (int bit = 0; bit < 31; ++bit)
        for (int i = 1; i <= values.size(); ++i) prefix[bit][i] = prefix[bit][i - 1];
      vector<long long> answer;
      for (const auto &[left, right] : queries)
        for (int bit = 0; bit < 31; ++bit) answer.push_back(prefix[bit][right] - prefix[bit][left - 1]);
      return answer;
    }`);
  // The paired `queries` container is a query-count axis (convention q).
  assert.equal(result.worstCaseTime, "O(n + q)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "exact");
});

test("a range-for over a string is a linear scan", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int digitSum(const string &text) {
      int sum = 0; for (char character : text) sum += character - '0'; return sum;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("indexed string scans remain linear when operator[] is lowered as a generic call", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int solve() {
      string text; cin >> text; int index = 0;
      while (index < (int)text.size() && text[index] == text[0]) ++index;
      return index;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});
