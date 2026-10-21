#include <bits/stdc++.h>
using namespace std;


// sweep-line-events-01
long long pack_project_x_p0_p1_pack_sweep_line_events_01(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }
