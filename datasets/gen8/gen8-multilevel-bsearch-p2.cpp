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


void g8_qBsearch_5(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_5(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_5(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_5(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_5(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_5(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_5(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_5(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_6(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_6(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_6(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_6(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_6(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_6(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_6(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_6(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_7(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_7(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_7(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_7(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_7(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_7(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_7(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_7(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_8(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_8(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_8(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_8(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_8(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_8(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_8(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_8(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_9(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_9(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_9(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_9(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_9(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_9(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_9(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_9(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }
