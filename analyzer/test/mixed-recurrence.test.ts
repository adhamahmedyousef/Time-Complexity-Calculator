import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("mixed-ratio recurrence uses a numerical Akra-Bazzi exponent", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int mixed(int n) {
      if (n <= 1) return 1;
      return mixed(n / 2) + mixed(n / 3);
    }`);
  assert.equal(result.worstCaseTime, "O(n^0.79)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(log n)");
  assert.equal(result.confidence, "estimated");
});

test("linear local work dominates a sublinear mixed-ratio recurrence", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int mixedWithScan(int n) {
      if (n <= 1) return 1;
      for (int i = 0; i < n; ++i) {}
      return mixedWithScan(n / 2) + mixedWithScan(n / 3);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});

test("mixed call arguments without visible ratios remain Unknown", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int opaqueMixed(int n, int k) {
      if (n <= 1) return 1;
      return opaqueMixed(n - k, k) + opaqueMixed(n / 2, k);
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});
