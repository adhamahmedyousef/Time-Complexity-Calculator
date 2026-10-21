// Generated family: gen5-sort-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void selectionSort_0(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_0(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_0(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_0(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_1(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_1(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_1(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_1(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_2(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_2(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_2(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_2(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_3(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_3(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_3(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_3(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_4(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_4(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_4(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_4(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_5(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_5(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_5(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_5(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_6(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_6(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_6(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_6(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_7(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_7(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_7(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_7(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_8(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_8(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_8(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_8(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_9(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_9(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_9(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_9(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_10(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_10(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_10(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_10(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_11(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_11(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_11(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_11(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_12(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_12(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_12(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_12(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_13(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_13(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_13(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_13(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_14(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_14(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_14(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_14(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_15(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_15(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_15(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_15(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_16(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_16(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_16(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_16(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_17(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_17(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_17(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_17(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_18(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_18(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_18(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_18(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_19(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_19(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_19(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_19(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_20(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_20(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_20(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_20(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_21(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_21(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_21(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_21(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_22(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_22(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_22(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_22(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_23(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_23(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_23(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_23(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_24(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_24(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_24(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_24(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
