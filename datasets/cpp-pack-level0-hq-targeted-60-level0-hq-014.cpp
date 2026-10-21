#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void pack_level0_hq_targeted_60_solve() {
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == 'a') ++cnt;
        else if (c == 'b') continue;
        else break;
    }
    cout << cnt << '\n';
}
