using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lesson16___First_Windows_Forms_Application
{
    public partial class frmFileSaveDialog : Form
    {
        public frmFileSaveDialog()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.BackColor = colorDialog1.Color;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.ForeColor = colorDialog1.Color;
            }
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            fontDialog1.ShowApply = true;
            fontDialog1.ShowColor = true;
            fontDialog1.ShowEffects = true;
            fontDialog1.ShowHelp = true;

            fontDialog1.Font = textBox1.Font;

            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.Font = fontDialog1.Font;
                textBox1.ForeColor = fontDialog1.Color;
            }
        }

        private void fontDialog1_Apply_1(object sender, EventArgs e)
        {
            textBox1.Font = fontDialog1.Font;
            textBox1.ForeColor = fontDialog1.Color;
        }

        private void fontDialog1_HelpRequest_1(object sender, EventArgs e)
        {
            MessageBox.Show("Please Enter a [FontType:FontStyle:FontSize:FontColor] then press ok or apply button",
                "Help Info",
                MessageBoxButtons.OK,
                MessageBoxIcon.Information);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            saveFileDialog1.InitialDirectory = @"C:\Users\MY-NAME\Documents\";

            saveFileDialog1.Title = "Save Test";

            saveFileDialog1.DefaultExt = "txt";

            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|png files (*.png)|*.png|All files (*.*)|*.*";

            saveFileDialog1.FilterIndex = 1;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show(saveFileDialog1.FileName, "Save Sucecessfuly", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
