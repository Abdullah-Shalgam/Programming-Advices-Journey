using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Deployment.Application;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace To_Do_List_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        void UpdateTotal()
        {
            lblTotal.Text = chklbTasks.Items.Count.ToString();
        }

        void UpdateDone()
        {
            lblDone.Text = chklbTasks.CheckedItems.Count.ToString();
        }

        void UpdateInProgress()
        {
            lblInProgress.Text = (chklbTasks.Items.Count - chklbTasks.CheckedItems.Count).ToString();
        }

        private void btnAddTask_Click(object sender, EventArgs e)
        {
            chklbTasks.Items.Add(txtTaskTitle.Text);
            UpdateTotal();
            UpdateInProgress();
        }

        private void btnClearCompleted_Click(object sender, EventArgs e)
        {
            for (int i = chklbTasks.CheckedIndices.Count - 1; i >= 0; i--)
            {
                int indexToRemove = chklbTasks.CheckedIndices[i];
                chklbTasks.Items.RemoveAt(indexToRemove);
            }

            UpdateDone();
            UpdateTotal();
            UpdateInProgress();
        }

        private void btnMarkAllDone_Click(object sender, EventArgs e)
        {
            bool IsAllChecked = (chklbTasks.CheckedIndices.Count == chklbTasks.Items.Count);

            if (IsAllChecked)
            {
                for (int i = 0; i < chklbTasks.Items.Count; i++)
                {
                    chklbTasks.SetItemChecked(i, false);
                }

                lblDone.Text = "0";
                lblInProgress.Text = chklbTasks.Items.Count.ToString();
            }

            else
            {
                for (int i = 0; i < chklbTasks.Items.Count; i++)
                {
                    chklbTasks.SetItemChecked(i, true);
                }

                lblDone.Text = chklbTasks.Items.Count.ToString();
                lblInProgress.Text = "0";
            }
        }

        private void btnDeleteSelected_Click(object sender, EventArgs e)
        {
            chklbTasks.Items.RemoveAt(chklbTasks.SelectedIndex);
            UpdateTotal();
            UpdateDone();
            UpdateInProgress();
        }

        private void btnDeleteAll_Click(object sender, EventArgs e)
        {
            chklbTasks.Items.Clear();
            lblTotal.Text = "0";
            lblDone.Text = "0";
            lblInProgress.Text = "0";
        }

        private void chklbTasks_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateDone();
            UpdateInProgress();
        }
    }
}
