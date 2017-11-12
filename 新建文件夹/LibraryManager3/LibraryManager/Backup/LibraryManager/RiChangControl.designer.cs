namespace LibraryManager
{
    partial class RiChangControl
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

        #region 组件设计器生成的代码

        /// <summary> 
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlRCManager = new System.Windows.Forms.Panel();
            this.btnBookMess = new System.Windows.Forms.Button();
            this.btnUserManager = new System.Windows.Forms.Button();
            this.btnHYManager = new System.Windows.Forms.Button();
            this.pnlRCManager.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlRCManager
            // 
            this.pnlRCManager.AutoSize = true;
            this.pnlRCManager.Controls.Add(this.btnBookMess);
            this.pnlRCManager.Controls.Add(this.btnUserManager);
            this.pnlRCManager.Controls.Add(this.btnHYManager);
            this.pnlRCManager.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlRCManager.Location = new System.Drawing.Point(0, 0);
            this.pnlRCManager.Name = "pnlRCManager";
            this.pnlRCManager.Size = new System.Drawing.Size(138, 305);
            this.pnlRCManager.TabIndex = 0;
            // 
            // btnBookMess
            // 
            this.btnBookMess.Location = new System.Drawing.Point(32, 241);
            this.btnBookMess.Name = "btnBookMess";
            this.btnBookMess.Size = new System.Drawing.Size(75, 23);
            this.btnBookMess.TabIndex = 7;
            this.btnBookMess.Text = "图书信息";
            this.btnBookMess.UseVisualStyleBackColor = true;
            this.btnBookMess.Click += new System.EventHandler(this.btnBookMess_Click);
            // 
            // btnUserManager
            // 
            this.btnUserManager.Location = new System.Drawing.Point(32, 141);
            this.btnUserManager.Name = "btnUserManager";
            this.btnUserManager.Size = new System.Drawing.Size(75, 23);
            this.btnUserManager.TabIndex = 5;
            this.btnUserManager.Text = "员工管理";
            this.btnUserManager.UseVisualStyleBackColor = true;
            this.btnUserManager.Click += new System.EventHandler(this.btnUserManager_Click);
            // 
            // btnHYManager
            // 
            this.btnHYManager.Location = new System.Drawing.Point(32, 41);
            this.btnHYManager.Name = "btnHYManager";
            this.btnHYManager.Size = new System.Drawing.Size(75, 23);
            this.btnHYManager.TabIndex = 6;
            this.btnHYManager.Text = "会员管理";
            this.btnHYManager.UseVisualStyleBackColor = true;
            this.btnHYManager.Click += new System.EventHandler(this.btnHYManager_Click);
            // 
            // RiChangControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Transparent;
            this.Controls.Add(this.pnlRCManager);
            this.Name = "RiChangControl";
            this.Size = new System.Drawing.Size(138, 305);
            this.pnlRCManager.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel pnlRCManager;
        private System.Windows.Forms.Button btnBookMess;
        private System.Windows.Forms.Button btnUserManager;
        private System.Windows.Forms.Button btnHYManager;

    }
}
