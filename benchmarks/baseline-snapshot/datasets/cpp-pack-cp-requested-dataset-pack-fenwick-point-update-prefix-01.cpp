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
long long pack_cp_requested_dataset_pack_fenwickQueries_1(const vector<pair<int, int>>& operations, int n) {
    Fenwick_1 tree(n);
    long long answer = 0;
    for (auto [type, x] : operations) { tree.add(x, 1); answer += tree.sum(x); }
    return answer;
}
