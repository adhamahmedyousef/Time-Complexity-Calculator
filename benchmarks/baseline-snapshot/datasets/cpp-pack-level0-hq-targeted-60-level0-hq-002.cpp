#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()


void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    while (q--) {
        int x; cin >> x;
        ans += lower_bound(all(a), x) - a.begin();
    }
    cout << ans << '\n';
}
