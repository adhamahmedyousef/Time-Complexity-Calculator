#include <bits/stdc++.h>
using namespace std;

long long pack_l2_zeroOneBfsStructural(int n, const vector<vector<pair<int,int>>>& adj, int s) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    deque<int> dq;
    dist[s] = 0;
    dq.push_back(s);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    int ans = 0;
    for (int x : dist) if (x < INF) ans += x;
    return ans;
}
