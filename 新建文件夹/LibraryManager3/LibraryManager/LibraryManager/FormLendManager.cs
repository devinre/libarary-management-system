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
        /// ����رպ��¼�
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
            if (cboSearch.Text=="ͼ������")
            {
                cboBookType.Visible = true;
                txtSearch.Enabled = false;
            }
            else if (cboSearch.Text=="ȫ��")
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
            if (cboSearch.Text=="ȫ��")
            {
                il = bm.GetAllBook();
            }
            else if (cboSearch.Text=="ͼ������")
            {
                if (txtSearch.Text=="")
                    il = bm.GetAllBook();
                il = bm.GetBookMessByName(txtSearch.Text);
            }
            else if (cboSearch.Text=="ͼ������")
            {
                il = bm.GetBookMessByTypeID(Convert.ToInt32(cboBookType.SelectedValue));
            }
            else if (cboSearch.Text=="����")
            {
                id = 1;
                il = bm.GetBookByState(id, txtSearch.Text);
            }
            else if (cboSearch.Text=="���")
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
                MessageBox.Show("��ѡ����Ҫ����ͼ�飡", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (cboIsVIP.Text=="")
            {
                MessageBox.Show("��ѡ���Ƿ�Ϊ��Ա��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                if (cboIsVIP.Text=="��Ա")
                {
                    if (txtUserID.Text == "")
                    {
                        MessageBox.Show("�������Ա���ţ�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
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
                            MessageBox.Show("��Ա�ű���Ϊ���֣�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            return;
                        }
                        if (!bdm.JudgeUser(id))
                        {
                            MessageBox.Show("�˻�Ա�����ڣ����������룡", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            txtUserID.Focus();
                            return;
                        }
                    }
                }
                else
                {
                    if (txtMoeny.Text=="")
                        MessageBox.Show("������Ѻ��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    else
                    {
                        try
                        {
                            yajin = Convert.ToDouble(txtMoeny.Text);
                        }
                        catch (Exception)
                        {
                            MessageBox.Show("����ȷ����Ѻ��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                            return;
                        }
                        if (yajin < 100)
                        {
                            MessageBox.Show("Ѻ�𲻵õ���100Ԫ��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            return;
                        }
                    }
                }
                MessageBox.Show(bdm.AddBookDeal(IniBookDeal()), "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                il = bm.GetAllBook();
                dgvBookMess.DataSource = il;
            }
        }
        /// <summary>
        /// ����ʵ��
        /// </summary>
        /// <returns></returns>
        public BooksDeal IniBookDeal()
        {
            int uid = -1;
            double price = 0d;
            if (cboIsVIP.Text == "��Ա")
            {
                try
                {
                    uid = Convert.ToInt32(txtUserID.Text);
                }
                catch (Exception)
                {
                    MessageBox.Show("ID���������", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Error);
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