#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() { int n; cin >> n; ll ans = 0; for (int mask = 0; mask < (1 << n); ++mask) ans += __builtin_popcount((unsigned)mask); cout << ans << '\n'; }
