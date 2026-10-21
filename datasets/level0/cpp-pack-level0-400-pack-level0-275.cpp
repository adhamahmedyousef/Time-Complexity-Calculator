#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; sort(all(a)); while (q--) { int x; cin >> x; cout << lower_bound(all(a), x) - a.begin() << ' '; } }
