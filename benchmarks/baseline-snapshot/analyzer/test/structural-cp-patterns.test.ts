import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("fixed-width sliding window is linear rather than quadratic", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int maxSumSubarray(vector<int>& arr, int k) {
      int n = arr.size(), sum = 0;
      for (int i = 0; i < k; ++i) sum += arr[i];
      int answer = sum;
      for (int i = k; i < n; ++i) { sum += arr[i] - arr[i - k]; answer = max(answer, sum); }
      return answer;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "estimated");
});

test("counting sort composes input and value-range dimensions", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<int> countingSort(vector<int>& arr, int maxVal) {
      vector<int> count(maxVal + 1, 0);
      for (int x : arr) count[x]++;
      vector<int> result;
      for (int i = 0; i <= maxVal; ++i) while (count[i]-- > 0) result.push_back(i);
      return result;
    }`);
  assert.equal(result.worstCaseTime, "O(n + maxVal)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + maxVal)");
  assert.equal(result.confidence, "estimated");
});

test("trie-style one-node-per-character insertion is linear", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct TrieNode { TrieNode* children[26] = {nullptr}; bool isEnd = false; };
    void trieInsert(TrieNode* root, string& word) {
      TrieNode* curr = root;
      for (char c : word) { int idx = c - 'a'; if (!curr->children[idx]) curr->children[idx] = new TrieNode(); curr = curr->children[idx]; }
      curr->isEnd = true;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("a loop whose bound is halved by its first inner iteration is logarithmic", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int x(int n) {
      for (int i = 0; i < n; ++i) while (i * i < n) n /= 2;
      return n;
    }`);
  assert.equal(result.worstCaseTime, "O(log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "estimated");
});

test("nested neighbour scans are not mislabeled as ordinary DFS", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
      visited[u] = true;
      for (int v : adj[u]) { for (int i = 0; i < adj[u].size(); ++i) {} if (!visited[v]) dfs(adj, v, visited); }
    }`);
  assert.equal(result.worstCaseTime, "O(V^3)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(V)");
  assert.equal(result.confidence, "estimated");
});
