#include <bits/stdc++.h>
using namespace std;

struct Node { Node* next; int val; };

// graph-builder-adjacency-01
long long buildAdjacency_ad1(int n, const vector<pair<int,int>>& edges) {
vector<vector<int>> adj(n);
for (auto [u, v] : edges) adj[u].push_back(v);
long long total = 0;
for (const auto& row : adj) total += row.size();
return total;
}

// graph-builder-adjacency-02
static long long buildAdjacency_ad2_helper(int n, const vector<pair<int,int>>& edges) {
vector<vector<int>> adj(n);
for (auto [u, v] : edges) adj[u].push_back(v);
long long total = 0;
for (const auto& row : adj) total += row.size();
return total;
}

long long buildAdjacency_ad2(int n, const vector<pair<int,int>>& edges) {
    return buildAdjacency_ad2_helper(n, edges);
}

// graph-builder-adjacency-03
struct buildAdjacency_ad3_cls {
    long long run(int n, const vector<pair<int,int>>& edges) {
vector<vector<int>> adj(n);
for (auto [u, v] : edges) adj[u].push_back(v);
long long total = 0;
for (const auto& row : adj) total += row.size();
return total;
    }
};

long long buildAdjacency_ad3(int n, const vector<pair<int,int>>& edges) {
    buildAdjacency_ad3_cls x;
    return x.run(n, edges);
}

// graph-bfs-01
int pack_project_x_manual_cp_dataset_1_bfsTraversal_bf1(const vector<vector<int>>& adj, int src) {
vector<char> vis(adj.size(), 0);
queue<int> q;
vis[src] = 1;
q.push(src);
int seen = 0;
while (!q.empty()) {
    int u = q.front(); q.pop();
    ++seen;
    for (int v : adj[u]) if (!vis[v]) vis[v] = 1, q.push(v);
}
return seen;
}
