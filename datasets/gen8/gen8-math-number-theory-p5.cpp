#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int g8_gcd_20(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_20(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_20(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_20(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_20(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_20(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_20(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_20(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_21(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_21(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_21(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_21(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_21(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_21(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_21(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_21(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_22(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_22(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_22(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_22(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_22(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_22(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_22(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_22(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_23(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_23(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_23(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_23(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_23(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_23(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_23(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_23(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_24(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_24(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_24(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_24(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_24(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_24(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_24(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_24(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
