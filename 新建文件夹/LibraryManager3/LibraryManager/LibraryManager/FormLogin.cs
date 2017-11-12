using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Threading;
using LibraryManagerBLL;
using LibraryManagerModels;

namespace LibraryManager
{
    public partial class FormLogin : Form
    {
        public FormLogin()
        {
            InitializeComponent();
        }
        UsersManager um;
        private void btnCancel_Click(object sender, EventArgs e)
        {
             Application.Exit();
        }

        private void FormLogin_Load(object sender, EventArgs e)
        {
            //this.TopLevel = false;
            um = new UsersManager();
            cboType.DataSource = um.GetRolesMess();
            cboType.DisplayMember = "RolesName";
            cboType.ValueMember = "RolesID";
        }

        private void FormLogin_FormClosing(object sender, FormClosingEventArgs e)
        {
            //Application.Exit();
        }
        //重置按钮
        private void btnReset_Click(object sender, EventArgs e)
        {
            cboType.SelectedIndex = 0;
            txtID.Text = "";
            txtPWD.Text = "";
        }

        private void btnLogin_Click(object sender, EventArgs e)
        
        {
            if (cboType.Text=="")
            {
                MessageBox.Show("请选择用户类型！", "提 示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                cboType.Focus();
            }
            else if (txtID.Text=="")
            {
                MessageBox.Show("请输入帐号!", "提 示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtID.Focus();
            }
            else if (txtPWD.Text=="")
            {
                MessageBox.Show("请输入密码!", "提 示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtPWD.Focus();
            }
            else
            {
                string mess = um.JudgeLogin(txtID.Text,txtPWD.Text,Convert.ToInt32(cboType.SelectedValue));
                MessageBox.Show(mess,"提示",MessageBoxButtons.OK,MessageBoxIcon.Information);
                if (mess=="登录成功！")
                {
                    UserHelp.UserUID = txtID.Text;
                    UserHelp.UserPWD = txtPWD.Text;

                    FormMain fm = new FormMain();
                    fm.Tag = cboType.Text+":"+um.GetUserNameBuUID(txtID.Text);
                    //fm.Owner = this;
                   
                    fm.Show();
                    this.Close();
                }
            }
        }

        //软键盘点击事件
        private void picSKB_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process _Process = System.Diagnostics.Process.Start(@"C:\Windows\System32\osk.exe");
            txtPWD.Focus();
        }

        private void txtType_MouseDown(object sender, MouseEventArgs e)
        {
            cboType.Visible = true;
        }
    }
}