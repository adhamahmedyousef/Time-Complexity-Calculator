#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int cf_r12_bitmask_350(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_350(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_351(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_351(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_352(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_352(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_353(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_353(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_354(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_354(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_355(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_355(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_356(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_356(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_357(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_357(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_358(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_358(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_359(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_359(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_360(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_360(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_361(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_361(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_362(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_362(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_363(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_363(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_364(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_364(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_365(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_365(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_366(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_366(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_367(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_367(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_368(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_368(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_369(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_369(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_370(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_370(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_371(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_371(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_372(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_372(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_373(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_373(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_374(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_374(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_375(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_375(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_376(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_376(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_377(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_377(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_378(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_378(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_379(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_379(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_380(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_380(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_381(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_381(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_382(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_382(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_383(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_383(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_384(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_384(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_385(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_385(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_386(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_386(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_387(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_387(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_388(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_388(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_389(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_389(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_390(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_390(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_391(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_391(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_392(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_392(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_393(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_393(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_394(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_394(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_395(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_395(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_396(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_396(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_397(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_397(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_398(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_398(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_399(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_399(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}