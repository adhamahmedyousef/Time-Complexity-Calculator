#include <bits/stdc++.h>
using namespace std;

// helper-prepass-plus-recursion-01
static long long prep(int n) { long long sum = 0; for (int i = 0; i < n; ++i) sum += i; return sum; } long long pack_project_x_recurrence_pack_helperPrepassRec_1_1(int n) { if (n <= 1) return 1; return prep(n) + pack_project_x_recurrence_pack_helperPrepassRec_1_1(n / 2); }
