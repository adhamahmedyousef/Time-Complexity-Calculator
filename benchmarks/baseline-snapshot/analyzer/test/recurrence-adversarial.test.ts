import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("duplicate partition branch is not mistaken for QuickSort", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int split(vector<int>& values, int low, int high) { return low; }
    void notQuickSort(vector<int>& values, int low, int high) {
      if (low < high) {
        int pivot = split(values, low, high);
        notQuickSort(values, low, pivot - 1);
        notQuickSort(values, low, pivot - 1);
      }
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("repeated-left-child recursion is not mistaken for a tree traversal", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct Node { Node* left; Node* right; };
    int notTree(Node* root) {
      if (!root) return 0;
      return notTree(root->left) + notTree(root->left);
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("non-progressing backtracking recursion remains unproved", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void notBacktracking(vector<int>& state, int row, int n) {
      if (row == n) return;
      for (int choice = 0; choice < n; ++choice) notBacktracking(state, row, n);
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});
