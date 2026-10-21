#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = n - 1;
    ll ans = 0;
    while (l <= r) { ans += a[l] + a[r]; ++l; --r; }
    cout << ans << '\n';
}
