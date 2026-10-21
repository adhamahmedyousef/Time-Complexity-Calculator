// Generated family: gen3-sort3-01
// Labels from first principles.
using namespace std;

void bubbleSort_0(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_0(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_0(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_0(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_0(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_0(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_0(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_0(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_0(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_0(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_1(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_1(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_1(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_1(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_1(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_1(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_1(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_1(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_1(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_1(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_2(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_2(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_2(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_2(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_2(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_2(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_2(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_2(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_2(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_2(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_3(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_3(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_3(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_3(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_3(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_3(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_3(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_3(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_3(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_3(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_4(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_4(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_4(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_4(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_4(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_4(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_4(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_4(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_4(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_4(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_5(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_5(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_5(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_5(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_5(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_5(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_5(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_5(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_5(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_5(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_6(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_6(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_6(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_6(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_6(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_6(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_6(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_6(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_6(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_6(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
void bubbleSort_7(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) if (a[j] > a[j + 1]) { int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; } }
void selectionSort_7(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) { int mn = i; for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j; int tmp = a[i]; a[i] = a[mn]; a[mn] = tmp; } }
void insertionSort_7(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; } a[j + 1] = key; } }
void insertionSortFor_7(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; for (; j >= 0 && a[j] > key; --j) a[j + 1] = a[j]; a[j + 1] = key; } }
vector<int> countingSort_7(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; vector<int> out(a.size(), 0); int w = 0; for (int v2 = 0; v2 <= k; ++v2) for (int c = 0; c < cnt[v2]; ++c) out[w++] = v2; return out; }
vector<int> countingSortStable_7(const vector<int>& a, int k) { vector<int> cnt(k + 1, 0); for (int x : a) ++cnt[x]; for (int v2 = 1; v2 <= k; ++v2) cnt[v2] += cnt[v2 - 1]; vector<int> out(a.size(), 0); for (int i = (int)a.size() - 1; i >= 0; --i) out[--cnt[a[i]]] = a[i]; return out; }
int sortScanEarly_7(vector<int>& a, int t) { sort(a.begin(), a.end()); for (int x : a) { if (x >= t) return x; } return -1; }
int kthSmallestSort_7(const vector<int>& a, int k) { vector<int> b = a; sort(b.begin(), b.end()); return b[k - 1]; }
long long sortThenCountPairs_7(vector<int>& a) { sort(a.begin(), a.end()); long long pairs = 0; for (int i = 0; i + 1 < (int)a.size(); ++i) if (a[i] == a[i + 1]) ++pairs; return pairs; }
void bubbleSortShrinking_7(vector<int>& a) { int n = a.size(); for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < n - i; ++j) { if (a[j] > a[j + 1]) swap(a[j], a[j + 1]); } }
