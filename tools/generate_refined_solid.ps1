Add-Type -AssemblyName System.Drawing

function Create-RefinedSolidLogo {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = "AntiAlias"
    $g.InterpolationMode = "HighQualityBicubic"
    $g.TextRenderingHint = "AntiAliasGridFit"
    
    # Solid Deep VoidHub Dark Background (#0b0e14)
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0b0e14"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Solid Rounded Squircle Card (#0e121a)
    $cardPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $radius = 80
    $cardPath.AddArc(20, 20, $radius, $radius, 180, 90)
    $cardPath.AddArc(20 + 472 - $radius, 20, $radius, $radius, 270, 90)
    $cardPath.AddArc(20 + 472 - $radius, 20 + 472 - $radius, $radius, $radius, 0, 90)
    $cardPath.AddArc(20, 20 + 472 - $radius, $radius, $radius, 90, 90)
    $cardPath.CloseFigure()

    $cardBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0e121a"))
    $g.FillPath($cardBrush, $cardPath)
    $cardBrush.Dispose()

    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#1e2535")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::White)
    $tealBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))

    # --- TOP MECHANICAL STOPWATCH HARDWARE (SOLID) ---
    # Center Crown Stem & Push Button
    $g.FillRectangle($whiteBrush, 246, 50, 20, 18)
    
    $crownPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $cR = 8
    $crownPath.AddArc(232, 36, $cR, $cR, 180, 90)
    $crownPath.AddArc(232 + 48 - $cR, 36, $cR, $cR, 270, 90)
    $crownPath.AddArc(232 + 48 - $cR, 36 + 16 - $cR, $cR, $cR, 0, 90)
    $crownPath.AddArc(232, 36 + 16 - $cR, $cR, $cR, 90, 90)
    $crownPath.CloseFigure()
    $g.FillPath($tealBrush, $crownPath)
    $crownPath.Dispose()

    # Angled Pushers (Left -40 deg, Right +40 deg)
    $g.TranslateTransform(256, 260)
    $g.RotateTransform(-40)
    $g.FillRectangle($whiteBrush, -9, -190, 18, 16)
    $g.ResetTransform()

    $g.TranslateTransform(256, 260)
    $g.RotateTransform(40)
    $g.FillRectangle($whiteBrush, -9, -190, 18, 16)
    $g.ResetTransform()

    # --- STOPWATCH OUTER RIM (SOLID WHITE) ---
    $rimPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::White), 12
    $g.DrawEllipse($rimPen, 96, 100, 320, 320)
    $rimPen.Dispose()

    # Inner Dial Precision Ticks (at 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)
    $tickMajor = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 5
    $tickMinor = New-Object System.Drawing.Pen ([System.Drawing.Color]::FromArgb(120, 255, 255, 255)), 3
    for ($a = 0; $a -lt 360; $a += 30) {
        $rad = $a * [Math]::PI / 180.0
        $isMajor = ($a % 90 -eq 0)
        $pen = if ($isMajor) { $tickMajor } else { $tickMinor }
        $len = if ($isMajor) { 16 } else { 10 }
        $rOuter = 148
        $rInner = $rOuter - $len
        $x1 = 256 + $rInner * [Math]::Cos($rad)
        $y1 = 260 + $rInner * [Math]::Sin($rad)
        $x2 = 256 + $rOuter * [Math]::Cos($rad)
        $y2 = 260 + $rOuter * [Math]::Sin($rad)
        $g.DrawLine($pen, [float]$x1, [float]$y1, [float]$x2, [float]$y2)
    }
    $tickMajor.Dispose()
    $tickMinor.Dispose()

    # Dynamic Complexity Speed Arc in VoidHub Teal
    $arcPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 8
    $arcPen.StartCap = "Round"
    $arcPen.EndCap = "Round"
    $g.DrawArc($arcPen, 120, 124, 272, 272, -35, 95)
    $arcPen.Dispose()

    # Stopwatch Needle (Pointing up-right from upper center)
    $needlePen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 6
    $needlePen.StartCap = "RoundAnchor"
    $needlePen.EndCap = "ArrowAnchor"
    $g.DrawLine($needlePen, 256, 205, 335, 145)
    $needlePen.Dispose()
    $g.FillEllipse($whiteBrush, 249, 198, 14, 14)

    # --- SOLID "O(n)" BIG-O LABEL (CENTERED & HARMONIZED) ---
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = "Center"
    $sf.LineAlignment = "Center"
    
    # "O" in solid white
    $oFont = New-Object System.Drawing.Font "Arial", 96, "Bold", "Pixel"
    $g.DrawString("O", $oFont, $whiteBrush, 212, 290, $sf)
    $oFont.Dispose()

    # "(n)" in solid VoidHub teal
    $nFont = New-Object System.Drawing.Font "Arial", 78, "Bold", "Pixel"
    $g.DrawString("(n)", $nFont, $tealBrush, 296, 295, $sf)
    $nFont.Dispose()

    # --- SIGNATURE VOIDHUB TEAL HORIZONTAL BAR (SOLID) ---
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 160; $barY = 355; $barW = 192; $barH = 16; $barR = 8
    $barPath.AddArc($barX, $barY, $barR, $barR, 180, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY, $barR, $barR, 270, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY + $barH - $barR, $barR, $barR, 0, 90)
    $barPath.AddArc($barX, $barY + $barH - $barR, $barR, $barR, 90, 90)
    $barPath.CloseFigure()
    $g.FillPath($tealBrush, $barPath)
    $barPath.Dispose()

    $whiteBrush.Dispose()
    $tealBrush.Dispose()

    $bmp.Save($outputPath, [System.Drawing.Imaging.ImageFormat]::Png)
    $g.Dispose()
    $bmp.Dispose()
}

$dir = "C:\Users\j\.gemini\antigravity\brain\ab52261d-cec2-41c8-98c9-813678f3fe6b"
Create-RefinedSolidLogo (Join-Path $dir "solid_dial_refined.png")
Write-Host "Created solid_dial_refined.png successfully!"
