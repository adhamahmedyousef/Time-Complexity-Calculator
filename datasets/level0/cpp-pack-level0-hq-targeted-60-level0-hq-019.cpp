#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

void solvelevel0_hq_019() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int pos = 0;
    while (pos < n) {
        if (a[pos] & 1) ++pos;
        else pos += a[pos] % 3 + 1;
        if (pos > 1000000) break;
    }
    cout << pos << '\n';
}
int pack_level0_hq_targeted_60_main() { fast(); solvelevel0_hq_019(); }
