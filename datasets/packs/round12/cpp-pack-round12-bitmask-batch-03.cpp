#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int cf_r12_bitmask_100(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_100(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_101(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_101(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_102(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_102(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_103(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_103(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_104(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_104(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_105(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_105(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_106(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_106(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_107(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_107(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_108(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_108(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_109(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_109(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_110(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_110(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_111(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_111(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_112(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_112(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_113(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_113(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_114(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_114(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_115(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_115(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_116(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_116(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_117(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_117(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_118(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_118(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_119(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_119(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_120(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_120(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_121(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_121(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_122(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_122(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_123(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_123(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_124(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_124(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_125(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_125(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_126(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_126(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_127(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_127(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_128(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_128(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_129(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_129(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_130(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_130(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_131(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_131(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_132(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_132(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_133(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_133(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_134(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_134(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_135(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_135(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_136(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_136(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_137(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_137(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_138(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_138(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_139(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_139(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_140(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_140(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_141(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_141(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_142(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_142(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_143(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_143(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_144(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_144(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_145(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_145(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_146(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_146(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_147(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_147(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_148(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_148(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_149(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_149(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}