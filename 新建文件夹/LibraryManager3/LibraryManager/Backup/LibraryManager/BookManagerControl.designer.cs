namespace LibraryManager
{
    partial class BookManagerControl
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
            this.pnlXiaoShou = new System.Windows.Forms.Panel();
            this.btnReturnBook = new System.Windows.Forms.Button();
            this.btnLendBook = new System.Windows.Forms.Button();
            this.btnBookManager = new System.Windows.Forms.Button();
            this.pnlXiaoShou.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlXiaoShou
            // 
            this.pnlXiaoShou.Controls.Add(this.btnReturnBook);
            this.pnlXiaoShou.Controls.Add(this.btnLendBook);
            this.pnlXiaoShou.Controls.Add(this.btnBookManager);
            this.pnlXiaoShou.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlXiaoShou.Location = new System.Drawing.Point(0, 0);
            this.pnlXiaoShou.Name = "pnlXiaoShou";
            this.pnlXiaoShou.Size = new System.Drawing.Size(138, 305);
            this.pnlXiaoShou.TabIndex = 0;
            // 
            // btnReturnBook
            // 
            this.btnReturnBook.Location = new System.Drawing.Point(32, 241);
            this.btnReturnBook.Name = "btnReturnBook";
            this.btnReturnBook.Size = new System.Drawing.Size(75, 23);
            this.btnReturnBook.TabIndex = 3;
            this.btnReturnBook.Text = "还书登记";
            this.btnReturnBook.UseVisualStyleBackColor = true;
            this.btnReturnBook.Click += new System.EventHandler(this.btnReturnBook_Click);
            // 
            // btnLendBook
            // 
            this.btnLendBook.Location = new System.Drawing.Point(32, 141);
            this.btnLendBook.Name = "btnLendBook";
            this.btnLendBook.Size = new System.Drawing.Size(75, 23);
            this.btnLendBook.TabIndex = 1;
            this.btnLendBook.Text = "借书登记";
            this.btnLendBook.UseVisualStyleBackColor = true;
            this.btnLendBook.Click += new System.EventHandler(this.btnLendBook_Click);
            // 
            // btnBookManager
            // 
            this.btnBookManager.Location = new System.Drawing.Point(32, 41);
            this.btnBookManager.Name = "btnBookManager";
            this.btnBookManager.Size = new System.Drawing.Size(75, 23);
            this.btnBookManager.TabIndex = 2;
            this.btnBookManager.Text = "图书管理";
            this.btnBookManager.UseVisualStyleBackColor = true;
            this.btnBookManager.Click += new System.EventHandler(this.btnBookManager_Click);
            // 
            // BookManagerControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Transparent;
            this.Controls.Add(this.pnlXiaoShou);
            this.Name = "BookManagerControl";
            this.Size = new System.Drawing.Size(138, 305);
            this.pnlXiaoShou.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlXiaoShou;
        private System.Windows.Forms.Button btnReturnBook;
        private System.Windows.Forms.Button btnLendBook;
        private System.Windows.Forms.Button btnBookManager;

    }
}
