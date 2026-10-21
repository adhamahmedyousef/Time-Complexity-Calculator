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


vector<int> g8_nextGreater_0(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_0(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_0(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_0(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_0(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_0(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_0(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_0(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_1(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_1(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_1(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_1(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_1(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_1(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_1(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_1(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_2(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_2(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_2(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_2(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_2(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_2(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_2(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_2(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_3(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_3(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_3(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_3(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_3(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_3(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_3(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_3(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }

vector<int> g8_nextGreater_4(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && a[st.top()] < a[i]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> g8_prevGreater_4(const vector<int>& a) { vector<int> res(a.size(), -1); stack<int> st; for (int i = 0; i < static_cast<int>(a.size()); ++i) { while (!st.empty() && st.top() <= a[i]) { st.pop(); } if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int g8_stackDrain_4(int n) { stack<int> s; for (int i = 0; i < n; ++i) s.push(i); int sum = 0; while (!s.empty()) { sum += s.top(); s.pop(); } return sum; }

int g8_queueDrain_4(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int total = 0; while (!q.empty()) { total += q.front(); q.pop(); } return total; }

void g8_pqueueDrain_4(int n) { priority_queue<int> pq; for (int i = 0; i < n; ++i) pq.push(i); while (!pq.empty()) { pq.pop(); } }

void g8_dequePop_4(int n) { deque<int> dq; for (int i = 0; i < n; ++i) dq.push_back(i); while (!dq.empty()) dq.pop_front(); }

int g8_stackWipe_4(const vector<int>& a) { stack<int> st; for (int x : a) { while (!st.empty() && st.top() < x) st.pop(); st.push(x); } return st.size(); }

void g8_monoVec_4(const vector<int>& a) { vector<int> st; for (int x : a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); } }
