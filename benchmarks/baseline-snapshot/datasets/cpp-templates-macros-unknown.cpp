
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define TMPL_FOR(i, n) for (int i = 0; i < (n); ++i)
#define TMPL_REPEAT(i, l, r) for (int i = (l); i < (r); ++i)

template <class T>
static ll tmplSumVector(const vector<T>& a) {
    ll s = 0;
    for (const auto& x : a) s += x;
    return s;
}

template <class T, class Cmp>
static vector<T> tmplSortedCopy(vector<T> a, Cmp cmp) {
    sort(a.begin(), a.end(), cmp);
    return a;
}

template <class T>
static ll tmplLowerBoundSweep(vector<T> a) {
    sort(a.begin(), a.end());
    ll ans = 0;
    for (const auto& x : a) ans += lower_bound(a.begin(), a.end(), x) - a.begin();
    return ans;
}

template <class T>
static ll tmplWindowMaxSum(const vector<T>& a, int k) {
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

static ll tmplBitsetReachable(int W, const vector<int>& a) {
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

static ll tmplTreeRerootSum(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<int> sz(n);
    vector<ll> down(n), ans(n);
    function<void(int,int)> dfs1 = [&](int u, int p) {
        sz[u] = 1;
        for (int v : g[u]) if (v != p) {
            dfs1(v, u);
            sz[u] += sz[v];
            down[u] += down[v] + sz[v];
        }
    };
    function<void(int,int)> dfs2 = [&](int u, int p) {
        ans[u] = down[u];
        for (int v : g[u]) if (v != p) {
            ll ou = down[u], ov = down[v];
            int su = sz[u], sv = sz[v];
            down[u] -= down[v] + sz[v];
            sz[u] -= sz[v];
            down[v] += down[u] + sz[u];
            sz[v] += sz[u];
            dfs2(v, u);
            down[u] = ou; down[v] = ov;
            sz[u] = su; sz[v] = sv;
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    return accumulate(ans.begin(), ans.end(), 0LL);
}

static ll tmplPriorityQueueMerge(const vector<vector<int>>& lists) {
    using Node = tuple<int,int,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int i = 0; i < (int)lists.size(); ++i) if (!lists[i].empty()) pq.push({lists[i][0], i, 0});
    ll ans = 0;
    while (!pq.empty()) {
        auto [v, id, idx] = pq.top(); pq.pop();
        ans += v;
        if (idx + 1 < (int)lists[id].size()) pq.push({lists[id][idx + 1], id, idx + 1});
    }
    return ans;
}

template <int N>
static array<int, N> tmplCompileTimeTransform(const array<int, N>& a) {
    array<int, N> b{};
    TMPL_FOR(i, N) b[i] = a[i] * 2 + i;
    return b;
}

static ll tmplMacroNestedLoopCount(int n, int m) {
    ll cnt = 0;
    TMPL_FOR(i, n) TMPL_FOR(j, m) cnt += (i ^ j) & 1;
    return cnt;
}

static ll tmplMacroPrefixScan(const vector<int>& a) {
    ll pref = 0, ans = 0;
    for (int x : a) { pref += x; ans += pref; }
    return ans;
}

static ll tmplTemplateMapAggregation(const vector<int>& a) {
    map<int,int> mp;
    for (int x : a) ++mp[x];
    ll ans = 0;
    for (auto [k, v] : mp) ans += 1LL * k * v;
    return ans;
}

static ll tmplTemplateSetUnionSweep(vector<pair<int,int>> segs) {
    sort(segs.begin(), segs.end());
    set<pair<int,int>> s;
    for (auto [l, r] : segs) {
        auto it = s.lower_bound({l, -1});
        if (it != s.begin()) {
            auto pit = prev(it);
            if (pit->second >= l) {
                l = min(l, pit->first);
                r = max(r, pit->second);
                s.erase(pit);
            }
        }
        s.insert({l, r});
    }
    return (ll)s.size();
}


static ll tmplGenericFenwick(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> bit(n + 1);
    auto add = [&](int i, int v) { for (++i; i <= n; i += i & -i) bit[i] += v; };
    auto sum = [&](int i) { int s = 0; for (++i; i > 0; i -= i & -i) s += bit[i]; return s; };
    for (int i = 0; i < n; ++i) add(i, a[i]);
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += sum(i);
    return ans;
}

static ll tmplGenericStablePartition(vector<int> a) {
    stable_partition(a.begin(), a.end(), [](int x) { return x % 2 == 0; });
    return (ll)a.size();
}

static ll tmplGenericDequeWindow(const vector<int>& a, int k) {
    return tmplWindowMaxSum(a, k);
}

static ll tmplRecursiveLambdaMemo(int n) {
    vector<ll> memo(n + 1, -1);
    function<ll(int)> f = [&](int x) -> ll {
        if (x <= 1) return 1;
        ll &res = memo[x];
        if (res != -1) return res;
        return res = f(x - 1) + f(x - 2);
    };
    return f(n);
}

static ll tmplYCombinatorTreeDP(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<ll> dp0(n), dp1(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        dp1[u] = 1;
        for (int v : g[u]) if (v != p) {
            dfs(v, u);
            dp0[u] += max(dp0[v], dp1[v]);
            dp1[u] += dp0[v];
        }
    };
    dfs(0, -1);
    return max(dp0[0], dp1[0]);
}

static ll tmplCallbackBfsUnknown(const vector<vector<int>>& g, function<bool(int)> stop) {
    queue<int> q;
    vector<int> vis(g.size());
    q.push(0);
    vis[0] = 1;
    ll seen = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ++seen;
        if (stop(u)) break;
        for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v);
    }
    return seen;
}

static ll tmplFunctionPointerUnknown(const vector<int>& a, int (*f)(int)) {
    ll ans = 0;
    for (int x : a) ans += f(x);
    return ans;
}

static ll tmplLambdaCaptureUnknown(const vector<int>& a) {
    int bias = (int)a.size();
    auto f = [&](int x) { return x + bias + (rand() & 1); };
    ll ans = 0;
    for (int x : a) ans += f(x);
    return ans;
}

static ll tmplAliasMutationUnknown(vector<int>& a, vector<int>& b) {
    int* p = a.data();
    int* q = b.data();
    ll ans = 0;
    for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
        p[i] += q[i];
        ans += p[i];
    }
    return ans;
}

static ll tmplRuntimeDispatchUnknown(const vector<int>& a, int mode) {
    switch (mode) {
        case 0: return accumulate(a.begin(), a.end(), 0LL);
        case 1: return (ll)count_if(a.begin(), a.end(), [](int x){ return x % 2 == 0; });
        default: return (ll)a.size() * mode;
    }
}

static ll tmplMoveOnlyFunctorUnknown(vector<int> a) {
    unique_ptr<int> p = make_unique<int>((int)a.size());
    auto f = [q = move(p)](int x) mutable { return x + *q; };
    ll ans = 0;
    for (int x : a) ans += f(x);
    return ans;
}

static ll tmplPointerToMemberUnknown(vector<int> a) {
    struct S { int x; int inc() { return ++x; } };
    S s{(int)a.size()};
    int (S::*pmf)() = &S::inc;
    ll ans = 0;
    for (int x : a) ans += (s.*pmf)() + x;
    return ans;
}

static ll tmplGenericSortByKey(vector<pair<int,int>> a) {
    sort(a.begin(), a.end(), [](auto &l, auto &r){ return l.first < r.first; });
    return (ll)a.size();
}

static ll tmplMacroHashMix(const vector<int>& a) {
    ll h = 0;
    for (int x : a) h = h * 1315423911u + x;
    return h;
}

ll tmplCaseGenericSum(vector<int> a) { return tmplSumVector(a); }

ll tmplCaseGenericSortByKey(vector<pair<int,int>> a) { return tmplGenericSortByKey(a); }

ll tmplCaseRecursiveLambdaMemo(int n) { return tmplRecursiveLambdaMemo(n); }

ll tmplCaseYCombinatorTreeDP(vector<vector<int>> g) { return tmplYCombinatorTreeDP(g); }

ll tmplCaseMacroNestedLoopCount(int n, int m) { return tmplMacroNestedLoopCount(n, m); }

ll tmplCaseMacroPrefixScan(vector<int> a) { return tmplMacroPrefixScan(a); }

ll tmplCaseTemplateMapAggregation(vector<int> a) { return tmplTemplateMapAggregation(a); }

ll tmplCaseTemplateSetUnionSweep(vector<pair<int,int>> segs) { return tmplTemplateSetUnionSweep(segs); }

ll tmplCaseGenericFenwick(vector<int> a) { return tmplGenericFenwick(a); }

ll tmplCaseGenericStablePartition(vector<int> a) { return tmplGenericStablePartition(a); }

ll tmplCaseGenericDequeWindow(vector<int> a, int k) { return tmplGenericDequeWindow(a, k); }

array<int, 8> tmplCaseCompileTimeArrayTransform(array<int, 8> a) { return tmplCompileTimeTransform<8>(a); }

ll tmplCasePriorityQueueMerge(vector<vector<int>> lists) { return tmplPriorityQueueMerge(lists); }

ll tmplCaseBitsetReachable(int W, vector<int> a) { return tmplBitsetReachable(W, a); }


ll tmplCaseTreeRerootSum(vector<vector<int>> g) { return tmplTreeRerootSum(g); }

ll tmplCaseLowerBoundSweep(vector<int> a) { return tmplLowerBoundSweep(a); }

ll tmplCaseCallbackBfsUnknown(vector<vector<int>> g, function<bool(int)> stop) { return tmplCallbackBfsUnknown(g, stop); }

ll tmplCaseFunctionPointerUnknown(vector<int> a, int (*f)(int)) { return tmplFunctionPointerUnknown(a, f); }

ll tmplCaseLambdaCaptureUnknown(vector<int> a) { return tmplLambdaCaptureUnknown(a); }

ll tmplCaseAliasMutationUnknown(vector<int> a, vector<int> b) { return tmplAliasMutationUnknown(a, b); }

ll tmplCaseRuntimeDispatchUnknown(vector<int> a, int mode) { return tmplRuntimeDispatchUnknown(a, mode); }

ll tmplCaseMoveOnlyFunctorUnknown(vector<int> a) { return tmplMoveOnlyFunctorUnknown(a); }

ll tmplCasePointerToMemberUnknown(vector<int> a) { return tmplPointerToMemberUnknown(a); }

ll tmplCaseMacroHashMix(const vector<int>& a) { return tmplMacroHashMix(a); }

