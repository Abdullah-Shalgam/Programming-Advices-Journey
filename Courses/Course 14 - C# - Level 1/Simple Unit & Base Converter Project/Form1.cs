using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using UnitAndBaseConverter.Core;
using UnitAndBaseConverter.UI.Theme;

namespace UnitAndBaseConverter
{
    public partial class Form1 : System.Windows.Forms.Form
    {
        private readonly HistoryManager _historyManager = new HistoryManager();

        public Form1()
        {
            InitializeComponent();
            DoubleBuffered = true;

            SetupInitialState();
            ThemeManager.ThemeChanged += (s, e) => ApplyCurrentTheme();
            ApplyCurrentTheme();
        }

        private void SetupInitialState()
        {
            // Base Converter Setup
            cmbFromBase.DataSource = Enum.GetValues(typeof(NumBase));
            cmbToBase.DataSource = Enum.GetValues(typeof(NumBase));
            cmbFromBase.SelectedItem = NumBase.Decimal;
            cmbToBase.SelectedItem = NumBase.Hexadecimal;

            // Unit Converter Setup
            cmbCategory.DataSource = Enum.GetValues(typeof(UnitCategory));
            cmbCategory.SelectedItem = UnitCategory.Length;
            RefreshUnitDropdowns();

            // Placeholders
            txtSearchHistory.Text = "Filter history...";
            txtSearchHistory.ForeColor = Color.Gray;
            txtSearchHistory.GotFocus += (s, e) => 
            { 
                if (txtSearchHistory.Text == "Filter history...") 
                { 
                    txtSearchHistory.Text = ""; 
                    txtSearchHistory.ForeColor = ThemeManager.Palette.TextPrimary; 
                } 
            };
            txtSearchHistory.LostFocus += (s, e) => 
            { 
                if (string.IsNullOrWhiteSpace(txtSearchHistory.Text)) 
                { 
                    txtSearchHistory.Text = "Filter history..."; 
                    txtSearchHistory.ForeColor = Color.Gray; 
                } 
            };
        }

        #region Base Converter Logic

        private void txtBaseInput_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (cmbFromBase.SelectedItem is NumBase)
            {
                NumBase fromBase = (NumBase)cmbFromBase.SelectedItem;
                if (!BaseConverter.IsValidChar(e.KeyChar, fromBase))
                {
                    e.Handled = true;
                    txtBaseInput.BackColor = Color.FromArgb(254, 226, 226);
                }
                else
                {
                    txtBaseInput.BackColor = ThemeManager.Palette.InputBackground;
                }
            }
        }

        private void txtBaseInput_TextChanged(object sender, EventArgs e)
        {
            ExecuteLiveBaseConversion();
        }

        private void cmbFromBase_SelectedIndexChanged(object sender, EventArgs e)
        {
            ExecuteLiveBaseConversion();
        }

        private void cmbToBase_SelectedIndexChanged(object sender, EventArgs e)
        {
            ExecuteLiveBaseConversion();
        }

        private void btnSwapBase_Click(object sender, EventArgs e)
        {
            int temp = cmbFromBase.SelectedIndex;
            cmbFromBase.SelectedIndex = cmbToBase.SelectedIndex;
            cmbToBase.SelectedIndex = temp;
        }

        private void ExecuteLiveBaseConversion()
        {
            string input = txtBaseInput.Text.Trim();
            if (string.IsNullOrEmpty(input))
            {
                lblBaseResult.Text = "0";
                lblBinVal.Text = "0";
                lblOctVal.Text = "0";
                lblDecVal.Text = "0";
                lblHexVal.Text = "0x0";
                txtBaseInput.BackColor = ThemeManager.Palette.InputBackground;
                return;
            }

            if (cmbFromBase.SelectedItem is NumBase && cmbToBase.SelectedItem is NumBase)
            {
                NumBase fromBase = (NumBase)cmbFromBase.SelectedItem;
                NumBase toBase = (NumBase)cmbToBase.SelectedItem;

                string result;
                bool valid = BaseConverter.TryConvertBase(input, fromBase, toBase, out result);

                if (valid)
                {
                    txtBaseInput.BackColor = ThemeManager.Palette.InputBackground;
                    lblBaseResult.Text = result;

                    Dictionary<NumBase, string> all = BaseConverter.ConvertToAllBases(input, fromBase);
                    lblBinVal.Text = all[NumBase.Binary];
                    lblOctVal.Text = all[NumBase.Octal];
                    lblDecVal.Text = all[NumBase.Decimal];
                    lblHexVal.Text = all[NumBase.Hexadecimal];
                }
                else
                {
                    txtBaseInput.BackColor = Color.FromArgb(254, 226, 226);
                    lblBaseResult.Text = "---";
                }
            }
        }

        private void txtBaseInput_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                e.SuppressKeyPress = true;
                SaveBaseToHistory();
            }
        }

        private void btnSaveBaseHistory_Click(object sender, EventArgs e)
        {
            SaveBaseToHistory();
        }

        private void SaveBaseToHistory()
        {
            string input = txtBaseInput.Text.Trim();
            if (string.IsNullOrEmpty(input) || lblBaseResult.Text == "---") return;

            NumBase fromBase = (NumBase)cmbFromBase.SelectedItem;
            NumBase toBase = (NumBase)cmbToBase.SelectedItem;

            _historyManager.AddRecord("Radix Conversion", input, fromBase.ToString(), lblBaseResult.Text, toBase.ToString());
            MessageBox.Show("Base conversion saved to history!", "Saved", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnCopyBaseResult_Click(object sender, EventArgs e)
        {
            CopyText(lblBaseResult.Text);
        }

        private void btnCopyBin_Click(object sender, EventArgs e)
        {
            CopyText(lblBinVal.Text.Replace(" ", ""));
        }

        private void btnCopyOct_Click(object sender, EventArgs e)
        {
            CopyText(lblOctVal.Text);
        }

        private void btnCopyDec_Click(object sender, EventArgs e)
        {
            CopyText(lblDecVal.Text.Replace(",", ""));
        }

        private void btnCopyHex_Click(object sender, EventArgs e)
        {
            CopyText(lblHexVal.Text);
        }

        #endregion

        #region Unit Converter Logic

        private void cmbCategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            RefreshUnitDropdowns();
        }

        private void RefreshUnitDropdowns()
        {
            if (cmbCategory.SelectedItem is UnitCategory)
            {
                UnitCategory cat = (UnitCategory)cmbCategory.SelectedItem;
                List<string> units = UnitConverter.GetUnits(cat);
                cmbFromUnit.DataSource = units.ToList();
                cmbToUnit.DataSource = units.ToList();

                if (units.Count > 1) cmbToUnit.SelectedIndex = 1;
                ExecuteLiveUnitConversion();
            }
        }

        private void txtUnitInput_TextChanged(object sender, EventArgs e)
        {
            ExecuteLiveUnitConversion();
        }

        private void cmbFromUnit_SelectedIndexChanged(object sender, EventArgs e)
        {
            ExecuteLiveUnitConversion();
        }

        private void cmbToUnit_SelectedIndexChanged(object sender, EventArgs e)
        {
            ExecuteLiveUnitConversion();
        }

        private void btnSwapUnit_Click(object sender, EventArgs e)
        {
            int temp = cmbFromUnit.SelectedIndex;
            cmbFromUnit.SelectedIndex = cmbToUnit.SelectedIndex;
            cmbToUnit.SelectedIndex = temp;
        }

        private void ExecuteLiveUnitConversion()
        {
            double val;
            if (double.TryParse(txtUnitInput.Text, out val))
            {
                txtUnitInput.BackColor = ThemeManager.Palette.InputBackground;
                UnitCategory cat = (UnitCategory)cmbCategory.SelectedItem;
                string from = cmbFromUnit.SelectedItem != null ? cmbFromUnit.SelectedItem.ToString() : null;
                string to = cmbToUnit.SelectedItem != null ? cmbToUnit.SelectedItem.ToString() : null;

                if (!string.IsNullOrEmpty(from) && !string.IsNullOrEmpty(to))
                {
                    double res = UnitConverter.ConvertUnit(val, from, to, cat);
                    lblUnitResult.Text = string.Format("{0:G8} {1}", res, to.Split(' ')[0]);
                    lblFormulaBadge.Text = string.Format("1 {0} = {1:G6} {2}", from.Split(' ')[0], UnitConverter.ConvertUnit(1.0, from, to, cat), to.Split(' ')[0]);
                }
            }
            else
            {
                txtUnitInput.BackColor = string.IsNullOrEmpty(txtUnitInput.Text) ? ThemeManager.Palette.InputBackground : Color.FromArgb(254, 226, 226);
                lblUnitResult.Text = "---";
            }
        }

        private void txtUnitInput_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                e.SuppressKeyPress = true;
                SaveUnitToHistory();
            }
        }

        private void btnSaveUnitHistory_Click(object sender, EventArgs e)
        {
            SaveUnitToHistory();
        }

        private void SaveUnitToHistory()
        {
            if (lblUnitResult.Text == "---" || string.IsNullOrEmpty(txtUnitInput.Text)) return;

            string from = cmbFromUnit.SelectedItem != null ? cmbFromUnit.SelectedItem.ToString() : string.Empty;
            string to = cmbToUnit.SelectedItem != null ? cmbToUnit.SelectedItem.ToString() : string.Empty;
            string cat = cmbCategory.SelectedItem != null ? cmbCategory.SelectedItem.ToString() : string.Empty;

            _historyManager.AddRecord(cat, txtUnitInput.Text, from, lblUnitResult.Text, to);
            MessageBox.Show("Unit conversion saved to history!", "Saved", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnCopyUnitResult_Click(object sender, EventArgs e)
        {
            CopyText(lblUnitResult.Text);
        }

        #endregion

        #region History & Export Logic

        private void tabControlMain_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControlMain.SelectedIndex == 2)
            {
                RefreshHistoryGrid();
            }
        }

        private void txtSearchHistory_TextChanged(object sender, EventArgs e)
        {
            string term = txtSearchHistory.Text == "Filter history..." ? "" : txtSearchHistory.Text;
            RefreshHistoryGrid(term);
        }

        private void RefreshHistoryGrid(string filter = null)
        {
            gridHistory.Rows.Clear();
            var records = _historyManager.GetRecords(filter);

            foreach (var r in records)
            {
                gridHistory.Rows.Add(r.Timestamp.ToString("HH:mm:ss"), r.OperationType,
                    string.Format("{0} ({1})", r.SourceValue, r.SourceType),
                    string.Format("{0} ({1})", r.ResultValue, r.ResultType));
            }
        }

        private void btnExportCsv_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog sfd = new SaveFileDialog())
            {
                sfd.Filter = "CSV Spreadsheet (*.csv)|*.csv";
                sfd.FileName = "Converter_History_" + DateTime.Now.ToString("yyyyMMdd_HHmmss");

                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        _historyManager.ExportToCsv(sfd.FileName);
                        MessageBox.Show("History exported successfully!", "Export", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Export error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void btnExportJson_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog sfd = new SaveFileDialog())
            {
                sfd.Filter = "JSON Data Document (*.json)|*.json";
                sfd.FileName = "Converter_History_" + DateTime.Now.ToString("yyyyMMdd_HHmmss");

                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        _historyManager.ExportToJson(sfd.FileName);
                        MessageBox.Show("History exported successfully!", "Export", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Export error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void btnClearHistory_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to clear all history records?", "Confirm",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                _historyManager.Clear();
                RefreshHistoryGrid();
            }
        }

        private void gridHistory_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                string res = gridHistory.Rows[e.RowIndex].Cells[3].Value != null ? gridHistory.Rows[e.RowIndex].Cells[3].Value.ToString() : null;
                if (!string.IsNullOrEmpty(res)) CopyText(res);
            }
        }

        private void CopyText(string text)
        {
            if (!string.IsNullOrWhiteSpace(text) && text != "---")
            {
                Clipboard.SetText(text);
                MessageBox.Show("Copied to clipboard: " + text, "Copied", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        #endregion

        #region Theme Styling

        private void btnThemeToggle_Click(object sender, EventArgs e)
        {
            ThemeManager.ToggleTheme();
        }

        private void ApplyCurrentTheme()
        {
            Color bg = ThemeManager.Palette.WindowBackground;
            Color cardBg = ThemeManager.Palette.CardBackground;
            Color inputBg = ThemeManager.Palette.InputBackground;
            Color border = ThemeManager.Palette.BorderColor;
            Color fg = ThemeManager.Palette.TextPrimary;
            Color fgSec = ThemeManager.Palette.TextSecondary;
            Color accent = ThemeManager.Palette.Accent;

            BackColor = bg;
            ForeColor = fg;

            lblAppTitle.ForeColor = fg;
            btnThemeToggle.BackColor = cardBg;
            btnThemeToggle.ForeColor = fg;
            btnThemeToggle.FlatAppearance.BorderColor = border;
            btnThemeToggle.Text = ThemeManager.CurrentMode == ThemeMode.Dark ? "☀️ Light Mode" : "🌙 Dark Mode";

            // Tab Pages
            tabBase.BackColor = bg;
            tabUnit.BackColor = bg;
            tabHistory.BackColor = bg;

            // Panels
            pnlBaseLeft.BackColor = cardBg;
            pnlBaseRight.BackColor = cardBg;
            pnlUnitLeft.BackColor = cardBg;
            pnlUnitRight.BackColor = cardBg;
            pnlHistoryHeader.BackColor = cardBg;

            pnlBaseHero.BackColor = inputBg;
            pnlUnitHero.BackColor = inputBg;
            pnlBin.BackColor = inputBg;
            pnlOct.BackColor = inputBg;
            pnlDec.BackColor = inputBg;
            pnlHex.BackColor = inputBg;

            // Labels
            lblBaseResult.ForeColor = accent;
            lblUnitResult.ForeColor = accent;
            lblFormulaBadge.ForeColor = fgSec;
            lblLiveTitle.ForeColor = fg;
            lblUnitHeroHeading.ForeColor = fg;

            // Inputs
            txtBaseInput.BackColor = inputBg;
            txtBaseInput.ForeColor = fg;
            txtUnitInput.BackColor = inputBg;
            txtUnitInput.ForeColor = fg;
            txtSearchHistory.BackColor = inputBg;
            txtSearchHistory.ForeColor = fg;

            // Combos
            cmbFromBase.BackColor = inputBg; cmbFromBase.ForeColor = fg;
            cmbToBase.BackColor = inputBg; cmbToBase.ForeColor = fg;
            cmbCategory.BackColor = inputBg; cmbCategory.ForeColor = fg;
            cmbFromUnit.BackColor = inputBg; cmbFromUnit.ForeColor = fg;
            cmbToUnit.BackColor = inputBg; cmbToUnit.ForeColor = fg;

            // Buttons
            StyleButton(btnCopyBaseResult, accent, Color.White);
            StyleButton(btnCopyUnitResult, accent, Color.White);
            StyleButton(btnSaveBaseHistory, cardBg, fg);
            StyleButton(btnSaveUnitHistory, cardBg, fg);
            StyleButton(btnSwapBase, cardBg, fg);
            StyleButton(btnSwapUnit, cardBg, fg);
            StyleButton(btnCopyBin, cardBg, fg);
            StyleButton(btnCopyOct, cardBg, fg);
            StyleButton(btnCopyDec, cardBg, fg);
            StyleButton(btnCopyHex, cardBg, fg);
            StyleButton(btnExportCsv, cardBg, fg);
            StyleButton(btnExportJson, cardBg, fg);
            StyleButton(btnClearHistory, Color.FromArgb(239, 68, 68), Color.White);

            // Grid
            gridHistory.BackgroundColor = cardBg;
            gridHistory.DefaultCellStyle.BackColor = cardBg;
            gridHistory.DefaultCellStyle.ForeColor = fg;
            gridHistory.DefaultCellStyle.SelectionBackColor = accent;
            gridHistory.DefaultCellStyle.SelectionForeColor = Color.White;
            gridHistory.ColumnHeadersDefaultCellStyle.BackColor = inputBg;
            gridHistory.ColumnHeadersDefaultCellStyle.ForeColor = fgSec;
            gridHistory.GridColor = border;

            Refresh();
        }

        private void StyleButton(Button btn, Color bg, Color fg)
        {
            btn.BackColor = bg;
            btn.ForeColor = fg;
            btn.FlatAppearance.BorderColor = ThemeManager.Palette.BorderColor;
        }

        #endregion
    }
}