#include <bits/stdc++.h>
using namespace std;

int pack_l2_knapsack01(int W, const vector<pair<int,int>>& items) {
    vector<int> dp(W + 1, 0);
    for (auto [w, val] : items)
        for (int cap = W; cap >= w; --cap)
            dp[cap] = max(dp[cap], dp[cap - w] + val);
    return dp[W];
}
