#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs1(v, adj, vis, order);
    order.push_back(u);
}
void dfs2(int u, const vector<vector<int>>& radj, vector<int>& vis, vector<int>& comp) {
    vis[u] = 1;
    comp.push_back(u);
    for (int v : radj[u]) if (!vis[v]) dfs2(v, radj, vis, comp);
}
vector<int> pack_l2_kosarajuStructural(int n, const vector<vector<int>>& adj, const vector<vector<int>>& radj) {
    vector<int> vis(n), order;
    for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i, adj, vis, order);
    fill(vis.begin(), vis.end(), 0);
    vector<int> sizes;
    for (int i = n - 1; i >= 0; --i) if (!vis[order[i]]) {
        vector<int> comp;
        dfs2(order[i], radj, vis, comp);
        sizes.push_back((int)comp.size());
    }
    return sizes;
}
