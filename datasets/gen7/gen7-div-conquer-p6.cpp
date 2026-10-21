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


int halvingTailStepThree_27(int n) { if (n <= 1) return n; return halvingTailStepThree_27(n / 3) + 2; }

int halvingTailStepFour_27(int n) { if (n <= 1) return n; return halvingTailStepFour_27(n / 4) + 1; }

void mergeSortVec_28(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_28(left); mergeSortVec_28(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_28(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_28(left); mergeSortInplace_28(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_28(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_28(left); mergeSortDeque_28(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_28(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_28(mid); splitCombineLinear_28(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_28(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_28(mid); splitConstantWork_28(mid); }

int halvingTailSearch_28(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_28(low, mid); return halvingTailSearch_28(mid + 1, high); }

int halvingTailConstStep_28(int n) { if (n <= 1) return n; return halvingTailConstStep_28(n / 2) + 1; }

int halvingTailStepThree_28(int n) { if (n <= 1) return n; return halvingTailStepThree_28(n / 3) + 2; }

int halvingTailStepFour_28(int n) { if (n <= 1) return n; return halvingTailStepFour_28(n / 4) + 1; }

void mergeSortVec_29(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_29(left); mergeSortVec_29(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_29(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_29(left); mergeSortInplace_29(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_29(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_29(left); mergeSortDeque_29(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_29(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_29(mid); splitCombineLinear_29(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_29(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_29(mid); splitConstantWork_29(mid); }

int halvingTailSearch_29(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_29(low, mid); return halvingTailSearch_29(mid + 1, high); }

int halvingTailConstStep_29(int n) { if (n <= 1) return n; return halvingTailConstStep_29(n / 2) + 1; }

int halvingTailStepThree_29(int n) { if (n <= 1) return n; return halvingTailStepThree_29(n / 3) + 2; }

int halvingTailStepFour_29(int n) { if (n <= 1) return n; return halvingTailStepFour_29(n / 4) + 1; }

void mergeSortVec_30(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_30(left); mergeSortVec_30(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_30(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_30(left); mergeSortInplace_30(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_30(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_30(left); mergeSortDeque_30(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_30(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_30(mid); splitCombineLinear_30(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_30(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_30(mid); splitConstantWork_30(mid); }

int halvingTailSearch_30(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_30(low, mid); return halvingTailSearch_30(mid + 1, high); }

int halvingTailConstStep_30(int n) { if (n <= 1) return n; return halvingTailConstStep_30(n / 2) + 1; }

int halvingTailStepThree_30(int n) { if (n <= 1) return n; return halvingTailStepThree_30(n / 3) + 2; }

int halvingTailStepFour_30(int n) { if (n <= 1) return n; return halvingTailStepFour_30(n / 4) + 1; }

void mergeSortVec_31(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_31(left); mergeSortVec_31(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_31(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_31(left); mergeSortInplace_31(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_31(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_31(left); mergeSortDeque_31(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_31(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_31(mid); splitCombineLinear_31(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_31(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_31(mid); splitConstantWork_31(mid); }

int halvingTailSearch_31(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_31(low, mid); return halvingTailSearch_31(mid + 1, high); }

int halvingTailConstStep_31(int n) { if (n <= 1) return n; return halvingTailConstStep_31(n / 2) + 1; }

int halvingTailStepThree_31(int n) { if (n <= 1) return n; return halvingTailStepThree_31(n / 3) + 2; }

int halvingTailStepFour_31(int n) { if (n <= 1) return n; return halvingTailStepFour_31(n / 4) + 1; }

void mergeSortVec_32(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_32(left); mergeSortVec_32(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_32(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_32(left); mergeSortInplace_32(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_32(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_32(left); mergeSortDeque_32(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_32(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_32(mid); splitCombineLinear_32(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_32(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_32(mid); splitConstantWork_32(mid); }

int halvingTailSearch_32(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_32(low, mid); return halvingTailSearch_32(mid + 1, high); }

int halvingTailConstStep_32(int n) { if (n <= 1) return n; return halvingTailConstStep_32(n / 2) + 1; }

int halvingTailStepThree_32(int n) { if (n <= 1) return n; return halvingTailStepThree_32(n / 3) + 2; }

int halvingTailStepFour_32(int n) { if (n <= 1) return n; return halvingTailStepFour_32(n / 4) + 1; }

void mergeSortVec_33(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_33(left); mergeSortVec_33(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_33(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_33(left); mergeSortInplace_33(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_33(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_33(left); mergeSortDeque_33(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }
