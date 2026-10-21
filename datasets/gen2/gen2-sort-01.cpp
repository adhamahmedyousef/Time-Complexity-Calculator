// Generated family: gen2-sort-01
// Labels from first principles.
using namespace std;

void bubbleSort_0(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }
void selectSort_0(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) { int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertSort_0(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; } a[j+1] = key; } }
void bubbleSort_1(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }
void selectSort_1(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) { int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertSort_1(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; } a[j+1] = key; } }
void bubbleSort_2(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }
void selectSort_2(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) { int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertSort_2(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; } a[j+1] = key; } }
void bubbleSort_3(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }
void selectSort_3(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) { int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertSort_3(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; } a[j+1] = key; } }
void bubbleSort_4(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }
void selectSort_4(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) { int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertSort_4(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; } a[j+1] = key; } }
void bubbleSort_5(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }
void selectSort_5(vector<int>& a) { int n = a.size(); for (int i = 0; i < n-1; ++i) { int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); } }
void insertSort_5(vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) { int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; } a[j+1] = key; } }
