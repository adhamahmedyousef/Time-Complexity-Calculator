#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); long long l, r; cin >> l >> r; while (l < r) { long long m = (l + r) / 2; if (m * m >= r) r = m; else l = m + 1; } cout << l << '\n'; }
