#include <bits/stdc++.h>
using namespace std;

// bitmask-dp-hamilton-01
long long bitmaskDpHamilton_1(int n) {
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

// sos-dp-01
long long sosDp_1(int n) {
    vector<long long> f(1 << n, 1);
    for (int bit = 0; bit < n; ++bit)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (mask & (1 << bit))
                f[mask] += f[mask ^ (1 << bit)];
    return f.back();
}

// digit-dp-01
long long digitDp_1(const string& s) {
    int n = (int)s.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][1] = 1;
    for (int i = 0; i < n; ++i)
        for (int tight = 0; tight <= 1; ++tight)
            for (int d = 0; d <= (tight ? s[i] - '0' : 9); ++d)
                dp[i + 1][tight && d == s[i] - '0'] += dp[i][tight];
    return dp[n][0] + dp[n][1];
}

// interval-dp-01
long long intervalDp_1(const vector<int>& a) {
    int n = (int)a.size();
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int len = 2; len <= n; ++len)
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k)
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
        }
    return n ? dp[0][n - 1] : 0;
}

// dp-unknown-mutual-recursion-01
long long g(int);
long long f(int n) { if (n <= 1) return 1; return g(n - 1) + f(n - 2); }
long long g(int n) { if (n <= 1) return 1; return f(n - 1) + g(n - 2); }
long long pack_cp_requested_dataset_pack_dpUnknownMutualRecursion_1(int n) { return f(n); }
