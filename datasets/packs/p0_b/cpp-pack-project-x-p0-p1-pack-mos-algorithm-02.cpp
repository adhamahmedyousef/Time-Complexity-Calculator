#include <bits/stdc++.h>
using namespace std;


// mos-algorithm-01
long long mos_algorithm_01(const vector<int>& a, const vector<pair<int,int>>& qs) { long long ans=0; for (auto [l,r]:qs) ans += (r-l+1); return ans; }

// mos-algorithm-02
long long pack_project_x_p0_p1_pack_mos_algorithm_02(const vector<int>& a, const vector<pair<int,int>>& qs) { long long ans=0; for (auto [l,r]:qs) ans += (r-l+1); return ans; }
