#include <bits/stdc++.h>
using namespace std;

long long pack_l1_maskDPHybrid(int n) {
            vector<long long> dp(1 << n, 0);
            for (int mask = 1; mask < (1 << n); ++mask) {
                dp[mask] = dp[mask & (mask - 1)] + __builtin_popcount((unsigned)mask);
            }
            return dp.back();
        }
