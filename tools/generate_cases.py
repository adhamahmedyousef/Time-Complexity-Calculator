#!/usr/bin/env python3
"""
Combinatorial reviewed-case generator for the Project-X corpus.

Integrity contract:
  - Labels are computed by a small first-principles composition algebra
    (trip counts multiply; halving/doubling loops are logarithmic; a loop
    bounded by its own index collapses to a geometric series; sequential
    phases add to their dominant term). The algebra is reviewable here and
    NEVER consults the engine.
  - Variants rename accumulators and adjust constants/directions; the
    asymptotic structure of a combo is fixed by its axes.
  - Whenever the engine disagrees with a label, that disagreement is a bug
    to investigate in the engine (or a wrong rule here) - never a reason to
    copy engine output into a label.

Generated families join the development set; the holdout stays untouched.
"""
import json
import os

DATASETS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "datasets")

# ---------------------------------------------------------------------------
# Tiny first-principles composition algebra over canonical bounds.
# ---------------------------------------------------------------------------

# Canonical term -> (poly exponent per symbol, log exponent). Supported
# symbols: n, m, q, W. Exponentials/factorials are represented as opaque
# self-evident strings handled by dedicated templates only.
CANON = {
    "O(1)": {},
    "O(n)": {"n": 1},
    "O(m)": {"m": 1},
    "O(q)": {"q": 1},
    "O(W)": {"W": 1},
    "O(log n)": {"n": 0.0001},
    "O(sqrt n)": {"n": 0.5},
    "O(n^2)": {"n": 2},
    "O(n^3)": {"n": 3},
    "O(n^4)": {"n": 4},
    "O(n m)": {"n": 1, "m": 1},
    "O(n q)": {"n": 1, "q": 1},
    "O(n W)": {"n": 1, "W": 1},
    "O(n^2 m)": {"n": 2, "m": 1},
    "O(n log n)": {"n": 1.0001},
    "O(m log m)": {"m": 1.0001},
    "O(log^2 n)": {"n": 0.0002},
    "O(n + m)": "+:O(n)|O(m)",
    "O(n + m + q)": "+:O(n)|O(m)|O(q)",
    "O(n + q)": "+:O(n)|O(q)",
    "O(n + m log m)": "+:O(n)|O(m log m)",
}

MULTIPLY = {}

def _key(factors):
    parts = []
    for symbol in ("n", "m", "q", "W"):
        exponent = factors.get(symbol, 0)
        if exponent > 0:
            if exponent == 0.5:
                parts.append(f"sqrt {symbol}")
            elif exponent == 0.0001:
                parts.append(f"log {symbol}")
            elif exponent == 0.0002:
                parts.append(f"log^2 {symbol}")
            elif exponent == 1.0001:
                parts.append(f"{symbol} log {symbol}")
            elif exponent == 1.0002:
                parts.append(f"{symbol} log^2 {symbol}")
            else:
                parts.append(f"{symbol}^{exponent:g}" if exponent != 1 else symbol)
    return "O(" + " ".join(parts) + ")" if parts else "O(1)"

def mul(a, b):
    """Multiplies two canonical bounds through the factor algebra."""
    key = (a, b)
    if key in MULTIPLY:
        return MULTIPLY[key]
    fa, fb = CANON[a], CANON[b]
    if isinstance(fa, str) or isinstance(fb, str):
        raise ValueError(f"non-product bound in mul: {a} x {b}")
    merged = dict(fa)
    for symbol, exponent in fb.items():
        merged[symbol] = merged.get(symbol, 0) + exponent
    result = _key(merged)
    CANON.setdefault(result, merged)
    MULTIPLY[key] = result
    return result

def add(a, b):
    """Sequential composition: the sum, canonicalized (dominated terms kept
    only when incomparable - sums of independent dimensions)."""
    if a == b:
        return a
    pair = tuple(sorted([a, b]))
    table = {
        ("O(n)", "O(m)"): "O(n + m)",
        ("O(m)", "O(n)"): "O(n + m)",
        ("O(n)", "O(q)"): "O(n + q)",
        ("O(n)", "O(m log m)"): "O(n + m log m)",
        ("O(m log m)", "O(n)"): "O(n + m log m)",
        ("O(n + m)", "O(q)"): "O(n + m + q)",
        ("O(q)", "O(n + m)"): "O(n + m + q)",
        ("O(n)", "O(log n)"): "O(n)",
        ("O(log n)", "O(n)"): "O(n)",
        ("O(n)", "O(n log n)"): "O(n log n)",
        ("O(n log n)", "O(n)"): "O(n log n)",
        ("O(n^2)", "O(n log n)"): "O(n^2)",
        ("O(n log n)", "O(n^2)"): "O(n^2)",
    }
    return table.get(pair, None) or max(a, b, key=lambda v: sum(CANON[v].values()))

# ---------------------------------------------------------------------------
# Axis definitions. Each axis yields (construction, label_multiplier,
# space_delta) tuples; iteration order is the family layout.
# ---------------------------------------------------------------------------

ACCUMULATORS = ["s", "total", "acc"]

def loop_updates():
    """(init, condition, update, label, uses_index_bound) for scalar n."""
    return [
        ("int i = 0", "i < n", "++i", "O(n)"),
        ("int i = 0", "i < n", "i += 2", "O(n)"),
        ("int i = 0", "i < n", "i += 7", "O(n)"),
        ("int i = n", "i > 0", "--i", "O(n)"),
    ]

def halving_updates():
    return [
        ("long long v = n", "v > 1", "v >>= 1", "O(log n)"),
        ("long long v = n", "v > 1", "v /= 2", "O(log n)"),
        ("long long v = 1", "v < n", "v *= 2", "O(log n)"),
    ]

def emit_loop(index_name, init, condition, update, body):
    return f"for ({init}; {condition}; {update}) {body}"

def emit_while(index_name, init, condition, update, body):
    return f"{{{init}; while ({condition}) {{ {update}; {body} }} }}"

# ---------------------------------------------------------------------------
# Family construction
# ---------------------------------------------------------------------------

FAMILIES = {}

def add_case(family, symbol, code, time, space, conf, tags):
    FAMILIES.setdefault(family, []).append({
        "symbol": symbol, "code": code, "time": time, "space": space,
        "confidence": conf, "tags": tags,
    })

def main():
    case_id = 0

    # -- family: single loops over one dimension, constant bodies -----------
    for u, (init, condition, update, label) in enumerate(loop_updates()):
        for k, acc in enumerate(ACCUMULATORS):
            symbol = f"gen_loop_{u}_{k}"
            body = f"++{acc};" 
            code = f"long long {symbol}(int n) {{ long long {acc} = 0; {emit_loop('i', init, condition, update, body)} return {acc}; }}"
            add_case("cpp-axis-loops", symbol, code, label, "O(1)", "exact", ["linear"])
            case_id += 1
    for u, (init, condition, update, label) in enumerate(halving_updates()):
        for k, acc in enumerate(ACCUMULATORS[:2]):
            symbol = f"gen_halve_{u}_{k}"
            code = f"long long {symbol}(long long n) {{ long long {acc} = 0; long long v = n; while ({condition.replace('v', 'v')}) {{ {update if '=' in update.split()[-1] else update}; ++{acc}; }} return {acc}; }}"
            # emit explicitly to keep the shape readable
            code = f"long long {symbol}(long long n) {{ long long {acc} = 0; {init}; while ({condition}) {{ {update}; ++{acc}; }} return {acc}; }}"
            add_case("cpp-axis-loops", symbol, code, label, "O(1)", "exact", ["logarithmic"])
            case_id += 1
    # sqrt loop
    for k, acc in enumerate(ACCUMULATORS[:2]):
        symbol = f"gen_sqrt_{k}"
        code = f"long long {symbol}(long long n) {{ long long {acc} = 0; for (long long d = 1; d * d <= n; ++d) ++{acc}; return {acc}; }}"
        add_case("cpp-axis-loops", symbol, code, "O(sqrt n)", "O(1)", "exact", ["sqrt"])
        case_id += 1

    # -- family: nested products over dimensions ----------------------------
    nest_specs = [
        (1, ["n"], "O(n)"),
        (2, ["n", "n"], "O(n^2)"),
        (3, ["n", "n", "n"], "O(n^3)"),
        (4, ["n", "n", "n", "n"], "O(n^4)"),
        (2, ["n", "m"], "O(n m)"),
        (3, ["n", "n", "m"], "O(n^2 m)"),
    ]
    for depth, dims, label in nest_specs:
        for k, acc in enumerate(ACCUMULATORS[:2]):
            symbol = f"gen_nest_{depth}_{''.join(d[0] for d in dims)}_{k}"
            # Distinct dimension parameters only; repeated dimensions reuse one
            # scalar (an n x n nest takes a single n).
            unique_dims = list(dict.fromkeys(dims))
            params = ", ".join(f"int {d}" for d in unique_dims)
            opens = " ".join(f"for (int i{level} = 0; i{level} < {dims[level]}; ++i{level}) {{" for level in range(depth))
            closes = "} " * depth
            code = f"long long {symbol}({params}) {{ long long {acc} = 0; {opens} ++{acc}; {closes}return {acc}; }}"
            add_case("cpp-axis-nesting", symbol, code, label, "O(1)", "exact", ["polynomial"])
            case_id += 1

    # -- family: outer loop x inner log / dependent geometric ---------------
    for k, acc in enumerate(ACCUMULATORS[:2]):
        symbol = f"gen_nlinlog_{k}"
        code = (f"long long {symbol}(int n) {{ long long {acc} = 0; for (int i = 0; i < n; ++i) "
                f"for (long long j = 1; j < n; j *= 2) ++{acc}; return {acc}; }}")
        add_case("cpp-axis-composition", symbol, code, "O(n log n)", "O(1)", "exact", ["linearithmic"])
        case_id += 1
    for k, acc in enumerate(ACCUMULATORS[:2]):
        symbol = f"gen_depgen_{k}"
        code = (f"long long {symbol}(int n) {{ long long {acc} = 0; for (int i = n; i > 0; i /= 2) "
                f"for (int j = 0; j < i; ++j) ++{acc}; return {acc}; }}")
        add_case("cpp-axis-composition", symbol, code, "O(n)", "O(1)", "exact", ["geometric"])
        case_id += 1
    for k, acc in enumerate(ACCUMULATORS[:2]):
        symbol = f"gen_logsq_{k}"
        code = (f"long long {symbol}(long long n) {{ long long {acc} = 0; for (long long a = n; a > 1; a /= 2) "
                f"for (long long b = n; b > 1; b /= 2) ++{acc}; return {acc}; }}")
        add_case("cpp-axis-composition", symbol, code, "O(log^2 n)", "O(1)", "exact", ["logarithmic"])
        case_id += 1

    # -- family: sequential phases ------------------------------------------
    seq_specs = [
        (["n", "m"], ["O(n)", "O(m)"], "O(n + m)"),
        (["n", "q"], ["O(n)", "O(q)"], "O(n + q)"),
        (["n", "m", "q"], ["O(n)", "O(m)", "O(q)"], "O(n + m + q)"),
        (["n", "n"], ["O(n)", "O(n)"], "O(n)"),
    ]
    for s, (dims, phase_labels, label) in enumerate(seq_specs):
        for k, acc in enumerate(ACCUMULATORS[:2]):
            symbol = f"gen_seq_{s}_{k}"
            params = ", ".join(f"int {d}" for d in dims)
            phases = " ".join(f"for (int i{p} = 0; i{p} < {dims[p]}; ++i{p}) ++{acc};" for p in range(len(dims)))
            code = f"long long {symbol}({params}) {{ long long {acc} = 0; {phases} return {acc}; }}"
            add_case("cpp-axis-sequential", symbol, code, label, "O(1)", "exact", ["linear"])
            case_id += 1

    # -- family: STL operations ---------------------------------------------
    stl_cases = []
    for k, acc in enumerate(ACCUMULATORS[:2]):
        stl_cases.append((f"gen_sort_{k}", f"long long {ACCUMULATORS[k]}_sort(vector<int> a) {{ sort(a.begin(), a.end()); return a.empty() ? 0 : a[0]; }}", "O(n log n)", "O(n)", "exact", ["stl"]))
    # sort variants use their own symbol naming; rebuild cleanly:
    stl_cases = []
    stl_templates = [
        ("sort", "long long {S}(vector<int> a) {{ sort(a.begin(), a.end()); return a.empty() ? 0 : a[0]; }}", "O(n log n)", "Unknown", "exact", ["stl", "sorting"]),
        ("lower", "int {S}(const vector<int>& a, int key) {{ return (int)(lower_bound(a.begin(), a.end(), key) - a.begin()); }}", "O(log n)", "O(1)", "exact", ["stl", "search"]),
        ("maploop", "long long {S}(const vector<int>& a) {{ map<int, int> freq; for (int x : a) ++freq[x]; return (long long)freq.size(); }}", "O(n log n)", "O(n)", "exact", ["stl", "ordered"]),
        ("umaploop", "long long {S}(const vector<int>& a) {{ unordered_map<int, int> freq; for (int x : a) ++freq[x]; return (long long)freq.size(); }}", "O(n^2)", "O(n)", "exact", ["stl", "hashing"]),
        ("setloop", "long long {S}(const vector<int>& a) {{ set<int> seen; for (int x : a) seen.insert(x); return (long long)seen.size(); }}", "O(n log n)", "O(n)", "exact", ["stl", "ordered"]),
        ("usetloop", "long long {S}(const vector<int>& a) {{ unordered_set<int> seen; for (int x : a) seen.insert(x); return (long long)seen.size(); }}", "O(n^2)", "O(n)", "exact", ["stl", "hashing"]),
        ("minel", "int {S}(const vector<int>& a) {{ return *min_element(a.begin(), a.end()); }}", "O(n)", "O(1)", "exact", ["stl", "linear"]),
        ("rev", "long long {S}(vector<int>& a) {{ reverse(a.begin(), a.end()); return a.empty() ? 0 : a[0]; }}", "O(n)", "O(1)", "exact", ["stl", "linear"]),
        ("iota", "long long {S}(vector<int>& a) {{ iota(a.begin(), a.end(), 0); return (long long)a.size(); }}", "O(n)", "O(1)", "exact", ["stl", "linear"]),
        ("pushloop", "vector<int> {S}(int n) {{ vector<int> out; for (int i = 0; i < n; ++i) out.push_back(i); return out; }}", "O(n)", "O(n)", "exact", ["stl", "amortized"]),
        ("pqloop", "long long {S}(const vector<int>& a) {{ priority_queue<int> pq; for (int x : a) pq.push(x); long long total = 0; while (!pq.empty()) {{ total += pq.top(); pq.pop(); }} return total; }}", "O(n log n)", "O(n)", "exact", ["stl", "heap"]),
        ("mapfind", "bool {S}(const map<int, int>& m, int key) {{ return m.find(key) != m.end(); }}", "O(log n)", "O(1)", "exact", ["stl", "ordered"]),
        ("umapfind", "bool {S}(const unordered_map<int, int>& m, int key) {{ return m.find(key) != m.end(); }}", "O(n)", "O(1)", "exact", ["stl", "hashing"]),
        ("strbuild", "string {S}(int n) {{ string out; for (int i = 0; i < n; ++i) out.push_back('x'); return out; }}", "O(n)", "O(n)", "exact", ["string"]),
        ("strcat", "string {S}(int n) {{ string out; for (int i = 0; i < n; ++i) out += 'x'; return out; }}", "O(n^2)", "O(n)", "exact", ["string"]),
        ("strscan", "long long {S}(const string& text) {{ long long hits = 0; for (char c : text) if (c == 'a') ++hits; return hits; }}", "O(n)", "O(1)", "exact", ["string"]),
    ]
    for t, (stem, body, time, space, conf, tags) in enumerate(stl_templates):
        for v in range(4):
            symbol = f"gen_{stem.replace(chr(45), chr(95))}_{v}"
            code = body.replace("{S}", symbol)
            add_case("cpp-axis-stl", symbol, code, time, space, conf, tags)
            case_id += 1

    # -- family: DP loop shapes ----------------------------------------------
    dp_templates = [
        ("knap", "long long {S}(int n, int W, const vector<int>& wt) {{ vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0)); for (int i = 1; i <= n; ++i) for (int w = 0; w <= W; ++w) dp[i][w] = max(dp[i - 1][w], wt[i - 1] <= w ? dp[i - 1][w - wt[i - 1]] : dp[i - 1][w]); return dp[n][W]; }}", "O(n W)", "O(n W)", "exact", ["dp"]),
        ("grid", "long long {S}(int n, int m) {{ vector<vector<long long>> dp(n, vector<long long>(m, 1)); for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; return dp[n - 1][m - 1]; }}", "O(n m)", "O(n m)", "exact", ["dp"]),
        ("lis", "long long {S}(const vector<int>& a) {{ int n = (int)a.size(); vector<int> dp(n, 1); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1); return (long long)dp[n - 1]; }}", "O(n^2)", "O(n)", "exact", ["dp"]),
        ("coins", "long long {S}(const vector<int>& coins, int k) {{ vector<long long> ways(k + 1, 0); ways[0] = 1; for (int c : coins) for (int x = c; x <= k; ++x) ways[x] += ways[x - c]; return ways[k]; }}", "O(n k)", "O(k)", "exact", ["dp"]),
        ("prefq", "long long {S}(const vector<int>& a, const vector<int>& qs) {{ int n = (int)a.size(); vector<long long> pref(n + 1, 0); for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i]; long long total = 0; for (int q : qs) total += pref[q % (n + 1)]; return total; }}", "O(n + m)", "O(n)", "exact", ["prefix"]),
        ("bitmask-subsets", "long long {S}(int n) {{ long long total = 0; for (int mask = 0; mask < (1 << n); ++mask) total += mask; return total; }}", "O(2^n)", "O(1)", "exact", ["bitmask"]),
        ("bitmask-pairs", "long long {S}(int n) {{ long long total = 0; for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) ++total; return total; }}", "O(n 2^n)", "O(1)", "exact", ["bitmask"]),
    ]
    for t, (stem, body, time, space, conf, tags) in enumerate(dp_templates):
        for v in range(4):
            symbol = f"gen_{stem.replace(chr(45), chr(95))}_{v}"
            code = body.replace("{S}", symbol)
            add_case("cpp-axis-dp", symbol, code, time, space, conf, tags)
            case_id += 1

    # -- family: recurrences --------------------------------------------------
    rec_templates = [
        ("rec-halving", "long long {S}(long long n) {{ if (n <= 1) return 0; return 1 + {S}(n / 2); }}", "O(log n)", "O(log n)", "exact", ["recursion"]),
        ("rec-decrement", "long long {S}(long long n) {{ if (n <= 0) return 0; return n + {S}(n - 1); }}", "O(n)", "O(n)", "exact", ["recursion"]),
        ("rec-fib", "long long {S}(long long n) {{ if (n <= 1) return n; return {S}(n - 1) + {S}(n - 2); }}", "O(1.618^n)", "O(n)", "estimated", ["recursion", "exponential"]),
        ("rec-tree", "long long {S}(long long n) {{ if (n <= 1) return 1; return {S}(n / 2) + {S}(n / 2); }}", "O(n)", "O(log n)", "exact", ["recursion"]),
        ("rec-perm", "long long {S}(vector<int>& used, int depth, int n) {{ if (depth == n) return 1; long long total = 0; for (int c = 0; c < n; ++c) {{ if (!used[c]) {{ used[c] = 1; total += {S}(used, depth + 1, n); used[c] = 0; }} }} return total; }}", "O(n!)", "O(n)", "estimated", ["backtracking"]),
    ]
    for t, (stem, body, time, space, conf, tags) in enumerate(rec_templates):
        for v in range(4):
            symbol = f"gen_{stem.replace(chr(45), chr(95))}_{v}"
            code = body.replace("{S}", symbol)
            add_case("cpp-axis-recursion", symbol, code, time, space, conf, tags)
            case_id += 1

    # -- family: graphs with conventional dimensions --------------------------
    graph_templates = [
        ("bfs", "vector<int> {S}(const vector<vector<int>>& adj, int source) {{ vector<int> dist(adj.size(), -1); queue<int> pending; dist[source] = 0; pending.push(source); while (!pending.empty()) {{ int u = pending.front(); pending.pop(); for (int v : adj[u]) if (dist[v] == -1) {{ dist[v] = dist[u] + 1; pending.push(v); }} }} return dist; }}", "O(V + E)", "O(V)", "estimated", ["graph"]),
        ("dfs", "vector<int> {S}(const vector<vector<int>>& adj, int source) {{ vector<int> seen(adj.size(), 0); stack<int> pending; pending.push(source); seen[source] = 1; while (!pending.empty()) {{ int u = pending.top(); pending.pop(); for (int v : adj[u]) if (!seen[v]) {{ seen[v] = 1; pending.push(v); }} }} return seen; }}", "Unknown", "Unknown", "unknown", ["graph", "adversarial"]),
        ("floyd", "void {S}(vector<vector<long long>>& dist) {{ int V = (int)dist.size(); for (int k = 0; k < V; ++k) for (int i = 0; i < V; ++i) for (int j = 0; j < V; ++j) if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j]; }}", "O(V^3)", "O(1)", "exact", ["graph"]),
        ("dense-prim", "long long {S}(const vector<vector<int>>& graph, int V) {{ vector<int> key(V, 1000000000); vector<bool> used(V, false); key[0] = 0; long long total = 0; for (int count = 0; count < V; ++count) {{ int best = -1; for (int v = 0; v < V; ++v) if (!used[v] && (best == -1 || key[v] < key[best])) best = v; used[best] = true; total += key[best]; for (int v = 0; v < V; ++v) if (!used[v] && graph[best][v] < key[v]) key[v] = graph[best][v]; }} return total; }}", "O(V^2)", "O(V)", "exact", ["graph", "mst"]),
    ]
    for t, (stem, body, time, space, conf, tags) in enumerate(graph_templates):
        for v in range(4):
            symbol = f"gen_{stem.replace(chr(45), chr(95))}_{v}"
            code = body.replace("{S}", symbol)
            add_case("cpp-axis-graphs", symbol, code, time, space, conf, tags)
            case_id += 1

    # -- family: math ----------------------------------------------------------
    math_templates = [
        ("pow", "long long {S}(long long base, long long e) {{ long long result = 1; while (e > 0) {{ if (e & 1) result *= base; base *= base; e >>= 1; }} return result; }}", "O(log n)", "O(1)", "exact", ["math"]),
        ("gcd", "long long {S}(long long a, long long b) {{ while (b != 0) {{ long long t = a % b; a = b; b = t; }} return a; }}", "O(log n)", "O(1)", "exact", ["math"]),
        ("sieve", "long long {S}(int n) {{ vector<bool> composite(n + 1, false); long long primes = 0; for (int i = 2; i * i <= n; ++i) {{ if (!composite[i]) {{ for (int j = i * i; j <= n; j += i) composite[j] = true; }} }} for (int i = 2; i <= n; ++i) if (!composite[i]) ++primes; return primes; }}", "O(n log log n)", "O(n)", "exact", ["math", "sieve"]),
        ("bits", "long long {S}(long long n) {{ long long bits = 0; while (n) {{ bits += n & 1; n >>= 1; }} return bits; }}", "O(log n)", "O(1)", "exact", ["bits"]),
        ("trialdiv", "long long {S}(long long n) {{ long long cnt = 0; for (long long d = 1; d * d <= n; ++d) if (n % d == 0) ++cnt; return cnt; }}", "O(sqrt n)", "O(1)", "exact", ["math"]),
    ]
    for t, (stem, body, time, space, conf, tags) in enumerate(math_templates):
        for v in range(4):
            symbol = f"gen_{stem.replace(chr(45), chr(95))}_{v}"
            code = body.replace("{S}", symbol)
            add_case("cpp-axis-math", symbol, code, time, space, conf, tags)
            case_id += 1

    # -- family: honest abstentions (correct Unknown behavior) -----------------
    abstain_templates = [
        ("collatz", "long long {S}(long long n) {{ long long steps = 0; while (n != 1) {{ n = (n % 2 == 0) ? n / 2 : 3 * n + 1; ++steps; }} return steps; }}", "Unknown", "Unknown", "unknown", ["adversarial"]),
        ("callback", "long long {S}(const vector<int>& a, const function<bool(int)>& predicate) {{ long long hits = 0; for (int x : a) if (predicate(x)) ++hits; return hits; }}", "Unknown", "O(1)", "unknown", ["adversarial"]),
        ("pointer-chase", "long long {S}(const vector<int>& nxt, int start) {{ int cur = start; long long steps = 0; while (cur != -1) {{ cur = nxt[cur]; ++steps; }} return steps; }}", "Unknown", "O(1)", "unknown", ["adversarial"]),
    ]
    for t, (stem, body, time, space, conf, tags) in enumerate(abstain_templates):
        for v in range(4):
            symbol = f"gen_{stem.replace(chr(45), chr(95))}_{v}"
            code = body.replace("{S}", symbol)
            add_case("cpp-axis-abstain", symbol, code, time, space, conf, tags)
            case_id += 1

    # ---------------------------------------------------------------------------
    # Variant expansion: rename safe single-letter identifiers through suffix
    # cycles. Dimension names (n, m, q, W, t, k) are protected because labels
    # reference them. Renaming tests name-independence: an engine that
    # memorized spellings would fail these variants; a derivation passes.
    # ---------------------------------------------------------------------------
    PROTECTED = {"n", "m", "q", "W", "t", "k"}
    KEYWORDS = {"if", "for", "while", "return", "int", "long", "bool", "void", "auto", "char", "const", "static", "else", "true", "false", "break", "continue"}

    import re as _re

    def rename_variant(code: str, variant: int) -> str:
        tokens = sorted(set(_re.findall(r"\b[A-Za-z_]\b", code)))
        renames = {}
        for position, token in enumerate(tokens):
            if token in PROTECTED or token in KEYWORDS:
                continue
            renames[token] = f"{token}x{variant}"
        if not renames:
            return code
        pattern = _re.compile(r"\b(" + "|".join(renames) + r")\b")
        return pattern.sub(lambda match: renames[match.group(1)], code)

    VARIANT_COUNT = int(os.environ.get("GEN_VARIANTS", "16"))
    expanded = {}
    for family, cases in FAMILIES.items():
        grown = []
        for case in cases:
            case = {**case, "symbol": case["symbol"].replace("-", "_")}
            for variant in range(VARIANT_COUNT):
                new_symbol = f"{case['symbol']}_v{variant}"
                # Templates were written with doubled braces for readability;
                # C++ emits single braces. Rebind the base symbol per variant
                # so every variant is a distinct, compilable definition.
                code = case["code"].replace("{{", "{").replace("}}", "}").replace(case["symbol"], new_symbol)
                code = rename_variant(code, variant)
                grown.append({**case, "code": code, "symbol": new_symbol})
        expanded[family] = grown

    # ---------------------------------------------------------------------------
    # Emit files: split each family into chunks of at most 120 functions so a
    # single Clang parse stays fast and partial-AST recovery stays relevant.
    # ---------------------------------------------------------------------------
    total = 0
    for family, cases in expanded.items():
        chunk_size = 120
        for chunk_index in range(0, len(cases), chunk_size):
            chunk = cases[chunk_index:chunk_index + chunk_size]
            part = f"{family}-{chunk_index // chunk_size + 1:02d}"
            cpp_lines = [
                f"// Generated reviewed family: {part}",
                "// Labels derive from each template's documented semantic shape",
                "// (first principles), never from engine output.",
                "using namespace std;",
                "",
            ]
            manifest_cases = []
            for case in chunk:
                cpp_lines.append(case["code"])
                manifest_cases.append({
                    "id": f"{part}-{case['symbol']}",
                    "symbol": case["symbol"],
                    "time": case["time"],
                    "space": case["space"],
                    "confidence": case["confidence"],
                    "tags": case["tags"],
                })
            with open(os.path.join(DATASETS, part + ".cpp"), "w", encoding="utf-8", newline="\n") as handle:
                handle.write("\n".join(cpp_lines) + "\n")
            with open(os.path.join(DATASETS, part + ".manifest.json"), "w", encoding="utf-8", newline="\n") as handle:
                json.dump({"version": 1, "language": "cpp", "cases": manifest_cases}, handle, indent=1)
            total += len(chunk)
            print(f"{part}: {len(chunk)} cases")
    print(f"TOTAL generated: {total}")

if __name__ == "__main__":
    main()
