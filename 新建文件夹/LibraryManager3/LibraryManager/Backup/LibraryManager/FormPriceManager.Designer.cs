namespace LibraryManager
{
    partial class FormPriceManager
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormPriceManager));
            this.dgvBookPrice = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.txtPriceDown = new System.Windows.Forms.TextBox();
            this.txtPriceUp = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txtZuJin = new System.Windows.Forms.TextBox();
            this.txtDay = new System.Windows.Forms.TextBox();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvBookPrice)).BeginInit();
            this.SuspendLayout();
            // 
            // dgvBookPrice
            // 
            this.dgvBookPrice.AllowUserToAddRows = false;
            this.dgvBookPrice.AllowUserToDeleteRows = false;
            this.dgvBookPrice.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvBookPrice.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvBookPrice.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvBookPrice.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3,
            this.Column4,
            this.Column5});
            this.dgvBookPrice.Location = new System.Drawing.Point(12, 12);
            this.dgvBookPrice.Name = "dgvBookPrice";
            this.dgvBookPrice.ReadOnly = true;
            this.dgvBookPrice.RowHeadersVisible = false;
            this.dgvBookPrice.RowTemplate.Height = 23;
            this.dgvBookPrice.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvBookPrice.Size = new System.Drawing.Size(442, 151);
            this.dgvBookPrice.TabIndex = 0;
            this.dgvBookPrice.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvBookPrice_CellClick);
            // 
            // Column1
            // 
            this.Column1.DataPropertyName = "BookPriceID";
            this.Column1.HeaderText = "价格ID";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            this.Column1.Visible = false;
            // 
            // Column2
            // 
            this.Column2.DataPropertyName = "BookUpPrice";
            this.Column2.HeaderText = "上限价格";
            this.Column2.Name = "Column2";
            this.Column2.ReadOnly = true;
            this.Column2.Width = 110;
            // 
            // Column3
            // 
            this.Column3.DataPropertyName = "BookDownPrice";
            this.Column3.HeaderText = "下限价格";
            this.Column3.Name = "Column3";
            this.Column3.ReadOnly = true;
            this.Column3.Width = 110;
            // 
            // Column4
            // 
            this.Column4.DataPropertyName = "BookPrice";
            dataGridViewCellStyle1.Format = "C1";
            dataGridViewCellStyle1.NullValue = null;
            this.Column4.DefaultCellStyle = dataGridViewCellStyle1;
            this.Column4.HeaderText = "租金";
            this.Column4.Name = "Column4";
            this.Column4.ReadOnly = true;
            this.Column4.Width = 110;
            // 
            // Column5
            // 
            this.Column5.DataPropertyName = "BackDate";
            this.Column5.HeaderText = "规定天数";
            this.Column5.Name = "Column5";
            this.Column5.ReadOnly = true;
            this.Column5.Width = 105;
            // 
            // txtPriceDown
            // 
            this.txtPriceDown.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtPriceDown.Location = new System.Drawing.Point(57, 209);
            this.txtPriceDown.Name = "txtPriceDown";
            this.txtPriceDown.Size = new System.Drawing.Size(111, 21);
            this.txtPriceDown.TabIndex = 5;
            // 
            // txtPriceUp
            // 
            this.txtPriceUp.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtPriceUp.Location = new System.Drawing.Point(57, 175);
            this.txtPriceUp.Name = "txtPriceUp";
            this.txtPriceUp.Size = new System.Drawing.Size(111, 21);
            this.txtPriceUp.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 212);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "下限";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(10, 178);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "上限";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(193, 178);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "租金";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(193, 212);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "天数";
            // 
            // txtZuJin
            // 
            this.txtZuJin.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtZuJin.Location = new System.Drawing.Point(240, 175);
            this.txtZuJin.Name = "txtZuJin";
            this.txtZuJin.Size = new System.Drawing.Size(111, 21);
            this.txtZuJin.TabIndex = 6;
            // 
            // txtDay
            // 
            this.txtDay.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtDay.Location = new System.Drawing.Point(240, 209);
            this.txtDay.Name = "txtDay";
            this.txtDay.Size = new System.Drawing.Size(111, 21);
            this.txtDay.TabIndex = 5;
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(379, 173);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(75, 23);
            this.btnUpdate.TabIndex = 7;
            this.btnUpdate.Tag = "15";
            this.btnUpdate.Text = "修 改";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(379, 206);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 7;
            this.btnExit.Tag = "0";
            this.btnExit.Text = "退 出";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // FormPriceManager
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(466, 247);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.txtDay);
            this.Controls.Add(this.txtPriceDown);
            this.Controls.Add(this.txtZuJin);
            this.Controls.Add(this.txtPriceUp);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgvBookPrice);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(482, 285);
            this.MinimumSize = new System.Drawing.Size(482, 285);
            this.Name = "FormPriceManager";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "租书价格设定";
            this.Load += new System.EventHandler(this.FormPriceManager_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormPriceManager_FormClosed);
            ((System.ComponentModel.ISupportInitialize)(this.dgvBookPrice)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvBookPrice;
        private System.Windows.Forms.TextBox txtPriceDown;
        private System.Windows.Forms.TextBox txtPriceUp;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtZuJin;
        private System.Windows.Forms.TextBox txtDay;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
    }
}