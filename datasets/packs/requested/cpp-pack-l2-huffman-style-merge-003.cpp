#include <bits/stdc++.h>
using namespace std;

long long pack_l2_huffmanStyleMerge(vector<int> w) {
    priority_queue<int, vector<int>, greater<int>> pq(w.begin(), w.end());
    long long cost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}
