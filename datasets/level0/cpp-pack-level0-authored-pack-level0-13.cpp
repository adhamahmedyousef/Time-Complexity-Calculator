#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    long long n;
    cin >> n;
    long long cnt = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) cnt += (i * i == n ? 1 : 2);
    }
    cout << cnt << '\n';
    return 0;
}
