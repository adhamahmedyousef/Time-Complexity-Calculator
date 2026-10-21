#include <bits/stdc++.h>
using namespace std;


// monotonic-queue-01
long long monotonic_queue_01(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-02
long long monotonic_queue_02(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-03
long long monotonic_queue_03(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-04
long long monotonic_queue_04(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-05
long long monotonic_queue_05(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-06
long long monotonic_queue_06(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-07
long long monotonic_queue_07(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-08
long long monotonic_queue_08(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-09
long long monotonic_queue_09(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-10
long long monotonic_queue_10(const vector<int>& a) { deque<int> dq; long long ans=0; for (int x:a) { while (!dq.empty() && dq.back() < x) dq.pop_back(); dq.push_back(x); ans += dq.front(); } return ans; }

// monotonic-queue-11
long long pack_project_x_p0_p1_pack_monotonic_queue_11(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
