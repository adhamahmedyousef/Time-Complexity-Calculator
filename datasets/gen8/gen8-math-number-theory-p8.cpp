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


int g8_gcd_35(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_35(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_35(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_35(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_35(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_35(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_35(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_35(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_36(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_36(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_36(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_36(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_36(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_36(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_36(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_36(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_37(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_37(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_37(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_37(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_37(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_37(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_37(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_37(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_38(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_38(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_38(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_38(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_38(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_38(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_38(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_38(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_gcd_39(int a, int b) { while (b != 0) { int t = b; b = a % b; a = t; } return a; }

long long g8_lcm_39(long long a, long long b) { return std::lcm(a, b); }

bool g8_trialPrime_39(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }

int g8_factorCount_39(int n) { int cnt = 0; for (int i = 1; i * i <= n; ++i) if (n % i == 0) cnt += (i * i == n ? 1 : 2); return cnt; }

int g8_modPow_39(int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; }

int g8_sumDigits_39(int n) { int s = 0; while (n > 0) { s += n % 10; n /= 10; } return s; }

int g8_binaryLen_39(int n) { int len = 0; while (n > 0) { len++; n >>= 1; } return len; }

bool g8_trialOdd_39(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
