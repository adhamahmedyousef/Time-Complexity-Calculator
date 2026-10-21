#include <bits/stdc++.h>
using namespace std;

struct Node { Node* next; int val; };
        int pack_l1_pointerChasingLoop(Node* cur) {
            int steps = 0;
            while (cur) {
                cur = cur->next;
                ++steps;
            }
            return steps;
        }
