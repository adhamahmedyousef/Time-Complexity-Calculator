#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


void g8_qBsearch_15(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_15(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_15(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_15(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_15(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_15(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_15(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_15(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_16(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_16(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_16(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_16(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_16(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_16(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_16(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_16(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_17(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_17(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_17(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_17(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_17(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_17(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_17(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_17(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_18(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_18(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_18(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_18(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_18(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_18(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_18(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_18(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_19(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_19(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_19(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_19(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_19(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_19(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_19(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_19(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }
