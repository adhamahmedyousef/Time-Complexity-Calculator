#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    string s;
    cin >> s;
    int best = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == s[0]) ++best;
        else break;
    }
    cout << best << '\n';
    return 0;
}
