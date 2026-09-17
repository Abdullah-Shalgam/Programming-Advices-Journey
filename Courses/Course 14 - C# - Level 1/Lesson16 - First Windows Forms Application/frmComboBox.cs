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
    public partial class frmComboBox : Form
    {
        public frmComboBox()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            cb1.Items.Add("BoBo");
        }

        private void cb1_SelectedIndexChanged(object sender, EventArgs e)
        {
            MessageBox.Show(cb1.Text, "info");
        }

        private void frmComboBox_Load(object sender, EventArgs e)
        {
            cb1.SelectedIndex = 3;
        }
    }
}
