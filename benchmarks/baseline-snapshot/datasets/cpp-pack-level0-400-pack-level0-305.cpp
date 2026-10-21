#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> cnt(100001); for (int i = 0; i < n; ++i) { int x; cin >> x; ++cnt[x]; } while (q--) { int x; cin >> x; cout << cnt[x] << '\n'; } }
