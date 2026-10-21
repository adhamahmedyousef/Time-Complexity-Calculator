#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n; vector<long long> tree;
    explicit SegTree(int size) : n(size), tree(4 * size) {}
    long long query(int p, int l, int r, int i, int j) { if (j < l || r < i) return 0; if (i <= l && r <= j) return tree[p]; int m = (l + r) / 2; return query(p * 2, l, m, i, j) + query(p * 2 + 1, m + 1, r, i, j); }
    void update(int p, int l, int r, int index, long long value) { if (l == r) { tree[p] = value; return; } int m = (l + r) / 2; if (index <= m) update(p * 2, l, m, index, value); else update(p * 2 + 1, m + 1, r, index, value); tree[p] = tree[p * 2] + tree[p * 2 + 1]; }
};

vector<vector<int>> sampleBuildLCA(int n, const vector<vector<int>>& g, int root) {
    int log = 1; while ((1 << log) <= n) ++log;
    vector<vector<int>> up(log, vector<int>(n, -1)); vector<int> depth(n);
    function<void(int,int)> dfs = [&](int u, int parent) { up[0][u] = parent; for (int k = 1; k < log; ++k) if (up[k - 1][u] != -1) up[k][u] = up[k - 1][up[k - 1][u]]; for (int v : g[u]) if (v != parent) depth[v] = depth[u] + 1, dfs(v, u); };
    dfs(root, -1); return up;
}

vector<int> sampleFenwickPrefix(const vector<int>& a) {
    int n = static_cast<int>(a.size()); vector<int> bit(n + 1), result(n);
    auto add = [&](int i, int value) { for (; i <= n; i += i & -i) bit[i] += value; };
    auto sum = [&](int i) { int value = 0; for (; i > 0; i -= i & -i) value += bit[i]; return value; };
    for (int i = 0; i < n; ++i) add(i + 1, a[i]);
    for (int i = 0; i < n; ++i) result[i] = sum(i + 1);
    return result;
}

vector<long long> sampleMergeSortTreeBuild(vector<long long> a) { sort(a.begin(), a.end()); return a; }
