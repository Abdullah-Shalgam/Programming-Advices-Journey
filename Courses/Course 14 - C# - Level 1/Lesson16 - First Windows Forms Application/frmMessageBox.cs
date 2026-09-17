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
    public partial class frmMessageBox : Form
    {
        public frmMessageBox()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hi This a Message.");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hi This a Message.", "This is a Title KoKo is the best");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are You sure?", "Confirm!", MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                MessageBox.Show("User Pressed Ok.",  "Done!");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are You sure?", "Confirm!", MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                MessageBox.Show("User Pressed Ok.", "Done!");
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {

            if (MessageBox.Show("Are You sure?", "Confirm!", MessageBoxButtons.OKCancel, MessageBoxIcon.Information, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                MessageBox.Show("User Pressed Ok.", "Done!");
            }
        }
    }
}
