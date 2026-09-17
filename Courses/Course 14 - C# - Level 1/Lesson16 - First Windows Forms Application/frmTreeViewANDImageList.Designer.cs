namespace Lesson16___First_Windows_Forms_Application
{
    partial class TreeView_and_ImageList
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
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Node8");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Lesson1", new System.Windows.Forms.TreeNode[] {
            treeNode1});
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Node9");
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Lesson2", new System.Windows.Forms.TreeNode[] {
            treeNode3});
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Node10");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Lesson3", new System.Windows.Forms.TreeNode[] {
            treeNode5});
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("Course 5", new System.Windows.Forms.TreeNode[] {
            treeNode2,
            treeNode4,
            treeNode6});
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("Node11");
            System.Windows.Forms.TreeNode treeNode9 = new System.Windows.Forms.TreeNode("Node12");
            System.Windows.Forms.TreeNode treeNode10 = new System.Windows.Forms.TreeNode("Lesson1", new System.Windows.Forms.TreeNode[] {
            treeNode8,
            treeNode9});
            System.Windows.Forms.TreeNode treeNode11 = new System.Windows.Forms.TreeNode("Node13");
            System.Windows.Forms.TreeNode treeNode12 = new System.Windows.Forms.TreeNode("Node14");
            System.Windows.Forms.TreeNode treeNode13 = new System.Windows.Forms.TreeNode("Lesson2", new System.Windows.Forms.TreeNode[] {
            treeNode11,
            treeNode12});
            System.Windows.Forms.TreeNode treeNode14 = new System.Windows.Forms.TreeNode("Course 6", new System.Windows.Forms.TreeNode[] {
            treeNode10,
            treeNode13});
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TreeView_and_ImageList));
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.SuspendLayout();
            // 
            // treeView1
            // 
            this.treeView1.ImageIndex = 0;
            this.treeView1.ImageList = this.imageList1;
            this.treeView1.Location = new System.Drawing.Point(12, 23);
            this.treeView1.Name = "treeView1";
            treeNode1.Name = "Node8";
            treeNode1.Text = "Node8";
            treeNode2.ImageKey = "icons8-folder-48.png";
            treeNode2.Name = "Node2";
            treeNode2.Text = "Lesson1";
            treeNode3.Name = "Node9";
            treeNode3.Text = "Node9";
            treeNode4.ImageKey = "icons8-folder-48.png";
            treeNode4.Name = "Node3";
            treeNode4.Text = "Lesson2";
            treeNode5.Name = "Node10";
            treeNode5.Text = "Node10";
            treeNode6.ImageKey = "icons8-folder-48.png";
            treeNode6.Name = "Node4";
            treeNode6.Text = "Lesson3";
            treeNode7.ImageKey = "icons8-folder-48.png";
            treeNode7.Name = "Node0";
            treeNode7.SelectedImageKey = "(default)";
            treeNode7.Text = "Course 5";
            treeNode8.Name = "Node11";
            treeNode8.Text = "Node11";
            treeNode9.Name = "Node12";
            treeNode9.Text = "Node12";
            treeNode10.ImageKey = "icons8-folder-48.png";
            treeNode10.Name = "Node5";
            treeNode10.Text = "Lesson1";
            treeNode11.Name = "Node13";
            treeNode11.Text = "Node13";
            treeNode12.Name = "Node14";
            treeNode12.Text = "Node14";
            treeNode13.ImageKey = "icons8-folder-48.png";
            treeNode13.Name = "Node6";
            treeNode13.Text = "Lesson2";
            treeNode14.ImageKey = "icons8-folder-48.png";
            treeNode14.Name = "Node1";
            treeNode14.Text = "Course 6";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode7,
            treeNode14});
            this.treeView1.SelectedImageIndex = 0;
            this.treeView1.Size = new System.Drawing.Size(293, 274);
            this.treeView1.TabIndex = 0;
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "icons8-txt-48.png");
            this.imageList1.Images.SetKeyName(1, "icons8-c++-48.png");
            this.imageList1.Images.SetKeyName(2, "icons8-folder-48.png");
            // 
            // TreeView_and_ImageList
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.treeView1);
            this.Name = "TreeView_and_ImageList";
            this.Text = "TreeView_and_ImageList";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.ImageList imageList1;
    }
}