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
int pack_cp_requested_dataset_pack_binaryLiftingLca_1(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    LCA_1 lca(adj);
    int score = 0;
    for (auto [u, v] : qs) score += lca.depth[u] + lca.depth[v];
    return score;
}
