using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Draw_Lesson
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            // تفعيل تنعيم الحواف لتبدو الخطوط والنجمة باحترافية وبدون زوايا حادة مشوهة
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

            Color Red = Color.FromArgb(255, 255, 0, 0);

            // القلم المستخدم لرسم حدود المربع والنجمة
            Pen Pen = new Pen(Red);
            Pen.Width = 5; // قمت بتقليل السمك قليلاً من 16 ليناسب تفاصيل النجمة، يمكنك زيادته حسب رغبتك

            Pen.StartCap = System.Drawing.Drawing2D.LineCap.Triangle;
            Pen.EndCap = System.Drawing.Drawing2D.LineCap.Triangle;

            // 1. تحديد أبعاد وموقع المربع (الموقع: 100, 100 والحجم: 300×300 بكسل)
            int x = 100;
            int y = 100;
            int size = 300;

            // رسم المربع باللون الأحمر
            e.Graphics.DrawRectangle(Pen, x, y, size, size);

            // 2. حساب نقاط النجمة الخماسية لتقع داخل المربع تماماً بنسب مئوية متناسقة
            PointF[] starPoints = new PointF[]
            {
                new PointF(x + size * 0.50f, y + size * 0.10f), // الرأس العلوي
                new PointF(x + size * 0.61f, y + size * 0.40f),
                new PointF(x + size * 0.90f, y + size * 0.40f), // الرأس الأيمن العلوي
                new PointF(x + size * 0.66f, y + size * 0.58f),
                new PointF(x + size * 0.75f, y + size * 0.88f), // الرأس الأيمن السفلي
                new PointF(x + size * 0.50f, y + size * 0.70f), // الزاوية الداخلية السفلية
                new PointF(x + size * 0.25f, y + size * 0.88f), // الرأس الأيسر السفلي
                new PointF(x + size * 0.34f, y + size * 0.58f),
                new PointF(x + size * 0.10f, y + size * 0.40f), // الرأس الأيسر العلوي
                new PointF(x + size * 0.39f, y + size * 0.40f)
            };

            // 3. رسم حدود النجمة باللون الأحمر
            e.Graphics.DrawPolygon(Pen, starPoints);

            // اختياري: إذا كنت تريد تعبئة النجمة باللون الأحمر من الداخل أيضاً، احذف التعليق عن السطر التالي:
            // e.Graphics.FillPolygon(new SolidBrush(Red), starPoints);

            // تنظيف الذاكرة
            Pen.Dispose();
        }

    }
}
