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


void mergeSortVec_0(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_0(left); mergeSortVec_0(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_0(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_0(left); mergeSortInplace_0(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_0(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_0(left); mergeSortDeque_0(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_0(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_0(mid); splitCombineLinear_0(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_0(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_0(mid); splitConstantWork_0(mid); }

int halvingTailSearch_0(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_0(low, mid); return halvingTailSearch_0(mid + 1, high); }

int halvingTailConstStep_0(int n) { if (n <= 1) return n; return halvingTailConstStep_0(n / 2) + 1; }

int halvingTailStepThree_0(int n) { if (n <= 1) return n; return halvingTailStepThree_0(n / 3) + 2; }

int halvingTailStepFour_0(int n) { if (n <= 1) return n; return halvingTailStepFour_0(n / 4) + 1; }

void mergeSortVec_1(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_1(left); mergeSortVec_1(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_1(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_1(left); mergeSortInplace_1(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_1(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_1(left); mergeSortDeque_1(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_1(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_1(mid); splitCombineLinear_1(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_1(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_1(mid); splitConstantWork_1(mid); }

int halvingTailSearch_1(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_1(low, mid); return halvingTailSearch_1(mid + 1, high); }

int halvingTailConstStep_1(int n) { if (n <= 1) return n; return halvingTailConstStep_1(n / 2) + 1; }

int halvingTailStepThree_1(int n) { if (n <= 1) return n; return halvingTailStepThree_1(n / 3) + 2; }

int halvingTailStepFour_1(int n) { if (n <= 1) return n; return halvingTailStepFour_1(n / 4) + 1; }

void mergeSortVec_2(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_2(left); mergeSortVec_2(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_2(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_2(left); mergeSortInplace_2(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_2(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_2(left); mergeSortDeque_2(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_2(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_2(mid); splitCombineLinear_2(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_2(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_2(mid); splitConstantWork_2(mid); }

int halvingTailSearch_2(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_2(low, mid); return halvingTailSearch_2(mid + 1, high); }

int halvingTailConstStep_2(int n) { if (n <= 1) return n; return halvingTailConstStep_2(n / 2) + 1; }

int halvingTailStepThree_2(int n) { if (n <= 1) return n; return halvingTailStepThree_2(n / 3) + 2; }

int halvingTailStepFour_2(int n) { if (n <= 1) return n; return halvingTailStepFour_2(n / 4) + 1; }

void mergeSortVec_3(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_3(left); mergeSortVec_3(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_3(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_3(left); mergeSortInplace_3(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_3(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_3(left); mergeSortDeque_3(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_3(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_3(mid); splitCombineLinear_3(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_3(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_3(mid); splitConstantWork_3(mid); }

int halvingTailSearch_3(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_3(low, mid); return halvingTailSearch_3(mid + 1, high); }

int halvingTailConstStep_3(int n) { if (n <= 1) return n; return halvingTailConstStep_3(n / 2) + 1; }

int halvingTailStepThree_3(int n) { if (n <= 1) return n; return halvingTailStepThree_3(n / 3) + 2; }

int halvingTailStepFour_3(int n) { if (n <= 1) return n; return halvingTailStepFour_3(n / 4) + 1; }

void mergeSortVec_4(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_4(left); mergeSortVec_4(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_4(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_4(left); mergeSortInplace_4(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_4(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_4(left); mergeSortDeque_4(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_4(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_4(mid); splitCombineLinear_4(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_4(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_4(mid); splitConstantWork_4(mid); }

int halvingTailSearch_4(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_4(low, mid); return halvingTailSearch_4(mid + 1, high); }

int halvingTailConstStep_4(int n) { if (n <= 1) return n; return halvingTailConstStep_4(n / 2) + 1; }

int halvingTailStepThree_4(int n) { if (n <= 1) return n; return halvingTailStepThree_4(n / 3) + 2; }

int halvingTailStepFour_4(int n) { if (n <= 1) return n; return halvingTailStepFour_4(n / 4) + 1; }

void mergeSortVec_5(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_5(left); mergeSortVec_5(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_5(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_5(left); mergeSortInplace_5(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_5(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_5(left); mergeSortDeque_5(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_5(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_5(mid); splitCombineLinear_5(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_5(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_5(mid); splitConstantWork_5(mid); }
