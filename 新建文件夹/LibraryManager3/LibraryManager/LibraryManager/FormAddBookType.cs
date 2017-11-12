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
    public partial class FormAddBookType : Form
    {
        public FormAddBookType()
        {
            InitializeComponent();
        }
        BookTypeManager btm = new BookTypeManager();
        private void btnSave_Click(object sender, EventArgs e)
        {
            if (txtBookType.Text=="")
            {
                MessageBox.Show("请填写类型名称！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else
            {
                MessageBox.Show(btm.AddNewBookType(IniBookType()), "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public BookType IniBookType()
        {
            BookType bt = new BookType();
            bt.TypeName = txtBookType.Text;
            return bt;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}