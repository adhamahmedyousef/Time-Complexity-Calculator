#include <bits/stdc++.h>
using namespace std;


// ordered-set-pbds-01
long long pack_project_x_p0_p1_pack_ordered_set_pbds_01(const vector<int>& a) { set<int> s; for (int x:a) s.insert(x); return (long long)s.size(); }
