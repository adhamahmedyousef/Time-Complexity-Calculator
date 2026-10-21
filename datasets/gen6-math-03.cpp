// Generated family: gen6-math-03
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool isPrimeTrial_33(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_33(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_33(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_33(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_34(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_34(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_34(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_34(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_34(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_34(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_35(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_35(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_35(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_35(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_35(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_35(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_36(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_36(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_36(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_36(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_36(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_36(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_37(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_37(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_37(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_37(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_37(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_37(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_38(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_38(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_38(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_38(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_38(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_38(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_39(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_39(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_39(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_39(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_39(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_39(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_40(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_40(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_40(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_40(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_40(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_40(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_41(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_41(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_41(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_41(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_41(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_41(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_42(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_42(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_42(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_42(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_42(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_42(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_43(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_43(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_43(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_43(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_43(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_43(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_44(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_44(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_44(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_44(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_44(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_44(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_45(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_45(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_45(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_45(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_45(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_45(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_46(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_46(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_46(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_46(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_46(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_46(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_47(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_47(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_47(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_47(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_47(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_47(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_48(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_48(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_48(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_48(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_48(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_48(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
long long powerExpMod_49(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_49(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPrimeTrial_49(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumOfDivisorsSqrt_49(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_49(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
int sievePrimeCount_49(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
