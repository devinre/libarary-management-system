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
    public partial class FormUserManager : Form
    {
        private FormUserManager()
        {
            InitializeComponent();
        }
        static FormUserManager fu;
        public static FormUserManager CreateForm()
        {
            if (fu == null)
            {
                fu = new FormUserManager();
                fu.TopMost = true;
            }
            return fu;
        }
        UsersManager um;
        IList<Users> il = new List<Users>();
        private void FormEmpShow_Load(object sender, EventArgs e)
        {
            um = new UsersManager();
            il = um.GetAllUsers();
            dgvMess.DataSource = il;

            foreach (Control v in this.Controls)
            {
                ToolStrip btn = v as ToolStrip;
                if (btn != null)
                {
                    foreach (object  v1 in btn.Items)
                    {                       
                        ToolStripButton vv=v1 as ToolStripButton;
                        if (vv != null)
                        {
                            if (v1 is ToolStripButton)
                            {
                                vv.Enabled = false;
                                foreach (int var in UserHelp.FunctionID)
                                {
                                    if (Convert.ToInt32(vv.Tag) == var || Convert.ToInt32(vv.Tag) == 0)
                                    {
                                        vv.Enabled = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        private void tsbtnAdd_Click(object sender, EventArgs e)
        {
            FormUser fu = FormUser.CreateForm();
            fu.Text = "����Ա����Ϣ";
            fu.Show();
            fu.BringToFront();
        }

        private void tsbtnUpdate_Click(object sender, EventArgs e)
        {
            FormUser fu = FormUser.CreateForm();
            if (dgvMess.SelectedRows.Count!=0)
            {
                fu.Text = "�޸�Ա����Ϣ";
                Users u = dgvMess.SelectedRows[0].DataBoundItem as Users;
                fu.txtID.Text = u.UserID.ToString();
                fu.txtUID.Text = u.UserUID;
                fu.txtPWD.Text = u.UserPwd.ToString();
                fu.txtUserName.Text = u.UserName;
                fu.cboType.Text = u.RolesName;
                fu.cboSex.Text = u.UserSex;
                fu.btnJianCe.Enabled = false;
                fu.lblJianCe.Enabled = false;
                fu.Show();
                fu.BringToFront();
            }
            else
            {
                MessageBox.Show("û��ѡ����Ҫ�޸ĵ���Ϣ��");
            }
        }
        //ˢ��
        private void tsbtnShuXin_Click(object sender, EventArgs e)
        {
            il = um.GetAllUsers();
            dgvMess.DataSource = il;
        }

        private void FormUserManager_FormClosed(object sender, FormClosedEventArgs e)
        {
            fu = null;
        }

        private void tsbtnDelete_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("ȷ��Ҫɾ������Ϣ��","��ʾ",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
            if (dgvMess.SelectedRows.Count==0)
            {
                MessageBox.Show("��ѡ����Ҫɾ������Ϣ��","��ʾ",MessageBoxButtons.OK,MessageBoxIcon.Information);
            }
            else
            {
                if (r==DialogResult.Yes)
                {
                    //ɾ����Ϣ
                    string mess=um.DeleteUserMess(Convert.ToInt32(dgvMess.SelectedRows[0].Cells[0].Value));
                    MessageBox.Show(mess,"��ʾ",MessageBoxButtons.OK,MessageBoxIcon.Information);
                    il = um.GetAllUsers();
                    dgvMess.DataSource = il;
                }
            }
        }
        
        private void tsbtnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}