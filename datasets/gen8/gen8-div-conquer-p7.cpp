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


void g8_mergeSortVec_30(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_30(left); g8_mergeSortVec_30(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_30(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_30(left); g8_mergeSortInplace_30(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_30(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_30(left); g8_mergeSortDeque_30(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_30(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_30(mid); g8_splitLinear_30(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_30(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_30(mid); g8_splitConst_30(mid); }

int g8_halvingTail_30(int n) { if (n <= 1) return n; return g8_halvingTail_30(n / 2) + 1; }

int g8_halvingTail3_30(int n) { if (n <= 1) return n; return g8_halvingTail3_30(n / 3) + 2; }

int g8_midSearch_30(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_30(low, mid); return g8_midSearch_30(mid + 1, high); }

void g8_mergeSortVec_31(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_31(left); g8_mergeSortVec_31(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_31(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_31(left); g8_mergeSortInplace_31(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_31(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_31(left); g8_mergeSortDeque_31(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_31(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_31(mid); g8_splitLinear_31(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_31(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_31(mid); g8_splitConst_31(mid); }

int g8_halvingTail_31(int n) { if (n <= 1) return n; return g8_halvingTail_31(n / 2) + 1; }

int g8_halvingTail3_31(int n) { if (n <= 1) return n; return g8_halvingTail3_31(n / 3) + 2; }

int g8_midSearch_31(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_31(low, mid); return g8_midSearch_31(mid + 1, high); }

void g8_mergeSortVec_32(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_32(left); g8_mergeSortVec_32(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_32(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_32(left); g8_mergeSortInplace_32(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_32(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_32(left); g8_mergeSortDeque_32(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_32(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_32(mid); g8_splitLinear_32(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_32(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_32(mid); g8_splitConst_32(mid); }

int g8_halvingTail_32(int n) { if (n <= 1) return n; return g8_halvingTail_32(n / 2) + 1; }

int g8_halvingTail3_32(int n) { if (n <= 1) return n; return g8_halvingTail3_32(n / 3) + 2; }

int g8_midSearch_32(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_32(low, mid); return g8_midSearch_32(mid + 1, high); }

void g8_mergeSortVec_33(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_33(left); g8_mergeSortVec_33(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_33(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_33(left); g8_mergeSortInplace_33(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_33(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_33(left); g8_mergeSortDeque_33(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_33(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_33(mid); g8_splitLinear_33(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_33(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_33(mid); g8_splitConst_33(mid); }

int g8_halvingTail_33(int n) { if (n <= 1) return n; return g8_halvingTail_33(n / 2) + 1; }

int g8_halvingTail3_33(int n) { if (n <= 1) return n; return g8_halvingTail3_33(n / 3) + 2; }

int g8_midSearch_33(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_33(low, mid); return g8_midSearch_33(mid + 1, high); }

void g8_mergeSortVec_34(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_34(left); g8_mergeSortVec_34(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_34(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_34(left); g8_mergeSortInplace_34(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_34(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_34(left); g8_mergeSortDeque_34(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_34(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_34(mid); g8_splitLinear_34(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_34(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_34(mid); g8_splitConst_34(mid); }

int g8_halvingTail_34(int n) { if (n <= 1) return n; return g8_halvingTail_34(n / 2) + 1; }

int g8_halvingTail3_34(int n) { if (n <= 1) return n; return g8_halvingTail3_34(n / 3) + 2; }

int g8_midSearch_34(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_34(low, mid); return g8_midSearch_34(mid + 1, high); }
