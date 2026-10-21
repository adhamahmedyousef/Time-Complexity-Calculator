// Generated family: gen3-num3-01
// Labels from first principles.
using namespace std;

long long gcdEuclid_0(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_0(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_0(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_0(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_0(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_0(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_0(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_0(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_0(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_0(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_0(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_0(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_1(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_1(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_1(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_1(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_1(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_1(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_1(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_1(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_1(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_1(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_1(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_1(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_2(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_2(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_2(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_2(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_2(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_2(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_2(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_2(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_2(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_2(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_2(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_2(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_3(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_3(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_3(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_3(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_3(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_3(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_3(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_3(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_3(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_3(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_3(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_3(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_4(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_4(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_4(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_4(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_4(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_4(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_4(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_4(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_4(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_4(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_4(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_4(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_5(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_5(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_5(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_5(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_5(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_5(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_5(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_5(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_5(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_5(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_5(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_5(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_6(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_6(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_6(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_6(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_6(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_6(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_6(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_6(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_6(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_6(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_6(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_6(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
long long gcdEuclid_7(long long a, long long b) { while (b != 0) { long long t = a % b; a = b; b = t; } return a; }
long long lcmEuclid_7(long long a, long long b) { long long x = a, y = b; while (y != 0) { long long t = x % y; x = y; y = t; } return a / x * b; }
bool isPrimeTrial_7(long long n) { if (n < 2) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int divisorCount_7(long long n) { int cnt = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n) ? 1 : 2; return cnt; }
long long divisorSum_7(long long n) { long long s = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { s += i; if (i * i != n) s += n / i; } return s; }
long long modPow_7(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
long long modInverse_7(long long b, long long m) { long long e = m - 2, r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int digitSumX_7(int x) { int s = 0; while (x) { s += x % 10; x /= 10; } return s; }
int digitCountX_7(int x) { int c = 0; while (x) { ++c; x /= 10; } return c; }
int reverseNumberX_7(int x) { int r = 0; while (x) { r = r * 10 + x % 10; x /= 10; } return r; }
int binaryDigitCount_7(int x) { int c = 0; while (x) { ++c; x >>= 1; } return c; }
int digitSquareSum_7(int x) { int s = 0; while (x) { int d = x % 10; s += d * d; x /= 10; } return s; }
