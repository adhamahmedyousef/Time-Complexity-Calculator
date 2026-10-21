#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll fac_156(int n) { ll r = 1; for (int i = 2; i <= n; ++i) r *= i; return r; } int pack_level0_400_pack_main() { fast(); int n; cin >> n; cout << fac_156(n) << '\n'; }
