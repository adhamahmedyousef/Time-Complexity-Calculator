import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("partition-shaped recursion is classified as QuickSort worst case", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int splitAroundPivot(vector<int>& values, int low, int high) {
      int pivot = values[high], i = low;
      for (int j = low; j < high; ++j) if (values[j] < pivot) swap(values[i++], values[j]);
      swap(values[i], values[high]); return i;
    }
    void rearrange(vector<int>& values, int low, int high) {
      if (low < high) {
        int pivot = splitAroundPivot(values, low, high);
        rearrange(values, low, pivot - 1);
        rearrange(values, pivot + 1, high);
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("left-right pointer recursion is classified as tree traversal", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct Node { Node* left; Node* right; int value; };
    int visit(Node* root) {
      if (!root) return 0;
      return 1 + visit(root->left) + visit(root->right);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("backtracking includes a resolved non-constant pruning helper", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    bool allowed(vector<int>& board, int row, int col) {
      for (int i = 0; i < row; ++i) if (board[i] == col) return false;
      return true;
    }
    void place(vector<int>& board, int row, int n, int& count) {
      if (row == n) { ++count; return; }
      for (int col = 0; col < n; ++col) if (allowed(board, row, col)) {
        board[row] = col; place(board, row + 1, n, count);
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n n!)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("adversarial two recursive calls without a partition pivot remain unproved", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int ambiguous(int n) {
      if (n <= 1) return n;
      return ambiguous(n - 1) + ambiguous(n / 2);
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("constant-step branching recursion solves its characteristic root", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const tribonacci = analyseCppSelection(`
    long long rec(int n) {
      if (n <= 1) return 1;
      return rec(n - 1) + rec(n - 2) + rec(n - 3);
    }`);
  assert.equal(tribonacci.worstCaseTime, "O(1.839^n)", tribonacci.proof.join(" "));
  assert.equal(tribonacci.auxiliarySpace, "O(n)");

  const balancedStep = analyseCppSelection(`
    long long rec(int n) {
      if (n <= 1) return 1;
      return rec(n - 2) + rec(n - 2);
    }`);
  assert.equal(balancedStep.worstCaseTime, "O(1.414^n)", balancedStep.proof.join(" "));
});

test("polynomial frame work does not hide a direct exponential recurrence", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long rec(int n) {
      if (n <= 1) return 1;
      for (int i = 0; i < n; ++i) { }
      return rec(n - 1) + rec(n - 1);
    }`);
  assert.equal(result.worstCaseTime, "O(2^n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});
