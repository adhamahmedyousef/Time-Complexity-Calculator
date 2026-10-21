// Generated family: gen6-math-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int countCoprimesTrial_16(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_16(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_17(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_17(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_17(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_17(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_17(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_17(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_18(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_18(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_18(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_18(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_18(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_18(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_19(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_19(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_19(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_19(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_19(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_19(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_20(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_20(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_20(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_20(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_20(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_20(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_21(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_21(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_21(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_21(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_21(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_21(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_22(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_22(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_22(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_22(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_22(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_22(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_23(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_23(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_23(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_23(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_23(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_23(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_24(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_24(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_24(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_24(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_24(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_24(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_25(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_25(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_25(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_25(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_25(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_25(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_26(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_26(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_26(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_26(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_26(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_26(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_27(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_27(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_27(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_27(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_27(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_27(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_28(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_28(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_28(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_28(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_28(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_28(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_29(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_29(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_29(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_29(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_29(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_29(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_30(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_30(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_30(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_30(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_30(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_30(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_31(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_31(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_31(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_31(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_31(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_31(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_32(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_32(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_32(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_32(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_32(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_32(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_33(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_33(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
