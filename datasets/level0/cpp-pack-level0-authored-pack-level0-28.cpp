#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i=0;i<n;++i) cin >> a[i]; int l=0, r=n-1; long long sum=0; while (l<=r) { if (a[l] + a[r] < 0) ++l; else { sum += a[r--]; } } cout << sum << '\n'; }
