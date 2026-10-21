#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll f_016(ll n) { ll ans = 0; while (n > 1) { ++ans; n >>= 1; } return ans; } int pack_level0_400_pack_main() { fast(); ll n; cin >> n; cout << f_016(n) << '\n'; }
