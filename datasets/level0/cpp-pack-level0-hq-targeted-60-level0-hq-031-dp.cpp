#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll pack_level0_hq_targeted_60_f(int i, int j, int k, vector<vector<vector<ll>>>& dp) {
    if (i == 0 || j == 0 || k == 0) return 0;
    ll &r = dp[i][j][k];
    if (r != -1) return r;
    ll a = pack_level0_hq_targeted_60_f(i - 1, j, k, dp), b = pack_level0_hq_targeted_60_f(i, j - 1, k, dp), c = pack_level0_hq_targeted_60_f(i, j, k - 1, dp);
    return r = max(a, max(b, c)) + 1;
}
