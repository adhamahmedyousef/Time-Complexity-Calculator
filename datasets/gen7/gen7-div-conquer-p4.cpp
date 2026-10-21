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


int halvingTailConstStep_16(int n) { if (n <= 1) return n; return halvingTailConstStep_16(n / 2) + 1; }

int halvingTailStepThree_16(int n) { if (n <= 1) return n; return halvingTailStepThree_16(n / 3) + 2; }

int halvingTailStepFour_16(int n) { if (n <= 1) return n; return halvingTailStepFour_16(n / 4) + 1; }

void mergeSortVec_17(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_17(left); mergeSortVec_17(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_17(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_17(left); mergeSortInplace_17(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_17(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_17(left); mergeSortDeque_17(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_17(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_17(mid); splitCombineLinear_17(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_17(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_17(mid); splitConstantWork_17(mid); }

int halvingTailSearch_17(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_17(low, mid); return halvingTailSearch_17(mid + 1, high); }

int halvingTailConstStep_17(int n) { if (n <= 1) return n; return halvingTailConstStep_17(n / 2) + 1; }

int halvingTailStepThree_17(int n) { if (n <= 1) return n; return halvingTailStepThree_17(n / 3) + 2; }

int halvingTailStepFour_17(int n) { if (n <= 1) return n; return halvingTailStepFour_17(n / 4) + 1; }

void mergeSortVec_18(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_18(left); mergeSortVec_18(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_18(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_18(left); mergeSortInplace_18(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_18(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_18(left); mergeSortDeque_18(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_18(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_18(mid); splitCombineLinear_18(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_18(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_18(mid); splitConstantWork_18(mid); }

int halvingTailSearch_18(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_18(low, mid); return halvingTailSearch_18(mid + 1, high); }

int halvingTailConstStep_18(int n) { if (n <= 1) return n; return halvingTailConstStep_18(n / 2) + 1; }

int halvingTailStepThree_18(int n) { if (n <= 1) return n; return halvingTailStepThree_18(n / 3) + 2; }

int halvingTailStepFour_18(int n) { if (n <= 1) return n; return halvingTailStepFour_18(n / 4) + 1; }

void mergeSortVec_19(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_19(left); mergeSortVec_19(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_19(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_19(left); mergeSortInplace_19(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_19(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_19(left); mergeSortDeque_19(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_19(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_19(mid); splitCombineLinear_19(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_19(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_19(mid); splitConstantWork_19(mid); }

int halvingTailSearch_19(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_19(low, mid); return halvingTailSearch_19(mid + 1, high); }

int halvingTailConstStep_19(int n) { if (n <= 1) return n; return halvingTailConstStep_19(n / 2) + 1; }

int halvingTailStepThree_19(int n) { if (n <= 1) return n; return halvingTailStepThree_19(n / 3) + 2; }

int halvingTailStepFour_19(int n) { if (n <= 1) return n; return halvingTailStepFour_19(n / 4) + 1; }

void mergeSortVec_20(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_20(left); mergeSortVec_20(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_20(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_20(left); mergeSortInplace_20(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_20(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_20(left); mergeSortDeque_20(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_20(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_20(mid); splitCombineLinear_20(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_20(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_20(mid); splitConstantWork_20(mid); }

int halvingTailSearch_20(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_20(low, mid); return halvingTailSearch_20(mid + 1, high); }

int halvingTailConstStep_20(int n) { if (n <= 1) return n; return halvingTailConstStep_20(n / 2) + 1; }

int halvingTailStepThree_20(int n) { if (n <= 1) return n; return halvingTailStepThree_20(n / 3) + 2; }

int halvingTailStepFour_20(int n) { if (n <= 1) return n; return halvingTailStepFour_20(n / 4) + 1; }

void mergeSortVec_21(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_21(left); mergeSortVec_21(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_21(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_21(left); mergeSortInplace_21(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_21(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_21(left); mergeSortDeque_21(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_21(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_21(mid); splitCombineLinear_21(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_21(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_21(mid); splitConstantWork_21(mid); }

int halvingTailSearch_21(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_21(low, mid); return halvingTailSearch_21(mid + 1, high); }

int halvingTailConstStep_21(int n) { if (n <= 1) return n; return halvingTailConstStep_21(n / 2) + 1; }

int halvingTailStepThree_21(int n) { if (n <= 1) return n; return halvingTailStepThree_21(n / 3) + 2; }

int halvingTailStepFour_21(int n) { if (n <= 1) return n; return halvingTailStepFour_21(n / 4) + 1; }

void mergeSortVec_22(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_22(left); mergeSortVec_22(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_22(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_22(left); mergeSortInplace_22(right); inplace_merge(left.begin(), left.end(), right.end()); }
