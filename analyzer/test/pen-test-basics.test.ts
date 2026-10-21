import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

function analyse(source: string) {
  process.env.PROJECT_X_CLANG = clangPath;
  return analyseCppSelection(source);
}

test("pen test: three nested canonical loops are cubic", { skip: !clangAvailable }, () => {
  const result = analyse(`void f(int n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k) cout << i + j + k;
  }`);
  assert.equal(result.worstCaseTime, "O(n^3)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("pen test: geometric outer bound with i-dependent work is linear", { skip: !clangAvailable }, () => {
  const result = analyse(`void f(int n) {
    for (int i = 1; i < n; i *= 2)
      for (int j = 0; j < i; ++j) cout << j;
  }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("pen test: a zero multiplicative update is non-terminating", { skip: !clangAvailable }, () => {
  const result = analyse(`void f(int n) { for (int i = 0; i < n; i *= 2) {} }`);
  assert.equal(result.worstCaseTime, "Does not terminate", result.proof.join(" "));
});
