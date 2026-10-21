#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll prep_025(const vector<int>& a) { vector<int> b = a; sort(all(b)); return b.empty() ? 0 : b.back(); } int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; ll base = prep_025(a); int q; cin >> q; ll ans = 0; while (q--) { int x; cin >> x; ans += base + x; } cout << ans << '\n'; }
