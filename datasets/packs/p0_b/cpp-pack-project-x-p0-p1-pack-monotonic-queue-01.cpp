#include <bits/stdc++.h>
using namespace std;


// monotonic-queue-01
long long pack_project_x_p0_p1_pack_monotonic_queue_01(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }
