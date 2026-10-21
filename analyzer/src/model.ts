export type Complexity =
  | "O(1)" | "O(n)" | "O(log n)" | "O(sqrt n)" | "O(n log n)" | "O(n log log n)" | "O(2^n)" | "O(n!)" | "O(n + m)" | "O(n m)" | "Does not terminate" | "Unknown"
  | `O(n^${number})` | `O(log^${number} n)` | `O(n log^${number} n)` | `O(n^${number} log log n)`
  | `O(n^${number} log n)` | `O(n^${number} log^${number} n)`
  // Preserve independent input dimensions, for example O(n W), instead of
  // collapsing every parameter to the single symbol n.
  | `O(${string})`;
export type Confidence = "exact" | "estimated" | "unknown";
export type AuxiliarySpace = Exclude<Complexity, "Does not terminate">;

/** Payload-width evidence for the optional editor memory scale display. */
export interface MemoryProfile {
  /** Bytes per symbolic auxiliary-storage unit, excluding allocator overhead. */
  bytesPerUnit: number;
  /** Whether this came from typed local storage or a conservative fallback. */
  basis: "typed-local-storage" | "generic";
}

export interface AnalysisResult {
  worstCaseTime: Complexity;
  auxiliarySpace: AuxiliarySpace;
  confidence: Confidence;
  /** Rule-derived display confidence, never a learned probability. */
  confidencePercent?: number;
  memoryProfile?: MemoryProfile;
  proof: string[];
  /** Parameter names whose magnitude bounds a memoized DP state space. */
  memoStateDims?: readonly string[];
}

/** Deliberately small, forward-compatible view of Clang's JSON AST. */
export interface ClangNode {
  /** Stable Clang JSON-AST declaration/node identity when emitted by Clang. */
  id?: string;
  kind?: string;
  name?: string;
  opcode?: string;
  value?: string;
  referencedDecl?: { id?: string; name?: string; kind?: string; type?: { qualType?: string; desugaredQualType?: string } };
  /** Clang uses this field for CXXCtorInitializer's initialized member. */
  anyInit?: { id?: string; name?: string; kind?: string; type?: { qualType?: string; desugaredQualType?: string } };
  /** Clang uses this field for the target of `object.method(...)`. */
  referencedMemberDecl?: string | { id?: string; name?: string; kind?: string; type?: { qualType?: string; desugaredQualType?: string } };
  /** Optional source span emitted by Clang; used only for lexical nesting checks. */
  range?: { begin?: { offset?: number }; end?: { offset?: number } };
  type?: { qualType?: string; desugaredQualType?: string };
  inner?: ClangNode[];
}
