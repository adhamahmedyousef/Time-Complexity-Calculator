#include <bits/stdc++.h>
using namespace std;


// monotonic-queue-01
long long monotonic_queue_01(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-02
long long monotonic_queue_02(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-03
long long monotonic_queue_03(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-04
long long pack_project_x_p0_p1_pack_monotonic_queue_04(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }
