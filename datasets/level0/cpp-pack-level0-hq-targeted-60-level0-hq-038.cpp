#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) { int x; cin >> x; s.insert(x); }
    cout << s.size() << '\n';
}
