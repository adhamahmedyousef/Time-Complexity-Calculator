#include <bits/stdc++.h>
using namespace std;

long long pack_l2_dijkstraStructural(int n, const vector<vector<pair<int,int>>>& graph, int source) {
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    long long total = 0;
    for (auto x : dist) if (x < INF) total += x;
    return total;
}
