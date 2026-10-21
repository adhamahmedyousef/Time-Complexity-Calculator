#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> diff(n + 2); while (q--) { int l, r; cin >> l >> r; ++diff[l]; --diff[r+1]; } int cur = 0; for (int i=1;i<=n;++i){ cur += diff[i]; cout << cur << ' '; } }
