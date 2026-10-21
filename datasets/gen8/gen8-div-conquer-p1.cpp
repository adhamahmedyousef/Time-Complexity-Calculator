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


void g8_mergeSortVec_0(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_0(left); g8_mergeSortVec_0(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_0(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_0(left); g8_mergeSortInplace_0(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_0(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_0(left); g8_mergeSortDeque_0(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_0(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_0(mid); g8_splitLinear_0(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_0(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_0(mid); g8_splitConst_0(mid); }

int g8_halvingTail_0(int n) { if (n <= 1) return n; return g8_halvingTail_0(n / 2) + 1; }

int g8_halvingTail3_0(int n) { if (n <= 1) return n; return g8_halvingTail3_0(n / 3) + 2; }

int g8_midSearch_0(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_0(low, mid); return g8_midSearch_0(mid + 1, high); }

void g8_mergeSortVec_1(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_1(left); g8_mergeSortVec_1(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_1(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_1(left); g8_mergeSortInplace_1(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_1(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_1(left); g8_mergeSortDeque_1(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_1(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_1(mid); g8_splitLinear_1(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_1(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_1(mid); g8_splitConst_1(mid); }

int g8_halvingTail_1(int n) { if (n <= 1) return n; return g8_halvingTail_1(n / 2) + 1; }

int g8_halvingTail3_1(int n) { if (n <= 1) return n; return g8_halvingTail3_1(n / 3) + 2; }

int g8_midSearch_1(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_1(low, mid); return g8_midSearch_1(mid + 1, high); }

void g8_mergeSortVec_2(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_2(left); g8_mergeSortVec_2(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_2(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_2(left); g8_mergeSortInplace_2(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_2(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_2(left); g8_mergeSortDeque_2(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_2(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_2(mid); g8_splitLinear_2(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_2(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_2(mid); g8_splitConst_2(mid); }

int g8_halvingTail_2(int n) { if (n <= 1) return n; return g8_halvingTail_2(n / 2) + 1; }

int g8_halvingTail3_2(int n) { if (n <= 1) return n; return g8_halvingTail3_2(n / 3) + 2; }

int g8_midSearch_2(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_2(low, mid); return g8_midSearch_2(mid + 1, high); }

void g8_mergeSortVec_3(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_3(left); g8_mergeSortVec_3(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_3(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_3(left); g8_mergeSortInplace_3(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_3(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_3(left); g8_mergeSortDeque_3(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_3(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_3(mid); g8_splitLinear_3(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_3(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_3(mid); g8_splitConst_3(mid); }

int g8_halvingTail_3(int n) { if (n <= 1) return n; return g8_halvingTail_3(n / 2) + 1; }

int g8_halvingTail3_3(int n) { if (n <= 1) return n; return g8_halvingTail3_3(n / 3) + 2; }

int g8_midSearch_3(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_3(low, mid); return g8_midSearch_3(mid + 1, high); }

void g8_mergeSortVec_4(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortVec_4(left); g8_mergeSortVec_4(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_mergeSortInplace_4(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortInplace_4(left); g8_mergeSortInplace_4(right); inplace_merge(left.begin(), left.end(), right.end()); }

void g8_mergeSortDeque_4(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); g8_mergeSortDeque_4(left); g8_mergeSortDeque_4(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void g8_splitLinear_4(int n) { if (n <= 1) return; int mid = n / 2; g8_splitLinear_4(mid); g8_splitLinear_4(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void g8_splitConst_4(int n) { if (n <= 1) return; int mid = n / 2; g8_splitConst_4(mid); g8_splitConst_4(mid); }

int g8_halvingTail_4(int n) { if (n <= 1) return n; return g8_halvingTail_4(n / 2) + 1; }

int g8_halvingTail3_4(int n) { if (n <= 1) return n; return g8_halvingTail3_4(n / 3) + 2; }

int g8_midSearch_4(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return g8_midSearch_4(low, mid); return g8_midSearch_4(mid + 1, high); }
