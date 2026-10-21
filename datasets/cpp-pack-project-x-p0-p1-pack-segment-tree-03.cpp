#include <bits/stdc++.h>
using namespace std;


// segment-tree-01
struct Seg_01 {
    int n; vector<long long> t;
    Seg_01(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
        if (n) build(1,0,n-1,a);
    }
    void build(int p,int l,int r,const vector<int>& a) {
        if (l==r) { t[p]=a[l]; return; }
        int m=(l+r)/2; build(p<<1,l,m,a); build(p<<1|1,m+1,r,a);
        t[p]=min(t[p<<1],t[p<<1|1]);
    }
    long long query(int p,int l,int r,int ql,int qr) const {
        if (qr<l||r<ql) return (long long)4e18;
        if (ql<=l&&r<=qr) return t[p];
        int m=(l+r)/2;
        return min(query(p<<1,l,m,ql,qr), query(p<<1|1,m+1,r,ql,qr));
    }
};
long long segment_tree_01(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_01 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-02
struct Seg_02 {
    int n; vector<long long> t;
    Seg_02(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
        if (n) build(1,0,n-1,a);
    }
    void build(int p,int l,int r,const vector<int>& a) {
        if (l==r) { t[p]=a[l]; return; }
        int m=(l+r)/2; build(p<<1,l,m,a); build(p<<1|1,m+1,r,a);
        t[p]=min(t[p<<1],t[p<<1|1]);
    }
    long long query(int p,int l,int r,int ql,int qr) const {
        if (qr<l||r<ql) return (long long)4e18;
        if (ql<=l&&r<=qr) return t[p];
        int m=(l+r)/2;
        return min(query(p<<1,l,m,ql,qr), query(p<<1|1,m+1,r,ql,qr));
    }
};
long long segment_tree_02(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_02 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-03
struct Seg_03 {
    int n; vector<long long> t;
    Seg_03(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
        if (n) build(1,0,n-1,a);
    }
    void build(int p,int l,int r,const vector<int>& a) {
        if (l==r) { t[p]=a[l]; return; }
        int m=(l+r)/2; build(p<<1,l,m,a); build(p<<1|1,m+1,r,a);
        t[p]=min(t[p<<1],t[p<<1|1]);
    }
    long long query(int p,int l,int r,int ql,int qr) const {
        if (qr<l||r<ql) return (long long)4e18;
        if (ql<=l&&r<=qr) return t[p];
        int m=(l+r)/2;
        return min(query(p<<1,l,m,ql,qr), query(p<<1|1,m+1,r,ql,qr));
    }
};
long long pack_project_x_p0_p1_pack_segment_tree_03(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_03 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}
