#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static unordered_map<int,int> factor_182(int x) { unordered_map<int,int> mp; for (int p = 2; 1LL * p * p <= x; ++p) while (x % p == 0) { ++mp[p]; x /= p; } if (x > 1) ++mp[x]; return mp; } int pack_level0_400_pack_main() { fast(); int n; cin >> n; auto mp = factor_182(n); cout << mp.size() << '\n'; }
