#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


vector<int> monotonicStackNextGreater_0(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_0(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_0(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_0(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_0(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_0(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_0(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_0(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_1(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_1(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_1(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_1(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_1(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_1(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_1(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_1(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_2(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_2(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_2(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_2(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_2(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_2(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_2(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_2(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_3(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_3(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_3(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_3(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_3(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_3(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_3(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_3(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_4(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_4(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_4(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_4(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_4(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_4(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_4(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_4(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_5(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_5(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_5(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_5(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_5(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_5(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_5(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_5(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_6(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_6(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }
