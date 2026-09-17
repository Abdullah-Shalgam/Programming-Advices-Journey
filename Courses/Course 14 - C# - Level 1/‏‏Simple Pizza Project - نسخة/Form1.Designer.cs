namespace Simple_Pizza_Project
{
    partial class frmMain
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.lblHeader = new System.Windows.Forms.Label();
            this.cardSize = new Simple_Pizza_Project.ModernCardPanel();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.cardCrust = new Simple_Pizza_Project.ModernCardPanel();
            this.rbThickCrust = new System.Windows.Forms.RadioButton();
            this.rbThinCrust = new System.Windows.Forms.RadioButton();
            this.cardDining = new Simple_Pizza_Project.ModernCardPanel();
            this.rbTakeOut = new System.Windows.Forms.RadioButton();
            this.rbEatIn = new System.Windows.Forms.RadioButton();
            this.cardToppings = new Simple_Pizza_Project.ModernCardPanel();
            this.chkGreenPeppers = new System.Windows.Forms.CheckBox();
            this.chkOlives = new System.Windows.Forms.CheckBox();
            this.chkOnion = new System.Windows.Forms.CheckBox();
            this.chkTomatoes = new System.Windows.Forms.CheckBox();
            this.chkMushrooms = new System.Windows.Forms.CheckBox();
            this.chkExtraChees = new System.Windows.Forms.CheckBox();
            this.cardSummary = new Simple_Pizza_Project.ModernCardPanel();
            this.lblTotalPrice = new System.Windows.Forms.Label();
            this.lblTotalHeader = new System.Windows.Forms.Label();
            this.lblWTE = new System.Windows.Forms.Label();
            this.lblWTEHeader = new System.Windows.Forms.Label();
            this.lblCrust = new System.Windows.Forms.Label();
            this.lblCrustHeader = new System.Windows.Forms.Label();
            this.lblToppings = new System.Windows.Forms.Label();
            this.lblToppingsHeader = new System.Windows.Forms.Label();
            this.lblSize = new System.Windows.Forms.Label();
            this.lblSizeHeader = new System.Windows.Forms.Label();
            this.btnOrderPizza = new Simple_Pizza_Project.ModernActionButton();
            this.btnReset = new Simple_Pizza_Project.ModernActionButton();

            this.cardSize.SuspendLayout();
            this.cardCrust.SuspendLayout();
            this.cardDining.SuspendLayout();
            this.cardToppings.SuspendLayout();
            this.cardSummary.SuspendLayout();
            this.SuspendLayout();

            // lblHeader
            this.lblHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblHeader.Font = new System.Drawing.Font("Segoe UI Variable Display", 22F, System.Drawing.FontStyle.Bold);
            this.lblHeader.ForeColor = System.Drawing.Color.FromArgb(255, 159, 28);
            this.lblHeader.Location = new System.Drawing.Point(0, 0);
            this.lblHeader.Name = "lblHeader";
            this.lblHeader.Size = new System.Drawing.Size(884, 70);
            this.lblHeader.TabIndex = 0;
            this.lblHeader.Text = "🍕 PIZZA ORDER STUDIO";
            this.lblHeader.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;

            // cardSize
            this.cardSize.Controls.Add(this.rbLarge);
            this.cardSize.Controls.Add(this.rbMedium);
            this.cardSize.Controls.Add(this.rbSmall);
            this.cardSize.Location = new System.Drawing.Point(24, 80);
            this.cardSize.Name = "cardSize";
            this.cardSize.Size = new System.Drawing.Size(220, 160);
            this.cardSize.TabIndex = 1;
            this.cardSize.Title = "1. Select Size";

            // rbSmall / rbMedium / rbLarge
            this.rbSmall.AutoSize = true;
            this.rbSmall.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbSmall.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbSmall.Location = new System.Drawing.Point(20, 48);
            this.rbSmall.Text = "🍕 Small ($20)";

            this.rbMedium.AutoSize = true;
            this.rbMedium.Checked = true;
            this.rbMedium.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbMedium.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbMedium.Location = new System.Drawing.Point(20, 80);
            this.rbMedium.Text = "🍕🍕 Medium ($30)";

            this.rbLarge.AutoSize = true;
            this.rbLarge.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbLarge.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbLarge.Location = new System.Drawing.Point(20, 112);
            this.rbLarge.Text = "🍕🍕🍕 Large ($40)";

            // cardCrust
            this.cardCrust.Controls.Add(this.rbThickCrust);
            this.cardCrust.Controls.Add(this.rbThinCrust);
            this.cardCrust.Location = new System.Drawing.Point(24, 255);
            this.cardCrust.Name = "cardCrust";
            this.cardCrust.Size = new System.Drawing.Size(220, 130);
            this.cardCrust.TabIndex = 2;
            this.cardCrust.Title = "2. Crust Type";

            this.rbThinCrust.AutoSize = true;
            this.rbThinCrust.Checked = true;
            this.rbThinCrust.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbThinCrust.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbThinCrust.Location = new System.Drawing.Point(20, 48);
            this.rbThinCrust.Text = "🍞 Thin Crust (+ $0)";

            this.rbThickCrust.AutoSize = true;
            this.rbThickCrust.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbThickCrust.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbThickCrust.Location = new System.Drawing.Point(20, 80);
            this.rbThickCrust.Text = "🥖 Thick Crust (+ $10)";

            // cardToppings
            this.cardToppings.Controls.Add(this.chkGreenPeppers);
            this.cardToppings.Controls.Add(this.chkOlives);
            this.cardToppings.Controls.Add(this.chkOnion);
            this.cardToppings.Controls.Add(this.chkTomatoes);
            this.cardToppings.Controls.Add(this.chkMushrooms);
            this.cardToppings.Controls.Add(this.chkExtraChees);
            this.cardToppings.Location = new System.Drawing.Point(260, 80);
            this.cardToppings.Name = "cardToppings";
            this.cardToppings.Size = new System.Drawing.Size(320, 160);
            this.cardToppings.TabIndex = 3;
            this.cardToppings.Title = "3. Select Toppings";

            this.chkExtraChees.AutoSize = true;
            this.chkExtraChees.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.chkExtraChees.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.chkExtraChees.Location = new System.Drawing.Point(18, 48);
            this.chkExtraChees.Text = "🧀 Extra Cheese ($5)";

            this.chkMushrooms.AutoSize = true;
            this.chkMushrooms.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.chkMushrooms.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.chkMushrooms.Location = new System.Drawing.Point(18, 80);
            this.chkMushrooms.Text = "🍄 Mushrooms ($3)";

            this.chkTomatoes.AutoSize = true;
            this.chkTomatoes.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.chkTomatoes.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.chkTomatoes.Location = new System.Drawing.Point(18, 112);
            this.chkTomatoes.Text = "🍅 Tomatoes ($3)";

            this.chkOnion.AutoSize = true;
            this.chkOnion.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.chkOnion.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.chkOnion.Location = new System.Drawing.Point(165, 48);
            this.chkOnion.Text = "🧅 Onion ($7)";

            this.chkOlives.AutoSize = true;
            this.chkOlives.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.chkOlives.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.chkOlives.Location = new System.Drawing.Point(165, 80);
            this.chkOlives.Text = "🫒 Olives ($4)";

            this.chkGreenPeppers.AutoSize = true;
            this.chkGreenPeppers.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.chkGreenPeppers.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.chkGreenPeppers.Location = new System.Drawing.Point(165, 112);
            this.chkGreenPeppers.Text = "🫑 Peppers ($6)";

            // cardDining
            this.cardDining.Controls.Add(this.rbTakeOut);
            this.cardDining.Controls.Add(this.rbEatIn);
            this.cardDining.Location = new System.Drawing.Point(260, 255);
            this.cardDining.Name = "cardDining";
            this.cardDining.Size = new System.Drawing.Size(320, 130);
            this.cardDining.TabIndex = 4;
            this.cardDining.Title = "4. Dining Option";

            this.rbEatIn.AutoSize = true;
            this.rbEatIn.Checked = true;
            this.rbEatIn.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbEatIn.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbEatIn.Location = new System.Drawing.Point(25, 58);
            this.rbEatIn.Text = "🍽️ Eat In";

            this.rbTakeOut.AutoSize = true;
            this.rbTakeOut.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbTakeOut.ForeColor = System.Drawing.Color.FromArgb(220, 220, 235);
            this.rbTakeOut.Location = new System.Drawing.Point(165, 58);
            this.rbTakeOut.Text = "🥡 Take Out";

            // cardSummary
            this.cardSummary.Controls.Add(this.lblTotalPrice);
            this.cardSummary.Controls.Add(this.lblTotalHeader);
            this.cardSummary.Controls.Add(this.lblWTE);
            this.cardSummary.Controls.Add(this.lblWTEHeader);
            this.cardSummary.Controls.Add(this.lblCrust);
            this.cardSummary.Controls.Add(this.lblCrustHeader);
            this.cardSummary.Controls.Add(this.lblToppings);
            this.cardSummary.Controls.Add(this.lblToppingsHeader);
            this.cardSummary.Controls.Add(this.lblSize);
            this.cardSummary.Controls.Add(this.lblSizeHeader);
            this.cardSummary.HeaderColor = System.Drawing.Color.FromArgb(230, 57, 70);
            this.cardSummary.Location = new System.Drawing.Point(600, 80);
            this.cardSummary.Name = "cardSummary";
            this.cardSummary.Size = new System.Drawing.Size(260, 365);
            this.cardSummary.TabIndex = 5;
            this.cardSummary.Title = "🧾 Order Summary";

            // Summary Labels
            this.lblSizeHeader.Text = "Size:";
            this.lblSizeHeader.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.lblSizeHeader.ForeColor = System.Drawing.Color.FromArgb(140, 145, 165);
            this.lblSizeHeader.Location = new System.Drawing.Point(16, 45);

            this.lblSize.Font = new System.Drawing.Font("Segoe UI Semibold", 9.5F, System.Drawing.FontStyle.Bold);
            this.lblSize.ForeColor = System.Drawing.Color.White;
            this.lblSize.Location = new System.Drawing.Point(100, 45);

            this.lblCrustHeader.Text = "Crust:";
            this.lblCrustHeader.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.lblCrustHeader.ForeColor = System.Drawing.Color.FromArgb(140, 145, 165);
            this.lblCrustHeader.Location = new System.Drawing.Point(16, 75);

            this.lblCrust.Font = new System.Drawing.Font("Segoe UI Semibold", 9.5F, System.Drawing.FontStyle.Bold);
            this.lblCrust.ForeColor = System.Drawing.Color.White;
            this.lblCrust.Location = new System.Drawing.Point(100, 75);

            this.lblWTEHeader.Text = "Dining:";
            this.lblWTEHeader.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.lblWTEHeader.ForeColor = System.Drawing.Color.FromArgb(140, 145, 165);
            this.lblWTEHeader.Location = new System.Drawing.Point(16, 105);

            this.lblWTE.Font = new System.Drawing.Font("Segoe UI Semibold", 9.5F, System.Drawing.FontStyle.Bold);
            this.lblWTE.ForeColor = System.Drawing.Color.White;
            this.lblWTE.Location = new System.Drawing.Point(100, 105);

            this.lblToppingsHeader.Text = "Toppings:";
            this.lblToppingsHeader.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.lblToppingsHeader.ForeColor = System.Drawing.Color.FromArgb(140, 145, 165);
            this.lblToppingsHeader.Location = new System.Drawing.Point(16, 135);

            this.lblToppings.Font = new System.Drawing.Font("Segoe UI", 8.5F);
            this.lblToppings.ForeColor = System.Drawing.Color.FromArgb(200, 205, 220);
            this.lblToppings.Location = new System.Drawing.Point(16, 155);
            this.lblToppings.Size = new System.Drawing.Size(225, 90);

            this.lblTotalHeader.Text = "TOTAL AMOUNT";
            this.lblTotalHeader.Font = new System.Drawing.Font("Segoe UI", 8.5F, System.Drawing.FontStyle.Bold);
            this.lblTotalHeader.ForeColor = System.Drawing.Color.FromArgb(140, 145, 165);
            this.lblTotalHeader.Location = new System.Drawing.Point(16, 260);

            this.lblTotalPrice.Font = new System.Drawing.Font("Segoe UI Variable Display", 28F, System.Drawing.FontStyle.Bold);
            this.lblTotalPrice.ForeColor = System.Drawing.Color.FromArgb(255, 159, 28);
            this.lblTotalPrice.Location = new System.Drawing.Point(12, 280);
            this.lblTotalPrice.Size = new System.Drawing.Size(235, 60);
            this.lblTotalPrice.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;

            // Action Buttons
            this.btnOrderPizza.Location = new System.Drawing.Point(260, 402);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.NormalColor = System.Drawing.Color.FromArgb(46, 196, 182); // Vibrant Teal
            this.btnOrderPizza.HoverColor = System.Drawing.Color.FromArgb(36, 166, 154);
            this.btnOrderPizza.Size = new System.Drawing.Size(155, 42);
            this.btnOrderPizza.TabIndex = 6;
            this.btnOrderPizza.Text = "🛒 Place Order";

            this.btnReset.Location = new System.Drawing.Point(425, 402);
            this.btnReset.Name = "btnReset";
            this.btnReset.NormalColor = System.Drawing.Color.FromArgb(230, 57, 70); // Warm Crimson
            this.btnReset.HoverColor = System.Drawing.Color.FromArgb(190, 40, 55);
            this.btnReset.Size = new System.Drawing.Size(155, 42);
            this.btnReset.TabIndex = 7;
            this.btnReset.Text = "🔄 Reset Form";

            // frmMain
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(18, 18, 22); // Deep Charcoal
            this.ClientSize = new System.Drawing.Size(884, 470);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.cardSummary);
            this.Controls.Add(this.cardDining);
            this.Controls.Add(this.cardToppings);
            this.Controls.Add(this.cardCrust);
            this.Controls.Add(this.cardSize);
            this.Controls.Add(this.lblHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Artisan Pizza Order Studio";
            this.Load += new System.EventHandler(this.frmMain_Load);

            this.cardSize.ResumeLayout(false);
            this.cardSize.PerformLayout();
            this.cardCrust.ResumeLayout(false);
            this.cardCrust.PerformLayout();
            this.cardDining.ResumeLayout(false);
            this.cardDining.PerformLayout();
            this.cardToppings.ResumeLayout(false);
            this.cardToppings.PerformLayout();
            this.cardSummary.ResumeLayout(false);
            this.cardSummary.PerformLayout();
            this.ResumeLayout(false);
        }

        #endregion

        private System.Windows.Forms.Label lblHeader;
        private ModernCardPanel cardSize;
        private ModernCardPanel cardCrust;
        private ModernCardPanel cardToppings;
        private ModernCardPanel cardDining;
        private ModernCardPanel cardSummary;

        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbMedium;

        private System.Windows.Forms.RadioButton rbThickCrust;
        private System.Windows.Forms.RadioButton rbThinCrust;

        private System.Windows.Forms.RadioButton rbTakeOut;
        private System.Windows.Forms.RadioButton rbEatIn;

        private System.Windows.Forms.CheckBox chkGreenPeppers;
        private System.Windows.Forms.CheckBox chkOlives;
        private System.Windows.Forms.CheckBox chkOnion;
        private System.Windows.Forms.CheckBox chkTomatoes;
        private System.Windows.Forms.CheckBox chkMushrooms;
        private System.Windows.Forms.CheckBox chkExtraChees;

        private ModernActionButton btnOrderPizza;
        private ModernActionButton btnReset;

        private System.Windows.Forms.Label lblSizeHeader;
        private System.Windows.Forms.Label lblSize;
        private System.Windows.Forms.Label lblCrustHeader;
        private System.Windows.Forms.Label lblCrust;
        private System.Windows.Forms.Label lblWTEHeader;
        private System.Windows.Forms.Label lblWTE;
        private System.Windows.Forms.Label lblToppingsHeader;
        private System.Windows.Forms.Label lblToppings;
        private System.Windows.Forms.Label lblTotalHeader;
        private System.Windows.Forms.Label lblTotalPrice;
    }
}