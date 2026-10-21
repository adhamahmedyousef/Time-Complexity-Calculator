
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INFLL = (1LL<<60);

static vector<ll> prefLL(const vector<int>& a) {
    vector<ll> p(a.size() + 1);
    for (size_t i = 0; i < a.size(); ++i) p[i + 1] = p[i] + a[i];
    return p;
}

static ll knap01Rolling(int W, const vector<pair<int,int>>& items) {
    vector<ll> dp(W + 1, 0);
    for (auto [w, v] : items) {
        for (int cap = W; cap >= w; --cap) dp[cap] = max(dp[cap], dp[cap - w] + v);
    }
    return *max_element(dp.begin(), dp.end());
}

static ll knapUnbounded(int W, const vector<pair<int,int>>& items) {
    vector<ll> dp(W + 1, 0);
    for (auto [w, v] : items) {
        for (int cap = w; cap <= W; ++cap) dp[cap] = max(dp[cap], dp[cap - w] + v);
    }
    return *max_element(dp.begin(), dp.end());
}

static ll subsetSumBitsetCountWays(int W, const vector<int>& a) {
    vector<ll> dp(W + 1);
    dp[0] = 1;
    for (int x : a) {
        for (int s = W; s >= x; --s) dp[s] += dp[s - x];
    }
    ll ans = 0;
    for (int s = 0; s <= W; ++s) if (dp[s]) ++ans;
    return ans;
}

static int subsetSumBitsetReachable(int W, const vector<int>& a) {
    vector<unsigned long long> bits((W >> 6) + 1);
    bits[0] = 1ULL;
    for (int x : a) {
        int shiftWords = x >> 6, shiftBits = x & 63;
        vector<unsigned long long> add(bits.size());
        for (size_t i = 0; i < bits.size(); ++i) if (bits[i]) {
            size_t j = i + shiftWords;
            if (j < bits.size()) add[j] |= bits[i] << shiftBits;
            if (shiftBits && j + 1 < bits.size()) add[j + 1] |= bits[i] >> (64 - shiftBits);
        }
        for (size_t i = 0; i < bits.size(); ++i) bits[i] |= add[i];
    }
    int ans = 0;
    for (int s = 0; s <= W; ++s) if (bits[s >> 6] & (1ULL << (s & 63))) ++ans;
    return ans;
}

static ll meetInMiddleSubsetCount(const vector<int>& a, int target) {
    int n = (int)a.size();
    int mid = n / 2;
    vector<int> L(a.begin(), a.begin() + mid), R(a.begin() + mid, a.end());
    vector<int> sumsL, sumsR;
    for (int mask = 0; mask < (1 << (int)L.size()); ++mask) {
        int s = 0;
        for (int i = 0; i < (int)L.size(); ++i) if (mask >> i & 1) s += L[i];
        sumsL.push_back(s);
    }
    for (int mask = 0; mask < (1 << (int)R.size()); ++mask) {
        int s = 0;
        for (int i = 0; i < (int)R.size(); ++i) if (mask >> i & 1) s += R[i];
        sumsR.push_back(s);
    }
    sort(sumsR.begin(), sumsR.end());
    ll ans = 0;
    for (int x : sumsL) {
        auto range = equal_range(sumsR.begin(), sumsR.end(), target - x);
        ans += range.second - range.first;
    }
    return ans;
}

static ll digitDpCountMod(long long n, int mod, int need) {
    string s = to_string(n);
    int L = (int)s.size();
    vector<vector<vector<ll>>> memo(L + 1, vector<vector<ll>>(mod, vector<ll>(2, -1)));
    function<ll(int,int,int)> dfs = [&](int pos, int rem, int tight) -> ll {
        if (pos == L) return rem == need;
        ll &res = memo[pos][rem][tight];
        if (res != -1) return res;
        res = 0;
        int lim = tight ? s[pos] - '0' : 9;
        for (int d = 0; d <= lim; ++d) res += dfs(pos + 1, (rem * 10 + d) % mod, tight && d == lim);
        return res;
    };
    return dfs(0, 0, 1);
}

static ll digitDpSum(long long n) {
    string s = to_string(n);
    int L = (int)s.size();
    vector<vector<vector<pair<ll,ll>>>> memo(L + 1, vector<vector<pair<ll,ll>>>(2, vector<pair<ll,ll>>(2, {-1, -1})));
    function<pair<ll,ll>(int,int,int)> dfs = [&](int pos, int tight, int started) -> pair<ll,ll> {
        if (pos == L) return {1, 0};
        auto &res = memo[pos][tight][started];
        if (res.first != -1) return res;
        ll cnt = 0, sum = 0;
        int lim = tight ? s[pos] - '0' : 9;
        for (int d = 0; d <= lim; ++d) {
            auto [c, sm] = dfs(pos + 1, tight && d == lim, started || d != 0);
            cnt += c;
            sum += sm + c * d;
        }
        return res = {cnt, sum};
    };
    return dfs(0, 1, 0).second;
}

static ll digitDpForbidden(long long n, const string& pat) {
    string s = to_string(n);
    int m = (int)pat.size(), L = (int)s.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j && pat[i] != pat[j]) j = pi[j - 1];
        if (pat[i] == pat[j]) ++j;
        pi[i] = j;
    }
    vector<array<int, 10>> go(m + 1);
    for (int st = 0; st <= m; ++st) for (int d = 0; d <= 9; ++d) {
        if (st == m) { go[st][d] = m; continue; }
        int j = st;
        char c = char('0' + d);
        while (j && (j == m || pat[j] != c)) j = pi[j - 1];
        if (j < m && pat[j] == c) ++j;
        go[st][d] = j;
    }
    vector<vector<vector<ll>>> memo(L + 1, vector<vector<ll>>(m + 1, vector<ll>(2, -1)));
    function<ll(int,int,int)> dfs = [&](int pos, int st, int tight) -> ll {
        if (st == m) return 0;
        if (pos == L) return 1;
        ll &res = memo[pos][st][tight];
        if (res != -1) return res;
        res = 0;
        int lim = tight ? s[pos] - '0' : 9;
        for (int d = 0; d <= lim; ++d) res += dfs(pos + 1, go[st][d], tight && d == lim);
        return res;
    };
    return dfs(0, 0, 1);
}


static ll treeIndependentSet(const vector<vector<int>>& g, int root = 0) {
    int n = (int)g.size();
    vector<array<ll,2>> dp(n, {0,0});
    function<void(int,int)> dfs = [&](int u, int p) {
        dp[u][1] = 1;
        dp[u][0] = 0;
        for (int v : g[u]) if (v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };
    dfs(root, -1);
    return max(dp[root][0], dp[root][1]);
}

static ll treeVertexCover(const vector<vector<int>>& g, int root = 0) {
    int n = (int)g.size();
    vector<array<ll,2>> dp(n, {0,0});
    function<void(int,int)> dfs = [&](int u, int p) {
        dp[u][0] = 0;
        dp[u][1] = 1;
        for (int v : g[u]) if (v != p) {
            dfs(v, u);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    };
    dfs(root, -1);
    return min(dp[root][0], dp[root][1]);
}

static vector<ll> treeRerootDistSum(const vector<vector<int>>& g, int root = 0) {
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
            ll pu = down[u], pv = down[v];
            int su = sz[u], sv = sz[v];
            down[u] -= down[v] + sz[v];
            sz[u] -= sz[v];
            down[v] += down[u] + sz[u];
            sz[v] += sz[u];
            dfs2(v, u);
            sz[v] = sv; down[v] = pv;
            sz[u] = su; down[u] = pu;
        }
    };
    dfs1(root, -1);
    dfs2(root, -1);
    return ans;
}

static ll weightedIntervalScheduling(vector<array<int,3>> jobs) {
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){ return a[1] < b[1]; });
    int n = (int)jobs.size();
    vector<int> ends(n);
    for (int i = 0; i < n; ++i) ends[i] = jobs[i][1];
    vector<ll> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int s = jobs[i-1][0], e = jobs[i-1][1], w = jobs[i-1][2];
        int j = upper_bound(ends.begin(), ends.begin() + i - 1, s) - ends.begin();
        dp[i] = max(dp[i-1], dp[j] + w);
    }
    return dp[n];
}

static ll intervalMergeStones(const vector<int>& a) {
    int n = (int)a.size();
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            dp[l][r] = INFLL;
            for (int k = l; k < r; ++k) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + pref[r+1] - pref[l]);
        }
    }
    return n ? dp[0][n-1] : 0;
}

static ll tspBitmask(const vector<vector<int>>& w) {
    int n = (int)w.size();
    vector<vector<ll>> dp(1 << n, vector<ll>(n, INFLL));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) if (dp[mask][u] < INFLL/2) {
            for (int v = 0; v < n; ++v) if (!(mask >> v & 1)) {
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + w[u][v]);
            }
        }
    }
    ll ans = INFLL;
    for (int u = 0; u < n; ++u) ans = min(ans, dp[(1 << n) - 1][u] + w[u][0]);
    return ans;
}

static ll assignmentBitmask(const vector<vector<int>>& cost) {
    int n = (int)cost.size();
    vector<ll> dp(1 << n, INFLL);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int i = __builtin_popcount((unsigned)mask);
        for (int j = 0; j < n; ++j) if (!(mask >> j & 1)) {
            dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[i][j]);
        }
    }
    return dp[(1 << n) - 1];
}

static vector<ll> sosSubsetTransform(vector<ll> f) {
    int n = 0;
    while ((1 << n) < (int)f.size()) ++n;
    for (int b = 0; b < n; ++b)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (mask >> b & 1) f[mask] += f[mask ^ (1 << b)];
    return f;
}

static vector<ll> sosSupersetTransform(vector<ll> f) {
    int n = 0;
    while ((1 << n) < (int)f.size()) ++n;
    for (int b = 0; b < n; ++b)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (!(mask >> b & 1)) f[mask] += f[mask | (1 << b)];
    return f;
}

static ll dominoTilings(int n, int m) {
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << m));
    dp[0][0] = 1;
    for (int r = 0; r < n; ++r) {
        function<void(int,int,int,ll)> dfs = [&](int c, int curMask, int nxtMask, ll ways) {
            if (c == m) { dp[r + 1][nxtMask] += ways; return; }
            if (curMask >> c & 1) dfs(c + 1, curMask, nxtMask, ways);
            else {
                dfs(c + 1, curMask | (1 << c), nxtMask | (1 << c), ways);
                if (c + 1 < m && !(curMask >> (c + 1) & 1)) dfs(c + 2, curMask | (1 << c) | (1 << (c + 1)), nxtMask, ways);

            }
        };
        fill(dp[r + 1].begin(), dp[r + 1].end(), 0);
        for (int mask = 0; mask < (1 << m); ++mask) if (dp[r][mask]) dfs(0, mask, 0, dp[r][mask]);
    }
    return dp[n][0];
}

static ll dequeOptimization(const vector<int>& a, int k) {
    int n = (int)a.size();
    vector<ll> dp(n + 1, INFLL);
    deque<int> dq;
    dp[0] = 0;
    dq.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();
        dp[i] = dp[dq.front()] + a[i - 1];
        while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    return dp[n];
}


struct Line {
    ll m, b;
    ll get(ll x) const { return m * x + b; }
};

static ll liChaoMinValue(const vector<pair<ll,ll>>& lines, const vector<ll>& xs) {
    if (xs.empty()) return 0;
    ll lo = *min_element(xs.begin(), xs.end());
    ll hi = *max_element(xs.begin(), xs.end());
    struct Node {
        Line line;
        Node *l = nullptr, *r = nullptr;
        bool has = false;
        Node() : line({0, INFLL}) {}
    };
    function<void(Node*&, ll, ll, Line)> add = [&](Node*& node, ll l, ll r, Line nw) {
        if (!node) node = new Node();
        if (!node->has) { node->line = nw; node->has = true; return; }
        ll mid = (l + r) >> 1;
        bool left = nw.get(l) < node->line.get(l);
        bool m = nw.get(mid) < node->line.get(mid);
        if (m) swap(nw, node->line);
        if (l == r) return;
        if (left != m) add(node->l, l, mid, nw);
        else add(node->r, mid + 1, r, nw);
    };
    function<ll(Node*, ll, ll, ll)> query = [&](Node* node, ll l, ll r, ll x) -> ll {
        if (!node) return INFLL;
        ll res = node->has ? node->line.get(x) : INFLL;
        if (l == r) return res;
        ll mid = (l + r) >> 1;
        if (x <= mid) return min(res, query(node->l, l, mid, x));
        return min(res, query(node->r, mid + 1, r, x));
    };
    Node* root = nullptr;
    for (auto [m, b] : lines) add(root, lo, hi, Line{m, b});
    ll ans = INFLL;
    for (ll x : xs) ans = min(ans, query(root, lo, hi, x));
    return ans;
}

static ll divideConquerPartitionDP(const vector<int>& a, int groups) {
    int n = (int)a.size();
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    auto cost = [&](int l, int r) -> ll { return (pref[r] - pref[l]) * (pref[r] - pref[l]); };
    vector<vector<ll>> dp(groups + 1, vector<ll>(n + 1, INFLL));
    dp[0][0] = 0;
    for (int g = 1; g <= groups; ++g) {
        function<void(int,int,int,int)> solve = [&](int L, int R, int optL, int optR) {
            if (L > R) return;
            int mid = (L + R) >> 1;
            pair<ll,int> best = {INFLL, -1};
            for (int k = optL; k <= min(optR, mid - 1); ++k) {
                ll cand = dp[g - 1][k] + cost(k, mid);
                if (cand < best.first) best = {cand, k};
            }
            dp[g][mid] = best.first;
            int opt = best.second;
            solve(L, mid - 1, optL, opt);
            solve(mid + 1, R, opt, optR);
        };
        solve(g, n, g - 1, n - 1);
    }
    return dp[groups][n];
}

static ll hamiltonianPathsDag(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<vector<ll>> dp(1 << n, vector<ll>(n));
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) if (dp[mask][u]) {
            for (int v : g[u]) if (!(mask >> v & 1)) dp[mask | (1 << v)][v] += dp[mask][u];
        }
    }
    ll ans = 0;
    for (int u = 0; u < n; ++u) ans += dp[(1 << n) - 1][u];
    return ans;
}

static ll circularHouseRobber(const vector<int>& a) {
    int n = (int)a.size();
    auto run = [&](int l, int r) {
        ll take = 0, skip = 0;
        for (int i = l; i < r; ++i) {
            ll ntake = skip + a[i];
            ll nskip = max(skip, take);
            take = ntake;
            skip = nskip;
        }
        return max(take, skip);
    };
    if (n == 1) return a[0];
    return max(run(0, n - 1), run(1, n));
}

static ll minMaxPartitionSum(const vector<int>& a, int k) {
    int n = (int)a.size();
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, INFLL));
    dp[0][0] = 0;
    for (int g = 1; g <= k; ++g) {
        for (int i = 1; i <= n; ++i) {
            for (int j = g - 1; j < i; ++j) {
                ll seg = pref[i] - pref[j];
                dp[g][i] = min(dp[g][i], max(dp[g - 1][j], seg));
            }
        }
    }
    return dp[k][n];
}

static ll bitsetKnapsackCountReachable(int W, const vector<int>& a) {
    return subsetSumBitsetReachable(W, a);
}

ll dpKnapsack01Rolling(int W, vector<pair<int,int>> items) { return knap01Rolling(W, items); }

ll dpKnapsack01RollingVariant(int W, vector<pair<int,int>> items) { return knap01Rolling(W, items); }

ll dpUnboundedKnapsack(int W, vector<pair<int,int>> items) { return knapUnbounded(W, items); }

int dpSubsetSumReachableBitset(int W, vector<int> a) { return subsetSumBitsetReachable(W, a); }


ll dpSubsetSumCountWays(int W, vector<int> a) { return subsetSumBitsetCountWays(W, a); }

ll dpMeetInMiddleSubsetCount(vector<int> a, int target) { return meetInMiddleSubsetCount(a, target); }

ll dpDigitCountMod(long long n, int mod, int need) { return digitDpCountMod(n, mod, need); }

ll dpDigitSum(long long n) { return digitDpSum(n); }

ll dpDigitForbiddenSubstring(long long n, string pat) { return digitDpForbidden(n, pat); }

ll dpTreeIndependentSet(vector<vector<int>> g) { return treeIndependentSet(g, 0); }

ll dpTreeVertexCover(vector<vector<int>> g) { return treeVertexCover(g, 0); }

vector<ll> dpTreeRerootDistanceSum(vector<vector<int>> g) { return treeRerootDistSum(g, 0); }

ll dpWeightedIntervalScheduling(vector<array<int,3>> jobs) { return weightedIntervalScheduling(jobs); }

ll dpIntervalMergeStones(vector<int> a) { return intervalMergeStones(a); }

ll dpTspBitmask(vector<vector<int>> w) { return tspBitmask(w); }

ll dpAssignmentBitmask(vector<vector<int>> cost) { return assignmentBitmask(cost); }

vector<ll> dpSosSubsetTransform(vector<ll> f) { return sosSubsetTransform(f); }

vector<ll> dpSosSupersetTransform(vector<ll> f) { return sosSupersetTransform(f); }

ll dpDominoTilings(int n, int m) { return dominoTilings(n, m); }

ll dpDequeOptimization(vector<int> a, int k) { return dequeOptimization(a, k); }

ll dpLiChaoMinValue(vector<pair<ll,ll>> lines, vector<ll> xs) { return liChaoMinValue(lines, xs); }

ll dpDivideConquerPartitionDP(vector<int> a, int groups) { return divideConquerPartitionDP(a, groups); }

ll dpHamiltonianPathsDag(vector<vector<int>> g) { return hamiltonianPathsDag(g); }

ll dpCircularHouseRobber(vector<int> a) { return circularHouseRobber(a); }

ll dpMinMaxPartitionSum(vector<int> a, int k) { return minMaxPartitionSum(a, k); }

ll dpBitsetKnapsackCountReachable(int W, vector<int> a) { return bitsetKnapsackCountReachable(W, a); }

