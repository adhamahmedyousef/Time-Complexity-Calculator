#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); ll n; cin >> n; ll cnt = 0; for (ll i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); cout << cnt << '\n'; }
