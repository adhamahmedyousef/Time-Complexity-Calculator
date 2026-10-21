#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n; cin >> n; ll x = n; while (x > 1) { if (x % 2) x = x * 3 + 1; else x /= 2; if (x > 1000000) break; } cout << x << '\n'; }
