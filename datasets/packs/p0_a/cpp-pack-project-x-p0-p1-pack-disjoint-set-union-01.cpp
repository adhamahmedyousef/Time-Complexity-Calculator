#include <bits/stdc++.h>
using namespace std;


// disjoint-set-union-01
struct D_01 { vector<int> p,r; D_01(int n):p(n),r(n){ iota(p.begin(),p.end(),0); } int f(int x){ return p[x]==x?x:p[x]=f(p[x]); } bool u(int a,int b){ a=f(a); b=f(b); if (a==b) return false; if (r[a]<r[b]) swap(a,b); p[b]=a; if (r[a]==r[b]) ++r[a]; return true; } };
long long pack_project_x_p0_p1_pack_disjoint_set_union_01(int n, const vector<pair<int,int>>& edges) { D_01 d(n); long long c=0; for (auto [u,v]:edges) c += d.u(u,v); return c; }
