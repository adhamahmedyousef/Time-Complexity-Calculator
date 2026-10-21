#include <bits/stdc++.h>
using namespace std;

void sampleBFS(int n, const vector<vector<int>>& g, int s) {
    vector<int> vis(n); queue<int> q; vis[s] = 1; q.push(s);
    while (!q.empty()) { int u = q.front(); q.pop(); for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v); }
}

void sampleDFS(int u, const vector<vector<int>>& g, vector<int>& vis) {
    vis[u] = 1; for (int v : g[u]) if (!vis[v]) sampleDFS(v, g, vis);
}

vector<long long> sampleDijkstra(int n, const vector<vector<pair<int,int>>>& g, int s) {
    vector<long long> d(n, LLONG_MAX); priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    d[s] = 0; q.push({0, s});
    while (!q.empty()) { auto [du, u] = q.top(); q.pop(); if (du != d[u]) continue; for (auto [v, w] : g[u]) if (d[v] > du + w) d[v] = du + w, q.push({d[v], v}); }
    return d;
}

vector<int> sampleTopoKahn(int n, const vector<vector<int>>& g) {
    vector<int> deg(n), order; for (int u = 0; u < n; ++u) for (int v : g[u]) ++deg[v];
    queue<int> q; for (int i = 0; i < n; ++i) if (!deg[i]) q.push(i);
    while (!q.empty()) { int u = q.front(); q.pop(); order.push_back(u); for (int v : g[u]) if (!--deg[v]) q.push(v); }
    return order;
}

void sampleFloydWarshall(vector<vector<long long>>& d) {
    int n = static_cast<int>(d.size());
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

long long samplePrimMST(int n, const vector<vector<pair<int,int>>>& g) {
    vector<int> vis(n); priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; q.push({0, 0}); long long cost = 0;
    while (!q.empty()) { auto [w, u] = q.top(); q.pop(); if (vis[u]) continue; vis[u] = 1; cost += w; for (auto [v, x] : g[u]) if (!vis[v]) q.push({x, v}); }
    return cost;
}
