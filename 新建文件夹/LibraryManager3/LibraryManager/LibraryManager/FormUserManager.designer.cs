namespace LibraryManager
{
    partial class FormUserManager
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormUserManager));
            this.tsTool = new System.Windows.Forms.ToolStrip();
            this.tsbtnAdd = new System.Windows.Forms.ToolStripButton();
            this.ttssA = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnUpdate = new System.Windows.Forms.ToolStripButton();
            this.tssC = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnDelete = new System.Windows.Forms.ToolStripButton();
            this.tssD = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnShuXin = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnExit = new System.Windows.Forms.ToolStripButton();
            this.dgvMess = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column9 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tsTool.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvMess)).BeginInit();
            this.SuspendLayout();
            // 
            // tsTool
            // 
            this.tsTool.AutoSize = false;
            this.tsTool.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("tsTool.BackgroundImage")));
            this.tsTool.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbtnAdd,
            this.ttssA,
            this.tsbtnUpdate,
            this.tssC,
            this.tsbtnDelete,
            this.tssD,
            this.tsbtnShuXin,
            this.toolStripSeparator1,
            this.tsbtnExit});
            this.tsTool.Location = new System.Drawing.Point(0, 0);
            this.tsTool.Name = "tsTool";
            this.tsTool.Size = new System.Drawing.Size(514, 63);
            this.tsTool.TabIndex = 14;
            this.tsTool.Text = "toolStrip1";
            // 
            // tsbtnAdd
            // 
            this.tsbtnAdd.AutoSize = false;
            this.tsbtnAdd.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.tsbtnAdd.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnAdd.Image")));
            this.tsbtnAdd.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsbtnAdd.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnAdd.Name = "tsbtnAdd";
            this.tsbtnAdd.Size = new System.Drawing.Size(60, 60);
            this.tsbtnAdd.Tag = "1";
            this.tsbtnAdd.Text = "增 加";
            this.tsbtnAdd.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnAdd.Click += new System.EventHandler(this.tsbtnAdd_Click);
            // 
            // ttssA
            // 
            this.ttssA.Name = "ttssA";
            this.ttssA.Size = new System.Drawing.Size(6, 63);
            // 
            // tsbtnUpdate
            // 
            this.tsbtnUpdate.AutoSize = false;
            this.tsbtnUpdate.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnUpdate.Image")));
            this.tsbtnUpdate.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.tsbtnUpdate.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsbtnUpdate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnUpdate.Name = "tsbtnUpdate";
            this.tsbtnUpdate.Size = new System.Drawing.Size(60, 60);
            this.tsbtnUpdate.Tag = "3";
            this.tsbtnUpdate.Text = "修 改";
            this.tsbtnUpdate.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnUpdate.Click += new System.EventHandler(this.tsbtnUpdate_Click);
            // 
            // tssC
            // 
            this.tssC.Name = "tssC";
            this.tssC.Size = new System.Drawing.Size(6, 63);
            // 
            // tsbtnDelete
            // 
            this.tsbtnDelete.AutoSize = false;
            this.tsbtnDelete.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnDelete.Image")));
            this.tsbtnDelete.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsbtnDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnDelete.Name = "tsbtnDelete";
            this.tsbtnDelete.Size = new System.Drawing.Size(60, 60);
            this.tsbtnDelete.Tag = "2";
            this.tsbtnDelete.Text = "删 除";
            this.tsbtnDelete.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnDelete.Click += new System.EventHandler(this.tsbtnDelete_Click);
            // 
            // tssD
            // 
            this.tssD.Name = "tssD";
            this.tssD.Size = new System.Drawing.Size(6, 63);
            // 
            // tsbtnShuXin
            // 
            this.tsbtnShuXin.AutoSize = false;
            this.tsbtnShuXin.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnShuXin.Image")));
            this.tsbtnShuXin.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsbtnShuXin.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnShuXin.Name = "tsbtnShuXin";
            this.tsbtnShuXin.Size = new System.Drawing.Size(60, 60);
            this.tsbtnShuXin.Tag = "4";
            this.tsbtnShuXin.Text = "刷 新";
            this.tsbtnShuXin.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnShuXin.Click += new System.EventHandler(this.tsbtnShuXin_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 63);
            // 
            // tsbtnExit
            // 
            this.tsbtnExit.AutoSize = false;
            this.tsbtnExit.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnExit.Image")));
            this.tsbtnExit.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tsbtnExit.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnExit.Name = "tsbtnExit";
            this.tsbtnExit.Size = new System.Drawing.Size(60, 60);
            this.tsbtnExit.Tag = "0";
            this.tsbtnExit.Text = "退 出";
            this.tsbtnExit.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnExit.Click += new System.EventHandler(this.tsbtnExit_Click);
            // 
            // dgvMess
            // 
            this.dgvMess.AllowUserToAddRows = false;
            this.dgvMess.AllowUserToDeleteRows = false;
            this.dgvMess.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvMess.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvMess.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvMess.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvMess.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column8,
            this.Column3,
            this.Column9,
            this.Column4,
            this.Column5});
            this.dgvMess.Location = new System.Drawing.Point(0, 66);
            this.dgvMess.Name = "dgvMess";
            this.dgvMess.ReadOnly = true;
            this.dgvMess.RowHeadersVisible = false;
            this.dgvMess.RowTemplate.Height = 23;
            this.dgvMess.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvMess.Size = new System.Drawing.Size(514, 214);
            this.dgvMess.TabIndex = 15;
            // 
            // Column1
            // 
            this.Column1.DataPropertyName = "UserID";
            this.Column1.HeaderText = "员工编号";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            // 
            // Column2
            // 
            this.Column2.DataPropertyName = "UserUID";
            this.Column2.HeaderText = "员工账号";
            this.Column2.Name = "Column2";
            this.Column2.ReadOnly = true;
            // 
            // Column8
            // 
            this.Column8.DataPropertyName = "UserPwd";
            this.Column8.HeaderText = "员工密码";
            this.Column8.Name = "Column8";
            this.Column8.ReadOnly = true;
            // 
            // Column3
            // 
            this.Column3.DataPropertyName = "UserName";
            this.Column3.HeaderText = "员工姓名";
            this.Column3.Name = "Column3";
            this.Column3.ReadOnly = true;
            // 
            // Column9
            // 
            this.Column9.DataPropertyName = "RolesName";
            this.Column9.HeaderText = "员工类型";
            this.Column9.Name = "Column9";
            this.Column9.ReadOnly = true;
            // 
            // Column4
            // 
            this.Column4.DataPropertyName = "UserSex";
            this.Column4.HeaderText = "员工性别";
            this.Column4.Name = "Column4";
            this.Column4.ReadOnly = true;
            // 
            // Column5
            // 
            this.Column5.DataPropertyName = "RoleID";
            this.Column5.HeaderText = "类型ID";
            this.Column5.Name = "Column5";
            this.Column5.ReadOnly = true;
            this.Column5.Visible = false;
            // 
            // FormUserManager
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(514, 285);
            this.Controls.Add(this.dgvMess);
            this.Controls.Add(this.tsTool);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(530, 323);
            this.MinimumSize = new System.Drawing.Size(530, 323);
            this.Name = "FormUserManager";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "员工信息";
            this.Load += new System.EventHandler(this.FormEmpShow_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormUserManager_FormClosed);
            this.tsTool.ResumeLayout(false);
            this.tsTool.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvMess)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ToolStrip tsTool;
        private System.Windows.Forms.ToolStripButton tsbtnAdd;
        private System.Windows.Forms.ToolStripSeparator ttssA;
        private System.Windows.Forms.ToolStripButton tsbtnUpdate;
        private System.Windows.Forms.ToolStripSeparator tssC;
        private System.Windows.Forms.ToolStripButton tsbtnDelete;
        private System.Windows.Forms.ToolStripSeparator tssD;
        private System.Windows.Forms.ToolStripButton tsbtnShuXin;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton tsbtnExit;
        public System.Windows.Forms.DataGridView dgvMess;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column8;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column9;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
    }
}