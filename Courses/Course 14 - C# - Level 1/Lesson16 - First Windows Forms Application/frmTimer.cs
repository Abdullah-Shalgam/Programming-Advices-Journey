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
    public partial class frmTimer : Form
    {
        int Counter = 0;
        int Counter2 = 0;

        public frmTimer()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Counter++;
            label1.Text = Counter2.ToString("D2") + ":" + Counter.ToString("D2");

            if (Counter == 60)
            {
                Counter2++;
                Counter = 0;
            }
        
        }
    }
}
