
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BadHash {
    size_t operator()(int) const noexcept { return 0; }
};

template <class T>
static ll sumVec(const vector<T>& a) {
    ll s = 0;
    for (auto &x : a) s += x;
    return s;
}

static ll stlVectorEraseLoopQuadratic(vector<int> a) {
    ll ops = 0;
    while (!a.empty()) {
        a.erase(a.begin() + (a.size() / 2));
        ++ops;
    }
    return ops;
}

static ll stlRotateInsideLoop(vector<int> a) {
    ll moves = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        rotate(a.begin(), a.begin() + 1, a.end());
        moves += a.size();
    }
    return moves;
}

static ll stlNthElementRepeated(vector<int> a) {
    ll score = 0;
    for (size_t i = 1; i <= a.size(); ++i) {
        nth_element(a.begin(), a.begin() + (i - 1), a.end());
        score += a[i - 1];
    }
    return score;
}

static ll stlDequeMonotonicMax(const vector<int>& a, int k) {
    deque<int> dq;
    ll ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        ans += a[dq.front()];
    }
    return ans;
}

static ll stlListSpliceBlocks(list<int> lst, int blockSize) {
    list<int> tmp;
    ll cnt = 0;
    while (!lst.empty()) {
        auto it = lst.begin();
        for (int i = 0; i < blockSize && it != lst.end(); ++i) ++it;
        tmp.splice(tmp.end(), lst, lst.begin(), it);
        ++cnt;
    }
    return cnt;
}

static ll stlListSortChunks(list<int> lst) {
    lst.sort();
    return (ll)lst.size();
}

static ll stlMultisetMedianMaintenance(const vector<int>& a) {
    multiset<int> lo, hi;
    ll ans = 0;
    for (int x : a) {
        if (lo.empty() || x <= *lo.rbegin()) lo.insert(x); else hi.insert(x);
        if (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            auto it = prev(lo.end());
            lo.erase(it);
        } else if (hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
        ans += *lo.rbegin();
    }
    return ans;
}

static ll stlUnorderedBadHashDistinct(const vector<int>& a) {
    unordered_map<int,int,BadHash> mp;
    for (int x : a) ++mp[x];
    return (ll)mp.size();
}

static ll stlUnorderedBadHashGroupSum(const vector<int>& a) {
    unordered_set<int,BadHash> st;
    for (int x : a) st.insert(x);
    return (ll)st.size();
}

static ll stlPriorityQueueKWayMerge(const vector<vector<int>>& lists) {
    using Node = tuple<int,int,int>; // value, list id, index
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int i = 0; i < (int)lists.size(); ++i) if (!lists[i].empty()) pq.push({lists[i][0], i, 0});
    ll cnt = 0;
    while (!pq.empty()) {
        auto [val, id, idx] = pq.top(); pq.pop();
        cnt += val;
        if (idx + 1 < (int)lists[id].size()) pq.push({lists[id][idx + 1], id, idx + 1});
    }
    return cnt;
}

static ll stlSetIntervalUnion(vector<pair<int,int>> segs) {
    sort(segs.begin(), segs.end());
    set<pair<int,int>> st;
    ll merged = 0;
    for (auto [l, r] : segs) {
        auto it = st.lower_bound({l, -1});
        if (it != st.begin()) {
            auto pit = prev(it);
            if (pit->second >= l) {
                l = min(l, pit->first);
                r = max(r, pit->second);
                st.erase(pit);
            }
        }
        st.insert({l, r});
        ++merged;
    }
    return merged + st.size();
}

static ll stlMapLowerBoundSweep(const vector<int>& a) {
    map<int,int> mp;
    ll ans = 0;
    for (int x : a) {
        auto it = mp.lower_bound(x);
        if (it != mp.end()) ans += it->first;
        ++mp[x];
    }
    return ans;
}

static ll stlHeapLazyDeletion(vector<int> a) {
    priority_queue<int> pq;
    unordered_map<int,int> dead;

    ll ans = 0;
    for (int x : a) pq.push(x);
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        if (dead[x]) { --dead[x]; continue; }
        ans += x;
        if (x % 2 == 0) dead[x/2]++;
    }
    return ans;
}

static ll stlBitsetShiftKnapsack(int W, const vector<int>& a) {
    vector<unsigned long long> bits((W >> 6) + 1);
    bits[0] = 1ULL;
    for (int x : a) {
        int w = x >> 6, b = x & 63;
        vector<unsigned long long> add(bits.size());
        for (size_t i = 0; i < bits.size(); ++i) if (bits[i]) {
            size_t j = i + w;
            if (j < bits.size()) add[j] |= bits[i] << b;
            if (b && j + 1 < bits.size()) add[j + 1] |= bits[i] >> (64 - b);
        }
        for (size_t i = 0; i < bits.size(); ++i) bits[i] |= add[i];
    }
    ll cnt = 0;
    for (int s = 0; s <= W; ++s) if (bits[s >> 6] & (1ULL << (s & 63))) ++cnt;
    return cnt;
}

static ll stlRemoveErasePattern(vector<int> a) {
    a.erase(remove_if(a.begin(), a.end(), [](int x){ return x % 3 == 0; }), a.end());
    return (ll)a.size();
}

static ll stlUniqueEraseSorted(vector<int> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return (ll)a.size();
}

static ll stlStablePartitionChain(vector<int> a) {
    stable_partition(a.begin(), a.end(), [](int x){ return x % 2 == 0; });
    stable_partition(a.begin(), a.end(), [](int x){ return x % 3 == 0; });
    return (ll)a.size();
}

static ll stlForwardListEraseAfter(forward_list<int> fl) {
    ll cnt = 0;
    auto before = fl.before_begin();
    while (next(before) != fl.end()) {
        if (*next(before) % 2 == 0) fl.erase_after(before);
        else { ++before; ++cnt; }
    }
    return cnt;
}

static ll stlVectorLowerBoundSweep(vector<int> a) {
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int x : a) ans += lower_bound(a.begin(), a.end(), x) - a.begin();
    return ans;
}

static ll stlDequeEndsStress(int n) {
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        dq.push_back(i);
        if (i % 2) dq.push_front(-i);
    }
    ll ans = 0;
    while (!dq.empty()) {
        ans += dq.front();
        dq.pop_front();
    }
    return ans;
}

static ll stlMultimapSweepLine(vector<pair<int,int>> events) {
    multimap<int,int> mp;
    for (auto [x, t] : events) mp.insert({x, t});
    ll ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) ans += it->first;
    return ans;
}

static ll stlIteratorInvalidationUnknown(vector<int> a) {
    vector<int> v = a;
    ll ans = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        ans += *it;
        if ((*it) % 2 == 0) v.push_back(*it);
    }
    return ans;
}

static ll stlCallbackComparatorUnknown(vector<int> a, function<bool(int,int)> cmp) {
    sort(a.begin(), a.end(), cmp);
    return (ll)a.size();
}

static ll stlHigherOrderTraversalUnknown(const vector<int>& a, function<int(int)> f) {
    ll ans = 0;
    for (int x : a) ans += f(x);
    return ans;
}

static ll stlUnorderedCollisionChain(const vector<int>& a) {
    unordered_map<int,int,BadHash> mp;
    ll ans = 0;
    for (int x : a) ans += ++mp[x];
    return ans;
}

ll stlCaseVectorEraseLoopQuadratic(vector<int> a) { return stlVectorEraseLoopQuadratic(a); }

ll stlCaseRotateInsideLoop(vector<int> a) { return stlRotateInsideLoop(a); }

ll stlCaseNthElementRepeated(vector<int> a) { return stlNthElementRepeated(a); }

ll stlCaseDequeMonotonicMax(vector<int> a, int k) { return stlDequeMonotonicMax(a, k); }

ll stlCaseListSpliceBlocks(list<int> lst, int blockSize) { return stlListSpliceBlocks(move(lst), blockSize); }

ll stlCaseListSortChunks(list<int> lst) { return stlListSortChunks(move(lst)); }

ll stlCaseMultisetMedianMaintenance(vector<int> a) { return stlMultisetMedianMaintenance(a); }

ll stlCaseUnorderedBadHashDistinct(vector<int> a) { return stlUnorderedBadHashDistinct(a); }

ll stlCaseUnorderedBadHashGroupSum(vector<int> a) { return stlUnorderedBadHashGroupSum(a); }

ll stlCasePriorityQueueKWayMerge(vector<vector<int>> lists) { return stlPriorityQueueKWayMerge(lists); }

ll stlCaseSetIntervalUnion(vector<pair<int,int>> segs) { return stlSetIntervalUnion(segs); }

ll stlCaseMapLowerBoundSweep(vector<int> a) { return stlMapLowerBoundSweep(a); }

ll stlCaseHeapLazyDeletion(vector<int> a) { return stlHeapLazyDeletion(a); }

ll stlCaseBitsetShiftKnapsack(int W, vector<int> a) { return stlBitsetShiftKnapsack(W, a); }

ll stlCaseRemoveErasePattern(vector<int> a) { return stlRemoveErasePattern(a); }

ll stlCaseUniqueEraseSorted(vector<int> a) { return stlUniqueEraseSorted(a); }

ll stlCaseStablePartitionChain(vector<int> a) { return stlStablePartitionChain(a); }

ll stlCaseForwardListEraseAfter(forward_list<int> fl) { return stlForwardListEraseAfter(move(fl)); }

ll stlCaseVectorLowerBoundSweep(vector<int> a) { return stlVectorLowerBoundSweep(a); }


ll stlCaseDequeEndsStress(int n) { return stlDequeEndsStress(n); }

ll stlCaseMultimapSweepLine(vector<pair<int,int>> events) { return stlMultimapSweepLine(events); }

ll stlCaseIteratorInvalidationUnknown(vector<int> a) { return stlIteratorInvalidationUnknown(a); }

ll stlCaseCallbackComparatorUnknown(vector<int> a, function<bool(int,int)> cmp) { return stlCallbackComparatorUnknown(a, cmp); }

ll stlCaseHigherOrderTraversalUnknown(const vector<int>& a, function<int(int)> f) { return stlHigherOrderTraversalUnknown(a, f); }

ll stlCaseUnorderedCollisionChain(const vector<int>& a) { return stlUnorderedCollisionChain(a); }

