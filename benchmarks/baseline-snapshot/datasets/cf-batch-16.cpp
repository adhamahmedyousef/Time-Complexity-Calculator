// 16
#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
#define int int64
typedef vector<int> vi;
#define fast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl '\n'

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 3) {
            cout << "1 2 3\n";
            continue;
        }
        vector<int> a;
        for (int i = 1; i <= n - 3; ++i) a.pb(i);
        int x = 0;
        for (int v : a) x ^= v;
        int A = (1LL << 20);
        int B = (1LL << 21);
        int C = x ^ A ^ B;
        a.pb(A);
        a.pb(B);
        a.pb(C);
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
}

int32_t main() {
    fast();
    solve();
    return 0;
}
