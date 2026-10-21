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


int halvingTailSearch_5(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_5(low, mid); return halvingTailSearch_5(mid + 1, high); }

int halvingTailConstStep_5(int n) { if (n <= 1) return n; return halvingTailConstStep_5(n / 2) + 1; }

int halvingTailStepThree_5(int n) { if (n <= 1) return n; return halvingTailStepThree_5(n / 3) + 2; }

int halvingTailStepFour_5(int n) { if (n <= 1) return n; return halvingTailStepFour_5(n / 4) + 1; }

void mergeSortVec_6(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_6(left); mergeSortVec_6(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_6(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_6(left); mergeSortInplace_6(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_6(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_6(left); mergeSortDeque_6(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_6(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_6(mid); splitCombineLinear_6(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_6(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_6(mid); splitConstantWork_6(mid); }

int halvingTailSearch_6(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_6(low, mid); return halvingTailSearch_6(mid + 1, high); }

int halvingTailConstStep_6(int n) { if (n <= 1) return n; return halvingTailConstStep_6(n / 2) + 1; }

int halvingTailStepThree_6(int n) { if (n <= 1) return n; return halvingTailStepThree_6(n / 3) + 2; }

int halvingTailStepFour_6(int n) { if (n <= 1) return n; return halvingTailStepFour_6(n / 4) + 1; }

void mergeSortVec_7(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_7(left); mergeSortVec_7(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_7(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_7(left); mergeSortInplace_7(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_7(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_7(left); mergeSortDeque_7(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_7(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_7(mid); splitCombineLinear_7(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_7(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_7(mid); splitConstantWork_7(mid); }

int halvingTailSearch_7(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_7(low, mid); return halvingTailSearch_7(mid + 1, high); }

int halvingTailConstStep_7(int n) { if (n <= 1) return n; return halvingTailConstStep_7(n / 2) + 1; }

int halvingTailStepThree_7(int n) { if (n <= 1) return n; return halvingTailStepThree_7(n / 3) + 2; }

int halvingTailStepFour_7(int n) { if (n <= 1) return n; return halvingTailStepFour_7(n / 4) + 1; }

void mergeSortVec_8(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_8(left); mergeSortVec_8(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_8(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_8(left); mergeSortInplace_8(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_8(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_8(left); mergeSortDeque_8(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_8(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_8(mid); splitCombineLinear_8(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_8(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_8(mid); splitConstantWork_8(mid); }

int halvingTailSearch_8(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_8(low, mid); return halvingTailSearch_8(mid + 1, high); }

int halvingTailConstStep_8(int n) { if (n <= 1) return n; return halvingTailConstStep_8(n / 2) + 1; }

int halvingTailStepThree_8(int n) { if (n <= 1) return n; return halvingTailStepThree_8(n / 3) + 2; }

int halvingTailStepFour_8(int n) { if (n <= 1) return n; return halvingTailStepFour_8(n / 4) + 1; }

void mergeSortVec_9(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_9(left); mergeSortVec_9(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_9(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_9(left); mergeSortInplace_9(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_9(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_9(left); mergeSortDeque_9(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_9(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_9(mid); splitCombineLinear_9(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_9(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_9(mid); splitConstantWork_9(mid); }

int halvingTailSearch_9(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_9(low, mid); return halvingTailSearch_9(mid + 1, high); }

int halvingTailConstStep_9(int n) { if (n <= 1) return n; return halvingTailConstStep_9(n / 2) + 1; }

int halvingTailStepThree_9(int n) { if (n <= 1) return n; return halvingTailStepThree_9(n / 3) + 2; }

int halvingTailStepFour_9(int n) { if (n <= 1) return n; return halvingTailStepFour_9(n / 4) + 1; }

void mergeSortVec_10(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_10(left); mergeSortVec_10(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_10(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_10(left); mergeSortInplace_10(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_10(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_10(left); mergeSortDeque_10(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_10(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_10(mid); splitCombineLinear_10(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_10(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_10(mid); splitConstantWork_10(mid); }

int halvingTailSearch_10(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_10(low, mid); return halvingTailSearch_10(mid + 1, high); }

int halvingTailConstStep_10(int n) { if (n <= 1) return n; return halvingTailConstStep_10(n / 2) + 1; }

int halvingTailStepThree_10(int n) { if (n <= 1) return n; return halvingTailStepThree_10(n / 3) + 2; }

int halvingTailStepFour_10(int n) { if (n <= 1) return n; return halvingTailStepFour_10(n / 4) + 1; }

void mergeSortVec_11(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_11(left); mergeSortVec_11(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }
