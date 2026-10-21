import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("a valid selected function survives an unrelated Clang diagnostic in the same file", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    int work(int n) { for (int i = 0; i < n; ++i) {} return 0; }
    int unfinished() { return missing_symbol; }`;
  const result = analyseCppFunctionInDocument(source, "work");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});
