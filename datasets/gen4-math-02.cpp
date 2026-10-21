// Generated family: gen4-math-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool isPerfectSquareBS_14(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_14(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_14(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_14(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_14(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_15(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_15(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_15(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_15(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_15(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_15(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_15(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_16(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_16(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_16(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_16(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_16(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_16(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_16(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_17(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_17(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_17(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_17(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_17(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_17(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_17(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_18(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_18(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_18(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_18(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_18(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_18(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_18(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_19(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_19(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_19(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_19(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_19(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_19(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_19(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
