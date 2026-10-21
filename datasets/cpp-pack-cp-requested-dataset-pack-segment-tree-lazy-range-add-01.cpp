#include <bits/stdc++.h>
using namespace std;

// segment-tree-recursive-build-query-update-01
struct SegTree_1 {
    int n;
    vector<int> t;
    SegTree_1(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), INT_MAX) {
        build(1, 0, n - 1, a);
    }
    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r) { t[p] = a[l]; return; }
        int m = (l + r) / 2;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
    int query(int p, int l, int r, int ql, int qr) const {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) return t[p];
        int m = (l + r) / 2;
        return min(query(p << 1, l, m, ql, qr), query(p << 1 | 1, m + 1, r, ql, qr));
    }
    void update(int p, int l, int r, int idx, int val) {
        if (l == r) { t[p] = val; return; }
        int m = (l + r) / 2;
        if (idx <= m) update(p << 1, l, m, idx, val);
        else update(p << 1 | 1, m + 1, r, idx, val);
        t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
};
int segmentTreeRangeMin_1(const vector<int>& a, const vector<pair<int,int>>& queries) {
    SegTree_1 st(a);
    long long ans = 0;
    for (auto [l, r] : queries) ans += st.query(1, 0, (int)a.size() - 1, l, r);
    return (int)ans;
}

// segment-tree-lazy-range-add-01
struct LazySeg_1 {
    int n;
    vector<long long> t, lazy;
    LazySeg_1(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), 0), lazy(4 * max(1, (int)a.size()), 0) {
        build(1, 0, n - 1, a);
    }
    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r) { t[p] = a[l]; return; }
        int m = (l + r) / 2;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
    void push(int p) {
        if (!lazy[p]) return;
        for (int c : {p << 1, p << 1 | 1}) { t[c] += lazy[p]; lazy[c] += lazy[p]; }
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
long long pack_cp_requested_dataset_pack_segmentTreeLazyRangeAdd_1(const vector<int>& a, const vector<tuple<int,int,int>>& ops) {
    LazySeg_1 st(a);
    long long score = 0;
    for (auto [l, r, v] : ops) { st.add(1, 0, (int)a.size() - 1, l, r, v); score += v; }
    return score;
}
