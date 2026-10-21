// Generated family: gen5-sort-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void selectionSort_25(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_25(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_25(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_25(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_26(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_26(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_26(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_26(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_27(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_27(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_27(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_27(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_28(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_28(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_28(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_28(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
void selectionSort_29(vector<int>& a) { int n = a.size(); for (int i = 0; i < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertionSort_29(vector<int>& a) { int n = a.size(); for (int i = 1; i < n; ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
vector<int> countSortFreq_29(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; return cnt; }
void dutchFlagPartition_29(vector<int>& a) { int lo = 0, mid = 0, hi = (int)a.size() - 1; while (mid <= hi) { if (a[mid] == 0) swap(a[lo++], a[mid++]); else if (a[mid] == 1) ++mid; else swap(a[mid], a[hi--]); } }
