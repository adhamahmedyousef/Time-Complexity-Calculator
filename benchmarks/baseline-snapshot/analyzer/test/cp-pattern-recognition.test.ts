import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppFunctionInDocument, analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

test("recognizes Floyd-Warshall from loop topology and matrix relaxation, not its name", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void allPairs(int limit, vector<vector<long long>>& cost) {
      for (int pivot = 0; pivot < limit; ++pivot)
        for (int from = 0; from < limit; ++from)
          if (cost[from][pivot] < 1000000000)
            for (int to = 0; to < limit; ++to)
              if (cost[from][to] > cost[from][pivot] + cost[pivot][to])
                cost[from][to] = cost[from][pivot] + cost[pivot][to];
    }`);
  assert.equal(result.worstCaseTime, "O(n^3)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "estimated");
  assert.equal(result.confidencePercent, 93);
});

test("recognizes Bellman-Ford from repeated edge relaxation rather than name spelling", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<long long> relaxAll(int vertices, const vector<array<int, 3>>& arcs, int source) {
      vector<long long> distance(vertices, 1000000000);
      distance[source] = 0;
      for (int pass = 0; pass < vertices - 1; ++pass)
        for (auto edge : arcs)
          if (distance[edge[1]] > distance[edge[0]] + edge[2])
            distance[edge[1]] = distance[edge[0]] + edge[2];
      return distance;
    }`);
  assert.equal(result.worstCaseTime, "O(n m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidencePercent, 91);
});

test("recognizes deque-based 0-1 BFS structural worklist", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<int> shortest01(vector<vector<pair<int, int>>>& graph, int source) {
      vector<int> distance(graph.size(), 1000000000); deque<int> work;
      distance[source] = 0; work.push_front(source);
      while (!work.empty()) { int u = work.front(); work.pop_front();
        for (auto edge : graph[u]) if (distance[edge.first] > distance[u] + edge.second) {
          distance[edge.first] = distance[u] + edge.second;
          if (edge.second == 0) work.push_front(edge.first); else work.push_back(edge.first);
        }
      }
      return distance;
    }`);
  assert.equal(result.worstCaseTime, "O(V + E)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(V)");
  assert.equal(result.confidencePercent, 91);
});

test("preserves n/m graph dimensions through a same-file CP helper", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const document = `
    vector<int> relax01(int n, vector<vector<pair<int, int>>>& graph, int source) {
      vector<int> dist(n, 1000000000); deque<int> work;
      dist[source] = 0; work.push_front(source);
      while (!work.empty()) { int u = work.front(); work.pop_front();
        for (auto edge : graph[u]) if (dist[edge.first] > dist[u] + edge.second) {
          dist[edge.first] = dist[u] + edge.second;
          if (edge.second == 0) work.push_front(edge.first); else work.push_back(edge.first);
        }
      }
      return dist;
    }
    vector<int> solve(int n, vector<vector<pair<int, int>>>& graph, int source) { return relax01(n, graph, source); }`;
  const result = analyseCppSelection(document, document);
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("recognizes Kahn topological processing from the indegree-to-zero worklist invariant", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<int> orderGraph(int n, vector<vector<int>>& graph) {
      vector<int> indegree(n); queue<int> pending; vector<int> order;
      for (int u = 0; u < n; ++u) for (int v : graph[u]) ++indegree[v];
      for (int u = 0; u < n; ++u) if (indegree[u] == 0) pending.push(u);
      while (!pending.empty()) { int u = pending.front(); pending.pop(); order.push_back(u);
        for (int v : graph[u]) if (--indegree[v] == 0) pending.push(v);
      }
      return order;
    }`);
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidencePercent, 91);
});

test("literal boolean helper arguments specialize a CP worklist branch", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const document = `
    vector<int> process(int n, vector<vector<int>>& graph, bool ordered) {
      vector<int> indegree(n), answer;
      for (int u = 0; u < n; ++u) for (int v : graph[u]) ++indegree[v];
      if (ordered) {
        priority_queue<int> pending;
        for (int u = 0; u < n; ++u) if (indegree[u] == 0) pending.push(u);
        while (!pending.empty()) { int u = pending.top(); pending.pop(); answer.push_back(u);
          for (int v : graph[u]) if (--indegree[v] == 0) pending.push(v);
        }
      } else {
        queue<int> pending;
        for (int u = 0; u < n; ++u) if (indegree[u] == 0) pending.push(u);
        while (!pending.empty()) { int u = pending.front(); pending.pop(); answer.push_back(u);
          for (int v : graph[u]) if (--indegree[v] == 0) pending.push(v);
        }
      }
      return answer;
    }
    vector<int> fifo(int n, vector<vector<int>>& graph) { return process(n, graph, false); }
    vector<int> heap(int n, vector<vector<int>>& graph) { return process(n, graph, true); }`;
  const fifo = analyseCppFunctionInDocument(document, "fifo");
  const heap = analyseCppFunctionInDocument(document, "heap");
  assert.equal(fifo.worstCaseTime, "O(n + m)", fifo.proof.join(" "));
  assert.equal(heap.worstCaseTime, "O((n + m) log n)", heap.proof.join(" "));
  assert.equal(heap.auxiliarySpace, "O(n)", heap.proof.join(" "));
  assert.equal(fifo.confidence, "estimated");
  assert.equal(heap.confidence, "estimated");
});

test("does not call an unrelated cubic matrix loop Floyd-Warshall", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long cube(int n, vector<vector<int>>& matrix) {
      long long answer = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          for (int k = 0; k < n; ++k) answer += matrix[i][j] * k;
      return answer;
    }`);
  assert.equal(result.worstCaseTime, "O(n^3)", result.proof.join(" "));
  assert.notEqual(result.confidencePercent, 93, "a generic cubic loop must not receive Floyd-specific evidence");
});
