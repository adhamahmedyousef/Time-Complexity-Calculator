#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = 0;
    ll sum = 0, best = 0;
    while (r < n) {
        sum += a[r++];
        while (sum > 100 && l < r) sum -= a[l++];
        best = max(best, sum);
    }
    cout << best << '\n';
}
