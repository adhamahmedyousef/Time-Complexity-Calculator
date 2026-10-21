#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll preflevel0_hq_011(const vector<int>& a) {
    vector<ll> p(a.size() + 1);
    for (size_t i = 0; i < a.size(); ++i) p[i + 1] = p[i] + a[i];
    return p.back();
}
void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << preflevel0_hq_011(a) + q << '\n';
}
