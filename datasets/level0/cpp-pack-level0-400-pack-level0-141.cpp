#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; unordered_map<int,int> mp; for (int x : a) { int t = x; for (int p = 2; 1LL * p * p <= t; ++p) while (t % p == 0) { mp[p]++; t /= p; } if (t > 1) mp[t]++; } cout << mp.size() << '\n'; }
