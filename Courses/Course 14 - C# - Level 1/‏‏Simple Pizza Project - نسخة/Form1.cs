using System;
using System.Drawing;
using System.Windows.Forms;

namespace Simple_Pizza_Project
{
    public partial class frmMain : Form
    {
        private PizzaOrder currentOrder = new PizzaOrder();

        public frmMain()
        {
            InitializeComponent();
            WireEvents();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            ResetForm();
        }

        private void WireEvents()
        {
            rbSmall.CheckedChanged += (s, e) => { if (rbSmall.Checked) { currentOrder.Size = PizzaSize.Small; SyncUI(); } };
            rbMedium.CheckedChanged += (s, e) => { if (rbMedium.Checked) { currentOrder.Size = PizzaSize.Medium; SyncUI(); } };
            rbLarge.CheckedChanged += (s, e) => { if (rbLarge.Checked) { currentOrder.Size = PizzaSize.Large; SyncUI(); } };

            rbThinCrust.CheckedChanged += (s, e) => { if (rbThinCrust.Checked) { currentOrder.Crust = CrustType.Thin; SyncUI(); } };
            rbThickCrust.CheckedChanged += (s, e) => { if (rbThickCrust.Checked) { currentOrder.Crust = CrustType.Thick; SyncUI(); } };

            rbEatIn.CheckedChanged += (s, e) => { if (rbEatIn.Checked) { currentOrder.Dining = DiningOption.EatIn; SyncUI(); } };
            rbTakeOut.CheckedChanged += (s, e) => { if (rbTakeOut.Checked) { currentOrder.Dining = DiningOption.TakeOut; SyncUI(); } };

            chkExtraChees.CheckedChanged += ToppingChanged;
            chkMushrooms.CheckedChanged += ToppingChanged;
            chkTomatoes.CheckedChanged += ToppingChanged;
            chkOnion.CheckedChanged += ToppingChanged;
            chkOlives.CheckedChanged += ToppingChanged;
            chkGreenPeppers.CheckedChanged += ToppingChanged;

            btnOrderPizza.Click += BtnOrderPizza_Click;
            btnReset.Click += BtnReset_Click;
        }

        private void ToppingChanged(object sender, EventArgs e)
        {
            Toppings toppings = Toppings.None;

            if (chkExtraChees.Checked) toppings |= Toppings.ExtraCheese;
            if (chkMushrooms.Checked) toppings |= Toppings.Mushrooms;
            if (chkTomatoes.Checked) toppings |= Toppings.Tomatoes;
            if (chkOnion.Checked) toppings |= Toppings.Onion;
            if (chkOlives.Checked) toppings |= Toppings.Olives;
            if (chkGreenPeppers.Checked) toppings |= Toppings.GreenPeppers;

            currentOrder.SelectedToppings = toppings;
            SyncUI();
        }

        private void SyncUI()
        {
            lblSize.Text = currentOrder.Size.ToString();
            lblCrust.Text = currentOrder.Crust == CrustType.Thin ? "Thin Crust 🍞" : "Thick Crust 🥖";
            lblWTE.Text = currentOrder.Dining == DiningOption.EatIn ? "Eat In 🍽️" : "Take Out 🥡";

            var toppings = currentOrder.GetToppingNames();
            lblToppings.Text = toppings.Count > 0 ? string.Join("\n", toppings) : "No Toppings Selected";

            lblTotalPrice.Text = $"${currentOrder.CalculateTotal():F2}";
        }

        private void BtnReset_Click(object sender, EventArgs e)
        {
            ResetForm();
        }

        private void ResetForm()
        {
            cardSize.Enabled = true;
            cardCrust.Enabled = true;
            cardToppings.Enabled = true;
            cardDining.Enabled = true;
            btnOrderPizza.Enabled = true;

            rbMedium.Checked = true;
            rbThinCrust.Checked = true;
            rbEatIn.Checked = true;

            chkExtraChees.Checked = false;
            chkMushrooms.Checked = false;
            chkTomatoes.Checked = false;
            chkOnion.Checked = false;
            chkOlives.Checked = false;
            chkGreenPeppers.Checked = false;

            currentOrder = new PizzaOrder();
            SyncUI();
        }

        private void BtnOrderPizza_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show(
                $"Confirm Order for ${currentOrder.CalculateTotal():F2}?",
                "Artisan Pizza Order Studio",
                MessageBoxButtons.YesNo,
                MessageBoxIcon.Question
            );

            if (result == DialogResult.Yes)
            {
                MessageBox.Show("Order Placed Successfully! 🍕 Your artisanal pizza is being prepared.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                cardSize.Enabled = false;
                cardCrust.Enabled = false;
                cardToppings.Enabled = false;
                cardDining.Enabled = false;
                btnOrderPizza.Enabled = false;
            }
        }
    }
}