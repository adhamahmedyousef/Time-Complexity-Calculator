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


void g8_mergeSortVec_15(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_15(left); g8_mergeSortVec_15(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_15(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_15(left); g8_mergeSortInplace_15(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_15(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_15(left); g8_mergeSortDeque_15(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_15(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_15(mid); g8_splitLinear_15(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_15(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_15(mid); g8_splitConst_15(mid); }

int g8_halvingTail_15(int n) { if (n <= 1) return n; return g8_halvingTail_15(n / 2) + 1; }

int g8_halvingTail3_15(int n) { if (n <= 1) return n; return g8_halvingTail3_15(n / 3) + 2; }

int g8_midSearch_15(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_15(low, mid); return g8_midSearch_15(mid + 1, high); }

void g8_mergeSortVec_16(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_16(left); g8_mergeSortVec_16(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_16(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_16(left); g8_mergeSortInplace_16(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_16(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_16(left); g8_mergeSortDeque_16(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_16(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_16(mid); g8_splitLinear_16(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_16(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_16(mid); g8_splitConst_16(mid); }

int g8_halvingTail_16(int n) { if (n <= 1) return n; return g8_halvingTail_16(n / 2) + 1; }

int g8_halvingTail3_16(int n) { if (n <= 1) return n; return g8_halvingTail3_16(n / 3) + 2; }

int g8_midSearch_16(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_16(low, mid); return g8_midSearch_16(mid + 1, high); }

void g8_mergeSortVec_17(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_17(left); g8_mergeSortVec_17(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_17(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_17(left); g8_mergeSortInplace_17(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_17(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_17(left); g8_mergeSortDeque_17(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_17(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_17(mid); g8_splitLinear_17(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_17(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_17(mid); g8_splitConst_17(mid); }

int g8_halvingTail_17(int n) { if (n <= 1) return n; return g8_halvingTail_17(n / 2) + 1; }

int g8_halvingTail3_17(int n) { if (n <= 1) return n; return g8_halvingTail3_17(n / 3) + 2; }

int g8_midSearch_17(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_17(low, mid); return g8_midSearch_17(mid + 1, high); }

void g8_mergeSortVec_18(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_18(left); g8_mergeSortVec_18(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_18(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_18(left); g8_mergeSortInplace_18(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_18(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_18(left); g8_mergeSortDeque_18(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_18(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_18(mid); g8_splitLinear_18(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_18(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_18(mid); g8_splitConst_18(mid); }

int g8_halvingTail_18(int n) { if (n <= 1) return n; return g8_halvingTail_18(n / 2) + 1; }

int g8_halvingTail3_18(int n) { if (n <= 1) return n; return g8_halvingTail3_18(n / 3) + 2; }

int g8_midSearch_18(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_18(low, mid); return g8_midSearch_18(mid + 1, high); }

void g8_mergeSortVec_19(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_19(left); g8_mergeSortVec_19(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_19(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_19(left); g8_mergeSortInplace_19(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_19(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_19(left); g8_mergeSortDeque_19(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_19(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_19(mid); g8_splitLinear_19(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_19(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_19(mid); g8_splitConst_19(mid); }

int g8_halvingTail_19(int n) { if (n <= 1) return n; return g8_halvingTail_19(n / 2) + 1; }

int g8_halvingTail3_19(int n) { if (n <= 1) return n; return g8_halvingTail3_19(n / 3) + 2; }

int g8_midSearch_19(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_19(low, mid); return g8_midSearch_19(mid + 1, high); }
