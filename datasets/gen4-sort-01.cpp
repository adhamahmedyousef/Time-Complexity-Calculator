// Generated family: gen4-sort-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void dutchNationalFlag_0(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_0(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_0(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_0(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_1(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_1(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_1(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_1(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_2(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_2(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_2(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_2(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_3(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_3(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_3(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_3(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_4(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_4(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_4(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_4(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_5(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_5(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_5(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_5(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_6(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_6(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_6(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_6(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_7(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_7(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_7(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_7(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_8(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_8(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_8(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_8(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_9(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_9(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_9(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_9(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_10(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_10(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_10(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_10(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_11(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_11(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_11(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_11(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_12(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_12(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_12(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_12(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_13(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_13(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_13(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_13(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_14(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_14(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_14(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_14(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_15(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_15(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_15(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_15(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_16(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_16(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_16(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_16(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_17(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_17(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_17(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_17(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_18(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_18(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_18(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_18(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchNationalFlag_19(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) { swap(a[lo++], a[mid++]); } else if (a[mid] == 1) { ++mid; } else { swap(a[mid], a[hi--]); } } }
void selectionSortMin_19(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_19(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_19(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
