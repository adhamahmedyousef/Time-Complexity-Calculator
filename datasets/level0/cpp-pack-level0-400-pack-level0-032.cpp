#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll f_032(ll x) { if (x <= 1) return 1; return f_032(x - 1) + f_032(x / 2); } int pack_level0_400_pack_main() { fast(); ll n; cin >> n; cout << f_032(n) << '\n'; }
