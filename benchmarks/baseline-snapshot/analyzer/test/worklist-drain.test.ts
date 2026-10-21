import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("fill-then-drain priority queue is exactly n log n", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      priority_queue<int> pq;
      for (int value : values) pq.push(value);
      long long total = 0;
      while (!pq.empty()) { total += pq.top(); pq.pop(); }
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "exact");
});

test("fill-then-drain queue and stack add to exact linear work", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const queueDrain = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      queue<int> queue;
      for (int value : values) queue.push(value);
      long long total = 0;
      while (!queue.empty()) { total += queue.front(); queue.pop(); }
      return total;
    }`);
  assert.equal(queueDrain.worstCaseTime, "O(n)", queueDrain.proof.join(" "));
  assert.equal(queueDrain.auxiliarySpace, "O(n)");
  assert.equal(queueDrain.confidence, "exact");
  const stackDrain = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      stack<int> stack;
      for (int value : values) stack.push(value);
      long long total = 0;
      while (!stack.empty()) { total += stack.top(); stack.pop(); }
      return total;
    }`);
  assert.equal(stackDrain.worstCaseTime, "O(n)", stackDrain.proof.join(" "));
});

test("size-positive drain condition matches the same proof", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      priority_queue<int> pq;
      for (int value : values) pq.push(value);
      long long total = 0;
      while (pq.size() > 0) { total += pq.top(); pq.pop(); }
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("a drain body that re-adds elements never claims the drain proof", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      priority_queue<int> pq;
      for (int value : values) pq.push(value);
      while (!pq.empty()) { pq.push(5); pq.pop(); }
      return 0;
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("a drain without a proven fill stays Unknown", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(int n) {
      priority_queue<int> pq;
      long long total = 0;
      if (n > 3) pq.push(3);
      while (!pq.empty()) { total += pq.top(); pq.pop(); }
      return total;
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("two pushes per fill iteration are not claimed as one", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      priority_queue<int> pq;
      for (int value : values) { pq.push(value); pq.push(value + 1); }
      long long total = 0;
      while (!pq.empty()) { total += pq.top(); pq.pop(); }
      return total;
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("a guarded push inside the fill loop is not counted per trip", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      priority_queue<int> pq;
      for (int value : values) { if (value > 0) pq.push(value); }
      long long total = 0;
      while (!pq.empty()) { total += pq.top(); pq.pop(); }
      return total;
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("a second fill loop makes the drain population unprovable with one bound", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values, int m) {
      priority_queue<int> pq;
      for (int value : values) pq.push(value);
      for (int i = 0; i < m; ++i) pq.push(i);
      long long total = 0;
      while (!pq.empty()) { total += pq.top(); pq.pop(); }
      return total;
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("the monotonic stack shrink pattern keeps its amortized result", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long solve(const vector<int>& values) {
      vector<int> work;
      long long answer = 0;
      for (int value : values) {
        while (!work.empty() && work.back() > value) work.pop_back();
        work.push_back(value);
        answer += work.size();
      }
      return answer;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});
