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


vector<int> g8_nextGreater_35(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_35(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_35(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_35(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_35(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_35(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_35(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_35(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_36(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_36(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_36(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_36(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_36(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_36(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_36(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_36(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_37(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_37(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_37(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_37(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_37(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_37(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_37(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_37(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_38(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_38(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_38(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_38(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_38(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_38(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_38(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_38(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_39(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_39(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_39(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_39(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_39(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_39(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_39(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_39(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }
