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


void g8_qBsearch_10(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_10(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_10(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_10(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_10(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_10(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_10(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_10(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_11(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_11(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_11(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_11(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_11(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_11(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_11(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_11(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_12(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_12(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_12(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_12(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_12(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_12(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_12(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_12(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_13(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_13(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_13(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_13(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_13(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_13(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_13(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_13(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_14(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_14(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_14(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_14(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_14(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_14(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_14(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_14(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }
