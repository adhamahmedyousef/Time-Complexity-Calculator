import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument, analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

test("queue plus visited adjacency traversal is recognized as BFS", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void traverse(vector<vector<int>>& adj, int start) {
      vector<bool> visited(adj.size(), false); queue<int> work;
      work.push(start); visited[start] = true;
      while (!work.empty()) { int u = work.front(); work.pop();
        for (int v : adj[u]) if (!visited[v]) { visited[v] = true; work.push(v); }
      }
    }`);
  assert.equal(result.worstCaseTime, "O(V + E)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(V)");
});

test("recursive visited adjacency traversal is recognized as DFS", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void traverse(vector<vector<int>>& adj, int u, vector<bool>& visited) {
      visited[u] = true;
      for (int v : adj[u]) if (!visited[v]) traverse(adj, v, visited);
    }`);
  assert.equal(result.worstCaseTime, "O(V + E)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(V)");
});

test("priority queue adjacency relaxation is recognized as Dijkstra", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<int> shortest(vector<vector<pair<int, int>>>& adj, int src) {
      int n = (int)adj.size(); vector<int> dist(n, INT_MAX);
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      dist[src] = 0; pq.push({0, src});
      while (!pq.empty()) { auto [d, u] = pq.top(); pq.pop(); if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.push({dist[v], v}); }
      }
      return dist;
    }`);
  assert.equal(result.worstCaseTime, "O((V + E) log V)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(V + E)");
});

test("ordered-set decrease-key adjacency relaxation is recognized as Dijkstra", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<long long> shortest(int n, const vector<vector<pair<int,int>>>& graph, int source) {
      vector<long long> dist(n, (long long)4e18);
      set<pair<long long,int>> work;
      dist[source] = 0;
      work.insert({0, source});
      while (!work.empty()) {
        auto [d, u] = *work.begin();
        work.erase(work.begin());
        if (d != dist[u]) continue;
        for (auto [v, w] : graph[u]) if (dist[v] > d + w) {
          if (dist[v] < (long long)4e18) work.erase({dist[v], v});
          dist[v] = d + w;
          work.insert({dist[v], v});
        }
      }
      return dist;
    }`);
  assert.equal(result.worstCaseTime, "O((n + m) log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + m)");
});

test("dense key-selection MST is recognized structurally as Prim", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long connect(int n, const vector<vector<pair<int, int>>>& graph) {
      vector<long long> best(n, (long long)4e18); vector<char> used(n, 0);
      best[0] = 0; long long answer = 0;
      for (int iteration = 0; iteration < n; ++iteration) {
        int chosen = -1;
        for (int candidate = 0; candidate < n; ++candidate)
          if (!used[candidate] && (chosen == -1 || best[candidate] < best[chosen])) chosen = candidate;
        used[chosen] = 1; answer += best[chosen];
        for (auto [next, weight] : graph[chosen])
          if (!used[next] && weight < best[next]) best[next] = weight;
      }
      return answer;
    }`);
  assert.equal(result.worstCaseTime, "O(n^2 + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("heap frontier MST is distinguished from distance relaxation", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long connect(int n, const vector<vector<pair<int, int>>>& graph) {
      vector<char> used(n, 0);
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> frontier;
      frontier.push({0, 0}); long long answer = 0;
      while (!frontier.empty()) {
        auto [weight, vertex] = frontier.top(); frontier.pop();
        if (used[vertex]) continue;
        used[vertex] = 1; answer += weight;
        for (auto [next, edgeWeight] : graph[vertex])
          if (!used[next]) frontier.push({edgeWeight, next});
      }
      return answer;
    }`);
  assert.equal(result.worstCaseTime, "O(m log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + m)");
  assert.equal(result.confidence, "estimated");
});

test("typed union-find edge scan is recognized as an estimated amortized DSU pass", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct DisjointSet { DisjointSet(int); int find(int); bool unite(int, int); };
    int components(int n, const vector<pair<int, int>>& edges) {
      DisjointSet uf(n);
      for (auto [u, v] : edges) uf.unite(u, v);
      return 0;
    }`);
  assert.equal(result.worstCaseTime, "O((n + m) α(n))", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("same-file adjacency construction is composed with a later graph traversal", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    #include <bits/stdc++.h>
    using namespace std;
    vector<vector<int>> makeGraph(int n, const vector<array<int, 2>>& edges) {
      vector<vector<int>> graph(n);
      for (auto edge : edges) graph[edge[0]].push_back(edge[1]);
      return graph;
    }
    int solve(int n, vector<array<int, 2>> edges) {
      auto graph = makeGraph(n, edges);
      int total = 0;
      for (int u = 0; u < n; ++u) for (int v : graph[u]) total += v;
      return total;
    }`;
  const result = analyseCppFunctionInDocument(source, "solve");
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + m)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});
