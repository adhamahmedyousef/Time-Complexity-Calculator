#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static vector<int> primes_181; static vector<bool> is_181; static void build_181(int n) { is_181.assign(n + 1, true); if (n >= 0) is_181[0] = false; if (n >= 1) is_181[1] = false; for (int i = 2; 1LL * i * i <= n; ++i) if (is_181[i]) for (int j = i * i; j <= n; j += i) is_181[j] = false; for (int i = 2; i <= n; ++i) if (is_181[i]) primes_181.push_back(i); } int pack_level0_400_pack_main() { fast(); int n; cin >> n; build_181(n); cout << primes_181.size() << '\n'; }
