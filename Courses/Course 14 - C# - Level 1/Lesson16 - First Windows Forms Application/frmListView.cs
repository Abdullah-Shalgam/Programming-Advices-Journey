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
    public partial class frmListView : Form
    {
        public frmListView()
        {
            InitializeComponent();
            panel1.BackColor = Color.FromArgb(243, 246, 253);
            label2.ForeColor = Color.FromArgb(156, 163, 175);
            label3.ForeColor = Color.FromArgb(156, 163, 175);
            label4.ForeColor = Color.FromArgb(156, 163, 175);
            txtID.ForeColor = Color.FromArgb(156, 163, 175);
            txtName.ForeColor = Color.FromArgb(156, 163, 175);
            txtPosition.ForeColor = Color.FromArgb(156, 163, 175);
            txtSalary.ForeColor = Color.FromArgb(156, 163, 175);
            txtSearch.ForeColor = Color.FromArgb(156, 163, 175);
            txtID.Text = txtID.Tag.ToString();
            txtName.Text = txtName.Tag.ToString();
            txtPosition.Text = txtPosition.Tag.ToString();
            txtSalary.Text = txtSalary.Tag.ToString();
            txtSearch.Text = txtSearch.Tag.ToString();
            label3.Text = DateTime.Now.ToShortDateString();
            label4.Text = DateTime.Now.ToShortTimeString();
            cbSearchDepartment.SelectedIndex = 0;
            rbMale.Checked = true;
        }

        List<ListViewItem> allEmployees = new List<ListViewItem>();

        void ResetForm()
        {
            txtID.ForeColor = Color.FromArgb(156, 163, 175);
            txtName.ForeColor = Color.FromArgb(156, 163, 175);
            txtPosition.ForeColor = Color.FromArgb(156, 163, 175);
            txtSalary.ForeColor = Color.FromArgb(156, 163, 175);

            txtID.Text = txtID.Tag.ToString();
            txtName.Text = txtName.Tag.ToString();
            txtPosition.Text = txtPosition.Tag.ToString();
            txtSalary.Text = txtSalary.Tag.ToString();

            cbDepartemnt.Text = cbDepartemnt.Tag.ToString();

            txtID.Focus();
        }

        void TextBoxEntered(TextBox txtbox)
        {
            if (txtbox.ForeColor == Color.FromArgb(156, 163, 175))
            {
                txtbox.Text = "";
                txtbox.ForeColor = Color.Black;
            }
        }

        void TextBoxLeave(TextBox txtbox)
        {
            if (txtbox.Text.Trim().Length == 0 || int.TryParse(txtbox.Text, out int value) && value == 0)
            {
                txtbox.ForeColor = Color.FromArgb(156, 163, 175);
                txtbox.Text = txtbox.Tag.ToString();
            }
        }

        private void txtID_Enter(object sender, EventArgs e)
        {
            TextBoxEntered((TextBox)sender);
        }

        private void txtID_Leave(object sender, EventArgs e)
        {
            TextBoxLeave((TextBox)sender);
        }

        private void txtID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsLetterOrDigit(e.KeyChar) && !char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }

        private void txtSalary_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (char.IsDigit(e.KeyChar) || char.IsControl(e.KeyChar))
            {
                return;
            }

            if (e.KeyChar == '.')
            {
                if (txtSalary.Text.Contains("."))
                {
                    e.Handled = true;
                }
                return;
            }
            e.Handled = true;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (txtID.Text == txtID.Tag.ToString() || txtName.Text == txtName.Tag.ToString() || txtPosition.Text == txtPosition.Tag.ToString() || txtSalary.Text == txtSalary.Tag.ToString() || cbDepartemnt.Text == cbDepartemnt.Tag.ToString())
            {
                return;
            }

            ListViewItem item = new ListViewItem(txtID.Text.Trim());

            item.SubItems.Add(txtName.Text.Trim());
            item.SubItems.Add(numericUpDown1.Value.ToString());

            if (rbMale.Checked)
            {
                item.ImageIndex = 0;
                item.SubItems.Add(rbMale.Text);
            }
            else
            {
                item.ImageIndex = 1;
                item.SubItems.Add(rbFemale.Text);
            }

            item.SubItems.Add(cbDepartemnt.Text.Trim());
            item.SubItems.Add(txtPosition.Text.Trim());
            if (float.TryParse(txtSalary.Text, out float value))
            {
                item.SubItems.Add(value.ToString());
            }

            listView1.Items.Add(item);
            allEmployees.Add(item);

            ResetForm();
        }

        private void btnGenerateEmployees_Click(object sender, EventArgs e)
        {
            for (byte i = 1; i <= 10; i++)
            {
                ListViewItem item = new ListViewItem(i.ToString());

                item.SubItems.Add("Person" + i);
                item.SubItems.Add((20 + i).ToString());

                if (i % 2 == 0)
                {
                    item.ImageIndex = 0;
                    item.SubItems.Add(rbMale.Text);
                }
                else
                {
                    item.ImageIndex = 1;
                    item.SubItems.Add(rbFemale.Text);
                }

                item.SubItems.Add("None");
                item.SubItems.Add("None");
                item.SubItems.Add((100 * i).ToString());

                listView1.Items.Add(item);
                allEmployees.Add(item);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            DialogResult confirmClear = MessageBox.Show(
                "WARNING: This will permanently delete ALL employee records from the screen and memory. This action cannot be undone!\n\nDo you really want to clear everything?",
                "Critical Warning",
                MessageBoxButtons.YesNo,
                MessageBoxIcon.Warning,
                MessageBoxDefaultButton.Button2
            );

            if (confirmClear == DialogResult.Yes)
            {
                allEmployees.Clear();
                listView1.Items.Clear();

                MessageBox.Show("All employee records have been wiped successfully.", "System Reset",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

            ResetForm();
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            string searchText = txtSearch.Text.Trim();
            string searchDepartment = cbSearchDepartment.Text;

            bool isDefaultSearchText = searchText.Equals(txtSearch.Tag?.ToString(), StringComparison.OrdinalIgnoreCase);
            bool isAllDepartment = searchDepartment.Equals(cbSearchDepartment.Tag?.ToString(), StringComparison.OrdinalIgnoreCase);

            listView1.Items.Clear();

            if (isDefaultSearchText && isAllDepartment)
            {
                listView1.Items.AddRange(allEmployees.ToArray());
                return;
            }

            listView1.BeginUpdate();
            try
            {
                foreach (ListViewItem item in allEmployees)
                {
                    string employeeID = item.Text;
                    string employeeName = item.SubItems[1].Text;
                    string department = item.SubItems[4].Text;

                    bool matchesDepartment = isAllDepartment || department.Equals(searchDepartment, StringComparison.OrdinalIgnoreCase);

                    if (matchesDepartment)
                    {
                        if (isDefaultSearchText)
                        {
                            listView1.Items.Add(item);
                        }

                        else if (employeeName.IndexOf(searchText, StringComparison.OrdinalIgnoreCase) >= 0 ||
                         employeeID.IndexOf(searchText, StringComparison.OrdinalIgnoreCase) >= 0)
                        {
                            listView1.Items.Add(item);
                        }
                    }
                }
            }
            finally
            {
                listView1.EndUpdate();
            }

            if (listView1.Items.Count == 0)
            {
                MessageBox.Show("No matching employee records found.", "Search Results",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select an employee from the list to delete.", "Selection Required",
                                MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            DialogResult confirmResult = MessageBox.Show("WARNING: Are you sure you want to delete the selected employee?",
                                                         "Confirm Delete",
                                                         MessageBoxButtons.YesNo,
                                                         MessageBoxIcon.Warning,
                                                         MessageBoxDefaultButton.Button2);

            if (confirmResult == DialogResult.Yes)
            {
                ListViewItem selectedItem = listView1.SelectedItems[0];
                allEmployees.Remove(selectedItem);
                listView1.Items.Remove(selectedItem);

                MessageBox.Show("Employee deleted successfully.", "Success",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void listView1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                btnDelete_Click(sender, e);
            }
        }
    }
}