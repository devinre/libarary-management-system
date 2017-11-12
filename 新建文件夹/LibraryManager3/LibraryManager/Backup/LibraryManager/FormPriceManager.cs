using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using LibraryManagerModels;
using LibraryManagerBLL;

namespace LibraryManager
{
    public partial class FormPriceManager : Form
    {
        private FormPriceManager()
        {
            InitializeComponent();
        }
        static FormPriceManager fp;
        BookPriceManager bpm;
        IList<BooksPrice> il = new List<BooksPrice>();
        BooksPrice bp = new BooksPrice();
        //用于保存DGV中的值
        int index;
        public static FormPriceManager CreateForm()
        {
            if (fp==null)
            {
                fp = new FormPriceManager();
            }
            return fp;
        }

        private void FormPriceManager_FormClosed(object sender, FormClosedEventArgs e)
        {
            fp = null;
        }

        private void FormPriceManager_Load(object sender, EventArgs e)
        {
            bpm = new BookPriceManager();
            il = bpm.GetBookPrice();
            dgvBookPrice.DataSource = il;
            foreach (Control v in this.Controls)
            {
                Button btn = v as Button;
                if (btn != null)
                {
                    btn.Enabled = false;
                    foreach (int var in UserHelp.FunctionID)
                    {
                        if (Convert.ToInt32(btn.Tag) == var || Convert.ToInt32(btn.Tag) == 0)
                        {
                            btn.Enabled = true;
                        }
                    }
                }
            }
        }

        private void dgvBookPrice_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (dgvBookPrice.SelectedRows.Count != 0)
            {
                index = dgvBookPrice.SelectedRows[0].Index;
                txtPriceUp.Text = il[index].BookUpPrice.ToString();
                txtPriceDown.Text = il[index].BookDownPrice.ToString();
                txtZuJin.Text = il[index].BookPrice.ToString();
                txtDay.Text = il[index].BackDate.ToString();
            }
        }
        /// <summary>
        /// 创建实体
        /// </summary>
        /// <returns></returns>
        public BooksPrice IniBookPrice()
        {
            bp.BookPriceID = Convert.ToInt32(dgvBookPrice.SelectedRows[0].Cells[0].Value);
            bp.BookUpPrice = Convert.ToDouble(txtPriceUp.Text);
            bp.BookDownPrice = Convert.ToDouble(txtPriceDown.Text);
            bp.BookPrice = Convert.ToDouble(txtZuJin.Text);
            bp.BackDate = Convert.ToInt32(txtDay.Text);
            return bp;
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (txtPriceUp.Text==""||txtPriceDown.Text==""||txtDay.Text==""||txtZuJin.Text=="")
            {
                MessageBox.Show("请填写完整信息！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                string mess = bpm.UpdateBookPrice(IniBookPrice());
                MessageBox.Show(mess,"提示",MessageBoxButtons.OK,MessageBoxIcon.Information);
                il = bpm.GetBookPrice();
                dgvBookPrice.DataSource = il;
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}