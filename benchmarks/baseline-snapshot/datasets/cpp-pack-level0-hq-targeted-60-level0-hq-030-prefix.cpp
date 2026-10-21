#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] ^ a[i];
    int q; cin >> q;
    while (q--) { int l, r; cin >> l >> r; cout << (pref[r] ^ pref[l - 1]) << '\n'; }
}
