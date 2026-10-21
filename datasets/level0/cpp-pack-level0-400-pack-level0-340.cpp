#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); string s, t; cin >> s >> t; int i = 0, j = 0; while (i < (int)s.size() && j < (int)t.size()) { if (s[i] == t[j]) { ++i; ++j; } else if (s[i] < t[j]) ++i; else ++j; } cout << (i + j) << '\n'; }
