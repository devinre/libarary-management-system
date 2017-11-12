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
    public partial class FormCardManager : Form
    {
        private FormCardManager()
        {
            InitializeComponent();
        }
        CardTypeManager ctm;
        IList<CardType> il;
        CardType ct = new CardType();
        static FormCardManager fc;
        public static FormCardManager CreateForm()
        {
            if (fc==null)
            {
                fc = new FormCardManager();
            }
            return fc;
        }
        
        private void FormCardManager_FormClosed(object sender, FormClosedEventArgs e)
        {
            fc = null;
        }
        int index;
        private void FormCardManager_Load(object sender, EventArgs e)
        {
            ctm = new CardTypeManager();
            il = new List<CardType>();
            il = ctm.GetCardType();
            dgvCardMess.DataSource = il;
            ShowCardMess();

            foreach (Control v in this.Controls)
            {
                Button btn = v as Button;
                if (btn != null)
                {
                    btn.Enabled = false;
                    foreach (int var in UserHelp.FunctionID)
                    {
                        if (Convert.ToInt32(btn.Tag)==var||Convert.ToInt32(btn.Tag)==0)
                        {
                            btn.Enabled = true;
                        }
                    }
                }
            }
            if (btnAdd.Enabled==false&&btnUpdate.Enabled==false)
            {
                btnSave.Enabled = false;
            }
        }

        private void ShowCardMess()
        {
            txtCardType.Enabled = false;
            txtDiscount.Enabled = false;
            txtCardType.Text = il[index].CardName;
            txtDiscount.Text = il[index].CardAgio.ToString();
        }
        /// <summary>
        /// 创建会员卡实体
        /// </summary>
        /// <returns></returns>
        public CardType IniCardType()
        {
            ct.CardName = txtCardType.Text;
            ct.CardAgio = Convert.ToDouble(txtDiscount.Text);
            ct.CardTypeID = Convert.ToInt32(dgvCardMess.SelectedRows[0].Cells[0].Value);
            return ct;
        }

        private void dgvCardMess_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            index = Convert.ToInt32(dgvCardMess.SelectedRows[0].Index);
            txtCardType.Enabled = false;
            txtDiscount.Enabled = false;
            txtCardType.Text = il[index].CardName;
            txtDiscount.Text = il[index].CardAgio.ToString();
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            txtCardType.Enabled = true;
            txtDiscount.Enabled = true;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            txtCardType.Enabled = true;
            txtDiscount.Enabled = true;
            txtCardType.Text = "";
            txtDiscount.Text = "";
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            string mess = "";
            if (txtCardType.Text==""||txtDiscount.Text=="")
            {
                MessageBox.Show("请填写完整信息！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else
            {
                if (ctm.JudgeCardType(txtCardType.Text))
                {
                    //如果存在此会员类型就执行修改操作
                    mess = ctm.UpdateCardType(IniCardType());
                }
                else
                {
                    //如果不存在此会员类型就执行添加操作
                    mess = ctm.AddNewCardType(IniCardType());
                }
                MessageBox.Show(mess, "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                il = ctm.GetCardType();
                dgvCardMess.DataSource = il;
                ShowCardMess();
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}