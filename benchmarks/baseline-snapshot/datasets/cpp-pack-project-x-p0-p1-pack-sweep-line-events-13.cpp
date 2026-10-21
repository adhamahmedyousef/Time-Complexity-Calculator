#include <bits/stdc++.h>
using namespace std;


// sweep-line-events-01
long long sweep_line_events_01(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-02
long long sweep_line_events_02(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-03
long long sweep_line_events_03(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-04
long long sweep_line_events_04(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-05
long long sweep_line_events_05(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-06
long long sweep_line_events_06(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-07
long long sweep_line_events_07(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-08
long long sweep_line_events_08(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-09
long long sweep_line_events_09(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-10
long long sweep_line_events_10(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-11
long long sweep_line_events_11(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-12
long long sweep_line_events_12(vector<pair<int,int>> ev) { sort(ev.begin(), ev.end()); long long cur=0, ans=0; for (auto [x,t]:ev) { cur += t; ans = max(ans, cur); } return ans; }

// sweep-line-events-13
long long pack_project_x_p0_p1_pack_sweep_line_events_13(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
