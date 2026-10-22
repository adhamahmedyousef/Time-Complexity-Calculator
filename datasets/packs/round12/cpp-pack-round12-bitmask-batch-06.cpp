#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int cf_r12_bitmask_250(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_250(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_251(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_251(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_252(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_252(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_253(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_253(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_254(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_254(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_255(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_255(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_256(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_256(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_257(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_257(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_258(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_258(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_259(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_259(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_260(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_260(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_261(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_261(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_262(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_262(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_263(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_263(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_264(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_264(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_265(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_265(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_266(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_266(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_267(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_267(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_268(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_268(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_269(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_269(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_270(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_270(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_271(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_271(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_272(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_272(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_273(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_273(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_274(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_274(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_275(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_275(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_276(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_276(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_277(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_277(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_278(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_278(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_279(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_279(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_280(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_280(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_281(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_281(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_282(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_282(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_283(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_283(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_284(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_284(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_285(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_285(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_286(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_286(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_287(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_287(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_288(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_288(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_289(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_289(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_290(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_290(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_291(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_291(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_292(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_292(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_293(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_293(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_294(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_294(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_295(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_295(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_296(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_296(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_297(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_297(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_298(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_298(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_299(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_299(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}