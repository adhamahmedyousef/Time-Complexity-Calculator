// Micro-statement dataset: single-line / handful-of-lines functions that a
// programmer might highlight to ask "what does this cost?".
//
// Adjudication policy for every label in the sibling manifest:
//  - Constant work (literals, fixed-size containers, constant-bound loops)
//    is O(1) time. Auxiliary space is O(1) unless a container of input-
//    derived size is materialized.
//  - Linear scans over an input container are O(n) time / O(1) space.
//  - Comparisons of input-sized containers follow the corpus conventions
//    already established by the axis/stl families (sort -> O(n log n) with
//    Unknown auxiliary space; reverse/find/count/fill -> O(n) / O(1);
//    order-statistic queries on sorted ranges -> O(log n) / O(1);
//    Euclid's gcd -> O(log n) / O(1)).
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// Constant scalar work: every function here performs a fixed number of
// elementary operations regardless of any input.
// ---------------------------------------------------------------------------

int microConstInt() { int x = 10; return x; }

int microConstFold() { int x = 10; int y = x * 2 + 7; return y; }

int microSwapScalars() { int x = 1, y = 2; swap(x, y); return x + y; }

long long microModArith() { long long x = 123; x = (x * 31 + 7) % 1000000007; return x; }

int microBitOps() { int x = 123; x = (x << 3) | (x >> 1); return x; }

int microMinMax() { int a = 3, b = 8; return max(a, b) - min(a, b); }

int microTernaryAbs() { int x = -5; int y = x > 0 ? x : -x; return y; }

int microCondIncrement() { int x = 0; if (x >= 0) ++x; return x; }

int microConstBoundFor() { int s = 0; for (int i = 0; i < 10; ++i) s += i; return s; }

int microConstBoundWhile() { int s = 0, i = 0; while (i < 5) { s += i++; } return s; }

int microNestedConstLoop() { int s = 0; for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) s += i * j; return s; }

int microFixedArraySwap() { int a[3] = {1, 2, 3}; swap(a[0], a[2]); return a[0]; }

int microIndexReadWrite() { int a[4] = {}; a[1] = 5; return a[1]; }

int microReturnZero() { return 0; }

int microFloorDivMod() { int x = 17; return x / 3 + x % 3; }

int microCharArith() { char c = 'A'; return c + 1; }

bool microBoolLogic() { bool a = true, b = false; return a && !b; }

int microXorShift() { int x = 1; for (int i = 0; i < 4; ++i) x = x * 1664525 + 1013904223; return x; }

int microPairSwap() { pair<int, int> p = {1, 2}; swap(p.first, p.second); return p.first; }

void microCoutLine() { cout << "hello" << endl; }

int microCinRead() { int x = 0; cin >> x; return x; }

// ---------------------------------------------------------------------------
// Fixed-size containers: constant numbers of elements and operations.
// ---------------------------------------------------------------------------

int microPushBackOne() { vector<int> v; v.push_back(7); return v[0]; }

int microPushBackTwo() { vector<int> v; v.push_back(7); v.push_back(8); return v[1]; }

int microPopBack() { vector<int> v = {1, 2, 3}; v.pop_back(); return (int)v.size(); }

int microClearInts() { vector<int> v(5, 1); v.clear(); return (int)v.size(); }

char microStringCharAt() { string s = "hello"; return s[2]; }

char microStringAssignChar() { string s = "hello"; s[0] = 'H'; return s[0]; }

int microDequePush() { deque<int> d; d.push_back(1); d.push_front(2); return d.front(); }

// ---------------------------------------------------------------------------
// Input-sized containers: canonical per-scan and per-query costs.
// ---------------------------------------------------------------------------

long long microSumFor(const vector<int>& v) { long long s = 0; for (int x : v) s += x; return s; }

int microCountEven(const vector<int>& v) { int c = 0; for (int x : v) if (x % 2 == 0) ++c; return c; }

int microMaxScan(const vector<int>& v) { int best = v[0]; for (int x : v) best = max(best, x); return best; }

int microTwoPassCount(const vector<int>& v) { int c = 0; for (int x : v) if (x > 0) ++c; for (int x : v) if (x < 0) --c; return c; }

void microSwapAdjacent(vector<int>& v) { for (int i = 0; i + 1 < (int)v.size(); ++i) swap(v[i], v[i + 1]); }

void microSortVector(vector<int>& v) { sort(v.begin(), v.end()); }

void microReverseVector(vector<int>& v) { reverse(v.begin(), v.end()); }

bool microFindValue(const vector<int>& v, int k) { return find(v.begin(), v.end(), k) != v.end(); }

int microCountValue(const vector<int>& v, int k) { return (int)count(v.begin(), v.end(), k); }

int microMinElement(const vector<int>& v) { return *min_element(v.begin(), v.end()); }

long long microAccumulate(const vector<int>& v) { return accumulate(v.begin(), v.end(), 0LL); }

bool microIsSorted(const vector<int>& v) { for (int i = 1; i < (int)v.size(); ++i) if (v[i] < v[i - 1]) return false; return true; }

int microFirstNegative(const vector<int>& v) { for (int x : v) if (x < 0) return x; return 0; }

void microFillZero(vector<int>& v) { fill(v.begin(), v.end(), 0); }

int microUniqueCount(vector<int>& v) { return (int)(unique(v.begin(), v.end()) - v.begin()); }

int microLowerBound(const vector<int>& v, int k) { return (int)(lower_bound(v.begin(), v.end(), k) - v.begin()); }

bool microBinarySearchValue(const vector<int>& v, int k) { return binary_search(v.begin(), v.end(), k); }

int microGcd(int a, int b) { return gcd(a, b); }

void microReverseString(string& s) { reverse(s.begin(), s.end()); }

void microPrintVectorLine(const vector<int>& v) { for (int x : v) cout << x; }
