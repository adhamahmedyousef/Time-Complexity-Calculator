#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll pw_146(ll a, ll b, ll mod) { ll r = 1; while (b) { if (b & 1) r = r * a % mod; a = a * a % mod; b >>= 1; } return r; } int pack_level0_400_pack_main() { fast(); ll a, b, mod; cin >> a >> b >> mod; cout << pw_146(a, b, mod) << '\n'; }
