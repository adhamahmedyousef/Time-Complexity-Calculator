Add-Type -AssemblyName System.Drawing

function Create-VoidHubLogo1 {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = [System.Drawing.Drawing2D.SmoothingMode]::AntiAlias
    $g.InterpolationMode = [System.Drawing.Drawing2D.InterpolationMode]::HighQualityBicubic
    $g.TextRenderingHint = [System.Drawing.Text.TextRenderingHint]::AntiAliasGridFit
    
    # Background
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0b0e14"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Rounded Squircle Card
    $cardRect = New-Object System.Drawing.Rectangle 16, 16, 480, 480
    $cardPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $radius = 72
    $cardPath.AddArc(16, 16, $radius, $radius, 180, 90)
    $cardPath.AddArc(16 + 480 - $radius, 16, $radius, $radius, 270, 90)
    $cardPath.AddArc(16 + 480 - $radius, 16 + 480 - $radius, $radius, $radius, 0, 90)
    $cardPath.AddArc(16, 16 + 480 - $radius, $radius, $radius, 90, 90)
    $cardPath.CloseFigure()

    $cardBrush = New-Object System.Drawing.Drawing2D.LinearGradientBrush (
        (New-Object System.Drawing.Point 0, 0),
        (New-Object System.Drawing.Point 512, 512),
        ([System.Drawing.ColorTranslator]::FromHtml("#131822")),
        ([System.Drawing.ColorTranslator]::FromHtml("#0d1017"))
    )
    $g.FillPath($cardBrush, $cardPath)
    $cardBrush.Dispose()

    # Subtle glowing card border
    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#242f42")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    # Outer decorative glow arc (Time complexity speed curve)
    $curvePen = New-Object System.Drawing.Pen ([System.Drawing.Color]::FromArgb(60, 45, 212, 191)), 6
    $g.DrawArc($curvePen, 40, 40, 432, 432, -45, 120)
    $curvePen.Dispose()
    
    $curvePen2 = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#2dd4bf")), 3
    $g.DrawArc($curvePen2, 40, 40, 432, 432, -20, 60)
    $curvePen2.Dispose()

    # Monogram "VH" (Bold, white, geometric)
    $vhFont = New-Object System.Drawing.Font "Arial", 168, "Bold", "Pixel"
    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::FromArgb(255, 255, 255, 255))
    
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = [System.Drawing.StringAlignment]::Center
    $sf.LineAlignment = [System.Drawing.StringAlignment]::Center
    
    # Draw VH slightly above center to accommodate the teal bar and O(n) badge
    $g.DrawString("VH", $vhFont, $whiteBrush, 256, 210, $sf)
    $vhFont.Dispose()
    $whiteBrush.Dispose()

    # Signature VoidHub Cyan/Teal Horizontal Bar
    # Positioned right under VH, matching the voidhub.co layout
    $tealBrush = New-Object System.Drawing.Drawing2D.LinearGradientBrush (
        (New-Object System.Drawing.Point 120, 315),
        (New-Object System.Drawing.Point 392, 315),
        ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")),
        ([System.Drawing.ColorTranslator]::FromHtml("#2dd4bf"))
    )
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 126
    $barY = 320
    $barW = 260
    $barH = 20
    $barR = 10
    $barPath.AddArc($barX, $barY, $barR, $barR, 180, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY, $barR, $barR, 270, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY + $barH - $barR, $barR, $barR, 0, 90)
    $barPath.AddArc($barX, $barY + $barH - $barR, $barR, $barR, 90, 90)
    $barPath.CloseFigure()
    $g.FillPath($tealBrush, $barPath)
    $tealBrush.Dispose()
    $barPath.Dispose()

    # Time Complexity Tag below: "O(n) CALCULATOR" in sleek monospace
    $subFont = New-Object System.Drawing.Font "Consolas", 24, "Bold", "Pixel"
    $subBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#2dd4bf"))
    $g.DrawString("O(n) CALCULATOR", $subFont, $subBrush, 256, 385, $sf)
    $subFont.Dispose()
    $subBrush.Dispose()
    
    # Small stop watch / complexity tick marks on bottom
    $dotBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::FromArgb(160, 45, 212, 191))
    $g.FillEllipse($dotBrush, 130, 428, 6, 6)
    $g.FillEllipse($dotBrush, 253, 428, 6, 6)
    $g.FillEllipse($dotBrush, 376, 428, 6, 6)
    $dotBrush.Dispose()

    $bmp.Save($outputPath, [System.Drawing.Imaging.ImageFormat]::Png)
    $g.Dispose()
    $bmp.Dispose()
}

function Create-VoidHubLogo2 {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = [System.Drawing.Drawing2D.SmoothingMode]::AntiAlias
    $g.InterpolationMode = [System.Drawing.Drawing2D.InterpolationMode]::HighQualityBicubic
    $g.TextRenderingHint = [System.Drawing.Text.TextRenderingHint]::AntiAliasGridFit
    
    # Background
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0b0e14"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Squircle Tile
    $cardPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $radius = 72
    $cardPath.AddArc(16, 16, $radius, $radius, 180, 90)
    $cardPath.AddArc(16 + 480 - $radius, 16, $radius, $radius, 270, 90)
    $cardPath.AddArc(16 + 480 - $radius, 16 + 480 - $radius, $radius, $radius, 0, 90)
    $cardPath.AddArc(16, 16 + 480 - $radius, $radius, $radius, 90, 90)
    $cardPath.CloseFigure()

    $cardBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#0e121a"))
    $g.FillPath($cardBrush, $cardPath)
    $cardBrush.Dispose()

    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#1f2737")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    # Monogram "VH"
    $vhFont = New-Object System.Drawing.Font "Arial", 180, "Bold", "Pixel"
    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::FromArgb(255, 255, 255, 255))
    
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = [System.Drawing.StringAlignment]::Center
    $sf.LineAlignment = [System.Drawing.StringAlignment]::Center
    
    $g.DrawString("VH", $vhFont, $whiteBrush, 256, 230, $sf)
    $vhFont.Dispose()
    $whiteBrush.Dispose()

    # Signature VoidHub Cyan/Teal Underline Bar
    $tealBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 120
    $barY = 350
    $barW = 272
    $barH = 22
    $barR = 10
    $barPath.AddArc($barX, $barY, $barR, $barR, 180, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY, $barR, $barR, 270, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY + $barH - $barR, $barR, $barR, 0, 90)
    $barPath.AddArc($barX, $barY + $barH - $barR, $barR, $barR, 90, 90)
    $barPath.CloseFigure()
    $g.FillPath($tealBrush, $barPath)
    $tealBrush.Dispose()
    $barPath.Dispose()

    # Glowing Big-O badge at top-right
    $badgeRect = New-Object System.Drawing.Rectangle 340, 48, 120, 46
    $badgePath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $badgeR = 22
    $badgePath.AddArc(340, 48, $badgeR, $badgeR, 180, 90)
    $badgePath.AddArc(340 + 120 - $badgeR, 48, $badgeR, $badgeR, 270, 90)
    $badgePath.AddArc(340 + 120 - $badgeR, 48 + 46 - $badgeR, $badgeR, $badgeR, 0, 90)
    $badgePath.AddArc(340, 48 + 46 - $badgeR, $badgeR, $badgeR, 90, 90)
    $badgePath.CloseFigure()

    $badgeBg = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::FromArgb(40, 0, 223, 162))
    $g.FillPath($badgeBg, $badgePath)
    $badgeBg.Dispose()

    $badgeBorder = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")), 2
    $g.DrawPath($badgeBorder, $badgePath)
    $badgeBorder.Dispose()

    $oFont = New-Object System.Drawing.Font "Consolas", 22, "Bold", "Pixel"
    $oBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))
    $g.DrawString("O(n)", $oFont, $oBrush, 400, 71, $sf)
    $oFont.Dispose()
    $oBrush.Dispose()

    $bmp.Save($outputPath, [System.Drawing.Imaging.ImageFormat]::Png)
    $g.Dispose()
    $bmp.Dispose()
}

function Create-VoidHubLogo3 {
    param([string]$outputPath)
    $size = 512
    $bmp = New-Object System.Drawing.Bitmap $size, $size
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    
    $g.SmoothingMode = [System.Drawing.Drawing2D.SmoothingMode]::AntiAlias
    $g.InterpolationMode = [System.Drawing.Drawing2D.InterpolationMode]::HighQualityBicubic
    $g.TextRenderingHint = [System.Drawing.Text.TextRenderingHint]::AntiAliasGridFit
    
    # Background
    $bgBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#090c10"))
    $g.FillRectangle($bgBrush, 0, 0, $size, $size)
    $bgBrush.Dispose()

    # Squircle Tile
    $cardPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $radius = 72
    $cardPath.AddArc(16, 16, $radius, $radius, 180, 90)
    $cardPath.AddArc(16 + 480 - $radius, 16, $radius, $radius, 270, 90)
    $cardPath.AddArc(16 + 480 - $radius, 16 + 480 - $radius, $radius, $radius, 0, 90)
    $cardPath.AddArc(16, 16 + 480 - $radius, $radius, $radius, 90, 90)
    $cardPath.CloseFigure()

    $cardBrush = New-Object System.Drawing.Drawing2D.LinearGradientBrush (
        (New-Object System.Drawing.Point 0, 0),
        (New-Object System.Drawing.Point 512, 512),
        ([System.Drawing.ColorTranslator]::FromHtml("#111622")),
        ([System.Drawing.ColorTranslator]::FromHtml("#0a0d13"))
    )
    $g.FillPath($cardBrush, $cardPath)
    $cardBrush.Dispose()

    $borderPen = New-Object System.Drawing.Pen ([System.Drawing.ColorTranslator]::FromHtml("#1e2736")), 3
    $g.DrawPath($borderPen, $cardPath)
    $borderPen.Dispose()

    # Circular chronometer dial behind the logo
    $dialPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::FromArgb(40, 0, 223, 162)), 4
    $g.DrawEllipse($dialPen, 64, 64, 384, 384)
    $dialPen.Dispose()

    # Dial tick marks around the ring
    $tickPen = New-Object System.Drawing.Pen ([System.Drawing.Color]::FromArgb(70, 0, 223, 162)), 3
    for ($angle = 0; $angle -lt 360; $angle += 30) {
        $rad = $angle * [Math]::PI / 180.0
        $x1 = 256 + 182 * [Math]::Cos($rad)
        $y1 = 256 + 182 * [Math]::Sin($rad)
        $x2 = 256 + 192 * [Math]::Cos($rad)
        $y2 = 256 + 192 * [Math]::Sin($rad)
        $g.DrawLine($tickPen, [float]$x1, [float]$y1, [float]$x2, [float]$y2)
    }
    $tickPen.Dispose()

    # Monogram "VH"
    $vhFont = New-Object System.Drawing.Font "Arial", 160, "Bold", "Pixel"
    $whiteBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.Color]::FromArgb(255, 255, 255, 255))
    
    $sf = New-Object System.Drawing.StringFormat
    $sf.Alignment = [System.Drawing.StringAlignment]::Center
    $sf.LineAlignment = [System.Drawing.StringAlignment]::Center
    
    $g.DrawString("VH", $vhFont, $whiteBrush, 256, 224, $sf)
    $vhFont.Dispose()
    $whiteBrush.Dispose()

    # Signature VoidHub Cyan/Teal Underline Bar
    $tealBrush = New-Object System.Drawing.Drawing2D.LinearGradientBrush (
        (New-Object System.Drawing.Point 130, 335),
        (New-Object System.Drawing.Point 382, 335),
        ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2")),
        ([System.Drawing.ColorTranslator]::FromHtml("#00b4d8"))
    )
    $barPath = New-Object System.Drawing.Drawing2D.GraphicsPath
    $barX = 136
    $barY = 335
    $barW = 240
    $barH = 18
    $barR = 8
    $barPath.AddArc($barX, $barY, $barR, $barR, 180, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY, $barR, $barR, 270, 90)
    $barPath.AddArc($barX + $barW - $barR, $barY + $barH - $barR, $barR, $barR, 0, 90)
    $barPath.AddArc($barX, $barY + $barH - $barR, $barR, $barR, 90, 90)
    $barPath.CloseFigure()
    $g.FillPath($tealBrush, $barPath)
    $tealBrush.Dispose()
    $barPath.Dispose()

    # Subtitle: VoidHub Complexity
    $subFont = New-Object System.Drawing.Font "Consolas", 20, "Bold", "Pixel"
    $subBrush = New-Object System.Drawing.SolidBrush ([System.Drawing.ColorTranslator]::FromHtml("#00dfa2"))
    $g.DrawString("TIME COMPLEXITY", $subFont, $subBrush, 256, 395, $sf)
    $subFont.Dispose()
    $subBrush.Dispose()

    $bmp.Save($outputPath, [System.Drawing.Imaging.ImageFormat]::Png)
    $g.Dispose()
    $bmp.Dispose()
}

$dir = "C:\Users\j\.gemini\antigravity\brain\ab52261d-cec2-41c8-98c9-813678f3fe6b"
Create-VoidHubLogo1 (Join-Path $dir "voidhub_logo_option_1.png")
Create-VoidHubLogo2 (Join-Path $dir "voidhub_logo_option_2.png")
Create-VoidHubLogo3 (Join-Path $dir "voidhub_logo_option_3.png")
Write-Host "All 3 VoidHub brand logos created successfully!"
