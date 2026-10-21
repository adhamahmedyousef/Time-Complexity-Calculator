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


int g8_gcd_5(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_5(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_5(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_5(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_5(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_5(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_5(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_5(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_6(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_6(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_6(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_6(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_6(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_6(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_6(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_6(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_7(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_7(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_7(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_7(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_7(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_7(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_7(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_7(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_8(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_8(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_8(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_8(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_8(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_8(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_8(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_8(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_9(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_9(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_9(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_9(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_9(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_9(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_9(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_9(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
