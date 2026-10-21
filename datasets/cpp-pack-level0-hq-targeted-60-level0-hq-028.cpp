#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n, q; cin >> n >> q;
    vector<int> c(26);
    for (int i = 0; i < n; ++i) { string s; cin >> s; ++c[s[0] - 'a']; }
    while (q--) { int x; cin >> x; cout << c[x % 26] << '\n'; }
}
