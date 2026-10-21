#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; ll ans = 0; for (int mask = 0; mask < (1 << n); ++mask) ans += __builtin_popcount((unsigned)mask); cout << ans << '\n'; }
