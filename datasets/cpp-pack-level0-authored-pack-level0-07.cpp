#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)t.size()) {
        if (s[i] != t[j]) break;
        ++i; ++j;
    }
    cout << (i + j) << '\n';
    return 0;
}
