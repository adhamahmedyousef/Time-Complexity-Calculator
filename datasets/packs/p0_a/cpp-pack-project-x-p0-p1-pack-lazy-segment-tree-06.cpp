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
long long pack_project_x_p0_p1_pack_lazy_segment_tree_06(int n, const vector<tuple<int,int,int>>& ops) {
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
