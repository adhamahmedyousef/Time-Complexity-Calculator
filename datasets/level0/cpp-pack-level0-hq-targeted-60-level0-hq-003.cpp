#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()


static vector<ll> preflevel0_hq_003(const vector<int>& a) {
    vector<ll> p(a.size() + 1);
    for (size_t i = 0; i < a.size(); ++i) p[i + 1] = p[i] + a[i];
    return p;
}
void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto p = preflevel0_hq_003(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << p[r] - p[l - 1] << '\n';
    }
}
