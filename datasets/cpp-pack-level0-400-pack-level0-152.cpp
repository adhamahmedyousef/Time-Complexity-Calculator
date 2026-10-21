#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; ll s = 0; for (int i = 0; i < n; ++i) s += __builtin_popcount((unsigned)i); cout << s << '\n'; }
