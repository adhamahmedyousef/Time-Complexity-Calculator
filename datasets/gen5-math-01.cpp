// Generated family: gen5-math-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long modPowExp_0(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_0(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_0(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_0(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_0(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_1(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_1(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_1(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_1(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_1(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_2(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_2(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_2(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_2(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_2(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_3(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_3(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_3(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_3(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_3(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_4(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_4(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_4(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_4(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_4(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_5(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_5(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_5(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_5(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_5(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_6(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_6(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_6(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_6(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_6(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_7(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_7(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_7(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_7(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_7(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_8(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_8(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_8(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_8(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_8(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_9(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_9(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_9(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_9(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_9(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_10(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_10(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_10(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_10(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_10(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_11(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_11(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_11(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_11(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_11(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_12(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_12(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_12(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_12(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_12(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_13(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_13(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_13(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_13(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_13(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_14(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_14(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_14(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_14(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_14(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_15(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_15(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_15(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_15(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_15(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_16(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_16(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_16(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_16(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_16(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_17(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_17(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_17(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_17(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_17(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_18(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_18(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_18(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_18(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_18(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
long long modPowExp_19(long long base, long long exp, long long mod) { long long res = 1; base %= mod; while (exp > 0) { if (exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
int sievePrimeCount_19(int n) { if (n < 2) return 0; vector<bool> isPrime(n + 1, true); isPrime[0] = isPrime[1] = false; for (int p = 2; p * p <= n; ++p) if (isPrime[p]) for (int i = p * p; i <= n; i += p) isPrime[i] = false; int count = 0; for (int i = 2; i <= n; ++i) if (isPrime[i]) ++count; return count; }
bool isPrimeTrialDivision_19(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
long long sumProperDivisors_19(long long n) { long long sum = 0; for (long long i = 1; i * i <= n; ++i) if (n % i == 0) { sum += i; if (i * i != n && i != 1) sum += n / i; } return sum; }
int eulerTotientPhi_19(int n) { int result = n; for (int i = 2; i * i <= n; ++i) if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } if (n > 1) result -= result / n; return result; }
