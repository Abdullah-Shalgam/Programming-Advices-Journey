namespace Lesson16___First_Windows_Forms_Application
{
    partial class frmPictureBox
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.PbStrongOrWeak = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.PbStrongOrWeak)).BeginInit();
            this.SuspendLayout();
            // 
            // PbStrongOrWeak
            // 
            this.PbStrongOrWeak.Image = global::Lesson16___First_Windows_Forms_Application.Properties.Resources.Strong;
            this.PbStrongOrWeak.Location = new System.Drawing.Point(21, 81);
            this.PbStrongOrWeak.Name = "PbStrongOrWeak";
            this.PbStrongOrWeak.Size = new System.Drawing.Size(290, 212);
            this.PbStrongOrWeak.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.PbStrongOrWeak.TabIndex = 0;
            this.PbStrongOrWeak.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(447, 81);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(117, 68);
            this.button1.TabIndex = 1;
            this.button1.Text = "Weak Picture";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(447, 177);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(117, 68);
            this.button2.TabIndex = 2;
            this.button2.Text = "Strong Picture";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(447, 270);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(117, 68);
            this.button3.TabIndex = 3;
            this.button3.Text = "Bwaba Logo";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // frmPictureBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.PbStrongOrWeak);
            this.Name = "frmPictureBox";
            this.Text = "frmPictureBox";
            ((System.ComponentModel.ISupportInitialize)(this.PbStrongOrWeak)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox PbStrongOrWeak;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
    }
}