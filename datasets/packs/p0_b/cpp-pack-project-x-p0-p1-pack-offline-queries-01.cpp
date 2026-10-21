#include <bits/stdc++.h>
using namespace std;


// offline-queries-01
long long pack_project_x_p0_p1_pack_offline_queries_01(const vector<int>& a, const vector<pair<int,int>>& qs) { vector<int> order; for (auto [l,r]:qs) order.push_back(r-l+1); return accumulate(order.begin(), order.end(), 0LL); }
