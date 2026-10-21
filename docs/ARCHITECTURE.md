# Architecture

Project X keeps source code on the developer's machine. The extension passes the current C++ selection to a local analyzer process over standard input; the analyzer invokes a local Clang executable to obtain its JSON AST and returns one JSON result on standard output. No network service is part of this path.

```text
C++ selection -> VS Code/Kiro command -> local analyzer CLI -> Clang JSON AST -> rule engine -> result JSON -> quiet editor notification
```

## Current analysis pipeline

```text
selected function/block
  -> local Clang JSON AST
  -> AST scope + declaration-identity symbol extraction
  -> bounded forward data-flow + path-sensitive CFG edge states
  -> symbolic bound expressions (n, n², n³ log²n, …)
  -> loop / branch composition
  -> same-file call-graph DFS + argument-sensitive summary substitution
  -> CP structural recognizers + evidence score
  -> structured exact / estimated / unknown result
```

The result is driven by AST structure and symbolic expressions, not a lookup of test snippets. Clang declaration IDs are used where available, so a nested/local `int n` or reused loop variable `i` does not inherit a same-spelled variable's bound from another scope. For example, `i < n * n` is represented as an `n²` bound; a child loop bounded by that `i` inherits that expression; nesting multiplies the expression exponents. Sequential regions take the dominant expression (`n + n² -> n²`).

The current forward data-flow pass processes declarations and direct assignments in statement order and records the symbolic state entering each loop. It joins compatible `if/else` paths (for example, `limit = n` on both paths) and deliberately removes a bound when paths are incomparable (`limit = n` versus `limit = m`).

It also retains separate states at each `if/else` CFG edge. The path-sensitive rule proves direct finite guards such as `if (n <= 64)`: only that edge treats `n` as `O(1)`, then the analyzer takes the dominant cost of mutually exclusive edges rather than adding them. Thus a bounded `O(n²)` branch and an unbounded `O(n)` branch are correctly reported as `O(n)`. The same edge state is propagated into branch-contained loops inside a header-progressing `for` loop. Incomparable alternatives such as `O(n)` versus `O(m)` compose as their sum `O(n + m)` - the sound worst-case bound for mutually exclusive edges over independent dimensions. A `break` can only shorten a loop, so the unbroken trip count remains a valid published upper bound; the engine drops a bound only when the proof would need a lower-bound argument. The current slice does not yet execute arbitrary loop bodies, follow aliases, solve pointer writes, reason about arbitrary predicate correlations, or prove arbitrary `while`-loop progress through `continue`; those are later milestones.

Same-file helpers are resolved with DFS through the call graph before analysing their caller. Their summaries retain formal parameter dimensions and auxiliary space, then safely substitute a caller's proven atomic argument dimension: for example, a helper proven `O(n)` becomes `O(m)` at `scan(m)`, and `vector<int> build(n)` storage becomes `O(W)` at `build(W)`. Expressions such as `n / 2` preserve their proven `O(n)` upper bound. Ambiguous/non-symbolic arguments remain unproved rather than being guessed. A recursive cycle remains `Unknown` unless a recurrence rule proves it (currently one self-call on a parameter divided by a constant). This is conservative by design.

For direct boolean control arguments, the resolver also creates bounded context-sensitive summaries. When a caller passes `true` or `false` to a `bool` parameter, it clones the helper AST and prunes only direct `if (flag)`, `if (!flag)`, and equality/inequality checks against boolean literals. The selected branch is then analyzed normally. This is why a wrapper around a dual queue/priority-queue helper can receive the FIFO bound when it calls the helper with `false`. Arbitrary predicates, runtime boolean values, mutations, and indirect conditions remain unspecialized and use the helper's conservative worst-case summary.

The bounded alias pass reuses those declaration-identity facts for direct container references, iterator endpoints, and direct pointer aliases. For example, `const auto& view = values`, `last = view.end()`, and `cursor = values.data()` preserve the `O(n)` range cardinality through a local alias chain. The same rule supports direct indexing of a nested container as a safe per-neighbour upper bound. It is flow-sensitive for direct assignments and removes a fact when branches can select incompatible targets (for example an `n` container versus an `m` container). It does not yet prove heap/object-field aliasing, pointer arithmetic with unknown provenance, pointer writes through calls, or general alias sets.

## Competitive-programming recognition

The analyzer has a separate CP layer after declaration-aware data flow and before generic loop fallback. It does not match function names, comments, or a dataset row. Each rule requires a structural signature proved from Clang's AST and the symbolic state. For example, Bellman-Ford needs a scalar-bounded sequence of complete range passes plus a distance relaxation; Floyd-Warshall needs three passes over the same dimension plus a matrix relaxation; 0-1 BFS needs an adjacency traversal and a deque that uses both front/back insertion; Kahn processing needs an indegree decrement-to-zero gate before a worklist enqueue. Level-1 rules also understand a complete `1 << n` mask domain, compose an independent bit scan as `O(n 2^n)`, prove the canonical `(sub - 1) & mask` all-submask identity as `O(3^n)`, identify a prefix recurrence followed by a separate range-query pass, and prove typed bitmask-DP state tables: a mask table with nested index passes produces `O(n^k 2^n)` by symbolic composition, including SOS/subset and Hamilton-style transitions. The same DFS engine now resolves local C++ methods by Clang declaration identity, which permits structural helper summaries for CP data structures while avoiding collisions with STL methods; a least-significant-set-bit update proves a Fenwick-style method is `O(log n)`. Existing rules similarly cover Sieve/SPF, BFS/DFS/Dijkstra, DSU/Kruskal, sliding windows, counting sort, trie insertion, and selected DP forms.

The CP rules deliberately report `estimated` rather than pretending to have a formal whole-program proof. They attach an evidence score (currently 90-93%) only when every required structural signal is present. A partial resemblance falls through to the normal symbolic analyzer and may correctly remain `Unknown`. Graph summaries retain an explicit vertex parameter such as `n` through same-file helper substitution and use `m` for the independent adjacency/edge dimension; adjacency-only traversal APIs retain conventional `V`/`E` notation. This makes common CP code useful in the editor without turning algorithm names into a lookup table or hiding ambiguous code.

Constructor preprocessing is handled as a separate, deliberately narrow CP proof. For a sparse-table-style local object, the engine requires the same Clang declaration identity to drive both the shifting bit-width condition and the outer fill loop, a typed `vector<vector<T>>` assignment, exactly one inner fill loop, and no deeper loop under that fill. Only then does it compose the constructor's `O(n log n)` time and storage with the enclosing function. This lets setup and query dimensions remain separate (`O(m + n log n)`), and prevents a similarly shaped but cubic constructor from being under-reported.

The same interprocedural composition is now applied to graph setup. A helper is accepted as an adjacency builder only if its typed `vector<vector<T>>` storage is sized from the visible vertex scalar and a complete edge-container range pass performs `push_back` into that storage. A caller must then hold the typed returned graph and traverse its neighbours. These requirements produce `O(n + m)` setup/traversal time and retained auxiliary storage without relying on helper names such as `buildAdj`.

## Supported forms

The first vertical slice accepts a complete C++ function and uses Clang AST nodes, not source-text pattern matching, to prove only these forms:

- no loops/calls/allocation: `O(1)` time, `O(1)` auxiliary space;
- canonical `for`/`while` loops with ++, --, +=, or -= against a symbolic input expression: O(expression);
- canonical for loops with *= or /= against a parameter, plus Euclid's %= loop: O(log n);
- arbitrarily deep canonical nested linear loops: O(n^k) for fixed nesting depth k;
- linear/logarithmic nesting: O(n^k log^r n);
- square-bound trial division: O(sqrt n).

The composition rules distinguish an inner loop bounded by the original input from one bounded by a geometrically changing outer index. A halving outer loop plus a fixed n-sized inner loop is O(n log n), while an inner loop bounded by i where i halves from n is the geometric series O(n). Two independent logarithmic loops are O(log^2 n).

Recognized C++17 free algorithms are represented by a local complexity knowledge base and still compose through the same AST rules. Examples include `sort` (`O(n log n)`), range scans such as `max_element` (`O(n)`), and binary-search algorithms (`O(log n)`). Selected container calls are typed from the AST before classification: ordered `map`/`set` operations are `O(log n)`, `unordered_*` operations use their `O(n)` worst case, and `priority_queue` insertion/removal is `O(log n)`. The standard-library prelude is declarations only, so parsing does not rely on an installed MSVC/GCC standard-library header path.

The auxiliary-space pass identifies direct size-based construction of `vector`, `deque`, and `string` and derives its symbolic size (for example, `vector<int> a(n * n)` gives `O(n²)`). Return/move wrappers around an already-accounted local container are not mistaken for a second unknown allocation. It returns `Unknown` rather than guessing for nested/indirect allocations or algorithms whose temporary storage is implementation-dependent.

Sequential supported loops are summed and reduced to the dominant term. The canonical Sieve of Eratosthenes and smallest-prime-factor sieve are recognized as separate AST patterns: an `i*i <= n` outer bound, a table guard, and an inner marking loop beginning at `i*i` and advancing by `i`. The SPF form additionally proves its table-initialization loop (`table[i] = i`) before reporting `O(n log log n)`. Only those proof rules report that bound; superficially similar nested loops remain Unknown. Any other call, allocation, range/do loop, unproved iterator/container operation, or unproved bound returns Unknown.

## LibTooling status

Project X now has a locally built native LibTooling prototype (`native-analyzer/`) using the pinned LLVM development build. It traverses Clang's typed AST, uses direct callee resolution, and builds a CFG for every main-file function. Its output is a compact fact stream (function names, direct/self calls, loop kinds, and CFG block counts) intended to become the native call-graph and control-flow layer.

The shipped rule engine still consumes local `clang++ -Xclang -ast-dump=json` because it has the mature symbolic-expression and proof pipeline. This is deliberate: the transition is **hybrid**, not a risky replacement. LibTooling is the source of stronger semantic/control-flow facts as each native fact is validated against the same corpus; JSON remains the backwards-compatible fallback and feeds the existing explanation renderer. Neither path uses the network or uploads source.

The next native milestone is to emit per-function loop bounds, declarations, and resolved call edges, then use those facts in the TypeScript rule engine behind parity tests. The native executable is development infrastructure for now, not an extra dependency that end users must build or download before installing the extension.

The public quality goal remains 95%+ precision on a locked, manually reviewed hidden holdout **for supported cases**, not a claim that every valid C++ program can be classified.

Set `PROJECT_X_CLANG` to a local `clang++` executable when it is not on `PATH`. The extension's `projectX.analyzerPath` must point to the built local analyzer command.
