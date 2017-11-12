using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using LibraryManagerBLL;
using LibraryManagerModels;

namespace LibraryManager
{
    public partial class FormUser : Form
    {
        private FormUser()
        {
            InitializeComponent();
        }
        static FormUser fu;
        public static FormUser CreateForm()
        {
            if (fu==null)
            {
                fu = new FormUser();
                fu.TopMost = true;
            }
            return fu;
        }
        UsersManager um;
        Users u = new Users();
        private void FormUser_Load(object sender, EventArgs e)
        {
            um = new UsersManager();
            cboType.DataSource = um.GetRolesMess();
            cboType.DisplayMember = "RolesName";
            cboType.ValueMember = "RolesID";
        }

        private void txtType_MouseDown(object sender, MouseEventArgs e)
        {
            cboType.Visible = true;
        }

        private void txtSex_MouseDown(object sender, MouseEventArgs e)
        {
            cboSex.Visible = true;
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            string mess = "";
            if (this.Text=="����Ա����Ϣ")
            {
                if (txtUID.Text=="")
                {
                    MessageBox.Show("������Ա���ʺţ�","��ʾ",MessageBoxButtons.OK,MessageBoxIcon.Information);
                    txtUID.Focus();
                    return;
                }
                if (txtPWD.Text=="")
                {
                    MessageBox.Show("������Ա�����룡", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    txtPWD.Focus();
                    return;
                }
                if (txtPWDS.Text == "")
                {
                    MessageBox.Show("��ȷ�����룡", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    txtPWDS.Focus();
                    return;
                }
                if (txtPWD.Text!=txtPWDS.Text)
                {
                    MessageBox.Show("�����������벻һ�£�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    txtPWDS.Focus();
                    return;
                }
                if (cboSex.Text=="")
                {
                    MessageBox.Show("��ѡ���Ա�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    cboSex.Focus();
                    return;
                }
                if (txtUserName.Text=="")
                {
                    MessageBox.Show("������Ա��������", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    cboSex.Focus();
                    return;
                }
                mess = um.AddUsersMess(IniUsers(),txtUID.Text);
            }
            else
            {
                if (txtPWD.Text != txtPWDS.Text)
                {
                    MessageBox.Show("�����������벻һ�£�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    txtPWDS.Focus();
                    return;
                }
                mess = um.UpdateUsers(IniUsers());
            }
            if (mess == "Ա����Ϣ��ӳɹ���"||mess == "Ա����Ϣ�޸ĳɹ���")
            {
                MessageBox.Show(mess, "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
            else
            {
                MessageBox.Show(mess, "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public Users IniUsers()
        {
            int id = -1;
            if (txtID.Text == "")
                id = 0;
            else
                id = Convert.ToInt32(txtID.Text);
            u.UserID = id;
            u.UserUID = txtUID.Text;
            u.UserPwd = txtPWD.Text;
            u.UserName = txtUserName.Text;
            u.RoleID = Convert.ToInt32(cboType.SelectedValue);
            u.RolesName = cboType.Text;
            u.UserSex = cboSex.Text;
            return u;
        }

        private void btnJianCe_Click(object sender, EventArgs e)
        {
            if (txtUID.Text=="")
            {
                MessageBox.Show("û����Ҫ������Ϣ","��ʾ",MessageBoxButtons.OK,MessageBoxIcon.Exclamation);
            }
            else
            {
                string mess = um.JudgeUser(txtUID.Text);
                lblJianCe.Text = mess;
            }
        }

        private void FormUser_FormClosed(object sender, FormClosedEventArgs e)
        {
            fu = null;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }
}