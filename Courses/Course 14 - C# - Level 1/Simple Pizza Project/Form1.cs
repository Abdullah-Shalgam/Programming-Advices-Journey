using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Simple_Pizza_Project
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        int GetSelectedSizePrice()
        {
            if (rbSmall.Checked) { return Convert.ToInt32(rbSmall.Tag); }
            if (rbMedium.Checked) { return Convert.ToInt32(rbMedium.Tag); }
            else { return Convert.ToInt32(rbLarge.Tag); }
        }

        int CalculateToppingsPrice()
        {
            int Price = 0;

            if (chkExtraChees.Checked) { Price += Convert.ToInt32(chkExtraChees.Tag); }
            if (chkMushrooms.Checked) { Price += Convert.ToInt32(chkMushrooms.Tag); }
            if (chkTomatoes.Checked) { Price += Convert.ToInt32(chkTomatoes.Tag); }
            if (chkOnion.Checked) { Price += Convert.ToInt32(chkOnion.Tag); }
            if (chkOlives.Checked) { Price += Convert.ToInt32(chkOlives.Tag); }
            if (chkGreenPeppers.Checked) { Price += Convert.ToInt32(chkGreenPeppers.Tag); }

            return Price;
        }

        int GetSelectedCrustPrice()
        {
            if (rbThinCrust.Checked) {  return Convert.ToInt32(rbThinCrust.Tag); }
            else { return Convert.ToInt32(rbThickCrust.Tag); }
        }

        int CalculatTotalPrice()
        {
            return (GetSelectedSizePrice() + CalculateToppingsPrice() + GetSelectedCrustPrice()) * (int)nudPizzaAmount.Value;
        }

        void UpdateTotalPrice()
        {
            lblTotalPrice.Text = "$" + CalculatTotalPrice().ToString();
        }

        void UpdateToppings()
        {
            UpdateTotalPrice();

            string toppings = "";

            if (chkExtraChees.Checked) { toppings += chkExtraChees.Text + ", "; }
            if (chkMushrooms.Checked) { toppings += chkMushrooms.Text + ", "; }
            if (chkTomatoes.Checked) { toppings += chkTomatoes.Text + ", "; }
            if (chkOnion.Checked) { toppings += chkOnion.Text + ", "; }
            if (chkOlives.Checked) { toppings += chkOlives.Text + ", "; }
            if (chkGreenPeppers.Checked) { toppings += chkGreenPeppers.Text + ", "; }

            if (!string.IsNullOrEmpty(toppings))
            {
                lblToppings.Text = toppings.TrimEnd(',', ' ');
            }
            else
            {
                lblToppings.Text = "No Toppings";
            }
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked) { lblSize.Text = rbSmall.Text; return; }
            if (rbMedium.Checked) { lblSize.Text = rbMedium.Text; return; }
            if (rbLarge.Checked) { lblSize.Text = rbLarge.Text; return; }
        }

        void UpdateCrust()
        {
            UpdateTotalPrice();

            if (rbThinCrust.Checked) { lblCrust.Text = rbThinCrust.Text; return; }
            if (rbThickCrust.Checked) { lblCrust.Text = rbThickCrust.Text; return; }
        }

        void UpdateWTE()
        {
            if (rbEatIn.Checked) { lblWTE.Text = rbEatIn.Text; return; }
            if (rbTakeOut.Checked) { lblWTE.Text = rbTakeOut.Text; return; }
        }

        void UpdateOrderSummary()
        {
            UpdateSize();
            UpdateToppings();
            UpdateCrust();
            UpdateWTE();
        }

        void ChangeAllGB_EnablePropirty(bool Value)
        {
            gbSize.Enabled = Value;
            gbCrust.Enabled = Value;
            gbToppings.Enabled = Value;
            gbWTE.Enabled = Value;
        }

        void ResetForm()
        {
            ChangeAllGB_EnablePropirty(true);
            btnOrderPizza.Enabled = true;

            rbMedium.Checked = true;
            rbThinCrust.Checked = true;
            rbEatIn.Checked = true;

            foreach (Control control in gbToppings.Controls)
            {
                if (control is CheckBox cb) cb.Checked = false;
            }
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbThickCrust_CheckedChanged_1(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWTE();
        }

        private void rbTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWTE();
        }

        private void chkExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void chkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            ResetForm();
        }


        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                ChangeAllGB_EnablePropirty(false);
                btnOrderPizza.Enabled = false;
            }
        }

        private void nudPizzaAmount_ValueChanged(object sender, EventArgs e)
        {
            UpdateTotalPrice();
        }
    }
}