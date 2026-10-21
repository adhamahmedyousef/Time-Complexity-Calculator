#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll prelevel0_hq_033(int n) { vector<ll> dp(n + 1); dp[0] = 1; for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp[n]; }
void pack_level0_hq_targeted_60_solve() { int n; cin >> n; cout << prelevel0_hq_033(n) << '\n'; }
