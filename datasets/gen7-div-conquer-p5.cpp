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


void mergeSortDeque_22(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_22(left); mergeSortDeque_22(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_22(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_22(mid); splitCombineLinear_22(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_22(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_22(mid); splitConstantWork_22(mid); }

int halvingTailSearch_22(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_22(low, mid); return halvingTailSearch_22(mid + 1, high); }

int halvingTailConstStep_22(int n) { if (n <= 1) return n; return halvingTailConstStep_22(n / 2) + 1; }

int halvingTailStepThree_22(int n) { if (n <= 1) return n; return halvingTailStepThree_22(n / 3) + 2; }

int halvingTailStepFour_22(int n) { if (n <= 1) return n; return halvingTailStepFour_22(n / 4) + 1; }

void mergeSortVec_23(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_23(left); mergeSortVec_23(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_23(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_23(left); mergeSortInplace_23(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_23(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_23(left); mergeSortDeque_23(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_23(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_23(mid); splitCombineLinear_23(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_23(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_23(mid); splitConstantWork_23(mid); }

int halvingTailSearch_23(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_23(low, mid); return halvingTailSearch_23(mid + 1, high); }

int halvingTailConstStep_23(int n) { if (n <= 1) return n; return halvingTailConstStep_23(n / 2) + 1; }

int halvingTailStepThree_23(int n) { if (n <= 1) return n; return halvingTailStepThree_23(n / 3) + 2; }

int halvingTailStepFour_23(int n) { if (n <= 1) return n; return halvingTailStepFour_23(n / 4) + 1; }

void mergeSortVec_24(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_24(left); mergeSortVec_24(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_24(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_24(left); mergeSortInplace_24(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_24(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_24(left); mergeSortDeque_24(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_24(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_24(mid); splitCombineLinear_24(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_24(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_24(mid); splitConstantWork_24(mid); }

int halvingTailSearch_24(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_24(low, mid); return halvingTailSearch_24(mid + 1, high); }

int halvingTailConstStep_24(int n) { if (n <= 1) return n; return halvingTailConstStep_24(n / 2) + 1; }

int halvingTailStepThree_24(int n) { if (n <= 1) return n; return halvingTailStepThree_24(n / 3) + 2; }

int halvingTailStepFour_24(int n) { if (n <= 1) return n; return halvingTailStepFour_24(n / 4) + 1; }

void mergeSortVec_25(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_25(left); mergeSortVec_25(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_25(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_25(left); mergeSortInplace_25(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_25(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_25(left); mergeSortDeque_25(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_25(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_25(mid); splitCombineLinear_25(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_25(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_25(mid); splitConstantWork_25(mid); }

int halvingTailSearch_25(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_25(low, mid); return halvingTailSearch_25(mid + 1, high); }

int halvingTailConstStep_25(int n) { if (n <= 1) return n; return halvingTailConstStep_25(n / 2) + 1; }

int halvingTailStepThree_25(int n) { if (n <= 1) return n; return halvingTailStepThree_25(n / 3) + 2; }

int halvingTailStepFour_25(int n) { if (n <= 1) return n; return halvingTailStepFour_25(n / 4) + 1; }

void mergeSortVec_26(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_26(left); mergeSortVec_26(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_26(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_26(left); mergeSortInplace_26(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_26(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_26(left); mergeSortDeque_26(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_26(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_26(mid); splitCombineLinear_26(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_26(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_26(mid); splitConstantWork_26(mid); }

int halvingTailSearch_26(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_26(low, mid); return halvingTailSearch_26(mid + 1, high); }

int halvingTailConstStep_26(int n) { if (n <= 1) return n; return halvingTailConstStep_26(n / 2) + 1; }

int halvingTailStepThree_26(int n) { if (n <= 1) return n; return halvingTailStepThree_26(n / 3) + 2; }

int halvingTailStepFour_26(int n) { if (n <= 1) return n; return halvingTailStepFour_26(n / 4) + 1; }

void mergeSortVec_27(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_27(left); mergeSortVec_27(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_27(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_27(left); mergeSortInplace_27(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_27(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_27(left); mergeSortDeque_27(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_27(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_27(mid); splitCombineLinear_27(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_27(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_27(mid); splitConstantWork_27(mid); }

int halvingTailSearch_27(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_27(low, mid); return halvingTailSearch_27(mid + 1, high); }

int halvingTailConstStep_27(int n) { if (n <= 1) return n; return halvingTailConstStep_27(n / 2) + 1; }
