import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

/**
 * Dependent-loop symbolic summation suite. Each case derives its total from
 * the loop structure (harmonic family, power sums, repeated reduction) -
 * never from the loop's spelling.
 */
const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const run = existsSync(clangPath) ? {} : { skip: true };
const analyse = (source: string) => analyseCppSelection(source, source);

test("harmonic: inner stride equals outer index sums to n log n", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; j += i) ++ans;
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("harmonic inside main with cin keeps the same class", run, () => {
  const r = analyse(`int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; j += i)
        cout << j << '\\n';
  }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("harmonic with linear inner body multiplies the constant body", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; j += i)
        for (int k = 0; k < 10; ++k) ++ans;
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("harmonic with logarithmic grandchild sums to n log^2 n", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; j += i)
        for (int k = 1; k <= j; k *= 2) ++ans;
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n log^2 n)", r.proof.join(" "));
});

test("harmonic with square-root grandchild sums to n^1.5 log n", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; j += i)
        for (int k = 1; k * k <= j; ++k) ++ans;
    return ans; }`);
  assert.equal(r.worstCaseTime, "O(n^1.5 log n)", r.proof.join(" "));
});

test("harmonic inner limit without dependent stride stays quadratic", run, () => {
  const r = analyse(`long long f(int n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; ++j) ++ans;
    return ans; }`);
  // Constant stride: the multiplicative bound n^2/2 is the tight class.
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});

test("repeated sqrt reduction is log log n", run, () => {
  const r = analyse(`long long f(long long n) {
    long long i = n; long long steps = 0;
    while (i > 1) { i = sqrt(i); ++steps; }
    return steps; }`);
  assert.equal(r.worstCaseTime, "O(log log n)", r.proof.join(" "));
});

test("repeated sqrt reduction with an accumulator is log log n", run, () => {
  const r = analyse(`int main() {
    long long n; cin >> n; long long steps = 0;
    while (n > 1) { n = sqrt(n); ++steps; }
    cout << steps; }`);
  assert.equal(r.worstCaseTime, "O(log log n)", r.proof.join(" "));
});

test("repeated division assignment is log n", run, () => {
  const r = analyse(`long long f(long long n) {
    long long steps = 0;
    while (n > 1) { n = n / 2; ++steps; }
    return steps; }`);
  assert.equal(r.worstCaseTime, "O(log n)", r.proof.join(" "));
});

// ---- regression: the documented successful shapes stay correct ----

test("regression: single linear loop", run, () => {
  const r = analyse(`long long f(int n) { long long s = 0; for (int i = 0; i < n; ++i) s += i; return s; }`);
  assert.equal(r.worstCaseTime, "O(n)", r.proof.join(" "));
});

test("regression: doubling loop is logarithmic", run, () => {
  const r = analyse(`long long f(int n) { long long s = 0; for (int i = 1; i <= n; i *= 2) ++s; return s; }`);
  assert.equal(r.worstCaseTime, "O(log n)", r.proof.join(" "));
});

test("regression: square-bound loop is sqrt n", run, () => {
  const r = analyse(`long long f(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) ++s; return s; }`);
  assert.equal(r.worstCaseTime, "O(sqrt n)", r.proof.join(" "));
});

test("regression: independent double loop is quadratic", run, () => {
  const r = analyse(`long long f(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += i; return s; }`);
  assert.equal(r.worstCaseTime, "O(n^2)", r.proof.join(" "));
});

test("regression: geometric outer with independent inner is n log n", run, () => {
  const r = analyse(`long long f(int n) { long long s = 0; for (int i = 1; i <= n; i *= 2) for (int j = 0; j < n; ++j) ++s; return s; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});

test("regression: sort costs n log n", run, () => {
  const r = analyse(`long long f(vector<int> a) { sort(a.begin(), a.end()); return a.empty() ? 0 : a[0]; }`);
  assert.equal(r.worstCaseTime, "O(n log n)", r.proof.join(" "));
});
