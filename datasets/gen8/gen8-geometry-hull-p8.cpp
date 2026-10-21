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


long long g8_crossProduct_35(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_35(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_35(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_35(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_35(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_35(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_35(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_35(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_36(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_36(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_36(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_36(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_36(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_36(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_36(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_36(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_37(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_37(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_37(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_37(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_37(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_37(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_37(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_37(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_38(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_38(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_38(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_38(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_38(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_38(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_38(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_38(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_39(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_39(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_39(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_39(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_39(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_39(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_39(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_39(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }
