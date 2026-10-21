#include <bits/stdc++.h>
using namespace std;

int pack_l2_binaryLiftingKthAncestor(int n, const vector<pair<int,int>>& queries) {
    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n, -1));
    int ans = 0;
    for (auto [u, k] : queries) {
        for (int bit = 0; bit < LOG; ++bit)
            if (k & (1 << bit)) u = (u >= 0 ? up[min(bit, LOG - 1)][u] : -1);
        ans += max(-1, u);
    }
    return ans;
}
