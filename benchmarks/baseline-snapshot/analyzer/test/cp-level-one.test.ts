import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument, analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("understands a complete bitmask domain as exponential rather than constant", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int explore(int bits) {
      int total = 0;
      for (int state = 0; state < (1 << bits); ++state) total += state;
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(2^bits)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("composes a bit scan inside an exponential mask domain", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int visitStates(int n) {
      int total = 0;
      for (int mask = 0; mask < (1 << n); ++mask)
        for (int bit = 0; bit < n; ++bit)
          if (mask & (1 << bit)) ++total;
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n 2^n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("recognizes the canonical all-submasks enumeration identity", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int enumerate(int n) {
      int total = 0;
      for (int mask = 0; mask < (1 << n); ++mask)
        for (int sub = mask; sub; sub = (sub - 1) & mask) ++total;
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(3^n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("composes a mask DP table with every nested state dimension", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long hamiltonLike(int n) {
      vector<vector<long long>> state(1 << n, vector<long long>(n, 0));
      for (int mask = 1; mask < (1 << n); ++mask)
        for (int last = 0; last < n; ++last)
          if (mask & (1 << last))
            for (int previous = 0; previous < n; ++previous)
              if (mask & (1 << previous))
                state[mask][last] += state[mask ^ (1 << last)][previous];
      return state[0][0];
    }`);
  assert.equal(result.worstCaseTime, "O(n^2 2^n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n 2^n)");
  assert.equal(result.confidence, "exact");
});

test("understands a renamed SOS-style subset DP structurally", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long transformed(int bits) {
      vector<long long> cache(1 << bits, 0);
      for (int state = 1; state < (1 << bits); ++state)
        for (int axis = 0; axis < bits; ++axis)
          if (state & (1 << axis)) cache[state] += cache[state ^ (1 << axis)];
      return cache.back();
    }`);
  assert.equal(result.worstCaseTime, "O(bits 2^bits)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(2^bits)");
  assert.equal(result.confidence, "exact");
});

test("recognizes prefix construction plus an independent range-query pass", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<long long> answerRanges(vector<int>& values, vector<pair<int, int>>& requests) {
      vector<long long> accumulated(values.size() + 1, 0);
      for (int index = 0; index < (int)values.size(); ++index)
        accumulated[index + 1] = accumulated[index] + values[index];
      vector<long long> answers;
      for (auto request : requests)
        answers.push_back(accumulated[request.second + 1] - accumulated[request.first]);
      return answers;
    }`);
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + m)");
  assert.equal(result.confidence, "estimated");
  assert.equal(result.confidencePercent, 91);
});

test("composes a same-file linear prefix-preprocessing helper with range queries", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const document = `
    static vector<long long> makeState(const vector<int>& values) {
      vector<long long> state(values.size() + 1, 0);
      for (size_t i = 0; i < values.size(); ++i) state[i + 1] = state[i] + values[i];
      return state;
    }
    long long answer(const vector<int>& values, const vector<pair<int, int>>& requests) {
      auto state = makeState(values); long long result = 0;
      for (auto [left, right] : requests) result += state[right + 1] - state[left];
      return result;
    }`;
  const result = analyseCppFunctionInDocument(document, "answer");
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});
