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


vector<int> g8_nextGreater_30(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_30(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_30(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_30(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_30(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_30(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_30(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_30(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_31(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_31(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_31(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_31(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_31(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_31(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_31(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_31(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_32(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_32(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_32(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_32(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_32(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_32(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_32(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_32(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_33(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_33(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_33(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_33(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_33(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_33(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_33(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_33(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_34(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_34(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_34(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_34(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_34(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_34(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_34(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_34(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }
