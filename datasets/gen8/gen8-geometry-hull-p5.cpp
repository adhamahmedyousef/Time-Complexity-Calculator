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


long long g8_crossProduct_20(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_20(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_20(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_20(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_20(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_20(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_20(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_20(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_21(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_21(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_21(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_21(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_21(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_21(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_21(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_21(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_22(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_22(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_22(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_22(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_22(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_22(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_22(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_22(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_23(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_23(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_23(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_23(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_23(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_23(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_23(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_23(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_24(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_24(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_24(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_24(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_24(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_24(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_24(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_24(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }
