namespace Lesson16___First_Windows_Forms_Application
{
    partial class frmMain
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
            this.btnShowPart1 = new System.Windows.Forms.Button();
            this.btnShowPart1AsDialog = new System.Windows.Forms.Button();
            this.btnMessageBoxForm = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnShowPart1
            // 
            this.btnShowPart1.Location = new System.Drawing.Point(120, 138);
            this.btnShowPart1.Name = "btnShowPart1";
            this.btnShowPart1.Size = new System.Drawing.Size(115, 63);
            this.btnShowPart1.TabIndex = 0;
            this.btnShowPart1.Text = "Show Form";
            this.btnShowPart1.UseVisualStyleBackColor = true;
            this.btnShowPart1.Click += new System.EventHandler(this.btnShowPart1_Click);
            // 
            // btnShowPart1AsDialog
            // 
            this.btnShowPart1AsDialog.Location = new System.Drawing.Point(120, 232);
            this.btnShowPart1AsDialog.Name = "btnShowPart1AsDialog";
            this.btnShowPart1AsDialog.Size = new System.Drawing.Size(115, 63);
            this.btnShowPart1AsDialog.TabIndex = 1;
            this.btnShowPart1AsDialog.Text = "Show Form As Dialog";
            this.btnShowPart1AsDialog.UseVisualStyleBackColor = true;
            this.btnShowPart1AsDialog.Click += new System.EventHandler(this.btnShowPart1AsDialog_Click);
            // 
            // btnMessageBoxForm
            // 
            this.btnMessageBoxForm.Location = new System.Drawing.Point(336, 178);
            this.btnMessageBoxForm.Name = "btnMessageBoxForm";
            this.btnMessageBoxForm.Size = new System.Drawing.Size(115, 63);
            this.btnMessageBoxForm.TabIndex = 2;
            this.btnMessageBoxForm.Text = "Show Message Box Form";
            this.btnMessageBoxForm.UseVisualStyleBackColor = true;
            this.btnMessageBoxForm.Click += new System.EventHandler(this.btnMessageBoxForm_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(44, 16);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(8, 8);
            this.button2.TabIndex = 3;
            this.button2.Text = "button2";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.btnMessageBoxForm);
            this.Controls.Add(this.btnShowPart1AsDialog);
            this.Controls.Add(this.btnShowPart1);
            this.Name = "frmMain";
            this.Text = "Main Form";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnShowPart1;
        private System.Windows.Forms.Button btnShowPart1AsDialog;
        private System.Windows.Forms.Button btnMessageBoxForm;
        private System.Windows.Forms.Button button2;
    }
}