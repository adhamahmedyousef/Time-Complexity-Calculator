import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("linear local vector push_back sequence has amortized linear total cost", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void appendAll(int n) {
      vector<int> values;
      for (int i = 0; i < n; ++i) values.push_back(i);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  // The potential-method argument is complete for a flat append-only
  // sequence, so the engine publishes a fully proved exact label.
  assert.equal(result.confidence, "exact");
});

test("nested vector growth is not falsely reduced to linear amortized work", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void nestedAppend(int n) {
      vector<int> values;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) values.push_back(j);
    }`);
  assert.notEqual(result.confidence, "estimated", result.proof.join(" "));
});
