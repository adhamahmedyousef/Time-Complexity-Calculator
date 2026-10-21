#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> cnt(31); while (q--) { int x; cin >> x; for (int b = 0; b < 31; ++b) cnt[b] += (x >> b) & 1; } cout << accumulate(cnt.begin(), cnt.end(), 0LL) << '\n'; }
