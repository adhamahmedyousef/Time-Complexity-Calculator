#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) { ll x; cin >> x; pref[i + 1] = pref[i] + x; }
    while (q--) { int l, r; cin >> l >> r; cout << pref[r] - pref[l - 1] << '\n'; }
}
