#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i=0;i<n;++i) cin >> a[i]; int i=0; while (i < n) { if (a[i] & 1) ++i; else i += a[i] % 3 + 1; } cout << i << '\n'; }
