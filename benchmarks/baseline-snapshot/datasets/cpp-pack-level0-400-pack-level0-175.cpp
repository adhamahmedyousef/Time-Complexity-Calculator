#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static vector<int> primes_175; static vector<bool> is_175; static void build_175(int n) { is_175.assign(n + 1, true); if (n >= 0) is_175[0] = false; if (n >= 1) is_175[1] = false; for (int i = 2; 1LL * i * i <= n; ++i) if (is_175[i]) for (int j = i * i; j <= n; j += i) is_175[j] = false; for (int i = 2; i <= n; ++i) if (is_175[i]) primes_175.push_back(i); } int pack_level0_400_pack_main() { fast(); int n; cin >> n; build_175(n); cout << primes_175.size() << '\n'; }
