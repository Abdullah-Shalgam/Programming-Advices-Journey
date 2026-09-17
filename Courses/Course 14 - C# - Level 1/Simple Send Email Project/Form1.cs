using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Simple_Send_Email_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLTR_Click(object sender, EventArgs e)
        {
            txtSubject.RightToLeft = RightToLeft.No;
        }

        private void btnRTL_Click(object sender, EventArgs e)
        {
            txtSubject.RightToLeft = RightToLeft.Yes;
        }

        private void btnBold_Click(object sender, EventArgs e)
        {
            txtSubject.Font = new Font(txtSubject.Font, txtSubject.Font.Style ^ FontStyle.Bold);
        }

        private void btnUnderLine_Click(object sender, EventArgs e)
        {
            txtSubject.Font = new Font(txtSubject.Font, txtSubject.Font.Style ^ FontStyle.Underline);
        }

        private void btnItalic_Click(object sender, EventArgs e)
        {
            txtSubject.Font = new Font(txtSubject.Font, txtSubject.Font.Style ^ FontStyle.Italic);
        }

        private void btnLeft_Click(object sender, EventArgs e)
        {
            txtSubject.TextAlign = HorizontalAlignment.Left;
        }

        private void btnCenter_Click(object sender, EventArgs e)
        {
            txtSubject.TextAlign = HorizontalAlignment.Center;
        }

        private void btnRight_Click(object sender, EventArgs e)
        {
            txtSubject.TextAlign = HorizontalAlignment.Right;
        }
    }
}
