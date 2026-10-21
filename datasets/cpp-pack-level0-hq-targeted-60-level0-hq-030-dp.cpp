#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll pack_level0_hq_targeted_60_f(int i, int j, vector<vector<ll>>& dp) {
    if (i == 0 || j == 0) return 0;
    ll &r = dp[i][j];
    if (r != -1) return r;
    return r = max(pack_level0_hq_targeted_60_f(i - 1, j, dp), pack_level0_hq_targeted_60_f(i, j - 1, dp)) + 1;
}
