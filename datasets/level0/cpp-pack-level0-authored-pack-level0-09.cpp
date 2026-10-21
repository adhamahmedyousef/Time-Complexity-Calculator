#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    string s, t;
    cin >> s >> t;
    int i = (int)s.size() - 1, j = (int)t.size() - 1;
    while (i >= 0 && j >= 0 && s[i] == t[j]) {
        --i; --j;
    }
    cout << (i + 1) + (j + 1) << '\n';
    return 0;
}
