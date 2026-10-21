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


int monotonicQueueDrain_31(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_31(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_31(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_31(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_31(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_31(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_32(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_32(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_32(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_32(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_32(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_32(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_32(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_32(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_33(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_33(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_33(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_33(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_33(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_33(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_33(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_33(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_34(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_34(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_34(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_34(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_34(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_34(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_34(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_34(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_35(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_35(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_35(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_35(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_35(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_35(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_35(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_35(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_36(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_36(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_36(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_36(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_36(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_36(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_36(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_36(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_37(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_37(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_37(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_37(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }
