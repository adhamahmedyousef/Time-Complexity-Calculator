#include <bits/stdc++.h>
using namespace std;

long long sampleMemoFib(int n) { vector<long long> dp(n + 1, -1); function<long long(int)> f = [&](int x) { if (x <= 1) return (long long)x; long long& r = dp[x]; return r != -1 ? r : r = f(x - 1) + f(x - 2); }; return f(n); }
int sampleKnapsack(const vector<int>& w, const vector<int>& value, int W) { vector<int> dp(W + 1); for (int i = 0; i < static_cast<int>(w.size()); ++i) for (int cap = W; cap >= w[i]; --cap) dp[cap] = max(dp[cap], dp[cap - w[i]] + value[i]); return dp[W]; }
int sampleLIS(const vector<int>& a) { vector<int> d; for (int x : a) { auto it = lower_bound(d.begin(), d.end(), x); if (it == d.end()) d.push_back(x); else *it = x; } return static_cast<int>(d.size()); }
long long samplePartitionDP(int n) { vector<long long> dp(n + 1); dp[0] = 1; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; ++j) dp[j] += dp[j - i]; return dp[n]; }
long long sampleBitmaskTSP(const vector<vector<int>>& dist) { int n = static_cast<int>(dist.size()), full = 1 << n; vector<vector<long long>> dp(full, vector<long long>(n, (long long)4e18)); dp[1][0] = 0; for (int mask = 1; mask < full; ++mask) for (int u = 0; u < n; ++u) if (mask & (1 << u)) for (int v = 0; v < n; ++v) if (!(mask & (1 << v))) dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]); return *min_element(dp.back().begin(), dp.back().end()); }
long long sampleCoinChangeWays(const vector<int>& coins, int sum) { vector<long long> dp(sum + 1); dp[0] = 1; for (int c : coins) for (int s = c; s <= sum; ++s) dp[s] += dp[s - c]; return dp[sum]; }
