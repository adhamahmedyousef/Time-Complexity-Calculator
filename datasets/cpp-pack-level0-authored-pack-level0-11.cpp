#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

ll gcd_ll(ll a, ll b) { while (b) { ll t = a % b; a = b; b = t; } return a; }
int pack_level0_authored_pack_main() { fast(); ll a, b; cin >> a >> b; cout << gcd_ll(a, b) << '\n'; }
