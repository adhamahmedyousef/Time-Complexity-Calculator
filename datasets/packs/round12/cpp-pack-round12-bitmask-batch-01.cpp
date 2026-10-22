#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int cf_r12_bitmask_0(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_0(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_1(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_1(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_2(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_2(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_3(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_3(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_4(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_4(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_5(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_5(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_6(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_6(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_7(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_7(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_8(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_8(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_9(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_9(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_10(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_10(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_11(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_11(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_12(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_12(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_13(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_13(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_14(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_14(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_15(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_15(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_16(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_16(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_17(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_17(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_18(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_18(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_19(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_19(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_20(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_20(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_21(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_21(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_22(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_22(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_23(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_23(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_24(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_24(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_25(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_25(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_26(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_26(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_27(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_27(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_28(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_28(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_29(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_29(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_30(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_30(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_31(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_31(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_32(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_32(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_33(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_33(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_34(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_34(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_35(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_35(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_36(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_36(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_37(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_37(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_38(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_38(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_39(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_39(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_40(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_40(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_41(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_41(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_42(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_42(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_43(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_43(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_44(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_44(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_45(int mask, int u, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
  int n = dist.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return dist[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, dist[u][v] + cf_r12_bitmask_45(mask | (1 << v), v, dist, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_46(int mask, int u, const vector<vector<int>>& adj, vector<vector<int>>& memo) {
  int n = adj.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, adj[u][v] + cf_r12_bitmask_46(mask | (1 << v), v, adj, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_47(int mask, int u, const vector<vector<int>>& cost, vector<vector<int>>& memo) {
  int n = cost.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return 0;
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = INT_MAX / 2;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, cost[u][v] + cf_r12_bitmask_47(mask | (1 << v), v, cost, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_48(int mask, int u, const vector<vector<int>>& reward, vector<vector<int>>& memo) {
  int n = reward.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return reward[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 0;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = max(ans, reward[u][v] + cf_r12_bitmask_48(mask | (1 << v), v, reward, memo));
    }
  }
  return ans;
}
int cf_r12_bitmask_49(int mask, int u, const vector<vector<int>>& graph, vector<vector<int>>& memo) {
  int n = graph.size();
  int fullMask = (1 << n) - 1;
  if (mask == fullMask) return graph[u][0];
  int& ans = memo[mask][u];
  if (ans != -1) return ans;
  ans = 1000000000;
  for (int v = 0; v < n; v++) {
    if (!(mask & (1 << v))) {
      ans = min(ans, graph[u][v] + cf_r12_bitmask_49(mask | (1 << v), v, graph, memo));
    }
  }
  return ans;
}