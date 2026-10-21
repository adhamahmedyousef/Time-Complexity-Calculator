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


void g8_mergeSortVec_20(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_20(left); g8_mergeSortVec_20(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_20(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_20(left); g8_mergeSortInplace_20(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_20(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_20(left); g8_mergeSortDeque_20(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_20(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_20(mid); g8_splitLinear_20(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_20(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_20(mid); g8_splitConst_20(mid); }

int g8_halvingTail_20(int n) { if (n <= 1) return n; return g8_halvingTail_20(n / 2) + 1; }

int g8_halvingTail3_20(int n) { if (n <= 1) return n; return g8_halvingTail3_20(n / 3) + 2; }

int g8_midSearch_20(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_20(low, mid); return g8_midSearch_20(mid + 1, high); }

void g8_mergeSortVec_21(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_21(left); g8_mergeSortVec_21(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_21(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_21(left); g8_mergeSortInplace_21(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_21(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_21(left); g8_mergeSortDeque_21(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_21(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_21(mid); g8_splitLinear_21(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_21(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_21(mid); g8_splitConst_21(mid); }

int g8_halvingTail_21(int n) { if (n <= 1) return n; return g8_halvingTail_21(n / 2) + 1; }

int g8_halvingTail3_21(int n) { if (n <= 1) return n; return g8_halvingTail3_21(n / 3) + 2; }

int g8_midSearch_21(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_21(low, mid); return g8_midSearch_21(mid + 1, high); }

void g8_mergeSortVec_22(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_22(left); g8_mergeSortVec_22(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_22(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_22(left); g8_mergeSortInplace_22(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_22(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_22(left); g8_mergeSortDeque_22(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_22(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_22(mid); g8_splitLinear_22(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_22(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_22(mid); g8_splitConst_22(mid); }

int g8_halvingTail_22(int n) { if (n <= 1) return n; return g8_halvingTail_22(n / 2) + 1; }

int g8_halvingTail3_22(int n) { if (n <= 1) return n; return g8_halvingTail3_22(n / 3) + 2; }

int g8_midSearch_22(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_22(low, mid); return g8_midSearch_22(mid + 1, high); }

void g8_mergeSortVec_23(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_23(left); g8_mergeSortVec_23(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_23(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_23(left); g8_mergeSortInplace_23(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_23(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_23(left); g8_mergeSortDeque_23(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_23(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_23(mid); g8_splitLinear_23(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_23(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_23(mid); g8_splitConst_23(mid); }

int g8_halvingTail_23(int n) { if (n <= 1) return n; return g8_halvingTail_23(n / 2) + 1; }

int g8_halvingTail3_23(int n) { if (n <= 1) return n; return g8_halvingTail3_23(n / 3) + 2; }

int g8_midSearch_23(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_23(low, mid); return g8_midSearch_23(mid + 1, high); }

void g8_mergeSortVec_24(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_24(left); g8_mergeSortVec_24(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_24(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_24(left); g8_mergeSortInplace_24(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_24(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_24(left); g8_mergeSortDeque_24(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_24(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_24(mid); g8_splitLinear_24(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_24(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_24(mid); g8_splitConst_24(mid); }

int g8_halvingTail_24(int n) { if (n <= 1) return n; return g8_halvingTail_24(n / 2) + 1; }

int g8_halvingTail3_24(int n) { if (n <= 1) return n; return g8_halvingTail3_24(n / 3) + 2; }

int g8_midSearch_24(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_24(low, mid); return g8_midSearch_24(mid + 1, high); }
