using System;
using System.Drawing;
using System.Windows.Forms;
using Tic_Tac_Toe_Game_Project.Properties;

namespace Tic_Tac_Toe_Game_Project
{
    public partial class Form1 : Form
    {
        enum enPlayer
        {
            Player1,
            Player2
        }

        enum enWinner
        {
            Player1,
            Player2,
            Draw,
            GameInProgress
        }

        struct stGameStatus
        {
            public enWinner Winner;
            public byte PlayCount;
            public bool GameOver;
        }

        stGameStatus GameStatus;
        enPlayer Player = enPlayer.Player1;

        public Form1()
        {
            InitializeComponent();
            ResetGame();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            using (Pen pen = new Pen(Color.White, 10))
            {
                pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
                pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

                // الخطوط الأفقية
                e.Graphics.DrawLine(pen, 300, 190, 750, 190);
                e.Graphics.DrawLine(pen, 300, 300, 750, 300);

                // الخطوط الراسية
                e.Graphics.DrawLine(pen, 450, 80, 450, 410);
                e.Graphics.DrawLine(pen, 600, 80, 600, 410);
            }
        }

        bool CheckThreeButtons(Button btn1, Button btn2, Button btn3)
        {
            if (btn1.Tag.ToString() != "?" &&
                btn1.Tag.ToString() == btn2.Tag.ToString() &&
                btn1.Tag.ToString() == btn3.Tag.ToString())
            {
                btn1.BackColor = Color.GreenYellow;
                btn2.BackColor = Color.GreenYellow;
                btn3.BackColor = Color.GreenYellow;

                if (btn1.Tag.ToString() == "X")
                    GameStatus.Winner = enWinner.Player1;
                else
                    GameStatus.Winner = enWinner.Player2;

                GameStatus.GameOver = true;
                EndGame();
                return true;
            }

            return false;
        }

        void CheckWinner()
        {
            // فحص الصفوف والأعمدة والأقطار
            if (CheckThreeButtons(button1, button2, button3) ||
                CheckThreeButtons(button4, button5, button6) ||
                CheckThreeButtons(button7, button8, button9) ||
                CheckThreeButtons(button1, button4, button7) ||
                CheckThreeButtons(button2, button5, button8) ||
                CheckThreeButtons(button3, button6, button9) ||
                CheckThreeButtons(button1, button5, button9) ||
                CheckThreeButtons(button3, button5, button7))
            {
                return;
            }

            // فحص حالة التعادل
            if (GameStatus.PlayCount == 9)
            {
                GameStatus.Winner = enWinner.Draw;
                GameStatus.GameOver = true;
                EndGame();
            }
        }

        void EndGame()
        {
            lblTurn.Text = "Game Over";

            switch (GameStatus.Winner)
            {
                case enWinner.Player1:
                    lblWinner.Text = "Player 1";
                    break;
                case enWinner.Player2:
                    lblWinner.Text = "Player 2";
                    break;
                case enWinner.Draw:
                    lblWinner.Text = "Draw";
                    break;
            }

            MessageBox.Show("Game Over", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        Image ResizeImage(Image img, int width, int height)
        {
            return new Bitmap(img, new Size(width, height));
        }

        void ChangeImage(Button btn)
        {
            if (GameStatus.GameOver)
                return;

            if (btn.Tag.ToString() == "?")
            {
                switch (Player)
                {
                    case enPlayer.Player1:
                        btn.Image = ResizeImage(Resources.X, 60, 60);
                        btn.Tag = "X";
                        Player = enPlayer.Player2;
                        lblTurn.Text = "Player 2";
                        break;

                    case enPlayer.Player2:
                        btn.Image = ResizeImage(Resources.O, 60, 60);
                        btn.Tag = "O";
                        Player = enPlayer.Player1;
                        lblTurn.Text = "Player 1";
                        break;
                }

                GameStatus.PlayCount++;
                CheckWinner();
            }
            else
            {
                MessageBox.Show("Wrong Choice", "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button_Click(object sender, EventArgs e)
        {
            ChangeImage((Button)sender);
        }

        void ResetButton(Button btn)
        {
            btn.Image = ResizeImage(Resources.question_mark_96, 60, 60);
            btn.Tag = "?";
            btn.BackColor = Color.Black;
        }

        void ResetGame()
        {
            ResetButton(button1);
            ResetButton(button2);
            ResetButton(button3);
            ResetButton(button4);
            ResetButton(button5);
            ResetButton(button6);
            ResetButton(button7);
            ResetButton(button8);
            ResetButton(button9);

            Player = enPlayer.Player1;
            GameStatus.Winner = enWinner.GameInProgress;
            GameStatus.PlayCount = 0;
            GameStatus.GameOver = false;

            lblTurn.Text = "Player 1";
            lblWinner.Text = "In Progress";
        }

        private void btnRestartForm_Click(object sender, EventArgs e)
        {
            ResetGame();
        }
    }
}