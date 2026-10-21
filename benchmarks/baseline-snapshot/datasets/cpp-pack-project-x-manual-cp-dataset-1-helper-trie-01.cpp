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
int pack_project_x_manual_cp_dataset_1_trieOperations_tr1(const vector<string>& words) {
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
