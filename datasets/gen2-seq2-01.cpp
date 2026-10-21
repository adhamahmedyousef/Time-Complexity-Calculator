// Generated family: gen2-seq2-01
// Labels from first principles.
using namespace std;

long long threePhase_0(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }
long long mixedLoops_0(int n) { long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 1; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }
long long threePhase_1(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }
long long mixedLoops_1(int n) { long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 1; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }
long long threePhase_2(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }
long long mixedLoops_2(int n) { long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 1; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }
long long threePhase_3(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }
long long mixedLoops_3(int n) { long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 1; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }
long long threePhase_4(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }
long long mixedLoops_4(int n) { long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 1; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }
long long threePhase_5(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }
long long mixedLoops_5(int n) { long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 1; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }
