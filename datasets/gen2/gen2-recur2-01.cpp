// Generated family: gen2-recur2-01
// Labels from first principles.
using namespace std;

void hanoi_0(int n, char from, char to, char aux) { if (n == 0) return; hanoi_0(n - 1, from, aux, to); hanoi_0(n - 1, aux, to, from); }
long long fastPow_0(long long base, int exp) { if (exp == 0) return 1; long long half = fastPow_0(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }
long long permCount_0(int n) { if (n <= 1) return 1; return n * permCount_0(n - 1); }
void hanoi_1(int n, char from, char to, char aux) { if (n == 0) return; hanoi_1(n - 1, from, aux, to); hanoi_1(n - 1, aux, to, from); }
long long fastPow_1(long long base, int exp) { if (exp == 0) return 1; long long half = fastPow_1(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }
long long permCount_1(int n) { if (n <= 1) return 1; return n * permCount_1(n - 1); }
void hanoi_2(int n, char from, char to, char aux) { if (n == 0) return; hanoi_2(n - 1, from, aux, to); hanoi_2(n - 1, aux, to, from); }
long long fastPow_2(long long base, int exp) { if (exp == 0) return 1; long long half = fastPow_2(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }
long long permCount_2(int n) { if (n <= 1) return 1; return n * permCount_2(n - 1); }
void hanoi_3(int n, char from, char to, char aux) { if (n == 0) return; hanoi_3(n - 1, from, aux, to); hanoi_3(n - 1, aux, to, from); }
long long fastPow_3(long long base, int exp) { if (exp == 0) return 1; long long half = fastPow_3(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }
long long permCount_3(int n) { if (n <= 1) return 1; return n * permCount_3(n - 1); }
void hanoi_4(int n, char from, char to, char aux) { if (n == 0) return; hanoi_4(n - 1, from, aux, to); hanoi_4(n - 1, aux, to, from); }
long long fastPow_4(long long base, int exp) { if (exp == 0) return 1; long long half = fastPow_4(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }
long long permCount_4(int n) { if (n <= 1) return 1; return n * permCount_4(n - 1); }
void hanoi_5(int n, char from, char to, char aux) { if (n == 0) return; hanoi_5(n - 1, from, aux, to); hanoi_5(n - 1, aux, to, from); }
long long fastPow_5(long long base, int exp) { if (exp == 0) return 1; long long half = fastPow_5(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }
long long permCount_5(int n) { if (n <= 1) return 1; return n * permCount_5(n - 1); }
