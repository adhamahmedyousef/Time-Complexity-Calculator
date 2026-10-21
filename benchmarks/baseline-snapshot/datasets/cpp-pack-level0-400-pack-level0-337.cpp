#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; int l = 0, r = 0; ll best = 0, cur = 0; while (r < n) { cur += a[r++]; while (cur > 100 && l < r) cur -= a[l++]; best = max(best, cur); } cout << best << '\n'; }
