using System;
using System.Drawing;
using System.Windows.Forms;

namespace SimpleCalculator
{
    public partial class Form1 : Form
    {
        private double firstNum = 0;
        private string currentOp = "";
        private bool isOpClicked = false;

        public Form1()
        {
            InitializeComponent();
            ApplyCustomColors();
        }

        private void ApplyCustomColors()
        {
            this.Text = "Calculator";
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.StartPosition = FormStartPosition.CenterScreen;
            this.BackColor = Color.FromArgb(245, 245, 245);

            Button[] allButtons = new Button[]
            {
                btnC, btnBackspace, btnMod, btnDivide,
                btn7, btn8, btn9, btnMultiply,
                btn4, btn5, btn6, btnSubtract,
                btn1, btn2, btn3, btnAdd,
                btnCopy, btn0, btnDot, btnEqual
            };

            foreach (Button btn in allButtons)
            {
                if (btn == null) continue;

                btn.FlatStyle = FlatStyle.Flat;
                btn.FlatAppearance.BorderSize = 1;
                btn.FlatAppearance.BorderColor = Color.LightGray;

                string txt = btn.Text;
                if (txt == "=")
                {
                    btn.BackColor = Color.FromArgb(0, 122, 204);
                    btn.ForeColor = Color.White;
                }
                else if (txt == "C" || txt == "⌫")
                {
                    btn.BackColor = Color.FromArgb(230, 100, 100);
                    btn.ForeColor = Color.White;
                }
                else if (txt == "÷" || txt == "×" || txt == "-" || txt == "+" || txt == "%")
                {
                    btn.BackColor = Color.FromArgb(220, 224, 230);
                    btn.ForeColor = Color.Black;
                }
                else
                {
                    btn.BackColor = Color.White;
                    btn.ForeColor = Color.Black;
                }
            }
        }

        // معالجة الضغط على أزرار الأرقام
        private void Number_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;

            if (lblResult.Text == "0" || isOpClicked)
            {
                lblResult.Text = "";
                isOpClicked = false;
            }

            lblResult.Text += btn.Text;
        }

        // معالجة النقطة العشرية
        private void btnDot_Click(object sender, EventArgs e)
        {
            if (isOpClicked)
            {
                lblResult.Text = "0.";
                isOpClicked = false;
                return;
            }

            if (!lblResult.Text.Contains("."))
            {
                lblResult.Text = string.IsNullOrEmpty(lblResult.Text) ? "0." : lblResult.Text + ".";
            }
        }

        // معالجة أزرار العمليات الحسابية (+, -, ×, ÷, %)
        private void Operator_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;

            if (double.TryParse(lblResult.Text, out double num))
            {
                firstNum = num;
                currentOp = btn.Text;
                isOpClicked = true;
            }
        }

        // زر المساواة =
        private void btnEqual_Click(object sender, EventArgs e)
        {
            if (double.TryParse(lblResult.Text, out double secondNum))
            {
                double result = 0;

                switch (currentOp)
                {
                    case "+": result = firstNum + secondNum; break;
                    case "-": result = firstNum - secondNum; break;
                    case "×": result = firstNum * secondNum; break;
                    case "÷":
                        if (secondNum != 0)
                            result = firstNum / secondNum;
                        else
                        {
                            MessageBox.Show("Cannot divide by zero. Please enter a number other than 0.", 
                "Calculation Error", 
                MessageBoxButtons.OK, 
                MessageBoxIcon.Error);

                            return;
                        }
                        break;
                    case "%":
                        if (secondNum != 0)
                            result = firstNum % secondNum;
                        else
                        {
                            MessageBox.Show("Cannot divide by zero. Please enter a number other than 0.",
                            "Calculation Error",
                            MessageBoxButtons.OK,
                            MessageBoxIcon.Error);

                            return;
                        }
                        break;
                    default:
                        return;
                }

                lblResult.Text = result.ToString();
                currentOp = "";
                isOpClicked = true;
            }
        }

        // زر المسح C
        private void btnC_Click(object sender, EventArgs e)
        {
            lblResult.Text = "0";
            firstNum = 0;
            currentOp = "";
            isOpClicked = false;
        }

        // زر التراجع ⌫
        private void btnBackspace_Click(object sender, EventArgs e)
        {
            if (lblResult.Text.Length > 1 && lblResult.Text != "Error")
            {
                lblResult.Text = lblResult.Text.Substring(0, lblResult.Text.Length - 1);
            }
            else
            {
                lblResult.Text = "0";
            }
        }

        // زر النسخ Copy
        private void btnCopy_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(lblResult.Text) && lblResult.Text != "Error")
            {
                Clipboard.SetText(lblResult.Text);
                MessageBox.Show("تم نسخ النتيجة إلى الحافظة!", "Copy", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}