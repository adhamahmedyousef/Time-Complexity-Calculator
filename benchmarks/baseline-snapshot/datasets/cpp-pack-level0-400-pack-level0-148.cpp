#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; vector<bool> is(n + 1, true); if (n >= 0) is[0] = false; if (n >= 1) is[1] = false; for (int i = 2; 1LL * i * i <= n; ++i) if (is[i]) for (int j = i * i; j <= n; j += i) is[j] = false; cout << count(is.begin(), is.end(), true) << '\n'; }
