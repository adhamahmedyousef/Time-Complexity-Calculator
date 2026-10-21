#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> p(n); iota(all(p), 1); ll cnt = 0; do { ++cnt; } while (next_permutation(all(p))); cout << cnt << '\n'; }
