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
    public partial class frmFileOpenDialog : Form
    {
        public frmFileOpenDialog()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.InitialDirectory = @"C:\Users\MY-NAME\Documents\";

            openFileDialog1.Title = "Open File Test";

            openFileDialog1.DefaultExt = "txt";

            openFileDialog1.Filter = "txt files (*.txt)|*.txt|png files (*.png)|*.png|All files (*.*)|*.*";

            openFileDialog1.FilterIndex = 3;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show(openFileDialog1.FileName, "Opened Sucecessfuly", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            openFileDialog1.InitialDirectory = @"C:\Users\MY-NAME\Documents\";

            openFileDialog1.Title = "Open File Test";

            openFileDialog1.DefaultExt = "txt";

            openFileDialog1.Filter = "txt files (*.txt)|*.txt|png files (*.png)|*.png|All files (*.*)|*.*";

            openFileDialog1.FilterIndex = 3;

            openFileDialog1.Multiselect = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                foreach(string File in openFileDialog1.FileNames)
                {
                    MessageBox.Show(File, "Opened Sucecessfuly", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }
    }
}
