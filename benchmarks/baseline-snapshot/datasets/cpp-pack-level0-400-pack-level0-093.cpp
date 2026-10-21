#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); string s; cin >> s; int l = 0, r = (int)s.size() - 1; bool ok = true; while (l < r) { if (s[l] != s[r]) ok = false; ++l; --r; } cout << (ok ? 1 : 0) << '\n'; }
