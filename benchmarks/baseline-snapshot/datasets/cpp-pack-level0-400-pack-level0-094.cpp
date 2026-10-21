#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); string s; cin >> s; for (char &c : s) if (c == 'a') c = 'b'; cout << s << '\n'; }
