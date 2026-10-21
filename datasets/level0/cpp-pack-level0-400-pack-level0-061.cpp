#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; int mn = INT_MAX, mx = INT_MIN; for (int x : a) { mn = min(mn, x); mx = max(mx, x); } cout << (mx - mn) << '\n'; }
