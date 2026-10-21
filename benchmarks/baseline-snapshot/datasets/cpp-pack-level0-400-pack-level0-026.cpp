#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll bs_026(const vector<int>& a, int x) { int l = 0, r = (int)a.size() - 1; while (l <= r) { int m = (l + r) / 2; if (a[m] == x) return m; if (a[m] < x) l = m + 1; else r = m - 1; } return -1; } int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; sort(all(a)); int q; cin >> q; ll ans = 0; while (q--) { int x; cin >> x; ans += bs_026(a, x); } cout << ans << '\n'; }
