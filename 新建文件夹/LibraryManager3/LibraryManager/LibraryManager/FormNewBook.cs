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
    public partial class FormNewBook : Form
    {
        public FormNewBook()
        {
            InitializeComponent();
        }
        BookManager bm = new BookManager();
        BookTypeManager btm = new BookTypeManager();
        BookStateManager bsm = new BookStateManager();
        private void FormAddNewBook_Load(object sender, EventArgs e)
        {
            txtBookID.Enabled = false;
            cboBookType.DataSource = btm.GetBookType();
            cboBookType.DisplayMember = "TypeName";
            cboBookType.ValueMember = "TypeID";
            cboState.DataSource = bsm.GetBookState();
            cboState.DisplayMember = "State";
            cboState.ValueMember = "StateID";
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            if (txtBookName.Text==""||txtBookPrice.Text==""||txtPublish.Text=="")
            {
                MessageBox.Show("����д������Ϣ��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else if (cboState.SelectedIndex==1)
            {
                MessageBox.Show("δ��ӵ�ͼ����ʱ���ܳ��⣡", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else
            {
                string mess="";
                if (this.Text=="ͼ������")
                {
                    mess = bm.AddNewBook(IniBook());
                }
                else if (this.Text=="ͼ���޸�")
                {
                    mess = bm.UpdateBook(IniBook());
                }
                MessageBox.Show(mess, "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtBookName.Text = "";
                txtBookPrice.Text = "";
                txtPublish.Text = "";
            }
        }
        /// <summary>
        /// ����ͼ��ʵ��
        /// </summary>
        /// <returns></returns>
        public Books IniBook()
        {
            Books book = new Books();
            book.BookID = Convert.ToInt32(this.Tag);
            book.BookName = txtBookName.Text;
            book.TypeID=Convert.ToInt32(cboBookType.SelectedValue);
            book.TypeName = cboBookType.Text;
            book.Price = Convert.ToDouble(txtBookPrice.Text);
            book.Publish = txtPublish.Text;
            book.StateID = Convert.ToInt32(cboState.SelectedValue);
            book.State = cboState.Text;
            return book;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}