#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); ll n; cin >> n; while (n > 1) { if (n & 1) n = n * 3 + 1; else n /= 2; if (n > 1000000) break; } cout << n << '\n'; }
