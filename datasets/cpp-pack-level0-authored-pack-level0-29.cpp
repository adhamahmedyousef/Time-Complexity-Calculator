#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i=0;i<n;++i) cin >> a[i]; int l=0; long long best=0, cur=0; for (int r=0;r<n;++r){ cur += a[r]; while (cur > 10 && l <= r) cur -= a[l++]; best = max(best, cur); } cout << best << '\n'; }
