using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MaskedTextBox_Exercise
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        bool IsAllValide()
        {
            return (maskedTextBox1.MaskCompleted && maskedTextBox2.MaskFull && maskedTextBox3.MaskFull && maskedTextBox4.MaskCompleted);
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            if (maskedTextBox1.MaskCompleted)
            {
                maskedTextBox1.BackColor = Color.GreenYellow;
            }

            else
            {
                maskedTextBox1.BackColor = Color.Red;
            }

            if (maskedTextBox2.MaskFull)
            {
                maskedTextBox2.BackColor = Color.GreenYellow;
            }

            else
            {
                maskedTextBox2.BackColor = Color.Red;
            }

            if (maskedTextBox3.MaskFull)
            {
                maskedTextBox3.BackColor = Color.GreenYellow;
            }

            else
            {
                maskedTextBox3.BackColor = Color.Red;
            }

            if (maskedTextBox4.MaskCompleted)
            {
                maskedTextBox4.BackColor = Color.GreenYellow;
            }

            else
            {
                maskedTextBox4.BackColor = Color.Red;
            }

            if (IsAllValide())
            {
                MessageBox.Show("Please Press OK to Continue", "Done", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

            else
            {
                MessageBox.Show("Please Enter the information Correctly", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
