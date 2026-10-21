#include <bits/stdc++.h>
using namespace std;

long long pack_l2_primStructural(int n, const vector<vector<pair<int,int>>>& adj) {
    vector<int> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    long long cost = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        cost += w;
        for (auto [v, ww] : adj[u]) if (!vis[v]) pq.push({ww, v});
    }
    return cost;
}
