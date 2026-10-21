#include <bits/stdc++.h>
using namespace std;


// sparse-table-01
int sparse_table_01(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-02
int sparse_table_02(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-03
int sparse_table_03(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-04
int sparse_table_04(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-05
int sparse_table_05(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-06
int sparse_table_06(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-07
int sparse_table_07(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-08
int sparse_table_08(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-09
int sparse_table_09(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-10
int sparse_table_10(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-11
int sparse_table_11(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}

// sparse-table-12
int pack_project_x_p0_p1_pack_sparse_table_12(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}
