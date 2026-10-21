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


void g8_mergeSortVec_35(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_35(left); g8_mergeSortVec_35(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_35(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_35(left); g8_mergeSortInplace_35(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_35(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_35(left); g8_mergeSortDeque_35(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_35(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_35(mid); g8_splitLinear_35(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_35(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_35(mid); g8_splitConst_35(mid); }

int g8_halvingTail_35(int n) { if (n <= 1) return n; return g8_halvingTail_35(n / 2) + 1; }

int g8_halvingTail3_35(int n) { if (n <= 1) return n; return g8_halvingTail3_35(n / 3) + 2; }

int g8_midSearch_35(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_35(low, mid); return g8_midSearch_35(mid + 1, high); }

void g8_mergeSortVec_36(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_36(left); g8_mergeSortVec_36(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_36(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_36(left); g8_mergeSortInplace_36(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_36(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_36(left); g8_mergeSortDeque_36(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_36(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_36(mid); g8_splitLinear_36(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_36(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_36(mid); g8_splitConst_36(mid); }

int g8_halvingTail_36(int n) { if (n <= 1) return n; return g8_halvingTail_36(n / 2) + 1; }

int g8_halvingTail3_36(int n) { if (n <= 1) return n; return g8_halvingTail3_36(n / 3) + 2; }

int g8_midSearch_36(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_36(low, mid); return g8_midSearch_36(mid + 1, high); }

void g8_mergeSortVec_37(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_37(left); g8_mergeSortVec_37(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_37(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_37(left); g8_mergeSortInplace_37(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_37(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_37(left); g8_mergeSortDeque_37(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_37(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_37(mid); g8_splitLinear_37(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_37(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_37(mid); g8_splitConst_37(mid); }

int g8_halvingTail_37(int n) { if (n <= 1) return n; return g8_halvingTail_37(n / 2) + 1; }

int g8_halvingTail3_37(int n) { if (n <= 1) return n; return g8_halvingTail3_37(n / 3) + 2; }

int g8_midSearch_37(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_37(low, mid); return g8_midSearch_37(mid + 1, high); }

void g8_mergeSortVec_38(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_38(left); g8_mergeSortVec_38(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_38(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_38(left); g8_mergeSortInplace_38(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_38(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_38(left); g8_mergeSortDeque_38(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_38(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_38(mid); g8_splitLinear_38(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_38(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_38(mid); g8_splitConst_38(mid); }

int g8_halvingTail_38(int n) { if (n <= 1) return n; return g8_halvingTail_38(n / 2) + 1; }

int g8_halvingTail3_38(int n) { if (n <= 1) return n; return g8_halvingTail3_38(n / 3) + 2; }

int g8_midSearch_38(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_38(low, mid); return g8_midSearch_38(mid + 1, high); }

void g8_mergeSortVec_39(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_39(left); g8_mergeSortVec_39(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_39(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_39(left); g8_mergeSortInplace_39(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_39(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_39(left); g8_mergeSortDeque_39(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_39(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_39(mid); g8_splitLinear_39(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_39(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_39(mid); g8_splitConst_39(mid); }

int g8_halvingTail_39(int n) { if (n <= 1) return n; return g8_halvingTail_39(n / 2) + 1; }

int g8_halvingTail3_39(int n) { if (n <= 1) return n; return g8_halvingTail3_39(n / 3) + 2; }

int g8_midSearch_39(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_39(low, mid); return g8_midSearch_39(mid + 1, high); }
