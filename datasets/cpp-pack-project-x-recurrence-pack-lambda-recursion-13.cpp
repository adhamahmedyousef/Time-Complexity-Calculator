#include <bits/stdc++.h>
using namespace std;

// nested-recursion-01
long long nestedRecursion_1_1(int n) { if (n <= 1) return 1; return nestedRecursion_1_1(nestedRecursion_1_1(n - 1)); }

// nested-recursion-02
static long long h(int n) { if (n <= 1) return 1; return h(h(n - 1)); } long long nestedRecursion_1_2(int n) { return h(n); }

// nested-recursion-03
struct S { long long run(int n) { if (n <= 1) return 1; return run(run(n - 1)); } }; long long nestedRecursion_1_3(int n) { return S{}.run(n); }

// nested-recursion-04
long long nestedRecursion_1_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, self(self, x - 1)); }; return go(go, n); }

// mutating-recursion-05
int g = 0; long long mutatingRecursion_2_1(int n) { if (n <= 1) return 1; g += n & 1; return mutatingRecursion_2_1(n - 1 + (g & 1)); }

// mutating-recursion-06
static int g = 0; long long mutatingRecursion_2_2(int n) { if (n <= 1) return 1; g += n & 1; return mutatingRecursion_2_2(n - 1 + (g & 1)); }

// mutating-recursion-07
struct S { int g = 0; long long run(int n) { if (n <= 1) return 1; g += n & 1; return run(n - 1 + (g & 1)); } }; long long mutatingRecursion_2_3(int n) { return S{}.run(n); }

// mutating-recursion-08
long long mutatingRecursion_2_4(int n) { auto go = [&](auto&& self, int x)->long long { static int g = 0; if (x <= 1) return 1; g += x & 1; return self(self, x - 1 + (g & 1)); }; return go(go, n); }

// pointer-recursion-09
struct Node { Node* next; int value; }; long long pointerRecursion_3_1(Node* cur) { if (!cur) return 1; return pointerRecursion_3_1(cur->next ? cur->next->next : nullptr) + pointerRecursion_3_1(cur->next); }

// pointer-recursion-10
struct Node { Node* next; int value; }; static long long h(Node* cur) { if (!cur) return 1; return h(cur->next ? cur->next->next : nullptr) + h(cur->next); } long long pointerRecursion_3_2(Node* cur) { return h(cur); }

// pointer-recursion-11
struct Node { Node* next; int value; }; struct S { long long run(Node* cur) { if (!cur) return 1; return run(cur->next ? cur->next->next : nullptr) + run(cur->next); } }; long long pointerRecursion_3_3(Node* cur) { return S{}.run(cur); }

// pointer-recursion-12
struct Node { Node* next; int value; }; long long pointerRecursion_3_4(Node* cur) { auto go = [&](auto&& self, Node* p)->long long { if (!p) return 1; return self(self, p->next ? p->next->next : nullptr) + self(self, p->next); }; return go(go, cur); }

// lambda-recursion-13
long long pack_project_x_recurrence_pack_lambdaRecursion_4_1(int n) { function<long long(int)> f = [&](int x) -> long long { if (x <= 1) return 1; return f(x - 1) + f(x / 2); }; return f(n); }
