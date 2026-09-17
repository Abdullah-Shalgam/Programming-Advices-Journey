using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace Simple_Pizza_Project
{
    public class ModernCardPanel : Panel
    {
        public string Title { get; set; } = string.Empty;
        public Color HeaderColor { get; set; } = Color.FromArgb(255, 159, 28); // Gourmet Amber
        public Color CardBackColor { get; set; } = Color.FromArgb(28, 30, 38);
        public Color BorderColor { get; set; } = Color.FromArgb(45, 49, 66);
        public int BorderRadius { get; set; } = 12;

        public ModernCardPanel()
        {
            DoubleBuffered = true;
            Padding = new Padding(16, 42, 16, 16);
            BackColor = Color.Transparent;
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;

            Rectangle rect = new Rectangle(0, 0, Width - 1, Height - 1);
            using (GraphicsPath path = GetRoundedPath(rect, BorderRadius))
            {
                using (SolidBrush bgBrush = new SolidBrush(CardBackColor))
                {
                    e.Graphics.FillPath(bgBrush, path);
                }
                using (Pen borderPen = new Pen(BorderColor, 1.5f))
                {
                    e.Graphics.DrawPath(borderPen, path);
                }
            }

            if (!string.IsNullOrEmpty(Title))
            {
                using (Font font = new Font("Segoe UI Semibold", 10.5f, FontStyle.Bold))
                using (SolidBrush brush = new SolidBrush(HeaderColor))
                {
                    e.Graphics.DrawString(Title.ToUpper(), font, brush, new PointF(16, 14));
                }
            }
        }

        private GraphicsPath GetRoundedPath(Rectangle rect, int radius)
        {
            GraphicsPath path = new GraphicsPath();
            int diameter = radius * 2;
            path.AddArc(rect.X, rect.Y, diameter, diameter, 180, 90);
            path.AddArc(rect.Right - diameter, rect.Y, diameter, diameter, 270, 90);
            path.AddArc(rect.Right - diameter, rect.Bottom - diameter, diameter, diameter, 0, 90);
            path.AddArc(rect.X, rect.Bottom - diameter, diameter, diameter, 90, 90);
            path.CloseFigure();
            return path;
        }
    }

    public class ModernActionButton : Button
    {
        public Color NormalColor { get; set; } = Color.FromArgb(230, 57, 70);
        public Color HoverColor { get; set; } = Color.FromArgb(200, 40, 55);
        public Color DisabledColor { get; set; } = Color.FromArgb(60, 64, 75);
        public int BorderRadius { get; set; } = 8;

        private bool isHovered = false;

        public ModernActionButton()
        {
            DoubleBuffered = true;
            FlatStyle = FlatStyle.Flat;
            FlatAppearance.BorderSize = 0;
            ForeColor = Color.White;
            Font = new Font("Segoe UI Semibold", 10.5f, FontStyle.Bold);
            Cursor = Cursors.Hand;
        }

        protected override void OnMouseEnter(EventArgs e)
        {
            base.OnMouseEnter(e);
            isHovered = true;
            Invalidate();
        }

        protected override void OnMouseLeave(EventArgs e)
        {
            base.OnMouseLeave(e);
            isHovered = false;
            Invalidate();
        }

        protected override void OnPaint(PaintEventArgs pevent)
        {
            pevent.Graphics.SmoothingMode = SmoothingMode.AntiAlias;

            Rectangle rect = new Rectangle(0, 0, Width - 1, Height - 1);
            Color fill = Enabled ? (isHovered ? HoverColor : NormalColor) : DisabledColor;

            using (GraphicsPath path = GetRoundedPath(rect, BorderRadius))
            {
                using (SolidBrush brush = new SolidBrush(fill))
                {
                    pevent.Graphics.FillPath(brush, path);
                }

                TextRenderer.DrawText(
                    pevent.Graphics,
                    Text,
                    Font,
                    rect,
                    Enabled ? ForeColor : Color.FromArgb(140, 140, 150),
                    TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter
                );
            }
        }

        private GraphicsPath GetRoundedPath(Rectangle rect, int radius)
        {
            GraphicsPath path = new GraphicsPath();
            int diameter = radius * 2;
            path.AddArc(rect.X, rect.Y, diameter, diameter, 180, 90);
            path.AddArc(rect.Right - diameter, rect.Y, diameter, diameter, 270, 90);
            path.AddArc(rect.Right - diameter, rect.Bottom - diameter, diameter, diameter, 0, 90);
            path.AddArc(rect.X, rect.Bottom - diameter, diameter, diameter, 90, 90);
            path.CloseFigure();
            return path;
        }
    }
}