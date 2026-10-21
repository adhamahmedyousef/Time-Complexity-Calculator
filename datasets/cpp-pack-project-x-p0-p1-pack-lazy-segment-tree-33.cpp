#include <bits/stdc++.h>
using namespace std;


// lazy-segment-tree-01
long long lazy_segment_tree_01(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-02
long long lazy_segment_tree_02(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-03
long long lazy_segment_tree_03(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-04
long long lazy_segment_tree_04(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-05
long long lazy_segment_tree_05(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-06
long long lazy_segment_tree_06(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-07
long long lazy_segment_tree_07(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-08
long long lazy_segment_tree_08(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-09
long long lazy_segment_tree_09(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-10
long long lazy_segment_tree_10(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-11
long long lazy_segment_tree_11(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-12
long long lazy_segment_tree_12(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-13
long long lazy_segment_tree_13(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-14
long long lazy_segment_tree_14(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-15
long long lazy_segment_tree_15(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-16
long long lazy_segment_tree_16(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-17
long long lazy_segment_tree_17(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-18
long long lazy_segment_tree_18(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-19
long long lazy_segment_tree_19(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-20
long long lazy_segment_tree_20(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-21
long long lazy_segment_tree_21(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-22
long long lazy_segment_tree_22(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-23
long long lazy_segment_tree_23(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-24
long long lazy_segment_tree_24(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n));
    auto add = [&](auto&& self,int p,int l,int r,int ql,int qr,long long v)->void {
        if (qr<l||r<ql) return;
        if (ql<=l&&r<=qr) { t[p]+=v; lz[p]+=v; return; }
        int m=(l+r)/2; if (lz[p]) { for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } lz[p]=0; }
        self(self,p<<1,l,m,ql,qr,v); self(self,p<<1|1,m+1,r,ql,qr,v); t[p]=min(t[p<<1],t[p<<1|1]);
    };
    if (n) for (auto [l,r,v]:ops) add(add,1,0,n-1,l,r,v);
    return (long long)t.size();
}

// lazy-segment-tree-25
static long long push_25(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_25(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_25(t,lz,1); }
    return ans;
}

// lazy-segment-tree-26
static long long push_26(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_26(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_26(t,lz,1); }
    return ans;
}

// lazy-segment-tree-27
static long long push_27(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_27(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_27(t,lz,1); }
    return ans;
}

// lazy-segment-tree-28
static long long push_28(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_28(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_28(t,lz,1); }
    return ans;
}

// lazy-segment-tree-29
static long long push_29(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_29(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_29(t,lz,1); }
    return ans;
}

// lazy-segment-tree-30
static long long push_30(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_30(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_30(t,lz,1); }
    return ans;
}

// lazy-segment-tree-31
static long long push_31(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_31(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_31(t,lz,1); }
    return ans;
}

// lazy-segment-tree-32
static long long push_32(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long lazy_segment_tree_32(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_32(t,lz,1); }
    return ans;
}

// lazy-segment-tree-33
static long long push_33(vector<long long>& t, vector<long long>& lz, int p) { if (!lz[p]) return 0; for (int c : {p<<1,p<<1|1}) { t[c]+=lz[p]; lz[c]+=lz[p]; } long long x=lz[p]; lz[p]=0; return x; }
long long pack_project_x_p0_p1_pack_lazy_segment_tree_33(int n, const vector<tuple<int,int,int>>& ops) {
    vector<long long> t(4*max(1,n)), lz(4*max(1,n)); long long ans=0;
    for (auto [l,r,v]:ops) { ans += v; if (n) push_33(t,lz,1); }
    return ans;
}
