#include <bits/stdc++.h>
using namespace std;

// unknown-pointer-chasing-01
struct Node { Node* next; int val; };
int unknownPointerChasing_1(Node* cur) {
    int steps = 0;
    while (cur) {
        if (cur->val & 1) cur = cur->next;
        else cur = cur->next ? cur->next->next : nullptr;
        ++steps;
    }
    return steps;
}

// unknown-branch-correlation-01
int unknownBranchCorrelation_1(const vector<int>& a) {
    int i = 0, j = (int)a.size() - 1, score = 0;
    while (i < j) {
        if (a[i] + a[j] > 0) {
            if ((a[i] ^ a[j]) & 1) return score;
            ++i;
        } else {
            --j;
        }
        ++score;
    }
    return score;
}

// unknown-template-macro-01
#define STEP(x) do { if ((x) & 1) (x) += 3; else (x) >>= 1; } while (0)
template<class T>
int unknownTemplateMacro_1(T n) {
    int x = (int)n, cnt = 0;
    while (x > 0) {
        STEP(x);
        if (++cnt > 100000) break;
    }
    return cnt;
}

// unknown-external-call-01
void externalWork(vector<int>&);
int pack_cp_requested_dataset_pack_unknownExternalCall_1(vector<int>& a) {
    for (int i = 0; i < (int)a.size(); ++i) externalWork(a);
    return (int)a.size();
}
