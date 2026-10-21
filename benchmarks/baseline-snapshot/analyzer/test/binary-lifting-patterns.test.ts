import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("binary lifting requires a table fill and a visible per-query level climb", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    int answer(const vector<vector<int>>& graph, const vector<pair<int,int>>& queries) {
      int n = graph.size(), levels = 1;
      while ((1 << levels) <= n) ++levels;
      vector<vector<int>> ancestor(levels, vector<int>(n, 0));
      for (int level = 1; level < levels; ++level)
        for (int vertex = 0; vertex < n; ++vertex)
          ancestor[level][vertex] = ancestor[level - 1][ancestor[level - 1][vertex]];
      int total = 0;
      for (auto [first, second] : queries) {
        for (int level = levels - 1; level >= 0; --level)
          if (ancestor[level][first] != ancestor[level][second]) first = ancestor[level][first];
        total += first;
      }
      return total;
    }`, "answer");
  assert.equal(result.worstCaseTime, "O(n log n + m log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n log n)");
  assert.equal(result.confidence, "estimated");
});

test("a lifting table without a query climb does not invent a logarithmic query cost", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    int preprocess(const vector<vector<int>>& graph, const vector<pair<int,int>>& queries) {
      int n = graph.size(), levels = 1;
      while ((1 << levels) <= n) ++levels;
      vector<vector<int>> ancestor(levels, vector<int>(n, 0));
      for (int level = 1; level < levels; ++level)
        for (int vertex = 0; vertex < n; ++vertex)
          ancestor[level][vertex] = ancestor[level - 1][ancestor[level - 1][vertex]];
      int total = 0; for (auto [first, second] : queries) total += first + second;
      return total;
    }`, "preprocess");
  assert.equal(result.worstCaseTime, "O(n log n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n log n)");
});
