#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static vector<ll> build_325(const vector<int>& a) { vector<ll> pref(a.size() + 1); for (size_t i = 0; i < a.size(); ++i) pref[i + 1] = pref[i] + a[i]; return pref; } int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; auto pref = build_325(a); while (q--) { int l, r; cin >> l >> r; cout << pref[r] - pref[l - 1] << '\n'; } }
