#include <bits/stdc++.h>
using namespace std;


// sqrt-decomposition-01
long long sqrt_decomposition_01(const vector<int>& a, const vector<pair<int,int>>& qs) { long long ans=0; for (auto [l,r]:qs) ans += (r-l+1); return ans; }

// sqrt-decomposition-02
long long sqrt_decomposition_02(const vector<int>& a, const vector<pair<int,int>>& qs) { long long ans=0; for (auto [l,r]:qs) ans += (r-l+1); return ans; }

// sqrt-decomposition-03
long long pack_project_x_p0_p1_pack_sqrt_decomposition_03(const vector<int>& a, const vector<pair<int,int>>& qs) { long long ans=0; for (auto [l,r]:qs) ans += (r-l+1); return ans; }
