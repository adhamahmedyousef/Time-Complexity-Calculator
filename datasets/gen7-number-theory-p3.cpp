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


int countDivisorsSqrt_12(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_12(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_12(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_12(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_13(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_13(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_13(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_13(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_13(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_13(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_13(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_13(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_14(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_14(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_14(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_14(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_14(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_14(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_14(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_14(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_15(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_15(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_15(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_15(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_15(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_15(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_15(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_15(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_16(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_16(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_16(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_16(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_16(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_16(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_16(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_16(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_17(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_17(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_17(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_17(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_17(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_17(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_17(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_17(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_18(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_18(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_18(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_18(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_18(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_18(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
