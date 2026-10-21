#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& order) {
    tin[u] = (int)order.size();
    order.push_back(u);
    for (int v : adj[u]) if (v != p) dfs(v, u, adj, tin, tout, order);
    tout[u] = (int)order.size() - 1;
}
long long pack_l2_eulerTourSubtree(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), order;
    dfs(0, -1, adj, tin, tout, order);
    long long ans = 0;
    for (int u : nodes) ans += tout[u] - tin[u] + 1;
    return ans;
}
