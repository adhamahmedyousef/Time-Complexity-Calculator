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
int bfsTraversal_bf1(const vector<vector<int>>& adj, int src) {
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

// graph-bfs-02
static int bfsTraversal_bf2_helper(const vector<vector<int>>& adj, int src) {
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

int bfsTraversal_bf2(const vector<vector<int>>& adj, int src) {
    return bfsTraversal_bf2_helper(adj, src);
}

// graph-bfs-03
struct bfsTraversal_bf3_cls {
    int run(const vector<vector<int>>& adj, int src) {
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
};

int bfsTraversal_bf3(const vector<vector<int>>& adj, int src) {
    bfsTraversal_bf3_cls x;
    return x.run(adj, src);
}

// graph-dfs-01
int dfsTraversal_df1(const vector<vector<int>>& adj, int src) {
vector<char> vis(adj.size(), 0);
int seen = 0;
auto go = [&](auto&& self, int u) -> void {
    vis[u] = 1;
    ++seen;
    for (int v : adj[u]) if (!vis[v]) self(self, v);
};
go(go, src);
return seen;
}

// graph-dfs-02
static int dfsTraversal_df2_helper(const vector<vector<int>>& adj, int src) {
vector<char> vis(adj.size(), 0);
int seen = 0;
auto go = [&](auto&& self, int u) -> void {
    vis[u] = 1;
    ++seen;
    for (int v : adj[u]) if (!vis[v]) self(self, v);
};
go(go, src);
return seen;
}

int dfsTraversal_df2(const vector<vector<int>>& adj, int src) {
    return dfsTraversal_df2_helper(adj, src);
}

// graph-dfs-03
struct dfsTraversal_df3_cls {
    int run(const vector<vector<int>>& adj, int src) {
vector<char> vis(adj.size(), 0);
int seen = 0;
auto go = [&](auto&& self, int u) -> void {
    vis[u] = 1;
    ++seen;
    for (int v : adj[u]) if (!vis[v]) self(self, v);
};
go(go, src);
return seen;
    }
};

int dfsTraversal_df3(const vector<vector<int>>& adj, int src) {
    dfsTraversal_df3_cls x;
    return x.run(adj, src);
}

// graph-dijkstra-01
long long dijkstraShortest_di1(const vector<vector<pair<int,int>>>& adj, int src) {
const long long INF = 1e18;
vector<long long> dist(adj.size(), INF);
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
dist[src] = 0;
pq.push({0, src});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : adj[u]) if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.push({dist[v], v});
    }
}
return accumulate(dist.begin(), dist.end(), 0LL);
}

// graph-dijkstra-02
static long long dijkstraShortest_di2_helper(const vector<vector<pair<int,int>>>& adj, int src) {
const long long INF = 1e18;
vector<long long> dist(adj.size(), INF);
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
dist[src] = 0;
pq.push({0, src});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : adj[u]) if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.push({dist[v], v});
    }
}
return accumulate(dist.begin(), dist.end(), 0LL);
}

long long dijkstraShortest_di2(const vector<vector<pair<int,int>>>& adj, int src) {
    return dijkstraShortest_di2_helper(adj, src);
}

// graph-dijkstra-03
struct dijkstraShortest_di3_cls {
    long long run(const vector<vector<pair<int,int>>>& adj, int src) {
const long long INF = 1e18;
vector<long long> dist(adj.size(), INF);
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
dist[src] = 0;
pq.push({0, src});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : adj[u]) if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.push({dist[v], v});
    }
}
return accumulate(dist.begin(), dist.end(), 0LL);
    }
};

long long dijkstraShortest_di3(const vector<vector<pair<int,int>>>& adj, int src) {
    dijkstraShortest_di3_cls x;
    return x.run(adj, src);
}

// graph-kahn-01
int kahnTopo_ka1(const vector<vector<int>>& adj, vector<int> indegree) {
queue<int> q;
for (int i = 0; i < (int)adj.size(); ++i) if (indegree[i] == 0) q.push(i);
int seen = 0;
while (!q.empty()) {
    int u = q.front(); q.pop();
    ++seen;
    for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
}
return seen;
}

// graph-kahn-02
static int kahnTopo_ka2_helper(const vector<vector<int>>& adj, vector<int> indegree) {
queue<int> q;
for (int i = 0; i < (int)adj.size(); ++i) if (indegree[i] == 0) q.push(i);
int seen = 0;
while (!q.empty()) {
    int u = q.front(); q.pop();
    ++seen;
    for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
}
return seen;
}

int kahnTopo_ka2(const vector<vector<int>>& adj, vector<int> indegree) {
    return kahnTopo_ka2_helper(adj, indegree);
}

// graph-kahn-03
struct kahnTopo_ka3_cls {
    int run(const vector<vector<int>>& adj, vector<int> indegree) {
queue<int> q;
for (int i = 0; i < (int)adj.size(); ++i) if (indegree[i] == 0) q.push(i);
int seen = 0;
while (!q.empty()) {
    int u = q.front(); q.pop();
    ++seen;
    for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
}
return seen;
    }
};

int kahnTopo_ka3(const vector<vector<int>>& adj, vector<int> indegree) {
    kahnTopo_ka3_cls x;
    return x.run(adj, indegree);
}

// graph-bellman-01
long long pack_project_x_manual_cp_dataset_1_bellmanFord_be1(int V, const vector<tuple<int,int,int>>& edges, int src) {
const long long INF = 1e18;
vector<long long> dist(V, INF);
dist[src] = 0;
for (int it = 0; it < V - 1; ++it) {
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w) dist[v] = dist[u] + w;
    }
}
return accumulate(dist.begin(), dist.end(), 0LL);
}
