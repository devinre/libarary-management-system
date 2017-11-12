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
    public partial class FormUpdataPWD : Form
    {
        private FormUpdataPWD()
        {
            InitializeComponent();
        }
        static FormUpdataPWD fu;
        UsersManager um;
        public static FormUpdataPWD CreateForm()
        {
            if (fu==null)
            {
                fu = new FormUpdataPWD();
                fu.TopMost = true;
            }
            return fu;
        }

        private void FormUpdataPWD_Load(object sender, EventArgs e)
        {
            um = new UsersManager();
            lblUsers.Text = UserHelp.UserUID;
            txtPWD.Text = UserHelp.UserPWD;
            txtNewPWD.Focus();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            if (txtNewPWD.Text=="")
            {
                MessageBox.Show("请输入新密码！","提示",MessageBoxButtons.OK,MessageBoxIcon.Information);
                txtNewPWD.Focus();
                return;
            }
            if (txtNewPWDS.Text=="")
            {
                MessageBox.Show("请验证新密码！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtNewPWDS.Focus();
                return;
            }
            if (txtNewPWD.Text!=txtNewPWDS.Text)
            {
                MessageBox.Show("两次密码输入不一致！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtNewPWDS.Focus();
                return;
            }
            string mess = um.UpdateUserPWD(txtNewPWD.Text, lblUsers.Text);
            MessageBox.Show(mess,"提示",MessageBoxButtons.OK,MessageBoxIcon.Information);
            this.Close();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void FormUpdataPWD_FormClosed(object sender, FormClosedEventArgs e)
        {
            fu = null;
        }

    }
}