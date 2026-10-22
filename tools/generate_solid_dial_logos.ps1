Add-Type -AssemblyName System.Drawing

function Create-SolidLogoOption1 {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = "AntiAlias"
    $g.InterpolationMode = "HighQualityBicubic"
    $g.TextRenderingHint = "AntiAliasGridFit"
    
    # Solid Dark Background
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0b0e14"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Solid Rounded Squircle Tile
    $cardPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $radius = 80
    $cardPath.AddArc(20, 20, $radius, $radius, 180, 90)
    $cardPath.AddArc(20 + 472 - $radius, 20, $radius, $radius, 270, 90)
    $cardPath.AddArc(20 + 472 - $radius, 20 + 472 - $radius, $radius, $radius, 0, 90)
    $cardPath.AddArc(20, 20 + 472 - $radius, $radius, $radius, 90, 90)
    $cardPath.CloseFigure()

    # Solid Slate-Dark Card
    $cardBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0f131c"))
    $g.FillPath($cardBrush, $cardPath)
    $cardBrush.Dispose()

    # Solid Crisp Border
    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#1f2738")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    # --- STOPWATCH CROWN & PUSHERS (SOLID) ---
    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::White)
    $tealBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))

    # Top Crown Stem & Button
    $g.FillRectangle($whiteBrush, 246, 52, 20, 18)
    
    $crownPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $cR = 8
    $crownPath.AddArc(236, 40, $cR, $cR, 180, 90)
    $crownPath.AddArc(236 + 40 - $cR, 40, $cR, $cR, 270, 90)
    $crownPath.AddArc(236 + 40 - $cR, 40 + 16 - $cR, $cR, $cR, 0, 90)
    $crownPath.AddArc(236, 40 + 16 - $cR, $cR, $cR, 90, 90)
    $crownPath.CloseFigure()
    $g.FillPath($tealBrush, $crownPath)
    $crownPath.Dispose()

    # Top-Right Angled Pusher (at ~45 degrees)
    $g.TranslateTransform(256, 260)
    $g.RotateTransform(40)
    $pusherPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $pusherPath.AddRectangle((New-Object System.Drawing.Rectangle -10, -188, 20, 14))
    $g.FillPath($whiteBrush, $pusherPath)
    $g.ResetTransform()

    # --- STOPWATCH DIAL (SOLID) ---
    # Outer Solid Ring (Teal + White)
    $ringPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::White), 10
    $g.DrawEllipse($ringPen, 96, 100, 320, 320)
    $ringPen.Dispose()

    # Inner Dial Tick Marks (Solid)
    $tickMajor = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 5
    $tickMinor = New-Object System.Drawing.Pen ([System.Drawing.Color]::FromArgb(140, 255, 255, 255)), 3
    for ($a = 0; $a -lt 360; $a += 30) {
        $rad = $a * [Math]::PI / 180.0
        $isMajor = ($a % 90 -eq 0)
        $pen = if ($isMajor) { $tickMajor } else { $tickMinor }
        $len = if ($isMajor) { 18 } else { 10 }
        $rOuter = 150
        $rInner = $rOuter - $len
        $x1 = 256 + $rInner * [Math]::Cos($rad)
        $y1 = 260 + $rInner * [Math]::Sin($rad)
        $x2 = 256 + $rOuter * [Math]::Cos($rad)
        $y2 = 260 + $rOuter * [Math]::Sin($rad)
        $g.DrawLine($pen, [float]$x1, [float]$y1, [float]$x2, [float]$y2)
    }
    $tickMajor.Dispose()
    $tickMinor.Dispose()

    # Solid Complexity Growth Curve (Exponential/Logarithmic speed curve rising sharply)
    $curvePen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 9
    $curvePen.StartCap = [System.Drawing.Drawing2D.LineCap]::Round
    $curvePen.EndCap = [System.Drawing.Drawing2D.LineCap]::Round
    $g.DrawArc($curvePen, 116, 120, 280, 280, -30, 90)
    $curvePen.Dispose()

    # Stopwatch Needle (Pointing up-right at the curve)
    $needlePen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 6
    $needlePen.StartCap = [System.Drawing.Drawing2D.LineCap]::RoundAnchor
    $needlePen.EndCap = [System.Drawing.Drawing2D.LineCap]::ArrowAnchor
    $g.DrawLine($needlePen, 256, 260, 335, 185)
    $needlePen.Dispose()

    # Center Pin
    $g.FillEllipse($whiteBrush, 248, 252, 16, 16)

    # --- SOLID "O(n)" BIG-O LABEL ---
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = "Center"
    $sf.LineAlignment = "Center"
    
    # "O" in solid white
    $oFont = New-Object System.Drawing.Font "Arial", 92, "Bold", "Pixel"
    $g.DrawString("O", $oFont, $whiteBrush, 218, 305, $sf)
    $oFont.Dispose()

    # "(n)" in solid VoidHub teal
    $nFont = New-Object System.Drawing.Font "Arial", 74, "Bold", "Pixel"
    $g.DrawString("(n)", $nFont, $tealBrush, 298, 310, $sf)
    $nFont.Dispose()

    # --- SOLID VOIDHUB TEAL ACCENT BAR (SIGNATURE BRAND MARK) ---
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 176; $barY = 368; $barW = 160; $barH = 14; $barR = 7
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

function Create-SolidLogoOption2 {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = "AntiAlias"
    $g.InterpolationMode = "HighQualityBicubic"
    $g.TextRenderingHint = "AntiAliasGridFit"
    
    # Solid Dark Background
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0b0e14"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Solid Rounded Squircle Tile
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

    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#1f2738")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::White)
    $tealBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))

    # Top Stopwatch Crown & Pusher in solid
    $g.FillRectangle($whiteBrush, 247, 54, 18, 16)
    $g.FillRectangle($tealBrush, 238, 42, 36, 14)

    # Dial Ring (Outer Solid Double Ring)
    $outerRingPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 8
    $g.DrawEllipse($outerRingPen, 96, 96, 320, 320)
    $outerRingPen.Dispose()

    $innerRingPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::FromArgb(60, 255, 255, 255)), 2
    $g.DrawEllipse($innerRingPen, 114, 114, 284, 284)
    $innerRingPen.Dispose()

    # Minimal Solid Hour Ticks
    $tickPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::White), 4
    for ($a = 0; $a -lt 360; $a += 45) {
        $rad = $a * [Math]::PI / 180.0
        $x1 = 256 + 130 * [Math]::Cos($rad)
        $y1 = 256 + 130 * [Math]::Sin($rad)
        $x2 = 256 + 144 * [Math]::Cos($rad)
        $y2 = 256 + 144 * [Math]::Sin($rad)
        $g.DrawLine($tickPen, [float]$x1, [float]$y1, [float]$x2, [float]$y2)
    }
    $tickPen.Dispose()

    # Speedometer Needle
    $needlePen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 6
    $g.DrawLine($needlePen, 256, 256, 340, 180)
    $needlePen.Dispose()
    $g.FillEllipse($whiteBrush, 248, 248, 16, 16)

    # Large Bold Solid O(n) centered
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = "Center"
    $sf.LineAlignment = "Center"
    
    $bigFont = New-Object System.Drawing.Font "Arial", 100, "Bold", "Pixel"
    $g.DrawString("O(n)", $bigFont, $whiteBrush, 256, 290, $sf)
    $bigFont.Dispose()

    # Solid Underline Bar
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 160; $barY = 356; $barW = 192; $barH = 16; $barR = 8
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

function Create-SolidLogoOption3 {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = "AntiAlias"
    $g.InterpolationMode = "HighQualityBicubic"
    $g.TextRenderingHint = "AntiAliasGridFit"
    
    # Solid Dark Background
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0b0e14"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Squircle Tile
    $cardPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $radius = 80
    $cardPath.AddArc(20, 20, $radius, $radius, 180, 90)
    $cardPath.AddArc(20 + 472 - $radius, 20, $radius, $radius, 270, 90)
    $cardPath.AddArc(20 + 472 - $radius, 20 + 472 - $radius, $radius, $radius, 0, 90)
    $cardPath.AddArc(20, 20 + 472 - $radius, $radius, $radius, 90, 90)
    $cardPath.CloseFigure()

    $cardBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0f121a"))
    $g.FillPath($cardBrush, $cardPath)
    $cardBrush.Dispose()

    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#1f2738")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::White)
    $tealBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))

    # Stopwatch Top Hardware (Crown + Dual Pushers)
    $g.FillRectangle($whiteBrush, 246, 50, 20, 18)
    $g.FillRectangle($tealBrush, 236, 36, 40, 16)
    
    # Left Pusher (at -45 deg)
    $g.TranslateTransform(256, 260)
    $g.RotateTransform(-40)
    $g.FillRectangle($whiteBrush, -10, -188, 20, 14)
    $g.ResetTransform()
    
    # Right Pusher (at +40 deg)
    $g.TranslateTransform(256, 260)
    $g.RotateTransform(40)
    $g.FillRectangle($whiteBrush, -10, -188, 20, 14)
    $g.ResetTransform()

    # Outer Stopwatch Rim (Solid White)
    $rimPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::White), 12
    $g.DrawEllipse($rimPen, 96, 100, 320, 320)
    $rimPen.Dispose()

    # Rising Algorithmic Trajectory Curve (Solid VoidHub Teal)
    $trajPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 8
    $trajPen.StartCap = [System.Drawing.Drawing2D.LineCap]::Round
    $trajPen.EndCap = [System.Drawing.Drawing2D.LineCap]::Round
    $g.DrawArc($trajPen, 118, 122, 276, 276, -40, 100)
    $trajPen.Dispose()

    # Big-O in center
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = "Center"
    $sf.LineAlignment = "Center"
    
    # "O" huge bold white
    $oFont = New-Object System.Drawing.Font "Arial", 120, "Bold", "Pixel"
    $g.DrawString("O", $oFont, $whiteBrush, 215, 255, $sf)
    $oFont.Dispose()

    # "n" bold teal
    $nFont = New-Object System.Drawing.Font "Arial", 90, "Bold", "Pixel"
    $g.DrawString("(n)", $nFont, $tealBrush, 305, 262, $sf)
    $nFont.Dispose()

    # Precision Tick Marks on the top rim
    $tickMajor = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 5
    for ($a = 280; $a -le 350; $a += 14) {
        $rad = $a * [Math]::PI / 180.0
        $x1 = 256 + 146 * [Math]::Cos($rad)
        $y1 = 260 + 146 * [Math]::Sin($rad)
        $x2 = 256 + 160 * [Math]::Cos($rad)
        $y2 = 260 + 160 * [Math]::Sin($rad)
        $g.DrawLine($tickMajor, [float]$x1, [float]$y1, [float]$x2, [float]$y2)
    }
    $tickMajor.Dispose()

    # Solid Signature Underline Bar at the bottom
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 168; $barY = 348; $barW = 176; $barH = 16; $barR = 8
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
Create-SolidLogoOption1 (Join-Path $dir "solid_dial_option_1.png")
Create-SolidLogoOption2 (Join-Path $dir "solid_dial_option_2.png")
Create-SolidLogoOption3 (Join-Path $dir "solid_dial_option_3.png")
Write-Host "All solid dial logos created successfully!"
