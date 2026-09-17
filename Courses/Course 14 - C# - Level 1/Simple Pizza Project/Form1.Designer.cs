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
            this.label1 = new System.Windows.Forms.Label();
            this.gbSize = new System.Windows.Forms.GroupBox();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.gbCrust = new System.Windows.Forms.GroupBox();
            this.rbThickCrust = new System.Windows.Forms.RadioButton();
            this.rbThinCrust = new System.Windows.Forms.RadioButton();
            this.gbWTE = new System.Windows.Forms.GroupBox();
            this.rbEatIn = new System.Windows.Forms.RadioButton();
            this.rbTakeOut = new System.Windows.Forms.RadioButton();
            this.gbToppings = new System.Windows.Forms.GroupBox();
            this.chkGreenPeppers = new System.Windows.Forms.CheckBox();
            this.chkExtraChees = new System.Windows.Forms.CheckBox();
            this.chkOlives = new System.Windows.Forms.CheckBox();
            this.chkMushrooms = new System.Windows.Forms.CheckBox();
            this.chkTomatoes = new System.Windows.Forms.CheckBox();
            this.chkOnion = new System.Windows.Forms.CheckBox();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.gbOrderSummary = new System.Windows.Forms.GroupBox();
            this.lblTotalPrice = new System.Windows.Forms.Label();
            this.Lable5 = new System.Windows.Forms.Label();
            this.lblWTE = new System.Windows.Forms.Label();
            this.Lable4 = new System.Windows.Forms.Label();
            this.lblCrust = new System.Windows.Forms.Label();
            this.Lable3 = new System.Windows.Forms.Label();
            this.lblToppings = new System.Windows.Forms.Label();
            this.Lable2 = new System.Windows.Forms.Label();
            this.lblSize = new System.Windows.Forms.Label();
            this.Lable1 = new System.Windows.Forms.Label();
            this.nudPizzaAmount = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.gbSize.SuspendLayout();
            this.gbCrust.SuspendLayout();
            this.gbWTE.SuspendLayout();
            this.gbToppings.SuspendLayout();
            this.gbOrderSummary.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPizzaAmount)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Dock = System.Windows.Forms.DockStyle.Top;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 28F, System.Drawing.FontStyle.Bold);
            this.label1.ForeColor = System.Drawing.Color.OrangeRed;
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(840, 80);
            this.label1.TabIndex = 0;
            this.label1.Text = "🍕 MAKE YOUR PIZZA 🍕";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // gbSize
            // 
            this.gbSize.Controls.Add(this.rbLarge);
            this.gbSize.Controls.Add(this.rbSmall);
            this.gbSize.Controls.Add(this.rbMedium);
            this.gbSize.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.gbSize.ForeColor = System.Drawing.Color.DarkOrange;
            this.gbSize.Location = new System.Drawing.Point(30, 95);
            this.gbSize.Name = "gbSize";
            this.gbSize.Size = new System.Drawing.Size(180, 150);
            this.gbSize.TabIndex = 1;
            this.gbSize.TabStop = false;
            this.gbSize.Text = "Size";
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbLarge.ForeColor = System.Drawing.Color.White;
            this.rbLarge.Location = new System.Drawing.Point(15, 105);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(61, 23);
            this.rbLarge.TabIndex = 11;
            this.rbLarge.TabStop = true;
            this.rbLarge.Tag = "40";
            this.rbLarge.Text = "Large";
            this.rbLarge.UseVisualStyleBackColor = true;
            this.rbLarge.CheckedChanged += new System.EventHandler(this.rbLarge_CheckedChanged);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbSmall.ForeColor = System.Drawing.Color.White;
            this.rbSmall.Location = new System.Drawing.Point(15, 35);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(59, 23);
            this.rbSmall.TabIndex = 9;
            this.rbSmall.TabStop = true;
            this.rbSmall.Tag = "20";
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            this.rbSmall.CheckedChanged += new System.EventHandler(this.rbSmall_CheckedChanged);
            // 
            // rbMedium
            // 
            this.rbMedium.AutoSize = true;
            this.rbMedium.Checked = true;
            this.rbMedium.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbMedium.ForeColor = System.Drawing.Color.White;
            this.rbMedium.Location = new System.Drawing.Point(15, 70);
            this.rbMedium.Name = "rbMedium";
            this.rbMedium.Size = new System.Drawing.Size(78, 23);
            this.rbMedium.TabIndex = 10;
            this.rbMedium.TabStop = true;
            this.rbMedium.Tag = "30";
            this.rbMedium.Text = "Medium";
            this.rbMedium.UseVisualStyleBackColor = true;
            this.rbMedium.CheckedChanged += new System.EventHandler(this.rbMedium_CheckedChanged);
            // 
            // gbCrust
            // 
            this.gbCrust.Controls.Add(this.rbThickCrust);
            this.gbCrust.Controls.Add(this.rbThinCrust);
            this.gbCrust.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.gbCrust.ForeColor = System.Drawing.Color.DarkOrange;
            this.gbCrust.Location = new System.Drawing.Point(30, 260);
            this.gbCrust.Name = "gbCrust";
            this.gbCrust.Size = new System.Drawing.Size(180, 110);
            this.gbCrust.TabIndex = 2;
            this.gbCrust.TabStop = false;
            this.gbCrust.Text = "Crust Type";
            // 
            // rbThickCrust
            // 
            this.rbThickCrust.AutoSize = true;
            this.rbThickCrust.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbThickCrust.ForeColor = System.Drawing.Color.White;
            this.rbThickCrust.Location = new System.Drawing.Point(15, 68);
            this.rbThickCrust.Name = "rbThickCrust";
            this.rbThickCrust.Size = new System.Drawing.Size(95, 23);
            this.rbThickCrust.TabIndex = 12;
            this.rbThickCrust.TabStop = true;
            this.rbThickCrust.Tag = "10";
            this.rbThickCrust.Text = "Thick Crust";
            this.rbThickCrust.UseVisualStyleBackColor = true;
            this.rbThickCrust.CheckedChanged += new System.EventHandler(this.rbThickCrust_CheckedChanged_1);
            // 
            // rbThinCrust
            // 
            this.rbThinCrust.AutoSize = true;
            this.rbThinCrust.Checked = true;
            this.rbThinCrust.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbThinCrust.ForeColor = System.Drawing.Color.White;
            this.rbThinCrust.Location = new System.Drawing.Point(15, 33);
            this.rbThinCrust.Name = "rbThinCrust";
            this.rbThinCrust.Size = new System.Drawing.Size(90, 23);
            this.rbThinCrust.TabIndex = 11;
            this.rbThinCrust.TabStop = true;
            this.rbThinCrust.Tag = "0";
            this.rbThinCrust.Text = "Thin Crust";
            this.rbThinCrust.UseVisualStyleBackColor = true;
            this.rbThinCrust.CheckedChanged += new System.EventHandler(this.rbThinCrust_CheckedChanged);
            // 
            // gbWTE
            // 
            this.gbWTE.Controls.Add(this.rbEatIn);
            this.gbWTE.Controls.Add(this.rbTakeOut);
            this.gbWTE.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.gbWTE.ForeColor = System.Drawing.Color.DarkOrange;
            this.gbWTE.Location = new System.Drawing.Point(235, 260);
            this.gbWTE.Name = "gbWTE";
            this.gbWTE.Size = new System.Drawing.Size(275, 110);
            this.gbWTE.TabIndex = 2;
            this.gbWTE.TabStop = false;
            this.gbWTE.Text = "Where To Eat";
            // 
            // rbEatIn
            // 
            this.rbEatIn.AutoSize = true;
            this.rbEatIn.Checked = true;
            this.rbEatIn.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbEatIn.ForeColor = System.Drawing.Color.White;
            this.rbEatIn.Location = new System.Drawing.Point(20, 48);
            this.rbEatIn.Name = "rbEatIn";
            this.rbEatIn.Size = new System.Drawing.Size(62, 23);
            this.rbEatIn.TabIndex = 13;
            this.rbEatIn.TabStop = true;
            this.rbEatIn.Text = "Eat In";
            this.rbEatIn.UseVisualStyleBackColor = true;
            this.rbEatIn.CheckedChanged += new System.EventHandler(this.rbEatIn_CheckedChanged);
            // 
            // rbTakeOut
            // 
            this.rbTakeOut.AutoSize = true;
            this.rbTakeOut.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.rbTakeOut.ForeColor = System.Drawing.Color.White;
            this.rbTakeOut.Location = new System.Drawing.Point(140, 48);
            this.rbTakeOut.Name = "rbTakeOut";
            this.rbTakeOut.Size = new System.Drawing.Size(81, 23);
            this.rbTakeOut.TabIndex = 14;
            this.rbTakeOut.TabStop = true;
            this.rbTakeOut.Text = "Take Out";
            this.rbTakeOut.UseVisualStyleBackColor = true;
            this.rbTakeOut.CheckedChanged += new System.EventHandler(this.rbTakeOut_CheckedChanged);
            // 
            // gbToppings
            // 
            this.gbToppings.Controls.Add(this.chkGreenPeppers);
            this.gbToppings.Controls.Add(this.chkExtraChees);
            this.gbToppings.Controls.Add(this.chkOlives);
            this.gbToppings.Controls.Add(this.chkMushrooms);
            this.gbToppings.Controls.Add(this.chkTomatoes);
            this.gbToppings.Controls.Add(this.chkOnion);
            this.gbToppings.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.gbToppings.ForeColor = System.Drawing.Color.DarkOrange;
            this.gbToppings.Location = new System.Drawing.Point(235, 95);
            this.gbToppings.Name = "gbToppings";
            this.gbToppings.Size = new System.Drawing.Size(275, 150);
            this.gbToppings.TabIndex = 2;
            this.gbToppings.TabStop = false;
            this.gbToppings.Text = "Toppings";
            // 
            // chkGreenPeppers
            // 
            this.chkGreenPeppers.AutoSize = true;
            this.chkGreenPeppers.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.chkGreenPeppers.ForeColor = System.Drawing.Color.White;
            this.chkGreenPeppers.Location = new System.Drawing.Point(140, 105);
            this.chkGreenPeppers.Name = "chkGreenPeppers";
            this.chkGreenPeppers.Size = new System.Drawing.Size(117, 23);
            this.chkGreenPeppers.TabIndex = 14;
            this.chkGreenPeppers.Tag = "6";
            this.chkGreenPeppers.Text = "Green Peppers";
            this.chkGreenPeppers.UseVisualStyleBackColor = true;
            this.chkGreenPeppers.CheckedChanged += new System.EventHandler(this.chkGreenPeppers_CheckedChanged);
            // 
            // chkExtraChees
            // 
            this.chkExtraChees.AutoSize = true;
            this.chkExtraChees.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.chkExtraChees.ForeColor = System.Drawing.Color.White;
            this.chkExtraChees.Location = new System.Drawing.Point(15, 35);
            this.chkExtraChees.Name = "chkExtraChees";
            this.chkExtraChees.Size = new System.Drawing.Size(106, 23);
            this.chkExtraChees.TabIndex = 9;
            this.chkExtraChees.Tag = "5";
            this.chkExtraChees.Text = "Extra Cheese";
            this.chkExtraChees.UseVisualStyleBackColor = true;
            this.chkExtraChees.CheckedChanged += new System.EventHandler(this.chkExtraChees_CheckedChanged);
            // 
            // chkOlives
            // 
            this.chkOlives.AutoSize = true;
            this.chkOlives.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.chkOlives.ForeColor = System.Drawing.Color.White;
            this.chkOlives.Location = new System.Drawing.Point(140, 70);
            this.chkOlives.Name = "chkOlives";
            this.chkOlives.Size = new System.Drawing.Size(65, 23);
            this.chkOlives.TabIndex = 13;
            this.chkOlives.Tag = "4";
            this.chkOlives.Text = "Olives";
            this.chkOlives.UseVisualStyleBackColor = true;
            this.chkOlives.CheckedChanged += new System.EventHandler(this.chkOlives_CheckedChanged);
            // 
            // chkMushrooms
            // 
            this.chkMushrooms.AutoSize = true;
            this.chkMushrooms.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.chkMushrooms.ForeColor = System.Drawing.Color.White;
            this.chkMushrooms.Location = new System.Drawing.Point(15, 70);
            this.chkMushrooms.Name = "chkMushrooms";
            this.chkMushrooms.Size = new System.Drawing.Size(102, 23);
            this.chkMushrooms.TabIndex = 10;
            this.chkMushrooms.Tag = "3";
            this.chkMushrooms.Text = "Mushrooms";
            this.chkMushrooms.UseVisualStyleBackColor = true;
            this.chkMushrooms.CheckedChanged += new System.EventHandler(this.chkMushrooms_CheckedChanged);
            // 
            // chkTomatoes
            // 
            this.chkTomatoes.AutoSize = true;
            this.chkTomatoes.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.chkTomatoes.ForeColor = System.Drawing.Color.White;
            this.chkTomatoes.Location = new System.Drawing.Point(15, 105);
            this.chkTomatoes.Name = "chkTomatoes";
            this.chkTomatoes.Size = new System.Drawing.Size(87, 23);
            this.chkTomatoes.TabIndex = 11;
            this.chkTomatoes.Tag = "3";
            this.chkTomatoes.Text = "Tomatoes";
            this.chkTomatoes.UseVisualStyleBackColor = true;
            this.chkTomatoes.CheckedChanged += new System.EventHandler(this.chkTomatoes_CheckedChanged);
            // 
            // chkOnion
            // 
            this.chkOnion.AutoSize = true;
            this.chkOnion.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.chkOnion.ForeColor = System.Drawing.Color.White;
            this.chkOnion.Location = new System.Drawing.Point(140, 35);
            this.chkOnion.Name = "chkOnion";
            this.chkOnion.Size = new System.Drawing.Size(66, 23);
            this.chkOnion.TabIndex = 12;
            this.chkOnion.Tag = "7";
            this.chkOnion.Text = "Onion";
            this.chkOnion.UseVisualStyleBackColor = true;
            this.chkOnion.CheckedChanged += new System.EventHandler(this.chkOnion_CheckedChanged);
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.BackColor = System.Drawing.Color.MediumSeaGreen;
            this.btnOrderPizza.FlatAppearance.BorderSize = 0;
            this.btnOrderPizza.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOrderPizza.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.btnOrderPizza.ForeColor = System.Drawing.Color.White;
            this.btnOrderPizza.Location = new System.Drawing.Point(235, 395);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(130, 42);
            this.btnOrderPizza.TabIndex = 3;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = false;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnReset
            // 
            this.btnReset.BackColor = System.Drawing.Color.IndianRed;
            this.btnReset.FlatAppearance.BorderSize = 0;
            this.btnReset.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnReset.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.btnReset.ForeColor = System.Drawing.Color.White;
            this.btnReset.Location = new System.Drawing.Point(380, 395);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(130, 42);
            this.btnReset.TabIndex = 4;
            this.btnReset.Text = "Reset Form";
            this.btnReset.UseVisualStyleBackColor = false;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // gbOrderSummary
            // 
            this.gbOrderSummary.Controls.Add(this.lblTotalPrice);
            this.gbOrderSummary.Controls.Add(this.Lable5);
            this.gbOrderSummary.Controls.Add(this.lblWTE);
            this.gbOrderSummary.Controls.Add(this.Lable4);
            this.gbOrderSummary.Controls.Add(this.lblCrust);
            this.gbOrderSummary.Controls.Add(this.Lable3);
            this.gbOrderSummary.Controls.Add(this.lblToppings);
            this.gbOrderSummary.Controls.Add(this.Lable2);
            this.gbOrderSummary.Controls.Add(this.lblSize);
            this.gbOrderSummary.Controls.Add(this.Lable1);
            this.gbOrderSummary.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.gbOrderSummary.ForeColor = System.Drawing.Color.DarkOrange;
            this.gbOrderSummary.Location = new System.Drawing.Point(535, 95);
            this.gbOrderSummary.Name = "gbOrderSummary";
            this.gbOrderSummary.Size = new System.Drawing.Size(275, 342);
            this.gbOrderSummary.TabIndex = 5;
            this.gbOrderSummary.TabStop = false;
            this.gbOrderSummary.Text = "Order Summary";
            // 
            // lblTotalPrice
            // 
            this.lblTotalPrice.Font = new System.Drawing.Font("Segoe UI", 36F, System.Drawing.FontStyle.Bold);
            this.lblTotalPrice.ForeColor = System.Drawing.Color.OrangeRed;
            this.lblTotalPrice.Location = new System.Drawing.Point(10, 260);
            this.lblTotalPrice.Name = "lblTotalPrice";
            this.lblTotalPrice.Size = new System.Drawing.Size(255, 65);
            this.lblTotalPrice.TabIndex = 9;
            this.lblTotalPrice.Text = "$0";
            this.lblTotalPrice.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Lable5
            // 
            this.Lable5.AutoSize = true;
            this.Lable5.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.Lable5.ForeColor = System.Drawing.Color.DarkOrange;
            this.Lable5.Location = new System.Drawing.Point(15, 235);
            this.Lable5.Name = "Lable5";
            this.Lable5.Size = new System.Drawing.Size(86, 20);
            this.Lable5.TabIndex = 8;
            this.Lable5.Text = "Total Price:";
            // 
            // lblWTE
            // 
            this.lblWTE.AutoSize = true;
            this.lblWTE.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblWTE.ForeColor = System.Drawing.Color.White;
            this.lblWTE.Location = new System.Drawing.Point(120, 195);
            this.lblWTE.Name = "lblWTE";
            this.lblWTE.Size = new System.Drawing.Size(15, 19);
            this.lblWTE.TabIndex = 7;
            this.lblWTE.Text = "-";
            // 
            // Lable4
            // 
            this.Lable4.AutoSize = true;
            this.Lable4.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Lable4.ForeColor = System.Drawing.Color.Gray;
            this.Lable4.Location = new System.Drawing.Point(15, 195);
            this.Lable4.Name = "Lable4";
            this.Lable4.Size = new System.Drawing.Size(101, 19);
            this.Lable4.TabIndex = 6;
            this.Lable4.Text = "Where To Eat:";
            // 
            // lblCrust
            // 
            this.lblCrust.AutoSize = true;
            this.lblCrust.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblCrust.ForeColor = System.Drawing.Color.White;
            this.lblCrust.Location = new System.Drawing.Point(100, 155);
            this.lblCrust.Name = "lblCrust";
            this.lblCrust.Size = new System.Drawing.Size(15, 19);
            this.lblCrust.TabIndex = 5;
            this.lblCrust.Text = "-";
            // 
            // Lable3
            // 
            this.Lable3.AutoSize = true;
            this.Lable3.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Lable3.ForeColor = System.Drawing.Color.Gray;
            this.Lable3.Location = new System.Drawing.Point(15, 155);
            this.Lable3.Name = "Lable3";
            this.Lable3.Size = new System.Drawing.Size(83, 19);
            this.Lable3.TabIndex = 4;
            this.Lable3.Text = "Crust Type:";
            // 
            // lblToppings
            // 
            this.lblToppings.Font = new System.Drawing.Font("Segoe UI", 9.5F);
            this.lblToppings.ForeColor = System.Drawing.Color.White;
            this.lblToppings.Location = new System.Drawing.Point(15, 90);
            this.lblToppings.Name = "lblToppings";
            this.lblToppings.Size = new System.Drawing.Size(245, 55);
            this.lblToppings.TabIndex = 3;
            this.lblToppings.Text = "No Toppings";
            // 
            // Lable2
            // 
            this.Lable2.AutoSize = true;
            this.Lable2.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Lable2.ForeColor = System.Drawing.Color.Gray;
            this.Lable2.Location = new System.Drawing.Point(15, 68);
            this.Lable2.Name = "Lable2";
            this.Lable2.Size = new System.Drawing.Size(74, 19);
            this.Lable2.TabIndex = 2;
            this.Lable2.Text = "Toppings:";
            // 
            // lblSize
            // 
            this.lblSize.AutoSize = true;
            this.lblSize.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblSize.ForeColor = System.Drawing.Color.White;
            this.lblSize.Location = new System.Drawing.Point(60, 35);
            this.lblSize.Name = "lblSize";
            this.lblSize.Size = new System.Drawing.Size(15, 19);
            this.lblSize.TabIndex = 1;
            this.lblSize.Text = "-";
            // 
            // Lable1
            // 
            this.Lable1.AutoSize = true;
            this.Lable1.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Lable1.ForeColor = System.Drawing.Color.Gray;
            this.Lable1.Location = new System.Drawing.Point(15, 35);
            this.Lable1.Name = "Lable1";
            this.Lable1.Size = new System.Drawing.Size(44, 19);
            this.Lable1.TabIndex = 0;
            this.Lable1.Text = "Size: ";
            // 
            // nudPizzaAmount
            // 
            this.nudPizzaAmount.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nudPizzaAmount.Location = new System.Drawing.Point(108, 404);
            this.nudPizzaAmount.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.nudPizzaAmount.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudPizzaAmount.Name = "nudPizzaAmount";
            this.nudPizzaAmount.Size = new System.Drawing.Size(102, 25);
            this.nudPizzaAmount.TabIndex = 6;
            this.nudPizzaAmount.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudPizzaAmount.ValueChanged += new System.EventHandler(this.nudPizzaAmount_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.label2.ForeColor = System.Drawing.Color.Gray;
            this.label2.Location = new System.Drawing.Point(30, 407);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 19);
            this.label2.TabIndex = 10;
            this.label2.Text = "Amount:";
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(22)))), ((int)(((byte)(26)))));
            this.ClientSize = new System.Drawing.Size(840, 460);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.nudPizzaAmount);
            this.Controls.Add(this.gbOrderSummary);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.gbCrust);
            this.Controls.Add(this.gbWTE);
            this.Controls.Add(this.gbToppings);
            this.Controls.Add(this.gbSize);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Pizza Order Studio";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.gbSize.ResumeLayout(false);
            this.gbSize.PerformLayout();
            this.gbCrust.ResumeLayout(false);
            this.gbCrust.PerformLayout();
            this.gbWTE.ResumeLayout(false);
            this.gbWTE.PerformLayout();
            this.gbToppings.ResumeLayout(false);
            this.gbToppings.PerformLayout();
            this.gbOrderSummary.ResumeLayout(false);
            this.gbOrderSummary.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPizzaAmount)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox gbSize;
        private System.Windows.Forms.GroupBox gbCrust;
        private System.Windows.Forms.GroupBox gbWTE;
        private System.Windows.Forms.GroupBox gbToppings;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbMedium;
        private System.Windows.Forms.RadioButton rbThinCrust;
        private System.Windows.Forms.CheckBox chkGreenPeppers;
        private System.Windows.Forms.CheckBox chkOlives;
        private System.Windows.Forms.CheckBox chkOnion;
        private System.Windows.Forms.CheckBox chkTomatoes;
        private System.Windows.Forms.CheckBox chkMushrooms;
        private System.Windows.Forms.CheckBox chkExtraChees;
        private System.Windows.Forms.RadioButton rbThickCrust;
        private System.Windows.Forms.RadioButton rbEatIn;
        private System.Windows.Forms.RadioButton rbTakeOut;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.GroupBox gbOrderSummary;
        private System.Windows.Forms.Label Lable2;
        private System.Windows.Forms.Label lblSize;
        private System.Windows.Forms.Label Lable1;
        private System.Windows.Forms.Label Lable5;
        private System.Windows.Forms.Label lblWTE;
        private System.Windows.Forms.Label Lable4;
        private System.Windows.Forms.Label lblCrust;
        private System.Windows.Forms.Label Lable3;
        private System.Windows.Forms.Label lblToppings;
        private System.Windows.Forms.Label lblTotalPrice;
        private System.Windows.Forms.NumericUpDown nudPizzaAmount;
        private System.Windows.Forms.Label label2;
    }
}