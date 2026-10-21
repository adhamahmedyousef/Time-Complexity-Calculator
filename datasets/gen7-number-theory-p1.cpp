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


int gcdEuclidModulo_0(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_0(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_0(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_0(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_0(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_0(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_0(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_0(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_1(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_1(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_1(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_1(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_1(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_1(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_1(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_1(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_2(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_2(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_2(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_2(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_2(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_2(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_2(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_2(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_3(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_3(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_3(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_3(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_3(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_3(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_3(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_3(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_4(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_4(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_4(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_4(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_4(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_4(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_4(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_4(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_5(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_5(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }

long long fastPowerMod_5(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

bool isPrimeTrialDivision_5(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int countDivisorsSqrt_5(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { cnt += (i * i == n) ? 1 : 2; } } return cnt; }

long long sumDivisorsSqrt_5(int n) { long long s = 0; for (int i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }

vector<int> sieveOfEratosthenes_5(int n) { vector<int> prime(n + 1, 1); prime[0] = prime[1] = 0; for (int p = 2; p * p <= n; ++p) { if (prime[p]) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime; }

vector<int> smallestPrimeFactorSieve_5(int n) { vector<int> spf(n + 1); for (int i = 1; i <= n; ++i) spf[i] = i; for (int i = 2; i * i <= n; ++i) { if (spf[i] == i) { for (int j = i * i; j <= n; j += i) if (spf[j] == j) spf[j] = i; } } return spf; }

int gcdEuclidModulo_6(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }

long long lcmEuclid_6(int a, int b) { int x = a, y = b; while (y) { x %= y; swap(x, y); } return (static_cast<long long>(a) / x) * b; }
