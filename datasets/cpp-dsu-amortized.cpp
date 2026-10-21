#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BasicDSU {
    vector<int> p, sz;
    int comps;
    BasicDSU(int n = 0) : p(n), sz(n, 1), comps(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        --comps;
        return true;
    }
};

struct ParityDSU {
    vector<int> p, sz, xr;
    int comps;
    ParityDSU(int n = 0) : p(n), sz(n, 1), xr(n, 0), comps(n) {
        iota(p.begin(), p.end(), 0);
    }
    pair<int, int> find(int x) {
        if (p[x] == x) return {x, 0};
        auto res = find(p[x]);
        xr[x] ^= res.second;
        p[x] = res.first;
        return {p[x], xr[x]};
    }
    // w = 0 means same color, w = 1 means different color
    bool unite(int a, int b, int w) {
        auto [ra, pa] = find(a);
        auto [rb, pb] = find(b);
        if (ra == rb) return ((pa ^ pb) == w);
        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
            swap(pa, pb);
        }
        p[rb] = ra;
        xr[rb] = pa ^ pb ^ w;
        sz[ra] += sz[rb];
        --comps;
        return true;
    }
};

struct WeightedDSU {
    vector<int> p, sz;
    vector<ll> pot; // pot[x] = value[x] - value[parent[x]]
    int comps;
    WeightedDSU(int n = 0) : p(n), sz(n, 1), pot(n, 0), comps(n) {
        iota(p.begin(), p.end(), 0);
    }
    pair<int, ll> find(int x) {
        if (p[x] == x) return {x, 0};
        auto res = find(p[x]);
        pot[x] += res.second;
        p[x] = res.first;
        return {p[x], pot[x]};
    }
    // Enforce value[b] - value[a] = w
    bool unite(int a, int b, ll w) {
        auto [ra, da] = find(a);
        auto [rb, db] = find(b);
        if (ra == rb) return (db - da == w);
        if (sz[ra] < sz[rb]) {
            // attach ra under rb
            p[ra] = rb;
            pot[ra] = db - da - w;
            sz[rb] += sz[ra];
        } else {
            // attach rb under ra
            p[rb] = ra;
            pot[rb] = da + w - db;
            sz[ra] += sz[rb];
        }
        --comps;
        return true;
    }
    ll potential(int x) { return find(x).second; }
};

struct RollbackDSU {
    struct Change {
        int b;
        int parent_b;
        int size_a;
        int comps;
        int maxSize;
        int unions;
        ll connectedPairs;
    };

    vector<int> p, sz;
    int comps;
    int maxSize;
    int unions;
    ll connectedPairs;
    vector<Change> hist;

    RollbackDSU(int n = 0) : p(n), sz(n, 1), comps(n), maxSize(n ? 1 : 0), unions(0), connectedPairs(0) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) const {
        while (p[x] != x) x = p[x];
        return x;
    }

    int snapshot() const { return (int)hist.size(); }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            hist.push_back({-1, -1, -1, comps, maxSize, unions, connectedPairs});
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        hist.push_back({b, p[b], sz[a], comps, maxSize, unions, connectedPairs});
        connectedPairs += 1LL * sz[a] * sz[b];
        p[b] = a;
        sz[a] += sz[b];
        --comps;
        ++unions;
        maxSize = max(maxSize, sz[a]);
        return true;
    }

    void rollback(int snap) {
        while ((int)hist.size() > snap) {
            Change c = hist.back();
            hist.pop_back();
            comps = c.comps;
            maxSize = c.maxSize;
            unions = c.unions;
            connectedPairs = c.connectedPairs;
            if (c.b == -1) continue;
            int a = p[c.b];
            p[c.b] = c.parent_b;
            sz[a] = c.size_a;
        }
    }
};

struct SuccessorDSU {
    vector<int> nxt;
    SuccessorDSU(int n = 0) : nxt(n + 1) {
        iota(nxt.begin(), nxt.end(), 0);
    }
    int find(int x) {
        if (x >= (int)nxt.size() - 1) return (int)nxt.size() - 1;
        if (nxt[x] == x) return x;
        return nxt[x] = find(nxt[x]);
    }
    void erase(int x) {
        nxt[x] = find(x + 1);
    }
};

struct AggDSU {
    vector<int> p, sz;
    vector<ll> sum;
    vector<ll> mn, mx;
    int comps;
    AggDSU(int n = 0, const vector<ll>& weight = {}) : p(n), sz(n, 1), sum(n, 0), mn(n, 0), mx(n, 0), comps(n) {
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; ++i) {
            ll w = weight.empty() ? 1 : weight[i];
            sum[i] = mn[i] = mx[i] = w;
        }
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];

        sum[a] += sum[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
        --comps;
        return true;
    }
};

struct WEdge {
    int u, v, w, id;
};

struct RollbackOp {
    int type, u, v;
};

struct PaintQuery {
    int l, r, color;
};

struct GridTrace {
    vector<int> components;
    vector<int> largest;
    vector<int> perimeter;
};

static ll choose2(ll x) { return x * (x - 1) / 2; }

static void addInterval(vector<vector<pair<int, int>>>& seg, int node, int l, int r, int ql, int qr, pair<int, int> e) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        seg[node].push_back(e);
        return;
    }
    int mid = (l + r) >> 1;
    addInterval(seg, node << 1, l, mid, ql, qr, e);
    addInterval(seg, node << 1 | 1, mid + 1, r, ql, qr, e);
}

static void rollbackDfs(int node, int l, int r, vector<vector<pair<int, int>>>& seg, RollbackDSU& dsu, const vector<int>& queryAt, GridTrace& tr, vector<int>& compAns, vector<ll>& pairAns, vector<int>& maxAns, vector<int>& unionAns) {
    int snap = dsu.snapshot();
    for (auto [u, v] : seg[node]) dsu.unite(u, v);
    if (l == r) {
        if (queryAt[l] != -1) {
            int idx = queryAt[l];
            compAns[idx] = dsu.comps;
            pairAns[idx] = dsu.connectedPairs;
            maxAns[idx] = dsu.maxSize;
            unionAns[idx] = dsu.unions;
        }
    } else {
        int mid = (l + r) >> 1;
        rollbackDfs(node << 1, l, mid, seg, dsu, queryAt, tr, compAns, pairAns, maxAns, unionAns);
        rollbackDfs(node << 1 | 1, mid + 1, r, seg, dsu, queryAt, tr, compAns, pairAns, maxAns, unionAns);
    }
    dsu.rollback(snap);
}

static tuple<vector<int>, vector<ll>, vector<int>, vector<int>> rollbackSolve(int n, const vector<RollbackOp>& ops) {
    int q = (int)ops.size();
    vector<vector<pair<int, int>>> seg(4 * max(1, q) + 5);
    map<pair<int, int>, int> open;
    vector<int> queryAt(q, -1);
    int queryCount = 0;

    auto normalize = [](int a, int b) {
        if (a > b) swap(a, b);
        return make_pair(a, b);
    };

    for (int i = 0; i < q; ++i) {
        auto [type, u, v] = ops[i];
        if (type == 0) {
            open[normalize(u, v)] = i;
        } else if (type == 1) {
            auto key = normalize(u, v);
            auto it = open.find(key);
            if (it != open.end()) {
                addInterval(seg, 1, 0, q - 1, it->second, i - 1, key);
                open.erase(it);
            }
        } else {
            queryAt[i] = queryCount++;
        }
    }
    for (auto &kv : open) addInterval(seg, 1, 0, q - 1, kv.second, q - 1, kv.first);

    RollbackDSU dsu(n);
    vector<int> compAns(queryCount), maxAns(queryCount), unionAns(queryCount);
    vector<ll> pairAns(queryCount);
    GridTrace dummy;
    if (q > 0) rollbackDfs(1, 0, q - 1, seg, dsu, queryAt, dummy, compAns, pairAns, maxAns, unionAns);
    return {compAns, pairAns, maxAns, unionAns};
}

static long long kruskalSolve(int n, vector<WEdge> edges, vector<WEdge>* chosen = nullptr, int stopAfter = -1, bool stableTie = false, const vector<int>* forcedIds = nullptr, const vector<int>* bannedIds = nullptr, int* componentCount = nullptr, int* maxEdgeUsed = nullptr) {
    vector<WEdge> original = edges;
    vector<char> banned(edges.size(), 0), forced(edges.size(), 0);
    if (bannedIds) {
        for (int id : *bannedIds) if (0 <= id && id < (int)edges.size()) banned[id] = 1;
    }
    if (forcedIds) {
        for (int id : *forcedIds) if (0 <= id && id < (int)edges.size()) forced[id] = 1;
    }
    auto cmp = [&](const WEdge& a, const WEdge& b) {
        if (a.w != b.w) return a.w < b.w;
        if (stableTie) {
            if (a.u != b.u) return a.u < b.u;
            if (a.v != b.v) return a.v < b.v;
        }
        return a.id < b.id;
    };
    sort(edges.begin(), edges.end(), cmp);
    BasicDSU dsu(n);
    long long total = 0;
    int used = 0;
    int maxEdge = -1;
    if (chosen) chosen->clear();

    if (forcedIds) {
        for (int id : *forcedIds) {
            if (id < 0 || id >= (int)original.size() || banned[id]) continue;
            const auto& e = original[id];
            if (!dsu.unite(e.u, e.v)) return -1;
            total += e.w;
            ++used;
            maxEdge = max(maxEdge, e.w);
            if (chosen) chosen->push_back(e);
        }
    }

    for (const auto& e : edges) {
        if (banned[e.id] || (forcedIds && e.id >= 0 && e.id < (int)forced.size() && forced[e.id])) continue;
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            ++used;
            maxEdge = max(maxEdge, e.w);
            if (chosen) chosen->push_back(e);
            if (stopAfter != -1 && used >= stopAfter) break;
        }
    }
    if (componentCount) *componentCount = dsu.comps;
    if (maxEdgeUsed) *maxEdgeUsed = maxEdge;
    return total;
}

static GridTrace gridSolve(int rows, int cols, const vector<pair<int, int>>& activations) {
    int n = rows * cols;
    BasicDSU dsu(n);
    vector<char> active(n, 0);
    GridTrace tr;
    tr.components.reserve(activations.size());
    tr.largest.reserve(activations.size());
    tr.perimeter.reserve(activations.size());
    int comps = 0, best = 0, perimeter = 0;
    auto id = [&](int r, int c) { return r * cols + c; };
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    for (auto [r, c] : activations) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            tr.components.push_back(comps);
            tr.largest.push_back(best);
            tr.perimeter.push_back(perimeter);
            continue;
        }
        int x = id(r, c);
        if (!active[x]) {
            active[x] = 1;
            ++comps;
            best = max(best, 1);
            perimeter += 4;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                int y = id(nr, nc);
                if (!active[y]) continue;
                perimeter -= 2;
                if (dsu.unite(x, y)) {
                    --comps;
                    int root = dsu.find(x);
                    best = max(best, dsu.sz[root]);
                }
            }
        }
        tr.components.push_back(comps);
        tr.largest.push_back(best);
        tr.perimeter.push_back(perimeter);
    }
    return tr;
}

static vector<int> paintSolve(int n, const vector<PaintQuery>& queries) {
    SuccessorDSU nxt(n + 1);
    vector<int> color(n + 1, 0);
    for (auto [l, r, c] : queries) {
        if (l > r) swap(l, r);
        l = max(l, 0);
        r = min(r, n - 1);
        for (int x = nxt.find(l); x <= r; x = nxt.find(x)) {
            color[x] = c;

            nxt.erase(x);
        }
    }
    color.pop_back();
    return color;
}

static vector<vector<string>> mergeNamedEntities(const vector<vector<string>>& records, int keyColumn) {
    map<string, int> id;
    vector<vector<string>> groups;
    vector<int> parent;
    auto find = [&](auto self, int x) -> int {
        if (parent[x] == x) return x;
        return parent[x] = self(self, parent[x]);
    };
    auto unite = [&](int a, int b) {
        a = find(find, a);
        b = find(find, b);
        if (a == b) return;
        parent[b] = a;
    };

    int n = (int)records.size();
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int)records[i].size(); ++j) {
            const string& key = records[i][j];
            auto it = id.find(key);
            if (it == id.end()) id[key] = i;
            else unite(i, it->second);
        }
    }
    map<int, vector<string>> merged;
    for (int i = 0; i < n; ++i) {
        int r = find(find, i);
        merged[r].push_back(records[i][0]);
    }
    for (auto& [r, names] : merged) {
        sort(names.begin(), names.end());
        names.erase(unique(names.begin(), names.end()), names.end());
        groups.push_back(names);
    }
    return groups;
}

int dsuCountComponentsByEdges(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    for (auto [u, v] : edges) dsu.unite(u, v);
    return dsu.comps;
}

int dsuLargestComponentAfterEdges(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    int best = n ? 1 : 0;
    for (auto [u, v] : edges) {
        if (dsu.unite(u, v)) {
            best = max(best, dsu.sz[dsu.find(u)]);
        }
    }
    return best;
}

int dsuLargestComponentAfterEdgesReversed(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    int best = n ? 1 : 0;
    for (int i = (int)edges.size() - 1; i >= 0; --i) {
        auto [u, v] = edges[i];
        if (dsu.unite(u, v)) {
            best = max(best, dsu.sz[dsu.find(u)]);
        }
    }
    return best;
}

int dsuRedundantEdgesByEdges(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    int redundant = 0;
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v)) ++redundant;
    }
    return redundant;
}

bool dsuCanMergeIntoOneComponent(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    for (auto [u, v] : edges) dsu.unite(u, v);
    return dsu.comps == 1;
}

vector<int> dsuComponentSizesAfterBatchUnions(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    for (auto [u, v] : edges) dsu.unite(u, v);
    vector<int> sizes;
    sizes.reserve(n);
    for (int i = 0; i < n; ++i) if (dsu.find(i) == i) sizes.push_back(dsu.sz[i]);
    sort(sizes.begin(), sizes.end(), greater<int>());
    return sizes;
}

int dsuFirstCycleEdgeIndex(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    for (int i = 0; i < (int)edges.size(); ++i) {
        auto [u, v] = edges[i];
        if (!dsu.unite(u, v)) return i;
    }
    return -1;
}

int dsuMinimumEdgesToConnectGraph(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    for (auto [u, v] : edges) dsu.unite(u, v);
    return max(0, dsu.comps - 1);
}

long long dsuUnionSequenceChecksum(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    long long checksum = 0;
    for (auto [u, v] : edges) {
        if (dsu.unite(u, v)) {
            int r = dsu.find(u);
            checksum += 1LL * (r + 1) * dsu.sz[r];
        }
    }
    return checksum;
}

long long dsuKruskalMstWeight(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    return kruskalSolve(n, e);
}

vector<WEdge> dsuKruskalMstEdges(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    vector<WEdge> picked;
    kruskalSolve(n, e, &picked);
    return picked;
}

long long dsuKruskalForestWeight(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    return kruskalSolve(n, e, nullptr, -1, false, nullptr, nullptr, nullptr, nullptr);
}

long long dsuKruskalEarlyStopWeight(int n, const vector<WEdge>& edges, int targetEdges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    return kruskalSolve(n, e, nullptr, targetEdges);
}

long long dsuKruskalWithForcedEdgesWeight(int n, const vector<WEdge>& edges, const vector<int>& forcedIds) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    return kruskalSolve(n, e, nullptr, -1, false, &forcedIds, nullptr);
}

long long dsuKruskalWithForbiddenEdgesWeight(int n, const vector<WEdge>& edges, const vector<int>& bannedIds) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    return kruskalSolve(n, e, nullptr, -1, false, nullptr, &bannedIds);
}

bool dsuKruskalConnectsGraph(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    int comps = 0;
    kruskalSolve(n, e, nullptr, -1, false, nullptr, nullptr, &comps, nullptr);
    return comps == 1;
}

int dsuKruskalMaxEdgeUsed(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    int maxEdge = -1;
    kruskalSolve(n, e, nullptr, -1, false, nullptr, nullptr, nullptr, &maxEdge);
    return maxEdge;
}

int dsuKruskalBottleneckWeight(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    int maxEdge = -1;
    kruskalSolve(n, e, nullptr, -1, true, nullptr, nullptr, nullptr, &maxEdge);
    return maxEdge;
}

int dsuKruskalComponentCountAfterMst(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    int comps = 0;
    kruskalSolve(n, e, nullptr, -1, false, nullptr, nullptr, &comps, nullptr);
    return comps;
}

long long dsuKruskalStableTieBreakWeight(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;

    return kruskalSolve(n, e, nullptr, -1, true);
}

long long dsuKruskalChosenEdgeChecksum(int n, const vector<WEdge>& edges) {
    vector<WEdge> e = edges;
    for (int i = 0; i < (int)e.size(); ++i) e[i].id = i;
    vector<WEdge> picked;
    kruskalSolve(n, e, &picked);
    long long checksum = 0;
    for (const auto& edge : picked) checksum += 1LL * (edge.u + 1) * (edge.v + 1) + edge.w;
    return checksum;
}

bool dsuIsBipartiteAfterEdges(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v, 1)) return false;
    }
    return true;
}

int dsuFirstOddCycleEdgeIndex(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (int i = 0; i < (int)edges.size(); ++i) {
        auto [u, v] = edges[i];
        if (!dsu.unite(u, v, 1)) return i;
    }
    return -1;
}

int dsuParityConflictCount(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    int conflicts = 0;
    for (auto [u, v] : edges) if (!dsu.unite(u, v, 1)) ++conflicts;
    return conflicts;
}

vector<int> dsuParityColoringSnapshot(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v, 1)) return {};
    }
    vector<int> color(n, 0);
    for (int i = 0; i < n; ++i) {
        color[i] = dsu.find(i).second & 1;
    }
    return color;
}

int dsuParityComponentCount(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (auto [u, v] : edges) {
        if (!dsu.unite(u, v, 1)) return -1;
    }
    return dsu.comps;
}

bool dsuParityCanAddEdge(int n, const vector<pair<int,int>>& edges, int u, int v) {
    ParityDSU dsu(n);
    for (auto [a, b] : edges) {
        if (!dsu.unite(a, b, 1)) return false;
    }
    return dsu.unite(u, v, 1);
}

vector<int> dsuParityComponentSizes(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (auto [u, v] : edges) if (!dsu.unite(u, v, 1)) return {};
    vector<int> sizes;
    for (int i = 0; i < n; ++i) if (dsu.find(i).first == i) sizes.push_back(dsu.sz[i]);
    sort(sizes.begin(), sizes.end(), greater<int>());
    return sizes;
}

long long dsuParityMergeTraceChecksum(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    long long checksum = 0;
    for (auto [u, v] : edges) {
        if (dsu.unite(u, v, 1)) {
            auto [ru, pu] = dsu.find(u);
            checksum += 1LL * (ru + 1) * (pu + 1) + dsu.comps;
        }
    }
    return checksum;
}

long long dsuParitySameColorPairs(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (auto [u, v] : edges) if (!dsu.unite(u, v, 1)) return -1;
    vector<int> zero(n, 0), one(n, 0);
    for (int i = 0; i < n; ++i) {
        auto [r, p] = dsu.find(i);
        if (p & 1) ++one[r];
        else ++zero[r];
    }
    long long pairs = 0;
    for (int i = 0; i < n; ++i) if (dsu.find(i).first == i) {
        pairs += choose2(zero[i]) + choose2(one[i]);
    }
    return pairs;
}

long long dsuParityComponentSignature(int n, const vector<pair<int,int>>& edges) {
    ParityDSU dsu(n);
    for (auto [u, v] : edges) if (!dsu.unite(u, v, 1)) return -1;
    long long sig = 0;
    for (int i = 0; i < n; ++i) if (dsu.find(i).first == i) {
        sig ^= (1LL * (i + 1) << 1) ^ (1LL * dsu.sz[i] << 17);
    }
    return sig;
}

bool dsuDifferenceConstraintsFeasible(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) {
        if (!dsu.unite(u, v, w)) return false;
    }
    return true;
}

vector<ll> dsuDifferenceQueryAnswers(int n, const vector<tuple<int,int,ll>>& constraints, const vector<pair<int,int>>& queries) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) {
        if (!dsu.unite(u, v, w)) return {};
    }
    vector<ll> ans;
    ans.reserve(queries.size());
    for (auto [u, v] : queries) {
        auto [ru, du] = dsu.find(u);
        auto [rv, dv] = dsu.find(v);
        if (ru != rv) ans.push_back((ll)4e18);
        else ans.push_back(dv - du);
    }
    return ans;
}

ll dsuWeightedComponentPotentialSpan(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return -1;
    vector<ll> mn(n, (ll)4e18), mx(n, -(ll)4e18);
    for (int i = 0; i < n; ++i) {
        auto [r, d] = dsu.find(i);
        mn[r] = min(mn[r], d);
        mx[r] = max(mx[r], d);
    }
    ll best = 0;
    for (int i = 0; i < n; ++i) if (dsu.find(i).first == i) {
        if (mn[i] == (ll)4e18) continue;
        best = max(best, mx[i] - mn[i]);
    }
    return best;
}

int dsuWeightedContradictionIndex(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (int i = 0; i < (int)constraints.size(); ++i) {
        auto [u, v, w] = constraints[i];
        if (!dsu.unite(u, v, w)) return i;
    }
    return -1;
}

ll dsuWeightedMaxDifference(int n, const vector<tuple<int,int,ll>>& constraints, const vector<pair<int,int>>& queries) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return -1;
    ll best = 0;
    for (auto [u, v] : queries) {
        auto [ru, du] = dsu.find(u);
        auto [rv, dv] = dsu.find(v);
        if (ru == rv) best = max(best, llabs(dv - du));
    }
    return best;
}

vector<ll> dsuWeightedRootOffsets(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return {};
    vector<ll> offsets(n);
    for (int i = 0; i < n; ++i) offsets[i] = dsu.potential(i);
    return offsets;
}

int dsuWeightedComponentsAfterConstraints(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return -1;
    return dsu.comps;
}

int dsuWeightedAnchoredNodeCount(int n, const vector<tuple<int,int,ll>>& constraints, int anchor) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return -1;
    int root = dsu.find(anchor).first;
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (dsu.find(i).first == root) ++cnt;
    return cnt;
}

ll dsuWeightedComponentPotentialChecksum(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return -1;

    ll checksum = 0;
    for (int i = 0; i < n; ++i) {
        auto [r, d] = dsu.find(i);
        checksum += 1LL * (r + 1) * (i + 1) + d;
    }
    return checksum;
}

vector<int> dsuWeightedConsistentRoots(int n, const vector<tuple<int,int,ll>>& constraints) {
    WeightedDSU dsu(n);
    for (auto [u, v, w] : constraints) if (!dsu.unite(u, v, w)) return {};
    vector<int> roots;
    for (int i = 0; i < n; ++i) if (dsu.find(i).first == i) roots.push_back(i);
    return roots;
}

vector<int> dsuRollbackOfflineComponentCounts(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    return comp;
}

vector<ll> dsuRollbackOfflineConnectedPairs(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    return pairs;
}

vector<int> dsuRollbackOfflineLargestComponentSizes(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    return best;
}

vector<int> dsuRollbackOfflineUnionCounts(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    return unions;
}

vector<int> dsuRollbackOfflineMaxSizeTrace(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    return best;
}

vector<ll> dsuRollbackOfflineChecksumTrace(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    vector<ll> checksum;
    checksum.reserve(comp.size());
    for (size_t i = 0; i < comp.size(); ++i) {
        checksum.push_back(1LL * comp[i] * 1000003 + pairs[i] + best[i] + unions[i]);
    }
    return checksum;
}

vector<ll> dsuRollbackOfflineMergedQueries(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    vector<ll> merged;
    merged.reserve(comp.size());
    for (size_t i = 0; i < comp.size(); ++i) merged.push_back(pairs[i] + comp[i] + best[i]);
    return merged;
}

vector<int> dsuRollbackOfflineActiveComponents(int n, const vector<RollbackOp>& ops) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    return comp;
}

vector<int> dsuPaintIntervalsColoring(int n, const vector<PaintQuery>& queries) {
    return paintSolve(n, queries);
}

int dsuCountPaintedCells(int n, const vector<PaintQuery>& queries) {
    auto colors = paintSolve(n, queries);
    int painted = 0;
    for (int c : colors) if (c != 0) ++painted;
    return painted;
}

vector<int> dsuNextUnpaintedPositions(int n, const vector<PaintQuery>& queries) {
    vector<int> colors = paintSolve(n, queries);
    SuccessorDSU nxt(n + 1);
    for (int i = 0; i < n; ++i) if (colors[i] != 0) nxt.erase(i);
    vector<int> nextEmpty(n);
    for (int i = 0; i < n; ++i) nextEmpty[i] = nxt.find(i);
    return nextEmpty;
}

int dsuMinOperationsToCoverAllCells(int n, const vector<PaintQuery>& queries) {
    SuccessorDSU nxt(n + 1);
    vector<int> seen(n, 0);
    int covered = 0;
    int used = 0;
    for (auto [l, r, c] : queries) {
        if (l > r) swap(l, r);
        l = max(l, 0);
        r = min(r, n - 1);
        bool changed = false;
        for (int x = nxt.find(l); x <= r; x = nxt.find(x)) {
            if (!seen[x]) {
                seen[x] = 1;
                ++covered;
                changed = true;
            }
            nxt.erase(x);
        }
        ++used;
        if (covered == n) return used;
        if (!changed) continue;
    }
    return (covered == n ? used : -1);
}

vector<int> dsuPaintedPrefixLengths(int n, const vector<PaintQuery>& queries) {
    vector<int> res;
    res.reserve(queries.size());
    vector<int> colors(n, 0);
    for (auto [l, r, c] : queries) {
        if (l > r) swap(l, r);
        l = max(l, 0);
        r = min(r, n - 1);
        for (int i = l; i <= r; ++i) colors[i] = c;
        int pref = 0;
        while (pref < n && colors[pref] != 0) ++pref;
        res.push_back(pref);
    }
    return res;
}

long long dsuIntervalPaintCostChecksum(int n, const vector<PaintQuery>& queries) {
    auto colors = paintSolve(n, queries);
    long long checksum = 0;
    for (int i = 0; i < (int)colors.size(); ++i) checksum += 1LL * (i + 1) * colors[i];
    return checksum;
}

int dsuGridIslandCount(int rows, int cols, const vector<pair<int,int>>& activations) {
    auto tr = gridSolve(rows, cols, activations);
    return tr.components.empty() ? 0 : tr.components.back();
}

int dsuGridLargestIslandSize(int rows, int cols, const vector<pair<int,int>>& activations) {
    auto tr = gridSolve(rows, cols, activations);
    return tr.largest.empty() ? 0 : tr.largest.back();
}

vector<int> dsuGridComponentCountsAfterActivations(int rows, int cols, const vector<pair<int,int>>& activations) {
    auto tr = gridSolve(rows, cols, activations);
    return tr.components;
}

vector<int> dsuGridPerimeterAfterActivations(int rows, int cols, const vector<pair<int,int>>& activations) {
    auto tr = gridSolve(rows, cols, activations);
    return tr.perimeter;
}

long long dsuGridMergeTraceChecksum(int rows, int cols, const vector<pair<int,int>>& activations) {
    auto tr = gridSolve(rows, cols, activations);
    long long checksum = 0;
    for (size_t i = 0; i < tr.components.size(); ++i) {
        checksum += 1LL * tr.components[i] * 10007 + tr.largest[i] * 131 + tr.perimeter[i];
    }
    return checksum;
}

bool dsuGridConnectivityAfterActivations(int rows, int cols, const vector<pair<int,int>>& activations) {
    auto tr = gridSolve(rows, cols, activations);
    return tr.components.empty() ? true : (tr.components.back() <= 1);
}

vector<ll> dsuComponentWeightSumsAfterUnions(int n, const vector<pair<int,int>>& edges, const vector<ll>& weight) {
    AggDSU dsu(n, weight);
    for (auto [u, v] : edges) dsu.unite(u, v);
    vector<ll> sums;
    for (int i = 0; i < n; ++i) if (dsu.find(i) == i) sums.push_back(dsu.sum[i]);
    sort(sums.begin(), sums.end(), greater<ll>());
    return sums;
}

pair<ll,ll> dsuComponentMinMaxAfterUnions(int n, const vector<pair<int,int>>& edges, const vector<ll>& weight) {
    AggDSU dsu(n, weight);
    for (auto [u, v] : edges) dsu.unite(u, v);
    ll mn = (ll)4e18, mx = -(ll)4e18;
    for (int i = 0; i < n; ++i) if (dsu.find(i) == i) {
        mn = min(mn, dsu.sum[i]);
        mx = max(mx, dsu.sum[i]);
    }
    if (mn == (ll)4e18) return {0, 0};
    return {mn, mx};
}

int dsuFriendCircleCountByNames(const vector<pair<string,string>>& relations) {
    map<string, int> id;
    vector<pair<int,int>> edges;
    for (auto [a, b] : relations) {
        if (!id.count(a)) id[a] = (int)id.size();
        if (!id.count(b)) id[b] = (int)id.size();
        edges.push_back({id[a], id[b]});
    }
    BasicDSU dsu((int)id.size());
    for (auto [u, v] : edges) dsu.unite(u, v);
    return dsu.comps;
}


vector<vector<string>> dsuMergeAccountsByEmail(const vector<vector<string>>& accounts) {
    map<string, int> id;
    vector<vector<string>> acc = accounts;
    int n = (int)acc.size();
    BasicDSU dsu(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int)acc[i].size(); ++j) {
            const string& email = acc[i][j];
            auto it = id.find(email);
            if (it == id.end()) id[email] = i;
            else dsu.unite(i, it->second);
        }
    }
    map<int, vector<string>> groups;
    for (int i = 0; i < n; ++i) {
        int r = dsu.find(i);
        groups[r].push_back(acc[i][0]);
        for (int j = 1; j < (int)acc[i].size(); ++j) groups[r].push_back(acc[i][j]);
    }
    vector<vector<string>> res;
    for (auto& [r, vals] : groups) {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        res.push_back(vals);
    }
    return res;
}

vector<vector<string>> dsuMergeAccountsByPhone(const vector<vector<string>>& accounts) {
    map<string, int> id;
    int n = (int)accounts.size();
    BasicDSU dsu(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int)accounts[i].size(); ++j) {
            const string& phone = accounts[i][j];
            auto it = id.find(phone);
            if (it == id.end()) id[phone] = i;
            else dsu.unite(i, it->second);
        }
    }
    map<int, vector<string>> groups;
    for (int i = 0; i < n; ++i) {
        int r = dsu.find(i);
        groups[r].push_back(accounts[i][0]);
    }
    vector<vector<string>> res;
    for (auto& [r, vals] : groups) {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        res.push_back(vals);
    }
    return res;
}

int dsuCallbackDrivenMergeUnknown(int n, const vector<pair<int,int>>& edges, const function<bool(int,int)>& accept) {
    BasicDSU dsu(n);
    int merged = 0;
    for (auto [u, v] : edges) {
        if (!accept(u, v)) continue;
        if (dsu.unite(u, v)) ++merged;
    }
    return merged;
}

int dsuFunctionPointerParentAccessUnknown(int n, int* parent, bool (*allow)(int)) {
    int touched = 0;
    for (int i = 0; i < n; ++i) {
        if (allow(i)) {
            parent[i] = parent[parent[i]];
            ++touched;
        }
    }
    return touched;
}

int dsuMutableParentAliasUnknown(int n, vector<int>& parent, vector<int>& sz) {
    int changed = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] != i) {
            parent[i] = parent[parent[i]];
            ++changed;
        }
        if (i < (int)sz.size()) sz[i] += parent[i] & 1;
    }
    return changed;
}

int dsuLambdaPredicateUnionUnknown(int n, const vector<pair<int,int>>& edges, const std::function<bool(int)>& stop) {
    BasicDSU dsu(n);
    int steps = 0;
    for (auto [u, v] : edges) {
        if (stop(steps)) break;
        dsu.unite(u, v);
        ++steps;
    }
    return dsu.comps;
}

long long dsuExternalComparatorMergesUnknown(int n, vector<WEdge> edges, const function<bool(const WEdge&, const WEdge&)>& cmp) {
    sort(edges.begin(), edges.end(), cmp);
    BasicDSU dsu(n);
    long long total = 0;
    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) total += e.w;
    }
    return total;
}

int dsuUnorderedMapStringMergeUnknown(const vector<vector<string>>& records) {
    unordered_map<string, int> id;
    vector<int> parent(records.size());
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](auto self, int x) -> int {
        return parent[x] == x ? x : parent[x] = self(self, parent[x]);
    };
    auto unite = [&](int a, int b) {
        a = find(find, a);
        b = find(find, b);
        if (a != b) parent[b] = a;
    };
    for (int i = 0; i < (int)records.size(); ++i) {
        for (int j = 1; j < (int)records[i].size(); ++j) {
            auto [it, inserted] = id.emplace(records[i][j], i);
            if (!inserted) unite(i, it->second);
        }
    }
    int roots = 0;
    for (int i = 0; i < (int)records.size(); ++i) if (find(find, i) == i) ++roots;
    return roots;
}

int dsuHashBasedEmailMergeUnknown(const vector<vector<string>>& accounts) {
    unordered_map<string, int> firstSeen;
    vector<int> parent(accounts.size());
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < (int)accounts.size(); ++i) {
        for (int j = 1; j < (int)accounts[i].size(); ++j) {
            auto it = firstSeen.find(accounts[i][j]);
            if (it == firstSeen.end()) firstSeen[accounts[i][j]] = i;
            else parent[i] = it->second;
        }
    }
    return (int)firstSeen.size();
}

int dsuStatefulFunctorFindUnknown(int n, const vector<pair<int,int>>& edges, const function<int(int)>& findRoot) {
    BasicDSU dsu(n);
    int failed = 0;
    for (auto [u, v] : edges) {
        int ru = findRoot(u);
        int rv = findRoot(v);
        if (ru == rv || !dsu.unite(u, v)) ++failed;
    }
    return failed;
}

int dsuRollbackWithCallbackUnknown(int n, const vector<RollbackOp>& ops, const function<void(int)>& onQuery) {
    auto [comp, pairs, best, unions] = rollbackSolve(n, ops);
    for (int x : comp) onQuery(x);
    return (int)comp.size();
}

int dsuAliasSensitiveComponentScanUnknown(int n, vector<int>& parent, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    for (auto [u, v] : edges) dsu.unite(u, v);
    for (int i = 0; i < n && i < (int)parent.size(); ++i) parent[i] = dsu.find(i);
    return dsu.comps;
}

int dsuPotentiallyNonTerminatingUnionUnknown(int n, const vector<pair<int,int>>& edges, const function<bool(int,int)>& continueLoop) {
    BasicDSU dsu(n);
    int idx = 0;
    while (idx < (int)edges.size() && continueLoop(idx, dsu.comps)) {
        auto [u, v] = edges[idx++];
        dsu.unite(u, v);
    }
    return dsu.comps;
}

long long dsuIndirectMutationThroughReferenceUnknown(int n, vector<int>& parent, vector<int>& sz, const vector<pair<int,int>>& edges) {
    long long touched = 0;
    for (auto [u, v] : edges) {
        if (u < n && v < n && parent[u] != parent[v]) {
            parent[u] = parent[v];
            if (u < (int)sz.size()) sz[u] += sz[v % sz.size()];
            ++touched;
        }
    }
    return touched;
}

int dsuTemplateAliasCycleUnknown(int n, const vector<pair<int,int>>& edges) {
    BasicDSU dsu(n);
    int score = 0;
    auto join = [&](auto&& self, int i) -> void {
        if (i >= (int)edges.size()) return;
        auto [u, v] = edges[i];
        dsu.unite(u, v);
        score += dsu.comps;
        self(self, i + 1);

    };
    join(join, 0);
    return score;
}

int dsuRuntimeSelectedJoinUnknown(int n, const vector<pair<int,int>>& edges, int mode) {
    BasicDSU dsu(n);
    for (auto [u, v] : edges) {
        if (mode == 0) {
            dsu.unite(u, v);
        } else if (mode == 1) {
            dsu.unite(v, u);
        } else {
            if ((u ^ v ^ mode) & 1) dsu.unite(u, v);
        }
    }
    return dsu.comps;
}

int dsuCallbackBasedStopConditionUnknown(int n, const vector<pair<int,int>>& edges, const function<bool(int)>& stopAtMergeCount) {
    BasicDSU dsu(n);
    int merges = 0;
    for (auto [u, v] : edges) {
        if (stopAtMergeCount(merges)) break;
        if (dsu.unite(u, v)) ++merges;
    }
    return merges;
}

int dsuMonkeyPatchedFindUnknown(int n, const vector<pair<int,int>>& edges, const function<int(int)>& patchedFind) {
    BasicDSU dsu(n);
    int acc = 0;
    for (auto [u, v] : edges) {
        acc += patchedFind(u) ^ patchedFind(v);
        dsu.unite(u, v);
    }
    return acc;
}
