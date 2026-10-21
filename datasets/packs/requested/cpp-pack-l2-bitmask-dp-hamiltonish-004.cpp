#include <bits/stdc++.h>
using namespace std;

long long pack_l2_bitmaskDpHamiltonish(int n) {
    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    for (int mask = 1; mask < (1 << n); ++mask)
        for (int last = 0; last < n; ++last)
            if (mask & (1 << last))
                for (int prev = 0; prev < n; ++prev)
                    if (mask & (1 << prev))
                        dp[mask][last] += dp[mask ^ (1 << last)][prev];
    return dp.back().empty() ? 0 : dp.back()[0];
}
