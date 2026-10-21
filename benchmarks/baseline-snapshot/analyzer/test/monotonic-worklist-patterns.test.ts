import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("structural monotonic stack charges every pop to a prior input insertion", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    long long solve(const vector<int>& values) {
      vector<int> work;
      long long answer = 0;
      for (int value : values) {
        while (!work.empty() && work.back() > value) work.pop_back();
        work.push_back(value);
        answer += work.size();
      }
      return answer;
    }`, "solve");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("a nested worklist loop that reinserts is not given a monotonic amortized proof", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    void unsafe(const vector<int>& values) {
      deque<int> work;
      for (int value : values) {
        while (!work.empty()) { work.pop_back(); work.push_back(value); }
        work.push_back(value);
      }
    }`, "unsafe");
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});
