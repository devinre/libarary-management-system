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
    public partial class FormUserTable : Form
    {
        private FormUserTable()
        {
            InitializeComponent();
        }
        static FormUserTable fu;
        IList<UserTable> ilUT;
        UserTableManager utm = new UserTableManager();
        UserTable ut = new UserTable();
        //���ڱ�����DGVʱ����ȡ��ֵ
        int index;
        public static FormUserTable CreateForm()
        {
            if (fu==null)
            {
                fu = new FormUserTable();
                fu.TopMost = true;
            }
            return fu;
        }
        /// <summary>
        /// ������Աʵ��
        /// </summary>
        /// <returns></returns>
        public UserTable CreateUserMess()
        {
            ut.UserName = txtUserName.Text;
            ut.UserSex = rdoF.Checked ? "Ů" : "��";
            ut.UserTel = txtUserTel.Text;
            ut.UserBrith = Convert.ToDateTime(dtpUserBirth.Text);
            ut.UserMoney = Convert.ToDouble(txtUserMoney.Text);
            ut.UserDate = Convert.ToDateTime(dtpUserDate.Text);
            ut.CardTypeID = Convert.ToInt32(cboCardType.SelectedValue);
            if (txtUserID.Text != "")
                ut.UserID = Convert.ToInt32(txtUserID.Text);
            else
                ut.UserID = 0;
            return ut;
        }

        private void FormUser_FormClosed(object sender, FormClosedEventArgs e)
        {
            fu = null;
        }

        private void FormUser_Load(object sender, EventArgs e)
        {
            dtpSearch.Visible = false;
            txtSearch.Visible = true;
            this.Size = new Size(684, 326);
            ilUT = new List<UserTable>();
            ilUT = utm.GetUserMess();
            dgvUserTable.DataSource = ilUT;
            cboCardType.DataSource = utm.GetCardType();
            cboCardType.DisplayMember = "CardName";
            cboCardType.ValueMember = "CardTypeID";
            //�����ؼ�
            foreach (Control v in this.Controls)
            {
                ToolStrip btn = v as ToolStrip;
                if (btn != null)
                {
                    foreach (ToolStripButton v1 in btn.Items)
                    {
                        if (v1 is ToolStripButton)
                        {
                            v1.Enabled = false;
                            foreach (int var in UserHelp.FunctionID)
                            {
                                if (Convert.ToInt32(v1.Tag) == var || Convert.ToInt32(v1.Tag) == 0)
                                {
                                    v1.Enabled = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        /// <summary>
        /// ��ѯ
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (cboSearch.Text=="ȫ��")
            {
                ilUT = utm.GetUserMess();
                dgvUserTable.DataSource = ilUT;
            }
            else if (cboSearch.Text == "����Ա��" || cboSearch.Text == "����Ա����")
            {
                ilUT = utm.GetUserMess(cboSearch.Text, txtSearch.Text);
                dgvUserTable.DataSource = ilUT;
            }
            else
            {
                ilUT = utm.GetUserMess(cboSearch.Text, dtpSearch.Text);
                dgvUserTable.DataSource = ilUT;
            }

        }
        /// <summary>
        /// ��Ϣ�б�ĵ���¼�
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dgvUserTable_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            this.Size = new Size(684, 439);
            txtUserName.Enabled = false;
            plSex.Enabled = false;
            txtUserTel.Enabled = false;
            dtpUserBirth.Enabled = false;
            txtUserMoney.Enabled = false;
            dtpUserDate.Enabled = false;
            cboCardType.Enabled = false;
            try
            {
                index = Convert.ToInt32(dgvUserTable.SelectedRows[0].Index);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }            
            ShowUserMess();
        }
        /// <summary>
        /// ��ʾ��Ա��Ϣ
        /// </summary>
        private void ShowUserMess()
        {
            txtUserID.Text = ilUT[index].UserID.ToString();
            txtUserName.Text = ilUT[index].UserName;
            if (ilUT[index].UserSex == "��")
                rdoM.Checked = true;
            else
                rdoF.Checked = true;
            txtUserTel.Text = ilUT[index].UserTel.ToString();
            dtpUserBirth.Text = ilUT[index].UserBrith.ToString();
            txtUserMoney.Text = ilUT[index].UserMoney.ToString();
            dtpUserDate.Text = ilUT[index].UserDate.ToString();
            cboCardType.Text = ilUT[index].CardName;
        }
        /// <summary>
        /// ȡ����ť
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbtnCancel_Click(object sender, EventArgs e)
        {
            this.Size = new Size(684, 326);
        }
        /// <summary>
        /// ��Ӱ�ť
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbtnAdd_Click(object sender, EventArgs e)
        {
            this.Size = new Size(684, 439);
            Clear();
            txtUserName.Enabled = true;
            plSex.Enabled = true;
            txtUserTel.Enabled = true;
            dtpUserBirth.Enabled = true;
            txtUserMoney.Enabled = true;
            dtpUserDate.Enabled = true;
            cboCardType.Enabled = true;
        }
        /// <summary>
        /// �޸İ�ť
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbtnUpdate_Click(object sender, EventArgs e)
        {
            this.Size = new Size(684, 439);
            txtUserName.Enabled = true;
            plSex.Enabled = true;
            txtUserTel.Enabled = true;
            dtpUserBirth.Enabled = true;
            txtUserMoney.Enabled = true;
            dtpUserDate.Enabled = true;
            cboCardType.Enabled = true;
            ShowUserMess();
        }
        /// <summary>
        /// ɾ����ť
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbtnDelete_Click(object sender, EventArgs e)
        {
            if (dgvUserTable.SelectedRows.Count!=0)
            {
                DialogResult r = MessageBox.Show("ȷ��Ҫɾ������Ϣ��","��ʾ",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
                if (r==DialogResult.Yes)
                {
                    string mess = utm.DeleteUser(CreateUserMess());
                    MessageBox.Show(mess, "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    ilUT = utm.GetUserMess();
                    dgvUserTable.DataSource = ilUT;
                    index = 0;
                }
            }
            else
            {
                MessageBox.Show("��ѡ����Ҫɾ������Ϣ��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void tsbtnSave_Click(object sender, EventArgs e)
        {
            if (txtUserID.Text=="")
            {
                if (txtUserName.Text==""||txtUserTel.Text==""||txtUserMoney.Text=="")
                {
                    MessageBox.Show("������������Ϣ�Ա���ӣ�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    string mess = utm.AddNewUser(CreateUserMess());
                    MessageBox.Show(mess);
                    ilUT = utm.GetUserMess();
                    dgvUserTable.DataSource = ilUT;
                    if (mess == "��Ա��ӳɹ�")
                        Clear();
                }
            }
            else
            {
                if (txtUserName.Text == "" || txtUserTel.Text == "" || txtUserMoney.Text == "")
                {
                    MessageBox.Show("������������Ϣ��", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    string mess = utm.UpdateUser(CreateUserMess());
                    MessageBox.Show(mess);
                    ilUT = utm.GetUserMess();
                    dgvUserTable.DataSource = ilUT;
                }
            }
        }

        public void Clear()
        {
            txtUserID.Text = "";
            txtUserName.Text = "";
            txtUserTel.Text = "";
            txtUserMoney.Text = "";
            cboCardType.SelectedIndex = 0;
        }

        private void cboSearch_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cboSearch.Text=="ȫ��")
            {
                dtpSearch.Visible = false;
                txtSearch.Visible = true;
                txtSearch.Enabled = false;
                txtSearch.Text = "";
            }
            else if (cboSearch.Text == "����Ա��" || cboSearch.Text == "����Ա����")
            {
                dtpSearch.Visible = false;
                txtSearch.Visible = true;
                txtSearch.Enabled = true;
                txtSearch.Text = "";
            }
            else if (cboSearch.Text == "����Ա����" || cboSearch.Text == "������ʱ��")
            {
                txtSearch.Visible = false;
                dtpSearch.Visible = true;
                txtSearch.Text = "";
            }
        }

        private void tsbtnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void tsmiAddMoney_Click(object sender, EventArgs e)
        {
            FormAddMoney fa = new FormAddMoney();
            if (dgvUserTable.SelectedRows.Count!=0)
            {
                fa.Tag = dgvUserTable.SelectedRows[0].Cells[0].Value;
                fa.ShowDialog();
                ilUT = utm.GetUserMess();
                dgvUserTable.DataSource = ilUT;
            }
        }
    }
}