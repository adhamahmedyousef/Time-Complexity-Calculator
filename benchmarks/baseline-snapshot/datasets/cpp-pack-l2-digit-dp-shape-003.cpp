#include <bits/stdc++.h>
using namespace std;

long long pack_l2_digitDpShape(const string& s) {
    int n = (int)s.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][1] = 1;
    for (int i = 0; i < n; ++i)
        for (int tight = 0; tight <= 1; ++tight)
            for (int d = 0; d <= (tight ? s[i] - '0' : 9); ++d)
                dp[i + 1][tight && d == s[i] - '0'] += dp[i][tight];
    return dp[n][0] + dp[n][1];
}
