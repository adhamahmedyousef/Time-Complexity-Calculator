import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

/**
 * Metamorphic and negative variants for the dependent-loop families: every
 * repair must generalize across syntax (+= vs j = j + i vs aliased step,
 * while vs for, renamed variables) and must NOT fire on sound-negative
 * shapes (pointer resets, runtime-dependent branches, opaque divisors).
 */
const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const run = existsSync(clangPath) ? {} : { skip: true };
const analyse = (source: string) => analyseCppSelection(source, source);

// ---- harmonic family: syntax metamorphs ----

test("metamorphic: j = j + i form is n log n", run, () => {
  const r = analyse(`long long f(int n) { long long ans = 0;
    for (long long i = 1; i <= n; ++i)
      for (long long j = i; j <= n; j = j + i) ++ans;
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("metamorphic: while-form harmonic is n log n", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
      long long j = i;
      while (j <= n) { ++ans; j += i; }
    }
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("metamorphic: renamed variables keep the harmonic class", run, () => {
  const r = analyse(`long long f(int size) {
    long long hits = 0;
    for (long long step = 1; step <= size; ++step)
      for (long long pos = step; pos <= size; pos += step) ++hits;
    return hits; }`);
  // The renamed parameter produces a renamed dimension — the class is
  // what matters, not the spelling.
  assert.ok(/log /.test(r.worstCaseTime) && /size/.test(r.worstCaseTime),
    "expected <dim> log <dim> with the renamed dimension, got " + r.worstCaseTime);
});

test("metamorphic: aliased step variable is n log n", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
      long long step = i;
      for (long long j = i; j <= n; j += step) ++ans;
    }
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("metamorphic: quotient condition with temporary limit is n log n", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
      long long limit = n / i;
      for (long long j = 1; j <= limit; ++j) ++ans;
    }
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("metamorphic: geometric j = j * 2 starting at i is linear", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (long long i = 1; i <= n; ++i)
      for (long long j = i; j <= n; j = j * 2) ++ans;
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("metamorphic: while-form geometric from i is linear", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
      long long j = i;
      while (j <= n) { ++ans; j *= 2; }
    }
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

// ---- repeated-root family: casts and equivalent spellings ----

test("metamorphic: pow with explicit double cast is log log n", run, () => {
  const r = analyse(`long long f(long long n) {
    long long x = n; long long steps = 0;
    while (x > 2) { x = (long long)pow(x, 0.5); ++steps; }
    return steps; }`);
  assert.equal(r.worstCaseTime, "O(log log n)", r.proof.join(" "));
});

test("metamorphic: unsigned long long repeated sqrt is log log n", run, () => {
  const r = analyse(`long long f(unsigned long long n) {
    unsigned long long x = n; long long steps = 0;
    while (x > 2) { x = (unsigned long long)sqrt((double)x); ++steps; }
    return steps; }`);
  assert.equal(r.worstCaseTime, "O(log log n)", r.proof.join(" "));
});

// ---- monotone cursor: syntax variants and negative shapes ----

test("metamorphic: for-form monotone cursor is linear", run, () => {
  const r = analyse(`long long f(int n, const vector<int>& a) {
    long long hits = 0;
    int fast = 0;
    for (int slow = 0; slow < n; ++slow)
      for (; fast < n && a[fast] <= a[slow]; ++fast) ++hits;
    return hits; }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("metamorphic: renamed monotone pair is linear", run, () => {
  const r = analyse(`long long f(int n, const vector<int>& a) {
    int hi = 0; long long total = 0;
    for (int lo = 0; lo < n; ++lo) {
      while (hi < n && a[hi] < a[lo] + 7) ++hi;
      total += hi - lo;
    }
    return total; }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("negative: a cursor reset every outer iteration is quadratic", run, () => {
  const r = analyse(`long long f(int n, const vector<int>& a) {
    long long total = 0;
    for (int lo = 0; lo < n; ++lo) {
      int hi = lo + 1;
      while (hi < n && a[hi] > a[lo]) ++hi;
      total += hi - lo;
    }
    return total; }`);
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});

test("negative: runtime-dependent branch must not collapse the loop", run, () => {
  const r = analyse(`long long f(int n, bool stop) {
    long long s = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) { ++s; if (stop) break; }
    }
    return s; }`);
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});

test("negative: opaque divisor keeps the sound numerator", run, () => {
  const r = analyse(`long long f(int n, int k) {
    long long s = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n / k; ++j) ++s;
    return s; }`);
  // k is an independent input: the ratio n/k is not summable over i, so the
  // sound upper bound keeps the numerator.
  assert.ok(["O(n^2)", "O(n^2 / k)"].includes(r.worstCaseTime), r.worstCaseTime);
});

// ---- recursion family variants ----

test("metamorphic: n-2 void recursion is linear", run, () => {
  const r = analyse(`void f(int n) { if (n <= 1) return; f(n - 2); }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
  assert.equal(r.auxiliarySpace, "O(n)", r.proof.join(" "));
});

test("metamorphic: halving void recursion is log n", run, () => {
  const r = analyse(`void f(long long n) { if (n <= 1) return; f(n / 2); }`);
  assert.equal(r.worstCaseTime, "O(log n)", r.proof.join(" "));
  assert.equal(r.auxiliarySpace, "O(log n)", r.proof.join(" "));
});

test("negative: no base case stays Unknown", run, () => {
  const r = analyse(`void f(int n) { f(n - 1); }`);
  assert.equal(r.confidence, "unknown");
});

// ---- amortized cursor: negative variant with reset inside a branch ----

test("negative: branch-guarded cursor reset is not amortized-linear", run, () => {
  const r = analyse(`long long f(int n, const vector<int>& a, bool reset) {
    int hi = 0; long long total = 0;
    for (int lo = 0; lo < n; ++lo) {
      if (reset) hi = lo;
      while (hi < n && a[hi] <= a[lo] + 3) ++hi;
      total += hi - lo;
    }
    return total; }`);
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});
