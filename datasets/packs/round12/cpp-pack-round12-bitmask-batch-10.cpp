#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int cf_r12_bitmask_450(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_450(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_451(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_451(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_452(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_452(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_453(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_453(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_454(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_454(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_455(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_455(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_456(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_456(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_457(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_457(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_458(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_458(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_459(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_459(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_460(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_460(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_461(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_461(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_462(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_462(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_463(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_463(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_464(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_464(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_465(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_465(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_466(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_466(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_467(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_467(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_468(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_468(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_469(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_469(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_470(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_470(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_471(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_471(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_472(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_472(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_473(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_473(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_474(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_474(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_475(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_475(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_476(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_476(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_477(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_477(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_478(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_478(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_479(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_479(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_480(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_480(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_481(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_481(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_482(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_482(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_483(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_483(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_484(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_484(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_485(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_485(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_486(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_486(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_487(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_487(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_488(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_488(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_489(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_489(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_490(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_490(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_491(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_491(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_492(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_492(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_493(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_493(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_494(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_494(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_495(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_495(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_496(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_496(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_497(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_497(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_498(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_498(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_499(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_499(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}