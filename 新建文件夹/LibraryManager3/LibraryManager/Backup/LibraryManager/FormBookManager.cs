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
            fa.Text = "图书新增";
            fa.TopMost = true;
            fa.ShowDialog();
        }

        private void tsmiAdd_Click(object sender, EventArgs e)
        {
            FormNewBook fa = new FormNewBook();
            fa.Text = "图书新增";
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
            TreeNode no=tvBookMess.Nodes.Add("图书类别");
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
        /// 删除图书信息
        /// </summary>
        private void DeleteBook()
        {
            int id = -1;
            if (dgvBookMess.DataSource != null)
            {
                if (dgvBookMess.SelectedRows.Count == 0)
                {
                    MessageBox.Show("请选中你要删除的信息!", "提示", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                }
                else
                {
                    DialogResult r = MessageBox.Show("确定要删除此信息吗？","提示",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
                    if (r==DialogResult.Yes)
                    {
                        id = Convert.ToInt32(dgvBookMess.SelectedRows[0].Cells[0].Value);
                        MessageBox.Show(bm.DeleteBook(id), "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        dgvBookMess.DataSource = bm.GetBookMessByTypeID(index);
                    }
                }
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (index==0)
            {
                MessageBox.Show("没有选择图书类型！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else if (txtSearch.Text=="")
            {
                MessageBox.Show("请填写查询条件！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
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
                MessageBox.Show("请选中你要修改的图书！","提示",MessageBoxButtons.OK,MessageBoxIcon.Information);
            }
            else
            {
                FormNewBook fb = new FormNewBook();
                fb.Text = "图书修改";
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