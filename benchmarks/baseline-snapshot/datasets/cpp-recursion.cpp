#include <bits/stdc++.h>
using namespace std;

long long sampleRecursiveSum(const vector<int>& a, int i) { return i == static_cast<int>(a.size()) ? 0 : a[i] + sampleRecursiveSum(a, i + 1); }
int sampleDivideConquerMax(const vector<int>& a, int l, int r) { if (l == r) return a[l]; int m = (l + r) / 2; return max(sampleDivideConquerMax(a, l, m), sampleDivideConquerMax(a, m + 1, r)); }
void sampleGenerateSubsets(int n, int i, vector<int>& cur, vector<vector<int>>& out) { if (i == n) { out.push_back(cur); return; } sampleGenerateSubsets(n, i + 1, cur, out); cur.push_back(i); sampleGenerateSubsets(n, i + 1, cur, out); cur.pop_back(); }
void samplePermutations(vector<int>& a, int l, vector<vector<int>>& out) { if (l == static_cast<int>(a.size())) { out.push_back(a); return; } for (int i = l; i < static_cast<int>(a.size()); ++i) { swap(a[l], a[i]); samplePermutations(a, l + 1, out); swap(a[l], a[i]); } }
int sampleRecursiveBinarySearch(const vector<int>& a, int l, int r, int x) { if (l > r) return -1; int m = (l + r) / 2; if (a[m] == x) return m; return a[m] < x ? sampleRecursiveBinarySearch(a, m + 1, r, x) : sampleRecursiveBinarySearch(a, l, m - 1, x); }
int sampleTailRecChain(int n) { return n == 0 ? 0 : 1 + sampleTailRecChain(n - 1); }
