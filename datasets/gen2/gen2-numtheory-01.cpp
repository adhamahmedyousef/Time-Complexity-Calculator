// Generated family: gen2-numtheory-01
// Labels from first principles.
using namespace std;

bool isPrime_0(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int countPrimes_0(int n) { vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) { if (!comp[i]) { ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; } } return cnt; }
long long modPow_0(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int eulerPhi_0(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
bool isPrime_1(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int countPrimes_1(int n) { vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) { if (!comp[i]) { ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; } } return cnt; }
long long modPow_1(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int eulerPhi_1(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
bool isPrime_2(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int countPrimes_2(int n) { vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) { if (!comp[i]) { ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; } } return cnt; }
long long modPow_2(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int eulerPhi_2(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
bool isPrime_3(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int countPrimes_3(int n) { vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) { if (!comp[i]) { ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; } } return cnt; }
long long modPow_3(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int eulerPhi_3(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
bool isPrime_4(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int countPrimes_4(int n) { vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) { if (!comp[i]) { ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; } } return cnt; }
long long modPow_4(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int eulerPhi_4(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
bool isPrime_5(long long n) { if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }
int countPrimes_5(int n) { vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) { if (!comp[i]) { ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; } } return cnt; }
long long modPow_5(long long b, long long e, long long m) { long long r = 1; b %= m; while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
int eulerPhi_5(int n) { int r = n; for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { while (n % i == 0) n /= i; r -= r / i; } } if (n > 1) r -= r / n; return r; }
