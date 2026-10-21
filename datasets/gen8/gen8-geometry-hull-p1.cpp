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


long long g8_crossProduct_0(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_0(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_0(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_0(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_0(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_0(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_0(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_0(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_1(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_1(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_1(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_1(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_1(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_1(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_1(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_1(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_2(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_2(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_2(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_2(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_2(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_2(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_2(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_2(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_3(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_3(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_3(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_3(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_3(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_3(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_3(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_3(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }

long long g8_crossProduct_4(long long x1, long long y1, long long x2, long long y2) { return x1 * y2 - y1 * x2; }

int g8_polygonPerimeter_4(const vector<int>& x, const vector<int>& y) { int n = x.size(), per = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; per += abs(x[i] - x[j]) + abs(y[i] - y[j]); } return per; }

void g8_pointSort_4(vector<pair<int, int>>& pts) { sort(pts.begin(), pts.end()); }

int g8_pointScan_4(const vector<pair<int, int>>& pts) { int maxX = 0; for (const auto& p : pts) maxX = max(maxX, p.first); return maxX; }

int g8_manhattanDist_4(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long long g8_polygonArea2D_4(const vector<int>& x, const vector<int>& y) { int n = x.size(); long long area = 0; for (int i = 0; i < n; ++i) { int j = (i + 1) % n; area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i]; } return area; }

void g8_lineSweepEvents_4(vector<int>& events) { sort(events.begin(), events.end()); for (int e : events) { (void)e; } }

bool g8_collinearCheck_4(int x1, int y1, int x2, int y2, int x3, int y3) { return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1); }
