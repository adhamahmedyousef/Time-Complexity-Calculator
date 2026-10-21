import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("structural coordinate compression proves sort plus unique-and-erase", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long compress(vector<int> values) {
      sort(values.begin(), values.end());
      values.erase(unique(values.begin(), values.end()), values.end());
      return values.size();
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("sorting alone is not mislabeled as coordinate compression", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void onlySort(vector<int>& values) {
      sort(values.begin(), values.end());
  }`);
  assert.equal(result.worstCaseTime, "O(n log n)");
  assert.equal(/deduplication/.test(result.proof.join(" ")), false);
});
