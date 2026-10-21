#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

ll fpow(ll a, ll b, ll mod) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}
int pack_level0_authored_pack_main() { fast(); ll a, b, mod; cin >> a >> b >> mod; cout << fpow(a, b, mod) << '\n'; }
