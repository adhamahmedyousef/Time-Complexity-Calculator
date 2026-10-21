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


bool twoPointerConvergeSorted_12(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_12(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_12(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_12(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_13(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_13(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_13(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_13(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_13(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_13(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_13(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_13(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_14(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_14(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_14(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_14(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_14(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_14(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_14(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_14(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_15(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_15(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_15(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_15(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_15(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_15(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_15(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_15(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_16(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_16(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_16(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_16(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_16(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_16(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_16(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_16(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_17(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_17(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_17(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_17(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_17(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_17(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_17(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_17(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_18(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_18(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_18(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_18(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_18(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_18(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }
