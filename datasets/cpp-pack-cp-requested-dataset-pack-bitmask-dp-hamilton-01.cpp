#include <bits/stdc++.h>
using namespace std;

// bitmask-dp-hamilton-01
long long pack_cp_requested_dataset_pack_bitmaskDpHamilton_1(int n) {
    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask)
        for (int last = 0; last < n; ++last)
            if (mask & (1 << last))
                for (int prev = 0; prev < n; ++prev)
                    if (mask & (1 << prev))
                        dp[mask][last] += dp[mask ^ (1 << last)][prev];
    return accumulate(dp.back().begin(), dp.back().end(), 0LL);
}
