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


void g8_qBsearch_0(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_0(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_0(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_0(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_0(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_0(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_0(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_0(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_1(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_1(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_1(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_1(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_1(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_1(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_1(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_1(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_2(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_2(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_2(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_2(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_2(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_2(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_2(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_2(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_3(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_3(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_3(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_3(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_3(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_3(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_3(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_3(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }

void g8_qBsearch_4(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)binary_search(a.begin(), a.end(), q); } }

void g8_qLowerBound_4(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)lower_bound(a.begin(), a.end(), q); } }

void g8_qUpperBound_4(const vector<int>& a, int m) { for (int q = 0; q < m; ++q) { (void)upper_bound(a.begin(), a.end(), q); } }

void g8_nBsearch_4(const vector<int>& a) { int n = static_cast<int>(a.size()); for (int i = 0; i < n; ++i) { (void)binary_search(a.begin(), a.end(), i); } }

void g8_bsearchBitwiseQuery_4(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)lower_bound(a.begin(), a.end(), i); } }

void g8_bsearchSqrtQuery_4(const vector<int>& a, int m) { for (int i = 0; i < m; ++i) { (void)upper_bound(a.begin(), a.end(), i); } }

int g8_qCountSearch_4(const vector<int>& a, int m) { int found = 0; for (int q = 0; q < m; ++q) { if (binary_search(a.begin(), a.end(), q)) found++; } return found; }

void g8_nBinarySteps_4(int n) { for (int i = 0; i < n; ++i) { int x = n; while (x > 1) x /= 2; } }
