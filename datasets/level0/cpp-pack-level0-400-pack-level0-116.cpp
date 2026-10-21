#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static string norm_116(string s) { for (char &c : s) if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a'); return s; } int pack_level0_400_pack_main() { fast(); string s; cin >> s; cout << norm_116(s) << '\n'; }
