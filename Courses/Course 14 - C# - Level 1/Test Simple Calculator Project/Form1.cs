using System;
using System.Drawing;
using System.Windows.Forms;

namespace Test_Simple_Calculator_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private bool TryGetInputs(out double num1, out double num2)
        {
            bool isNum1Valid = double.TryParse(Number1_TextBox.Text, out num1);
            bool isNum2Valid = double.TryParse(Number2_TextBox.Text, out num2);

            if (!isNum1Valid || !isNum2Valid)
            {
                MessageBox.Show("يرجى إدخال أرقام صحيحة في الخانات!", "خطأ في الإدخال", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return false;
            }
            return true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (TryGetInputs(out double n1, out double n2))
                Result_TextBox.Text = (n1 + n2).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (TryGetInputs(out double n1, out double n2))
                Result_TextBox.Text = (n1 - n2).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (TryGetInputs(out double n1, out double n2))
            {
                if (n2 == 0)
                {
                    MessageBox.Show("لا يمكن القسمة على صفر!", "خطأ حُسابي", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                Result_TextBox.Text = (n1 / n2).ToString();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (TryGetInputs(out double n1, out double n2))
                Result_TextBox.Text = (n1 * n2).ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Result_TextBox.Clear();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Number1_TextBox.Clear();
            Number2_TextBox.Clear();
            Result_TextBox.Clear();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }
    }
}