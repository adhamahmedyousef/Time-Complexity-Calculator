#include <bits/stdc++.h>
using namespace std;


// sparse-table-01
int pack_project_x_p0_p1_pack_sparse_table_01(const vector<int>& a, const vector<pair<int,int>>& qs) {
    int n=(int)a.size(), K=1; while ((1<<K)<=n) ++K;
    vector<vector<int>> st(K, vector<int>(n)); if (n) st[0]=a;
    for (int k=1;k<K;++k) for (int i=0;i+(1<<k)<=n;++i) st[k][i]=min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
    int ans=0; for (auto [l,r]:qs) { int len=r-l+1, k=31-__builtin_clz(len); ans += min(st[k][l], st[k][r-(1<<k)+1]); } return ans;
}
