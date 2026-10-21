#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n; cin >> n; unordered_map<int,int> mp; for (int i=0;i<n;++i){ int x; cin >> x; mp[x]++; } cout << mp.size() << '\n'; }
