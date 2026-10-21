#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll score_113(const string& s) { vector<int> f(26); for (char c : s) ++f[c - 'a']; return accumulate(f.begin(), f.end(), 0LL); } int pack_level0_400_pack_main() { fast(); string s; cin >> s; cout << score_113(s) << '\n'; }
