#include <bits/stdc++.h>
using namespace std;

long long pack_l2_rerootingDpStructural(int n, const vector<vector<int>>& adj) {
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
