#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};
long long pack_l2_kruskalStructural(int n, vector<tuple<int,int,int>> edges) {
    sort(edges.begin(), edges.end(), [](auto& A, auto& B){ return get<2>(A) < get<2>(B); });
    DSU dsu(n);
    long long ans = 0;
    for (auto [u, v, w] : edges) if (dsu.unite(u, v)) ans += w;
    return ans;
}
