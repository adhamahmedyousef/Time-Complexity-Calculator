#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; ll cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub; sub = (sub - 1) & mask) ++cnt; cout << cnt << '\n'; }
