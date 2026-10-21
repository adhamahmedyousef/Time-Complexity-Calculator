// Generated family: gen6-sort-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void selectionSortMin_0(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_0(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_0(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_1(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_1(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_1(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_2(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_2(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_2(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_3(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_3(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_3(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_4(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_4(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_4(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_5(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_5(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_5(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_6(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_6(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_6(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_7(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_7(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_7(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_8(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_8(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_8(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_9(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_9(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_9(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_10(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_10(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_10(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_11(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_11(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_11(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_12(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_12(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_12(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_13(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_13(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_13(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_14(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_14(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_14(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_15(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_15(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_15(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_16(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_16(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_16(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_17(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_17(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_17(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_18(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_18(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_18(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_19(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_19(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_19(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_20(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_20(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_20(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_21(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_21(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_21(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_22(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_22(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_22(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_23(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_23(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_23(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_24(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_24(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_24(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_25(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_25(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_25(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_26(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_26(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_26(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_27(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_27(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_27(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_28(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_28(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_28(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_29(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_29(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_29(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_30(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_30(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_30(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_31(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_31(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_31(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_32(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSortAscending_32(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreqArray_32(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void selectionSortMin_33(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
