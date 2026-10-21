# Read-only status check for the optional local LLVM/Clang LibTooling build.
# Run from the repository root:
#   powershell -ExecutionPolicy Bypass -File .\tools\libtooling-status.ps1

$buildRoot = "C:\Users\j\.project-x-deps\llvm-build-22.1.8-native"
$ninja = "C:\Users\j\AppData\Local\Microsoft\WinGet\Packages\Ninja-build.Ninja_Microsoft.Winget.Source_8wekyb3d8bbwe\ninja.exe"
# This is the total reported when the currently configured LibTooling target
# resumed. Update it only if the LLVM build directory is reconfigured.
$totalWorkItems = 1051
$tooling = Get-ChildItem -LiteralPath $buildRoot -Filter "clangTooling.lib" -Recurse -ErrorAction SilentlyContinue |
    Select-Object -First 1 -ExpandProperty FullName
$matchers = Get-ChildItem -LiteralPath $buildRoot -Filter "clangASTMatchers.lib" -Recurse -ErrorAction SilentlyContinue |
    Select-Object -First 1 -ExpandProperty FullName
$workers = Get-Process -Name "cmake", "ninja", "cl" -ErrorAction SilentlyContinue |
    Select-Object Name, Id, CPU, StartTime

if ($tooling -and $matchers) {
    Write-Host "LibTooling build: COMPLETE" -ForegroundColor Green
    Write-Host "clangTooling: $tooling"
    Write-Host "clangASTMatchers: $matchers"
    exit 0
}

if ($workers) {
    Write-Host "LibTooling build: RUNNING" -ForegroundColor Yellow
    $workers | Format-Table -AutoSize
    if (Test-Path -LiteralPath $ninja) {
        $dryRun = & $ninja -C $buildRoot -n clangTooling clangASTMatchers 2>$null
        $progressLines = @($dryRun | Where-Object { $_ -match '^\[\d+/(\d+)\]' })
        if ($progressLines.Count -gt 0 -and $progressLines[0] -match '^\[\d+/(\d+)\]') {
            $remaining = [int]$Matches[1]
            $completed = [Math]::Max(0, $totalWorkItems - $remaining)
            $percent = [Math]::Round((100 * $completed) / $totalWorkItems, 1)
            Write-Host ("Progress: {0}/{1} ({2}%) | remaining: {3}" -f $completed, $totalWorkItems, $percent, $remaining) -ForegroundColor Cyan
        }
        else {
            Write-Host "Progress: preparing build graph; run the command again in a minute." -ForegroundColor Cyan
        }
    }
    Write-Host "The build is complete only after both clangTooling.lib and clangASTMatchers.lib appear."
    exit 0
}

Write-Host "LibTooling build: NOT RUNNING / NOT COMPLETE" -ForegroundColor Red
Write-Host "No final clangTooling libraries were found under $buildRoot."
exit 1
