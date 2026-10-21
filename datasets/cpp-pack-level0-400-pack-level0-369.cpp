#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; unordered_map<int,int> mp; for (int i = 0; i < n; ++i) { int x; cin >> x; mp[x + i]++; if (i > 3 && mp.count(x)) break; } cout << mp.size() << '\n'; }
