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
    public partial class FormBookMess : Form
    {
        private FormBookMess()
        {
            InitializeComponent();
        }
        static FormBookMess fb;
        IList<Books> il = new List<Books>();
        BookManager bm;
        BookTypeManager btm = new BookTypeManager();
        public static FormBookMess CreateForm()
        {
            if (fb == null)
            {
                fb = new FormBookMess();
                fb.TopMost = true;
            }
            return fb;
        }

        private void FormBookMess_FormClosed(object sender, FormClosedEventArgs e)
        {
            fb = null;
        }

        private void FormBookMess_Load(object sender, EventArgs e)
        {
            bm = new BookManager();
            il = bm.GetAllBook();
            dgvBookMess.DataSource = il;
            cboBookType.DataSource = btm.GetBookType();
            cboBookType.DisplayMember = "TypeName";
            cboBookType.ValueMember = "TypeID";
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (txtSearch.Text=="")
                il = bm.GetBookMessByTypeID(Convert.ToInt32(cboBookType.SelectedValue));
            else
                il = bm.GetBookByBookName(Convert.ToInt32(cboBookType.SelectedValue), txtSearch.Text);
            dgvBookMess.DataSource = il;
        }
    }
}