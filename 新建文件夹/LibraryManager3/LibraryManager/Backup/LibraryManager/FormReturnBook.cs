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
    public partial class FormReturnBook : Form
    {
        private FormReturnBook()
        {
            InitializeComponent();
        }
        static FormReturnBook fr;
        IList<BooksDeal> il = new List<BooksDeal>();
        BookDealManager bdm = new BookDealManager();
        BookManager bm = new BookManager();
        public static FormReturnBook CreateForm()
        {
            if (fr==null)
            {
                fr = new FormReturnBook();
                fr.TopMost = true;
            }
            return fr;
        }

        private void FormReturnBook_FormClosed(object sender, FormClosedEventArgs e)
        {
            fr = null;
        }

        private void FormReturnBook_Load(object sender, EventArgs e)
        {
            il = bdm.GetBookMess();
            FillListView();
        }

        private void FillListView()
        {
            lvBookMess.Items.Clear();
            foreach (BooksDeal var in il)
            {
                ListViewItem lviMess = new ListViewItem();
                lviMess.Text = var.Book.BookName;
                lviMess.SubItems.Add(var.YaJin.ToString());
                lviMess.SubItems.Add(var.ZuJin.ToString());
                lviMess.SubItems.Add(var.Book.Price.ToString());
                lviMess.SubItems.Add(var.DealDate.ToString());
                lviMess.Tag = var.Book.BookName;
                lvBookMess.Items.Add(lviMess);
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (txtBookName.Text!="")
            {
                il=bdm.GetBookMessByName(txtBookName.Text);
                FillListView();
            }
            else
            {
                il = bdm.GetBookMess();
                FillListView();
            }
        }

        private void btnReturn_Click(object sender, EventArgs e)
        {
            if (lvBookMess.SelectedItems.Count==0)
            {
                MessageBox.Show("请选择你要归还的图书！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                string name = lvBookMess.SelectedItems[0].Tag.ToString();
                int bookID = bm.GetBookIDByName(name);
                double lendPrice = 0d;
                double zujin = bdm.GetZuJin(bookID, out lendPrice);
                string mess = bdm.ReturnBook(name) + "租金：" + zujin.ToString()+"元"+" " +
                                "额外费用：" + lendPrice.ToString()+"元";
                MessageBox.Show(mess, "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                il = bdm.GetBookMess();
                FillListView();
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}