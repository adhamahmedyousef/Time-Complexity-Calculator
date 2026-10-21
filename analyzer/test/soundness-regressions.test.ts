import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

// Regression coverage for the round-4 soundness fixes documented in Deep.md
// (BUG-007 loop reachability, BUG-008 signed strides, BUG-009 input storage,
// BUG-010 cast-wrapped constant pins). Every case below pins a behavior that
// previously differed (verified against the frozen baseline dist).

test("BUG-007: an equality loop stepping up away from its literal target does not terminate", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 4; while (i != 2) { ++i; } return i; }`);
  assert.equal(result.worstCaseTime, "Does not terminate", result.proof.join(" "));
});

test("BUG-007: an equality loop stepping down away from its literal target does not terminate", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 0; while (i != 5) { --i; } return i; }`);
  assert.equal(result.worstCaseTime, "Does not terminate", result.proof.join(" "));
});

test("BUG-007: a reachable equality loop keeps its constant trip count", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 0; while (i != 5) { ++i; } return i; }`);
  assert.equal(result.worstCaseTime, "O(1)", result.proof.join(" "));
});

test("BUG-007: a numeric start that may lie past a symbolic equality target abstains", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve(int n) { int i = 4; while (i != n) { ++i; } return i; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
  assert.equal(result.confidence, "unknown");
});

test("BUG-007: an unpinned start against a literal equality target abstains", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i; cin >> i; while (i != 5) { ++i; } return i; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
  assert.equal(result.confidence, "unknown");
});

test("BUG-008: a negative compound stride under < is not forward progress", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve(int n) { int i = 0; while (i < n) { i += -1; } return i; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("BUG-008: a negative compound stride under > is forward progress", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve(int n) { int i = n; while (i > 0) { i += -1; } return i; }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("BUG-008: a negative compound stride is not a two-endpoint unit advance", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve(int n) { int l = 0; while (l < n) { l += -1; } return l; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

// Round-6 convention reversal (census reconciliation — see Deep.md): the
// reviewed corpus labels are split on whether a container materialized from
// the input stream counts as auxiliary storage (near-identical programs carry
// `O(n)` and `O(1)` space labels). The majority side, and the 2D-grid family
// whose `cin >> g[i][j]` fills are labeled `O(n m)`, charge the input
// instance; the former input-storage exclusion was therefore reverted and
// this pin now locks the majority convention.
test("space convention: an input-filled local container is charged O(n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() {
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int s = 0; for (int i = 0; i < n; ++i) s += a[i];
    return s;
  }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("space convention: an unfilled sized container is charged O(n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() {
    int n; cin >> n; vector<int> a(n);
    int s = 0; for (int i = 0; i < n; ++i) s += a[i];
    return s;
  }`);
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("space convention: a computed scratch container is charged O(n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() {
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> pref(n + 1); pref[0] = 0;
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    return pref[n];
  }`);
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("BUG-007: a counter reset inside the loop disables the away claim", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 4; while (i != 2) { i = 1; ++i; } return i; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("BUG-007: a condition that wraps the counter disables the away claim", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 4; while (i % 5 != 2) { ++i; } return i; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("BUG-007: a compound literal stride away from its target does not terminate", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 4; while (i != 2) { i += 1; } return i; }`);
  assert.equal(result.worstCaseTime, "Does not terminate", result.proof.join(" "));
});

test("BUG-007: a non-dividing compound stride away from its target does not terminate", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 4; while (i != 2) { i += 2; } return i; }`);
  assert.equal(result.worstCaseTime, "Does not terminate", result.proof.join(" "));
});

test("BUG-007: a dividing compound stride toward its target keeps its trip count", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 8; while (i != 2) { i -= 2; } return i; }`);
  assert.equal(result.worstCaseTime, "O(1)", result.proof.join(" "));
});

test("BUG-010: a cast-wrapped long long accumulator does not seed its own bound", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() {
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = 0; long long sum = 0; int best = 0;
    while (r < n) {
      sum += a[r++];
      while (sum > 100 && l < r) sum -= a[l++];
      if (sum > best) best = (int)sum;
    }
    return best;
  }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  // Space flipped O(1) -> O(n) in the round-6 convention reversal (materialized
  // input containers are charged; see the space-convention tests above). The
  // BUG-010 pin is the time bound — the accumulator no longer seeds `O(sum)`.
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("BUG-011: a cancelling second counter write disables the trip claim", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 0; int s = 0; while (i < 5) { --i; ++i; } return s; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("BUG-011: a reversing second counter write disables the trip claim", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve() { int i = 0; int s = 0; while (i < 10) { i -= 2; s += i; ++i; } return s; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("BUG-011: an oscillating two-pointer endpoint write disables the interval-shrink claim", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve(int n) { int i = 0; int s = 0; while (i <= n) { s += i; ++i; --i; } return s; }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("BUG-011: a single-write counter keeps its charged trip count", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`int solve(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

// --- Round-7 battery (BUG-012..019) -----------------------------------------
// Every case below was verified against the frozen baseline-snapshot dist
// (benchmarks/baseline-snapshot) to differ before the fix; see Deep.md
// "Round 7" for the per-bug audit and .scratch/round7-dual-probe*.mjs for the
// side-by-side evidence.

test("BUG-019: control-flow body-visit seeding bounds insertion sort quadratically", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Before the fix the inner shifting loop contributed no work state, so the
  // outer loop was published as O(n) — a silent under-claim.
  const result = analyseCppSelection(`int f(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
      int x = a[i];
      int j = i - 1;
      while (j >= 0 && a[j] > x) { a[j + 1] = a[j]; --j; }
      a[j + 1] = x;
    }
    return n;
  }`);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
});

test("BUG-011: a pair built from loop-accumulated values composes exactly", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Before the fix the make_pair call was unresolvable and the whole function
  // abstained (Unknown) even though the loop is a plain O(n) scan.
  const result = analyseCppSelection(`pair<int, int> f(const vector<int>& a, int n) {
    int best = 0, at = 0;
    for (int i = 0; i < n; ++i) { if (a[i] > best) { best = a[i]; at = i; } }
    return make_pair(best, at);
  }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("BUG-012: growing a reference-parameter container materializes O(n) storage", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Before the fix the growth of `out` was not charged, publishing O(1).
  const result = analyseCppSelection(`void f(int n, vector<int>& out) { for (int i = 0; i < n; ++i) out.push_back(i * i); }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("BUG-013: an exponential work loop charges exponential storage", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // A proven per-instance product is used directly; before the fix the growth
  // fallback collapsed the 2^n loop to the corpus-convention O(n).
  const result = analyseCppSelection(`vector<int> f(int n) { vector<int> r; for (int i = 0; i < (1 << n); ++i) r.push_back(i); return r; }`);
  assert.equal(result.worstCaseTime, "O(2^n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(2^n)");
});

test("BUG-014: a loop-local buffer charges its own size, not the enclosing loop's", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Peak storage is the transient buffer's own trip count m: loops enclosing
  // the declaration re-materialize the buffer instead of multiplying it.
  const result = analyseCppSelection(`int f(int n, int m) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> tmp;
      for (int j = 0; j < m; ++j) tmp.push_back(j);
      s += tmp[m - 1];
    }
    return s;
  }`);
  assert.equal(result.auxiliarySpace, "O(m)", result.proof.join(" "));
});

test("BUG-014: independent peak allocations combine as their sum", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // `acc` (n) is live while each `row` (m) is materialized: the peak is n + m.
  const result = analyseCppSelection(`vector<int> f(int n, int m) {
    vector<int> acc(n, 0);
    for (int i = 0; i < n; ++i) {
      vector<int> row(m, i);
      for (int j = 0; j < m; ++j) acc[i] += row[j];
    }
    return acc;
  }`);
  assert.equal(result.auxiliarySpace, "O(n + m)", result.proof.join(" "));
});

test("BUG-015: a subscript receiver's size denotes the element dimension", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // `g[i].size()` bounds the inner loop by the row length (m), so the total is
  // n * m; before the fix the receiver's dimension was reused for both loops.
  const result = analyseCppSelection(`long long f(const vector<vector<int>>& g) {
    long long s = 0;
    for (int i = 0; i < (int)g.size(); ++i)
      for (int j = 0; j < (int)g[i].size(); ++j) s += g[i][j];
    return s;
  }`);
  assert.equal(result.worstCaseTime, "O(n m)", result.proof.join(" "));
});

test("sort + full range scan keeps O(1) auxiliary space", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // The library sort's internal storage used to force Unknown auxiliary space
  // even when a proven linear scan follows it.
  const result = analyseCppSelection(`int f(vector<int>& a) {
    sort(a.begin(), a.end());
    int c = 0;
    for (int x : a) if (x == a[0]) ++c;
    return c;
  }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("recursive halving composition solves the Towers of Hanoi recurrence", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`void hanoi(int n, char a, char b, char c) {
    if (n == 0) return;
    hanoi(n - 1, a, c, b);
    hanoi(n - 1, c, b, a);
  }`);
  assert.equal(result.worstCaseTime, "O(2^n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("a composite-marking sieve is recognized in the exact log-log class", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Before the fix the marking loop over multiples was chained as O(n^2) with
  // estimated confidence; the harmonic sum is exactly O(n log log n).
  const result = analyseCppSelection(`int f(int n) {
    vector<bool> comp(n + 1, false);
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
      if (!comp[i]) {
        ++cnt;
        for (int j = i + i; j <= n; j += i) comp[j] = true;
      }
    }
    return cnt;
  }`);
  assert.equal(result.worstCaseTime, "O(n log log n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("BUG-016: single-character appends in a loop are amortized linear", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // `s += s[i]` appends exactly one element; only a string/sequence right-hand
  // side copies proportional to the receiver length.
  const result = analyseCppSelection(`string f(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) r += s[i]; return r; }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("BUG-017: incomparable storage axes combine as their sum", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Count table (k) plus output array (n): before the fix the first allocation
  // won whenever the axes were incomparable, publishing O(k).
  const result = analyseCppSelection(`vector<int> f(const vector<int>& a, int k) {
    vector<int> cnt(k + 1, 0);
    for (int x : a) ++cnt[x];
    vector<int> out(a.size(), 0);
    int w = 0;
    for (int v = 0; v <= k; ++v) for (int c = 0; c < cnt[v]; ++c) out[w++] = v;
    return out;
  }`);
  assert.equal(result.worstCaseTime, "O(n + k)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + k)");
});

test("BUG-018: a stack growing to hold every input element charges O(n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // Container adapters own deque storage; before the fix `stack`/`queue` were
  // absent from the growth-charged container set and the stack claim was O(1).
  const result = analyseCppSelection(`bool f(const string& s) {
    stack<char> st;
    for (char c : s) {
      if (c == '(') st.push(c);
      else if (c == ')') { if (st.empty()) return false; st.pop(); }
    }
    return st.empty();
  }`);
  assert.equal(result.auxiliarySpace, "O(n)", result.proof.join(" "));
});
