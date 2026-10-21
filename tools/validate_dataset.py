"""Basic integrity check for the reviewed C++ corpus."""
from __future__ import annotations

import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
missing = []
invalid = []
case_count = 0
seen_ids = set()
manifests = sorted((ROOT / "datasets").rglob("*.manifest.json"))
for manifest_path in manifests:
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    source_path = manifest_path.with_name(manifest_path.name.replace(".manifest.json", ".cpp"))
    if not source_path.exists():
        invalid.append(f"{manifest_path.name}:missing paired C++ file")
        continue
    source = source_path.read_text(encoding="utf-8")
    version = manifest.get("version", 1)
    if manifest.get("language") != "cpp":
        invalid.append(f"{manifest_path.name}:language must be cpp")
    if version >= 2 and (not isinstance(manifest.get("family"), str) or not isinstance(manifest.get("reviewedBy"), str)):
        invalid.append(f"{manifest_path.name}:version 2 requires family and reviewedBy")
    for case in manifest["cases"]:
        case_count += 1
        case_id = case.get("id")
        if not isinstance(case_id, str) or not case_id:
            invalid.append(f"{manifest_path.name}:case without stable id")
        elif case_id in seen_ids:
            invalid.append(f"duplicate case id: {case_id}")
        else:
            seen_ids.add(case_id)
        symbol = re.escape(case["symbol"])
        # Symbols only need to be unique within their paired translation unit.
        # Competitive-programming submissions naturally reuse names such as
        # `solve`, `f`, and `main` across separate files; the benchmark already
        # analyzes every manifest/source pair independently.
        if not re.search(rf"\b{symbol}\s*\(", source):
            missing.append(f"{manifest_path.name}:{case['symbol']}")
        if case["confidence"] not in {"exact", "estimated", "unknown"}:
            invalid.append(f"{manifest_path.name}:{case['id']}")
        if version >= 2:
            if not isinstance(case.get("inputSymbols"), list) or not isinstance(case.get("proof"), str):
                invalid.append(f"{manifest_path.name}:{case['id']}:missing inputSymbols or proof")
            origin = case.get("origin")
            if not isinstance(origin, dict) or origin.get("kind") not in {"authored", "licensed", "derived"} or not isinstance(origin.get("license"), str):
                invalid.append(f"{manifest_path.name}:{case['id']}:invalid origin record")

if missing:
    raise SystemExit(f"Missing symbols in reviewed corpus: {', '.join(missing)}")

if invalid:
    raise SystemExit(f"Invalid confidence values: {', '.join(invalid)}")

print(f"OK: {case_count} reviewed C++ cases across {len(manifests)} manifests")
