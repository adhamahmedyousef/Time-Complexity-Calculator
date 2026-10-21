#include <bits/stdc++.h>
using namespace std;

int pack_l2_binaryLiftingLca(int n, const vector<vector<int>>& tree, const vector<pair<int,int>>& qs) {
    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n, -1));
    vector<int> depth(n, 0), parent(n, -1), order = {0};
    for (int i = 0; i < (int)order.size(); ++i)
        for (int v : tree[order[i]]) if (v != parent[order[i]]) {
            parent[v] = order[i];
            depth[v] = depth[order[i]] + 1;
            order.push_back(v);
        }
    for (int k = 1; k < LOG; ++k)
        for (int v = 0; v < n; ++v)
            up[k][v] = up[k - 1][v] < 0 ? -1 : up[k - 1][up[k - 1][v]];
    int total = 0;
    for (auto [u, v] : qs) total += depth[u] + depth[v];
    return total;
}
