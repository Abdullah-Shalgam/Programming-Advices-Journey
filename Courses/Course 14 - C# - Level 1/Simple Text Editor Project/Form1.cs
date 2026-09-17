using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace SimpleTextEditor
{
    public partial class Form1 : Form
    {
        private bool isDarkMode = false;

        public Form1()
        {
            InitializeComponent();
            ApplyLightTheme();
        }

        private void btnThemeToggle_Click(object sender, EventArgs e)
        {
            isDarkMode = !isDarkMode;
            if (isDarkMode)
            {
                ApplyDarkMode();
            }
            else
            {
                ApplyLightTheme();
            }
        }

        private void ApplyDarkMode()
        {
            // ألوان الوضع الداكن الاحترافي (Dark Charcoal & Off-White Text)
            Color darkBg = Color.FromArgb(30, 30, 30);
            Color darkMenuBg = Color.FromArgb(45, 45, 48);
            Color lightText = Color.FromArgb(241, 241, 241);

            this.BackColor = darkBg;
            
            // منطقة الكتابة
            richTextBox1.BackColor = darkBg;
            richTextBox1.ForeColor = lightText;

            // شريط القوائم
            menuStrip1.BackColor = darkMenuBg;
            menuStrip1.ForeColor = lightText;

            foreach (ToolStripMenuItem item in menuStrip1.Items)
            {
                item.ForeColor = lightText;
                SetMenuItemColors(item, darkMenuBg, lightText);
            }

            // زر التبديل
            btnThemeToggle.BackColor = Color.FromArgb(60, 60, 65);
            btnThemeToggle.ForeColor = Color.White;
            btnThemeToggle.Text = "☀️ الوضع الفاتح";
        }

        private void ApplyLightTheme()
        {
            Color lightBg = Color.White;
            Color lightMenuBg = Color.FromArgb(240, 240, 240);
            Color darkText = Color.Black;

            this.BackColor = lightBg;

            // منطقة الكتابة
            richTextBox1.BackColor = lightBg;
            richTextBox1.ForeColor = darkText;

            // شريط القوائم
            menuStrip1.BackColor = lightMenuBg;
            menuStrip1.ForeColor = darkText;

            foreach (ToolStripMenuItem item in menuStrip1.Items)
            {
                item.ForeColor = darkText;
                SetMenuItemColors(item, lightMenuBg, darkText);
            }

            // زر التبديل
            btnThemeToggle.BackColor = Color.FromArgb(224, 224, 224);
            btnThemeToggle.ForeColor = Color.Black;
            btnThemeToggle.Text = "🌙 الوضع الداكن";
        }

        private void SetMenuItemColors(ToolStripMenuItem item, Color bgColor, Color fgColor)
        {
            foreach (ToolStripItem subItem in item.DropDownItems)
            {
                subItem.BackColor = bgColor;
                subItem.ForeColor = fgColor;

                if (subItem is ToolStripMenuItem subMenu)
                {
                    SetMenuItemColors(subMenu, bgColor, fgColor);
                }
            }
        }

        // --- أحداث القوائم ---

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Text = File.ReadAllText(openFileDialog1.FileName);
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                File.WriteAllText(saveFileDialog1.FileName, richTextBox1.Text);
            }
        }

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void fontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fontDialog1.Font = richTextBox1.SelectionFont ?? richTextBox1.Font;
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                if (richTextBox1.SelectionLength > 0)
                    richTextBox1.SelectionFont = fontDialog1.Font;
                else
                    richTextBox1.Font = fontDialog1.Font;
            }
        }

        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fontDialog1.Color = richTextBox1.SelectionColor;
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                if (richTextBox1.SelectionLength > 0)
                    richTextBox1.SelectionColor = colorDialog1.Color;
                else
                    richTextBox1.ForeColor = colorDialog1.Color;
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("محرر نصوص بسيط مصمم للراحة أثناء الكتابة باستخدام الوضع الداكن.", "حول البرنامج", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void نسخtsm_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void قصtsm_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void لصقtsm_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void تظليلالنصtsm_Click(object sender, EventArgs e)
        {
            if (richTextBox1.SelectionLength > 0)
            {
                richTextBox1.SelectionBackColor = Color.Yellow;
            }
        }

        private void tsmتحويلإلىUPPERCASE_Click(object sender, EventArgs e)
        {
            if (richTextBox1.SelectionLength > 0)
            {
                richTextBox1.SelectedText = richTextBox1.SelectedText.ToUpper();
            }
        }
    }
}