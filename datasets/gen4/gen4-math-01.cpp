// Generated family: gen4-math-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long powerExpMod_0(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_0(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_0(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_0(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_0(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_0(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_0(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_1(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_1(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_1(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_1(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_1(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_1(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_1(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_2(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_2(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_2(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_2(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_2(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_2(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_2(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_3(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_3(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_3(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_3(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_3(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_3(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_3(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_4(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_4(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_4(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_4(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_4(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_4(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_4(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_5(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_5(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_5(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_5(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_5(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_5(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_5(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_6(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_6(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_6(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_6(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_6(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_6(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_6(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_7(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_7(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_7(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_7(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_7(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_7(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_7(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_8(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_8(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_8(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_8(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_8(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_8(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_8(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_9(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_9(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_9(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_9(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_9(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_9(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_9(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_10(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_10(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_10(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_10(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_10(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_10(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_10(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_11(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_11(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_11(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_11(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_11(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_11(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_11(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_12(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_12(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_12(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_12(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_12(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_12(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_12(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_13(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_13(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
bool isPerfectSquareBS_13(long long n) { if (n < 0) return false; if (n <= 1) return true; long long lo = 1, hi = n; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid * mid == n) return true; if (mid * mid < n) lo = mid + 1; else hi = mid - 1; } return false; }
long long sumOfDivisorsSqrt_13(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) { if (n % i == 0) { s += i; if (i * i != n) s += n / i; } } return s; }
int countCoprimesTrial_13(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
long long modularFactorial_13(int n, long long m) { long long f = 1; for (int i = 2; i <= n; ++i) f = (f * i) % m; return f; }
bool isPrimeTrial_13(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long powerExpMod_14(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
long long fastMulMod_14(long long a, long long b, long long m) { long long res = 0; a %= m; while (b > 0) { if (b & 1) res = (res + a) % m; a = (a + a) % m; b >>= 1; } return res; }
