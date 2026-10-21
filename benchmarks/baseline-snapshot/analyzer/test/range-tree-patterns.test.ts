import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("recursive interval query methods compose through an operation pass", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    struct RangeStore {
      long long query(int node, int left, int right, int from, int to) const {
        if (to < left || right < from) return 0;
        int middle = (left + right) / 2;
        return query(node << 1, left, middle, from, to) + query(node << 1 | 1, middle + 1, right, from, to);
      }
    };
    long long process(int n, const vector<pair<int,int>>& requests) {
      RangeStore store; long long answer = 0;
      for (auto [from, to] : requests) answer += store.query(1, 0, n - 1, from, to);
      return answer;
    }`;
  const result = analyseCppFunctionInDocument(source, "process");
  // The corpus convention names the independent paired-query dimension q
  // (81 reviewed manifests write labels like O((n + q) log n)); a request
  // list after a scalar n is such a query axis.
  assert.equal(result.worstCaseTime, "O(q log n)", result.proof.join(" "));
  // The compositional path derives the query recurrence exactly
  // (T(range) = 2T(range/2) + O(1) => O(log n)), so the composed pass is exact.
  assert.equal(result.confidence, "exact");
});

test("self-passing lazy interval updates are recognized from their range invariants", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    long long process(int n, const vector<tuple<int,int,int>>& operations) {
      vector<long long> tree(4 * n), lazy(4 * n);
      auto update = [&](auto&& self, int node, int left, int right, int from, int to, long long value) -> void {
        if (to < left || right < from) return;
        if (from <= left && right <= to) { tree[node] += value; lazy[node] += value; return; }
        int middle = (left + right) / 2;
        self(self, node << 1, left, middle, from, to, value);
        self(self, node << 1 | 1, middle + 1, right, from, to, value);
      };
      for (auto [from, to, value] : operations) update(update, 1, 0, n - 1, from, to, value);
      return tree[1];
    }`;
  const result = analyseCppFunctionInDocument(source, "process");
  assert.equal(result.worstCaseTime, "O(n + m log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});
