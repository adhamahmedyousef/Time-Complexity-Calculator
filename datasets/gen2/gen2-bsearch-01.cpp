// Generated family: gen2-bsearch-01
// Labels from first principles.
using namespace std;

int binSearch_0(const vector<int>& a, int t) { int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) { int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; } return -1; }
int lowerBnd_0(const vector<int>& a, int x) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; } return lo; }
int binSearch_1(const vector<int>& a, int t) { int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) { int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; } return -1; }
int lowerBnd_1(const vector<int>& a, int x) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; } return lo; }
int binSearch_2(const vector<int>& a, int t) { int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) { int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; } return -1; }
int lowerBnd_2(const vector<int>& a, int x) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; } return lo; }
int binSearch_3(const vector<int>& a, int t) { int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) { int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; } return -1; }
int lowerBnd_3(const vector<int>& a, int x) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; } return lo; }
int binSearch_4(const vector<int>& a, int t) { int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) { int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; } return -1; }
int lowerBnd_4(const vector<int>& a, int x) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; } return lo; }
int binSearch_5(const vector<int>& a, int t) { int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) { int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; } return -1; }
int lowerBnd_5(const vector<int>& a, int x) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; } return lo; }
