#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()

int pack_level0_400_pack_main() { fast(); int n; cin >> n; priority_queue<int> pq; for (int i = 0; i < n; ++i) { int x; cin >> x; pq.push(x); } ll ans = 0; while (!pq.empty()) { ans += pq.top(); pq.pop(); } cout << ans << '\n'; }
