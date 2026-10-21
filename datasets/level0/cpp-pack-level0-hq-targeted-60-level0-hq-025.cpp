#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> pref(31, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        for (int b = 0; b < 31; ++b) pref[b][i] = pref[b][i - 1] + ((x >> b) & 1);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        ll ans = 0;
        for (int b = 0; b < 31; ++b) ans += pref[b][r] - pref[b][l - 1];
        cout << ans << '\n';
    }
}
