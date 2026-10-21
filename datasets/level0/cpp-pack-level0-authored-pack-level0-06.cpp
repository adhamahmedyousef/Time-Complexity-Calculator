#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() {
    fast();
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) if (string("aeiou").find(c) != string::npos) ++cnt;
    cout << cnt << '\n';
    return 0;
}
