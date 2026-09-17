using System;
using System.Drawing;
using UnitAndBaseConverter.Core;

namespace UnitAndBaseConverter.UI.Theme
{
    public class ColorPalette
    {
        public Color WindowBackground { get; set; }
        public Color CardBackground { get; set; }
        public Color CardHover { get; set; }
        public Color InputBackground { get; set; }
        public Color BorderColor { get; set; }
        public Color BorderFocus { get; set; }
        public Color TextPrimary { get; set; }
        public Color TextSecondary { get; set; }
        public Color TextMuted { get; set; }
        public Color Accent { get; set; }
        public Color AccentHover { get; set; }
        public Color Danger { get; set; }
        public Color Success { get; set; }
        public Color BinaryBadge { get; set; }
        public Color OctalBadge { get; set; }
        public Color DecimalBadge { get; set; }
        public Color HexBadge { get; set; }
    }

    public static class ThemeManager
    {
        public static ThemeMode CurrentMode { get; private set; } = ThemeMode.Dark;
        public static ColorPalette Palette { get; private set; }

        public static event EventHandler ThemeChanged;

        static ThemeManager()
        {
            ApplyTheme(ThemeMode.Dark);
        }

        public static void ToggleTheme()
        {
            ApplyTheme(CurrentMode == ThemeMode.Dark ? ThemeMode.Light : ThemeMode.Dark);
        }

        public static void ApplyTheme(ThemeMode mode)
        {
            CurrentMode = mode;

            if (mode == ThemeMode.Dark)
            {
                Palette = new ColorPalette
                {
                    WindowBackground = Color.FromArgb(18, 19, 26),
                    CardBackground = Color.FromArgb(28, 30, 41),
                    CardHover = Color.FromArgb(36, 38, 52),
                    InputBackground = Color.FromArgb(23, 24, 33),
                    BorderColor = Color.FromArgb(48, 52, 70),
                    BorderFocus = Color.FromArgb(99, 102, 241),
                    TextPrimary = Color.FromArgb(243, 244, 246),
                    TextSecondary = Color.FromArgb(156, 163, 175),
                    TextMuted = Color.FromArgb(107, 114, 128),
                    Accent = Color.FromArgb(99, 102, 241),       // Indigo
                    AccentHover = Color.FromArgb(129, 140, 248),
                    Danger = Color.FromArgb(239, 68, 68),
                    Success = Color.FromArgb(16, 185, 129),
                    BinaryBadge = Color.FromArgb(6, 182, 212),    // Cyan
                    OctalBadge = Color.FromArgb(245, 158, 11),    // Amber
                    DecimalBadge = Color.FromArgb(59, 130, 246),  // Blue
                    HexBadge = Color.FromArgb(168, 85, 247)       // Purple
                };
            }
            else
            {
                Palette = new ColorPalette
                {
                    WindowBackground = Color.FromArgb(243, 244, 246),
                    CardBackground = Color.FromArgb(255, 255, 255),
                    CardHover = Color.FromArgb(249, 250, 251),
                    InputBackground = Color.FromArgb(249, 250, 251),
                    BorderColor = Color.FromArgb(229, 231, 235),
                    BorderFocus = Color.FromArgb(79, 70, 229),
                    TextPrimary = Color.FromArgb(17, 24, 39),
                    TextSecondary = Color.FromArgb(75, 85, 99),
                    TextMuted = Color.FromArgb(156, 163, 175),
                    Accent = Color.FromArgb(79, 70, 229),
                    AccentHover = Color.FromArgb(67, 56, 202),
                    Danger = Color.FromArgb(220, 38, 38),
                    Success = Color.FromArgb(5, 150, 105),
                    BinaryBadge = Color.FromArgb(14, 165, 233),
                    OctalBadge = Color.FromArgb(217, 119, 6),
                    DecimalBadge = Color.FromArgb(37, 99, 235),
                    HexBadge = Color.FromArgb(147, 51, 234)
                };
            }

            ThemeChanged?.Invoke(null, EventArgs.Empty);
        }
    }
}