namespace LibraryManager
{
    partial class UsuallyControl
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
            this.pnlKCManager = new System.Windows.Forms.Panel();
            this.btnCardType = new System.Windows.Forms.Button();
            this.btnCounter = new System.Windows.Forms.Button();
            this.btnZuJin = new System.Windows.Forms.Button();
            this.pnlKCManager.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlKCManager
            // 
            this.pnlKCManager.Controls.Add(this.btnCardType);
            this.pnlKCManager.Controls.Add(this.btnCounter);
            this.pnlKCManager.Controls.Add(this.btnZuJin);
            this.pnlKCManager.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlKCManager.Location = new System.Drawing.Point(0, 0);
            this.pnlKCManager.Name = "pnlKCManager";
            this.pnlKCManager.Size = new System.Drawing.Size(138, 305);
            this.pnlKCManager.TabIndex = 0;
            // 
            // btnCardType
            // 
            this.btnCardType.Location = new System.Drawing.Point(32, 141);
            this.btnCardType.Name = "btnCardType";
            this.btnCardType.Size = new System.Drawing.Size(75, 23);
            this.btnCardType.TabIndex = 9;
            this.btnCardType.Text = "卡类型设定";
            this.btnCardType.UseVisualStyleBackColor = true;
            this.btnCardType.Click += new System.EventHandler(this.btnCardType_Click);
            // 
            // btnCounter
            // 
            this.btnCounter.Location = new System.Drawing.Point(32, 241);
            this.btnCounter.Name = "btnCounter";
            this.btnCounter.Size = new System.Drawing.Size(75, 23);
            this.btnCounter.TabIndex = 5;
            this.btnCounter.Text = "计 算 器";
            this.btnCounter.UseVisualStyleBackColor = true;
            this.btnCounter.Click += new System.EventHandler(this.btnCounter_Click);
            // 
            // btnZuJin
            // 
            this.btnZuJin.Location = new System.Drawing.Point(32, 41);
            this.btnZuJin.Name = "btnZuJin";
            this.btnZuJin.Size = new System.Drawing.Size(75, 23);
            this.btnZuJin.TabIndex = 6;
            this.btnZuJin.Text = "租金设定";
            this.btnZuJin.UseVisualStyleBackColor = true;
            this.btnZuJin.Click += new System.EventHandler(this.btnZuJin_Click);
            // 
            // UsuallyControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.Transparent;
            this.Controls.Add(this.pnlKCManager);
            this.Name = "UsuallyControl";
            this.Size = new System.Drawing.Size(138, 305);
            this.pnlKCManager.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlKCManager;
        private System.Windows.Forms.Button btnCounter;
        private System.Windows.Forms.Button btnZuJin;
        private System.Windows.Forms.Button btnCardType;

    }
}
