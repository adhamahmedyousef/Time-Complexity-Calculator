// Generated family: gen5-math-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long modPowExp_20(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_20(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_20(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_20(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_20(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_21(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_21(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_21(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_21(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_21(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_22(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_22(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_22(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_22(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_22(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_23(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_23(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_23(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_23(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_23(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_24(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_24(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_24(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_24(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_24(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_25(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_25(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_25(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_25(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_25(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_26(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_26(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_26(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_26(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_26(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_27(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_27(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_27(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_27(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_27(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_28(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_28(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_28(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_28(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_28(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_29(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_29(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_29(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_29(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_29(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
