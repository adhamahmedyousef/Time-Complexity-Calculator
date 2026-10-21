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


int g8_gcd_10(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_10(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_10(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_10(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_10(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_10(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_10(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_10(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_11(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_11(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_11(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_11(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_11(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_11(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_11(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_11(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_12(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_12(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_12(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_12(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_12(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_12(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_12(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_12(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_13(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_13(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_13(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_13(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_13(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_13(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_13(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_13(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_14(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_14(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_14(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_14(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_14(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_14(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_14(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_14(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
