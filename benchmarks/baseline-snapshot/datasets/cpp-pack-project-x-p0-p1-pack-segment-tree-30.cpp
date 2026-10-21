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
long long segment_tree_03(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_03 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-04
struct Seg_04 {
    int n; vector<long long> t;
    Seg_04(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_04(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_04 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-05
struct Seg_05 {
    int n; vector<long long> t;
    Seg_05(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_05(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_05 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-06
struct Seg_06 {
    int n; vector<long long> t;
    Seg_06(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_06(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_06 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-07
struct Seg_07 {
    int n; vector<long long> t;
    Seg_07(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_07(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_07 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-08
struct Seg_08 {
    int n; vector<long long> t;
    Seg_08(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_08(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_08 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-09
struct Seg_09 {
    int n; vector<long long> t;
    Seg_09(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_09(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_09 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-10
struct Seg_10 {
    int n; vector<long long> t;
    Seg_10(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_10(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_10 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-11
struct Seg_11 {
    int n; vector<long long> t;
    Seg_11(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_11(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_11 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-12
struct Seg_12 {
    int n; vector<long long> t;
    Seg_12(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_12(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_12 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-13
struct Seg_13 {
    int n; vector<long long> t;
    Seg_13(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_13(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_13 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-14
struct Seg_14 {
    int n; vector<long long> t;
    Seg_14(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_14(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_14 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-15
struct Seg_15 {
    int n; vector<long long> t;
    Seg_15(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_15(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_15 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-16
struct Seg_16 {
    int n; vector<long long> t;
    Seg_16(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_16(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_16 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-17
struct Seg_17 {
    int n; vector<long long> t;
    Seg_17(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_17(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_17 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-18
struct Seg_18 {
    int n; vector<long long> t;
    Seg_18(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_18(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_18 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-19
struct Seg_19 {
    int n; vector<long long> t;
    Seg_19(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_19(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_19 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-20
struct Seg_20 {
    int n; vector<long long> t;
    Seg_20(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_20(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_20 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-21
struct Seg_21 {
    int n; vector<long long> t;
    Seg_21(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_21(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_21 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-22
struct Seg_22 {
    int n; vector<long long> t;
    Seg_22(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_22(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_22 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-23
struct Seg_23 {
    int n; vector<long long> t;
    Seg_23(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_23(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_23 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-24
struct Seg_24 {
    int n; vector<long long> t;
    Seg_24(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_24(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_24 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-25
struct Seg_25 {
    int n; vector<long long> t;
    Seg_25(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_25(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_25 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-26
struct Seg_26 {
    int n; vector<long long> t;
    Seg_26(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_26(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_26 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-27
struct Seg_27 {
    int n; vector<long long> t;
    Seg_27(const vector<int>& a): n((int)a.size()), t(4*max(1,(int)a.size()), 0) {
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
long long segment_tree_27(const vector<int>& a, const vector<pair<int,int>>& qs) {
    Seg_27 st(a); long long ans=0; for (auto [l,r]:qs) ans += st.query(1,0,(int)a.size()-1,l,r); return ans;
}

// segment-tree-28
static long long build_pref_28(const vector<int>& a) {
    vector<long long> pref(a.size()+1); for (size_t i=0;i<a.size();++i) pref[i+1]=pref[i]+a[i]; return pref.back();
}
long long segment_tree_28(const vector<int>& a, const vector<pair<int,int>>& qs) {
    auto x = build_pref_28(a);
    long long ans=0; for (auto [l,r]:qs) ans += (r-l+1) + x; return ans;
}

// segment-tree-29
static long long build_pref_29(const vector<int>& a) {
    vector<long long> pref(a.size()+1); for (size_t i=0;i<a.size();++i) pref[i+1]=pref[i]+a[i]; return pref.back();
}
long long segment_tree_29(const vector<int>& a, const vector<pair<int,int>>& qs) {
    auto x = build_pref_29(a);
    long long ans=0; for (auto [l,r]:qs) ans += (r-l+1) + x; return ans;
}

// segment-tree-30
static long long build_pref_30(const vector<int>& a) {
    vector<long long> pref(a.size()+1); for (size_t i=0;i<a.size();++i) pref[i+1]=pref[i]+a[i]; return pref.back();
}
long long pack_project_x_p0_p1_pack_segment_tree_30(const vector<int>& a, const vector<pair<int,int>>& qs) {
    auto x = build_pref_30(a);
    long long ans=0; for (auto [l,r]:qs) ans += (r-l+1) + x; return ans;
}
