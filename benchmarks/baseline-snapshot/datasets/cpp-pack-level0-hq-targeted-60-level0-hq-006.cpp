#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()


ll bslevel0_hq_006(int L, int R) {
    while (L < R) {
        int M = (L + R) >> 1;
        if (M * M >= R) R = M;
        else L = M + 1;
    }
    return L;
}
void pack_level0_hq_targeted_60_solve() {
    int n; cin >> n;
    cout << bslevel0_hq_006(1, n) << '\n';
}
