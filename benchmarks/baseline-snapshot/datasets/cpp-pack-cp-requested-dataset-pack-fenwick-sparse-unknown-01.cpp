#include <bits/stdc++.h>
using namespace std;

// fenwick-point-update-prefix-01
struct Fenwick_1 {
    int n;
    vector<long long> bit;
    Fenwick_1(int n) : n(n), bit(n + 1) {}
    void add(int index, long long value) { for (; index <= n; index += index & -index) bit[index] += value; }
    long long sum(int index) const { long long result = 0; for (; index > 0; index -= index & -index) result += bit[index]; return result; }
};
long long fenwickQueries_1(const vector<pair<int, int>>& operations, int n) {
    Fenwick_1 tree(n);
    long long answer = 0;
    for (auto [type, x] : operations) { tree.add(x, 1); answer += tree.sum(x); }
    return answer;
}

// fenwick-range-update-point-query-01
struct FenwickRange_1 {
    int n;
    vector<long long> bit;
    FenwickRange_1(int n) : n(n), bit(n + 1) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
    long long sum(int i) const { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
};
long long fenwickRangeUpdatePointQuery_1(int n, const vector<tuple<int,int,long long>>& updates) {
    FenwickRange_1 ft(n);
    long long ans = 0;
    for (auto [l, r, v] : updates) { ft.add(l, v); if (r + 1 <= n) ft.add(r + 1, -v); ans += ft.sum(r); }
    return ans;
}

// fenwick-2d-01
struct Fenwick2D_1 {
    int n;
    vector<vector<long long>> bit;
    Fenwick2D_1(int n) : n(n), bit(n + 1, vector<long long>(n + 1, 0)) {}
    void add(int x, int y, long long v) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= n; j += j & -j)
                bit[i][j] += v;
    }
    long long sum(int x, int y) const {
        long long r = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                r += bit[i][j];
        return r;
    }
};
long long fenwick2DQueries_1(int n, const vector<tuple<int,int,int>>& ops) {
    Fenwick2D_1 ft(n);
    long long total = 0;
    for (auto [x, y, v] : ops) { ft.add(x, y, v); total += ft.sum(x, y); }
    return total;
}

// sparse-table-rmq-01
struct SparseTable_1 {
    vector<vector<int>> st;
    SparseTable_1(const vector<int>& a) {
        int n = (int)a.size(), K = 1;
        while ((1 << K) <= n) ++K;
        st.assign(K, vector<int>(n));
        st[0] = a;
        for (int k = 1; k < K; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    int query(int l, int r) const {
        int len = r - l + 1, k = 31 - __builtin_clz(len);
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
int sparseTableRMQ_1(const vector<int>& a, const vector<pair<int,int>>& qs) {
    SparseTable_1 st(a);
    int ans = 0;
    for (auto [l, r] : qs) ans += st.query(l, r);
    return ans;
}

// fenwick-sparse-unknown-01
long long pack_cp_requested_dataset_pack_fenwickSparseUnknown_1(vector<int> a) {
    int i = 1;
    long long sum = 0;
    while (i < (int)a.size()) {
        sum += a[i];
        if (a[i] & 1) i += a[i] % 3 + 1;
        else i -= (a[i] % 2);
        if (i <= 0) i = 1;
    }
    return sum;
}
