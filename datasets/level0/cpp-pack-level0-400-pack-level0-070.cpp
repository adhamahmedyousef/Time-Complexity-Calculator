#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll helper_070(const vector<int>& a) { vector<ll> pref(a.size() + 1); for (size_t i = 0; i < a.size(); ++i) pref[i + 1] = pref[i] + a[i]; return pref.back(); } int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; auto base = helper_070(a); while (q--) { int l, r; cin >> l >> r; cout << base + l + r << '\n'; } }
