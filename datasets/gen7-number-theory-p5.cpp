#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int gcdEuclidModulo_25(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_25(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_25(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_25(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_25(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_25(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_25(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_25(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_26(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_26(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_26(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_26(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_26(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_26(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_26(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_26(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_27(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_27(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_27(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_27(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_27(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_27(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_27(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_27(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_28(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_28(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_28(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_28(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_28(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_28(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_28(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_28(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_29(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_29(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_29(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_29(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_29(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_29(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_29(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_29(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_30(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_30(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_30(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_30(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_30(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_30(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_30(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_30(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_31(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_31(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }
