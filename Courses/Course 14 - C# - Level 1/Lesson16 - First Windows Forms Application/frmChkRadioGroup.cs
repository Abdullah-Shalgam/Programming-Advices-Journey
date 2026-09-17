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
    public partial class frmChkRadioGroup : Form
    {
        public frmChkRadioGroup()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show($"The Value of Check Box is = {chkReceiveEmails.Checked}", "Check Box Value", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
           button1.Enabled = chkReceiveEmails.Checked;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string WhosTheCheckedOne = string.Empty;

            if (rbSmall.Checked) WhosTheCheckedOne = "1";
            else if (rbMedium.Checked) WhosTheCheckedOne = "2";
            else if (rbLarge.Checked) WhosTheCheckedOne = "3";
            else WhosTheCheckedOne = "None of thim is Checked";

            MessageBox.Show($"The Cheked Radio Button is = {WhosTheCheckedOne}", "Checked RadioButton", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void frmChkRadioGroup_Load(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            gbSize.Visible = false;
        }
    }
}
