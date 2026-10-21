#include <bits/stdc++.h>
using namespace std;

// unknown-pointer-chasing-01
struct Node { Node* next; int val; };
int pack_cp_requested_dataset_pack_unknownPointerChasing_1(Node* cur) {
    int steps = 0;
    while (cur) {
        if (cur->val & 1) cur = cur->next;
        else cur = cur->next ? cur->next->next : nullptr;
        ++steps;
    }
    return steps;
}
