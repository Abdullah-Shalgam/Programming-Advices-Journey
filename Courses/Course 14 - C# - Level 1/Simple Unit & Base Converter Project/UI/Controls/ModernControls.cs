using System;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Text;
using System.Windows.Forms;
using UnitAndBaseConverter.Core;
using UnitAndBaseConverter.UI.Theme;

namespace UnitAndBaseConverter.UI.Controls
{
    public static class GdiHelper
    {
        public static GraphicsPath CreateRoundedRectangle(Rectangle bounds, int radius)
        {
            GraphicsPath path = new GraphicsPath();
            int diameter = radius * 2;
            Rectangle arc = new Rectangle(bounds.Location, new Size(diameter, diameter));

            if (radius == 0)
            {
                path.AddRectangle(bounds);
                return path;
            }

            // Top Left
            path.AddArc(arc, 180, 90);

            // Top Right
            arc.X = bounds.Right - diameter;
            path.AddArc(arc, 270, 90);

            // Bottom Right
            arc.Y = bounds.Bottom - diameter;
            path.AddArc(arc, 0, 90);

            // Bottom Left
            arc.X = bounds.Left;
            path.AddArc(arc, 90, 90);

            path.CloseFigure();
            return path;
        }
    }

    public class ModernCard : Panel
    {
        private int _borderRadius = 12;

        [Category("Appearance")]
        public int BorderRadius
        {
            get { return _borderRadius; }
            set { _borderRadius = value; Invalidate(); }
        }

        [Category("Appearance")]
        public bool DrawBorder { get; set; } = true;

        public ModernCard()
        {
            SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw |
                     ControlStyles.SupportsTransparentBackColor, true);
            BackColor = Color.Transparent;
            Padding = new Padding(14);
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            e.Graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;

            Rectangle bounds = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GdiHelper.CreateRoundedRectangle(bounds, _borderRadius))
            {
                using (SolidBrush brush = new SolidBrush(ThemeManager.Palette.CardBackground))
                {
                    e.Graphics.FillPath(brush, path);
                }

                if (DrawBorder)
                {
                    using (Pen pen = new Pen(ThemeManager.Palette.BorderColor, 1.2f))
                    {
                        e.Graphics.DrawPath(pen, path);
                    }
                }
            }
        }
    }

    public class ModernButton : Button
    {
        private bool _isHovered;
        private bool _isPressed;
        private int _borderRadius = 8;
        private ButtonStyle _buttonStyle = ButtonStyle.Primary;

        [Category("Appearance")]
        public ButtonStyle Style
        {
            get { return _buttonStyle; }
            set { _buttonStyle = value; Invalidate(); }
        }

        [Category("Appearance")]
        public int BorderRadius
        {
            get { return _borderRadius; }
            set { _borderRadius = value; Invalidate(); }
        }

        public ModernButton()
        {
            SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw |
                     ControlStyles.SupportsTransparentBackColor, true);
            Cursor = Cursors.Hand;
            Font = new Font("Segoe UI Semibold", 9.75f, FontStyle.Bold);
            Size = new Size(120, 38);
            BackColor = Color.Transparent;
        }

        protected override void OnMouseEnter(EventArgs e) { _isHovered = true; Invalidate(); base.OnMouseEnter(e); }
        protected override void OnMouseLeave(EventArgs e) { _isHovered = false; _isPressed = false; Invalidate(); base.OnMouseLeave(e); }
        protected override void OnMouseDown(MouseEventArgs mevent) { _isPressed = true; Invalidate(); base.OnMouseDown(mevent); }
        protected override void OnMouseUp(MouseEventArgs mevent) { _isPressed = false; Invalidate(); base.OnMouseUp(mevent); }

        protected override void OnPaint(PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            e.Graphics.TextRenderingHint = TextRenderingHint.ClearTypeGridFit;

            Rectangle bounds = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GdiHelper.CreateRoundedRectangle(bounds, _borderRadius))
            {
                Color bg, fg, border;

                switch (_buttonStyle)
                {
                    case ButtonStyle.Accent:
                    case ButtonStyle.Primary:
                        bg = _isPressed ? ControlPaint.Dark(ThemeManager.Palette.Accent, 0.1f) :
                             _isHovered ? ThemeManager.Palette.AccentHover : ThemeManager.Palette.Accent;
                        fg = Color.White;
                        border = bg;
                        break;
                    case ButtonStyle.Danger:
                        bg = _isHovered ? Color.FromArgb(220, 38, 38) : ThemeManager.Palette.Danger;
                        fg = Color.White;
                        border = bg;
                        break;
                    case ButtonStyle.Ghost:
                        bg = _isHovered ? ThemeManager.Palette.CardHover : Color.Transparent;
                        fg = ThemeManager.Palette.TextPrimary;
                        border = _isHovered ? ThemeManager.Palette.BorderColor : Color.Transparent;
                        break;
                    default: // Secondary
                        bg = _isHovered ? ThemeManager.Palette.CardHover : ThemeManager.Palette.InputBackground;
                        fg = ThemeManager.Palette.TextPrimary;
                        border = ThemeManager.Palette.BorderColor;
                        break;
                }

                using (SolidBrush brush = new SolidBrush(bg))
                {
                    e.Graphics.FillPath(brush, path);
                }
                using (Pen pen = new Pen(border, 1.2f))
                {
                    e.Graphics.DrawPath(pen, path);
                }

                TextFormatFlags flags = TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter | TextFormatFlags.SingleLine;
                TextRenderer.DrawText(e.Graphics, Text, Font, bounds, fg, flags);
            }
        }
    }

    public class ModernTextBox : Panel
    {
        private readonly TextBox _innerBox;
        private bool _isFocused;
        private bool _hasError;
        private string _placeholder = string.Empty;

        [Category("Appearance")]
        public string Placeholder
        {
            get { return _placeholder; }
            set { _placeholder = value; Invalidate(); }
        }

        [Category("Appearance")]
        public bool HasError
        {
            get { return _hasError; }
            set { _hasError = value; Invalidate(); }
        }

        public override string Text
        {
            get { return _innerBox.Text; }
            set { _innerBox.Text = value; }
        }

        public TextBox InnerBox { get { return _innerBox; } }

        public event EventHandler ValueChanged;

        public ModernTextBox()
        {
            SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw, true);

            Padding = new Padding(12, 10, 12, 10);
            Size = new Size(240, 44);

            _innerBox = new TextBox
            {
                BorderStyle = BorderStyle.None,
                Dock = DockStyle.Fill,
                Font = new Font("Segoe UI Semibold", 12F, FontStyle.Bold)
            };

            _innerBox.GotFocus += (s, e) => { _isFocused = true; Invalidate(); };
            _innerBox.LostFocus += (s, e) => { _isFocused = false; Invalidate(); };
            _innerBox.TextChanged += (s, e) => { ValueChanged?.Invoke(this, EventArgs.Empty); Invalidate(); };

            Controls.Add(_innerBox);
            UpdateColors();
            ThemeManager.ThemeChanged += (s, e) => UpdateColors();
        }

        public void UpdateColors()
        {
            BackColor = ThemeManager.Palette.InputBackground;
            _innerBox.BackColor = ThemeManager.Palette.InputBackground;
            _innerBox.ForeColor = ThemeManager.Palette.TextPrimary;
            Invalidate();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;

            Rectangle bounds = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GdiHelper.CreateRoundedRectangle(bounds, 8))
            {
                using (SolidBrush brush = new SolidBrush(ThemeManager.Palette.InputBackground))
                {
                    e.Graphics.FillPath(brush, path);
                }

                Color border = _hasError ? ThemeManager.Palette.Danger :
                               _isFocused ? ThemeManager.Palette.BorderFocus : ThemeManager.Palette.BorderColor;

                using (Pen pen = new Pen(border, _isFocused || _hasError ? 1.8f : 1.2f))
                {
                    e.Graphics.DrawPath(pen, path);
                }

                if (string.IsNullOrEmpty(_innerBox.Text) && !string.IsNullOrEmpty(_placeholder) && !_isFocused)
                {
                    using (Font font = new Font("Segoe UI", 10.5f, FontStyle.Italic))
                    {
                        TextRenderer.DrawText(e.Graphics, _placeholder, font, new Rectangle(14, 10, Width - 28, Height - 20),
                            ThemeManager.Palette.TextMuted, TextFormatFlags.Left | TextFormatFlags.VerticalCenter);
                    }
                }
            }
        }
    }

    public class BaseLivePreviewCard : UserControl
    {
        private readonly Label _lblBase;
        private readonly Label _lblValue;
        private readonly Button _btnCopy;
        private readonly NumBase _baseType;
        private Color _badgeColor;

        public event EventHandler<string> CopyRequested;

        public BaseLivePreviewCard(NumBase baseType, string title, Color badgeColor)
        {
            _baseType = baseType;
            _badgeColor = badgeColor;

            SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.AllPaintingInWmPaint | ControlStyles.UserPaint, true);
            Height = 62;
            Dock = DockStyle.Top;
            Padding = new Padding(8, 6, 8, 6);
            Margin = new Padding(0, 0, 0, 6);

            _lblBase = new Label
            {
                Text = title.ToUpperInvariant(),
                Font = new Font("Segoe UI Black", 8.5f, FontStyle.Bold),
                ForeColor = badgeColor,
                AutoSize = false,
                Size = new Size(60, 20),
                Location = new Point(14, 21),
                TextAlign = ContentAlignment.MiddleLeft
            };

            _lblValue = new Label
            {
                Text = "0",
                Font = new Font("Consolas", 11.5f, FontStyle.Bold),
                ForeColor = ThemeManager.Palette.TextPrimary,
                Location = new Point(80, 10),
                Size = new Size(Width - 145, 42),
                TextAlign = ContentAlignment.MiddleLeft,
                Anchor = AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Top
            };

            _btnCopy = new Button
            {
                Text = "Copy",
                Size = new Size(54, 28),
                Location = new Point(Width - 68, 17),
                Anchor = AnchorStyles.Right | AnchorStyles.Top,
                FlatStyle = FlatStyle.Flat,
                Cursor = Cursors.Hand,
                Font = new Font("Segoe UI", 8F, FontStyle.Bold)
            };
            _btnCopy.FlatAppearance.BorderSize = 0;
            _btnCopy.Click += (s, e) => CopyRequested?.Invoke(this, _lblValue.Text.Replace(" ", ""));

            Controls.Add(_lblBase);
            Controls.Add(_lblValue);
            Controls.Add(_btnCopy);

            ThemeManager.ThemeChanged += (s, e) => ApplyTheme();
            ApplyTheme();
        }

        public void SetValue(string val)
        {
            _lblValue.Text = string.IsNullOrEmpty(val) ? "0" : val;
        }

        public void SetBadgeColor(Color color)
        {
            _badgeColor = color;
            _lblBase.ForeColor = color;
            Invalidate();
        }

        private void ApplyTheme()
        {
            _lblValue.ForeColor = ThemeManager.Palette.TextPrimary;
            _btnCopy.BackColor = ThemeManager.Palette.CardHover;
            _btnCopy.ForeColor = ThemeManager.Palette.TextSecondary;
            Invalidate();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;

            Rectangle bounds = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GdiHelper.CreateRoundedRectangle(bounds, 8))
            {
                using (SolidBrush brush = new SolidBrush(ThemeManager.Palette.CardBackground))
                {
                    e.Graphics.FillPath(brush, path);
                }

                using (Pen pen = new Pen(ThemeManager.Palette.BorderColor, 1f))
                {
                    e.Graphics.DrawPath(pen, path);
                }

                using (SolidBrush pillBrush = new SolidBrush(_badgeColor))
                {
                    e.Graphics.FillRectangle(pillBrush, new Rectangle(0, 12, 4, Height - 24));
                }
            }
        }
    }

    public class SegmentedNavControl : Control
    {
        private string[] _tabs = new string[] { "Base Converter", "Unit Converter", "History Log" };
        private int _selectedIndex = 0;

        public event EventHandler SelectedIndexChanged;

        [Category("Behavior")]
        public int SelectedIndex
        {
            get { return _selectedIndex; }
            set
            {
                if (_selectedIndex != value && value >= 0 && value < _tabs.Length)
                {
                    _selectedIndex = value;
                    Invalidate();
                    SelectedIndexChanged?.Invoke(this, EventArgs.Empty);
                }
            }
        }

        public SegmentedNavControl()
        {
            SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw, true);
            Height = 44;
            Cursor = Cursors.Hand;
            Font = new Font("Segoe UI Semibold", 10F, FontStyle.Bold);
        }

        protected override void OnMouseClick(MouseEventArgs e)
        {
            base.OnMouseClick(e);
            int tabWidth = Width / _tabs.Length;
            int clicked = e.X / tabWidth;
            if (clicked >= 0 && clicked < _tabs.Length)
            {
                SelectedIndex = clicked;
            }
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            e.Graphics.TextRenderingHint = TextRenderingHint.ClearTypeGridFit;

            Rectangle bounds = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GdiHelper.CreateRoundedRectangle(bounds, 10))
            {
                using (SolidBrush bgBrush = new SolidBrush(ThemeManager.Palette.InputBackground))
                {
                    e.Graphics.FillPath(bgBrush, path);
                }

                int tabWidth = Width / _tabs.Length;

                for (int i = 0; i < _tabs.Length; i++)
                {
                    Rectangle tabRect = new Rectangle(i * tabWidth + 3, 3, tabWidth - 6, Height - 7);

                    if (i == _selectedIndex)
                    {
                        using (GraphicsPath activePath = GdiHelper.CreateRoundedRectangle(tabRect, 8))
                        {
                            using (SolidBrush activeBrush = new SolidBrush(ThemeManager.Palette.CardBackground))
                            {
                                e.Graphics.FillPath(activeBrush, activePath);
                            }
                            using (Pen activePen = new Pen(ThemeManager.Palette.BorderColor, 1.2f))
                            {
                                e.Graphics.DrawPath(activePen, activePath);
                            }
                        }

                        TextRenderer.DrawText(e.Graphics, _tabs[i], Font, tabRect,
                            ThemeManager.Palette.Accent, TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter);
                    }
                    else
                    {
                        TextRenderer.DrawText(e.Graphics, _tabs[i], Font, tabRect,
                            ThemeManager.Palette.TextSecondary, TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter);
                    }
                }

                using (Pen borderPen = new Pen(ThemeManager.Palette.BorderColor, 1f))
                {
                    e.Graphics.DrawPath(borderPen, path);
                }
            }
        }
    }

    public class ModernToastNotification : Control
    {
        private readonly Timer _timer;
        private int _opacity = 0;
        private bool _fadingOut = false;
        private string _message = string.Empty;

        public ModernToastNotification()
        {
            SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.OptimizedDoubleBuffer | ControlStyles.SupportsTransparentBackColor, true);

            Size = new Size(260, 42);
            Visible = false;
            BackColor = Color.Transparent;

            _timer = new Timer { Interval = 25 };
            _timer.Tick += (s, e) =>
            {
                if (!_fadingOut)
                {
                    _opacity += 35;
                    if (_opacity >= 255)
                    {
                        _opacity = 255;
                        _timer.Stop();
                        Timer stayTimer = new Timer { Interval = 1600 };
                        stayTimer.Tick += (st, ev) =>
                        {
                            stayTimer.Stop();
                            stayTimer.Dispose();
                            _fadingOut = true;
                            _timer.Start();
                        };
                        stayTimer.Start();
                    }
                }
                else
                {
                    _opacity -= 30;
                    if (_opacity <= 0)
                    {
                        _opacity = 0;
                        _timer.Stop();
                        Visible = false;
                    }
                }
                Invalidate();
            };
        }

        public void ShowMessage(string message, Form parent)
        {
            _message = message;
            _fadingOut = false;
            _opacity = 0;

            Location = new Point((parent.ClientSize.Width - Width) / 2, parent.ClientSize.Height - Height - 24);
            BringToFront();
            Visible = true;
            _timer.Start();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            if (_opacity <= 0) return;

            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            e.Graphics.TextRenderingHint = TextRenderingHint.ClearTypeGridFit;

            Rectangle bounds = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GdiHelper.CreateRoundedRectangle(bounds, 10))
            {
                using (SolidBrush brush = new SolidBrush(Color.FromArgb(_opacity, ThemeManager.Palette.Accent)))
                {
                    e.Graphics.FillPath(brush, path);
                }

                using (Font font = new Font("Segoe UI Semibold", 9.5F, FontStyle.Bold))
                {
                    TextRenderer.DrawText(e.Graphics, _message, font, bounds,
                        Color.FromArgb(_opacity, Color.White), TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter);
                }
            }
        }
    }
}