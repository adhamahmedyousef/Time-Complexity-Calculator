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


long long g8_crossProduct_15(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_15(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_15(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_15(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_15(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_15(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_15(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_15(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_16(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_16(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_16(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_16(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_16(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_16(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_16(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_16(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_17(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_17(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_17(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_17(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_17(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_17(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_17(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_17(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_18(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_18(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_18(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_18(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_18(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_18(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_18(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_18(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_19(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_19(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_19(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_19(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_19(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_19(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_19(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_19(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }
