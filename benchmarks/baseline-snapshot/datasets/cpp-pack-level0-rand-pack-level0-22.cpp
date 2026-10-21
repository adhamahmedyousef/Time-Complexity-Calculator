// -_- <3

#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vi  = vector<int>;
using pii = pair<int,int>;

#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

constexpr ll INFLL = (ll)4e18;
constexpr int INF  = (int)2e9;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

inline ll add(ll a, ll b) {
    if (a > INFLL - b) return INFLL;
    return a + b;
}

inline ll mul(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > INFLL / b) return INFLL;
    return a * b;
}

ll pack_level0_rand_pack_good(ll n) {
    ll ans = n;
    ans -= (n/2 + n/3 + n/5 + n/7);
    ans += (n/6 + n/10 + n/14 + n/15 + n/21 + n/35);
    ans -= (n/30 + n/42 + n/70 + n/105);
    ans += n/210;

    return ans;
}
