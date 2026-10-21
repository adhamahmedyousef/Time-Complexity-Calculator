#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); long long l, r; cin >> l >> r; while (l < r) { long long m = (l + r) / 2; if (m * m >= r) r = m; else l = m + 1; } cout << l << '\n'; }
