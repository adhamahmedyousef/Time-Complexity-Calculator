#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, x; cin >> n >> x; int l = 0, r = n - 1; while (l <= r) { int m = (l + r) / 2; if (m == x) break; if (m < x) l = m + 1; else r = m - 1; } cout << min(l, r) << '\n'; }
