namespace Lesson16___First_Windows_Forms_Application
{
    partial class frmCheckedListBox
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmCheckedListBox));
            System.Windows.Forms.TreeNode treeNode15 = new System.Windows.Forms.TreeNode("Lesson.cpp", 1, 1);
            System.Windows.Forms.TreeNode treeNode16 = new System.Windows.Forms.TreeNode("Lesson1", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode15});
            System.Windows.Forms.TreeNode treeNode17 = new System.Windows.Forms.TreeNode("Lesson.cpp", 1, 1);
            System.Windows.Forms.TreeNode treeNode18 = new System.Windows.Forms.TreeNode("Lesson2", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode17});
            System.Windows.Forms.TreeNode treeNode19 = new System.Windows.Forms.TreeNode("Lesson.cpp", 1, 1);
            System.Windows.Forms.TreeNode treeNode20 = new System.Windows.Forms.TreeNode("Lesson3", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode19});
            System.Windows.Forms.TreeNode treeNode21 = new System.Windows.Forms.TreeNode("Course 5", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode16,
            treeNode18,
            treeNode20});
            System.Windows.Forms.TreeNode treeNode22 = new System.Windows.Forms.TreeNode("Lesson.cpp", 1, 1);
            System.Windows.Forms.TreeNode treeNode23 = new System.Windows.Forms.TreeNode("Notes.txt", 0, 0);
            System.Windows.Forms.TreeNode treeNode24 = new System.Windows.Forms.TreeNode("Lesson1", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode22,
            treeNode23});
            System.Windows.Forms.TreeNode treeNode25 = new System.Windows.Forms.TreeNode("Lesson.cpp", 1, 1);
            System.Windows.Forms.TreeNode treeNode26 = new System.Windows.Forms.TreeNode("Notes.txt", 0, 0);
            System.Windows.Forms.TreeNode treeNode27 = new System.Windows.Forms.TreeNode("Lesson2", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode25,
            treeNode26});
            System.Windows.Forms.TreeNode treeNode28 = new System.Windows.Forms.TreeNode("Course 6", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode24,
            treeNode27});
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "icons8-txt-48.png");
            this.imageList1.Images.SetKeyName(1, "icons8-c++-48.png");
            this.imageList1.Images.SetKeyName(2, "icons8-folder-48.png");
            // 
            // treeView1
            // 
            this.treeView1.CheckBoxes = true;
            this.treeView1.ImageIndex = 0;
            this.treeView1.ImageList = this.imageList1;
            this.treeView1.Location = new System.Drawing.Point(23, 29);
            this.treeView1.Name = "treeView1";
            treeNode15.ImageIndex = 1;
            treeNode15.Name = "Node8";
            treeNode15.SelectedImageIndex = 1;
            treeNode15.Text = "Lesson.cpp";
            treeNode16.ImageIndex = 2;
            treeNode16.Name = "Node2";
            treeNode16.SelectedImageIndex = 2;
            treeNode16.Text = "Lesson1";
            treeNode17.ImageIndex = 1;
            treeNode17.Name = "Node9";
            treeNode17.SelectedImageIndex = 1;
            treeNode17.Text = "Lesson.cpp";
            treeNode18.ImageIndex = 2;
            treeNode18.Name = "Node3";
            treeNode18.SelectedImageIndex = 2;
            treeNode18.Text = "Lesson2";
            treeNode19.ImageIndex = 1;
            treeNode19.Name = "Node10";
            treeNode19.SelectedImageIndex = 1;
            treeNode19.Text = "Lesson.cpp";
            treeNode20.ImageIndex = 2;
            treeNode20.Name = "Node4";
            treeNode20.SelectedImageIndex = 2;
            treeNode20.Text = "Lesson3";
            treeNode21.ImageIndex = 2;
            treeNode21.Name = "Node0";
            treeNode21.SelectedImageIndex = 2;
            treeNode21.Text = "Course 5";
            treeNode22.ImageIndex = 1;
            treeNode22.Name = "Node11";
            treeNode22.SelectedImageIndex = 1;
            treeNode22.Text = "Lesson.cpp";
            treeNode23.ImageIndex = 0;
            treeNode23.Name = "Node12";
            treeNode23.SelectedImageIndex = 0;
            treeNode23.Text = "Notes.txt";
            treeNode24.ImageIndex = 2;
            treeNode24.Name = "Node5";
            treeNode24.SelectedImageIndex = 2;
            treeNode24.Text = "Lesson1";
            treeNode25.ImageIndex = 1;
            treeNode25.Name = "Node13";
            treeNode25.SelectedImageIndex = 1;
            treeNode25.Text = "Lesson.cpp";
            treeNode26.ImageIndex = 0;
            treeNode26.Name = "Node14";
            treeNode26.SelectedImageIndex = 0;
            treeNode26.Text = "Notes.txt";
            treeNode27.ImageIndex = 2;
            treeNode27.Name = "Node6";
            treeNode27.SelectedImageIndex = 2;
            treeNode27.Text = "Lesson2";
            treeNode28.ImageIndex = 2;
            treeNode28.Name = "Node1";
            treeNode28.SelectedImageIndex = 2;
            treeNode28.Text = "Course 6";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode21,
            treeNode28});
            this.treeView1.SelectedImageIndex = 0;
            this.treeView1.Size = new System.Drawing.Size(447, 386);
            this.treeView1.TabIndex = 6;
            this.treeView1.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterCheck);
            this.treeView1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.treeView1_MouseDoubleClick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(555, 152);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(113, 61);
            this.button1.TabIndex = 7;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // frmCheckedListBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.treeView1);
            this.Name = "frmCheckedListBox";
            this.Text = "frmCheckedListBox";
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.Button button1;
    }
}