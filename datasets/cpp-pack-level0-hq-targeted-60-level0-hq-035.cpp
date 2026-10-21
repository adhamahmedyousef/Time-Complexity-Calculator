#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; ++i) { int x; cin >> x; ++mp[x]; }
    cout << mp.size() << '\n';
}
