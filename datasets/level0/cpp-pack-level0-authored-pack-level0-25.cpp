#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n, q; cin >> n >> q; vector<long long> pref(n + 1); for (int i=0;i<n;++i){ long long x; cin >> x; pref[i+1] = pref[i] + x; } while (q--) { int l, r; cin >> l >> r; cout << pref[r] - pref[l-1] << '\n'; } }
