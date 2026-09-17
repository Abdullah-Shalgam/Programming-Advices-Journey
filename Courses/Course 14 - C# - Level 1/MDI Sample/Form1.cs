using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MDI_Sample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void findClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Find Client Is Here", "koko1");
        }

        private void addNewClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Add New Client Is Here", "koko2");
        }

        private void logoutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Logout is Here", "koko3");
        }

        private void showForm2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form frm = new Form2();
            frm.ShowDialog();
        }
    }
}
