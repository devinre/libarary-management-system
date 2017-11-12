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
        //用于保存点击DGV时所获取的值
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
        /// 创建会员实体
        /// </summary>
        /// <returns></returns>
        public UserTable CreateUserMess()
        {
            ut.UserName = txtUserName.Text;
            ut.UserSex = rdoF.Checked ? "女" : "男";
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
            //遍历控件
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
        /// 查询
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (cboSearch.Text=="全部")
            {
                ilUT = utm.GetUserMess();
                dgvUserTable.DataSource = ilUT;
            }
            else if (cboSearch.Text == "按会员号" || cboSearch.Text == "按会员姓名")
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
        /// 信息列表的点击事件
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
        /// 显示会员信息
        /// </summary>
        private void ShowUserMess()
        {
            txtUserID.Text = ilUT[index].UserID.ToString();
            txtUserName.Text = ilUT[index].UserName;
            if (ilUT[index].UserSex == "男")
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
        /// 取消按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbtnCancel_Click(object sender, EventArgs e)
        {
            this.Size = new Size(684, 326);
        }
        /// <summary>
        /// 添加按钮
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
        /// 修改按钮
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
        /// 删除按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbtnDelete_Click(object sender, EventArgs e)
        {
            if (dgvUserTable.SelectedRows.Count!=0)
            {
                DialogResult r = MessageBox.Show("确定要删除此信息吗？","提示",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
                if (r==DialogResult.Yes)
                {
                    string mess = utm.DeleteUser(CreateUserMess());
                    MessageBox.Show(mess, "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    ilUT = utm.GetUserMess();
                    dgvUserTable.DataSource = ilUT;
                    index = 0;
                }
            }
            else
            {
                MessageBox.Show("请选中你要删除的信息！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void tsbtnSave_Click(object sender, EventArgs e)
        {
            if (txtUserID.Text=="")
            {
                if (txtUserName.Text==""||txtUserTel.Text==""||txtUserMoney.Text=="")
                {
                    MessageBox.Show("请输入完整信息以便添加！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    string mess = utm.AddNewUser(CreateUserMess());
                    MessageBox.Show(mess);
                    ilUT = utm.GetUserMess();
                    dgvUserTable.DataSource = ilUT;
                    if (mess == "会员添加成功")
                        Clear();
                }
            }
            else
            {
                if (txtUserName.Text == "" || txtUserTel.Text == "" || txtUserMoney.Text == "")
                {
                    MessageBox.Show("请输入完整信息！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
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
            if (cboSearch.Text=="全部")
            {
                dtpSearch.Visible = false;
                txtSearch.Visible = true;
                txtSearch.Enabled = false;
                txtSearch.Text = "";
            }
            else if (cboSearch.Text == "按会员号" || cboSearch.Text == "按会员姓名")
            {
                dtpSearch.Visible = false;
                txtSearch.Visible = true;
                txtSearch.Enabled = true;
                txtSearch.Text = "";
            }
            else if (cboSearch.Text == "按会员生日" || cboSearch.Text == "按开户时间")
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