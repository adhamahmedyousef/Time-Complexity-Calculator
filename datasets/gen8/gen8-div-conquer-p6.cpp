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


void g8_mergeSortVec_25(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_25(left); g8_mergeSortVec_25(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_25(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_25(left); g8_mergeSortInplace_25(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_25(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_25(left); g8_mergeSortDeque_25(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_25(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_25(mid); g8_splitLinear_25(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_25(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_25(mid); g8_splitConst_25(mid); }

int g8_halvingTail_25(int n) { if (n <= 1) return n; return g8_halvingTail_25(n / 2) + 1; }

int g8_halvingTail3_25(int n) { if (n <= 1) return n; return g8_halvingTail3_25(n / 3) + 2; }

int g8_midSearch_25(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_25(low, mid); return g8_midSearch_25(mid + 1, high); }

void g8_mergeSortVec_26(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_26(left); g8_mergeSortVec_26(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_26(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_26(left); g8_mergeSortInplace_26(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_26(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_26(left); g8_mergeSortDeque_26(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_26(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_26(mid); g8_splitLinear_26(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_26(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_26(mid); g8_splitConst_26(mid); }

int g8_halvingTail_26(int n) { if (n <= 1) return n; return g8_halvingTail_26(n / 2) + 1; }

int g8_halvingTail3_26(int n) { if (n <= 1) return n; return g8_halvingTail3_26(n / 3) + 2; }

int g8_midSearch_26(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_26(low, mid); return g8_midSearch_26(mid + 1, high); }

void g8_mergeSortVec_27(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_27(left); g8_mergeSortVec_27(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_27(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_27(left); g8_mergeSortInplace_27(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_27(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_27(left); g8_mergeSortDeque_27(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_27(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_27(mid); g8_splitLinear_27(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_27(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_27(mid); g8_splitConst_27(mid); }

int g8_halvingTail_27(int n) { if (n <= 1) return n; return g8_halvingTail_27(n / 2) + 1; }

int g8_halvingTail3_27(int n) { if (n <= 1) return n; return g8_halvingTail3_27(n / 3) + 2; }

int g8_midSearch_27(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_27(low, mid); return g8_midSearch_27(mid + 1, high); }

void g8_mergeSortVec_28(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_28(left); g8_mergeSortVec_28(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_28(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_28(left); g8_mergeSortInplace_28(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_28(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_28(left); g8_mergeSortDeque_28(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_28(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_28(mid); g8_splitLinear_28(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_28(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_28(mid); g8_splitConst_28(mid); }

int g8_halvingTail_28(int n) { if (n <= 1) return n; return g8_halvingTail_28(n / 2) + 1; }

int g8_halvingTail3_28(int n) { if (n <= 1) return n; return g8_halvingTail3_28(n / 3) + 2; }

int g8_midSearch_28(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_28(low, mid); return g8_midSearch_28(mid + 1, high); }

void g8_mergeSortVec_29(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_29(left); g8_mergeSortVec_29(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_29(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_29(left); g8_mergeSortInplace_29(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_29(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_29(left); g8_mergeSortDeque_29(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_29(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_29(mid); g8_splitLinear_29(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_29(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_29(mid); g8_splitConst_29(mid); }

int g8_halvingTail_29(int n) { if (n <= 1) return n; return g8_halvingTail_29(n / 2) + 1; }

int g8_halvingTail3_29(int n) { if (n <= 1) return n; return g8_halvingTail3_29(n / 3) + 2; }

int g8_midSearch_29(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_29(low, mid); return g8_midSearch_29(mid + 1, high); }
