#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll pack_level0_hq_targeted_60_f(int n, vector<ll>& dp) {
    if (n <= 1) return 1;
    ll &r = dp[n];
    if (r != -1) return r;
    return r = pack_level0_hq_targeted_60_f(n - 1, dp) + 1;
}
