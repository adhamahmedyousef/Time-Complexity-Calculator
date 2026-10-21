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


long long fastPowerMod_6(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_6(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_6(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_6(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_6(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_6(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_7(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_7(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_7(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_7(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_7(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_7(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_7(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_7(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_8(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_8(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_8(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_8(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_8(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_8(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_8(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_8(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_9(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_9(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_9(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_9(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_9(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_9(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_9(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_9(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_10(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_10(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_10(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_10(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_10(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_10(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_10(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_10(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_11(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_11(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_11(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_11(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_11(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_11(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_11(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_11(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_12(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_12(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_12(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_12(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
