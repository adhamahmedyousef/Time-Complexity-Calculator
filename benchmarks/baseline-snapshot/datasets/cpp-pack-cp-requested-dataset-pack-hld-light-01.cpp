#include <bits/stdc++.h>
using namespace std;

// binary-lifting-lca-01
struct LCA_1 {
    vector<vector<int>> up;
    vector<int> depth, parent, order;
    int LOG;
    LCA_1(const vector<vector<int>>& adj) {
        int n = (int)adj.size();
        LOG = 1; while ((1 << LOG) <= n) ++LOG;
        up.assign(LOG, vector<int>(n, -1));
        depth.assign(n, 0); parent.assign(n, -1); order = {0};
        for (int i = 0; i < (int)order.size(); ++i)
            for (int v : adj[order[i]]) if (v != parent[order[i]]) {
                parent[v] = order[i];
                depth[v] = depth[order[i]] + 1;
                order.push_back(v);
            }
        for (int k = 1; k < LOG; ++k)
            for (int v = 0; v < n; ++v)
                up[k][v] = up[k - 1][v] < 0 ? -1 : up[k - 1][up[k - 1][v]];
    }
};
int binaryLiftingLca_1(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    LCA_1 lca(adj);
    int score = 0;
    for (auto [u, v] : qs) score += lca.depth[u] + lca.depth[v];
    return score;
}

// euler-tour-subtree-01
struct EulerTour_1 {
    vector<int> tin, tout, order;
    void dfs(int u, int p, const vector<vector<int>>& adj) {
        tin[u] = (int)order.size();
        order.push_back(u);
        for (int v : adj[u]) if (v != p) dfs(v, u, adj);
        tout[u] = (int)order.size() - 1;
    }
};
long long eulerTourSubtree_1(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    EulerTour_1 et; et.tin.assign(n, 0); et.tout.assign(n, 0);
    et.dfs(0, -1, adj);
    long long ans = 0;
    for (int u : nodes) ans += et.tout[u] - et.tin[u] + 1;
    return ans;
}

// rerooting-dp-01
long long rerootingDp_1(int n, const vector<vector<int>>& adj) {
    vector<int> parent(n, -1), order = {0};
    for (int i = 0; i < (int)order.size(); ++i)
        for (int v : adj[order[i]]) if (v != parent[order[i]]) {
            parent[v] = order[i];
            order.push_back(v);
        }
    vector<long long> sub(n, 1), dp(n, 0);
    for (int i = n - 1; i >= 0; --i)
        for (int v : adj[order[i]]) if (v != parent[order[i]]) sub[order[i]] += sub[v];
    for (int v = 1; v < n; ++v) dp[v] = dp[parent[v]] + n - 2 * sub[v];
    long long ans = 0;
    for (long long x : dp) ans += x;
    return ans;
}

// hld-light-01
int pack_cp_requested_dataset_pack_heavyLightDecomposition_1(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> parent(n, -1), depth(n, 0), heavy(n, -1), size(n, 1);
    vector<int> order = {0};
    for (int i = 0; i < (int)order.size(); ++i) for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        depth[v] = depth[order[i]] + 1;
        order.push_back(v);
    }
    int ans = 0;
    for (auto [u, v] : qs) ans += depth[u] + depth[v] + (heavy[u] == -1);
    return ans;
}
