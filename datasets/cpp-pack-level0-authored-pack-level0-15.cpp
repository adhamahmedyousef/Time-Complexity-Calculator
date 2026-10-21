#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    int n;
    cin >> n;
    vector<int> spf(n + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; 1LL * i * i <= n; ++i) if (spf[i] == i) for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i;
    cout << spf[n] << '\n';
    return 0;
}
