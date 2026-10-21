#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int q, limit; cin >> q >> limit;
    int cur = 0, best = 0;
    while (q--) {
        int x; cin >> x;
        cur += x;
        best = max(best, cur);
        if (cur > limit) cur -= limit / 2;
    }
    cout << best << '\n';
}
