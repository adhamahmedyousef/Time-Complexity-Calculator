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


void g8_mergeSortVec_5(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_5(left); g8_mergeSortVec_5(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_5(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_5(left); g8_mergeSortInplace_5(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_5(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_5(left); g8_mergeSortDeque_5(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_5(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_5(mid); g8_splitLinear_5(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_5(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_5(mid); g8_splitConst_5(mid); }

int g8_halvingTail_5(int n) { if (n <= 1) return n; return g8_halvingTail_5(n / 2) + 1; }

int g8_halvingTail3_5(int n) { if (n <= 1) return n; return g8_halvingTail3_5(n / 3) + 2; }

int g8_midSearch_5(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_5(low, mid); return g8_midSearch_5(mid + 1, high); }

void g8_mergeSortVec_6(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_6(left); g8_mergeSortVec_6(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_6(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_6(left); g8_mergeSortInplace_6(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_6(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_6(left); g8_mergeSortDeque_6(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_6(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_6(mid); g8_splitLinear_6(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_6(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_6(mid); g8_splitConst_6(mid); }

int g8_halvingTail_6(int n) { if (n <= 1) return n; return g8_halvingTail_6(n / 2) + 1; }

int g8_halvingTail3_6(int n) { if (n <= 1) return n; return g8_halvingTail3_6(n / 3) + 2; }

int g8_midSearch_6(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_6(low, mid); return g8_midSearch_6(mid + 1, high); }

void g8_mergeSortVec_7(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_7(left); g8_mergeSortVec_7(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_7(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_7(left); g8_mergeSortInplace_7(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_7(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_7(left); g8_mergeSortDeque_7(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_7(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_7(mid); g8_splitLinear_7(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_7(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_7(mid); g8_splitConst_7(mid); }

int g8_halvingTail_7(int n) { if (n <= 1) return n; return g8_halvingTail_7(n / 2) + 1; }

int g8_halvingTail3_7(int n) { if (n <= 1) return n; return g8_halvingTail3_7(n / 3) + 2; }

int g8_midSearch_7(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_7(low, mid); return g8_midSearch_7(mid + 1, high); }

void g8_mergeSortVec_8(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_8(left); g8_mergeSortVec_8(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_8(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_8(left); g8_mergeSortInplace_8(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_8(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_8(left); g8_mergeSortDeque_8(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_8(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_8(mid); g8_splitLinear_8(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_8(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_8(mid); g8_splitConst_8(mid); }

int g8_halvingTail_8(int n) { if (n <= 1) return n; return g8_halvingTail_8(n / 2) + 1; }

int g8_halvingTail3_8(int n) { if (n <= 1) return n; return g8_halvingTail3_8(n / 3) + 2; }

int g8_midSearch_8(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_8(low, mid); return g8_midSearch_8(mid + 1, high); }

void g8_mergeSortVec_9(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_9(left); g8_mergeSortVec_9(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_9(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_9(left); g8_mergeSortInplace_9(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_9(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_9(left); g8_mergeSortDeque_9(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_9(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_9(mid); g8_splitLinear_9(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_9(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_9(mid); g8_splitConst_9(mid); }

int g8_halvingTail_9(int n) { if (n <= 1) return n; return g8_halvingTail_9(n / 2) + 1; }

int g8_halvingTail3_9(int n) { if (n <= 1) return n; return g8_halvingTail3_9(n / 3) + 2; }

int g8_midSearch_9(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_9(low, mid); return g8_midSearch_9(mid + 1, high); }
