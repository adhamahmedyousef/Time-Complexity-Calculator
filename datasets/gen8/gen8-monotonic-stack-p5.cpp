#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


vector<int> g8_nextGreater_20(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_20(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_20(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_20(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_20(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_20(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_20(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_20(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_21(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_21(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_21(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_21(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_21(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_21(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_21(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_21(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_22(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_22(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_22(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_22(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_22(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_22(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_22(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_22(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_23(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_23(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_23(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_23(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_23(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_23(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_23(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_23(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_24(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_24(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_24(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_24(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_24(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_24(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_24(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_24(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }
