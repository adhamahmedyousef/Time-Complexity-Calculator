#!/usr/bin/env python3
"""
Un-randomizes the cpp-pack-level0-400 labels.

The pack's label pipeline assigned labels from a pool at random: identical
code shapes carry up to five different labels (verified by grouping). Each
signature rule below is written from first principles for one code shape;
the rule's label is the complexity a reader derives by sight. Shapes that no
rule covers keep their original labels (conservative).
"""
import glob
import json
import os
import re

DATASETS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "datasets")

# Signature -> (time, space, confidence). Each rule: code pattern -> truth.
SIGNATURES = [
    (r"ll x = n \* 3 \+ 7", "O(1)", "O(1)", "exact"),
    (r"for \(int mask = 0; mask < \(1 << n\); \+\+mask\) ans \+= __builtin_popcount", "O(2^n)", "O(1)", "exact"),
    (r"for \(int mask = 0; mask < \(1 << n\); \+\+mask\) cnt \+= __builtin_popcount", "O(2^n)", "O(1)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) s \+= __builtin_popcount", "O(n)", "O(1)", "exact"),
    (r"do \{ \+\+cnt; \} while \(next_permutation", "O(n n!)", "O(n)", "estimated"),
    (r"for \(ll i = 1; i \* i <= n; \+\+i\) if \(n % i == 0\) cnt \+= \(i \* i == n \? 1 : 2\)", "O(sqrt n)", "O(1)", "exact"),
    (r"sort\(all\(a\)\); ll ans = 0; for \(int x : a\) ans \+= x", "O(n log n)", "O(n)", "exact"),
    (r"sort\(all\(a\)\); cout << a\.back\(\)", "O(n log n)", "O(n)", "exact"),
    (r"sort\(all\(a\)\); int q; cin >> q; ll ans = 0; while \(q--\) \{ int x; cin >> x; ans += bs_\d+\(a, x\)", "O(n log n + m log n)", "O(n)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) for \(int j = 0; j < n; \+\+j\) for \(int k = 0; k < n; \+\+k\) ans \+= i \+ j \+ k", "O(n^3)", "O(1)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) for \(int j = 0; j < n; \+\+j\) for \(int k = 0; k < m; \+\+k\) \+\+ans", "O(n^2 m)", "O(1)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) for \(int j = 0; j < m; \+\+j\) \+\+ans", "O(n m)", "O(1)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) for \(int j = 0; j < n; \+\+j\) ans \+= i \+ j", "O(n^2)", "O(1)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) for \(int j = 0; j < i; \+\+j\) ans \+= j", "O(n^2)", "O(1)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) ans \+= i; for \(int j = 0; j < m; \+\+j\) ans \+= j", "O(n + m)", "O(1)", "exact"),
    (r"for \(int i = n - 1; i >= 0; --i\) ans \+= a\[i\]", "O(n)", "O(n)", "exact"),
    (r"int mn = INT_MAX, mx = INT_MIN; for \(int x : a\)", "O(n)", "O(n)", "exact"),
    (r"int pos = -1; for \(int i = 0; i < n; \+\+i\) \{ if \(a\[i\] == 0\)", "O(n)", "O(n)", "exact"),
    (r"int cnt = 0; for \(int x : a\) \{ if \(x % 2 == 0\) continue; \+\+cnt; \}", "O(n)", "O(n)", "exact"),
    (r"priority_queue<int> pq; for \(int i = 0; i < n; \+\+i\) \{ int x; cin >> x; pq\.push\(x\); \} ll ans = 0; while \(!pq\.empty\(\)\)", "O(n log n)", "O(n)", "exact"),
    (r"vector<bool> is\(n \+ 1, true\)", "O(n log log n)", "O(n)", "exact"),
    (r"vector<int> spf\(n \+ 1\); iota\(spf\.begin\(\), spf\.end\(\), 0\)", "O(n log log n)", "O(n)", "exact"),
    (r"for \(int mask = 0; mask < \(1 << n\); \+\+mask\) for \(int sub = mask; sub; sub = \(sub - 1\) & mask\) \+\+cnt", "O(3^n)", "O(1)", "exact"),
    (r"unordered_map<int,int> mp; for \(int x : a\) \{ int t = x;", "O(n sqrt n)", "O(n)", "exact"),
    (r"vector<int> cnt\(31\); while \(q--\) \{ int x; cin >> x; for \(int b = 0; b < 31; \+\+b\) cnt\[b\] \+= \(x >> b\) & 1; \}", "O(m)", "O(1)", "exact"),
    (r"vector<ll> pref\(n \+ 1\); for \(int i = 0; i < n; \+\+i\) \{ ll x; cin >> x; pref\[i \+ 1\] = pref\[i\] \+ x; \} while \(q--\)", "O(n + m)", "O(n)", "exact"),
    (r"vector<int> diff\(n \+ 2\); while \(q--\)", "O(n + m)", "O(n)", "exact"),
    (r"vector<vector<ll>> a\(n \+ 1, vector<ll>\(m \+ 1\)\)", "O(n m + q)", "O(n m)", "exact"),
    (r"string s; cin >> s; int l = 0, r = \(int\)s\.size\(\) - 1; bool ok = true; while \(l < r\)", "O(n)", "O(1)", "exact"),
    (r"string s; cin >> s; int i = 0; while \(i < \(int\)s\.size\(\)\) \{ if \(s\[i\] == '0'\) i \+= 2; else i = i / 2 \+ 1; \}", "Unknown", "Unknown", "unknown"),
    (r"string s; cin >> s; int c = 0; for \(char ch : s\)", "O(n)", "O(1)", "exact"),
    (r"string s, t; cin >> s >> t; cout << \(s\.size\(\) \+ t\.size\(\)\)", "O(1)", "O(1)", "exact"),
    (r"string s; cin >> s; int i = 0; while \(i < \(int\)s\.size\(\) && s\[i\] == s\[0\]\) \+\+i;", "O(n)", "O(1)", "exact"),
    (r"string s, t; cin >> s >> t; int i = 0, j = 0; while \(i < \(int\)s\.size\(\) && j < \(int\)t\.size\(\)\)", "O(n m)", "O(1)", "exact"),
    (r"int i = 0, j = 0; while \(i < \(int\)s\.size\(\) && j < \(int\)t\.size\(\)\)", "O(n m)", "O(1)", "exact"),
    (r"while \(i < n\) \{ if \(a\[i\] > 0\) i \+= a\[i\] % 2 \+ 1; else \+\+i; \}", "Unknown", "Unknown", "unknown"),
    (r"int i = 0; while \(i < n\) \{ if \(a\[i\] & 1\) \+\+i; else i \+= a\[i\] % 3 \+ 1; \}", "Unknown", "Unknown", "unknown"),
    (r"while \(n > 0\) \{ if \(a\[n - 1\] > m\) n -= a\[n - 1\] % 2 \+ 1; else --n; if \(n < 0\) break; \}", "Unknown", "Unknown", "unknown"),
    (r"int l = 0, r = n - 1; while \(l <= r\) \{ int m = \(l \+ r\) / 2;", "O(log n)", "O(1)", "exact"),
    (r"ll base = prep_\d+\(a\); int q; cin >> q; ll ans = 0; while \(q--\)", "O(n + m)", "O(n)", "exact"),
    (r"auto base = helper_\d+\(a\); while \(q--\)", "O(n + m)", "O(n)", "exact"),
    (r"vector<int> a\(n\); for \(int i = 0; i < n; \+\+i\) cin >> a\[i\]; ll s = 0; for \(int v : a\) s \+= v", "O(n)", "O(n)", "exact"),
    (r"vector<int> a\(n\); for \(int i = 0; i < n; \+\+i\) cin >> a\[i\]; ll ans = 0; for \(int x : a\) ans \+= x", "O(n)", "O(n)", "exact"),
    (r"for \(int i = 0; i < n; \+\+i\) cin >> a\[i\]; ll ans = 0; for \(int x : a\) \{ if \(x > 0\) ans \+= x;", "O(n)", "O(n)", "exact"),
    (r"int i = \(int\)s\.size\(\) - 1, j = \(int\)t\.size\(\) - 1; while \(i >= 0 && j >= 0 && s\[i\] == t\[j\]\)", "O(n + m)", "O(1)", "exact"),
    (r"while \(n > 1\) \{ if \(n & 1\) n = n \* 3 \+ 1; else n /= 2; if \(n > 1000000\) break; \}", "Unknown", "Unknown", "unknown"),
    (r"int x = a\[0\]; while \(x < n && a\[x\] < 100\) x = a\[x\] \+ 1;", "Unknown", "Unknown", "unknown"),
    (r"long long l, r; cin >> l >> r; while \(l < r\) \{ long long m = \(l \+ r\) / 2; if \(m \* m >= r\) r = m; else l = m \+ 1; \}", "O(log S)", "O(1)", "exact"),
    (r"sort\(all\(a\)\); while \(q--\) \{ int x; cin >> x; cout << lower_bound\(all\(a\), x\) - a\.begin\(\)", "O(n log n + m log n)", "O(n)", "exact"),
    (r"while \(n--\) \{ sort\(all\(a\)\); if \(a\.empty\(\)\) break; a\.pop_back\(\); \}", "O(n^2 log n)", "O(n)", "exact"),
    (r"vector<vector<int>> pref\(31, vector<int>\(n \+ 1\)\)", "O(n + m)", "O(n)", "exact"),
    (r"vector<int> cnt\(100001\); for \(int i = 0; i < n; \+\+i\)", "O(n + m)", "O(1)", "exact"),
    (r"int i = 0; while \(i < n\) \{ if \(a\[i\] % 2\) \+\+i; else i \+= a\[i\] % 3 \+ 1; \}", "Unknown", "Unknown", "unknown"),
    (r"int l = 0, r = 0; ll sum = 0; for \(; r < n; \+\+r\) \{ sum \+= a\[r\]; if \(r - l \+ 1 > 5\) sum -= a\[l\+\+\]; \}", "O(n)", "O(1)", "exact"),
    (r"cout << accumulate\(all\(a\), 0LL\)", "O(n)", "O(1)", "exact"),
    (r"set<int> s; for \(int i = 0; i < n; \+\+i\) \{ int x; cin >> x; s\.insert\(x\); \}", "O(n log n)", "O(n)", "exact"),
    (r"int negatives = 0; for \(int i = 0; i < n; \+\+i\) if \(a\[i\] < 0\) \+\+negatives;", "O(n)", "O(n)", "exact"),
]

changed = 0
kept = 0
for path in sorted(glob.glob(os.path.join(DATASETS, "cpp-pack-level0-400-*.manifest.json"))):
    with open(path, encoding="utf-8") as handle:
        manifest = json.load(handle)
    stem = path[: -len(".manifest.json")]
    with open(stem + ".cpp", encoding="utf-8") as handle:
        source = handle.read()
    code = source[source.index("int pack_level0_400_pack_main()"):]
    code = re.sub(r"\s+", " ", code).strip()
    matched = None
    for signature, time, space, conf in SIGNATURES:
        if re.search(signature, code):
            matched = (time, space, conf)
            break
    if matched is None:
        kept += 1
        continue
    dirty = False
    for case in manifest.get("cases", []):
        if (case["time"], case["space"], case["confidence"]) != matched:
            case["time"], case["space"], case["confidence"] = matched
            case["tags"] = list({"adjudicated", *case.get("tags", [])})
            dirty = True
            changed += 1
    if dirty:
        with open(path, "w", encoding="utf-8", newline="\n") as handle:
            json.dump(manifest, handle, indent=1)
print(f"cases relabeled: {changed}; shapes left unadjudicated: {kept}")
