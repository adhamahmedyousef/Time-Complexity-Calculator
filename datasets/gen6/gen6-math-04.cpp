// Generated family: gen6-math-04
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long powerExpMod_50(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_50(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_50(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_50(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_50(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_50(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_51(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_51(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_51(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_51(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_51(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_51(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_52(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_52(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_52(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_52(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_52(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_52(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_53(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_53(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_53(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_53(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_53(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_53(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_54(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_54(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_54(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_54(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_54(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_54(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_55(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_55(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_55(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_55(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_55(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_55(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_56(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_56(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_56(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_56(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_56(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_56(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_57(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_57(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_57(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_57(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_57(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_57(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_58(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_58(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_58(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_58(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_58(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_58(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_59(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_59(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_59(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_59(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_59(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_59(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_60(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_60(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_60(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_60(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_60(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_60(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_61(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_61(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_61(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_61(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_61(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_61(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_62(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_62(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_62(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_62(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_62(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_62(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_63(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_63(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_63(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_63(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_63(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_63(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_64(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_64(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_64(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_64(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_64(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_64(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_65(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_65(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_65(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_65(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_65(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_65(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_66(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_66(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_66(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_66(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
