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


int eulerTotientPhi_18(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_18(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_19(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_19(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_19(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_19(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_19(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_19(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_19(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_19(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_20(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_20(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_20(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_20(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_20(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_20(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_20(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_20(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_21(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_21(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_21(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_21(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_21(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_21(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_21(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_21(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_22(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_22(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_22(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_22(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_22(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_22(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_22(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_22(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_23(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_23(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_23(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_23(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_23(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_23(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_23(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_23(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }

vector<int> monotonicStackNextGreater_24(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && a[i] > a[st.top()]) { res[st.top()] = a[i]; st.pop(); } st.push(i); } return res; }

vector<int> monotonicStackPrevGreater_24(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> res(n, -1); stack<int> st; for (int i = 0; i < n; ++i) { while (!st.empty() && st.top() <= a[i]) st.pop(); if (!st.empty()) res[i] = st.top(); st.push(a[i]); } return res; }

int monotonicQueueDrain_24(const vector<int>& a) { queue<int> q; for (int x : a) q.push(x); int sum = 0; while (!q.empty()) { sum += q.front(); q.pop(); } return sum; }

vector<int> priorityQueueSort_24(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); vector<int> res; while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); } return res; }

bool twoPointerConvergeSorted_24(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left < right) { int cur = a[left] + a[right]; if (cur == target) return true; if (cur < target) ++left; else --right; } return false; }

int twoPointerPartition_24(vector<int>& a) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { if (a[left] % 2 == 0) ++left; else if (a[right] % 2 != 0) --right; else { swap(a[left], a[right]); ++left; --right; } } return left; }

int eulerTotientPhi_24(int n) { int res = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }

vector<int> primeFactorizationAmort_24(int n) { vector<int> fac; for (int i = 2; i * i <= n; ++i) { while (n % i == 0) { fac.push_back(i); n /= i; } } if (n > 1) fac.push_back(n); return fac; }
