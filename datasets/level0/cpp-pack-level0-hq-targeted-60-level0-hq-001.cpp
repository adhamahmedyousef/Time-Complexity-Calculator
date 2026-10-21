#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()


void pack_level0_hq_targeted_60_solve() {
    int n, m;
    cin >> n >> m;
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) s1 += i;
    for (int j = 0; j < m; ++j) s2 += j;
    cout << s1 + s2 << '\n';
}
