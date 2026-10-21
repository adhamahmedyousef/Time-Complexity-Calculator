#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll helperlevel0_hq_021(const vector<int>& a) { ll s = 0; for (int x : a) s += x; return s; }
void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << helperlevel0_hq_021(a) << '\n';
}
