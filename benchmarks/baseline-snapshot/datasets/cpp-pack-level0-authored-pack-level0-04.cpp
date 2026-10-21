#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    int n;
    cin >> n;
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) cnt += j;
    }
    cout << cnt << '\n';
    return 0;
}
