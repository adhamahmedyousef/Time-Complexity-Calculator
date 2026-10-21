import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

/**
 * Soundness trap suite: near-miss shapes where a pattern-matching engine
 * would overclaim or undercount. Every test pins either the correct bound or
 * an honest abstention - an engine that "memorizes" fails this suite.
 */
const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const run = process.env.PROJECT_X_CLANG ? {} : { skip: true };
const analyse = (source: string) => analyseCppSelection(source, source);

// ---- traps: must NOT claim a bound (data-dependent progress) ----

test("trap: a positive data-dependent stride keeps the linear upper bound", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    int i = 0; long long steps = 0;
    while (i < (int)a.size()) { i += a[i] % 5 + 1; ++steps; }
    return steps; }`);
  // The stride is at least 1, so the index strictly grows: O(n) is the
  // sound worst case. Claiming anything smaller would be unsound.
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("trap: pointer chasing stays Unknown", run, () => {
  const r = analyse(`long long f(const vector<int>& nxt, int cur) {
    long long steps = 0;
    while (cur != -1) { cur = nxt[cur]; ++steps; }
    return steps; }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("trap: collatz-style loop with an unrelated counter stays Unknown", run, () => {
  const r = analyse(`long long f(long long n) {
    long long steps = 0;
    while (n != 1) { n = (n % 2 == 0) ? n / 2 : 3 * n + 1; ++steps; }
    return steps; }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("trap: do-while driven by an opaque call stays Unknown", run, () => {
  const r = analyse(`long long f(vector<int>& p) {
    long long cnt = 0;
    do { ++cnt; } while (next_permutation(p.begin(), p.end()));
    return cnt; }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("trap: value-deriving pointer walk stays Unknown", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    int x = a[0];
    while (x < (int)a.size() && a[x] < 100) x = a[x] + 1;
    return x; }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("trap: recursion with data-derived arguments stays Unknown", run, () => {
  const r = analyse(`long long f(const vector<int>& a, int i) {
    if (i >= (int)a.size()) return 0;
    return a[i] + f(a, i + a[i]); }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("trap: memo cache with data-dependent state stays Unknown", run, () => {
  const r = analyse(`long long f(const vector<int>& a, int i, vector<long long>& memo) {
    if (i >= (int)a.size()) return 0;
    if (memo[i] != -1) return memo[i];
    return memo[i] = f(a, i + a[i], memo); }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("trap: fixed-iteration loop with an opaque body stays Unknown", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    long long s = 0;
    for (int i = 0; i < 100; ++i) s += mystery(a, i);
    return s; }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

// ---- traps: must NOT undercount (hidden work) ----

test("guard: binary search on answer composes the feasibility check", run, () => {
  const r = analyse(`bool heavy(const vector<int>& w, int cap);
int f(const vector<int>& w, int S) {
    int lo = 0, hi = S;
    while (lo < hi) { int mid = lo + (hi - lo) / 2;
      if (heavy(w, mid)) hi = mid; else lo = mid + 1; }
    return lo; }`);
  assert.notEqual(r.worstCaseTime, "O(log n)", "a bare log hides the per-iteration check");
});

test("guard: m.find inside iterator comparison composes its logarithm", run, () => {
  const r = analyse(`bool f(const map<int, int>& m, int key) {
    return m.find(key) != m.end(); }`);
  assert.equal(r.worstCaseTime, "O(log n)", r.proof.join(" "));
});

test("guard: cout chaining composes the streamed helper's cost", run, () => {
  const r = analyse(`int h(int x) { int t = 0; for (int i = 0; i < x; ++i) t += i; return t; }
void f(int x) { cout << h(x) << endl; }`);
  // The caller parameter is named x, so the composed bound spells O(x).
  assert.equal(r.worstCaseTime, "O(x)", r.proof.join(" "));
});

test("guard: string += in a loop is quadratic, not linear", run, () => {
  const r = analyse(`string f(int n) {
    string out; for (int i = 0; i < n; ++i) out += 'x'; return out; }`);
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});

test("guard: unordered_map iteration is worst-case quadratic", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    unordered_map<int, int> freq;
    for (int x : a) ++freq[x];
    return (long long)freq.size(); }`);
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});

test("guard: ordered map iteration keeps the logarithmic factor", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    map<int, int> freq;
    for (int x : a) ++freq[x];
    return (long long)freq.size(); }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("guard: two recursive halves in one return is linear, not logarithmic", run, () => {
  const r = analyse(`long long f(int lo, int hi) {
    if (lo >= hi) return 1;
    int mid = lo + (hi - lo) / 2;
    return 1 + f(lo, mid) + f(mid + 1, hi); }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("guard: a single halving call is logarithmic", run, () => {
  const r = analyse(`long long f(long long n) {
    if (n <= 1) return 0;
    return 1 + f(n / 2); }`);
  assert.equal(r.worstCaseTime, "O(log n)", r.proof.join(" "));
});

test("guard: Euclid with assignment chains is logarithmic", run, () => {
  const r = analyse(`long long f(long long a, long long b) {
    while (b != 0) { long long t = a % b; a = b; b = t; }
    return a; }`);
  assert.equal(r.worstCaseTime, "O(log n)", r.proof.join(" "));
});

test("guard: a loop whose counter is unrelated to its condition abstains", run, () => {
  const r = analyse(`long long f(long long n) {
    long long steps = 0;
    while (n > 1) { ++steps; n >>= 1; }
    long long other = 0;
    while (steps > 0) { --steps; other += n; }
    return other; }`);
  assert.notEqual(r.worstCaseTime, "O(1)");
});

// ---- traps: must NOT overcount (tightness) ----

test("tight: indexed reads on a string do not grow auxiliary space", run, () => {
  const r = analyse(`int f(const string& text) {
    int hits = 0;
    for (int i = 0; i < (int)text.size(); ++i) if (text[i] == 'a') ++hits;
    return hits; }`);
  assert.equal(r.auxiliarySpace, "O(1)", r.proof.join(" "));
});

test("tight: writing into a fixed-capacity vector does not grow space", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    vector<long long> cnt(100001, 0);
    for (int x : a) ++cnt[x];
    return cnt[0]; }`);
  assert.equal(r.auxiliarySpace, "O(1)", r.proof.join(" "));
});

test("tight: writing through operator[] into a map grows space", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    map<int, int> freq;
    for (int x : a) ++freq[x];
    return (long long)freq.size(); }`);
  assert.equal(r.auxiliarySpace, "O(n)", r.proof.join(" "));
});

test("tight: push_back loop grows space linearly", run, () => {
  const r = analyse(`vector<int> f(int n) {
    vector<int> out; for (int i = 0; i < n; ++i) out.push_back(i); return out; }`);
  assert.equal(r.auxiliarySpace, "O(n)", r.proof.join(" "));
});

test("tight: a break only shortens the loop - upper bound stands", run, () => {
  const r = analyse(`long long f(const vector<int>& a) {
    long long s = 0;
    for (int x : a) { if (x < 0) break; s += x; }
    return s; }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("tight: incomparable branch dimensions compose as a sum", run, () => {
  const r = analyse(`long long f(int n, int m, bool pick) {
    long long s = 0;
    if (pick) for (int i = 0; i < n; ++i) ++s;
    else for (int j = 0; j < m; ++j) ++s;
    return s; }`);
  assert.equal(r.worstCaseTime, "O(n + m)", r.proof.join(" "));
});

test("tight: a merge-style conjunction loop is the sum of its bounds", run, () => {
  const r = analyse(`long long f(int n, int m, const int* a, const int* b) {
    int l = 0, r = 0; long long s = 0;
    while (l < n && r < m) { if (a[l] < b[r]) ++l; else ++r; ++s; }
    return s; }`);
  assert.equal(r.worstCaseTime, "O(n + m)", r.proof.join(" "));
});

test("tight: shadowing local wins over the parameter of the same name", run, () => {
  const r = analyse(`int f(int n) {
    int n2 = 0;
    for (int i = 0; i < 100; ++i) ++n2;
    return n2; }`);
  assert.equal(r.worstCaseTime, "O(1)", r.proof.join(" "));
});

test("tight: pointer alias with incompatible branch targets stays Unknown", run, () => {
  const r = analyse(`int f(const vector<int>& left, const vector<int>& right, bool pick) {
    const vector<int>* sel = &left;
    if (pick) sel = &right;
    int hits = 0;
    for (int i = 0; i < (int)sel->size(); ++i) ++hits;
    return hits; }`);
  assert.equal(r.worstCaseTime, "Unknown", r.proof.join(" "));
});

test("tight: comments-only selection abstains instead of claiming O(1)", run, () => {
  const r = analyseCppSelection("// nothing here\n// just comments");
  assert.equal(r.confidence, "unknown");
});

test("tight: three sequential loops report the dominant phase", run, () => {
  const r = analyse(`long long f(int n, int m, int q) {
    long long s = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s;
    for (int i = 0; i < m; ++i) ++s;
    for (int i = 0; i < q; ++i) ++s;
    return s; }`);
  assert.equal(r.worstCaseTime, "O(n^2 + m + q)", r.proof.join(" "));
});

test("tight: bit enumeration over all masks is exponential", run, () => {
  const r = analyse(`long long f(int n) {
    long long s = 0;
    for (int mask = 0; mask < (1 << n); ++mask) s += mask;
    return s; }`);
  assert.equal(r.worstCaseTime, "O(2^n)", r.proof.join(" "));
});

test("tight: submask enumeration is 3^n", run, () => {
  const r = analyse(`long long f(int n) {
    long long s = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
      for (int sub = mask; sub; sub = (sub - 1) & mask) ++s;
    return s; }`);
  assert.equal(r.worstCaseTime, "O(3^n)", r.proof.join(" "));
});

test("tight: sieve keeps its log log factor", run, () => {
  const r = analyse(`long long f(int n) {
    vector<bool> composite(n + 1, false); long long primes = 0;
    for (int i = 2; i * i <= n; ++i)
      if (!composite[i]) for (int j = i * i; j <= n; j += i) composite[j] = true;
    for (int i = 2; i <= n; ++i) if (!composite[i]) ++primes;
    return primes; }`);
  assert.equal(r.worstCaseTime, "O(n log log n)", r.proof.join(" "));
});
