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
    public partial class FormBookManager : Form
    {
        private FormBookManager()
        {
            InitializeComponent();
        }
        static FormBookManager fb;
        IList<Books> il = new List<Books>();
        public static FormBookManager CreateForm()
        {
            if (fb==null)
            {
                fb = new FormBookManager();
                fb.TopMost = true;
            }
            return fb;
        }

        BookTypeManager btm = new BookTypeManager();
        BookManager bm = new BookManager();
        private void FormBookManager_FormClosed(object sender, FormClosedEventArgs e)
        {
            fb = null;
        }

        private void tsmiAddBookType_Click(object sender, EventArgs e)
        {
            FormAddBookType fa = new FormAddBookType();
            fa.TopMost=true;
            fa.ShowDialog();
        }

        private void tsbtnAdd_Click(object sender, EventArgs e)
        {
            FormNewBook fa = new FormNewBook();
            fa.Text = "ͼ������";
            fa.TopMost = true;
            fa.ShowDialog();
        }

        private void tsmiAdd_Click(object sender, EventArgs e)
        {
            FormNewBook fa = new FormNewBook();
            fa.Text = "ͼ������";
            fa.TopMost = true;
            fa.ShowDialog();
        }

        private void FormBookManager_Load(object sender, EventArgs e)
        {
            tvBookMess.Nodes.Clear();
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

        private void tsbtnSearch_Click(object sender, EventArgs e)
        {
            FillTree();

        }
        public void FillTree()
        {
            tvBookMess.Nodes.Clear();
            TreeNode no=tvBookMess.Nodes.Add("ͼ�����");
            foreach (BookType v in btm.GetBookType())
            {
                TreeNode n = no.Nodes.Add(v.TypeName);
                n.Tag = v.TypeID;                
            }
        }
        int index;
        private void tvBookMess_AfterSelect(object sender, TreeViewEventArgs e)
        {
            TreeNode node = tvBookMess.SelectedNode;
            index = Convert.ToInt32(node.Tag);
            txtSearch.Text = "";
            if (node == null)
            {
                return;
            }
            if (node.Level != 1)
            {
                return;
            }
            il = bm.GetBookMessByTypeID(index);
            dgvBookMess.DataSource = il;
        }

        private void tsmiShowList_Click(object sender, EventArgs e)
        {
            FillTree();
        }

        private void tsbtnDelete_Click(object sender, EventArgs e)
        {
            DeleteBook();
        }
        /// <summary>
        /// ɾ��ͼ����Ϣ
        /// </summary>
        private void DeleteBook()
        {
            int id = -1;
            if (dgvBookMess.DataSource != null)
            {
                if (dgvBookMess.SelectedRows.Count == 0)
                {
                    MessageBox.Show("��ѡ����Ҫɾ������Ϣ!", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                }
                else
                {
                    DialogResult r = MessageBox.Show("ȷ��Ҫɾ������Ϣ��","��ʾ",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
                    if (r==DialogResult.Yes)
                    {
                        id = Convert.ToInt32(dgvBookMess.SelectedRows[0].Cells[0].Value);
                        MessageBox.Show(bm.DeleteBook(id), "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        dgvBookMess.DataSource = bm.GetBookMessByTypeID(index);
                    }
                }
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (index==0)
            {
                MessageBox.Show("û��ѡ��ͼ�����ͣ�", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else if (txtSearch.Text=="")
            {
                MessageBox.Show("����д��ѯ������", "��ʾ", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else
            {
                dgvBookMess.DataSource = bm.GetBookByBookName(index, txtSearch.Text);
            }
        }

        private void tsbtnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void tsmiDelete_Click(object sender, EventArgs e)
        {
            DeleteBook();
        }

        private void tsbtnUpdateBook_Click(object sender, EventArgs e)
        {
            if (dgvBookMess.SelectedRows.Count==0)
            {
                MessageBox.Show("��ѡ����Ҫ�޸ĵ�ͼ�飡","��ʾ",MessageBoxButtons.OK,MessageBoxIcon.Information);
            }
            else
            {
                FormNewBook fb = new FormNewBook();
                fb.Text = "ͼ���޸�";
                int id = Convert.ToInt32(dgvBookMess.SelectedRows[0].Cells[0].Value);
                fb.Tag=id;
                Books b = dgvBookMess.SelectedRows[0].DataBoundItem as Books;
                fb.txtBookID.Text = b.BookID.ToString(); ;
                fb.txtBookName.Text = b.BookName;
                fb.cboBookType.Text = b.TypeName;
                fb.txtBookPrice.Text = b.Price.ToString();
                fb.txtPublish.Text = b.Publish;
                fb.cboState.Text = b.State;
                fb.cboState.Enabled = false;
                fb.ShowDialog();
                il = bm.GetBookMessByTypeID(index);
                dgvBookMess.DataSource = il;
            }
        }
    }
}