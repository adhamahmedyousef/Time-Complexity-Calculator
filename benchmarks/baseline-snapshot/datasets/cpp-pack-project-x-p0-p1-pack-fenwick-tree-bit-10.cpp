#include <bits/stdc++.h>
using namespace std;


// fenwick-tree-bit-01
struct BIT_01 {
    int n; vector<long long> bit;
    BIT_01(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_01(int n, const vector<int>& xs) {
    BIT_01 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-02
struct BIT_02 {
    int n; vector<long long> bit;
    BIT_02(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_02(int n, const vector<int>& xs) {
    BIT_02 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-03
struct BIT_03 {
    int n; vector<long long> bit;
    BIT_03(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_03(int n, const vector<int>& xs) {
    BIT_03 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-04
struct BIT_04 {
    int n; vector<long long> bit;
    BIT_04(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_04(int n, const vector<int>& xs) {
    BIT_04 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-05
struct BIT_05 {
    int n; vector<long long> bit;
    BIT_05(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_05(int n, const vector<int>& xs) {
    BIT_05 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-06
struct BIT_06 {
    int n; vector<long long> bit;
    BIT_06(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_06(int n, const vector<int>& xs) {
    BIT_06 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-07
struct BIT_07 {
    int n; vector<long long> bit;
    BIT_07(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_07(int n, const vector<int>& xs) {
    BIT_07 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-08
struct BIT_08 {
    int n; vector<long long> bit;
    BIT_08(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_08(int n, const vector<int>& xs) {
    BIT_08 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-09
struct BIT_09 {
    int n; vector<long long> bit;
    BIT_09(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_09(int n, const vector<int>& xs) {
    BIT_09 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-10
struct BIT_10 {
    int n; vector<long long> bit;
    BIT_10(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long pack_project_x_p0_p1_pack_fenwick_tree_bit_10(int n, const vector<int>& xs) {
    BIT_10 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}
