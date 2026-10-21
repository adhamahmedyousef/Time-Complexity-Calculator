import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("path-sensitive CFG analysis caps a finite branch before choosing the worst edge", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void boundedBranch(int n) {
      if (n <= 64) {
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j) {}
      } else {
        for (int i = 0; i < n; ++i) {}
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
  assert.match(result.proof.join(" "), /CFG branch analysis/);
});

test("path-sensitive CFG analysis sums incomparable independent branch costs", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void incomparableBranches(int n, int m, bool chooseN) {
      if (chooseN) {
        for (int i = 0; i < n; ++i) {}
      } else {
        for (int j = 0; j < m; ++j) {}
      }
    }`);
  // Only one branch runs, so max(O(n), O(m)) <= O(n + m): the sum is the
  // sound worst-case bound when the two dimensions cannot be ordered.
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
});

test("path-sensitive CFG analysis handles a finite else edge", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void finiteElse(int n) {
      if (n > 32) {
        for (int i = 0; i < n; ++i) {}
      } else {
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) {}
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("CFG analysis propagates a finite branch guard into a nested loop body", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void guardedInner(int n) {
      for (int i = 0; i < n; ++i) {
        if (i <= 64) {
          for (int j = 0; j < i; ++j) {}
        } else {
          continue;
        }
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.match(result.proof.join(" "), /composed once per loop iteration/);
});

test("CFG analysis keeps a sound upper bound when a break can only shorten the loop", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void opaqueBreak(int n, bool stop) {
      for (int i = 0; i < n; ++i) {
        if (stop) break;
      }
    }`);
  // A break only removes iterations, so the unbroken trip count remains a
  // valid worst-case upper bound.
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});
