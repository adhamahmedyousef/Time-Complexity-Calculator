#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll build_155(int n) { vector<int> is(n + 1, 1); if (n >= 0) is[0] = 0; if (n >= 1) is[1] = 0; for (int i = 2; 1LL * i * i <= n; ++i) if (is[i]) for (int j = i * i; j <= n; j += i) is[j] = 0; return count(is.begin(), is.end(), 1); } int pack_level0_400_pack_main() { fast(); int n; cin >> n; cout << build_155(n) << '\n'; }
