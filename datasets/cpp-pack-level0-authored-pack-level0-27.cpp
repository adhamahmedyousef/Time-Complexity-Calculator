#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n, q; cin >> n >> q; vector<int> f(100000 + 1); while (q--) { int x; cin >> x; ++f[x]; } for (int i=0;i<n;++i) cout << f[i] << ' '; }
