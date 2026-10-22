import { analyseFunctionAst, callArguments, segmentTreeConstructorSummary } from "./analyze-ast.js";
import type { LocalFunctionSummary, LocalRecordOwnedStorage, LocalSummaryValue } from "./analyze-ast.js";
import { formatBound, maxBounds, parseBound } from "./bound.js";
import { clangAstFor, findFunctionDeclarations, findFunctionNamed, findMethodDeclarations } from "./clang.js";
import type { AnalysisResult, ClangNode, Complexity } from "./model.js";
import { nativeFactsFor, type NativeFacts } from "./native-facts.js";

// This is intentionally declarations only: some Windows LLVM installs have no MSVC STL include path.
// Clang still builds a real AST for the selected code without depending on those external headers.
const standardPrelude = [
  "using size_t = unsigned long long;",
  // Contest code routinely does `#define int int64` (or int64_t); the fixed-width
  // aliases must exist or every dependent typedef (vector<int64>) collapses
  // into Clang recovery expressions that no rule can cost.
  "using int8_t = signed char; using int16_t = short; using int32_t = int; using int64_t = long long;",
  "using uint8_t = unsigned char; using uint16_t = unsigned short; using uint32_t = unsigned int; using uint64_t = unsigned long long;",
  "using int64 = int64_t; using int32 = int32_t; using uint64 = uint64_t; using uint32 = uint32_t;",
  "namespace std {",
  "template<class A, class B> struct pair { A first; B second; pair(); pair(const A&, const B&); };",
  "template<class... Ts> class tuple { public: tuple(Ts...); }; template<class A, class B, class C> class tuple<A, B, C> { public: A first; B second; C third; tuple(); tuple(const A&, const B&, const C&); }; template<class T> struct tuple_size; template<class A, class B, class C> struct tuple_size<tuple<A, B, C>> { static constexpr unsigned long long value = 3; }; template<unsigned long long I, class T> struct tuple_element; template<class A, class B, class C> struct tuple_element<0, tuple<A, B, C>> { using type = A; }; template<class A, class B, class C> struct tuple_element<1, tuple<A, B, C>> { using type = B; }; template<class A, class B, class C> struct tuple_element<2, tuple<A, B, C>> { using type = C; }; template<unsigned long long I, class A, class B, class C> typename tuple_element<I, tuple<A, B, C>>::type& get(tuple<A, B, C>&); template<unsigned long long I, class A, class B, class C> typename tuple_element<I, tuple<A, B, C>>::type&& get(tuple<A, B, C>&&);",
  "template<class A, class B, class C, class D> class tuple<A, B, C, D> { public: A first; B second; C third; D fourth; tuple(); tuple(const A&, const B&, const C&, const D&); }; template<class A, class B, class C, class D> struct tuple_size<tuple<A, B, C, D>> { static constexpr unsigned long long value = 4; }; template<class A, class B, class C, class D> struct tuple_element<0, tuple<A, B, C, D>> { using type = A; }; template<class A, class B, class C, class D> struct tuple_element<1, tuple<A, B, C, D>> { using type = B; }; template<class A, class B, class C, class D> struct tuple_element<2, tuple<A, B, C, D>> { using type = C; }; template<class A, class B, class C, class D> struct tuple_element<3, tuple<A, B, C, D>> { using type = D; }; template<unsigned long long I, class A, class B, class C, class D> typename tuple_element<I, tuple<A, B, C, D>>::type& get(tuple<A, B, C, D>&); template<unsigned long long I, class A, class B, class C, class D> typename tuple_element<I, tuple<A, B, C, D>>::type&& get(tuple<A, B, C, D>&&);",
  // Clang recognizes brace-initializers only when initializer_list has this
  // ABI-mandated two-field layout.  Keeping it here avoids depending on a
  // platform STL header while still parsing normal CP test harnesses.
  "template<class T> class initializer_list { const T* __begin_; unsigned long long __size_; public: const T* begin() const; const T* end() const; unsigned long long size() const; };",
  "class string { public: string(); string(const char*); string& operator+=(const char*); string& operator+=(char); string& operator+=(const string&); string& append(unsigned long long, char); char& operator[](long long); const char& operator[](long long) const; char* begin(); char* end(); const char* begin() const; const char* end() const; long long size() const; bool empty() const; void push_back(char); void pop_back(); };",
  "template<class T> class vector { public: vector() {} explicit vector(long long) {} vector(long long, const T&) {} vector(initializer_list<T>) {} template<class I> vector(I, I) {} T& operator[](long long) { return *static_cast<T*>(nullptr); } const T& operator[](long long) const { return *static_cast<const T*>(nullptr); } T* begin() { return nullptr; } T* end() { return nullptr; } const T* begin() const { return nullptr; } const T* end() const { return nullptr; } T* data() { return nullptr; } const T* data() const { return nullptr; } long long size() const { return 0; } bool empty() const { return true; } void push_back(const T&) {} template<class... A> void emplace_back(A...) {} void pop_back() {} T& front() { return *static_cast<T*>(nullptr); } T& back() { return *static_cast<T*>(nullptr); } const T& front() const { return *static_cast<const T*>(nullptr); } const T& back() const { return *static_cast<const T*>(nullptr); } void clear() {} void resize(long long) {} void resize(long long, const T&) {} void reserve(long long) {} void assign(long long, const T&) {} template<class I> void assign(I, I) {} T* erase(T*) { return nullptr; } T* erase(T*, T*) { return nullptr; } T* insert(T*, const T&) { return nullptr; } };",
  "template<class T, class... R> class deque { public: T* begin(); T* end(); const T* begin() const; const T* end() const; long long size() const; bool empty() const; void push_back(const T&); void push_front(const T&); void pop_back(); void pop_front(); T& front(); T& back(); };",
  "template<class T, class... R> class queue { public: void push(const T&); template<class... A> void emplace(A...); void pop(); T& front(); T& back(); bool empty() const; long long size() const; };",
  "template<class T, class... R> class stack { public: void push(const T&); template<class... A> void emplace(A...); void pop(); T& top(); bool empty() const; long long size() const; };",
  "template<class T, class... R> class priority_queue { public: void push(const T&); template<class... A> void emplace(A...); void pop(); T& top(); bool empty() const; long long size() const; };",
  "template<class T, class... R> class set { public: T* begin(); T* end(); const T* begin() const; const T* end() const; T* rbegin(); T* rend(); T* find(const T&) const; long long count(const T&) const; bool contains(const T&) const; T* lower_bound(const T&) const; T* upper_bound(const T&) const; void insert(const T&); void erase(const T&); void erase(T*); long long size() const; bool empty() const; void clear(); };",
  "template<class T, class... R> class multiset { public: T* begin(); T* end(); const T* begin() const; const T* end() const; T* rbegin(); T* rend(); T* find(const T&) const; long long count(const T&) const; bool contains(const T&) const; T* lower_bound(const T&) const; T* upper_bound(const T&) const; void insert(const T&); void erase(const T&); void erase(T*); long long size() const; bool empty() const; }; template<class K, class V, class... R> class multimap { public: pair<K, V>* begin(); pair<K, V>* end(); bool empty() const; long long size() const; void insert(const pair<K, V>&); pair<K, V>* lower_bound(const K&); void erase(pair<K, V>*); };",
  "template<class T, class... R> class unordered_set { public: T* begin(); T* end(); const T* begin() const; const T* end() const; T* find(const T&) const; long long count(const T&) const; bool contains(const T&) const; void insert(const T&); template<class... A> void emplace(A...); void erase(const T&); void erase(T*); long long size() const; bool empty() const; void clear(); };",
  "template<class K, class V, class... R> class map { public: pair<K, V>* begin(); pair<K, V>* end(); const pair<K, V>* begin() const; const pair<K, V>* end() const; pair<K, V>* find(const K&) const; bool contains(const K&) const; pair<K, V>* lower_bound(const K&) const; pair<K, V>* upper_bound(const K&) const; long long count(const K&) const; V& operator[](const K&); void insert(const pair<K, V>&); void erase(const K&); void erase(pair<K, V>*); long long size() const; bool empty() const; };",
  "template<class K, class V, class... R> class unordered_map { public: pair<K, V>* begin(); pair<K, V>* end(); const pair<K, V>* begin() const; const pair<K, V>* end() const; pair<K, V>* find(const K&) const; bool contains(const K&) const; long long count(const K&) const; V& operator[](const K&); pair<pair<K, V>*, bool> emplace(const K&, const V&); void insert(const pair<K, V>&); void erase(const K&); void erase(pair<K, V>*); long long size() const; bool empty() const; };",
  "template<class T, class... R> class list { public: list(); T* begin(); T* end(); T* rbegin(); T* rend(); long long size() const; bool empty() const; void push_back(const T&); T& front(); T& back(); void splice(T*, list&, T*, T*); void sort(); void erase(T*); }; template<class T, class... R> class forward_list { public: T* begin(); T* end(); T* before_begin(); bool empty() const; void push_front(const T&); T* erase_after(T*); };",
  "template<class T, unsigned long long N> class bitset { public: bitset(); bool operator[](unsigned long long) const; bitset& set(unsigned long long, bool = true); bitset& operator<<=(unsigned long long); bitset operator<<(unsigned long long) const; bitset& operator|=(const bitset&); };",
  "template<class T, unsigned long long Count> struct array { T storage[Count]; T& operator[](long long); const T& operator[](long long) const; T* begin(); T* end(); const T* begin() const; const T* end() const; T* rbegin(); T* rend(); const T* rbegin() const; const T* rend() const; long long size() const; bool empty() const; void fill(const T&); };",
  "template<class Signature> class function; template<class R, class... A> class function<R(A...)> { public: function() {} template<class F> function(F) {} template<class F> function& operator=(F) { return *this; } R operator()(A...) const { return *static_cast<R*>(nullptr); } }; template<class... A> class function<void(A...)> { public: function() {} template<class F> function(F) {} template<class F> function& operator=(F) { return *this; } void operator()(A...) const {} };",
  "template<class T> struct numeric_limits { static T max(); };",
  "template<class I> void sort(I, I); template<class I, class C> void sort(I, I, C) {} template<class I> void stable_sort(I, I); template<class I, class C> void stable_sort(I, I, C) {} template<class I> void partial_sort(I, I, I); template<class I> void nth_element(I, I, I); template<class I> void inplace_merge(I, I, I); template<class I> void make_heap(I, I); template<class I> void sort_heap(I, I);",
  "template<class I, class T> I lower_bound(I, I, const T&); template<class I, class T> I upper_bound(I, I, const T&); template<class I, class T> pair<I, I> equal_range(I, I, const T&);",
  "template<class I> I max_element(I, I); template<class I> I min_element(I, I); template<class I, class T> I find(I, I, const T&); template<class I, class P> I find_if(I, I, P); template<class I, class T> long long count(I, I, const T&); template<class I, class P> long long count_if(I, I, P);",
  "template<class I, class T> T accumulate(I, I, T); template<class I, class T> void iota(I, I, T); template<class I, class P> bool all_of(I, I, P); template<class I, class P> bool any_of(I, I, P); template<class I, class P> bool none_of(I, I, P); template<class I, class F> F for_each(I, I, F);",
  "template<class I, class O> O copy(I, I, O); template<class I, class P, class O> O copy_if(I, I, O, P); template<class I, class O> O copy_n(I, long long, O); template<class I, class T> void fill(I, I, const T&); template<class I, class T> I fill_n(I, long long, const T&); template<class I, class O, class F> O transform(I, I, O, F);",
  "template<class I> void reverse(I, I); template<class I> I rotate(I, I, I); template<class I, class P> I stable_partition(I first, I, P) { return first; } template<class I, class O> O merge(I, I, I, I, O out); template<class I, class T> void replace(I, I, const T&, const T&); template<class I, class P, class T> void replace_if(I, I, P, const T&); template<class I, class T> I remove(I first, I, const T&) { return first; } template<class I, class P> I remove_if(I first, I, P) { return first; } template<class I> I unique(I first, I) { return first; } template<class I, class P> I partition(I first, I, P) { return first; } template<class I> bool is_sorted(I, I); template<class I> I prev(I); template<class I> I next(I);",
  "template<class T> const T& max(const T&, const T&); template<class T> const T& min(const T&, const T&); template<class T> void swap(T&, T&); template<class T> T abs(T); long long llabs(long long); template<class T> string to_string(T); template<class A, class B> pair<A, B> make_pair(A, B); template<class T = void> struct greater { bool operator()(const T&, const T&) const; }; template<> struct greater<void> { template<class A, class B> bool operator()(const A&, const B&) const; };",
  "template<class T, auto Count> T* begin(T (&)[Count]); template<class T, auto Count> T* end(T (&)[Count]); template<class C> auto begin(C& c) -> decltype(c.begin()); template<class C> auto begin(const C& c) -> decltype(c.begin()); template<class C> auto end(C& c) -> decltype(c.end()); template<class C> auto end(const C& c) -> decltype(c.end());",
  "template<class I, class T> bool binary_search(I, I, const T&); template<class T> T gcd(T, T); template<class T> T lcm(T, T);",
  "template<class I> long long distance(I, I); template<class T> T&& move(T&); double sqrt(double); double pow(double, double); long double pow(long double, long double); float pow(float, float);",
  "}",
  "class __project_x_stream { public: __project_x_stream* tie(__project_x_stream*); __project_x_stream* tie(); __project_x_stream* flush(); long long precision() const; long long precision(long long); }; extern __project_x_stream cin; extern __project_x_stream cout; extern __project_x_stream cerr; extern __project_x_stream clog; __project_x_stream& endl(__project_x_stream&);",
  "template<class T> __project_x_stream& operator<<(__project_x_stream&, const T&); __project_x_stream& operator<<(__project_x_stream&, __project_x_stream& (*)(__project_x_stream&)); template<class T> __project_x_stream& operator>>(__project_x_stream&, T&);",
  "int system(const char*); int scanf(const char*, ...); int printf(const char*, ...);",
  "using namespace std;",
  "constexpr int INT_MAX = 2147483647; constexpr int INT_MIN = (-2147483647 - 1);"
].join("\n");

function selectedFunctionName(header: string): string | undefined {
  const beforeArguments = header.slice(0, header.lastIndexOf("(")).trim();
  const candidate = beforeArguments.split(/\s+/).at(-1)?.split("::").at(-1);
  return candidate && /^[A-Za-z_][A-Za-z0-9_]*$/.test(candidate) ? candidate : undefined;
}

function functionNamesIn(source: string): string[] {
  // This is selection routing only; complexity analysis still comes from
  // Clang's AST. A regex sees the `sort(` before a lambda body and can wrongly
  // choose `sort` as a function. Scan C++ delimiters instead and consider only
  // opening braces at global scope, where a complete selected function lives.
  const names: string[] = [];
  let depth = 0;
  let segmentStart = 0;
  let quote: "'" | '"' | undefined;
  let lineComment = false;
  let blockComment = false;
  for (let index = 0; index < source.length; index += 1) {
    const current = source[index];
    const next = source[index + 1];
    if (lineComment) {
      if (current === "\n") lineComment = false;
      continue;
    }
    if (blockComment) {
      if (current === "*" && next === "/") { blockComment = false; index += 1; }
      continue;
    }
    if (quote) {
      if (current === "\\") { index += 1; continue; }
      if (current === quote) quote = undefined;
      continue;
    }
    if (current === "/" && next === "/") { lineComment = true; index += 1; continue; }
    if (current === "/" && next === "*") { blockComment = true; index += 1; continue; }
    if (current === "'" || current === '"') { quote = current; continue; }
    if (current === "{") {
      if (depth === 0) {
        const header = source.slice(segmentStart, index);
        const name = selectedFunctionName(header);
        if (name && !["for", "while", "if", "switch", "catch"].includes(name) && /\)/.test(header)) names.push(name);
      }
      depth += 1;
      continue;
    }
    if (current === "}") {
      depth = Math.max(0, depth - 1);
      if (depth === 0) segmentStart = index + 1;
      continue;
    }
    if (current === ";" && depth === 0) segmentStart = index + 1;
  }
  return names;
}

function withoutIncludes(source: string): string {
  return source.split(/\r?\n/).filter((line) => !line.trimStart().startsWith("#include")).join("\n");
}

/**
 * Selection validation only.  It deliberately does not participate in
 * analysis: Clang remains the source of truth for C++ semantics.  Without
 * this guard a selection made entirely of `//`-commented examples is wrapped
 * as an empty synthetic function and misleadingly reported as O(1).
 */
function withoutComments(source: string): string {
  let result = "";
  let quote: "'" | '"' | undefined;
  let lineComment = false;
  let blockComment = false;
  for (let index = 0; index < source.length; index += 1) {
    const current = source[index];
    const next = source[index + 1];
    if (lineComment) {
      if (current === "\n") { lineComment = false; result += current; }
      continue;
    }
    if (blockComment) {
      if (current === "*" && next === "/") { blockComment = false; index += 1; }
      continue;
    }
    if (quote) {
      result += current;
      if (current === "\\") { result += next ?? ""; index += 1; continue; }
      if (current === quote) quote = undefined;
      continue;
    }
    if (current === "/" && next === "/") { lineComment = true; index += 1; continue; }
    if (current === "/" && next === "*") { blockComment = true; index += 1; continue; }
    if (current === "'" || current === '"') quote = current;
    result += current;
  }
  return result;
}

function translationUnitConstants(ast: ClangNode): Set<string> {
  // The set holds BOTH constant names and their declaration ids. Consumers
  // resolve a DeclRefExpr by id when Clang provides one, so a parameter that
  // shadows a global constant (`const int N = 5; int f(int N)`) is not
  // mistaken for the constant - name-only matching would cost the shadowed
  // loop as O(1).
  const constants = new Set<string>();
  for (const node of ast.inner ?? []) {
    // Enum constants: `enum { SIZE = 100 }` - the EnumConstantDecl is a
    // compile-time constant usable as a loop bound.
    if (node.kind === "EnumDecl") {
      for (const constant of node.inner ?? []) {
        if (constant.kind === "EnumConstantDecl" && constant.name) {
          constants.add(constant.name);
          if (constant.id) constants.add(constant.id);
        }
      }
      continue;
    }
    if (node.kind !== "VarDecl" || !node.name) continue;
    let hasNumericInitializer = false;
    const visit = (current: ClangNode): void => {
      if (current.kind === "IntegerLiteral" || current.kind === "FloatingLiteral") hasNumericInitializer = true;
      for (const child of current.inner ?? []) visit(child);
    };
    visit(node);
    if (hasNumericInitializer) {
      constants.add(node.name);
      if (node.id) constants.add(node.id);
    }
  }
  return constants;
}

/** Source routing only: restrict class-method summaries to user records. */
function localRecordNamesIn(source: string): Set<string> {
  const names = new Set<string>();
  for (const match of source.matchAll(/\b(?:class|struct)\s+([A-Za-z_][A-Za-z0-9_]*)/g)) names.add(match[1]);
  return names;
}

/**
 * Discover storage owned by local records from Clang declarations. A member is
 * counted only when a constructor initializer constructs vector/deque/string
 * storage from one of its formal arguments. This lets a caller's `Tree t(n)`
 * inherit O(n) space without hard-coding any CP data-structure names.
 */
function localRecordOwnedStorage(ast: ClangNode, localRecordNames: ReadonlySet<string>): LocalRecordOwnedStorage {
  const result = new Map<string, number[]>();
  const referencesParameter = (node: ClangNode, parameter: string): boolean => {
    if (node.kind === "DeclRefExpr" && node.referencedDecl?.name === parameter) return true;
    return (node.inner ?? []).some((child) => referencesParameter(child, parameter));
  };
  const visit = (node: ClangNode): void => {
    if (node.kind === "CXXRecordDecl" && node.name && localRecordNames.has(node.name)) {
      const dimensions: number[] = [];
      for (const constructor of (node.inner ?? []).filter((child) => child.kind === "CXXConstructorDecl")) {
        const parameters = (constructor.inner ?? []).filter((child) => child.kind === "ParmVarDecl");
        for (const initializer of (constructor.inner ?? []).filter((child) => child.kind === "CXXCtorInitializer")) {
          const dynamicConstructions: ClangNode[] = [];
          const collect = (current: ClangNode): void => {
            const type = current.type?.desugaredQualType ?? current.type?.qualType ?? "";
            if ((current.kind === "CXXConstructExpr" || current.kind === "CXXTemporaryObjectExpr") && /\b(?:vector|deque|string|basic_string)</.test(type)) dynamicConstructions.push(current);
            for (const child of current.inner ?? []) collect(child);
          };
          collect(initializer);
          for (const construction of dynamicConstructions) {
            parameters.forEach((parameter, index) => {
              if (parameter.name && referencesParameter(construction, parameter.name)) dimensions.push(index);
            });
          }
        }
      }
      if (dimensions.length > 0) result.set(node.name, dimensions);
    }
    for (const child of node.inner ?? []) visit(child);
  };
  visit(ast);
  return result;
}

function callableKey(declaration: ClangNode): string | undefined {
  return declaration.id ?? declaration.name;
}

function referencedCallableKeys(call: ClangNode): string[] {
  const keys = new Set<string>();
  const visit = (current: ClangNode): void => {
    // A call can point at a forward declaration while the resolver indexes
    // the out-of-line definition. Keep both identity and spelling for free
    // functions; declaration identity remains mandatory for methods.
    if (current.referencedDecl?.id) keys.add(current.referencedDecl.id);
    if (current.referencedDecl?.name) keys.add(current.referencedDecl.name);
    const member = current.referencedMemberDecl;
    const memberKey = typeof member === "string" ? member : member?.id ?? member?.name;
    if (memberKey) keys.add(memberKey);
    for (const child of current.inner ?? []) visit(child);
  };
  visit(call);
  return [...keys];
}

/** Returns same-file calls so helper summaries can be resolved in dependency order. */
function localCallees(functionDecl: ClangNode, localKeys: ReadonlySet<string>): string[] {
  const callees = new Set<string>();
  // `auto f = helper; f(n)` is still a same-file edge.  Preserve the AST
  // declaration identity of the local variable and map it to the function it
  // was initialized from; arbitrary reassignment is deliberately excluded.
  const functionAliases = new Map<string, string>();
  const aliasVisit = (node: ClangNode): void => {
    if (node.kind === "VarDecl") {
      const target = referencedCallableKeys(node).find((key) => localKeys.has(key));
      const aliasKeys = [node.id, node.name].filter((key): key is string => Boolean(key));
      if (target && aliasKeys.length > 0) for (const alias of aliasKeys) functionAliases.set(alias, target);
    }
    for (const child of node.inner ?? []) aliasVisit(child);
  };
  aliasVisit(functionDecl);
  const visit = (node: ClangNode): void => {
    if (node.kind === "CallExpr" || node.kind === "CXXMemberCallExpr") {
      const references = referencedCallableKeys(node);
      const localKey = references.find((key) => localKeys.has(key))
        ?? references.map((key) => functionAliases.get(key)).find((key): key is string => Boolean(key));
      if (localKey) callees.add(localKey);
    }
    for (const child of node.inner ?? []) visit(child);
  };
  visit(functionDecl);
  return [...callees];
}

function booleanLiteral(node: ClangNode | undefined): boolean | undefined {
  if (!node) return undefined;
  if (["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(node.kind ?? "")) return booleanLiteral(node.inner?.at(-1));
  if (node.kind === "CXXBoolLiteralExpr") return node.value === "true" || node.value === "1" || (node.value as unknown) === true;
  if (node.kind === "IntegerLiteral") return node.value === "0" ? false : node.value === "1" ? true : undefined;
  return undefined;
}

function isParameterReference(node: ClangNode | undefined, parameterName: string): boolean {
  if (!node) return false;
  if (["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(node.kind ?? "")) return isParameterReference(node.inner?.at(-1), parameterName);
  return node.kind === "DeclRefExpr" && node.referencedDecl?.name === parameterName;
}

/** Returns the truth value of a direct boolean guard for a literal argument. */
function booleanGuardOutcome(condition: ClangNode | undefined, parameterName: string, argument: boolean): boolean | undefined {
  if (!condition) return undefined;
  if (["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(condition.kind ?? "")) return booleanGuardOutcome(condition.inner?.at(-1), parameterName, argument);
  if (isParameterReference(condition, parameterName)) return argument;
  if (condition.kind === "UnaryOperator" && condition.opcode === "!") return !argument;
  if (condition.kind !== "BinaryOperator" || !["==", "!="].includes(condition.opcode ?? "") || (condition.inner?.length ?? 0) < 2) return undefined;
  const [left, right] = condition.inner!;
  const literal = booleanLiteral(right);
  if (isParameterReference(left, parameterName) && literal !== undefined) return condition.opcode === "==" ? argument === literal : argument !== literal;
  const reversedLiteral = booleanLiteral(left);
  if (isParameterReference(right, parameterName) && reversedLiteral !== undefined) return condition.opcode === "==" ? argument === reversedLiteral : argument !== reversedLiteral;
  return undefined;
}

/**
 * Bounded AST specialization for a literal boolean parameter. Only direct
 * boolean conditions are folded; all other control flow is retained exactly.
 * This is the semantic equivalent of following a single known call edge, not
 * a source-text algorithm-name shortcut.
 */
function specializeBooleanBranches(node: ClangNode, parameterName: string, argument: boolean): ClangNode {
  if (node.kind === "IfStmt") {
    const outcome = booleanGuardOutcome(node.inner?.[0], parameterName, argument);
    if (outcome !== undefined) {
      const branches = (node.inner ?? []).slice(1);
      return specializeBooleanBranches(outcome ? branches[0] ?? { kind: "NullStmt" } : branches[1] ?? { kind: "NullStmt" }, parameterName, argument);
    }
  }
  return { ...node, inner: node.inner?.map((child) => specializeBooleanBranches(child, parameterName, argument)) };
}

function summaryValue(result: ReturnType<typeof analyseFunctionAst>): LocalSummaryValue | undefined {
  return result.confidence !== "unknown" && result.worstCaseTime !== "Unknown"
    ? { value: result.worstCaseTime, auxiliarySpace: result.auxiliarySpace, confidence: result.confidence, memoStateDims: result.memoStateDims }
    : undefined;
}

/**
 * DFS over same-file functions. A helper is summarised before every caller, so
 * declaration order does not affect analysis. A recursive cycle remains absent
 * from the cost map and is therefore conservatively reported as Unknown unless
 * the recurrence recogniser proves it separately.
 */
function resolveLocalFunctionCosts(functions: ClangNode[], constants: ReadonlySet<string>, ownedRecordStorage?: LocalRecordOwnedStorage): { costs: Map<string, LocalFunctionSummary>; resolve: (name: string) => void; propagateMemoStateContexts: () => void } {
  const declarations = new Map<string, ClangNode>();
  const aliases = new Map<string, string>();
  for (const functionDecl of functions) {
    const key = callableKey(functionDecl);
    if (!key) continue;
    declarations.set(key, functionDecl);
    // Selection routing has a free-function spelling. Methods are deliberately
    // resolved only by Clang declaration identity to avoid collisions such as
    // a local `find` method versus standard-library declarations.
    if (functionDecl.kind === "FunctionDecl" && functionDecl.name) aliases.set(functionDecl.name, key);
  }
  // Clang call sites may reference either the definition id or a redeclared
  // function's earlier id. Retain the spelling as a free-function fallback;
  // methods remain identity-only so class members with equal names stay safe.
  const localKeys = new Set([...declarations.keys(), ...aliases.keys()]);
  const costs = new Map<string, LocalFunctionSummary>();
  const visiting = new Set<string>();

  const resolve = (nameOrKey: string): void => {
    const key = aliases.get(nameOrKey) ?? nameOrKey;
    if (costs.has(key) || visiting.has(key)) return;
    const functionDecl = declarations.get(key);
    if (!functionDecl) return;
    visiting.add(key);
    for (const callee of localCallees(functionDecl, localKeys)) if (callee !== key) resolve(callee);
    const summary = analyseFunctionAst(functionDecl, costs, constants, ownedRecordStorage);
    const generic = summaryValue(summary);
    if (generic) {
      const parameterNodes = (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl");
      const scalarNames = new Set(parameterNodes
        .filter((node) => !/\b(?:vector|deque|array|string)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))
        .map((node) => node.name)
        .filter((name): name is string => Boolean(name)));
      const scalarNPosition = parameterNodes.findIndex((node) => node.name === "n"
        && !/\b(?:vector|deque|array|string)\s*</.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""));
      let containerIndex = 0;
      const parameters = parameterNodes
          .flatMap((node, parameterIndex) => {
            if (!node.name) return [];
            const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
            // Tuple element shape alone is not graph evidence: query packs
            // use the same pair/array syntax. Preserve m only for an
            // explicitly edge/arc-named independent input.
            const graphLike = /(?:edge|arc)/i.test(node.name);
            // A scalar `n` plus a `queries`/`ops`/`requests` container has
            // two independent dimensions. Preserve the query count as m;
            // treating it as another n loses the distinction needed by range
            // structures, LCA batches, and offline-query algorithms.
            const queryLike = /(?:^q$|qs|quer(?:y|ies)|requests?|events?)/i.test(node.name);
            const symbol = /\b(?:vector|deque|array|string)\b/.test(type)
              ? graphLike && scalarNames.has("V") ? "E"
                : graphLike && scalarNames.has("n") ? "m"
                  : queryLike && scalarNames.has("n") && scalarNPosition >= 0 && scalarNPosition < parameterIndex ? "m"
                  : containerIndex++ === 0 ? "n" : "m"
              : node.name;
            return [{ name: node.name, symbol }];
          });
      const booleanSpecializations = new Map<string, { whenFalse?: LocalSummaryValue; whenTrue?: LocalSummaryValue }>();
      for (const parameter of (functionDecl.inner ?? []).filter((node) => node.kind === "ParmVarDecl" && /\bbool\b/.test(node.type?.desugaredQualType ?? node.type?.qualType ?? ""))) {
        if (!parameter.name) continue;
        const whenFalse = summaryValue(analyseFunctionAst(specializeBooleanBranches(functionDecl, parameter.name, false), costs, constants, ownedRecordStorage));
        const whenTrue = summaryValue(analyseFunctionAst(specializeBooleanBranches(functionDecl, parameter.name, true), costs, constants, ownedRecordStorage));
        if (whenFalse || whenTrue) booleanSpecializations.set(parameter.name, { whenFalse, whenTrue });
      }
      costs.set(key, {
        ...generic,
        parameters,
        booleanSpecializations: booleanSpecializations.size > 0 ? booleanSpecializations : undefined
      });
      if (functionDecl.kind === "FunctionDecl" && functionDecl.name) {
        costs.set(functionDecl.name, costs.get(key)!);
      }
    }
    visiting.delete(key);
  };

  /**
   * A memoized recursive callee is summarised with its own parameter names as
   * state dimensions. Call sites pass the caller's dimensions (f(1, k) names
   * the space of the second coordinate k). When every same-file call site
   * binds a state dimension to a bare scalar or a resolvable bound, refine
   * the callee's summary to that caller context. State spaces are bounded by
   * the initial value because the memo proof only permits constant decrements.
   */
  const propagateMemoStateContexts = (): void => {
    const wb = String.fromCharCode(92, 98); // backslash-b: regex word boundary
    for (const [key, summary] of [...costs.entries()]) {
      if (!summary.memoStateDims || summary.memoStateDims.length === 0) continue;
      const decl = declarations.get(key);
      if (!decl) continue;
      const paramIndex = new Map(summary.parameters.map((parameter, index) => [parameter.symbol, index]));
      const refined: string[] = [];
      for (const caller of functions) {
        if (callableKey(caller) === key) continue;
        const findCalls = (node: ClangNode, acc: ClangNode[]): void => {
          if (node.kind === "CallExpr" || node.kind === "CXXMemberCallExpr") {
            const references_ = referencedCallableKeys(node);
            if (references_.some((candidate) => candidate === key || aliases.get(candidate) === key)) acc.push(node);
          }
          for (const child of node.inner ?? []) findCalls(child, acc);
        };
        const sites: ClangNode[] = [];
        findCalls(caller, sites);
        for (const site of sites) {
          const arguments_ = callArguments(site, costs);
          let body = /^O\((.+)\)$/.exec(summary.value)?.[1];
          if (!body) continue;
          let replaced = true;
          for (const dimension of summary.memoStateDims) {
            const index = paramIndex.get(dimension);
            if (index === undefined) continue;
            if (!new RegExp(wb + dimension + wb).test(body)) continue;
            const argument = arguments_[index];
            if (!argument) { replaced = false; break; }
            // A bare scalar argument names the caller's dimension directly; a
            // literal or complex argument leaves the callee dimension intact
            // (constants cannot bound a decrementing state space).
            let unwrapped = argument;
            while (["ImplicitCastExpr", "ParenExpr", "ExprWithCleanups"].includes(unwrapped.kind ?? "")) unwrapped = unwrapped.inner?.[0] ?? unwrapped;
            const bare = unwrapped.kind === "DeclRefExpr" ? unwrapped.referencedDecl?.name : undefined;
            if (!bare) { replaced = false; break; }
            body = body.replace(new RegExp(wb + dimension + wb, "g"), bare);
          }
          if (replaced) refined.push(`O(${body})`);
        }
      }
      if (refined.length === 0) continue;
      let merged = parseBound(refined[0]);
      if (!merged) continue;
      for (const value of refined.slice(1)) {
        const parsed = parseBound(value);
        if (!parsed) { merged = undefined; break; }
        merged = maxBounds(merged, parsed);
      }
      if (!merged) continue;
      const newValue = formatBound(merged);
      if (newValue === summary.value) continue;
      costs.set(key, { ...summary, value: newValue, auxiliarySpace: newValue as LocalSummaryValue["auxiliarySpace"] });
      if (decl.kind === "FunctionDecl" && decl.name && costs.has(decl.name)) costs.set(decl.name, costs.get(decl.name)!);
    }
  };

  return { costs, resolve, propagateMemoStateContexts };
}

function fragmentInput(selection: string, documentSource: string): string {
  return [
    standardPrelude,
    withoutIncludes(documentSource),
    "void __project_x_selection(long long n, long long m, long long k, long long q, long long h, long long W, long long sum, long long V, long long E, long long t) {",
    withoutIncludes(selection),
    "}"
  ].join("\n");
}

function withNativeFactProof(result: AnalysisResult, functionName: string, facts: NativeFacts | undefined): AnalysisResult {
  if (!facts?.parsed) return result;
  const fact = facts.functionFacts.find((candidate) => candidate.name === functionName);
  if (!fact) return result;
  const calleeDetail = fact.directCallees.length === 0
    ? "no resolved direct callees"
    : `${fact.directCallees.length} resolved direct callee${fact.directCallees.length === 1 ? "" : "s"}`;
  return {
    ...result,
    proof: [...result.proof, `Local LibTooling independently verified this function's CFG (${fact.cfgBlocks} blocks) and ${calleeDetail}.`]
  };
}

/**
 * Derive a payload width from Clang's typed local declarations. This is not a
 * runtime-allocation measurement: STL capacity, allocator metadata, pointer
 * topology, and unknown helper state remain outside the displayed estimate.
 */
function withMemoryProfile(result: AnalysisResult, functionDecl: ClangNode, ownedRecordPayloadWidths?: ReadonlyMap<string, number>): AnalysisResult {
  if (result.auxiliarySpace === "Unknown" || result.auxiliarySpace === "O(1)") {
    return { ...result, memoryProfile: { bytesPerUnit: 8, basis: "generic" } };
  }
  const widths: number[] = [];
  const widthForType = (type: string): number | undefined => {
    if (/\b(?:long long|unsigned long long|double|int64_t|uint64_t)\b/.test(type)) return 8;
    if (/\b(?:int|unsigned int|float|int32_t|uint32_t)\b/.test(type)) return 4;
    if (/\b(?:short|char|bool|int16_t|uint16_t|int8_t|uint8_t)\b/.test(type)) return 1;
    return undefined;
  };
  const visit = (node: ClangNode): void => {
    if (node.kind === "VarDecl") {
      // Clang lowers range-for into implementation-only `__range`, `__begin`,
      // and `__end` declarations. They alias an input container; counting
      // them would double the displayed auxiliary-memory estimate.
      if (node.name?.startsWith("__")) return;
      const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
      // Parameters are inputs, not auxiliary storage. Vector/deque/string and
      // arrays declared in the selected function are local payload candidates.
      if (/\b(?:vector|deque|basic_string|array)\s*</.test(type) || /\[[^\]]+\]$/.test(type)) {
        const width = widthForType(type);
        if (width) widths.push(width);
      }
      // The asymptotic storage rule already proves that this local record owns
      // a dynamic member. Reuse the AST-derived element width for the editor's
      // byte scale; do not guess a width for opaque user-defined members.
      const recordName = type.replace(/\b(?:const|volatile|struct|class)\b/g, " ")
        .replace(/[&*].*$/, " ").trim().match(/([A-Za-z_][A-Za-z0-9_]*)$/)?.[1];
      const ownedWidth = recordName ? ownedRecordPayloadWidths?.get(recordName) : undefined;
      if (ownedWidth) widths.push(ownedWidth);
    }
    for (const child of node.inner ?? []) visit(child);
  };
  const body = (functionDecl.inner ?? []).find((node) => node.kind === "CompoundStmt");
  if (body) visit(body);
  // Multiple visible local tables at the same scale contribute additively.
  // Keep a generic 8-byte model when the AST cannot prove a payload type.
  return {
    ...result,
    memoryProfile: widths.length > 0
      ? { bytesPerUnit: widths.reduce((sum, width) => sum + width, 0), basis: "typed-local-storage" }
      : { bytesPerUnit: 8, basis: "generic" }
  };
}

/** Payload bytes per dynamic member owned by a local record, from Clang types. */
function localRecordPayloadWidths(ast: ClangNode, localRecordNames: ReadonlySet<string>): ReadonlyMap<string, number> {
  const result = new Map<string, number>();
  const widthForType = (type: string): number | undefined => {
    if (/\b(?:long long|unsigned long long|double|int64_t|uint64_t)\b/.test(type)) return 8;
    if (/\b(?:int|unsigned int|float|int32_t|uint32_t)\b/.test(type)) return 4;
    if (/\b(?:short|char|bool|int16_t|uint16_t|int8_t|uint8_t)\b/.test(type)) return 1;
    return undefined;
  };
  const visit = (node: ClangNode): void => {
    if (node.kind === "CXXRecordDecl" && node.name && localRecordNames.has(node.name)) {
      const widths = (node.inner ?? []).filter((member) => member.kind === "FieldDecl")
        .map((member) => member.type?.desugaredQualType ?? member.type?.qualType ?? "")
        .filter((type) => /\b(?:vector|deque|basic_string|array)\s*</.test(type))
        .map(widthForType)
        .filter((width): width is number => width !== undefined);
      if (widths.length > 0) result.set(node.name, widths.reduce((sum, width) => sum + width, 0));
    }
    for (const child of node.inner ?? []) visit(child);
  };
  visit(ast);
  return result;
}

/** Proven preprocessing summaries for local record constructors. */
function localRecordConstructorSummaries(ast: ClangNode, localRecordNames: ReadonlySet<string>, constants: ReadonlySet<string>, ownedRecordStorage: LocalRecordOwnedStorage): ReadonlyMap<string, LocalSummaryValue> {
  const result = new Map<string, LocalSummaryValue>();
  const visit = (node: ClangNode): void => {
    if (node.kind === "CXXRecordDecl" && node.name && localRecordNames.has(node.name)) {
      const members = node.inner ?? [];
      const methods = members.filter((child) => child.kind === "CXXMethodDecl" && child.name);
      for (const constructor of members.filter((child) => child.kind === "CXXConstructorDecl" && child.inner?.some((part) => part.kind === "CompoundStmt"))) {
        // A complete segment-tree-style interval build is recognized
        // structurally before the generic constructor pass so that a build
        // method invoked outside ordinary call resolution is still measured.
        const segmentTree = segmentTreeConstructorSummary(constructor, methods, constants);
        if (segmentTree && !result.has(node.name)) { result.set(node.name, segmentTree); continue; }
        const summary = summaryValue(analyseFunctionAst(constructor, undefined, constants, ownedRecordStorage));
        // Only compose a constructor when it reached a dedicated structural
        // estimate. A generic exact loop result inside an arbitrary
        // constructor is not enough to prove that it represents one-time
        // preprocessing rather than an incidental implementation detail.
        if (summary?.confidence === "estimated" && !result.has(node.name)) result.set(node.name, summary);
      }
    }
    for (const child of node.inner ?? []) visit(child);
  };
  visit(ast);
  return result;
}

function additiveComplexity(left: Complexity, right: Complexity): Complexity {
  if (left === "O(1)") return right;
  if (right === "O(1)" || left === right) return left;
  // Compose through the canonical bound algebra when both sides parse so that
  // "O(q log n) + O(n log n)" prints as the factored "O((n + q) log n)"
  // instead of leaking an unparseable "+ O(...)" concatenation. The fallback
  // preserves the concat spelling for exotic (exponential) forms that the
  // algebra refuses to add.
  try {
    const leftBound = parseBound(left);
    const rightBound = parseBound(right);
    if (leftBound && rightBound) return formatBound([...leftBound, ...rightBound]) as Complexity;
  } catch {
    // Fall through to the spelled composition.
  }
  const leftBody = /^O\((.+)\)$/.exec(left)?.[1];
  const rightBody = /^O\((.+)\)$/.exec(right)?.[1];
  return leftBody && rightBody ? `O(${leftBody} + ${rightBody})` as Complexity : left;
}

/** Compose a local object's proved preprocessing into its enclosing function. */
function withConstructorPreprocessing(result: AnalysisResult, functionDecl: ClangNode, summaries: ReadonlyMap<string, LocalSummaryValue>): AnalysisResult {
  if (result.confidence === "unknown" || summaries.size === 0) return result;
  const body = (functionDecl.inner ?? []).find((node) => node.kind === "CompoundStmt");
  if (!body) return result;
  const costs: LocalSummaryValue[] = [];
  const visit = (node: ClangNode): void => {
    if (node.kind === "VarDecl") {
      const type = node.type?.desugaredQualType ?? node.type?.qualType ?? "";
      const recordName = type.replace(/\b(?:const|volatile|struct|class)\b/g, " ")
        .replace(/[&*].*$/, " ").trim().match(/([A-Za-z_][A-Za-z0-9_]*)$/)?.[1];
      const construction = (node.inner ?? []).some((child) => child.kind === "CXXConstructExpr" || child.kind === "CXXTemporaryObjectExpr");
      const summary = recordName ? summaries.get(recordName) : undefined;
      if (construction && summary) costs.push(summary);
    }
    for (const child of node.inner ?? []) visit(child);
  };
  visit(body);
  if (costs.length === 0) return result;
  let time = result.worstCaseTime;
  let space = result.auxiliarySpace;
  for (const cost of costs) {
    time = additiveComplexity(time, cost.value);
    space = additiveComplexity(space, cost.auxiliarySpace) as AnalysisResult["auxiliarySpace"];
  }
  return {
    ...result,
    worstCaseTime: time,
    auxiliarySpace: space,
    confidence: "estimated",
    confidencePercent: Math.min(result.confidencePercent ?? 85, 90),
    proof: [...result.proof, "Composed proven local-object constructor preprocessing with the selected function's remaining work."]
  };
}

export function prepareCppSelection(source: string): { input: string; functionName: string } {
  const trimmed = source.trim();
  const sanitized = withoutIncludes(trimmed);
  const selectionName = "__project_x_selection";
  const firstBrace = sanitized.indexOf("{");
  const header = firstBrace >= 0 ? sanitized.slice(0, firstBrace) : "";
  const startsControlStatement = ["for", "while", "if", "switch"].some((keyword) => header.trimStart().startsWith(keyword + " "));
  const functions = functionNamesIn(sanitized);
  const hasTopLevelFunction = functions.length > 0 && !startsControlStatement;
  const functionName = hasTopLevelFunction ? functions.at(-1) ?? selectedFunctionName(header) : selectionName;
  if (!functionName) throw new Error("Could not identify the selected function name.");
  return {
    input: hasTopLevelFunction
      ? standardPrelude + "\n" + sanitized
      : [
        standardPrelude,
        "long long n, m, k, q, h, W, sum, V, E, t;",
        "void " + selectionName + "() {",
        sanitized,
        "}"
      ].join("\n"),
    functionName
  };
}

export function analyseCppSelection(source: string, documentSource = source): AnalysisResult {
  try {
    if (!withoutComments(withoutIncludes(source)).trim()) {
      return {
        worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown",
        proof: ["The selection contains comments only. Select one active C++ function or block; commented examples are not executable code."]
      };
    }
    const prepared = prepareCppSelection(source);
    const documentFunctions = functionNamesIn(withoutIncludes(documentSource));
    const selectedIsFunction = prepared.functionName !== "__project_x_selection";
    const input = selectedIsFunction && documentFunctions.includes(prepared.functionName)
      ? standardPrelude + "\n" + withoutIncludes(documentSource)
      : selectedIsFunction || documentSource === source ? prepared.input : fragmentInput(source, documentSource);
    const ast = clangAstFor(input);
    const nativeFacts = nativeFactsFor(input);
    const constants = translationUnitConstants(ast);
    const functionDecl = findFunctionNamed(ast, prepared.functionName);
    const localRecords = localRecordNamesIn(withoutIncludes(documentSource));
    const localMethods = findMethodDeclarations(ast, localRecords);
    const ownedRecordStorage = localRecordOwnedStorage(ast, localRecords);
    const ownedRecordPayloadWidths = localRecordPayloadWidths(ast, localRecords);
    const constructorSummaries = localRecordConstructorSummaries(ast, localRecords, constants, ownedRecordStorage);
    // The synthetic prelude instantiates body-carrying STL declarations
    // (unique, three-argument sort, remove, ...). Their bodies are one-line
    // stubs, and resolving them as local summaries would cost a real
    // sort/unique pass as O(1). Only functions defined in user source -
    // i.e. past the prelude prefix shared by every input shape here - may
    // supply same-file call costs.
    const preludeEnd = standardPrelude.length + 1;
    const sameFileFunctions = findFunctionDeclarations(ast)
      .filter((declaration) => (declaration.range?.begin?.offset ?? Number.POSITIVE_INFINITY) >= preludeEnd);
    const resolver = resolveLocalFunctionCosts([...sameFileFunctions, ...localMethods], constants, ownedRecordStorage);
    resolver.resolve(prepared.functionName);
    resolver.propagateMemoStateContexts();
    return functionDecl ? withMemoryProfile(withConstructorPreprocessing(withNativeFactProof(analyseFunctionAst(functionDecl, resolver.costs, constants, ownedRecordStorage), prepared.functionName, nativeFacts), functionDecl, constructorSummaries), functionDecl, ownedRecordPayloadWidths) : {
      worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown", proof: ["No analyzable function or self-contained C++ block was found in the selection."]
    };
  } catch (error) {
    const detail = error instanceof Error ? error.message : String(error);
    const compilerRejectedCode = /error:|fatal error:/.test(detail);
    return {
      worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown",
      proof: [compilerRejectedCode
        ? "Clang rejected the selected code, so no safe complexity result can be produced."
        : "Clang could not start. Install Clang locally or set PROJECT_X_CLANG to its executable path.", detail]
    };
  }
}

/**
 * Analyses one named function from a complete C++ translation unit. Dataset and
 * holdout tooling uses this entry point so it exercises exactly the same Clang
 * AST, constant discovery, and same-file DFS call resolution as the editor.
 */
export function analyseCppFunctionsInDocument(documentSource: string, functionNames: readonly string[]): Map<string, AnalysisResult> {
  const results = new Map<string, AnalysisResult>();
  try {
    const input = standardPrelude + "\n" + withoutIncludes(documentSource);
    const ast = clangAstFor(input);
    const nativeFacts = nativeFactsFor(input);
    const constants = translationUnitConstants(ast);
    const declaredInDocument = new Set(functionNamesIn(withoutIncludes(documentSource)));
    // The AST also contains our synthetic STL prelude. Only corpus-defined
    // functions may participate in same-file call resolution; admitting the
    // prelude turns a 100-case benchmark into thousands of irrelevant DFS
    // nodes and does not improve analysis quality. The source-offset check
    // also stops a user function that happens to share a prelude STL name
    // (unique, remove, ...) from being shadowed by the stub instantiation.
    const preludeEnd = standardPrelude.length + 1;
    const functions = findFunctionDeclarations(ast)
      .filter((declaration) => Boolean(declaration.name && declaredInDocument.has(declaration.name))
        && (declaration.range?.begin?.offset ?? Number.POSITIVE_INFINITY) >= preludeEnd);
    const localRecords = localRecordNamesIn(withoutIncludes(documentSource));
    const methods = findMethodDeclarations(ast, localRecords);
    // The benchmark can request hundreds of symbols from one translation
    // unit. Build this index once instead of traversing Clang's (large) JSON
    // AST again for every name.
    const functionByName = new Map<string, ClangNode>();
    for (const declaration of functions) if (declaration.name) functionByName.set(declaration.name, declaration);
    const ownedRecordStorage = localRecordOwnedStorage(ast, localRecords);
    const ownedRecordPayloadWidths = localRecordPayloadWidths(ast, localRecords);
    const constructorSummaries = localRecordConstructorSummaries(ast, localRecords, constants, ownedRecordStorage);
    const resolver = resolveLocalFunctionCosts([...functions, ...methods], constants, ownedRecordStorage);
    for (const functionName of functionNames) {
      const functionDecl = functionByName.get(functionName);
      if (!functionDecl) {
        results.set(functionName, {
          worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown",
          proof: ["The manifest symbol was not found as a complete C++ function in this translation unit."]
        });
        continue;
      }
      resolver.resolve(functionName);
      resolver.propagateMemoStateContexts();
      const direct = analyseFunctionAst(functionDecl, resolver.costs, constants, ownedRecordStorage);
      // When the selected function is itself a memoized DP helper whose state
      // dimensions the same-file callers bind (f(1, k) names the space k),
      // publish the caller-context summary instead of the bare parameter
      // spelling, keeping the derivation's proof lines.
      const contextual = resolver.costs.get(functionName);
      if (direct.memoStateDims && contextual?.memoStateDims && contextual.value !== direct.worstCaseTime) {
        const refined: AnalysisResult = {
          worstCaseTime: contextual.value,
          auxiliarySpace: contextual.auxiliarySpace,
          confidence: contextual.confidence,
          proof: [...direct.proof, "Same-file call sites bind the memoized state dimensions to their input sizes."]
        };
        results.set(functionName, withMemoryProfile(withConstructorPreprocessing(withNativeFactProof(refined, functionName, nativeFacts), functionDecl, constructorSummaries), functionDecl, ownedRecordPayloadWidths));
        continue;
      }
      results.set(functionName, withMemoryProfile(withConstructorPreprocessing(withNativeFactProof(direct, functionName, nativeFacts), functionDecl, constructorSummaries), functionDecl, ownedRecordPayloadWidths));
    }
  } catch (error) {
    const detail = error instanceof Error ? error.message : String(error);
    const compilerRejectedCode = /error:|fatal error:/.test(detail);
    for (const functionName of functionNames) results.set(functionName, {
      worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown",
      proof: [compilerRejectedCode
        ? "Clang rejected the corpus function, so no safe complexity result can be produced."
        : "Clang could not start. Install Clang locally or set PROJECT_X_CLANG to its executable path.", detail]
    });
  }
  return results;
}

export function analyseCppFunctionInDocument(documentSource: string, functionName: string): AnalysisResult {
  return analyseCppFunctionsInDocument(documentSource, [functionName]).get(functionName) ?? {
    worstCaseTime: "Unknown", auxiliarySpace: "Unknown", confidence: "unknown",
    proof: ["The manifest symbol was not found as a complete C++ function in this translation unit."]
  };
}

export type { AnalysisResult, ClangNode } from "./model.js";
