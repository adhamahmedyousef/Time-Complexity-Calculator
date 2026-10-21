#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll intervallevel0_hq_032(int n) { vector<vector<ll>> dp(n + 1, vector<ll>(n + 1)); for (int len = 2; len <= n; ++len) for (int l = 0; l + len - 1 < n; ++l) dp[l][l + len - 1] = dp[l + 1][l + len - 1] + 1; return dp[0][n - 1]; }
void pack_level0_hq_targeted_60_solve() { int n; cin >> n; cout << intervallevel0_hq_032(n) << '\n'; }
