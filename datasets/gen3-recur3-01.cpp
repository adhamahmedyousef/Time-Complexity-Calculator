// Generated family: gen3-recur3-01
// Labels from first principles.
using namespace std;

long long factorialRec_0(int n) { if (n <= 1) return 1; return n * factorialRec_0(n - 1); }
long long powerRec_0(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_0(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_0(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_0(n / 10); }
long long sumArrayRec_0(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_0(a, i + 1); }
long long fibBranch_0(int n) { if (n <= 1) return n; return fibBranch_0(n - 1) + fibBranch_0(n - 2); }
long long tribBranch_0(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_0(n - 1) + tribBranch_0(n - 2) + tribBranch_0(n - 3); }
void hanoiRec_0(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_0(n - 1, from, via, to); hanoiRec_0(n - 1, via, to, from); }
long long binaryStringsRec_0(int n) { if (n == 0) return 1; return binaryStringsRec_0(n - 1) + binaryStringsRec_0(n - 1); }
long long binomialRec_0(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_0(n - 1, k - 1) + binomialRec_0(n - 1, k); }
long long factorialRec_1(int n) { if (n <= 1) return 1; return n * factorialRec_1(n - 1); }
long long powerRec_1(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_1(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_1(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_1(n / 10); }
long long sumArrayRec_1(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_1(a, i + 1); }
long long fibBranch_1(int n) { if (n <= 1) return n; return fibBranch_1(n - 1) + fibBranch_1(n - 2); }
long long tribBranch_1(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_1(n - 1) + tribBranch_1(n - 2) + tribBranch_1(n - 3); }
void hanoiRec_1(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_1(n - 1, from, via, to); hanoiRec_1(n - 1, via, to, from); }
long long binaryStringsRec_1(int n) { if (n == 0) return 1; return binaryStringsRec_1(n - 1) + binaryStringsRec_1(n - 1); }
long long binomialRec_1(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_1(n - 1, k - 1) + binomialRec_1(n - 1, k); }
long long factorialRec_2(int n) { if (n <= 1) return 1; return n * factorialRec_2(n - 1); }
long long powerRec_2(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_2(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_2(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_2(n / 10); }
long long sumArrayRec_2(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_2(a, i + 1); }
long long fibBranch_2(int n) { if (n <= 1) return n; return fibBranch_2(n - 1) + fibBranch_2(n - 2); }
long long tribBranch_2(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_2(n - 1) + tribBranch_2(n - 2) + tribBranch_2(n - 3); }
void hanoiRec_2(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_2(n - 1, from, via, to); hanoiRec_2(n - 1, via, to, from); }
long long binaryStringsRec_2(int n) { if (n == 0) return 1; return binaryStringsRec_2(n - 1) + binaryStringsRec_2(n - 1); }
long long binomialRec_2(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_2(n - 1, k - 1) + binomialRec_2(n - 1, k); }
long long factorialRec_3(int n) { if (n <= 1) return 1; return n * factorialRec_3(n - 1); }
long long powerRec_3(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_3(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_3(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_3(n / 10); }
long long sumArrayRec_3(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_3(a, i + 1); }
long long fibBranch_3(int n) { if (n <= 1) return n; return fibBranch_3(n - 1) + fibBranch_3(n - 2); }
long long tribBranch_3(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_3(n - 1) + tribBranch_3(n - 2) + tribBranch_3(n - 3); }
void hanoiRec_3(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_3(n - 1, from, via, to); hanoiRec_3(n - 1, via, to, from); }
long long binaryStringsRec_3(int n) { if (n == 0) return 1; return binaryStringsRec_3(n - 1) + binaryStringsRec_3(n - 1); }
long long binomialRec_3(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_3(n - 1, k - 1) + binomialRec_3(n - 1, k); }
long long factorialRec_4(int n) { if (n <= 1) return 1; return n * factorialRec_4(n - 1); }
long long powerRec_4(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_4(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_4(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_4(n / 10); }
long long sumArrayRec_4(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_4(a, i + 1); }
long long fibBranch_4(int n) { if (n <= 1) return n; return fibBranch_4(n - 1) + fibBranch_4(n - 2); }
long long tribBranch_4(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_4(n - 1) + tribBranch_4(n - 2) + tribBranch_4(n - 3); }
void hanoiRec_4(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_4(n - 1, from, via, to); hanoiRec_4(n - 1, via, to, from); }
long long binaryStringsRec_4(int n) { if (n == 0) return 1; return binaryStringsRec_4(n - 1) + binaryStringsRec_4(n - 1); }
long long binomialRec_4(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_4(n - 1, k - 1) + binomialRec_4(n - 1, k); }
long long factorialRec_5(int n) { if (n <= 1) return 1; return n * factorialRec_5(n - 1); }
long long powerRec_5(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_5(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_5(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_5(n / 10); }
long long sumArrayRec_5(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_5(a, i + 1); }
long long fibBranch_5(int n) { if (n <= 1) return n; return fibBranch_5(n - 1) + fibBranch_5(n - 2); }
long long tribBranch_5(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_5(n - 1) + tribBranch_5(n - 2) + tribBranch_5(n - 3); }
void hanoiRec_5(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_5(n - 1, from, via, to); hanoiRec_5(n - 1, via, to, from); }
long long binaryStringsRec_5(int n) { if (n == 0) return 1; return binaryStringsRec_5(n - 1) + binaryStringsRec_5(n - 1); }
long long binomialRec_5(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_5(n - 1, k - 1) + binomialRec_5(n - 1, k); }
long long factorialRec_6(int n) { if (n <= 1) return 1; return n * factorialRec_6(n - 1); }
long long powerRec_6(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_6(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_6(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_6(n / 10); }
long long sumArrayRec_6(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_6(a, i + 1); }
long long fibBranch_6(int n) { if (n <= 1) return n; return fibBranch_6(n - 1) + fibBranch_6(n - 2); }
long long tribBranch_6(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_6(n - 1) + tribBranch_6(n - 2) + tribBranch_6(n - 3); }
void hanoiRec_6(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_6(n - 1, from, via, to); hanoiRec_6(n - 1, via, to, from); }
long long binaryStringsRec_6(int n) { if (n == 0) return 1; return binaryStringsRec_6(n - 1) + binaryStringsRec_6(n - 1); }
long long binomialRec_6(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_6(n - 1, k - 1) + binomialRec_6(n - 1, k); }
long long factorialRec_7(int n) { if (n <= 1) return 1; return n * factorialRec_7(n - 1); }
long long powerRec_7(long long b, long long e) { if (e == 0) return 1; long long half = powerRec_7(b, e / 2); long long sq = half * half; return (e % 2 == 0) ? sq : sq * b; }
int digitSumRec_7(int n) { if (n == 0) return 0; return n % 10 + digitSumRec_7(n / 10); }
long long sumArrayRec_7(const vector<int>& a, int i) { if (i >= (int)a.size()) return 0; return a[i] + sumArrayRec_7(a, i + 1); }
long long fibBranch_7(int n) { if (n <= 1) return n; return fibBranch_7(n - 1) + fibBranch_7(n - 2); }
long long tribBranch_7(int n) { if (n <= 1) return n; if (n == 2) return 1; return tribBranch_7(n - 1) + tribBranch_7(n - 2) + tribBranch_7(n - 3); }
void hanoiRec_7(int n, int from, int to, int via) { if (n == 0) return; hanoiRec_7(n - 1, from, via, to); hanoiRec_7(n - 1, via, to, from); }
long long binaryStringsRec_7(int n) { if (n == 0) return 1; return binaryStringsRec_7(n - 1) + binaryStringsRec_7(n - 1); }
long long binomialRec_7(int n, int k) { if (k == 0 || k == n) return 1; return binomialRec_7(n - 1, k - 1) + binomialRec_7(n - 1, k); }
