#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

bool rec(int n) { if (n == 0) return true; return rec(n - 1) || rec(n - 1); }
int pack_level0_authored_pack_main() { fast(); int n; cin >> n; cout << rec(n) << '\n'; }
