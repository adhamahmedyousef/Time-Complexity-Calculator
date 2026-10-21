#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static vector<int> primes_178; static vector<bool> is_178; static void build_178(int n) { is_178.assign(n + 1, true); if (n >= 0) is_178[0] = false; if (n >= 1) is_178[1] = false; for (int i = 2; 1LL * i * i <= n; ++i) if (is_178[i]) for (int j = i * i; j <= n; j += i) is_178[j] = false; for (int i = 2; i <= n; ++i) if (is_178[i]) primes_178.push_back(i); } int pack_level0_400_pack_main() { fast(); int n; cin >> n; build_178(n); cout << primes_178.size() << '\n'; }
