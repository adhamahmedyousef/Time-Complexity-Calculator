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


void g8_mergeSortVec_10(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_10(left); g8_mergeSortVec_10(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_10(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_10(left); g8_mergeSortInplace_10(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_10(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_10(left); g8_mergeSortDeque_10(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_10(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_10(mid); g8_splitLinear_10(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_10(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_10(mid); g8_splitConst_10(mid); }

int g8_halvingTail_10(int n) { if (n <= 1) return n; return g8_halvingTail_10(n / 2) + 1; }

int g8_halvingTail3_10(int n) { if (n <= 1) return n; return g8_halvingTail3_10(n / 3) + 2; }

int g8_midSearch_10(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_10(low, mid); return g8_midSearch_10(mid + 1, high); }

void g8_mergeSortVec_11(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_11(left); g8_mergeSortVec_11(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_11(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_11(left); g8_mergeSortInplace_11(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_11(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_11(left); g8_mergeSortDeque_11(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_11(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_11(mid); g8_splitLinear_11(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_11(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_11(mid); g8_splitConst_11(mid); }

int g8_halvingTail_11(int n) { if (n <= 1) return n; return g8_halvingTail_11(n / 2) + 1; }

int g8_halvingTail3_11(int n) { if (n <= 1) return n; return g8_halvingTail3_11(n / 3) + 2; }

int g8_midSearch_11(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_11(low, mid); return g8_midSearch_11(mid + 1, high); }

void g8_mergeSortVec_12(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_12(left); g8_mergeSortVec_12(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_12(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_12(left); g8_mergeSortInplace_12(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_12(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_12(left); g8_mergeSortDeque_12(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_12(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_12(mid); g8_splitLinear_12(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_12(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_12(mid); g8_splitConst_12(mid); }

int g8_halvingTail_12(int n) { if (n <= 1) return n; return g8_halvingTail_12(n / 2) + 1; }

int g8_halvingTail3_12(int n) { if (n <= 1) return n; return g8_halvingTail3_12(n / 3) + 2; }

int g8_midSearch_12(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_12(low, mid); return g8_midSearch_12(mid + 1, high); }

void g8_mergeSortVec_13(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_13(left); g8_mergeSortVec_13(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_13(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_13(left); g8_mergeSortInplace_13(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_13(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_13(left); g8_mergeSortDeque_13(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_13(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_13(mid); g8_splitLinear_13(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_13(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_13(mid); g8_splitConst_13(mid); }

int g8_halvingTail_13(int n) { if (n <= 1) return n; return g8_halvingTail_13(n / 2) + 1; }

int g8_halvingTail3_13(int n) { if (n <= 1) return n; return g8_halvingTail3_13(n / 3) + 2; }

int g8_midSearch_13(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_13(low, mid); return g8_midSearch_13(mid + 1, high); }

void g8_mergeSortVec_14(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_14(left); g8_mergeSortVec_14(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_14(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_14(left); g8_mergeSortInplace_14(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_14(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_14(left); g8_mergeSortDeque_14(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_14(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_14(mid); g8_splitLinear_14(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_14(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_14(mid); g8_splitConst_14(mid); }

int g8_halvingTail_14(int n) { if (n <= 1) return n; return g8_halvingTail_14(n / 2) + 1; }

int g8_halvingTail3_14(int n) { if (n <= 1) return n; return g8_halvingTail3_14(n / 3) + 2; }

int g8_midSearch_14(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_14(low, mid); return g8_midSearch_14(mid + 1, high); }
