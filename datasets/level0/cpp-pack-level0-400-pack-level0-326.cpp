#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll helper_326(int n, int q) { return 1LL * n + q; } int pack_level0_400_pack_main() { fast(); int n, q; cin >> n >> q; cout << helper_326(n, q) << '\n'; }
