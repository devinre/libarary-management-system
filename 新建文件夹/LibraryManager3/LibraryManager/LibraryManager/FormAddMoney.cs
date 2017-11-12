using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using LibraryManagerBLL;

namespace LibraryManager
{
    public partial class FormAddMoney : Form
    {
        public FormAddMoney()
        {
            InitializeComponent();
        }
        UserTableManager ut = new UserTableManager();
        private void btnOK_Click(object sender, EventArgs e)
        {
            if (txtMoney.Text=="")
            {
                MessageBox.Show("请填写充值金额！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else
            {
                string mess = ut.UpdateUserMoney(Convert.ToDouble(txtMoney.Text),
                                                Convert.ToInt32(this.Tag));
                MessageBox.Show(mess, "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}