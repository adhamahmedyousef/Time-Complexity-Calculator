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


int halvingTailStepFour_38(int n) { if (n <= 1) return n; return halvingTailStepFour_38(n / 4) + 1; }

void mergeSortVec_39(vector<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortVec_39(left); mergeSortVec_39(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void mergeSortInplace_39(vector<int>& a) { if (a.empty() || a.size() == 1) return; int mid = static_cast<int>(a.size()) / 2; vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortInplace_39(left); mergeSortInplace_39(right); inplace_merge(left.begin(), left.end(), right.end()); }

void mergeSortDeque_39(deque<int>& a) { if (a.size() <= 1) return; int mid = static_cast<int>(a.size()) / 2; deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end()); mergeSortDeque_39(left); mergeSortDeque_39(right); merge(left.begin(), left.end(), right.begin(), right.end(), a.begin()); }

void splitCombineLinear_39(int n) { if (n <= 1) return; int mid = n / 2; splitCombineLinear_39(mid); splitCombineLinear_39(mid); for (int i = 0; i < n; ++i) { (void)i; } }

void splitConstantWork_39(int n) { if (n <= 1) return; int mid = n / 2; splitConstantWork_39(mid); splitConstantWork_39(mid); }

int halvingTailSearch_39(int low, int high) { if (low >= high) return low; int mid = (low + high) / 2; if (mid > 10) return halvingTailSearch_39(low, mid); return halvingTailSearch_39(mid + 1, high); }

int halvingTailConstStep_39(int n) { if (n <= 1) return n; return halvingTailConstStep_39(n / 2) + 1; }

int halvingTailStepThree_39(int n) { if (n <= 1) return n; return halvingTailStepThree_39(n / 3) + 2; }

int halvingTailStepFour_39(int n) { if (n <= 1) return n; return halvingTailStepFour_39(n / 4) + 1; }
