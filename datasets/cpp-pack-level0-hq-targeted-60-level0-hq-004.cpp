#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()


void pack_level0_hq_targeted_60_solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    ll ans = 0;
    for (int x : a) ans += x;
    for (int y : b) ans += y;
    while (q--) { int z; cin >> z; ans += z; }
    cout << ans << '\n';
}
