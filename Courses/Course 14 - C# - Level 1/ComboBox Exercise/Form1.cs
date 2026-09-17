using ComboBox_Exercise.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PictureBox_Exercise
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedItem.ToString().ToLower())
            {
                case "boy":
                    pbTitle.Image = Resources.Boy;
                    lblTitle.Text = "Boy";
                    break;

                case "girl":
                    pbTitle.Image = Resources.Girl;
                    lblTitle.Text = "Girl";
                    break;

                case "book":
                    pbTitle.Image = Resources.Book;
                    lblTitle.Text = "Book";
                    break;

                case "pen":
                    pbTitle.Image = Resources.Pen;
                    lblTitle.Text = "Pen";
                    break;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
        }
    }
}
