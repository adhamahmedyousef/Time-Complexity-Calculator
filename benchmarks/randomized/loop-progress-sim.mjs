#!/usr/bin/env node
/*
 * Randomized soundness campaign: generated single-counter while-loop programs
 * are checked against an independent trip-count simulator.
 *
 * Why this is a valid differential test: the ENGINE reads only the generated
 * C++ text (it never sees the variant descriptors), while the simulator
 * interprets the variant descriptors directly. Any disagreement between the
 * C++ text and the descriptor would be a generator bug; given that they agree,
 * the simulator is an independent oracle for this restricted family.
 *
 * Invariants checked (violation = engine bug):
 *   INV1  simulated loop terminates  =>  engine must not claim "Does not terminate"
 *   INV2  simulated loop does not terminate (cap reached)
 *         =>  engine must not claim any finite bound (must be Unknown or "Does not terminate")
 *   INV3  literal-bound loop where engine claims O(1)
 *         =>  simulated trip count must be small (<= 100 here)
 *
 * Determinism: mulberry32(seed); the exact generated sources are saved with
 * every result so any finding is reproducible without the generator.
 *
 * Usage:
 *   node benchmarks/randomized/loop-progress-sim.mjs --dist=analyzer/dist/index.js --label=after --seed=20261017
 */
import { mkdirSync, writeFileSync } from "node:fs";
import { dirname, resolve } from "node:path";
import { fileURLToPath, pathToFileURL } from "node:url";

const scriptDir = dirname(fileURLToPath(import.meta.url));
const root = resolve(scriptDir, "..", "..");
const args = process.argv.slice(2);
const option = (name, fallback) => {
  const found = args.find((argument) => argument.startsWith(`--${name}=`));
  return found ? found.slice(name.length + 3) : fallback;
};

const dist = resolve(root, option("dist", "analyzer/dist/index.js"));
const label = option("label", "run");
const seed = Number(option("seed", "20261017"));
const caseCount = Number(option("cases", "120"));
const outPath = resolve(root, option("out", `benchmarks/randomized/results/loop-progress-sim-${label}-seed${seed}.json`));
if (!process.env.PROJECT_X_CLANG) process.env.PROJECT_X_CLANG = "C:\\Program Files\\LLVM\\bin\\clang++.exe";

const { analyseCppFunctionsInDocument } = await import(pathToFileURL(dist).href);
const { parseBound, boundsEqual } = await import(pathToFileURL(dist.replace(/index\.js$/, "bound.js")).href);

function mulberry32(seedValue) {
  let a = seedValue >>> 0;
  return function next() {
    a |= 0;
    a = (a + 0x6d2b79f5) | 0;
    let t = Math.imul(a ^ (a >>> 15), 1 | a);
    t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t;
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
  };
}
const rnd = mulberry32(seed);
const pick = (list) => list[Math.floor(rnd() * list.length) % list.length];

const START_VALUES = [-3, 0, 1, 4];
const LITERAL_BOUNDS = [0, 1, 3, 5, 10];
const CMPS = ["<", "<=", ">", ">="];
const CAP = 100000;
const CONSTANT_TRIP_LIMIT = 100;

// Variant descriptors: each yields C++ statement text plus a simulator step.
function makeVariant(start) {
  const k = 1 + Math.floor(rnd() * 3);
  const pool = [
    { id: "inc-pre", text: "++i;", step: (state) => { state.i += 1; } },
    { id: "inc-post", text: "i++;", step: (state) => { state.i += 1; } },
    { id: `inc-add${k}`, text: `i += ${k};`, step: (state) => { state.i += k; } },
    { id: "dec-pre", text: "--i;", step: (state) => { state.i -= 1; } },
    { id: `dec-sub${k}`, text: `i -= ${k};`, step: (state) => { state.i -= k; } },
    { id: "acc-then-inc", text: "s += i; ++i;", step: (state) => { state.s += state.i; state.i += 1; } },
    { id: "acc-via-post", text: "s += i++;", step: (state) => { state.s += state.i; state.i += 1; } },
    { id: "inc-first-acc", text: "++i; s += i;", step: (state) => { state.i += 1; state.s += state.i; } },
    {
      id: "guarded-toward",
      text: `if (i < ${start + 3}) ++i;`,
      step: (state) => { if (state.i < start + 3) state.i += 1; }
    },
    {
      id: "guarded-away",
      text: `if (i > ${start + 2}) --i;`,
      step: (state) => { if (state.i > start + 2) state.i -= 1; }
    },
    { id: "acc-only", text: "s += i;", step: (state) => { state.s += state.i; } },
    { id: "cancel", text: "{ ++i; --i; }", step: (state) => { state.i += 1; state.i -= 1; } }
  ];
  return pick(pool);
}

const simulate = (start, cmp, bound, variants) => {
  const state = { i: start, s: 0 };
  let iterations = 0;
  const condition = () => {
    if (cmp === "<") return state.i < bound;
    if (cmp === "<=") return state.i <= bound;
    if (cmp === ">") return state.i > bound;
    return state.i >= bound;
  };
  while (condition()) {
    for (const variant of variants) variant.step(state);
    iterations += 1;
    if (iterations > CAP) return { terminates: false, iterations: CAP, state };
  }
  return { terminates: true, iterations, state };
};

const isConstantBound = (text) => {
  if (text === "O(1)") return true;
  try {
    const parsed = parseBound(text);
    const one = parseBound("O(1)");
    if (parsed && one) return boundsEqual(parsed, one);
  } catch {
    /* not parseable */
  }
  return false;
};

const records = [];
const violations = [];
for (let index = 0; index < caseCount; index += 1) {
  const start = pick(START_VALUES);
  const cmp = pick(CMPS);
  const symbolic = index % 4 === 3;
  const bound = symbolic ? 10 : pick(LITERAL_BOUNDS);
  const variants = [makeVariant(start)];
  if (rnd() < 0.4) variants.push(makeVariant(start));
  const bodyText = variants.map((variant) => variant.text).join(" ");
  const boundText = symbolic ? "n" : String(bound);
  // The symbol embeds the label, so it must stay a valid C++ identifier: a
  // label like "round7-before" would otherwise emit `int rnd_round7-before_...`
  // which Clang cannot parse and every case would silently come back Unknown.
  const symbolLabel = label.replace(/[^A-Za-z0-9_]/g, "_");
  const symbol = `rnd_${symbolLabel}_${seed}_${index}`;
  const source = `int ${symbol}(int n) { int i = ${start}; int s = 0; while (i ${cmp} ${boundText}) { ${bodyText} } return s; }`;
  const simulated = simulate(start, cmp, bound, variants);

  const result = analyseCppFunctionsInDocument(source, [symbol]).get(symbol);
  const time = result?.worstCaseTime ?? "Unknown";
  const confidence = result?.confidence ?? "unknown";
  const finiteClaim = time !== "Unknown" && time !== "Does not terminate";
  const nonTerminationClaim = time === "Does not terminate";

  const found = [];
  if (simulated.terminates && nonTerminationClaim) found.push("INV1");
  if (!simulated.terminates && finiteClaim) found.push("INV2");
  if (!symbolic && simulated.terminates && isConstantBound(time) && simulated.iterations > CONSTANT_TRIP_LIMIT) found.push("INV3");
  if (confidence === "exact" && time === "Unknown") found.push("WARN-inconsistent-confidence");

  records.push({
    id: symbol,
    source,
    symbolic,
    simulated,
    engine: { time, space: result?.auxiliarySpace ?? "Unknown", confidence },
    violations: found
  });
  if (found.length > 0) violations.push(records[records.length - 1]);
}

// A run where every case abstains is not a soundness result — it is the
// signature of generated sources that do not compile (or a missing toolchain).
// Fail loudly instead of reporting a meaningless 0-violation campaign.
const abstained = records.filter((entry) => entry.engine.time === "Unknown").length;
if (abstained === caseCount) {
  console.error(`all ${caseCount} cases abstained (Unknown) - the run is not a soundness result; check the generated sources and PROJECT_X_CLANG`);
  process.exitCode = 2;
}

const report = {
  campaign: "loop-progress-sim",
  label,
  seed,
  caseCount,
  dist,
  invariants: {
    INV1: "simulated termination => engine must not claim non-termination",
    INV2: "simulated non-termination => engine must not claim a finite bound",
    INV3: `literal-bound O(1) claim => simulated trip count <= ${CONSTANT_TRIP_LIMIT}`
  },
  cap: CAP,
  violations,
  records,
  startedForTask: "2026-10-17 analyzer bug hunt"
};
mkdirSync(dirname(outPath), { recursive: true });
writeFileSync(outPath, `${JSON.stringify(report, null, 1)}\n`, "utf8");
console.log(`cases: ${caseCount}, violations: ${violations.length}`);
for (const entry of violations) {
  console.log(`VIOLATION ${entry.violations.join(",")}: ${entry.source}`);
  console.log(`  engine: ${entry.engine.time} | ${entry.engine.space} | ${entry.engine.confidence}; simulated: ${JSON.stringify(entry.simulated)}`);
}
console.log(`written: ${outPath}`);
