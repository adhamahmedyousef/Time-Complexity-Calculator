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


void splitCombineLinear_33(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_33(mid); splitCombineLinear_33(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_33(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_33(mid); splitConstantWork_33(mid); }

int halvingTailSearch_33(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_33(low, mid); return halvingTailSearch_33(mid + 1, high); }

int halvingTailConstStep_33(int n) { if (n <= 1) return n; return halvingTailConstStep_33(n / 2) + 1; }

int halvingTailStepThree_33(int n) { if (n <= 1) return n; return halvingTailStepThree_33(n / 3) + 2; }

int halvingTailStepFour_33(int n) { if (n <= 1) return n; return halvingTailStepFour_33(n / 4) + 1; }

void mergeSortVec_34(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_34(left); mergeSortVec_34(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_34(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_34(left); mergeSortInplace_34(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_34(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_34(left); mergeSortDeque_34(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_34(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_34(mid); splitCombineLinear_34(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_34(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_34(mid); splitConstantWork_34(mid); }

int halvingTailSearch_34(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_34(low, mid); return halvingTailSearch_34(mid + 1, high); }

int halvingTailConstStep_34(int n) { if (n <= 1) return n; return halvingTailConstStep_34(n / 2) + 1; }

int halvingTailStepThree_34(int n) { if (n <= 1) return n; return halvingTailStepThree_34(n / 3) + 2; }

int halvingTailStepFour_34(int n) { if (n <= 1) return n; return halvingTailStepFour_34(n / 4) + 1; }

void mergeSortVec_35(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_35(left); mergeSortVec_35(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_35(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_35(left); mergeSortInplace_35(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_35(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_35(left); mergeSortDeque_35(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_35(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_35(mid); splitCombineLinear_35(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_35(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_35(mid); splitConstantWork_35(mid); }

int halvingTailSearch_35(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_35(low, mid); return halvingTailSearch_35(mid + 1, high); }

int halvingTailConstStep_35(int n) { if (n <= 1) return n; return halvingTailConstStep_35(n / 2) + 1; }

int halvingTailStepThree_35(int n) { if (n <= 1) return n; return halvingTailStepThree_35(n / 3) + 2; }

int halvingTailStepFour_35(int n) { if (n <= 1) return n; return halvingTailStepFour_35(n / 4) + 1; }

void mergeSortVec_36(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_36(left); mergeSortVec_36(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_36(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_36(left); mergeSortInplace_36(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_36(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_36(left); mergeSortDeque_36(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_36(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_36(mid); splitCombineLinear_36(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_36(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_36(mid); splitConstantWork_36(mid); }

int halvingTailSearch_36(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_36(low, mid); return halvingTailSearch_36(mid + 1, high); }

int halvingTailConstStep_36(int n) { if (n <= 1) return n; return halvingTailConstStep_36(n / 2) + 1; }

int halvingTailStepThree_36(int n) { if (n <= 1) return n; return halvingTailStepThree_36(n / 3) + 2; }

int halvingTailStepFour_36(int n) { if (n <= 1) return n; return halvingTailStepFour_36(n / 4) + 1; }

void mergeSortVec_37(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_37(left); mergeSortVec_37(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_37(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_37(left); mergeSortInplace_37(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_37(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_37(left); mergeSortDeque_37(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_37(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_37(mid); splitCombineLinear_37(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_37(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_37(mid); splitConstantWork_37(mid); }

int halvingTailSearch_37(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_37(low, mid); return halvingTailSearch_37(mid + 1, high); }

int halvingTailConstStep_37(int n) { if (n <= 1) return n; return halvingTailConstStep_37(n / 2) + 1; }

int halvingTailStepThree_37(int n) { if (n <= 1) return n; return halvingTailStepThree_37(n / 3) + 2; }

int halvingTailStepFour_37(int n) { if (n <= 1) return n; return halvingTailStepFour_37(n / 4) + 1; }

void mergeSortVec_38(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_38(left); mergeSortVec_38(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_38(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_38(left); mergeSortInplace_38(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_38(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_38(left); mergeSortDeque_38(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_38(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_38(mid); splitCombineLinear_38(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_38(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_38(mid); splitConstantWork_38(mid); }

int halvingTailSearch_38(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_38(low, mid); return halvingTailSearch_38(mid + 1, high); }

int halvingTailConstStep_38(int n) { if (n <= 1) return n; return halvingTailConstStep_38(n / 2) + 1; }

int halvingTailStepThree_38(int n) { if (n <= 1) return n; return halvingTailStepThree_38(n / 3) + 2; }
