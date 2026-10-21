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


vector<int> g8_nextGreater_5(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_5(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_5(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_5(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_5(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_5(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_5(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_5(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_6(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_6(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_6(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_6(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_6(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_6(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_6(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_6(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_7(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_7(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_7(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_7(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_7(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_7(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_7(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_7(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_8(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_8(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_8(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_8(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_8(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_8(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_8(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_8(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_9(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_9(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_9(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_9(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_9(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_9(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_9(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_9(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }
