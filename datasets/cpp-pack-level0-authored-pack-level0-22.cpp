#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

bool cmp(int a, int b) { return a > b; }
int pack_level0_authored_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i=0;i<n;++i) cin >> a[i]; sort(a.begin(), a.end(), cmp); cout << a[0] << '\n'; }
