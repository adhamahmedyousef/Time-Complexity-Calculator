#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

int pack_level0_authored_pack_main() { fast(); int n; cin >> n; priority_queue<int> pq; for (int i=0;i<n;++i){ int x; cin >> x; pq.push(x); } long long ans = 0; while (!pq.empty()) { ans += pq.top(); pq.pop(); } cout << ans << '\n'; }
