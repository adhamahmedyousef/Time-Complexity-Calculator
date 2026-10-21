import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("DFS-resolves local Fenwick methods by Clang declaration identity", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    struct BinaryIndexedTree {
      int limit; vector<int> values;
      void adjust(int index, int delta) {
        for (; index <= limit; index += index & -index) values[index] += delta;
      }
      int prefix(int index) {
        int result = 0;
        for (; index > 0; index -= index & -index) result += values[index];
        return result;
      }
    };
    long long process(const vector<pair<int, int>>& operations, int limit) {
      BinaryIndexedTree tree{limit, vector<int>(limit + 1, 0)};
      long long answer = 0;
      for (const auto& operation : operations) {
        tree.adjust(operation.first, operation.second);
        answer += tree.prefix(operation.first);
      }
      return answer;
    }`;
  const result = analyseCppFunctionInDocument(source, "process");
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(limit)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
  assert.deepEqual(result.memoryProfile, { bytesPerUnit: 4, basis: "typed-local-storage" });
});

test("DFS-resolves a free low-bit helper through an input pass", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    void adjust(vector<int>& tree, int limit, int index, int delta) {
      for (; index <= limit; index += index & -index) tree[index] += delta;
    }
    long long process(int n, const vector<int>& values) {
      vector<int> tree(n + 1); long long answer = 0;
      for (int value : values) { adjust(tree, n, value, 1); answer += value; }
      return answer;
    }`;
  const result = analyseCppFunctionInDocument(source, "process");
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("local object ownership composes repeated constructor dimensions into space", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    struct Table { vector<vector<int>> values; Table(int n) : values(n, vector<int>(n, 0)) {} };
    int use(int n) { Table table(n); return table.values[0][0]; }`;
  const result = analyseCppFunctionInDocument(source, "use");
  assert.equal(result.worstCaseTime, "O(1)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n^2)", result.proof.join(" "));
  assert.deepEqual(result.memoryProfile, { bytesPerUnit: 4, basis: "typed-local-storage" });
});

test("nested least-significant-bit walks compose as a two-dimensional Fenwick operation", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    struct Fenwick2D {
      int limit; vector<vector<int>> data;
      Fenwick2D(int n) : limit(n), data(n, vector<int>(n, 0)) {}
      void add(int x, int y) {
        for (int i = x; i <= limit; i += i & -i)
          for (int j = y; j <= limit; j += j & -j) data[i][j] += 1;
      }
    };
    int process(int n, const vector<pair<int, int>>& operations) {
      Fenwick2D tree(n);
      for (const auto& op : operations) tree.add(op.first, op.second);
      return 0;
    }`;
  const result = analyseCppFunctionInDocument(source, "process");
  assert.equal(result.worstCaseTime, "O(n log^2 n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n^2)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});

test("an unrelated similarly named standard member is not a local helper", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    struct Local { int find(int x) { return x; } };
    int use(const vector<int>& values) {
      int result = 0;
      for (int value : values) result += value;
      return result;
    }`;
  const result = analyseCppFunctionInDocument(source, "use");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("reports a typed int payload width for the editor memory scale", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppFunctionInDocument(`
    long long buffered(const vector<int>& input) {
      vector<int> copy(input.size());
      for (size_t i = 0; i < input.size(); ++i) copy[i] = input[i];
      return copy[0];
    }`, "buffered");
  assert.equal(result.auxiliarySpace, "O(n)", result.proof.join(" "));
  assert.deepEqual(result.memoryProfile, { bytesPerUnit: 4, basis: "typed-local-storage" });
});
