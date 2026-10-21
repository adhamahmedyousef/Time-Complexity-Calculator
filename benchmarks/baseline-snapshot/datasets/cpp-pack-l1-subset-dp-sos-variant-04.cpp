#include <bits/stdc++.h>
using namespace std;

long long pack_l1_subsetDPVariant(int n) {
            vector<long long> dp(1 << n, 0);
            for (int mask = 1; mask < (1 << n); ++mask) {
                for (int bit = 0; bit < n; ++bit) {
                    if (mask & (1 << bit)) dp[mask] += dp[mask ^ (1 << bit)];
                }
            }
            return dp.back();
        }
