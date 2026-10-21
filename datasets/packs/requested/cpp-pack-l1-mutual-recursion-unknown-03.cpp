#include <bits/stdc++.h>
using namespace std;

int b(int);
        int a(int n) { if (n <= 0) return 1; return b(n - 1) + 1; }
        int b(int n) { if (n <= 0) return 1; return a(n - 1) + 1; }
        int pack_l1_mutualRecursionUnknown(int n) { return a(n); }
