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


vector<int> sieveOfEratosthenes_18(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_18(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_19(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_19(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_19(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_19(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_19(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_19(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_19(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_19(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_20(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_20(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_20(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_20(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_20(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_20(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_20(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_20(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_21(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_21(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_21(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_21(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_21(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_21(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_21(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_21(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_22(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_22(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_22(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_22(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_22(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_22(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_22(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_22(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_23(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_23(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_23(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_23(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_23(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_23(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_23(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_23(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_24(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_24(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_24(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_24(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_24(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_24(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_24(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_24(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }
