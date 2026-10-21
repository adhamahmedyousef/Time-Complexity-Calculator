#include <bits/stdc++.h>
using namespace std;

long long pack_l2_bellmanFordStructural(int n, const vector<tuple<int,int,int>>& edges, int s) {
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[s] = 0;
    for (int it = 0; it < n - 1; ++it) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }
    long long ans = 0;
    for (auto x : dist) if (x < INF) ans += x;
    return ans;
}
