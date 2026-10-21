#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static vector<int> primes_172; static vector<bool> is_172; static void build_172(int n) { is_172.assign(n + 1, true); if (n >= 0) is_172[0] = false; if (n >= 1) is_172[1] = false; for (int i = 2; 1LL * i * i <= n; ++i) if (is_172[i]) for (int j = i * i; j <= n; j += i) is_172[j] = false; for (int i = 2; i <= n; ++i) if (is_172[i]) primes_172.push_back(i); } int pack_level0_400_pack_main() { fast(); int n; cin >> n; build_172(n); cout << primes_172.size() << '\n'; }
