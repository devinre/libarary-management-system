namespace LibraryManager
{
    partial class FormUser
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormUser));
            this.grpMess = new System.Windows.Forms.GroupBox();
            this.cboSex = new System.Windows.Forms.ComboBox();
            this.btnJianCe = new System.Windows.Forms.Button();
            this.txtSex = new System.Windows.Forms.TextBox();
            this.lblPWD = new System.Windows.Forms.Label();
            this.lblPWDS = new System.Windows.Forms.Label();
            this.cboType = new System.Windows.Forms.ComboBox();
            this.txtPWD = new System.Windows.Forms.TextBox();
            this.lblName = new System.Windows.Forms.Label();
            this.txtPWDS = new System.Windows.Forms.TextBox();
            this.txtType = new System.Windows.Forms.TextBox();
            this.txtUserName = new System.Windows.Forms.TextBox();
            this.txtUID = new System.Windows.Forms.TextBox();
            this.txtID = new System.Windows.Forms.TextBox();
            this.lblSex = new System.Windows.Forms.Label();
            this.lblJianCe = new System.Windows.Forms.Label();
            this.lblType = new System.Windows.Forms.Label();
            this.lblUID = new System.Windows.Forms.Label();
            this.lblID = new System.Windows.Forms.Label();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.grpMess.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpMess
            // 
            this.grpMess.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.grpMess.Controls.Add(this.cboSex);
            this.grpMess.Controls.Add(this.btnJianCe);
            this.grpMess.Controls.Add(this.txtSex);
            this.grpMess.Controls.Add(this.lblPWD);
            this.grpMess.Controls.Add(this.lblPWDS);
            this.grpMess.Controls.Add(this.cboType);
            this.grpMess.Controls.Add(this.txtPWD);
            this.grpMess.Controls.Add(this.lblName);
            this.grpMess.Controls.Add(this.txtPWDS);
            this.grpMess.Controls.Add(this.txtType);
            this.grpMess.Controls.Add(this.txtUserName);
            this.grpMess.Controls.Add(this.txtUID);
            this.grpMess.Controls.Add(this.txtID);
            this.grpMess.Controls.Add(this.lblSex);
            this.grpMess.Controls.Add(this.lblJianCe);
            this.grpMess.Controls.Add(this.lblType);
            this.grpMess.Controls.Add(this.lblUID);
            this.grpMess.Controls.Add(this.lblID);
            this.grpMess.Location = new System.Drawing.Point(12, 12);
            this.grpMess.Name = "grpMess";
            this.grpMess.Size = new System.Drawing.Size(401, 200);
            this.grpMess.TabIndex = 0;
            this.grpMess.TabStop = false;
            this.grpMess.Text = "员工信息";
            // 
            // cboSex
            // 
            this.cboSex.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboSex.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cboSex.FormattingEnabled = true;
            this.cboSex.Items.AddRange(new object[] {
            "男",
            "女"});
            this.cboSex.Location = new System.Drawing.Point(81, 161);
            this.cboSex.Name = "cboSex";
            this.cboSex.Size = new System.Drawing.Size(100, 20);
            this.cboSex.TabIndex = 3;
            // 
            // btnJianCe
            // 
            this.btnJianCe.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnJianCe.ForeColor = System.Drawing.Color.Blue;
            this.btnJianCe.Location = new System.Drawing.Point(208, 72);
            this.btnJianCe.Name = "btnJianCe";
            this.btnJianCe.Size = new System.Drawing.Size(75, 23);
            this.btnJianCe.TabIndex = 1;
            this.btnJianCe.Text = "帐号检测";
            this.btnJianCe.UseVisualStyleBackColor = true;
            this.btnJianCe.Click += new System.EventHandler(this.btnJianCe_Click);
            // 
            // txtSex
            // 
            this.txtSex.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtSex.Location = new System.Drawing.Point(80, 160);
            this.txtSex.Multiline = true;
            this.txtSex.Name = "txtSex";
            this.txtSex.Size = new System.Drawing.Size(102, 22);
            this.txtSex.TabIndex = 4;
            this.txtSex.MouseDown += new System.Windows.Forms.MouseEventHandler(this.txtSex_MouseDown);
            // 
            // lblPWD
            // 
            this.lblPWD.AutoSize = true;
            this.lblPWD.Location = new System.Drawing.Point(12, 120);
            this.lblPWD.Name = "lblPWD";
            this.lblPWD.Size = new System.Drawing.Size(65, 12);
            this.lblPWD.TabIndex = 0;
            this.lblPWD.Text = "员工密码：";
            // 
            // lblPWDS
            // 
            this.lblPWDS.AutoSize = true;
            this.lblPWDS.Location = new System.Drawing.Point(218, 120);
            this.lblPWDS.Name = "lblPWDS";
            this.lblPWDS.Size = new System.Drawing.Size(65, 12);
            this.lblPWDS.TabIndex = 0;
            this.lblPWDS.Text = "确认密码：";
            // 
            // cboType
            // 
            this.cboType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboType.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cboType.FormattingEnabled = true;
            this.cboType.Location = new System.Drawing.Point(287, 33);
            this.cboType.Name = "cboType";
            this.cboType.Size = new System.Drawing.Size(100, 20);
            this.cboType.TabIndex = 2;
            // 
            // txtPWD
            // 
            this.txtPWD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtPWD.Location = new System.Drawing.Point(80, 118);
            this.txtPWD.Name = "txtPWD";
            this.txtPWD.PasswordChar = '*';
            this.txtPWD.Size = new System.Drawing.Size(100, 21);
            this.txtPWD.TabIndex = 1;
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(218, 163);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(65, 12);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "员工姓名：";
            // 
            // txtPWDS
            // 
            this.txtPWDS.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtPWDS.Location = new System.Drawing.Point(286, 118);
            this.txtPWDS.Name = "txtPWDS";
            this.txtPWDS.PasswordChar = '*';
            this.txtPWDS.Size = new System.Drawing.Size(100, 21);
            this.txtPWDS.TabIndex = 1;
            // 
            // txtType
            // 
            this.txtType.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtType.Location = new System.Drawing.Point(286, 32);
            this.txtType.Multiline = true;
            this.txtType.Name = "txtType";
            this.txtType.Size = new System.Drawing.Size(102, 22);
            this.txtType.TabIndex = 1;
            this.txtType.MouseDown += new System.Windows.Forms.MouseEventHandler(this.txtType_MouseDown);
            // 
            // txtUserName
            // 
            this.txtUserName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtUserName.Location = new System.Drawing.Point(286, 160);
            this.txtUserName.Name = "txtUserName";
            this.txtUserName.Size = new System.Drawing.Size(100, 21);
            this.txtUserName.TabIndex = 1;
            // 
            // txtUID
            // 
            this.txtUID.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtUID.Location = new System.Drawing.Point(80, 74);
            this.txtUID.Name = "txtUID";
            this.txtUID.Size = new System.Drawing.Size(100, 21);
            this.txtUID.TabIndex = 1;
            // 
            // txtID
            // 
            this.txtID.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtID.Enabled = false;
            this.txtID.Location = new System.Drawing.Point(80, 31);
            this.txtID.Name = "txtID";
            this.txtID.Size = new System.Drawing.Size(100, 21);
            this.txtID.TabIndex = 1;
            // 
            // lblSex
            // 
            this.lblSex.AutoSize = true;
            this.lblSex.Location = new System.Drawing.Point(12, 163);
            this.lblSex.Name = "lblSex";
            this.lblSex.Size = new System.Drawing.Size(65, 12);
            this.lblSex.TabIndex = 0;
            this.lblSex.Text = "员工性别：";
            // 
            // lblJianCe
            // 
            this.lblJianCe.AutoSize = true;
            this.lblJianCe.ForeColor = System.Drawing.Color.Red;
            this.lblJianCe.Location = new System.Drawing.Point(289, 77);
            this.lblJianCe.Name = "lblJianCe";
            this.lblJianCe.Size = new System.Drawing.Size(35, 12);
            this.lblJianCe.TabIndex = 0;
            this.lblJianCe.Text = "lable";
            // 
            // lblType
            // 
            this.lblType.AutoSize = true;
            this.lblType.Location = new System.Drawing.Point(218, 34);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(65, 12);
            this.lblType.TabIndex = 0;
            this.lblType.Text = "员工类型：";
            // 
            // lblUID
            // 
            this.lblUID.AutoSize = true;
            this.lblUID.Location = new System.Drawing.Point(12, 77);
            this.lblUID.Name = "lblUID";
            this.lblUID.Size = new System.Drawing.Size(65, 12);
            this.lblUID.TabIndex = 0;
            this.lblUID.Text = "员工账号：";
            // 
            // lblID
            // 
            this.lblID.AutoSize = true;
            this.lblID.Location = new System.Drawing.Point(12, 34);
            this.lblID.Name = "lblID";
            this.lblID.Size = new System.Drawing.Size(65, 12);
            this.lblID.TabIndex = 0;
            this.lblID.Text = "员工编号：";
            // 
            // btnOK
            // 
            this.btnOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnOK.Location = new System.Drawing.Point(95, 222);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 1;
            this.btnOK.Text = "确 定";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // btnExit
            // 
            this.btnExit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnExit.Location = new System.Drawing.Point(254, 222);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 1;
            this.btnExit.Text = "退 出";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // FormUser
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(425, 255);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.grpMess);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimumSize = new System.Drawing.Size(441, 268);
            this.Name = "FormUser";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FormUser";
            this.Load += new System.EventHandler(this.FormUser_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormUser_FormClosed);
            this.grpMess.ResumeLayout(false);
            this.grpMess.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpMess;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.TextBox txtType;
        private System.Windows.Forms.Label lblSex;
        private System.Windows.Forms.Label lblPWDS;
        private System.Windows.Forms.Label lblType;
        private System.Windows.Forms.Label lblID;
        private System.Windows.Forms.Label lblPWD;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblUID;
        private System.Windows.Forms.TextBox txtSex;
        internal System.Windows.Forms.TextBox txtPWD;
        internal System.Windows.Forms.TextBox txtID;
        internal System.Windows.Forms.TextBox txtUserName;
        internal System.Windows.Forms.ComboBox cboType;
        internal System.Windows.Forms.ComboBox cboSex;
        internal System.Windows.Forms.TextBox txtUID;
        internal System.Windows.Forms.TextBox txtPWDS;
        internal System.Windows.Forms.Button btnJianCe;
        internal System.Windows.Forms.Label lblJianCe;
    }
}