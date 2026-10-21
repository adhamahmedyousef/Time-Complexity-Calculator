#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

static ll helperlevel0_hq_039(vector<int> a) {
    unordered_map<int,int> mp;
    for (int x : a) ++mp[x];
    return mp.size();
}
void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << helperlevel0_hq_039(a) << '\n';
}
