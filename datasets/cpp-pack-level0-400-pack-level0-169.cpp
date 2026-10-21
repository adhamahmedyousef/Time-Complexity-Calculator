#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

ll g_169(ll a, ll b) { while (b) { ll t = a % b; a = b; b = t; } return a; } int pack_level0_400_pack_main() { fast(); ll a, b; cin >> a >> b; cout << g_169(a, b) << '\n'; }
