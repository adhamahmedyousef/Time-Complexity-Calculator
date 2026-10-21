#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, m; cin >> n >> m; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; while (n > 0) { if (a[n - 1] > m) n -= a[n - 1] % 2 + 1; else --n; if (n < 0) break; } cout << n << '\n'; }
