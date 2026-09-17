using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lesson16___First_Windows_Forms_Application
{
    public partial class frmCheckedListBox : Form
    {
        public frmCheckedListBox()
        {
            InitializeComponent();
        }

        private void treeView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show(treeView1.SelectedNode.Text, "Selected Node is:", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void treeView1_AfterCheck(object sender, TreeViewEventArgs e)
        {
            CheckTreeViewNode(e.Node, e.Node.Checked);
        }

        void CheckTreeViewNode(TreeNode Node, Boolean IsChecked)
        {
            foreach(TreeNode item in Node.Nodes)
            {
                item.Checked = IsChecked;

                if (item.Nodes.Count > 0)
                {
                    this.CheckTreeViewNode(item, IsChecked);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            treeView1.Nodes.Add("koko", "that is added by button", 2, 2);
        }
    }
}
