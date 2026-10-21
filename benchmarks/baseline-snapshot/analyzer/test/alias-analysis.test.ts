import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

test("container reference aliases preserve a vector size bound", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void referenceAlias(const vector<int>& values) {
      const vector<int>& view = values;
      for (int i = 0; i < view.size(); ++i) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("iterator aliases preserve begin/end range cardinality", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void iteratorAliases(const vector<int>& values) {
      auto first = values.begin();
      auto last = values.end();
      for (auto it = first; it != last; ++it) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("data-pointer aliases preserve a vector range bound", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void pointerAliases(const vector<int>& values) {
      const int* cursor = values.data();
      const int* finish = values.data() + values.size();
      for (; cursor != finish; ++cursor) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("unresolved raw pointer ranges remain Unknown", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void unknownPointerRange(int* first, int* last) {
      for (; first != last; ++first) {}
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("pointer-to-container aliases retain a proven iterator range", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void containerPointerAlias(const vector<int>& values) {
      const vector<int>* chosen = &values;
      for (auto it = chosen->begin(); it != chosen->end(); ++it) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("free begin/end iterator aliases retain a vector range bound", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void freeIteratorAliases(vector<int>& values) {
      auto first = begin(values);
      auto last = end(values);
      for (auto it = first; it != last; ++it) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("an indexed nested-container alias retains a safe neighbour-size bound", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void neighbourAlias(const vector<vector<int>>& adj, int u) {
      const auto& neighbours = adj[u];
      for (int i = 0; i < neighbours.size(); ++i) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("pointer aliases with incompatible branch targets remain Unknown", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void ambiguousPointerAlias(const vector<int>& left, const vector<int>& right, bool chooseRight) {
      const vector<int>* selected = &left;
      if (chooseRight) selected = &right;
      for (int i = 0; i < selected->size(); ++i) {}
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});
