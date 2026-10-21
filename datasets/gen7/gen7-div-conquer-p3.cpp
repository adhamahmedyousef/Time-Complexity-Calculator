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


void mergeSortInplace_11(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_11(left); mergeSortInplace_11(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_11(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_11(left); mergeSortDeque_11(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_11(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_11(mid); splitCombineLinear_11(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_11(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_11(mid); splitConstantWork_11(mid); }

int halvingTailSearch_11(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_11(low, mid); return halvingTailSearch_11(mid + 1, high); }

int halvingTailConstStep_11(int n) { if (n <= 1) return n; return halvingTailConstStep_11(n / 2) + 1; }

int halvingTailStepThree_11(int n) { if (n <= 1) return n; return halvingTailStepThree_11(n / 3) + 2; }

int halvingTailStepFour_11(int n) { if (n <= 1) return n; return halvingTailStepFour_11(n / 4) + 1; }

void mergeSortVec_12(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_12(left); mergeSortVec_12(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_12(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_12(left); mergeSortInplace_12(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_12(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_12(left); mergeSortDeque_12(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_12(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_12(mid); splitCombineLinear_12(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_12(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_12(mid); splitConstantWork_12(mid); }

int halvingTailSearch_12(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_12(low, mid); return halvingTailSearch_12(mid + 1, high); }

int halvingTailConstStep_12(int n) { if (n <= 1) return n; return halvingTailConstStep_12(n / 2) + 1; }

int halvingTailStepThree_12(int n) { if (n <= 1) return n; return halvingTailStepThree_12(n / 3) + 2; }

int halvingTailStepFour_12(int n) { if (n <= 1) return n; return halvingTailStepFour_12(n / 4) + 1; }

void mergeSortVec_13(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_13(left); mergeSortVec_13(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_13(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_13(left); mergeSortInplace_13(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_13(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_13(left); mergeSortDeque_13(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_13(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_13(mid); splitCombineLinear_13(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_13(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_13(mid); splitConstantWork_13(mid); }

int halvingTailSearch_13(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_13(low, mid); return halvingTailSearch_13(mid + 1, high); }

int halvingTailConstStep_13(int n) { if (n <= 1) return n; return halvingTailConstStep_13(n / 2) + 1; }

int halvingTailStepThree_13(int n) { if (n <= 1) return n; return halvingTailStepThree_13(n / 3) + 2; }

int halvingTailStepFour_13(int n) { if (n <= 1) return n; return halvingTailStepFour_13(n / 4) + 1; }

void mergeSortVec_14(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_14(left); mergeSortVec_14(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_14(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_14(left); mergeSortInplace_14(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_14(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_14(left); mergeSortDeque_14(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_14(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_14(mid); splitCombineLinear_14(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_14(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_14(mid); splitConstantWork_14(mid); }

int halvingTailSearch_14(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_14(low, mid); return halvingTailSearch_14(mid + 1, high); }

int halvingTailConstStep_14(int n) { if (n <= 1) return n; return halvingTailConstStep_14(n / 2) + 1; }

int halvingTailStepThree_14(int n) { if (n <= 1) return n; return halvingTailStepThree_14(n / 3) + 2; }

int halvingTailStepFour_14(int n) { if (n <= 1) return n; return halvingTailStepFour_14(n / 4) + 1; }

void mergeSortVec_15(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_15(left); mergeSortVec_15(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_15(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_15(left); mergeSortInplace_15(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_15(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_15(left); mergeSortDeque_15(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_15(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_15(mid); splitCombineLinear_15(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_15(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_15(mid); splitConstantWork_15(mid); }

int halvingTailSearch_15(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_15(low, mid); return halvingTailSearch_15(mid + 1, high); }

int halvingTailConstStep_15(int n) { if (n <= 1) return n; return halvingTailConstStep_15(n / 2) + 1; }

int halvingTailStepThree_15(int n) { if (n <= 1) return n; return halvingTailStepThree_15(n / 3) + 2; }

int halvingTailStepFour_15(int n) { if (n <= 1) return n; return halvingTailStepFour_15(n / 4) + 1; }

void mergeSortVec_16(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_16(left); mergeSortVec_16(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_16(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_16(left); mergeSortInplace_16(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_16(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_16(left); mergeSortDeque_16(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_16(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_16(mid); splitCombineLinear_16(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_16(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_16(mid); splitConstantWork_16(mid); }

int halvingTailSearch_16(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_16(low, mid); return halvingTailSearch_16(mid + 1, high); }
