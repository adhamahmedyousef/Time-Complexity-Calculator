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


int g8_gcd_25(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_25(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_25(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_25(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_25(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_25(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_25(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_25(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_26(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_26(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_26(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_26(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_26(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_26(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_26(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_26(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_27(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_27(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_27(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_27(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_27(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_27(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_27(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_27(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_28(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_28(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_28(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_28(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_28(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_28(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_28(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_28(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_29(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_29(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_29(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_29(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_29(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_29(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_29(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_29(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
