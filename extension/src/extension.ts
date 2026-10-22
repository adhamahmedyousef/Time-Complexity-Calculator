import * as vscode from "vscode";
import { spawn } from "node:child_process";
import { existsSync } from "node:fs";
import { resolve } from "node:path";

interface AnalysisResult {
  worstCaseTime: string;
  auxiliarySpace: string;
  confidence: string;
  confidencePercent?: number;
  memoryProfile?: { bytesPerUnit: number; basis: "typed-local-storage" | "generic" };
  proof: string[];
}

function confidencePercent(result: AnalysisResult): number {
  if (typeof result.confidencePercent === "number") return result.confidencePercent;
  return result.confidence === "exact" ? 99 : result.confidence === "estimated" ? 85 : 0;
}

function displayComplexity(value: string): string {
  const superscripts: Record<string, string> = {
    "0": "⁰", "1": "¹", "2": "²", "3": "³", "4": "⁴", "5": "⁵", "6": "⁶", "7": "⁷", "8": "⁸", "9": "⁹",
    ".": "·", "n": "ⁿ", "m": "ᵐ", "k": "ᵏ", "V": "ⱽ", "E": "ᴱ", "W": "ᵂ"
  };
  return value
    .replace(/sqrt n/g, "√n")
    .replace(/\^([0-9.]+)/g, (_, exponent: string) => [...exponent].map((character) => superscripts[character] ?? character).join(""))
    .replace(/\^([nmkVEW])/g, (_, exponent: string) => superscripts[exponent] ?? `^${exponent}`)
    .replace(/α/g, "α")
    .replace(/([A-Za-z][⁰¹²³⁴⁵⁶⁷⁸⁹]*) log([⁰¹²³⁴⁵⁶⁷⁸⁹]*) ([A-Za-z])/g, "$1 · log$2 $3")
    .replace(/V\+E/g, "V + E");
}

function stripOuterParentheses(value: string): string {
  const text = value.trim();
  if (!text.startsWith("(") || !text.endsWith(")")) return text;
  let depth = 0;
  for (let index = 0; index < text.length; index += 1) {
    if (text[index] === "(") depth += 1;
    if (text[index] === ")") depth -= 1;
    if (depth === 0 && index < text.length - 1) return text;
  }
  return stripOuterParentheses(text.slice(1, -1));
}

function topLevelPlusParts(value: string): string[] {
  const parts: string[] = [];
  let depth = 0;
  let start = 0;
  for (let index = 0; index < value.length; index += 1) {
    if (value[index] === "(") depth += 1;
    else if (value[index] === ")") depth -= 1;
    else if (value[index] === "+" && depth === 0) {
      parts.push(value.slice(start, index));
      start = index + 1;
    }
  }
  parts.push(value.slice(start));
  return parts.map((part) => part.trim()).filter(Boolean);
}

/** Evaluates the supported auxiliary-space expression at equal symbolic scales. */
function estimateUnits(expression: string, scale: number): number | undefined {
  const match = /^O\((.+)\)$/.exec(expression.trim());
  if (!match || /Unknown|Does not terminate|α|!/.test(match[1])) return undefined;
  const values: Record<string, number> = { n: scale, m: scale, V: scale, E: scale, W: scale, sum: scale, maxVal: scale, bits: scale };
  const evaluate = (raw: string): number | undefined => {
    const text = stripOuterParentheses(raw.replace(/·/g, " ").trim());
    const sumParts = topLevelPlusParts(text);
    if (sumParts.length > 1) {
      const terms = sumParts.map(evaluate);
      return terms.every((term): term is number => term !== undefined) ? terms.reduce((total, term) => total + term, 0) : undefined;
    }
    const tokens: string[] = [];
    for (let index = 0; index < text.length;) {
      if (/\s/.test(text[index])) { index += 1; continue; }
      if (text[index] === "(") {
        let depth = 1;
        const start = index + 1;
        index += 1;
        while (index < text.length && depth > 0) { if (text[index] === "(") depth += 1; else if (text[index] === ")") depth -= 1; index += 1; }
        if (depth !== 0) return undefined;
        tokens.push("(" + text.slice(start, index - 1) + ")");
        continue;
      }
      const start = index;
      while (index < text.length && !/\s/.test(text[index]) && text[index] !== "(") index += 1;
      tokens.push(text.slice(start, index));
    }
    let product = 1;
    for (let index = 0; index < tokens.length; index += 1) {
      const token = tokens[index];
      let factor: number | undefined;
      if (token.startsWith("(")) factor = evaluate(token.slice(1, -1));
      else if (token === "log") {
        const next = tokens[++index];
        if (next === "log") {
          const variable = tokens[++index];
          const value = values[variable];
          factor = value && value > 1 ? Math.log2(Math.log2(value)) : 0;
        } else {
          const value = values[next];
          factor = value && value > 1 ? Math.log2(value) : 0;
        }
      } else if (token === "sqrt") {
        const value = values[tokens[++index]];
        factor = value === undefined ? undefined : Math.sqrt(value);
      } else {
        const exponential = /^(\d+)\^([A-Za-z_][A-Za-z0-9_]*)$/.exec(token);
        const polynomial = /^([A-Za-z_][A-Za-z0-9_]*)(?:\^(\d+))?$/.exec(token);
        if (exponential) factor = Math.pow(Number(exponential[1]), values[exponential[2]] ?? Number.NaN);
        else if (polynomial) factor = Math.pow(values[polynomial[1]] ?? Number.NaN, Number(polynomial[2] ?? "1"));
        else if (/^\d+$/.test(token)) factor = Number(token);
      }
      if (factor === undefined || !Number.isFinite(factor)) return undefined;
      product *= factor;
      if (!Number.isFinite(product)) return undefined;
    }
    return product;
  };
  return evaluate(match[1]);
}

function formatBytes(bytes: number): string {
  const units = ["B", "KiB", "MiB", "GiB", "TiB"];
  let value = bytes;
  let index = 0;
  while (value >= 1024 && index < units.length - 1) { value /= 1024; index += 1; }
  return `${value >= 100 ? value.toFixed(0) : value >= 10 ? value.toFixed(1) : value.toFixed(2)} ${units[index]}`;
}

function memoryScale(result: AnalysisResult): string | undefined {
  if (result.auxiliarySpace === "Unknown") return undefined;
  const bytesPerUnit = result.memoryProfile?.bytesPerUnit ?? 8;
  const scales = [1_000, 10_000, 100_000, 1_000_000];
  const estimates = scales.map((scale) => {
    const units = estimateUnits(result.auxiliarySpace, scale);
    return units === undefined ? undefined : formatBytes(units * bytesPerUnit);
  });
  if (estimates.some((estimate) => estimate === undefined)) return undefined;
  const width = result.memoryProfile?.basis === "typed-local-storage" ? `${bytesPerUnit} B typed payload` : `${bytesPerUnit} B generic unit`;
  return `Memory scale: 1K ${estimates[0]} · 10K ${estimates[1]} · 100K ${estimates[2]} · 1M ${estimates[3]} (${width}; excludes allocator overhead).`;
}

function memoryEntries(result: AnalysisResult): readonly { label: string; value: string }[] | undefined {
  if (result.auxiliarySpace === "Unknown") return undefined;
  const bytesPerUnit = result.memoryProfile?.bytesPerUnit ?? 8;
  const scales = [1_000, 10_000, 100_000, 1_000_000];
  const values = scales.map((scale) => estimateUnits(result.auxiliarySpace, scale))
    .map((units) => units === undefined ? undefined : formatBytes(units * bytesPerUnit));
  return values.every((value): value is string => value !== undefined)
    ? ["1K", "10K", "100K", "1M"].map((label, index) => ({ label, value: values[index] }))
    : undefined;
}

function escapeHtml(value: string): string {
  return value.replace(/[&<>"']/g, (character) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", "\"": "&quot;", "'": "&#39;" }[character] ?? character));
}

/** Offline LaTeX-like typesetting without loading a web CDN or runtime. */
function mathHtml(value: string): string {
  return escapeHtml(value)
    .replace(/sqrt\s+([A-Za-z0-9]+)/g, "√$1")
    .replace(/\^([A-Za-z0-9.]+)/g, "<sup>$1</sup>")
    .replace(/\b(log)(<sup>[^<]+<\/sup>)?\s+([A-Za-z])/g, "$1$2 $3");
}

function resultDetailsHtml(result: AnalysisResult, minimumConfidence: number): string {
  const score = confidencePercent(result);
  const withheld = result.confidence === "unknown" || score < minimumConfidence;
  const memory = memoryEntries(result);
  const proof = result.proof.map((item) => `<li>${mathHtml(item)}</li>`).join("");
  const memoryGrid = memory ? `<p class="section-label">memory by size</p><div class="memory-grid">${memory.map((entry) => `<div><p class="mem-label">${entry.label}</p><p class="mem-value">${entry.value}</p></div>`).join("")}</div>` : "";
  return `<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8" />
  <meta http-equiv="Content-Security-Policy" content="default-src 'none'; style-src 'unsafe-inline';" />
  <style>
    :root { font-family:var(--vscode-font-family); color:#d4d4d4; }
    body { margin:0; padding:18px; background:var(--vscode-editor-background); }
    .analysis-card { background:#252526; border:1px solid #3c3c3c; border-radius:8px; padding:14px 16px; max-width:380px; box-sizing:border-box; }
    .card-header { display:flex; justify-content:space-between; align-items:center; cursor:pointer; user-select:none; }
    .row { font-size:14px; color:#d4d4d4; margin:0 0 6px; }
    .row:last-child { margin-bottom:0; }
    .value { color:#4ec9b0; font-family:Cambria Math, STIX Two Math, var(--vscode-font-family); font-weight:500; }
    sup { font-size:.66em; line-height:0; vertical-align:super; }
    .chevron { color:#858585; font-size:18px; line-height:1; transition:transform .15s ease; }
    .chevron.open { transform:rotate(180deg); }
    .card-details { border-top:1px solid #3c3c3c; margin-top:12px; padding-top:12px; }
    .section-label { font-size:12px; color:#858585; letter-spacing:.3px; text-transform:lowercase; margin:0 0 6px; }
    .reason-text { font-size:13px; color:#cccccc; line-height:1.7; margin:0 0 14px; padding-left:18px; }
    .reason-text li { margin:0 0 3px; }
    .memory-grid { display:grid; grid-template-columns:repeat(4, 1fr); gap:8px; text-align:center; }
    .mem-label { font-size:11px; color:#858585; margin:0; }
    .mem-value { font-size:13px; color:#e0e0e0; margin:2px 0 0; white-space:nowrap; }
  </style></head><body><div class="analysis-card" id="card">
    <div class="card-header" id="toggle" role="button" aria-expanded="false" tabindex="0">
      <div class="card-summary"><p class="row">Worst case <span class="value">${withheld ? " - " : mathHtml(result.worstCaseTime)}</span></p><p class="row">Space <span class="value">${withheld ? " - " : mathHtml(result.auxiliarySpace)}</span></p></div>
      <span class="chevron" id="chevron" aria-hidden="true">▾</span>
    </div>
    <div class="card-details" id="details" hidden><p class="section-label">${withheld ? `confidence ${score}% (minimum ${minimumConfidence}%)` : "reason"}</p><ul class="reason-text">${proof}</ul>${!withheld ? memoryGrid : ""}</div>
  </div><script>
    const toggle=document.getElementById('toggle'); const details=document.getElementById('details'); const chevron=document.getElementById('chevron');
    const flip=()=>{ const open=!details.hidden; details.hidden=open; chevron.textContent=open?'▾':'▴'; chevron.classList.toggle('open',!open); toggle.setAttribute('aria-expanded',String(!open)); };
    toggle.addEventListener('click',flip); toggle.addEventListener('keydown',(event)=>{ if(event.key==='Enter'||event.key===' '){event.preventDefault();flip();} });
  </script></body></html>`;
}

function resultNotificationText(result: AnalysisResult, minimumConfidence: number): string {
  const score = confidencePercent(result);
  const withheld = result.confidence === "unknown" || score < minimumConfidence;
  if (withheld) {
    return `Result withheld · ${score}% confidence`;
  }
  return `Time ${displayComplexity(result.worstCaseTime)}  ·  Space ${displayComplexity(result.auxiliarySpace)}  ·  ${score}% ${result.confidence}`;
}

function conciseReason(result: AnalysisResult, maximumLength = 170): string {
  const text = result.proof.join(" ").replace(/\s+/g, " ").trim();
  return text.length <= maximumLength ? text : `${text.slice(0, maximumLength - 3).trimEnd()}…`;
}

function formatWork(value: number): string {
  if (value < 1_000) return value.toFixed(value < 10 ? 1 : 0);
  if (value < 1_000_000) return `${(value / 1_000).toFixed(value < 10_000 ? 1 : 0)}K`;
  if (value < 1_000_000_000) return `${(value / 1_000_000).toFixed(value < 10_000_000 ? 1 : 0)}M`;
  return `${(value / 1_000_000_000).toFixed(1)}B`;
}

function formatInputSize(value: number): string {
  if (value < 1_000) return Math.floor(value).toString();
  if (value < 1_000_000) return `${(value / 1_000).toFixed(value < 10_000 ? 1 : 0)}K`;
  if (value < 1_000_000_000) return `${(value / 1_000_000).toFixed(value < 10_000_000 ? 1 : 0)}M`;
  return `${(value / 1_000_000_000).toFixed(value < 10_000_000_000 ? 1 : 0)}B`;
}

/**
 * Inverts the proven auxiliary-space expression numerically at equal symbolic
 * dimensions. This is a memory-capacity estimate, not a runtime prediction.
 */
function estimatedInputCapacity(result: AnalysisResult, budgetBytes = 256 * 1024 * 1024): string | undefined {
  if (result.auxiliarySpace === "Unknown") return undefined;
  const bytesPerUnit = result.memoryProfile?.bytesPerUnit ?? 8;
  const fits = (input: number): boolean => {
    const units = estimateUnits(result.auxiliarySpace, input);
    return units !== undefined && Number.isFinite(units) && units * bytesPerUnit <= budgetBytes;
  };
  if (!fits(1)) return "Estimated memory limit: below n = 1 (256 MiB)";
  let lower = 1;
  let upper = 2;
  const maximumSearch = 1_000_000_000_000;
  while (upper < maximumSearch && fits(upper)) { lower = upper; upper *= 2; }
  if (upper >= maximumSearch && fits(upper)) return "Estimated memory limit: not reached below n = 1T (256 MiB)";
  for (let iteration = 0; iteration < 52; iteration += 1) {
    const middle = (lower + upper) / 2;
    if (fits(middle)) lower = middle;
    else upper = middle;
  }
  return `Estimated max input: n ≈ ${formatInputSize(lower)} under 256 MiB`;
}

/** A machine-independent growth display. It is deliberately not a seconds estimate. */
function relativeWork(result: AnalysisResult): string | undefined {
  const scales = [1_000, 10_000];
  const values = scales.map((scale) => estimateUnits(result.worstCaseTime, scale));
  if (!values.every((value): value is number => value !== undefined && Number.isFinite(value))) return undefined;
  return `Relative work: 1K ≈ ${formatWork(values[0])} · 10K ≈ ${formatWork(values[1])}`;
}

function resultDetailsNotificationText(result: AnalysisResult, minimumConfidence: number): string {
  const score = confidencePercent(result);
  const withheld = result.confidence === "unknown" || score < minimumConfidence;
  const capacity = estimatedInputCapacity(result);
  if (withheld) return `Confidence ${score}% ${result.confidence}  ·  Reason: ${conciseReason(result, 105)}`;
  // Kiro flattens every line separator in native notifications (including
  // U+2028/U+2029), so use one deliberate, readable line rather than a fake
  // multiline layout that will be collapsed by the host renderer.
  return [
    `Time ${displayComplexity(result.worstCaseTime)}`,
    `Space ${displayComplexity(result.auxiliarySpace)}`,
    `Confidence ${score}% ${result.confidence}`,
    ...(capacity ? [capacity] : [])
  ].join("  ·  ");
}

function fullExplanationNotificationText(result: AnalysisResult, minimumConfidence: number): string {
  const score = confidencePercent(result);
  return [
    `Reason · ${score}% ${result.confidence}`,
    ...result.proof.map((item) => `• ${item}`),
    `Results below ${minimumConfidence}% confidence are withheld.`
  ].join("  ·  ");
}

function runAnalyzer(executable: string, args: string[], source: string, clangPath?: string, nativeAnalyzerPath?: string, timeoutMs = 15000): Promise<string> {
  return new Promise((resolve, reject) => {
    const child = spawn(executable, args, {
      windowsHide: true,
      stdio: ["pipe", "pipe", "pipe"],
      env: {
        ...process.env,
        ELECTRON_RUN_AS_NODE: "1",
        ...(clangPath ? { PROJECT_X_CLANG: clangPath } : {}),
        ...(nativeAnalyzerPath?.trim() ? { PROJECT_X_NATIVE_ANALYZER: nativeAnalyzerPath.trim() } : {})
      }
    });
    let stdout = "";
    let stderr = "";
    let settled = false;

    const timer = setTimeout(() => {
      if (!settled) {
        settled = true;
        try { child.kill(); } catch { /* ignore */ }
        reject(new Error(`Analysis timed out after ${timeoutMs / 1000}s.`));
      }
    }, timeoutMs);

    child.stdout.setEncoding("utf8");
    child.stderr.setEncoding("utf8");
    child.stdout.on("data", (chunk: string) => { stdout += chunk; });
    child.stderr.on("data", (chunk: string) => { stderr += chunk; });
    child.on("error", (err) => {
      if (!settled) {
        settled = true;
        clearTimeout(timer);
        reject(err);
      }
    });
    child.on("close", (code) => {
      if (!settled) {
        settled = true;
        clearTimeout(timer);
        if (code === 0) resolve(stdout);
        else reject(new Error(stderr || `Analyzer exited with code ${code}`));
      }
    });
    child.stdin.end(source, "utf8");
  });
}

function resolveClangPath(configuredPath: string | undefined): string | undefined {
  if (configuredPath?.trim()) return configuredPath.trim();
  if (process.env.PROJECT_X_CLANG && existsSync(process.env.PROJECT_X_CLANG)) return process.env.PROJECT_X_CLANG;
  const candidates = process.platform === "win32"
    ? [
        "C:\\Program Files\\LLVM\\bin\\clang++.exe",
        "C:\\LLVM\\bin\\clang++.exe",
        "C:\\msys64\\mingw64\\bin\\clang++.exe"
      ]
    : process.platform === "darwin"
    ? [
        "/opt/homebrew/bin/clang++",
        "/usr/local/bin/clang++",
        "/usr/bin/clang++"
      ]
    : [
        "/usr/bin/clang++",
        "/usr/local/bin/clang++"
      ];
  for (const candidate of candidates) {
    if (existsSync(candidate)) return candidate;
  }
  return undefined;
}

function extractFunctionBody(documentText: string, startIndex: number): string | undefined {
  const braceIndex = documentText.indexOf("{", startIndex);
  if (braceIndex === -1) return undefined;
  let depth = 1;
  for (let i = braceIndex + 1; i < documentText.length; i++) {
    if (documentText[i] === "{") depth++;
    else if (documentText[i] === "}") {
      depth--;
      if (depth === 0) {
        return documentText.slice(startIndex, i + 1);
      }
    }
  }
  return undefined;
}

const analysisCache = new Map<string, AnalysisResult>();

class ComplexityCodeLensProvider implements vscode.CodeLensProvider {
  provideCodeLenses(document: vscode.TextDocument): vscode.CodeLens[] {
    const codeLenses: vscode.CodeLens[] = [];
    if (document.languageId !== "cpp") return codeLenses;
    const text = document.getText();
    const regex = /^[ \t]*(?:(?:inline|static|constexpr|virtual|explicit|friend)\s+)*(?:[\w:<>&*~]+\s+)+([a-zA-Z_]\w*)\s*\([^;)]*\)\s*(?:const\s*)?(?:noexcept\s*)?\s*\{/gm;
    let match: RegExpExecArray | null;
    while ((match = regex.exec(text)) !== null) {
      const functionName = match[1];
      if (/^(?:if|while|for|switch|catch)$/.test(functionName)) continue;
      const startPos = document.positionAt(match.index);
      const range = new vscode.Range(startPos, startPos);
      codeLenses.push(new vscode.CodeLens(range, {
        title: `$(watch) Calculate Complexity: ${functionName}`,
        command: "projectX.calculateFunctionComplexity",
        arguments: [document, match.index, functionName]
      }));
    }
    return codeLenses;
  }
}

class ComplexityHoverProvider implements vscode.HoverProvider {
  provideHover(document: vscode.TextDocument, position: vscode.Position): vscode.ProviderResult<vscode.Hover> {
    const wordRange = document.getWordRangeAtPosition(position);
    if (!wordRange) return undefined;
    const word = document.getText(wordRange);
    const cached = analysisCache.get(word);
    if (!cached) return undefined;

    const md = new vscode.MarkdownString();
    md.isTrusted = true;
    md.appendMarkdown(`### ⏱ Complexity: \`${word}\` (Built By [@VoidHub](https://voidhub.co))\n\n`);
    md.appendMarkdown(`- **Worst-Case Time:** \`${cached.worstCaseTime}\`\n`);
    md.appendMarkdown(`- **Auxiliary Space:** \`${cached.auxiliarySpace}\`\n`);
    md.appendMarkdown(`- **Confidence:** \`${confidencePercent(cached)}% ${cached.confidence}\`\n\n`);
    if (cached.proof.length > 0) {
      md.appendMarkdown(`> **Proof:** ${cached.proof[0]}\n`);
    }
    return new vscode.Hover(md, wordRange);
  }
}

export function activate(context: vscode.ExtensionContext): void {
  context.subscriptions.push(vscode.commands.registerCommand("projectX.openVoidHub", () => {
    void vscode.env.openExternal(vscode.Uri.parse("https://voidhub.co"));
  }));

  const voidHubStatus = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Right, 100);
  voidHubStatus.text = "$(watch) Built By @VoidHub";
  voidHubStatus.tooltip = "Time Complexity Calculator - Built By @VoidHub (https://voidhub.co)";
  voidHubStatus.command = "projectX.openVoidHub";
  voidHubStatus.show();
  context.subscriptions.push(voidHubStatus);

  const showResultNotification = (result: AnalysisResult, minimumConfidence: number): void => {
    const message = resultNotificationText(result, minimumConfidence);
    const withheld = result.confidence === "unknown" || confidencePercent(result) < minimumConfidence;
    const notification = withheld
      ? vscode.window.showWarningMessage(message, "Details", "Built By @VoidHub")
      : vscode.window.showInformationMessage(message, "Details", "Built By @VoidHub");
    void notification.then((action) => {
      if (action === "Built By @VoidHub") {
        void vscode.env.openExternal(vscode.Uri.parse("https://voidhub.co"));
        return;
      }
      if (action !== "Details") return;
      const details = vscode.window.showInformationMessage(resultDetailsNotificationText(result, minimumConfidence), "Open explanation", "Built By @VoidHub");
      void details.then((detailAction) => {
        if (detailAction === "Built By @VoidHub") {
          void vscode.env.openExternal(vscode.Uri.parse("https://voidhub.co"));
        } else if (detailAction === "Open explanation") {
          void vscode.window.showInformationMessage(fullExplanationNotificationText(result, minimumConfidence), "Built By @VoidHub").then((expAction) => {
            if (expAction === "Built By @VoidHub") void vscode.env.openExternal(vscode.Uri.parse("https://voidhub.co"));
          });
        }
      });
    });
  };

  const executeAnalysis = async (source: string, fullDocument: string, funcName?: string): Promise<void> => {
    const analyzerRequest = JSON.stringify({ selection: source, document: fullDocument });
    const configuredPath = vscode.workspace.getConfiguration().get<string>("projectX.analyzerPath");
    const configuredClangPath = vscode.workspace.getConfiguration().get<string>("projectX.clangPath");
    const configuredNativeAnalyzerPath = vscode.workspace.getConfiguration().get<string>("projectX.nativeAnalyzerPath");
    const minimumConfidence = vscode.workspace.getConfiguration().get<number>("projectX.minimumConfidence", 80);
    const clangPath = resolveClangPath(configuredClangPath);

    if (!clangPath) {
      const choice = await vscode.window.showErrorMessage(
        "Clang++ was not found. Time Complexity Calculator requires Clang++ to parse C++ AST.",
        "Installation Guide",
        "Configure Path"
      );
      if (choice === "Installation Guide") {
        void vscode.env.openExternal(vscode.Uri.parse("https://releases.llvm.org/"));
      } else if (choice === "Configure Path") {
        void vscode.commands.executeCommand("workbench.action.openSettings", "projectX.clangPath");
      }
      return;
    }

    const packagedMjs = resolve(context.extensionPath, "dist", "analyzer-cli.mjs");
    const packagedDirect = resolve(context.extensionPath, "dist", "analyzer", "cli.js");
    const developmentAnalyzer = resolve(context.extensionPath, "..", "analyzer", "dist", "cli.js");
    const bundledCli = existsSync(packagedMjs) ? packagedMjs : existsSync(packagedDirect) ? packagedDirect : existsSync(developmentAnalyzer) ? developmentAnalyzer : undefined;
    const useBundledAnalyzer = !configuredPath && Boolean(bundledCli);
    const analyzer = useBundledAnalyzer && bundledCli ? process.execPath : (configuredPath || "project-x-analyzer");
    const analyzerArgs = useBundledAnalyzer && bundledCli ? [bundledCli] : [];
    try {
      const stdout = await runAnalyzer(analyzer, analyzerArgs, analyzerRequest, clangPath, configuredNativeAnalyzerPath);
      const result = JSON.parse(stdout) as AnalysisResult;
      if (funcName) {
        analysisCache.set(funcName, result);
      }
      showResultNotification(result, minimumConfidence);
    } catch (error) {
      const detail = error instanceof Error ? error.message : String(error);
      void vscode.window.showWarningMessage(`Could not start the local analyzer. Configure projectX.analyzerPath. ${detail}`);
    }
  };

  context.subscriptions.push(vscode.commands.registerCommand("projectX.calculateTimeComplexity", async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor || editor.document.languageId !== "cpp" || editor.selection.isEmpty) {
      void vscode.window.showWarningMessage("Select one complete C++ function before calculating complexity.");
      return;
    }
    const source = editor.document.getText(editor.selection);
    await executeAnalysis(source, editor.document.getText());
  }));

  context.subscriptions.push(vscode.commands.registerCommand("projectX.calculateFunctionComplexity", async (doc: vscode.TextDocument, startIndex: number, funcName: string) => {
    const text = doc.getText();
    const funcBody = extractFunctionBody(text, startIndex);
    if (!funcBody) {
      void vscode.window.showWarningMessage(`Could not extract full body for function '${funcName}'.`);
      return;
    }
    await executeAnalysis(funcBody, text, funcName);
  }));

  const enableCodeLens = vscode.workspace.getConfiguration().get<boolean>("projectX.enableCodeLens", true);
  if (enableCodeLens) {
    context.subscriptions.push(
      vscode.languages.registerCodeLensProvider({ language: "cpp" }, new ComplexityCodeLensProvider())
    );
  }

  const enableHover = vscode.workspace.getConfiguration().get<boolean>("projectX.enableHover", true);
  if (enableHover) {
    context.subscriptions.push(
      vscode.languages.registerHoverProvider({ language: "cpp" }, new ComplexityHoverProvider())
    );
  }
}

export function deactivate(): void {}
