#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); string s; cin >> s; int i = 0; while (i < (int)s.size()) { if (s[i] == '0') i += 2; else i = i / 2 + 1; } cout << i << '\n'; }
