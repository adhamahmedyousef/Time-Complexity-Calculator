#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, m; cin >> n >> m; ll ans = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < m; ++k) ++ans; cout << ans << '\n'; }
