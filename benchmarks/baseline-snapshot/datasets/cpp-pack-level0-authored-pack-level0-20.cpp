#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

ll pack_level0_authored_pack_f(int n, vector<ll>& dp) {
    if (n <= 1) return 1;
    ll &r = dp[n];
    if (r != -1) return r;
    return r = pack_level0_authored_pack_f(n - 1, dp) + pack_level0_authored_pack_f(n - 2, dp);
}
