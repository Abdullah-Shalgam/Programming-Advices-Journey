using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Simple_Date_Time_Excirsice
{
    public partial class Form1 : Form
    {
        DateTime UserDate;

        public Form1()
        {
            InitializeComponent();
            monthCalendar1.MinDate = DateTime.Now;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            UserDate = monthCalendar1.SelectionStart;
            UserDate = dateTimePicker1.Value;
            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (DateTime.Now == UserDate)
            {
                notifyIcon1.Icon = SystemIcons.Application;
                notifyIcon1.ShowBalloonTip(3000, "تذكير بموعد!", txtTaskName.Text, ToolTipIcon.Info);
            }
        }
    }
}
