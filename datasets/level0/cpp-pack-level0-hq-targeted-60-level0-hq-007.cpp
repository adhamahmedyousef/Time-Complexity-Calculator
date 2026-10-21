#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()


static ll helperlevel0_hq_007(vector<int> a) {
    sort(all(a));
    return a.empty() ? 0 : a.back();
}
void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll base = helperlevel0_hq_007(a);
    ll ans = 0;
    while (q--) { int x; cin >> x; ans += base + x; }
    cout << ans << '\n';
}
