#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n, x; cin >> n >> x; int l = 0, r = n - 1; while (l <= r) { int m = (l + r) / 2; if (m == x) break; if (m < x) l = m + 1; else r = m - 1; } cout << min(l, r) << '\n'; }
