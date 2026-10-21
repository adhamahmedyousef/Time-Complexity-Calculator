#include <bits/stdc++.h>
using namespace std;

struct Box { vector<int> v; };
        void touch(Box& b) { b.v.push_back((int)b.v.size()); }
        long long pack_l1_aliasHeavyFieldMutation(Box& b) {
            for (int i = 0; i < 10; ++i) touch(b);
            return b.v.size();
        }
