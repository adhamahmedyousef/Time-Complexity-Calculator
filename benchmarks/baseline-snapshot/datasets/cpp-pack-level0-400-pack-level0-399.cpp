#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i]; while (!a.empty()) { if (a.back() % 2) a.pop_back(); else a.back() /= 2; if (a.size() > 1000) break; } cout << a.size() << '\n'; }
