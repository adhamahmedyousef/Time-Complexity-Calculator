#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> diff(n + 2); while (q--) { int l, r; cin >> l >> r; ++diff[l]; --diff[r + 1]; } int cur = 0; for (int i = 1; i <= n; ++i) { cur += diff[i]; cout << cur << ' '; } }
