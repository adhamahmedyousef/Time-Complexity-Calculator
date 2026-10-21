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


int stlMaxElementVector_37(const vector<int>& a) { if (a.empty()) return 0; return *max_element(a.begin(), a.end()); }

int stlMinElementVector_37(const vector<int>& a) { if (a.empty()) return 0; return *min_element(a.begin(), a.end()); }

long long stlAccumulateVector_37(const vector<int>& a) { return accumulate(a.begin(), a.end(), 0LL); }

int stlCountIfVector_37(const vector<int>& a) { int c = 0; for (int x : a) if (x > 0) ++c; return c; }

void stlSortVector_38(vector<int>& a) { sort(a.begin(), a.end()); }

void stlReverseVector_38(vector<int>& a) { reverse(a.begin(), a.end()); }

void stlFillVector_38(vector<int>& a, int val) { fill(a.begin(), a.end(), val); }

void stlIotaVector_38(vector<int>& a, int start) { iota(a.begin(), a.end(), start); }

int stlMaxElementVector_38(const vector<int>& a) { if (a.empty()) return 0; return *max_element(a.begin(), a.end()); }

int stlMinElementVector_38(const vector<int>& a) { if (a.empty()) return 0; return *min_element(a.begin(), a.end()); }

long long stlAccumulateVector_38(const vector<int>& a) { return accumulate(a.begin(), a.end(), 0LL); }

int stlCountIfVector_38(const vector<int>& a) { int c = 0; for (int x : a) if (x > 0) ++c; return c; }

void stlSortVector_39(vector<int>& a) { sort(a.begin(), a.end()); }

void stlReverseVector_39(vector<int>& a) { reverse(a.begin(), a.end()); }

void stlFillVector_39(vector<int>& a, int val) { fill(a.begin(), a.end(), val); }

void stlIotaVector_39(vector<int>& a, int start) { iota(a.begin(), a.end(), start); }

int stlMaxElementVector_39(const vector<int>& a) { if (a.empty()) return 0; return *max_element(a.begin(), a.end()); }

int stlMinElementVector_39(const vector<int>& a) { if (a.empty()) return 0; return *min_element(a.begin(), a.end()); }

long long stlAccumulateVector_39(const vector<int>& a) { return accumulate(a.begin(), a.end(), 0LL); }

int stlCountIfVector_39(const vector<int>& a) { int c = 0; for (int x : a) if (x > 0) ++c; return c; }
