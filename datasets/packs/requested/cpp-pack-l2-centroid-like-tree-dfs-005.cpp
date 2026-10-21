#include <bits/stdc++.h>
using namespace std;

int pack_l2_centroidLikeTreeDfs(int n, const vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    function<int(int,int)> dfs = [&](int u, int p) -> int {
        vis[u] = 1;
        int sz = 1;
        for (int v : adj[u]) if (v != p && !vis[v]) sz += dfs(v, u);
        return sz;
    };
    return dfs(0, -1);
}
