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
    public partial class frmProgressBar : Form
    {
        public frmProgressBar()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            progressBar1.Maximum = 100;
            progressBar1.Minimum = 0;
            progressBar1.Value = 0;

            Timer timer = new Timer();
            timer.Interval = 1;

            timer.Tick += (s, ev) =>
            {
                if (progressBar1.Value < progressBar1.Maximum)
                {
                    progressBar1.Value++;
                    label1.Text = ((float)progressBar1.Value / progressBar1.Maximum) * 100 + "%";
                }
                else
                {
                    timer.Stop();
                    timer.Dispose();
                }
            };

            timer.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = "0%";
            progressBar1.Value = 0;
            button1.Enabled = true;
        }
    }
}