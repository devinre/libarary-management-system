namespace LibraryManager
{
    partial class FormUpdataPWD
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormUpdataPWD));
            this.panel1 = new System.Windows.Forms.Panel();
            this.txtNewPWDS = new System.Windows.Forms.TextBox();
            this.txtNewPWD = new System.Windows.Forms.TextBox();
            this.lblNewPWDS = new System.Windows.Forms.Label();
            this.txtPWD = new System.Windows.Forms.TextBox();
            this.lblNewPWD = new System.Windows.Forms.Label();
            this.lblUsers = new System.Windows.Forms.Label();
            this.lblPwd = new System.Windows.Forms.Label();
            this.lblUser = new System.Windows.Forms.Label();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.Controls.Add(this.txtNewPWDS);
            this.panel1.Controls.Add(this.txtNewPWD);
            this.panel1.Controls.Add(this.lblNewPWDS);
            this.panel1.Controls.Add(this.txtPWD);
            this.panel1.Controls.Add(this.lblNewPWD);
            this.panel1.Controls.Add(this.lblUsers);
            this.panel1.Controls.Add(this.lblPwd);
            this.panel1.Controls.Add(this.lblUser);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(216, 169);
            this.panel1.TabIndex = 0;
            // 
            // txtNewPWDS
            // 
            this.txtNewPWDS.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtNewPWDS.Location = new System.Drawing.Point(86, 128);
            this.txtNewPWDS.Name = "txtNewPWDS";
            this.txtNewPWDS.PasswordChar = '*';
            this.txtNewPWDS.Size = new System.Drawing.Size(112, 21);
            this.txtNewPWDS.TabIndex = 7;
            // 
            // txtNewPWD
            // 
            this.txtNewPWD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtNewPWD.Location = new System.Drawing.Point(86, 88);
            this.txtNewPWD.Name = "txtNewPWD";
            this.txtNewPWD.PasswordChar = '*';
            this.txtNewPWD.Size = new System.Drawing.Size(112, 21);
            this.txtNewPWD.TabIndex = 8;
            // 
            // lblNewPWDS
            // 
            this.lblNewPWDS.AutoSize = true;
            this.lblNewPWDS.Location = new System.Drawing.Point(15, 131);
            this.lblNewPWDS.Name = "lblNewPWDS";
            this.lblNewPWDS.Size = new System.Drawing.Size(65, 12);
            this.lblNewPWDS.TabIndex = 6;
            this.lblNewPWDS.Text = "验证密码：";
            // 
            // txtPWD
            // 
            this.txtPWD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtPWD.Enabled = false;
            this.txtPWD.Location = new System.Drawing.Point(86, 48);
            this.txtPWD.Name = "txtPWD";
            this.txtPWD.PasswordChar = '*';
            this.txtPWD.Size = new System.Drawing.Size(112, 21);
            this.txtPWD.TabIndex = 9;
            // 
            // lblNewPWD
            // 
            this.lblNewPWD.AutoSize = true;
            this.lblNewPWD.Location = new System.Drawing.Point(15, 91);
            this.lblNewPWD.Name = "lblNewPWD";
            this.lblNewPWD.Size = new System.Drawing.Size(65, 12);
            this.lblNewPWD.TabIndex = 3;
            this.lblNewPWD.Text = "新 密 码：";
            // 
            // lblUsers
            // 
            this.lblUsers.AutoSize = true;
            this.lblUsers.ForeColor = System.Drawing.Color.Blue;
            this.lblUsers.Location = new System.Drawing.Point(86, 11);
            this.lblUsers.Name = "lblUsers";
            this.lblUsers.Size = new System.Drawing.Size(41, 12);
            this.lblUsers.TabIndex = 4;
            this.lblUsers.Text = "label1";
            // 
            // lblPwd
            // 
            this.lblPwd.AutoSize = true;
            this.lblPwd.Location = new System.Drawing.Point(15, 51);
            this.lblPwd.Name = "lblPwd";
            this.lblPwd.Size = new System.Drawing.Size(65, 12);
            this.lblPwd.TabIndex = 2;
            this.lblPwd.Text = "原始密码：";
            // 
            // lblUser
            // 
            this.lblUser.AutoSize = true;
            this.lblUser.Location = new System.Drawing.Point(15, 11);
            this.lblUser.Name = "lblUser";
            this.lblUser.Size = new System.Drawing.Size(65, 12);
            this.lblUser.TabIndex = 5;
            this.lblUser.Text = "操 作 员：";
            // 
            // btnOK
            // 
            this.btnOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnOK.Location = new System.Drawing.Point(29, 192);
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
            this.btnExit.Location = new System.Drawing.Point(137, 192);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 1;
            this.btnExit.Text = "退 出";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // FormUpdataPWD
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(240, 227);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.panel1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "FormUpdataPWD";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "修改密码";
            this.Load += new System.EventHandler(this.FormUpdataPWD_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormUpdataPWD_FormClosed);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox txtNewPWDS;
        private System.Windows.Forms.TextBox txtNewPWD;
        private System.Windows.Forms.Label lblNewPWDS;
        private System.Windows.Forms.TextBox txtPWD;
        private System.Windows.Forms.Label lblNewPWD;
        private System.Windows.Forms.Label lblUsers;
        private System.Windows.Forms.Label lblPwd;
        private System.Windows.Forms.Label lblUser;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnExit;

    }
}