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
long long fenwick_tree_bit_10(int n, const vector<int>& xs) {
    BIT_10 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-11
struct BIT_11 {
    int n; vector<long long> bit;
    BIT_11(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_11(int n, const vector<int>& xs) {
    BIT_11 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-12
struct BIT_12 {
    int n; vector<long long> bit;
    BIT_12(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_12(int n, const vector<int>& xs) {
    BIT_12 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-13
struct BIT_13 {
    int n; vector<long long> bit;
    BIT_13(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_13(int n, const vector<int>& xs) {
    BIT_13 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-14
struct BIT_14 {
    int n; vector<long long> bit;
    BIT_14(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_14(int n, const vector<int>& xs) {
    BIT_14 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-15
struct BIT_15 {
    int n; vector<long long> bit;
    BIT_15(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_15(int n, const vector<int>& xs) {
    BIT_15 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-16
struct BIT_16 {
    int n; vector<long long> bit;
    BIT_16(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_16(int n, const vector<int>& xs) {
    BIT_16 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-17
struct BIT_17 {
    int n; vector<long long> bit;
    BIT_17(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_17(int n, const vector<int>& xs) {
    BIT_17 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-18
struct BIT_18 {
    int n; vector<long long> bit;
    BIT_18(int n): n(n), bit(n+1) {}
    void add(int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
    long long sum(int i) const { long long s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }
};
long long fenwick_tree_bit_18(int n, const vector<int>& xs) {
    BIT_18 ft(n); long long ans=0; for (int x:xs) { ft.add(x,1); ans += ft.sum(x); } return ans;
}

// fenwick-tree-bit-19
static void add_19(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long fenwick_tree_bit_19(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_19(bit,n,x,1); ans += x; } return ans;
}

// fenwick-tree-bit-20
static void add_20(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long fenwick_tree_bit_20(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_20(bit,n,x,1); ans += x; } return ans;
}

// fenwick-tree-bit-21
static void add_21(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long fenwick_tree_bit_21(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_21(bit,n,x,1); ans += x; } return ans;
}

// fenwick-tree-bit-22
static void add_22(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long fenwick_tree_bit_22(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_22(bit,n,x,1); ans += x; } return ans;
}

// fenwick-tree-bit-23
static void add_23(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long fenwick_tree_bit_23(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_23(bit,n,x,1); ans += x; } return ans;
}

// fenwick-tree-bit-24
static void add_24(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long fenwick_tree_bit_24(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_24(bit,n,x,1); ans += x; } return ans;
}

// fenwick-tree-bit-25
static void add_25(vector<long long>& bit, int n, int i, long long v) { for (; i<=n; i += i&-i) bit[i] += v; }
long long pack_project_x_p0_p1_pack_fenwick_tree_bit_25(int n, const vector<int>& xs) {
    vector<long long> bit(n+1); long long ans=0; for (int x:xs) { add_25(bit,n,x,1); ans += x; } return ans;
}
