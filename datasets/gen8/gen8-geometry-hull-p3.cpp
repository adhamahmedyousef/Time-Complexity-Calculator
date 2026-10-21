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


long long g8_crossProduct_10(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_10(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_10(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_10(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_10(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_10(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_10(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_10(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_11(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_11(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_11(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_11(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_11(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_11(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_11(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_11(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_12(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_12(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_12(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_12(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_12(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_12(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_12(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_12(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_13(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_13(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_13(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_13(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_13(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_13(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_13(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_13(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_14(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_14(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_14(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_14(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_14(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_14(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_14(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_14(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }
