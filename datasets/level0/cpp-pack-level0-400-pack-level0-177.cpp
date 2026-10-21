#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll helper_177(ll n) { ll ans = 0; for (ll i = 1; i * i <= n; ++i) if (n % i == 0) ans += i; return ans; } int pack_level0_400_pack_main() { fast(); ll n; cin >> n; cout << helper_177(n) << '\n'; }
