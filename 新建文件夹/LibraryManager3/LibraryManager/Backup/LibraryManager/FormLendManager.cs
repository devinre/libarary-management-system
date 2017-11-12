using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using LibraryManagerBLL;
using LibraryManagerModels;

namespace LibraryManager
{
    public partial class FormLendManager : Form
    {
        private FormLendManager()
        {
            InitializeComponent();
        }
        BookManager bm = new BookManager();
        BookTypeManager btm = new BookTypeManager();
        BookDealManager bdm = new BookDealManager();
        IList<Books> il;
        int index;
        BooksDeal bd = new BooksDeal();
        static FormLendManager fl;
        public static FormLendManager CreateForm()
        {
            if (fl==null)
            {
                fl = new FormLendManager();
                fl.TopMost = true;
            }
            return fl;
        }
        /// <summary>
        /// 窗体关闭后事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void FormLendManager_FormClosed(object sender, FormClosedEventArgs e)
        {
            fl = null;
        }

        private void FormLendManager_Load(object sender, EventArgs e)
        {
            this.Size = new Size(614, 299);
            cboBookType.Visible = false;
            txtSearch.Enabled = true;
            il = new List<Books>();
            il = bm.GetAllBook();
            dgvBookMess.DataSource = il;
            cboBookType.DataSource = btm.GetBookType();
            cboBookType.DisplayMember = "TypeName";
            cboBookType.ValueMember = "TypeID";
        }

        private void btnLend_Click(object sender, EventArgs e)
        {
            this.Size = new Size(614, 380);
        }

        private void cboIsVIP_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cboIsVIP.SelectedIndex==0)
            {
                txtUserID.Enabled = true;
                txtMoeny.Enabled = false;
            }
            else if (cboIsVIP.SelectedIndex==1)
            {
                txtUserID.Enabled = false;
                txtMoeny.Enabled = true;
            }
        }

        private void cboSearch_SelectedIndexChanged(object sender, EventArgs e)
        {
            txtSearch.Text = "";
            if (cboSearch.Text=="图书类型")
            {
                cboBookType.Visible = true;
                txtSearch.Enabled = false;
            }
            else if (cboSearch.Text=="全部")
            {
                cboBookType.Visible = false;
                txtSearch.Enabled = false;
            }
            else
            {
                cboBookType.Visible = false;
                txtSearch.Enabled = true;
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            int id=-1;
            if (cboSearch.Text=="全部")
            {
                il = bm.GetAllBook();
            }
            else if (cboSearch.Text=="图书名称")
            {
                if (txtSearch.Text=="")
                    il = bm.GetAllBook();
                il = bm.GetBookMessByName(txtSearch.Text);
            }
            else if (cboSearch.Text=="图书类型")
            {
                il = bm.GetBookMessByTypeID(Convert.ToInt32(cboBookType.SelectedValue));
            }
            else if (cboSearch.Text=="正常")
            {
                id = 1;
                il = bm.GetBookByState(id, txtSearch.Text);
            }
            else if (cboSearch.Text=="借出")
            {
                id = 2;
                il = bm.GetBookByState(id, txtSearch.Text); 
            }
            dgvBookMess.DataSource = il;
        }

        private void dgvBookMess_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (dgvBookMess.SelectedRows.Count != 0)
            {
                index = Convert.ToInt32(dgvBookMess.SelectedRows[0].Index);
                txtBookName.Text = il[index].BookName.ToString();
            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            double yajin = 0d;
            double price = bm.GetBookPriceByName(txtBookName.Text);
            int id = -1;
            if (txtBookName.Text=="")
            {
                MessageBox.Show("请选择你要租借的图书！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (cboIsVIP.Text=="")
            {
                MessageBox.Show("请选择是否为会员！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                if (cboIsVIP.Text=="会员")
                {
                    if (txtUserID.Text == "")
                    {
                        MessageBox.Show("请输入会员卡号！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        return;
                    }
                    else
                    {
                        try
                        {
                            id = Convert.ToInt32(txtUserID.Text);
                        }
                        catch (Exception)
                        {
                            MessageBox.Show("会员号必须为数字！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            return;
                        }
                        if (!bdm.JudgeUser(id))
                        {
                            MessageBox.Show("此会员不存在，请重新输入！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            txtUserID.Focus();
                            return;
                        }
                    }
                }
                else
                {
                    if (txtMoeny.Text=="")
                        MessageBox.Show("请输入押金！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    else
                    {
                        try
                        {
                            yajin = Convert.ToDouble(txtMoeny.Text);
                        }
                        catch (Exception)
                        {
                            MessageBox.Show("请正确输入押金！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                            return;
                        }
                        if (yajin < 100)
                        {
                            MessageBox.Show("押金不得低于100元！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            return;
                        }
                    }
                }
                MessageBox.Show(bdm.AddBookDeal(IniBookDeal()), "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                il = bm.GetAllBook();
                dgvBookMess.DataSource = il;
            }
        }
        /// <summary>
        /// 创建实体
        /// </summary>
        /// <returns></returns>
        public BooksDeal IniBookDeal()
        {
            int uid = -1;
            double price = 0d;
            if (cboIsVIP.Text == "会员")
            {
                try
                {
                    uid = Convert.ToInt32(txtUserID.Text);
                }
                catch (Exception)
                {
                    MessageBox.Show("ID号输入错误！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                price = 0d;
            }
            else
            {
                uid = 10000;
                price = Convert.ToDouble(txtMoeny.Text);
            }
            bd.UserID = uid;
            bd.BookName = txtBookName.Text;
            bd.BookID = bm.GetBookIDByName(txtBookName.Text);
            bd.DealDate = Convert.ToDateTime(dtpDealDate.Text);
            bd.PriceID = bdm.GetPriceID(txtBookName.Text);
            bd.BookLendPrice = 0d;
            bd.BackDate = Convert.ToDateTime(dtpBackDate.Text);
            bd.YaJin = price;
            bd.Book.Price = bm.GetBookPriceByName(txtBookName.Text);
            return bd;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}