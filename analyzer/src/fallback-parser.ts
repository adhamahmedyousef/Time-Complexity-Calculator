import type { ClangNode } from "./model.js";

/**
 * Token types for the zero-dependency C++ fallback tokenizer.
 */
type TokenType =
  | "KEYWORD"
  | "IDENTIFIER"
  | "NUMBER"
  | "STRING"
  | "OPERATOR"
  | "PUNCTUATION";

interface Token {
  type: TokenType;
  value: string;
  offset: number;
}

const KEYWORDS = new Set([
  "for", "while", "do", "if", "else", "switch", "case", "default",
  "return", "break", "continue", "int", "long", "short", "char",
  "float", "double", "bool", "void", "auto", "const", "constexpr",
  "static", "inline", "unsigned", "signed", "struct", "class",
  "template", "typename", "using", "typedef", "namespace", "true", "false",
  "nullptr", "virtual", "explicit", "friend", "noexcept"
]);

const MULTI_CHAR_OPERATORS = [
  ">>=", "<<=", "->*", "...", "==", "!=", "<=", ">=", "&&", "||",
  "++", "--", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
  "<<", ">>", "::", "->"
];

export function tokenizeCpp(source: string): Token[] {
  const tokens: Token[] = [];
  let i = 0;
  const len = source.length;

  while (i < len) {
    const ch = source[i];

    // Whitespace
    if (/\s/.test(ch)) {
      i++;
      continue;
    }

    // Line comment
    if (ch === "/" && source[i + 1] === "/") {
      i += 2;
      while (i < len && source[i] !== "\n") i++;
      continue;
    }

    // Block comment
    if (ch === "/" && source[i + 1] === "*") {
      i += 2;
      while (i < len - 1 && !(source[i] === "*" && source[i + 1] === "/")) i++;
      i += 2;
      continue;
    }

    // Preprocessor directive
    if (ch === "#") {
      while (i < len && source[i] !== "\n") i++;
      continue;
    }

    // Number literal
    if (/[0-9]/.test(ch) || (ch === "." && /[0-9]/.test(source[i + 1] || ""))) {
      const start = i;
      while (i < len && /[0-9a-zA-Z._]/.test(source[i])) i++;
      tokens.push({ type: "NUMBER", value: source.slice(start, i), offset: start });
      continue;
    }

    // String literal
    if (ch === '"') {
      const start = i++;
      while (i < len && source[i] !== '"') {
        if (source[i] === "\\" && i + 1 < len) i += 2;
        else i++;
      }
      if (i < len) i++;
      tokens.push({ type: "STRING", value: source.slice(start, i), offset: start });
      continue;
    }

    // Character literal
    if (ch === "'") {
      const start = i++;
      while (i < len && source[i] !== "'") {
        if (source[i] === "\\" && i + 1 < len) i += 2;
        else i++;
      }
      if (i < len) i++;
      tokens.push({ type: "STRING", value: source.slice(start, i), offset: start });
      continue;
    }

    // Multi-character operator check
    let matchedMulti = false;
    for (const op of MULTI_CHAR_OPERATORS) {
      if (source.startsWith(op, i)) {
        tokens.push({ type: "OPERATOR", value: op, offset: i });
        i += op.length;
        matchedMulti = true;
        break;
      }
    }
    if (matchedMulti) continue;

    // Identifier or Keyword
    if (/[a-zA-Z_]/.test(ch)) {
      const start = i;
      while (i < len && /[a-zA-Z0-9_]/.test(source[i])) i++;
      const word = source.slice(start, i);
      tokens.push({
        type: KEYWORDS.has(word) ? "KEYWORD" : "IDENTIFIER",
        value: word,
        offset: start
      });
      continue;
    }

    // Single-character operator or punctuation
    const isPunct = ["(", ")", "{", "}", "[", "]", ";", ",", ":", "?"].includes(ch);
    tokens.push({
      type: isPunct ? "PUNCTUATION" : "OPERATOR",
      value: ch,
      offset: i
    });
    i++;
  }

  return tokens;
}

let nodeIdCounter = 1;
function nextId(): string {
  return `fallback_0x${(nodeIdCounter++).toString(16)}`;
}

interface SymbolInfo {
  id: string;
  name: string;
  kind: "ParmVarDecl" | "VarDecl" | "FunctionDecl";
  type?: string;
}

/**
 * Recursive descent parser to build ClangNode AST from token stream.
 */
class CppAstBuilder {
  private tokens: Token[];
  private pos = 0;
  private scopes: Map<string, SymbolInfo>[] = [new Map()];

  constructor(tokens: Token[]) {
    this.tokens = tokens;
  }

  private enterScope(): void {
    this.scopes.push(new Map());
  }

  private exitScope(): void {
    if (this.scopes.length > 1) {
      this.scopes.pop();
    }
  }

  private defineSymbol(name: string, kind: "ParmVarDecl" | "VarDecl" | "FunctionDecl", type?: string): SymbolInfo {
    const id = nextId();
    const info: SymbolInfo = { id, name, kind, type };
    this.scopes[this.scopes.length - 1].set(name, info);
    return info;
  }

  private lookupSymbol(name: string): SymbolInfo {
    for (let i = this.scopes.length - 1; i >= 0; i--) {
      const info = this.scopes[i].get(name);
      if (info) return info;
    }
    // Global fallback
    const info: SymbolInfo = { id: nextId(), name, kind: "VarDecl" };
    this.scopes[0].set(name, info);
    return info;
  }

  private peek(): Token | undefined {
    return this.tokens[this.pos];
  }

  private next(): Token | undefined {
    return this.tokens[this.pos++];
  }

  private match(val: string): boolean {
    if (this.peek()?.value === val) {
      this.pos++;
      return true;
    }
    return false;
  }

  private expect(val: string): Token | undefined {
    const tok = this.next();
    if (tok?.value !== val) {
      return undefined;
    }
    return tok;
  }

  public parseTranslationUnit(): ClangNode {
    const inner: ClangNode[] = [];
    while (this.pos < this.tokens.length) {
      const prevPos = this.pos;
      const decl = this.parseTopLevelDeclaration();
      if (decl) {
        inner.push(decl);
      }
      if (this.pos === prevPos) {
        this.pos++;
      }
    }
    return {
      id: nextId(),
      kind: "TranslationUnitDecl",
      inner
    };
  }

  private parseTopLevelDeclaration(): ClangNode | undefined {
    const start = this.pos;

    // Skip qualifiers / templates
    while (this.pos < this.tokens.length && ["template", "inline", "static", "constexpr", "virtual", "explicit"].includes(this.peek()?.value || "")) {
      if (this.peek()?.value === "template") {
        this.pos++;
        if (this.peek()?.value === "<") {
          this.skipAngleBrackets();
        }
      } else {
        this.pos++;
      }
    }

    // Type name
    const typeTokens: string[] = [];
    while (this.pos < this.tokens.length && this.peek()?.value !== "{" && this.peek()?.value !== ";" && this.peek()?.value !== "(") {
      if (this.peek()?.value === "<") {
        typeTokens.push(this.skipAngleBrackets());
        continue;
      }
      const tok = this.next();
      if (!tok) break;
      typeTokens.push(tok.value);
    }

    // If next is '(', the previous token might be the function name
    if (this.peek()?.value === "(" && typeTokens.length > 0) {
      const funcName = typeTokens.pop()!;
      const returnType = typeTokens.join(" ");

      this.defineSymbol(funcName, "FunctionDecl");
      this.enterScope();

      // Parse parameters
      this.expect("(");
      const params = this.parseParameterList();
      this.expect(")");

      // Skip const/noexcept/trailing return type
      while (this.pos < this.tokens.length && ["const", "noexcept", "override", "final"].includes(this.peek()?.value || "")) {
        this.pos++;
      }

      if (this.peek()?.value === "{") {
        const body = this.parseCompoundStmt();
        this.exitScope();
        return {
          id: nextId(),
          kind: "FunctionDecl",
          name: funcName,
          type: { qualType: `${returnType} (${params.map((p) => p.type?.qualType || "int").join(", ")})` },
          inner: [...params, body]
        };
      }
      this.exitScope();
    }

    // Not a function definition, skip to ';'
    while (this.pos < this.tokens.length && this.peek()?.value !== ";") {
      if (this.peek()?.value === "{") {
        this.skipBlock();
        return undefined;
      }
      this.pos++;
    }
    if (this.peek()?.value === ";") this.pos++;
    return undefined;
  }

  private skipAngleBrackets(): string {
    if (this.peek()?.value !== "<") return "";
    let depth = 0;
    let result = "";
    while (this.pos < this.tokens.length) {
      const tok = this.next()!;
      result += (result ? " " : "") + tok.value;
      if (tok.value === "<") depth++;
      else if (tok.value === ">") {
        depth--;
        if (depth === 0) break;
      }
    }
    return result;
  }

  private skipBlock(): void {
    if (this.peek()?.value !== "{") return;
    let depth = 0;
    while (this.pos < this.tokens.length) {
      const tok = this.next()!;
      if (tok.value === "{") depth++;
      else if (tok.value === "}") {
        depth--;
        if (depth === 0) break;
      }
    }
  }

  private parseParameterList(): ClangNode[] {
    const params: ClangNode[] = [];
    while (this.pos < this.tokens.length && this.peek()?.value !== ")") {
      const pTokens: string[] = [];
      while (this.pos < this.tokens.length && this.peek()?.value !== "," && this.peek()?.value !== ")") {
        if (this.peek()?.value === "<") {
          pTokens.push(this.skipAngleBrackets());
          continue;
        }
        const tok = this.next()!;
        pTokens.push(tok.value);
      }
      if (pTokens.length > 0) {
        const name = pTokens.pop()!;
        const typeStr = pTokens.join(" ");
        const sym = this.defineSymbol(name, "ParmVarDecl", typeStr);
        params.push({
          id: sym.id,
          kind: "ParmVarDecl",
          name,
          type: { qualType: typeStr }
        });
      }
      if (this.peek()?.value === ",") this.pos++;
    }
    return params;
  }

  private parseCompoundStmt(): ClangNode {
    this.expect("{");
    this.enterScope();
    const inner: ClangNode[] = [];
    while (this.pos < this.tokens.length && this.peek()?.value !== "}") {
      const prevPos = this.pos;
      const stmt = this.parseStatement();
      if (stmt) {
        inner.push(stmt);
      }
      if (this.pos === prevPos) {
        this.pos++;
      }
    }
    this.expect("}");
    this.exitScope();
    return {
      id: nextId(),
      kind: "CompoundStmt",
      inner
    };
  }

  private parseStatement(): ClangNode | undefined {
    const tok = this.peek();
    if (!tok) return undefined;

    if (tok.value === "{") {
      return this.parseCompoundStmt();
    }
    if (tok.value === "for") {
      return this.parseForStmt();
    }
    if (tok.value === "while") {
      return this.parseWhileStmt();
    }
    if (tok.value === "do") {
      return this.parseDoStmt();
    }
    if (tok.value === "if") {
      return this.parseIfStmt();
    }
    if (tok.value === "return") {
      return this.parseReturnStmt();
    }
    if (tok.value === "break") {
      this.next();
      this.match(";");
      return { id: nextId(), kind: "BreakStmt" };
    }
    if (tok.value === "continue") {
      this.next();
      this.match(";");
      return { id: nextId(), kind: "ContinueStmt" };
    }
    if (tok.value === ";") {
      this.next();
      return { id: nextId(), kind: "NullStmt" };
    }

    // Check if it is a variable declaration
    const decl = this.tryParseDeclStmt();
    if (decl) return decl;

    // Expression statement
    const expr = this.parseExpression();
    this.match(";");
    return expr;
  }

  private parseForStmt(): ClangNode {
    this.expect("for");
    this.expect("(");

    // Look ahead to check if this is a range-for: `for (auto x : a)`
    let isRangeFor = false;
    let parenDepth = 1;
    let colonIndex = -1;
    for (let i = this.pos; i < this.tokens.length; i++) {
      const t = this.tokens[i];
      if (t.value === "(") parenDepth++;
      else if (t.value === ")") {
        parenDepth--;
        if (parenDepth === 0) break;
      } else if (t.value === ":" && parenDepth === 1) {
        isRangeFor = true;
        colonIndex = i;
        break;
      } else if (t.value === ";" && parenDepth === 1) {
        break;
      }
    }

    if (isRangeFor) {
      // Range-for: e.g. for (int x : a) or for (const auto &item : container)
      const varTokens: string[] = [];
      while (this.pos < colonIndex) {
        varTokens.push(this.next()!.value);
      }
      this.expect(":");
      const containerTokens: string[] = [];
      while (this.pos < this.tokens.length && this.peek()?.value !== ")") {
        containerTokens.push(this.next()!.value);
      }
      this.expect(")");

      const varName = varTokens.filter((v) => !["const", "auto", "&", "*"].includes(v)).pop() || "x";
      const containerName = containerTokens.join(" ");

      const containerSym = this.lookupSymbol(containerName);
      this.enterScope();
      const varSym = this.defineSymbol(varName, "VarDecl", "auto");
      const body = this.parseLoopBody();
      this.exitScope();

      // Model CXXForRangeStmt matching Clang's layout
      return {
        id: nextId(),
        kind: "CXXForRangeStmt",
        inner: [
          {
            id: nextId(),
            kind: "VarDecl",
            name: "__range1",
            type: { qualType: "auto &" },
            inner: [
              {
                id: nextId(),
                kind: "DeclRefExpr",
                name: containerName,
                referencedDecl: { id: containerSym.id, name: containerName, kind: containerSym.kind }
              }
            ]
          },
          {
            id: varSym.id,
            kind: "VarDecl",
            name: varName,
            type: { qualType: "auto" }
          },
          body
        ]
      };
    }

    // Classic for loop: for (init; cond; inc) body
    this.enterScope();
    let initNode: ClangNode | undefined;
    if (this.peek()?.value !== ";") {
      initNode = this.tryParseDeclStmt(false) || this.parseExpression();
    }
    this.match(";");

    let condNode: ClangNode | undefined;
    if (this.peek()?.value !== ";") {
      condNode = this.parseExpression();
    }
    this.match(";");

    let incNode: ClangNode | undefined;
    if (this.peek()?.value !== ")") {
      incNode = this.parseExpression();
    }
    this.expect(")");

    const body = this.parseLoopBody();
    this.exitScope();

    return {
      id: nextId(),
      kind: "ForStmt",
      inner: [
        initNode || { id: nextId(), kind: "NullStmt" },
        {},
        condNode || { id: nextId(), kind: "NullStmt" },
        incNode || { id: nextId(), kind: "NullStmt" },
        body
      ]
    };
  }

  private parseWhileStmt(): ClangNode {
    this.expect("while");
    this.expect("(");
    const cond = this.parseExpression() || { id: nextId(), kind: "NullStmt" };
    this.expect(")");
    const body = this.parseLoopBody();

    return {
      id: nextId(),
      kind: "WhileStmt",
      inner: [
        {},
        cond,
        body
      ]
    };
  }

  private parseDoStmt(): ClangNode {
    this.expect("do");
    const body = this.parseLoopBody();
    this.expect("while");
    this.expect("(");
    const cond = this.parseExpression() || { id: nextId(), kind: "NullStmt" };
    this.expect(")");
    this.match(";");

    return {
      id: nextId(),
      kind: "DoStmt",
      inner: [
        body,
        cond
      ]
    };
  }

  private parseIfStmt(): ClangNode {
    this.expect("if");
    this.expect("(");
    const cond = this.parseExpression() || { id: nextId(), kind: "NullStmt" };
    this.expect(")");
    const thenStmt = this.parseLoopBody();
    let elseStmt: ClangNode | undefined;
    if (this.match("else")) {
      elseStmt = this.parseLoopBody();
    }

    return {
      id: nextId(),
      kind: "IfStmt",
      inner: elseStmt ? [cond, thenStmt, elseStmt] : [cond, thenStmt]
    };
  }

  private parseReturnStmt(): ClangNode {
    this.expect("return");
    let expr: ClangNode | undefined;
    if (this.peek()?.value !== ";") {
      expr = this.parseExpression();
    }
    this.match(";");
    return {
      id: nextId(),
      kind: "ReturnStmt",
      inner: expr ? [expr] : []
    };
  }

  private parseLoopBody(): ClangNode {
    if (this.peek()?.value === "{") {
      return this.parseCompoundStmt();
    }
    const stmt = this.parseStatement();
    return {
      id: nextId(),
      kind: "CompoundStmt",
      inner: stmt ? [stmt] : []
    };
  }

  private tryParseDeclStmt(consumeSemicolon = true): ClangNode | undefined {
    const start = this.pos;
    const typeTokens: string[] = [];

    // Check if the current tokens form a type
    while (this.pos < this.tokens.length) {
      const tok = this.peek();
      if (!tok) break;
      if (
        KEYWORDS.has(tok.value) &&
        ["int", "long", "short", "char", "float", "double", "bool", "void", "auto", "const", "unsigned", "signed"].includes(tok.value)
      ) {
        typeTokens.push(this.next()!.value);
      } else if (tok.type === "IDENTIFIER") {
        const nextTok = this.tokens[this.pos + 1];
        if (nextTok?.value === "<") {
          typeTokens.push(this.next()!.value);
          typeTokens.push(this.skipAngleBrackets());
        } else if (nextTok?.type === "IDENTIFIER" || nextTok?.value === "*" || nextTok?.value === "&") {
          typeTokens.push(this.next()!.value);
        } else {
          break;
        }
      } else if (tok.value === "&" || tok.value === "*") {
        typeTokens.push(this.next()!.value);
      } else {
        break;
      }
    }

    if (typeTokens.length > 0 && this.peek()?.type === "IDENTIFIER") {
      const varName = this.next()!.value;
      const typeStr = typeTokens.join(" ");

      const sym = this.defineSymbol(varName, "VarDecl", typeStr);
      let initExpr: ClangNode | undefined;
      if (this.match("=")) {
        initExpr = this.parseExpression();
      } else if (this.peek()?.value === "(") {
        // Constructor arguments: e.g. vector<int> a(n);
        this.next();
        const args: ClangNode[] = [];
        while (this.pos < this.tokens.length && this.peek()?.value !== ")") {
          const arg = this.parseExpression();
          if (arg) args.push(arg);
          if (this.peek()?.value === ",") this.pos++;
        }
        this.expect(")");
        initExpr = {
          id: nextId(),
          kind: "CXXConstructExpr",
          inner: args
        };
      }

      if (consumeSemicolon) {
        this.match(";");
      }

      return {
        id: nextId(),
        kind: "DeclStmt",
        inner: [
          {
            id: sym.id,
            kind: "VarDecl",
            name: varName,
            type: { qualType: typeStr },
            inner: initExpr ? [initExpr] : []
          }
        ]
      };
    }

    this.pos = start;
    return undefined;
  }

  private parseExpression(): ClangNode | undefined {
    return this.parseAssignment();
  }

  private parseAssignment(): ClangNode | undefined {
    let left = this.parseLogicalOr();
    if (!left) return undefined;

    const op = this.peek()?.value;
    if (op && ["=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "|=", "^="].includes(op)) {
      this.next();
      const right = this.parseAssignment();
      if (!right) return left;
      const isCompound = op !== "=";
      return {
        id: nextId(),
        kind: isCompound ? "CompoundAssignOperator" : "BinaryOperator",
        opcode: op,
        inner: [left, right]
      };
    }
    return left;
  }

  private parseLogicalOr(): ClangNode | undefined {
    let left = this.parseLogicalAnd();
    while (this.peek()?.value === "||") {
      const op = this.next()!.value;
      const right = this.parseLogicalAnd();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseLogicalAnd(): ClangNode | undefined {
    let left = this.parseBitwiseOr();
    while (this.peek()?.value === "&&") {
      const op = this.next()!.value;
      const right = this.parseBitwiseOr();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseBitwiseOr(): ClangNode | undefined {
    let left = this.parseBitwiseXor();
    while (this.peek()?.value === "|" && this.tokens[this.pos + 1]?.value !== "|") {
      const op = this.next()!.value;
      const right = this.parseBitwiseXor();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseBitwiseXor(): ClangNode | undefined {
    let left = this.parseBitwiseAnd();
    while (this.peek()?.value === "^") {
      const op = this.next()!.value;
      const right = this.parseBitwiseAnd();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseBitwiseAnd(): ClangNode | undefined {
    let left = this.parseEquality();
    while (this.peek()?.value === "&" && this.tokens[this.pos + 1]?.value !== "&") {
      const op = this.next()!.value;
      const right = this.parseEquality();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseEquality(): ClangNode | undefined {
    let left = this.parseRelational();
    while (this.peek()?.value === "==" || this.peek()?.value === "!=") {
      const op = this.next()!.value;
      const right = this.parseRelational();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseRelational(): ClangNode | undefined {
    let left = this.parseShift();
    while (["<", "<=", ">", ">="].includes(this.peek()?.value || "")) {
      const op = this.next()!.value;
      const right = this.parseShift();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseShift(): ClangNode | undefined {
    let left = this.parseAdditive();
    while (["<<", ">>"].includes(this.peek()?.value || "")) {
      const op = this.next()!.value;
      const right = this.parseAdditive();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseAdditive(): ClangNode | undefined {
    let left = this.parseMultiplicative();
    while (["+", "-"].includes(this.peek()?.value || "")) {
      const op = this.next()!.value;
      const right = this.parseMultiplicative();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseMultiplicative(): ClangNode | undefined {
    let left = this.parseUnary();
    while (["*", "/", "%"].includes(this.peek()?.value || "")) {
      const op = this.next()!.value;
      const right = this.parseUnary();
      if (right) {
        left = {
          id: nextId(),
          kind: "BinaryOperator",
          opcode: op,
          inner: [left!, right]
        };
      }
    }
    return left;
  }

  private parseUnary(): ClangNode | undefined {
    const op = this.peek()?.value;
    if (op && ["++", "--", "!", "~", "+", "-", "*", "&"].includes(op)) {
      this.next();
      const operand = this.parseUnary();
      if (!operand) return undefined;
      return {
        id: nextId(),
        kind: "UnaryOperator",
        opcode: op,
        inner: [operand]
      };
    }
    return this.parsePostfix();
  }

  private parsePostfix(): ClangNode | undefined {
    let expr = this.parsePrimary();
    if (!expr) return undefined;

    while (this.pos < this.tokens.length) {
      const tok = this.peek();
      if (!tok) break;

      if (tok.value === "++" || tok.value === "--") {
        this.next();
        expr = {
          id: nextId(),
          kind: "UnaryOperator",
          opcode: tok.value,
          inner: [expr]
        };
      } else if (tok.value === "[") {
        this.next();
        const indexExpr = this.parseExpression();
        this.expect("]");
        expr = {
          id: nextId(),
          kind: "ArraySubscriptExpr",
          inner: indexExpr ? [expr, indexExpr] : [expr]
        };
      } else if (tok.value === "(") {
        // Function call
        this.next();
        const args: ClangNode[] = [];
        while (this.pos < this.tokens.length && this.peek()?.value !== ")") {
          const arg = this.parseExpression();
          if (arg) args.push(arg);
          if (this.peek()?.value === ",") this.pos++;
        }
        this.expect(")");
        const calleeName: string = expr.name || expr.referencedDecl?.name || "func";
        expr = {
          id: nextId(),
          kind: "CallExpr",
          inner: [
            {
              id: nextId(),
              kind: "DeclRefExpr",
              name: calleeName,
              referencedDecl: { id: nextId(), name: calleeName, kind: "FunctionDecl" }
            },
            ...args
          ]
        };
      } else if (tok.value === "." || tok.value === "->") {
        this.next();
        const memberName = this.next()?.value || "member";
        if (this.peek()?.value === "(") {
          // Member call: e.g. seen.insert(x), a.push_back(y)
          this.next();
          const args: ClangNode[] = [];
          while (this.pos < this.tokens.length && this.peek()?.value !== ")") {
            const arg = this.parseExpression();
            if (arg) args.push(arg);
            if (this.peek()?.value === ",") this.pos++;
          }
          this.expect(")");
          expr = {
            id: nextId(),
            kind: "CXXMemberCallExpr",
            referencedMemberDecl: memberName,
            inner: [
              {
                id: nextId(),
                kind: "MemberExpr",
                name: memberName,
                referencedDecl: { id: nextId(), name: memberName, kind: "CXXMethodDecl" },
                inner: [expr]
              },
              ...args
            ]
          };
        } else {
          expr = {
            id: nextId(),
            kind: "MemberExpr",
            name: memberName,
            referencedDecl: { id: nextId(), name: memberName, kind: "FieldDecl" },
            inner: [expr]
          };
        }
      } else {
        break;
      }
    }

    return expr;
  }

  private parsePrimary(): ClangNode | undefined {
    const tok = this.peek();
    if (!tok) return undefined;

    if (tok.value === "(") {
      this.next();
      const expr = this.parseExpression();
      this.expect(")");
      return expr;
    }

    if (tok.type === "NUMBER") {
      this.next();
      return {
        id: nextId(),
        kind: "IntegerLiteral",
        value: tok.value
      };
    }

    if (tok.type === "STRING") {
      this.next();
      return {
        id: nextId(),
        kind: "StringLiteral",
        value: tok.value
      };
    }

    if (tok.value === "true" || tok.value === "false") {
      this.next();
      return {
        id: nextId(),
        kind: "CXXBoolLiteralExpr",
        value: tok.value
      };
    }

    if (tok.type === "IDENTIFIER" || tok.type === "KEYWORD") {
      this.next();
      const sym = this.lookupSymbol(tok.value);
      return {
        id: nextId(),
        kind: "DeclRefExpr",
        name: tok.value,
        referencedDecl: {
          id: sym.id,
          name: sym.name,
          kind: sym.kind
        }
      };
    }

    return undefined;
  }
}

/**
 * Synthesizes a valid ClangNode AST from C++ source without Clang.
 */
export function synthesizeAstFromCpp(source: string): ClangNode {
  const tokens = tokenizeCpp(source);
  const builder = new CppAstBuilder(tokens);
  return builder.parseTranslationUnit();
}
