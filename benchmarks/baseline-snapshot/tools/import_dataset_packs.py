"""Import one reviewed representative per variant family from supplied ZIP packs.

The public corpus must measure independent algorithm families, not inflate its
score with formatting/name variants. This importer keeps the first stable case
for every (manifest family, variantOf) pair and materializes a normal paired
`.cpp` / `.manifest.json` dataset entry that the existing validator can read.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import zipfile
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATASETS = ROOT / "datasets"


def slug(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "-", value.lower()).strip("-")


def function_name_for(level: str, original: str) -> str:
    # `level` normally comes from an archive filename.  Archive stems may
    # contain hyphens, but a C++ identifier cannot.  Sanitise every generated
    # component, not only the user-provided function spelling, so imported
    # corpora remain syntactically valid before the analyzer sees them.
    safe_level = re.sub(r"[^A-Za-z0-9_]", "_", level)
    safe_original = re.sub(r"[^A-Za-z0-9_]", "_", original)
    return f"pack_{safe_level}_{safe_original}"


def matching_brace(source: str, opening: int) -> int:
    """Return the matching C++ brace while respecting strings and comments."""
    depth = 0
    quote: str | None = None
    line_comment = False
    block_comment = False
    index = opening
    while index < len(source):
        current = source[index]
        following = source[index + 1] if index + 1 < len(source) else ""
        if line_comment:
            if current == "\n": line_comment = False
            index += 1
            continue
        if block_comment:
            if current == "*" and following == "/": block_comment = False; index += 2; continue
            index += 1
            continue
        if quote:
            if current == "\\": index += 2; continue
            if current == quote: quote = None
            index += 1
            continue
        if current == "/" and following == "/": line_comment = True; index += 2; continue
        if current == "/" and following == "*": block_comment = True; index += 2; continue
        if current in ("'", '\"'): quote = current; index += 1; continue
        if current == "{": depth += 1
        elif current == "}":
            depth -= 1
            if depth == 0: return index
        index += 1
    raise ValueError("unterminated function body")


def source_through_function(source: str, original_symbol: str) -> str:
    """Materialize one case from a shared multi-case source file.

    Some reviewed packs intentionally put variants in one file. Keeping the
    prefix through the requested definition preserves its includes, macros,
    structs, and preceding helpers, while excluding later variants that may
    redeclare the same support types.
    """
    for match in re.finditer(rf"\b{re.escape(original_symbol)}\s*\(", source):
        opening = source.find("{", match.end())
        semicolon = source.find(";", match.end())
        if opening < 0 or (semicolon >= 0 and semicolon < opening):
            continue
        return source[:matching_brace(source, opening) + 1] + "\n"
    raise ValueError(f"could not find a function definition for {original_symbol}")


def resolve_source_symbol(source: str, declared_symbol: str, case_id: str) -> str | None:
    """Return the literal definition name for an explicitly named target.

    A few generated reviewed packs give every target a collision-free spelling
    such as ``solvelevel0_hq_015`` while their manifest intentionally records
    the conceptual target as ``solve``.  This is a packaging convention, not
    an inference about program behaviour.  Accept only the deterministic
    ``<declared-symbol><normalised-case-id>`` spelling after first preferring
    the declared name itself; all other mismatches remain rejected.
    """
    try:
        source_through_function(source, declared_symbol)
        return declared_symbol
    except ValueError:
        suffix = re.sub(r"[^A-Za-z0-9_]", "_", case_id)
        generated_symbol = f"{declared_symbol}{suffix}"
        try:
            source_through_function(source, generated_symbol)
            return generated_symbol
        except ValueError:
            return None


def rewrite_entry_source(source: str, original_symbol: str, symbol: str) -> str:
    extracted = source_through_function(source, original_symbol)
    # Each materialized corpus translation unit needs a unique exported
    # function. Rename both the definition and any direct recursion safely on
    # identifier boundaries; this is source packaging, never runtime analysis.
    rewritten = re.sub(rf"\b{re.escape(original_symbol)}\b", symbol, extracted)
    if not re.search(rf"\b{re.escape(symbol)}\s*\(", rewritten):
        raise ValueError(f"could not materialize {symbol}: selected function was not rewritten")
    return rewritten


def source_is_usable(source: str) -> bool:
    """Reject evidently damaged generated snippets without guessing a repair.

    The supplied CP packs are standalone translation units and conventionally
    begin with an include.  A token-level template substitution can corrupt
    that directive (for example ``#ibitsclude``); importing it would turn the
    benchmark into a test of malformed source rather than analyzer quality.
    Keep the input faithful: report and skip it instead of trying to infer the
    author's intended identifier.
    """
    return bool(re.search(r"^\s*#\s*include\b", source, re.MULTILINE))


def normalize_generator_escaped_braces(source: str) -> str:
    """Undo the brace escaping used by a small number of generated packs.

    Those packs consistently serialize every C++ brace as ``{{`` / ``}}``;
    without this normalization their materialized files are not valid C++ and
    cannot exercise the analyzer at all.  The signature is deliberately
    strict, so ordinary C++ sources (including nested initializer lists) are
    left byte-for-byte intact.
    """
    opens = source.count("{{")
    closes = source.count("}}")
    if opens < 3 or opens != closes:
        return source
    return source.replace("{{", "{").replace("}}", "}")


def load_representatives(archive_path: Path, level: str) -> tuple[list[tuple[str, dict, str]], list[str]]:
    representatives: list[tuple[str, dict, str]] = []
    skipped: list[str] = []
    with zipfile.ZipFile(archive_path) as archive:
        manifests = [name for name in archive.namelist() if name.endswith(".manifest.json")]
        for manifest_name in manifests:
            manifest = json.loads(archive.read(manifest_name))
            groups: dict[str, list[dict]] = defaultdict(list)
            for case in manifest["cases"]:
                groups[case.get("variantOf") or case["id"]].append(case)
            directory = manifest_name.rsplit("/", 1)[0]
            # Some manually reviewed packs keep every function in one source
            # file and omit `sourceFile` from individual cases. Support that
            # explicit paired layout without guessing: the manifest stem maps
            # directly to its sibling `.cpp` file.
            shared_source = manifest_name.removesuffix(".manifest.json") + ".cpp"
            family = manifest.get("family") or Path(manifest_name).stem.removesuffix(".manifest")
            for variant, cases in sorted(groups.items()):
                case = min(cases, key=lambda item: item["id"])
                source_name = f"{directory}/{case['sourceFile']}" if case.get("sourceFile") else shared_source
                source = normalize_generator_escaped_braces(archive.read(source_name).decode("utf-8"))
                if not source_is_usable(source):
                    skipped.append(f"{archive_path.name}:{case['id']} ({case['sourceFile']}; malformed include directive)")
                    continue
                # A manifest can reference a declaration-only helper or a
                # symbol from a different shared source. Do not abort the
                # entire import (or invent a repair); keep only cases whose
                # declared target has a complete materializable definition.
                source_symbol = resolve_source_symbol(source, case["symbol"], case["id"])
                if source_symbol is None:
                    skipped.append(
                        f"{archive_path.name}:{case['id']} "
                        f"(could not find a function definition for {case['symbol']})"
                    )
                    continue
                resolved_case = dict(case)
                resolved_case["_sourceSymbol"] = source_symbol
                resolved_case["_sourcePath"] = source_name
                representatives.append((family, resolved_case, source))
    return representatives, skipped


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("archives", nargs="+", type=Path, help="Level-1/Level-2 dataset pack ZIP files")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    selected: list[tuple[str, str, dict, str]] = []
    skipped: list[str] = []
    for archive in args.archives:
        level = "l1" if "level1" in archive.name.lower() else "l2" if "level2" in archive.name.lower() else slug(archive.stem)
        representatives, rejected = load_representatives(archive, level)
        skipped.extend(rejected)
        for family, case, source in representatives:
            selected.append((level, family, case, source))

    base_stems = Counter(f"cpp-pack-{level}-{slug(case['id'])}" for level, _, case, _ in selected)
    materialized: list[tuple[str, str, str, dict, str]] = []
    target_names: set[str] = set()
    for level, family, case, source in selected:
        base_stem = f"cpp-pack-{level}-{slug(case['id'])}"
        if base_stems[base_stem] > 1:
            # The archive has reused an id across different topic folders.
            # Preserve both reviewed cases using the explicit folder identity;
            # never silently discard or merge distinct algorithms.
            source_group = case["_sourcePath"].rsplit("/", 2)[-2]
            stem = f"{base_stem}-{slug(source_group)}"
        else:
            stem = base_stem
        if stem in target_names:
            raise ValueError(f"duplicate materialized dataset stem: {stem}")
        target_names.add(stem)
        materialized.append((stem, level, family, case, source))

    print(f"Selected {len(selected)} independent variant families from {len(args.archives)} pack(s).")
    for reason in skipped:
        print(f"Skipped malformed source: {reason}", file=sys.stderr)
    for stem, level, family, case, source in materialized:
        symbol = function_name_for(level, case["symbol"])
        rewritten = rewrite_entry_source(source, case["_sourceSymbol"], symbol)
        print(f"{stem}: {family}/{case['variantOf'] or case['id']} -> {symbol}")
        if args.dry_run:
            continue
        imported = dict(case)
        imported.pop("_sourceSymbol", None)
        imported.pop("_sourcePath", None)
        # Use the materialized filename identity for the public case id too.
        # Some packs legitimately reuse a numeric id in two different topic
        # folders (for example Prefix and DP); `stem` already carries that
        # explicit topic suffix, so this keeps case ids globally unique.
        imported["id"] = stem.removeprefix("cpp-")
        imported["symbol"] = symbol
        imported["variantOf"] = f"pack-{level}-{case['variantOf'] or case['id']}"
        imported.pop("sourceFile", None)
        imported["origin"] = {
            "kind": "derived",
            "license": case.get("origin", {}).get("license", "CC0-1.0-or-authored"),
        }
        manifest = {
            "version": 2,
            "language": "cpp",
            "family": f"pack-{level}-{slug(family)}",
            "reviewedBy": "imported-pack-representative",
            "cases": [imported],
        }
        (DATASETS / f"{stem}.cpp").write_text(rewritten, encoding="utf-8")
        (DATASETS / f"{stem}.manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, zipfile.BadZipFile, KeyError) as error:
        print(f"dataset import failed: {error}", file=sys.stderr)
        raise SystemExit(2)
