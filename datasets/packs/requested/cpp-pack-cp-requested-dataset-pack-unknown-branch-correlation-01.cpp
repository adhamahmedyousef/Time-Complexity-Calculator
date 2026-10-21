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
int pack_cp_requested_dataset_pack_unknownBranchCorrelation_1(const vector<int>& a) {
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
