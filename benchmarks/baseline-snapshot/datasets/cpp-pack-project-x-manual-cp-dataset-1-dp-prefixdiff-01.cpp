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
long long bellmanFord_be1(int V, const vector<tuple<int,int,int>>& edges, int src) {
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

// graph-bellman-02
static long long bellmanFord_be2_helper(int V, const vector<tuple<int,int,int>>& edges, int src) {
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

long long bellmanFord_be2(int V, const vector<tuple<int,int,int>>& edges, int src) {
    return bellmanFord_be2_helper(V, edges, src);
}

// graph-bellman-03
struct bellmanFord_be3_cls {
    long long run(int V, const vector<tuple<int,int,int>>& edges, int src) {
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
};

long long bellmanFord_be3(int V, const vector<tuple<int,int,int>>& edges, int src) {
    bellmanFord_be3_cls x;
    return x.run(V, edges, src);
}

// graph-floyd-01
long long floydWarshall_fl1(vector<vector<long long>> dist) {
int V = (int)dist.size();
for (int k = 0; k < V; ++k)
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
return dist.empty() ? 0 : dist[0][0];
}

// graph-floyd-02
static long long floydWarshall_fl2_helper(vector<vector<long long>> dist) {
int V = (int)dist.size();
for (int k = 0; k < V; ++k)
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
return dist.empty() ? 0 : dist[0][0];
}

long long floydWarshall_fl2(vector<vector<long long>> dist) {
    return floydWarshall_fl2_helper(dist);
}

// graph-floyd-03
struct floydWarshall_fl3_cls {
    long long run(vector<vector<long long>> dist) {
int V = (int)dist.size();
for (int k = 0; k < V; ++k)
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
return dist.empty() ? 0 : dist[0][0];
    }
};

long long floydWarshall_fl3(vector<vector<long long>> dist) {
    floydWarshall_fl3_cls x;
    return x.run(dist);
}

// graph-tarjan-01
int tarjanScc_ta1(const vector<vector<int>>& adj) {
int n = (int)adj.size(), timer = 0;
vector<int> disc(n, -1), low(n, -1), st, on(n, 0);
int comps = 0;
auto dfs = [&](auto&& self, int u) -> void {
    disc[u] = low[u] = timer++;
    st.push_back(u);
    on[u] = 1;
    for (int v : adj[u]) {
        if (disc[v] == -1) { self(self, v); low[u] = min(low[u], low[v]); }
        else if (on[v]) low[u] = min(low[u], disc[v]);
    }
    if (low[u] == disc[u]) {
        while (!st.empty()) {
            int x = st.back(); st.pop_back(); on[x] = 0;
            if (x == u) break;
        }
        ++comps;
    }
};
for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(dfs, i);
return comps;
}

// graph-tarjan-02
static int tarjanScc_ta2_helper(const vector<vector<int>>& adj) {
int n = (int)adj.size(), timer = 0;
vector<int> disc(n, -1), low(n, -1), st, on(n, 0);
int comps = 0;
auto dfs = [&](auto&& self, int u) -> void {
    disc[u] = low[u] = timer++;
    st.push_back(u);
    on[u] = 1;
    for (int v : adj[u]) {
        if (disc[v] == -1) { self(self, v); low[u] = min(low[u], low[v]); }
        else if (on[v]) low[u] = min(low[u], disc[v]);
    }
    if (low[u] == disc[u]) {
        while (!st.empty()) {
            int x = st.back(); st.pop_back(); on[x] = 0;
            if (x == u) break;
        }
        ++comps;
    }
};
for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(dfs, i);
return comps;
}

int tarjanScc_ta2(const vector<vector<int>>& adj) {
    return tarjanScc_ta2_helper(adj);
}

// graph-tarjan-03
struct tarjanScc_ta3_cls {
    int run(const vector<vector<int>>& adj) {
int n = (int)adj.size(), timer = 0;
vector<int> disc(n, -1), low(n, -1), st, on(n, 0);
int comps = 0;
auto dfs = [&](auto&& self, int u) -> void {
    disc[u] = low[u] = timer++;
    st.push_back(u);
    on[u] = 1;
    for (int v : adj[u]) {
        if (disc[v] == -1) { self(self, v); low[u] = min(low[u], low[v]); }
        else if (on[v]) low[u] = min(low[u], disc[v]);
    }
    if (low[u] == disc[u]) {
        while (!st.empty()) {
            int x = st.back(); st.pop_back(); on[x] = 0;
            if (x == u) break;
        }
        ++comps;
    }
};
for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(dfs, i);
return comps;
    }
};

int tarjanScc_ta3(const vector<vector<int>>& adj) {
    tarjanScc_ta3_cls x;
    return x.run(adj);
}

// graph-bridges-01
int bridgesArticulation_br1(const vector<vector<int>>& adj) {
int n = (int)adj.size(), timer = 0, bridges = 0, cut = 0;
vector<int> tin(n, -1), low(n, -1), vis(n, 0);
auto dfs = [&](auto&& self, int u, int p) -> void {
    vis[u] = 1; tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) if (v != p) {
        if (vis[v]) low[u] = min(low[u], tin[v]);
        else {
            self(self, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) ++bridges;
            if (low[v] >= tin[u] && p != -1) ++cut;
            ++children;
        }
    }
    if (p == -1 && children > 1) ++cut;
};
if (n) dfs(dfs, 0, -1);
return bridges + cut;
}

// graph-bridges-02
static int bridgesArticulation_br2_helper(const vector<vector<int>>& adj) {
int n = (int)adj.size(), timer = 0, bridges = 0, cut = 0;
vector<int> tin(n, -1), low(n, -1), vis(n, 0);
auto dfs = [&](auto&& self, int u, int p) -> void {
    vis[u] = 1; tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) if (v != p) {
        if (vis[v]) low[u] = min(low[u], tin[v]);
        else {
            self(self, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) ++bridges;
            if (low[v] >= tin[u] && p != -1) ++cut;
            ++children;
        }
    }
    if (p == -1 && children > 1) ++cut;
};
if (n) dfs(dfs, 0, -1);
return bridges + cut;
}

int bridgesArticulation_br2(const vector<vector<int>>& adj) {
    return bridgesArticulation_br2_helper(adj);
}

// graph-bridges-03
struct bridgesArticulation_br3_cls {
    int run(const vector<vector<int>>& adj) {
int n = (int)adj.size(), timer = 0, bridges = 0, cut = 0;
vector<int> tin(n, -1), low(n, -1), vis(n, 0);
auto dfs = [&](auto&& self, int u, int p) -> void {
    vis[u] = 1; tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) if (v != p) {
        if (vis[v]) low[u] = min(low[u], tin[v]);
        else {
            self(self, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) ++bridges;
            if (low[v] >= tin[u] && p != -1) ++cut;
            ++children;
        }
    }
    if (p == -1 && children > 1) ++cut;
};
if (n) dfs(dfs, 0, -1);
return bridges + cut;
    }
};

int bridgesArticulation_br3(const vector<vector<int>>& adj) {
    bridgesArticulation_br3_cls x;
    return x.run(adj);
}

// graph-mst-flow-01
long long mstOrFlow_fl1(int n, const vector<tuple<int,int,int>>& edges) {
vector<tuple<int,int,int>> e = edges;
sort(e.begin(), e.end(), [](auto& a, auto& b) { return get<2>(a) < get<2>(b); });
vector<int> p(n); iota(p.begin(), p.end(), 0);
auto find = [&](auto&& self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
long long cost = 0;
for (auto [u, v, w] : e) {
    int a = find(find, u), b = find(find, v);
    if (a != b) p[a] = b, cost += w;
}
return cost;
}

// graph-mst-flow-02
static long long mstOrFlow_fl2_helper(int n, const vector<tuple<int,int,int>>& edges) {
vector<tuple<int,int,int>> e = edges;
sort(e.begin(), e.end(), [](auto& a, auto& b) { return get<2>(a) < get<2>(b); });
vector<int> p(n); iota(p.begin(), p.end(), 0);
auto find = [&](auto&& self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
long long cost = 0;
for (auto [u, v, w] : e) {
    int a = find(find, u), b = find(find, v);
    if (a != b) p[a] = b, cost += w;
}
return cost;
}

long long mstOrFlow_fl2(int n, const vector<tuple<int,int,int>>& edges) {
    return mstOrFlow_fl2_helper(n, edges);
}

// graph-mst-flow-03
struct mstOrFlow_fl3_cls {
    long long run(int n, const vector<tuple<int,int,int>>& edges) {
vector<tuple<int,int,int>> e = edges;
sort(e.begin(), e.end(), [](auto& a, auto& b) { return get<2>(a) < get<2>(b); });
vector<int> p(n); iota(p.begin(), p.end(), 0);
auto find = [&](auto&& self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
long long cost = 0;
for (auto [u, v, w] : e) {
    int a = find(find, u), b = find(find, v);
    if (a != b) p[a] = b, cost += w;
}
return cost;
    }
};

long long mstOrFlow_fl3(int n, const vector<tuple<int,int,int>>& edges) {
    mstOrFlow_fl3_cls x;
    return x.run(n, edges);
}

// helper-fenwick-01
long long fenwickPrefix_fen1(int n, const vector<int>& values) {
struct Fenwick {
    int n; vector<long long> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
    long long sum(int i) const { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
};
Fenwick ft(n);
long long ans = 0;
for (int i = 1; i <= n; ++i) { ft.add(i, values[i - 1]); ans += ft.sum(i); }
return ans;
}

// helper-fenwick-02
static long long fenwickPrefix_fen2_helper(int n, const vector<int>& values) {
struct Fenwick {
    int n; vector<long long> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
    long long sum(int i) const { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
};
Fenwick ft(n);
long long ans = 0;
for (int i = 1; i <= n; ++i) { ft.add(i, values[i - 1]); ans += ft.sum(i); }
return ans;
}

long long fenwickPrefix_fen2(int n, const vector<int>& values) {
    return fenwickPrefix_fen2_helper(n, values);
}

// helper-fenwick-03
struct fenwickPrefix_fen3_cls {
    long long run(int n, const vector<int>& values) {
struct Fenwick {
    int n; vector<long long> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
    long long sum(int i) const { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
};
Fenwick ft(n);
long long ans = 0;
for (int i = 1; i <= n; ++i) { ft.add(i, values[i - 1]); ans += ft.sum(i); }
return ans;
    }
};

long long fenwickPrefix_fen3(int n, const vector<int>& values) {
    fenwickPrefix_fen3_cls x;
    return x.run(n, values);
}

// helper-fenwick2d-01
long long fenwick2DQuery_f2d1(int n, const vector<tuple<int,int,int>>& ops) {
struct Fenwick2D {
    int n; vector<vector<long long>> bit;
    explicit Fenwick2D(int n) : n(n), bit(n + 1, vector<long long>(n + 1, 0)) {}
    void add(int x, int y, long long v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= n; j += j & -j)
                bit[i][j] += v;
    }
    long long sum(int x, int y) const {
        long long s = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                s += bit[i][j];
        return s;
    }
};
Fenwick2D ft(n);
long long ans = 0;
for (auto [x, y, v] : ops) { ft.add(x, y, v); ans += ft.sum(x, y); }
return ans;
}

// helper-fenwick2d-02
static long long fenwick2DQuery_f2d2_helper(int n, const vector<tuple<int,int,int>>& ops) {
struct Fenwick2D {
    int n; vector<vector<long long>> bit;
    explicit Fenwick2D(int n) : n(n), bit(n + 1, vector<long long>(n + 1, 0)) {}
    void add(int x, int y, long long v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= n; j += j & -j)
                bit[i][j] += v;
    }
    long long sum(int x, int y) const {
        long long s = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                s += bit[i][j];
        return s;
    }
};
Fenwick2D ft(n);
long long ans = 0;
for (auto [x, y, v] : ops) { ft.add(x, y, v); ans += ft.sum(x, y); }
return ans;
}

long long fenwick2DQuery_f2d2(int n, const vector<tuple<int,int,int>>& ops) {
    return fenwick2DQuery_f2d2_helper(n, ops);
}

// helper-fenwick2d-03
struct fenwick2DQuery_f2d3_cls {
    long long run(int n, const vector<tuple<int,int,int>>& ops) {
struct Fenwick2D {
    int n; vector<vector<long long>> bit;
    explicit Fenwick2D(int n) : n(n), bit(n + 1, vector<long long>(n + 1, 0)) {}
    void add(int x, int y, long long v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= n; j += j & -j)
                bit[i][j] += v;
    }
    long long sum(int x, int y) const {
        long long s = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                s += bit[i][j];
        return s;
    }
};
Fenwick2D ft(n);
long long ans = 0;
for (auto [x, y, v] : ops) { ft.add(x, y, v); ans += ft.sum(x, y); }
return ans;
    }
};

long long fenwick2DQuery_f2d3(int n, const vector<tuple<int,int,int>>& ops) {
    fenwick2DQuery_f2d3_cls x;
    return x.run(n, ops);
}

// helper-segment-01
long long segmentTreeRange_seg1(const vector<int>& a, const vector<pair<int,int>>& qs) {
struct Seg {
    int n; vector<long long> t;
    Seg(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0) {
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            t[p] = t[p << 1] + t[p << 1 | 1];
        };
        if (n) build(build, 1, 0, n - 1);
    }
    long long query(int p, int l, int r, int ql, int qr) const {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[p];
        int m = (l + r) / 2;
        return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
    }
};
Seg st(a);
long long ans = 0;
for (auto [l, r] : qs) if (!a.empty()) ans += st.query(1, 0, (int)a.size() - 1, l, r);
return ans;
}

// helper-segment-02
static long long segmentTreeRange_seg2_helper(const vector<int>& a, const vector<pair<int,int>>& qs) {
struct Seg {
    int n; vector<long long> t;
    Seg(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0) {
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            t[p] = t[p << 1] + t[p << 1 | 1];
        };
        if (n) build(build, 1, 0, n - 1);
    }
    long long query(int p, int l, int r, int ql, int qr) const {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[p];
        int m = (l + r) / 2;
        return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
    }
};
Seg st(a);
long long ans = 0;
for (auto [l, r] : qs) if (!a.empty()) ans += st.query(1, 0, (int)a.size() - 1, l, r);
return ans;
}

long long segmentTreeRange_seg2(const vector<int>& a, const vector<pair<int,int>>& qs) {
    return segmentTreeRange_seg2_helper(a, qs);
}

// helper-segment-03
struct segmentTreeRange_seg3_cls {
    long long run(const vector<int>& a, const vector<pair<int,int>>& qs) {
struct Seg {
    int n; vector<long long> t;
    Seg(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0) {
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            t[p] = t[p << 1] + t[p << 1 | 1];
        };
        if (n) build(build, 1, 0, n - 1);
    }
    long long query(int p, int l, int r, int ql, int qr) const {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[p];
        int m = (l + r) / 2;
        return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
    }
};
Seg st(a);
long long ans = 0;
for (auto [l, r] : qs) if (!a.empty()) ans += st.query(1, 0, (int)a.size() - 1, l, r);
return ans;
    }
};

long long segmentTreeRange_seg3(const vector<int>& a, const vector<pair<int,int>>& qs) {
    segmentTreeRange_seg3_cls x;
    return x.run(a, qs);
}

// helper-sparse-01
long long sparseTableQuery_sp1(const vector<int>& a, const vector<pair<int,int>>& qs) {
int n = (int)a.size();
int K = 1; while ((1 << K) <= n) ++K;
vector<vector<int>> st(K, vector<int>(n));
if (n) st[0] = a;
for (int k = 1; k < K; ++k)
    for (int i = 0; i + (1 << k) <= n; ++i)
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
long long ans = 0;
for (auto [l, r] : qs) if (n) {
    int len = r - l + 1, k = 31 - __builtin_clz(len);
    ans += min(st[k][l], st[k][r - (1 << k) + 1]);
}
return ans;
}

// helper-sparse-02
static long long sparseTableQuery_sp2_helper(const vector<int>& a, const vector<pair<int,int>>& qs) {
int n = (int)a.size();
int K = 1; while ((1 << K) <= n) ++K;
vector<vector<int>> st(K, vector<int>(n));
if (n) st[0] = a;
for (int k = 1; k < K; ++k)
    for (int i = 0; i + (1 << k) <= n; ++i)
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
long long ans = 0;
for (auto [l, r] : qs) if (n) {
    int len = r - l + 1, k = 31 - __builtin_clz(len);
    ans += min(st[k][l], st[k][r - (1 << k) + 1]);
}
return ans;
}

long long sparseTableQuery_sp2(const vector<int>& a, const vector<pair<int,int>>& qs) {
    return sparseTableQuery_sp2_helper(a, qs);
}

// helper-sparse-03
struct sparseTableQuery_sp3_cls {
    long long run(const vector<int>& a, const vector<pair<int,int>>& qs) {
int n = (int)a.size();
int K = 1; while ((1 << K) <= n) ++K;
vector<vector<int>> st(K, vector<int>(n));
if (n) st[0] = a;
for (int k = 1; k < K; ++k)
    for (int i = 0; i + (1 << k) <= n; ++i)
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
long long ans = 0;
for (auto [l, r] : qs) if (n) {
    int len = r - l + 1, k = 31 - __builtin_clz(len);
    ans += min(st[k][l], st[k][r - (1 << k) + 1]);
}
return ans;
    }
};

long long sparseTableQuery_sp3(const vector<int>& a, const vector<pair<int,int>>& qs) {
    sparseTableQuery_sp3_cls x;
    return x.run(a, qs);
}

// helper-trie-01
int trieOperations_tr1(const vector<string>& words) {
struct Trie {
    struct Node { array<int, 26> nxt; int end = 0; Node() { nxt.fill(-1); } };
    vector<Node> t;
    Trie() { t.emplace_back(); }
    void add(const string& s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) { t[u].nxt[x] = (int)t.size(); t.emplace_back(); }
            u = t[u].nxt[x];
        }
        ++t[u].end;
    }
    bool contains(const string& s) const {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) return false;
            u = t[u].nxt[x];
        }
        return t[u].end > 0;
    }
};
Trie tr;
for (auto& w : words) tr.add(w);
return (int)tr.t.size();
}

// helper-trie-02
static int trieOperations_tr2_helper(const vector<string>& words) {
struct Trie {
    struct Node { array<int, 26> nxt; int end = 0; Node() { nxt.fill(-1); } };
    vector<Node> t;
    Trie() { t.emplace_back(); }
    void add(const string& s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) { t[u].nxt[x] = (int)t.size(); t.emplace_back(); }
            u = t[u].nxt[x];
        }
        ++t[u].end;
    }
    bool contains(const string& s) const {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) return false;
            u = t[u].nxt[x];
        }
        return t[u].end > 0;
    }
};
Trie tr;
for (auto& w : words) tr.add(w);
return (int)tr.t.size();
}

int trieOperations_tr2(const vector<string>& words) {
    return trieOperations_tr2_helper(words);
}

// helper-trie-03
struct trieOperations_tr3_cls {
    int run(const vector<string>& words) {
struct Trie {
    struct Node { array<int, 26> nxt; int end = 0; Node() { nxt.fill(-1); } };
    vector<Node> t;
    Trie() { t.emplace_back(); }
    void add(const string& s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) { t[u].nxt[x] = (int)t.size(); t.emplace_back(); }
            u = t[u].nxt[x];
        }
        ++t[u].end;
    }
    bool contains(const string& s) const {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) return false;
            u = t[u].nxt[x];
        }
        return t[u].end > 0;
    }
};
Trie tr;
for (auto& w : words) tr.add(w);
return (int)tr.t.size();
    }
};

int trieOperations_tr3(const vector<string>& words) {
    trieOperations_tr3_cls x;
    return x.run(words);
}

// helper-binarylift-01
int binaryLiftingKth_bl1(int n, const vector<pair<int,int>>& queries) {
int LOG = 1; while ((1 << LOG) <= max(1, n)) ++LOG;
vector<vector<int>> up(LOG, vector<int>(max(1, n), -1));
for (int k = 1; k < LOG; ++k)
    for (int v = 0; v < max(1, n); ++v)
        up[k][v] = up[k - 1][v] < 0 ? -1 : up[k - 1][up[k - 1][v]];
int ans = 0;
for (auto [u, k] : queries) ans += (u + k) % max(1, n);
return ans;
}

// helper-binarylift-02
static int binaryLiftingKth_bl2_helper(int n, const vector<pair<int,int>>& queries) {
int LOG = 1; while ((1 << LOG) <= max(1, n)) ++LOG;
vector<vector<int>> up(LOG, vector<int>(max(1, n), -1));
for (int k = 1; k < LOG; ++k)
    for (int v = 0; v < max(1, n); ++v)
        up[k][v] = up[k - 1][v] < 0 ? -1 : up[k - 1][up[k - 1][v]];
int ans = 0;
for (auto [u, k] : queries) ans += (u + k) % max(1, n);
return ans;
}

int binaryLiftingKth_bl2(int n, const vector<pair<int,int>>& queries) {
    return binaryLiftingKth_bl2_helper(n, queries);
}

// helper-binarylift-03
struct binaryLiftingKth_bl3_cls {
    int run(int n, const vector<pair<int,int>>& queries) {
int LOG = 1; while ((1 << LOG) <= max(1, n)) ++LOG;
vector<vector<int>> up(LOG, vector<int>(max(1, n), -1));
for (int k = 1; k < LOG; ++k)
    for (int v = 0; v < max(1, n); ++v)
        up[k][v] = up[k - 1][v] < 0 ? -1 : up[k - 1][up[k - 1][v]];
int ans = 0;
for (auto [u, k] : queries) ans += (u + k) % max(1, n);
return ans;
    }
};

int binaryLiftingKth_bl3(int n, const vector<pair<int,int>>& queries) {
    binaryLiftingKth_bl3_cls x;
    return x.run(n, queries);
}

// helper-dsu-01
int dsuFindUnion_dsu1(int n, const vector<pair<int,int>>& edges) {
vector<int> p(n), r(n, 0);
iota(p.begin(), p.end(), 0);
auto find = [&](auto&& self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
int merged = 0;
for (auto [u, v] : edges) {
    int a = find(find, u), b = find(find, v);
    if (a != b) { if (r[a] < r[b]) swap(a, b); p[b] = a; if (r[a] == r[b]) ++r[a]; ++merged; }
}
return merged;
}

// helper-dsu-02
static int dsuFindUnion_dsu2_helper(int n, const vector<pair<int,int>>& edges) {
vector<int> p(n), r(n, 0);
iota(p.begin(), p.end(), 0);
auto find = [&](auto&& self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
int merged = 0;
for (auto [u, v] : edges) {
    int a = find(find, u), b = find(find, v);
    if (a != b) { if (r[a] < r[b]) swap(a, b); p[b] = a; if (r[a] == r[b]) ++r[a]; ++merged; }
}
return merged;
}

int dsuFindUnion_dsu2(int n, const vector<pair<int,int>>& edges) {
    return dsuFindUnion_dsu2_helper(n, edges);
}

// helper-dsu-03
struct dsuFindUnion_dsu3_cls {
    int run(int n, const vector<pair<int,int>>& edges) {
vector<int> p(n), r(n, 0);
iota(p.begin(), p.end(), 0);
auto find = [&](auto&& self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
int merged = 0;
for (auto [u, v] : edges) {
    int a = find(find, u), b = find(find, v);
    if (a != b) { if (r[a] < r[b]) swap(a, b); p[b] = a; if (r[a] == r[b]) ++r[a]; ++merged; }
}
return merged;
    }
};

int dsuFindUnion_dsu3(int n, const vector<pair<int,int>>& edges) {
    dsuFindUnion_dsu3_cls x;
    return x.run(n, edges);
}

// helper-lca-01
int lcaQuery_lca1(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
int n = (int)adj.size(), LOG = 1;
while ((1 << LOG) <= max(1, n)) ++LOG;
vector<vector<int>> up(LOG, vector<int>(max(1, n), 0));
vector<int> depth(max(1, n), 0), parent(max(1, n), 0), order = {0};
for (int i = 0; i < (int)order.size(); ++i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        depth[v] = depth[order[i]] + 1;
        order.push_back(v);
    }
long long ans = 0;
for (auto [u, v] : qs) ans += depth[u] + depth[v];
return (int)ans;
}

// helper-lca-02
static int lcaQuery_lca2_helper(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
int n = (int)adj.size(), LOG = 1;
while ((1 << LOG) <= max(1, n)) ++LOG;
vector<vector<int>> up(LOG, vector<int>(max(1, n), 0));
vector<int> depth(max(1, n), 0), parent(max(1, n), 0), order = {0};
for (int i = 0; i < (int)order.size(); ++i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        depth[v] = depth[order[i]] + 1;
        order.push_back(v);
    }
long long ans = 0;
for (auto [u, v] : qs) ans += depth[u] + depth[v];
return (int)ans;
}

int lcaQuery_lca2(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    return lcaQuery_lca2_helper(adj, qs);
}

// helper-lca-03
struct lcaQuery_lca3_cls {
    int run(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
int n = (int)adj.size(), LOG = 1;
while ((1 << LOG) <= max(1, n)) ++LOG;
vector<vector<int>> up(LOG, vector<int>(max(1, n), 0));
vector<int> depth(max(1, n), 0), parent(max(1, n), 0), order = {0};
for (int i = 0; i < (int)order.size(); ++i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        depth[v] = depth[order[i]] + 1;
        order.push_back(v);
    }
long long ans = 0;
for (auto [u, v] : qs) ans += depth[u] + depth[v];
return (int)ans;
    }
};

int lcaQuery_lca3(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    lcaQuery_lca3_cls x;
    return x.run(adj, qs);
}

// helper-euler-01
long long eulerTourSubtree_et1(const vector<vector<int>>& adj, const vector<int>& nodes) {
int n = (int)adj.size();
vector<int> tin(n), tout(n), order;
auto dfs = [&](auto&& self, int u, int p) -> void {
    tin[u] = (int)order.size();
    order.push_back(u);
    for (int v : adj[u]) if (v != p) self(self, v, u);
    tout[u] = (int)order.size() - 1;
};
if (n) dfs(dfs, 0, -1);
long long ans = 0;
for (int u : nodes) ans += tout[u] - tin[u] + 1;
return ans;
}

// helper-euler-02
static long long eulerTourSubtree_et2_helper(const vector<vector<int>>& adj, const vector<int>& nodes) {
int n = (int)adj.size();
vector<int> tin(n), tout(n), order;
auto dfs = [&](auto&& self, int u, int p) -> void {
    tin[u] = (int)order.size();
    order.push_back(u);
    for (int v : adj[u]) if (v != p) self(self, v, u);
    tout[u] = (int)order.size() - 1;
};
if (n) dfs(dfs, 0, -1);
long long ans = 0;
for (int u : nodes) ans += tout[u] - tin[u] + 1;
return ans;
}

long long eulerTourSubtree_et2(const vector<vector<int>>& adj, const vector<int>& nodes) {
    return eulerTourSubtree_et2_helper(adj, nodes);
}

// helper-euler-03
struct eulerTourSubtree_et3_cls {
    long long run(const vector<vector<int>>& adj, const vector<int>& nodes) {
int n = (int)adj.size();
vector<int> tin(n), tout(n), order;
auto dfs = [&](auto&& self, int u, int p) -> void {
    tin[u] = (int)order.size();
    order.push_back(u);
    for (int v : adj[u]) if (v != p) self(self, v, u);
    tout[u] = (int)order.size() - 1;
};
if (n) dfs(dfs, 0, -1);
long long ans = 0;
for (int u : nodes) ans += tout[u] - tin[u] + 1;
return ans;
    }
};

long long eulerTourSubtree_et3(const vector<vector<int>>& adj, const vector<int>& nodes) {
    eulerTourSubtree_et3_cls x;
    return x.run(adj, nodes);
}

// helper-lazyseg-01
long long lazySegmentRange_lz1(const vector<int>& a, const vector<tuple<int,int,int>>& ops) {
struct LazySeg {
    int n; vector<long long> t, lazy;
    LazySeg(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0), lazy(4 * max(1, (int)a.size()), 0) {
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            t[p] = min(t[p << 1], t[p << 1 | 1]);
        };
        if (n) build(build, 1, 0, n - 1);
    }
    void push(int p) {
        if (!lazy[p]) return;
        for (int c : {p << 1, p << 1 | 1}) t[c] += lazy[p], lazy[c] += lazy[p];
        lazy[p] = 0;
    }
    void add(int p, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { t[p] += v; lazy[p] += v; return; }
        push(p);
        int m = (l + r) / 2;
        add(p << 1, l, m, ql, qr, v);
        add(p << 1 | 1, m + 1, r, ql, qr, v);
        t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
};
LazySeg st(a);
long long ans = 0;
for (auto [l, r, v] : ops) if (!a.empty()) { st.add(1, 0, (int)a.size() - 1, l, r, v); ans += v; }
return ans;
}

// helper-lazyseg-02
static long long lazySegmentRange_lz2_helper(const vector<int>& a, const vector<tuple<int,int,int>>& ops) {
struct LazySeg {
    int n; vector<long long> t, lazy;
    LazySeg(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0), lazy(4 * max(1, (int)a.size()), 0) {
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            t[p] = min(t[p << 1], t[p << 1 | 1]);
        };
        if (n) build(build, 1, 0, n - 1);
    }
    void push(int p) {
        if (!lazy[p]) return;
        for (int c : {p << 1, p << 1 | 1}) t[c] += lazy[p], lazy[c] += lazy[p];
        lazy[p] = 0;
    }
    void add(int p, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { t[p] += v; lazy[p] += v; return; }
        push(p);
        int m = (l + r) / 2;
        add(p << 1, l, m, ql, qr, v);
        add(p << 1 | 1, m + 1, r, ql, qr, v);
        t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
};
LazySeg st(a);
long long ans = 0;
for (auto [l, r, v] : ops) if (!a.empty()) { st.add(1, 0, (int)a.size() - 1, l, r, v); ans += v; }
return ans;
}

long long lazySegmentRange_lz2(const vector<int>& a, const vector<tuple<int,int,int>>& ops) {
    return lazySegmentRange_lz2_helper(a, ops);
}

// helper-lazyseg-03
struct lazySegmentRange_lz3_cls {
    long long run(const vector<int>& a, const vector<tuple<int,int,int>>& ops) {
struct LazySeg {
    int n; vector<long long> t, lazy;
    LazySeg(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0), lazy(4 * max(1, (int)a.size()), 0) {
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            t[p] = min(t[p << 1], t[p << 1 | 1]);
        };
        if (n) build(build, 1, 0, n - 1);
    }
    void push(int p) {
        if (!lazy[p]) return;
        for (int c : {p << 1, p << 1 | 1}) t[c] += lazy[p], lazy[c] += lazy[p];
        lazy[p] = 0;
    }
    void add(int p, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { t[p] += v; lazy[p] += v; return; }
        push(p);
        int m = (l + r) / 2;
        add(p << 1, l, m, ql, qr, v);
        add(p << 1 | 1, m + 1, r, ql, qr, v);
        t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
};
LazySeg st(a);
long long ans = 0;
for (auto [l, r, v] : ops) if (!a.empty()) { st.add(1, 0, (int)a.size() - 1, l, r, v); ans += v; }
return ans;
    }
};

long long lazySegmentRange_lz3(const vector<int>& a, const vector<tuple<int,int,int>>& ops) {
    lazySegmentRange_lz3_cls x;
    return x.run(a, ops);
}

// rec-divide-conquer-01
long long divideConquerCount_dc1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return 2 * f(x / 2) + x;
};
return f(n);
}

// rec-divide-conquer-02
static long long divideConquerCount_dc2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return 2 * f(x / 2) + x;
};
return f(n);
}

long long divideConquerCount_dc2(int n) {
    return divideConquerCount_dc2_helper(n);
}

// rec-divide-conquer-03
struct divideConquerCount_dc3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return 2 * f(x / 2) + x;
};
return f(n);
    }
};

long long divideConquerCount_dc3(int n) {
    divideConquerCount_dc3_cls x;
    return x.run(n);
}

// rec-memo-01
long long memoizedCount_mo1(int n) {
vector<long long> memo(max(2, n + 1), -1);
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    long long& r = memo[x];
    if (r != -1) return r;
    return r = f(x - 1) + f(x - 2);
};
return f(n);
}

// rec-memo-02
static long long memoizedCount_mo2_helper(int n) {
vector<long long> memo(max(2, n + 1), -1);
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    long long& r = memo[x];
    if (r != -1) return r;
    return r = f(x - 1) + f(x - 2);
};
return f(n);
}

long long memoizedCount_mo2(int n) {
    return memoizedCount_mo2_helper(n);
}

// rec-memo-03
struct memoizedCount_mo3_cls {
    long long run(int n) {
vector<long long> memo(max(2, n + 1), -1);
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    long long& r = memo[x];
    if (r != -1) return r;
    return r = f(x - 1) + f(x - 2);
};
return f(n);
    }
};

long long memoizedCount_mo3(int n) {
    memoizedCount_mo3_cls x;
    return x.run(n);
}

// rec-backtrack-01
long long backtrackSearch_bk1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x == 0) return 1;
    return f(x - 1) + f(x - 1);
};
return f(n);
}

// rec-backtrack-02
static long long backtrackSearch_bk2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x == 0) return 1;
    return f(x - 1) + f(x - 1);
};
return f(n);
}

long long backtrackSearch_bk2(int n) {
    return backtrackSearch_bk2_helper(n);
}

// rec-backtrack-03
struct backtrackSearch_bk3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x == 0) return 1;
    return f(x - 1) + f(x - 1);
};
return f(n);
    }
};

long long backtrackSearch_bk3(int n) {
    backtrackSearch_bk3_cls x;
    return x.run(n);
}

// rec-mutual-01
long long mutualRecursionCount_mu1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return x + (x - 1);
};
function<long long(int)> g = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x - 1) + g(x - 2);
};
return g(n);
}

// rec-mutual-02
static long long mutualRecursionCount_mu2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return x + (x - 1);
};
function<long long(int)> g = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x - 1) + g(x - 2);
};
return g(n);
}

long long mutualRecursionCount_mu2(int n) {
    return mutualRecursionCount_mu2_helper(n);
}

// rec-mutual-03
struct mutualRecursionCount_mu3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return x + (x - 1);
};
function<long long(int)> g = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x - 1) + g(x - 2);
};
return g(n);
    }
};

long long mutualRecursionCount_mu3(int n) {
    mutualRecursionCount_mu3_cls x;
    return x.run(n);
}

// rec-tree-01
long long treeRecursionSize_tr1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x / 2) + f(x / 2);
};
return f(n);
}

// rec-tree-02
static long long treeRecursionSize_tr2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x / 2) + f(x / 2);
};
return f(n);
}

long long treeRecursionSize_tr2(int n) {
    return treeRecursionSize_tr2_helper(n);
}

// rec-tree-03
struct treeRecursionSize_tr3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x / 2) + f(x / 2);
};
return f(n);
    }
};

long long treeRecursionSize_tr3(int n) {
    treeRecursionSize_tr3_cls x;
    return x.run(n);
}

// rec-lambda-01
long long lambdaRecursion_la1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x / 2) + 1;
};
return f(n);
}

// rec-lambda-02
static long long lambdaRecursion_la2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x / 2) + 1;
};
return f(n);
}

long long lambdaRecursion_la2(int n) {
    return lambdaRecursion_la2_helper(n);
}

// rec-lambda-03
struct lambdaRecursion_la3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return f(x / 2) + 1;
};
return f(n);
    }
};

long long lambdaRecursion_la3(int n) {
    lambdaRecursion_la3_cls x;
    return x.run(n);
}

// rec-perm-01
long long permutationRecursion_pr1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return x * f(x - 1);
};
return f(n);
}

// rec-perm-02
static long long permutationRecursion_pr2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return x * f(x - 1);
};
return f(n);
}

long long permutationRecursion_pr2(int n) {
    return permutationRecursion_pr2_helper(n);
}

// rec-perm-03
struct permutationRecursion_pr3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    return x * f(x - 1);
};
return f(n);
    }
};

long long permutationRecursion_pr3(int n) {
    permutationRecursion_pr3_cls x;
    return x.run(n);
}

// rec-prune-01
long long prunedSearch_pn1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 0) return 1;
    if (x % 3 == 0) return f(x - 1);
    return f(x - 1) + f(x - 2);
};
return f(n);
}

// rec-prune-02
static long long prunedSearch_pn2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 0) return 1;
    if (x % 3 == 0) return f(x - 1);
    return f(x - 1) + f(x - 2);
};
return f(n);
}

long long prunedSearch_pn2(int n) {
    return prunedSearch_pn2_helper(n);
}

// rec-prune-03
struct prunedSearch_pn3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 0) return 1;
    if (x % 3 == 0) return f(x - 1);
    return f(x - 1) + f(x - 2);
};
return f(n);
    }
};

long long prunedSearch_pn3(int n) {
    prunedSearch_pn3_cls x;
    return x.run(n);
}

// rec-helper-01
long long helperRecursion_hp1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    return x <= 1 ? 1 : 1 + f(x - 1);
};
return f(n);
}

// rec-helper-02
static long long helperRecursion_hp2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    return x <= 1 ? 1 : 1 + f(x - 1);
};
return f(n);
}

long long helperRecursion_hp2(int n) {
    return helperRecursion_hp2_helper(n);
}

// rec-helper-03
struct helperRecursion_hp3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    return x <= 1 ? 1 : 1 + f(x - 1);
};
return f(n);
    }
};

long long helperRecursion_hp3(int n) {
    helperRecursion_hp3_cls x;
    return x.run(n);
}

// rec-unknown-01
long long unknownRecursion_un1(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    if (x & 1) return f(x - (x % 3 + 1));
    return f(x - 1) + f(x - 2);
};
return f(n);
}

// rec-unknown-02
static long long unknownRecursion_un2_helper(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    if (x & 1) return f(x - (x % 3 + 1));
    return f(x - 1) + f(x - 2);
};
return f(n);
}

long long unknownRecursion_un2(int n) {
    return unknownRecursion_un2_helper(n);
}

// rec-unknown-03
struct unknownRecursion_un3_cls {
    long long run(int n) {
function<long long(int)> f = [&](int x) -> long long {
    if (x <= 1) return 1;
    if (x & 1) return f(x - (x % 3 + 1));
    return f(x - 1) + f(x - 2);
};
return f(n);
    }
};

long long unknownRecursion_un3(int n) {
    unknownRecursion_un3_cls x;
    return x.run(n);
}

// dp-bitmask-01
long long bitmaskDpCount_bm1(int n) {
vector<long long> dp(1 << n, 1);
for (int mask = 0; mask < (1 << n); ++mask)
    for (int bit = 0; bit < n; ++bit)
        if (mask & (1 << bit)) dp[mask] += dp[mask ^ (1 << bit)];
return dp.back();
}

// dp-bitmask-02
static long long bitmaskDpCount_bm2_helper(int n) {
vector<long long> dp(1 << n, 1);
for (int mask = 0; mask < (1 << n); ++mask)
    for (int bit = 0; bit < n; ++bit)
        if (mask & (1 << bit)) dp[mask] += dp[mask ^ (1 << bit)];
return dp.back();
}

long long bitmaskDpCount_bm2(int n) {
    return bitmaskDpCount_bm2_helper(n);
}

// dp-bitmask-03
struct bitmaskDpCount_bm3_cls {
    long long run(int n) {
vector<long long> dp(1 << n, 1);
for (int mask = 0; mask < (1 << n); ++mask)
    for (int bit = 0; bit < n; ++bit)
        if (mask & (1 << bit)) dp[mask] += dp[mask ^ (1 << bit)];
return dp.back();
    }
};

long long bitmaskDpCount_bm3(int n) {
    bitmaskDpCount_bm3_cls x;
    return x.run(n);
}

// dp-sos-01
long long sosDpCount_sos1(int n) {
vector<long long> f(1 << n, 1);
for (int bit = 0; bit < n; ++bit)
    for (int mask = 0; mask < (1 << n); ++mask)
        if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
return f.back();
}

// dp-sos-02
static long long sosDpCount_sos2_helper(int n) {
vector<long long> f(1 << n, 1);
for (int bit = 0; bit < n; ++bit)
    for (int mask = 0; mask < (1 << n); ++mask)
        if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
return f.back();
}

long long sosDpCount_sos2(int n) {
    return sosDpCount_sos2_helper(n);
}

// dp-sos-03
struct sosDpCount_sos3_cls {
    long long run(int n) {
vector<long long> f(1 << n, 1);
for (int bit = 0; bit < n; ++bit)
    for (int mask = 0; mask < (1 << n); ++mask)
        if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
return f.back();
    }
};

long long sosDpCount_sos3(int n) {
    sosDpCount_sos3_cls x;
    return x.run(n);
}

// dp-digit-01
long long digitDpCount_dg1(const string& s) {
int n = (int)s.size();
vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
dp[0][1] = 1;
for (int i = 0; i < n; ++i)
    for (int tight = 0; tight <= 1; ++tight)
        for (int d = 0; d <= (tight ? s[i] - '0' : 9); ++d)
            dp[i + 1][tight && d == s[i] - '0'] += dp[i][tight];
return dp[n][0] + dp[n][1];
}

// dp-digit-02
static long long digitDpCount_dg2_helper(const string& s) {
int n = (int)s.size();
vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
dp[0][1] = 1;
for (int i = 0; i < n; ++i)
    for (int tight = 0; tight <= 1; ++tight)
        for (int d = 0; d <= (tight ? s[i] - '0' : 9); ++d)
            dp[i + 1][tight && d == s[i] - '0'] += dp[i][tight];
return dp[n][0] + dp[n][1];
}

long long digitDpCount_dg2(const string& s) {
    return digitDpCount_dg2_helper(s);
}

// dp-digit-03
struct digitDpCount_dg3_cls {
    long long run(const string& s) {
int n = (int)s.size();
vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
dp[0][1] = 1;
for (int i = 0; i < n; ++i)
    for (int tight = 0; tight <= 1; ++tight)
        for (int d = 0; d <= (tight ? s[i] - '0' : 9); ++d)
            dp[i + 1][tight && d == s[i] - '0'] += dp[i][tight];
return dp[n][0] + dp[n][1];
    }
};

long long digitDpCount_dg3(const string& s) {
    digitDpCount_dg3_cls x;
    return x.run(s);
}

// dp-interval-01
long long intervalDpScore_in1(const vector<int>& a) {
int n = (int)a.size();
vector<vector<long long>> dp(n, vector<long long>(n, 0));
for (int len = 2; len <= n; ++len)
    for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        for (int k = l; k < r; ++k)
            dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
    }
return n ? dp[0][n - 1] : 0;
}

// dp-interval-02
static long long intervalDpScore_in2_helper(const vector<int>& a) {
int n = (int)a.size();
vector<vector<long long>> dp(n, vector<long long>(n, 0));
for (int len = 2; len <= n; ++len)
    for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        for (int k = l; k < r; ++k)
            dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
    }
return n ? dp[0][n - 1] : 0;
}

long long intervalDpScore_in2(const vector<int>& a) {
    return intervalDpScore_in2_helper(a);
}

// dp-interval-03
struct intervalDpScore_in3_cls {
    long long run(const vector<int>& a) {
int n = (int)a.size();
vector<vector<long long>> dp(n, vector<long long>(n, 0));
for (int len = 2; len <= n; ++len)
    for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        for (int k = l; k < r; ++k)
            dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
    }
return n ? dp[0][n - 1] : 0;
    }
};

long long intervalDpScore_in3(const vector<int>& a) {
    intervalDpScore_in3_cls x;
    return x.run(a);
}

// dp-reroot-01
long long rerootDpScore_rr1(const vector<vector<int>>& adj) {
int n = (int)adj.size();
vector<int> parent(n, -1), order = {0};
for (int i = 0; i < (int)order.size(); ++i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        order.push_back(v);
    }
vector<long long> sub(n, 1), dp(n, 0);
for (int i = n - 1; i >= 0; --i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) sub[order[i]] += sub[v];
for (int v = 1; v < n; ++v) dp[v] = dp[parent[v]] + n - 2 * sub[v];
return accumulate(dp.begin(), dp.end(), 0LL);
}

// dp-reroot-02
static long long rerootDpScore_rr2_helper(const vector<vector<int>>& adj) {
int n = (int)adj.size();
vector<int> parent(n, -1), order = {0};
for (int i = 0; i < (int)order.size(); ++i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        order.push_back(v);
    }
vector<long long> sub(n, 1), dp(n, 0);
for (int i = n - 1; i >= 0; --i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) sub[order[i]] += sub[v];
for (int v = 1; v < n; ++v) dp[v] = dp[parent[v]] + n - 2 * sub[v];
return accumulate(dp.begin(), dp.end(), 0LL);
}

long long rerootDpScore_rr2(const vector<vector<int>>& adj) {
    return rerootDpScore_rr2_helper(adj);
}

// dp-reroot-03
struct rerootDpScore_rr3_cls {
    long long run(const vector<vector<int>>& adj) {
int n = (int)adj.size();
vector<int> parent(n, -1), order = {0};
for (int i = 0; i < (int)order.size(); ++i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) {
        parent[v] = order[i];
        order.push_back(v);
    }
vector<long long> sub(n, 1), dp(n, 0);
for (int i = n - 1; i >= 0; --i)
    for (int v : adj[order[i]]) if (v != parent[order[i]]) sub[order[i]] += sub[v];
for (int v = 1; v < n; ++v) dp[v] = dp[parent[v]] + n - 2 * sub[v];
return accumulate(dp.begin(), dp.end(), 0LL);
    }
};

long long rerootDpScore_rr3(const vector<vector<int>>& adj) {
    rerootDpScore_rr3_cls x;
    return x.run(adj);
}

// dp-knapsack-01
long long knapsack01_kn1(int W, const vector<pair<int,int>>& items) {
vector<long long> dp(W + 1, 0);
for (auto [w, val] : items)
    for (int cap = W; cap >= w; --cap)
        dp[cap] = max(dp[cap], dp[cap - w] + val);
return dp[W];
}

// dp-knapsack-02
static long long knapsack01_kn2_helper(int W, const vector<pair<int,int>>& items) {
vector<long long> dp(W + 1, 0);
for (auto [w, val] : items)
    for (int cap = W; cap >= w; --cap)
        dp[cap] = max(dp[cap], dp[cap - w] + val);
return dp[W];
}

long long knapsack01_kn2(int W, const vector<pair<int,int>>& items) {
    return knapsack01_kn2_helper(W, items);
}

// dp-knapsack-03
struct knapsack01_kn3_cls {
    long long run(int W, const vector<pair<int,int>>& items) {
vector<long long> dp(W + 1, 0);
for (auto [w, val] : items)
    for (int cap = W; cap >= w; --cap)
        dp[cap] = max(dp[cap], dp[cap - w] + val);
return dp[W];
    }
};

long long knapsack01_kn3(int W, const vector<pair<int,int>>& items) {
    knapsack01_kn3_cls x;
    return x.run(W, items);
}

// dp-sieve-01
int sieveCount_sv1(int n) {
vector<char> prime(n + 1, 1);
prime[0] = prime[1] = 0;
for (int i = 2; i * i <= n; ++i)
    if (prime[i])
        for (int j = i * i; j <= n; j += i)
            prime[j] = 0;
return accumulate(prime.begin(), prime.end(), 0);
}

// dp-sieve-02
static int sieveCount_sv2_helper(int n) {
vector<char> prime(n + 1, 1);
prime[0] = prime[1] = 0;
for (int i = 2; i * i <= n; ++i)
    if (prime[i])
        for (int j = i * i; j <= n; j += i)
            prime[j] = 0;
return accumulate(prime.begin(), prime.end(), 0);
}

int sieveCount_sv2(int n) {
    return sieveCount_sv2_helper(n);
}

// dp-sieve-03
struct sieveCount_sv3_cls {
    int run(int n) {
vector<char> prime(n + 1, 1);
prime[0] = prime[1] = 0;
for (int i = 2; i * i <= n; ++i)
    if (prime[i])
        for (int j = i * i; j <= n; j += i)
            prime[j] = 0;
return accumulate(prime.begin(), prime.end(), 0);
    }
};

int sieveCount_sv3(int n) {
    sieveCount_sv3_cls x;
    return x.run(n);
}

// dp-gcdpow-01
long long gcdPowLoop_gp1(long long n) {
long long ans = 0;
while (n > 0) {
    n >>= 1;
    ++ans;
}
return ans;
}

// dp-gcdpow-02
static long long gcdPowLoop_gp2_helper(long long n) {
long long ans = 0;
while (n > 0) {
    n >>= 1;
    ++ans;
}
return ans;
}

long long gcdPowLoop_gp2(long long n) {
    return gcdPowLoop_gp2_helper(n);
}

// dp-gcdpow-03
struct gcdPowLoop_gp3_cls {
    long long run(long long n) {
long long ans = 0;
while (n > 0) {
    n >>= 1;
    ++ans;
}
return ans;
    }
};

long long gcdPowLoop_gp3(long long n) {
    gcdPowLoop_gp3_cls x;
    return x.run(n);
}

// dp-prefixdiff-01
long long pack_project_x_manual_cp_dataset_1_prefixDifferenceQuery_pd1(const vector<int>& values, const vector<pair<int,int>>& queries) {
vector<long long> pref(values.size() + 1, 0);
for (size_t i = 0; i < values.size(); ++i) pref[i + 1] = pref[i] + values[i];
long long ans = 0;
for (auto [l, r] : queries) ans += pref[r + 1] - pref[l];
return ans;
}
