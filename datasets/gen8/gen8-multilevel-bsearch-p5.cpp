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


void g8_qBsearch_20(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_20(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_20(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_20(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_20(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_20(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_20(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_20(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_21(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_21(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_21(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_21(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_21(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_21(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_21(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_21(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_22(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_22(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_22(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_22(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_22(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_22(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_22(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_22(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_23(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_23(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_23(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_23(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_23(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_23(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_23(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_23(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_24(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_24(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_24(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_24(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_24(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_24(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_24(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_24(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }
