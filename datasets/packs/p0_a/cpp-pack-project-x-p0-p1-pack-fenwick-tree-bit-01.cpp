#include <bits/stdc++.h>
using namespace std;


// fenwick-tree-bit-01
struct BIT_01 {
    int n; vector<long long> bit;
    BIT_01(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long pack_project_x_p0_p1_pack_fenwick_tree_bit_01(int n, const vector<int>& xs) {
    BIT_01 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}
