
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INFLL = (1LL<<60);

struct DSU {
    vector<int> p, sz;
    DSU(int n = 0) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x; }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

static vector<vector<int>> buildAdj(int n, const vector<array<int,2>>& edges, bool directed = false) {
    vector<vector<int>> g(n);
    for (auto e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        if (!directed) g[v].push_back(u);
    }
    return g;
}

static vector<vector<pair<int,int>>> buildWAdj(int n, const vector<array<int,3>>& edges, bool directed = false) {
    vector<vector<pair<int,int>>> g(n);
    for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        g[u].push_back({v, w});
        if (!directed) g[v].push_back({u, w});
    }
    return g;
}

static ll kruskalWeight(int n, vector<array<int,3>> edges) {
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
        if (a[2] != b[2]) return a[2] < b[2];
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    DSU dsu(n);
    ll ans = 0;
    int used = 0;
    for (auto e : edges) if (dsu.unite(e[0], e[1])) {
        ans += e[2];
        if (++used == n - 1) break;
    }
    return ans;
}

static ll primDenseWeight(int n, const vector<vector<pair<int,int>>>& g) {
    vector<ll> dist(n, INFLL);
    vector<char> vis(n, 0);
    dist[0] = 0;
    ll ans = 0;
    for (int it = 0; it < n; ++it) {
        int u = -1;
        for (int i = 0; i < n; ++i) if (!vis[i] && (u == -1 || dist[i] < dist[u])) u = i;
        vis[u] = 1;
        ans += dist[u];
        for (auto [v, w] : g[u]) if (!vis[v] && w < dist[v]) dist[v] = w;
    }
    return ans;
}

static ll primHeapWeight(int n, const vector<vector<pair<int,int>>>& g) {
    vector<char> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    ll ans = 0;
    int taken = 0;
    while (!pq.empty() && taken < n) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += w;
        ++taken;
        for (auto [v, nw] : g[u]) if (!vis[v]) pq.push({nw, v});
    }
    return ans;
}

static vector<int> kahnTopo(int n, const vector<array<int,2>>& edges, bool usePriority = false) {
    auto g = buildAdj(n, edges, true);
    vector<int> indeg(n);
    for (int u = 0; u < n; ++u) for (int v : g[u]) ++indeg[v];
    vector<int> order;
    if (usePriority) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i) if (!indeg[i]) pq.push(i);
        while (!pq.empty()) {
            int u = pq.top(); pq.pop();
            order.push_back(u);
            for (int v : g[u]) if (--indeg[v] == 0) pq.push(v);
        }
    } else {
        queue<int> q;
        for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
        }
    }
    return order;
}

static vector<int> dijkstraHeap(int n, const vector<vector<pair<int,int>>>& g, int src = 0) {
    vector<ll> dist(n, INFLL);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) if (dist[v] > d + w) {
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) if (dist[i] < INFLL/2) ans[i] = (int)dist[i];
    return ans;
}

static vector<int> dijkstraSet(int n, const vector<vector<pair<int,int>>>& g, int src = 0) {
    set<pair<ll,int>> st;
    vector<ll> dist(n, INFLL);
    dist[src] = 0;
    st.insert({0, src});
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) if (dist[v] > d + w) {
            if (dist[v] != INFLL) st.erase({dist[v], v});
            dist[v] = d + w;
            st.insert({dist[v], v});
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) if (dist[i] < INFLL/2) ans[i] = (int)dist[i];
    return ans;

}

static vector<int> zeroOneBfs(int n, const vector<vector<pair<int,int>>>& g, int src = 0) {
    deque<int> dq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    dq.push_front(src);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : g[u]) if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            if (w == 0) dq.push_front(v); else dq.push_back(v);
        }
    }
    return dist;
}

static vector<int> multiSourceZeroOneBfs(int n, const vector<vector<pair<int,int>>>& g, const vector<int>& sources) {
    deque<int> dq;
    vector<int> dist(n, INT_MAX);
    for (int s : sources) if (dist[s] > 0) {
        dist[s] = 0;
        dq.push_front(s);
    }
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : g[u]) if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            if (w == 0) dq.push_front(v); else dq.push_back(v);
        }
    }
    return dist;
}

static vector<int> bellmanFord(int n, const vector<array<int,3>>& edges, int src = 0, bool detectNeg = false) {
    vector<ll> dist(n, INFLL);
    dist[src] = 0;
    for (int it = 0; it < n - 1; ++it) {
        bool any = false;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] < INFLL/2 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                any = true;
            }
        }
        if (!any) break;
    }
    if (detectNeg) {
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] < INFLL/2 && dist[v] > dist[u] + w) return vector<int>{-1};
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) if (dist[i] < INFLL/2) ans[i] = (int)dist[i];
    return ans;
}

static vector<vector<ll>> floydWarshall(int n, vector<vector<ll>> d) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            if (d[i][k] < INFLL/2)
                for (int j = 0; j < n; ++j)
                    if (d[k][j] < INFLL/2 && d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];
    return d;
}

static vector<int> tarjanScc(int n, const vector<array<int,2>>& edges) {
    auto g = buildAdj(n, edges, true);
    vector<int> disc(n, -1), low(n), comp(n, -1), st;
    vector<char> inSt(n, 0);
    int timer = 0, comps = 0;
    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = timer++;
        st.push_back(u);
        inSt[u] = 1;
        for (int v : g[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inSt[v]) low[u] = min(low[u], disc[v]);
        }
        if (low[u] == disc[u]) {
            while (1) {
                int x = st.back(); st.pop_back();
                inSt[x] = 0;
                comp[x] = comps;
                if (x == u) break;
            }
            ++comps;
        }
    };
    for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(i);
    return comp;
}

static vector<int> kosarajuScc(int n, const vector<array<int,2>>& edges) {
    auto g = buildAdj(n, edges, true);
    vector<vector<int>> rg(n);
    for (auto e : edges) rg[e[1]].push_back(e[0]);
    vector<char> vis(n);
    vector<int> order, comp(n, -1);
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = 1;
        for (int v : g[u]) if (!vis[v]) dfs1(v);
        order.push_back(u);
    };
    function<void(int,int)> dfs2 = [&](int u, int cid) {
        comp[u] = cid;
        for (int v : rg[u]) if (comp[v] == -1) dfs2(v, cid);
    };
    for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i);
    int cid = 0;
    for (int i = n - 1; i >= 0; --i) if (comp[order[i]] == -1) dfs2(order[i], cid++);
    return comp;
}

static vector<int> bridgeFind(int n, const vector<array<int,2>>& edges) {
    auto g = buildAdj(n, edges, false);
    vector<int> disc(n, -1), low(n), parent(n, -1), bridges;
    int timer = 0;
    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = timer++;
        for (int v : g[u]) {
            if (v == parent[u]) continue;
            if (disc[v] == -1) {
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) bridges.push_back(u * n + v);
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    };
    for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(i);
    return bridges;
}

static vector<int> articulationPoints(int n, const vector<array<int,2>>& edges) {
    auto g = buildAdj(n, edges, false);
    vector<int> disc(n, -1), low(n), parent(n, -1), cut(n, 0);
    int timer = 0;
    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = timer++;
        int children = 0;
        for (int v : g[u]) {
            if (v == parent[u]) continue;

            if (disc[v] == -1) {
                parent[v] = u;
                ++children;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (parent[u] != -1 && low[v] >= disc[u]) cut[u] = 1;
            } else low[u] = min(low[u], disc[v]);
        }
        if (parent[u] == -1 && children > 1) cut[u] = 1;
    };
    for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(i);
    return cut;
}

static int biconnectedComponentsCount(int n, const vector<array<int,2>>& edges) {
    auto g = buildAdj(n, edges, false);
    vector<int> disc(n, -1), low(n), parent(n, -1);
    int timer = 0, comps = 0;
    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = timer++;
        for (int v : g[u]) {
            if (v == parent[u]) continue;
            if (disc[v] == -1) {
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (low[v] >= disc[u]) ++comps;
            } else if (disc[v] < disc[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    };
    for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(i);
    return comps;
}

static vector<int> dagLongestPath(int n, const vector<array<int,2>>& edges, int src = 0) {
    auto order = kahnTopo(n, edges, false);
    auto g = buildAdj(n, edges, true);
    vector<int> dp(n, INT_MIN/4);
    dp[src] = 0;
    for (int u : order) if (dp[u] > INT_MIN/4) for (int v : g[u]) dp[v] = max(dp[v], dp[u] + 1);
    return dp;
}

static vector<int> countShortestPathsDag(int n, const vector<array<int,2>>& edges, int src = 0) {
    auto order = kahnTopo(n, edges, false);
    auto g = buildAdj(n, edges, true);
    vector<int> ways(n), dist(n, INT_MAX);
    dist[src] = 0; ways[src] = 1;
    for (int u : order) {
        for (int v : g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
            } else if (dist[v] == dist[u] + 1) {
                ways[v] += ways[u];
            }
        }
    }
    return ways;
}

static vector<int> functionalJump(vector<int> nxt, vector<int> start, long long k) {
    int n = (int)nxt.size();
    int LOG = 1;
    while ((1LL << LOG) <= k) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n));
    up[0] = nxt;
    for (int j = 1; j < LOG; ++j)
        for (int i = 0; i < n; ++i)
            up[j][i] = up[j-1][up[j-1][i]];
    vector<int> res = start;
    for (int bit = 0; (1LL << bit) <= k; ++bit) if (k & (1LL << bit)) {
        for (int &x : res) x = up[bit][x];
    }
    return res;
}

static ll dinicMaxFlow(int n, const vector<array<int,3>>& edges, int s, int t) {
    struct E { int to, rev; ll cap; };
    vector<vector<E>> g(n);
    auto addEdge = [&](int u, int v, ll c) {
        E a{v, (int)g[v].size(), c};
        E b{u, (int)g[u].size(), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    };
    for (auto e : edges) addEdge(e[0], e[1], e[2]);
    ll flow = 0;
    vector<int> level(n), it(n);
    auto bfs = [&]() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g[u]) if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
        return level[t] != -1;
    };
    function<ll(int,ll)> dfs = [&](int u, ll f) {
        if (u == t || !f) return f;
        for (int &i = it[u]; i < (int)g[u].size(); ++i) {
            auto &e = g[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                ll ret = dfs(e.to, min(f, e.cap));
                if (ret) {
                    e.cap -= ret;
                    g[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0LL;
    };
    while (bfs()) {
        fill(it.begin(), it.end(), 0);
        while (ll pushed = dfs(s, INFLL)) flow += pushed;
    }
    return flow;
}

static ll edmondsKarp(int n, const vector<array<int,3>>& edges, int s, int t) {
    struct E { int to, rev; ll cap; };
    vector<vector<E>> g(n);
    auto addEdge = [&](int u, int v, ll c) {
        E a{v, (int)g[v].size(), c};
        E b{u, (int)g[u].size(), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    };
    for (auto e : edges) addEdge(e[0], e[1], e[2]);
    ll flow = 0;
    while (1) {
        vector<int> parent(n, -1), pe(n, -1);
        queue<int> q;
        q.push(s);
        parent[s] = s;
        while (!q.empty() && parent[t] == -1) {
            int u = q.front(); q.pop();
            for (int i = 0; i < (int)g[u].size(); ++i) {
                auto &e = g[u][i];
                if (e.cap > 0 && parent[e.to] == -1) {
                    parent[e.to] = u;
                    pe[e.to] = i;

                    q.push(e.to);
                    if (e.to == t) break;
                }
            }
        }
        if (parent[t] == -1) break;
        ll aug = INFLL;
        for (int v = t; v != s; v = parent[v]) aug = min(aug, g[parent[v]][pe[v]].cap);
        for (int v = t; v != s; v = parent[v]) {
            auto &e = g[parent[v]][pe[v]];
            e.cap -= aug;
            g[v][e.rev].cap += aug;
        }
        flow += aug;
    }
    return flow;
}

static int hopcroftKarp(int nLeft, int nRight, const vector<array<int,2>>& edges) {
    vector<vector<int>> g(nLeft);
    for (auto e : edges) g[e[0]].push_back(e[1]);
    vector<int> dist(nLeft), matchL(nLeft, -1), matchR(nRight, -1);
    auto bfs = [&]() {
        queue<int> q;
        bool found = false;
        for (int i = 0; i < nLeft; ++i) {
            if (matchL[i] == -1) dist[i] = 0, q.push(i);
            else dist[i] = -1;
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                int w = matchR[v];
                if (w == -1) found = true;
                else if (dist[w] == -1) dist[w] = dist[u] + 1, q.push(w);
            }
        }
        return found;
    };
    function<bool(int)> dfs = [&](int u) {
        for (int v : g[u]) {
            int w = matchR[v];
            if (w == -1 || (dist[w] == dist[u] + 1 && dfs(w))) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    };
    int matching = 0;
    while (bfs()) for (int i = 0; i < nLeft; ++i) if (matchL[i] == -1 && dfs(i)) ++matching;
    return matching;
}

static vector<int> eulerSubtreeSum(int n, const vector<array<int,2>>& edges, const vector<int>& val, int root = 0) {
    auto g = buildAdj(n, edges, false);
    vector<int> tin(n), tout(n), order;
    int timer = 0;
    function<void(int,int)> dfs = [&](int u, int p) {
        tin[u] = timer++;
        order.push_back(u);
        for (int v : g[u]) if (v != p) dfs(v, u);
        tout[u] = timer;
    };
    dfs(root, -1);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + val[order[i]];
    vector<int> sub(n);
    for (int i = 0; i < n; ++i) sub[i] = pref[tout[i]] - pref[tin[i]];
    return sub;
}

static vector<int> lcaBatch(int n, const vector<array<int,2>>& edges, const vector<pair<int,int>>& queries, int root = 0) {
    auto g = buildAdj(n, edges, false);
    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n, root));
    vector<int> tin(n), tout(n);
    int timer = 0;
    function<void(int,int)> dfs = [&](int u, int p) {
        tin[u] = ++timer;
        up[0][u] = (p == -1 ? u : p);
        for (int j = 1; j < LOG; ++j) up[j][u] = up[j-1][up[j-1][u]];
        for (int v : g[u]) if (v != p) dfs(v, u);
        tout[u] = ++timer;
    };
    dfs(root, -1);
    auto isAnc = [&](int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; };
    auto lca = [&](int a, int b) {
        if (isAnc(a, b)) return a;
        if (isAnc(b, a)) return b;
        for (int j = LOG - 1; j >= 0; --j) if (!isAnc(up[j][a], b)) a = up[j][a];
        return up[0][a];
    };
    vector<int> ans;
    for (auto [u, v] : queries) ans.push_back(lca(u, v));
    return ans;
}

static vector<int> bridgeTreeDiameterSummary(int n, const vector<array<int,2>>& edges) {
    auto bridges = bridgeFind(n, edges);
    auto cut = articulationPoints(n, edges);
    return { (int)bridges.size(), accumulate(cut.begin(), cut.end(), 0) };
}

static vector<int> topoLevels(int n, const vector<array<int,2>>& edges) {
    auto g = buildAdj(n, edges, true);
    vector<int> indeg(n), level(n);
    for (int u = 0; u < n; ++u) for (int v : g[u]) ++indeg[v];
    queue<int> q;
    for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            level[v] = max(level[v], level[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return level;
}

long long advGraphKruskalMST(int n, vector<array<int,3>> edges) { return kruskalWeight(n, move(edges)); }

long long advGraphKruskalMSTStable(int n, vector<array<int,3>> edges) { return kruskalWeight(n, move(edges)); }

long long advGraphPrimDenseMST(int n, vector<vector<pair<int,int>>> g) { return primDenseWeight(n, g); }

long long advGraphPrimHeapMST(int n, vector<vector<pair<int,int>>> g) { return primHeapWeight(n, g); }

vector<int> advGraphTarjanSCC(int n, vector<array<int,2>> edges) { return tarjanScc(n, edges); }

vector<int> advGraphKosarajuSCC(int n, vector<array<int,2>> edges) { return kosarajuScc(n, edges); }

vector<int> advGraphKahnTopoQueue(int n, vector<array<int,2>> edges) { return kahnTopo(n, edges, false); }

vector<int> advGraphKahnTopoPriority(int n, vector<array<int,2>> edges) { return kahnTopo(n, edges, true); }

vector<int> advGraphBellmanFord(int n, vector<array<int,3>> edges, int src) { return bellmanFord(n, edges, src, false); }

vector<int> advGraphBellmanFordDetectNegCycle(int n, vector<array<int,3>> edges, int src) { return bellmanFord(n, edges, src, true); }

vector<int> advGraphZeroOneBFS(int n, vector<vector<pair<int,int>>> g, int src) { return zeroOneBfs(n, g, src); }

vector<int> advGraphDijkstraHeap(int n, vector<vector<pair<int,int>>> g, int src) { return dijkstraHeap(n, g, src); }

vector<int> advGraphDijkstraSet(int n, vector<vector<pair<int,int>>> g, int src) { return dijkstraSet(n, g, src); }

vector<int> advGraphDagShortestPath(int n, vector<array<int,2>> edges, int src) { auto order = kahnTopo(n, edges, false); auto g = buildAdj(n, edges, true); vector<int> dist(n, INT_MAX); dist[src] = 0; for (int u : order) if (dist[u] != INT_MAX) for (int v : g[u]) dist[v] = min(dist[v], dist[u] + 1); return dist; }


vector<int> advGraphDagLongestPath(int n, vector<array<int,2>> edges, int src) { return dagLongestPath(n, edges, src); }

vector<vector<ll>> advGraphFloydWarshallAllPairs(int n, vector<vector<ll>> d) { return floydWarshall(n, move(d)); }

int advGraphHopcroftKarpMatching(int nLeft, int nRight, vector<array<int,2>> edges) { return hopcroftKarp(nLeft, nRight, edges); }

long long advGraphDinicMaxFlow(int n, vector<array<int,3>> edges, int s, int t) { return dinicMaxFlow(n, edges, s, t); }

long long advGraphEdmondsKarpMaxFlow(int n, vector<array<int,3>> edges, int s, int t) { return edmondsKarp(n, edges, s, t); }

vector<int> advGraphBridgeFinder(int n, vector<array<int,2>> edges) { return bridgeFind(n, edges); }

vector<int> advGraphArticulationPoints(int n, vector<array<int,2>> edges) { return articulationPoints(n, edges); }

int advGraphBiconnectedComponentsCount(int n, vector<array<int,2>> edges) { return biconnectedComponentsCount(n, edges); }

vector<int> advGraphLcaBatchQueries(int n, vector<array<int,2>> edges, vector<pair<int,int>> queries) { return lcaBatch(n, edges, queries, 0); }

vector<int> advGraphEulerSubtreeSum(int n, vector<array<int,2>> edges, vector<int> val) { return eulerSubtreeSum(n, edges, val, 0); }

vector<int> advGraphFunctionalJump(vector<int> nxt, vector<int> start, long long k) { return functionalJump(nxt, start, k); }

vector<int> advGraphBridgeTreeDiameterSummary(int n, vector<array<int,2>> edges) { return bridgeTreeDiameterSummary(n, edges); }

int advGraphSccCondensationLongestPath(int n, vector<array<int,2>> edges) { auto comp = tarjanScc(n, edges); int comps = *max_element(comp.begin(), comp.end()) + 1; vector<array<int,2>> ce; ce.reserve(edges.size()); for (auto e : edges) if (comp[e[0]] != comp[e[1]]) ce.push_back({comp[e[0]], comp[e[1]]}); auto order = kahnTopo(comps, ce, false); auto g = buildAdj(comps, ce, true); vector<int> dp(comps, 1); for (int u : order) for (int v : g[u]) dp[v] = max(dp[v], dp[u] + 1); return *max_element(dp.begin(), dp.end()); }

vector<int> advGraphDagShortestPathCountWays(int n, vector<array<int,2>> edges, int src) { return countShortestPathsDag(n, edges, src); }

vector<int> advGraphMultiSourceZeroOneBFS(int n, vector<vector<pair<int,int>>> g, vector<int> sources) { return multiSourceZeroOneBfs(n, g, sources); }

vector<int> advGraphTopologicalLevels(int n, vector<array<int,2>> edges) { return topoLevels(n, edges); }

