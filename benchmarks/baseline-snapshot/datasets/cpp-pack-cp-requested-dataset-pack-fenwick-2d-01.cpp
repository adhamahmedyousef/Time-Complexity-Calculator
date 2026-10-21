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
long long pack_cp_requested_dataset_pack_fenwick2DQueries_1(int n, const vector<tuple<int,int,int>>& ops) {
    Fenwick2D_1 ft(n);
    long long total = 0;
    for (auto [x, y, v] : ops) { ft.add(x, y, v); total += ft.sum(x, y); }
    return total;
}
