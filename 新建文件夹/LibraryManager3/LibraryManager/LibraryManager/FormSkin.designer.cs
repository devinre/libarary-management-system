namespace LibraryManager
{
    partial class FormSkin
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormSkin));
            this.panelTop = new System.Windows.Forms.Panel();
            this.pictureSkinShow = new System.Windows.Forms.PictureBox();
            this.panelBottom = new System.Windows.Forms.Panel();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOK = new System.Windows.Forms.Button();
            this.panelLeft = new System.Windows.Forms.Panel();
            this.listViewSkinList = new System.Windows.Forms.ListView();
            this.panelTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureSkinShow)).BeginInit();
            this.panelBottom.SuspendLayout();
            this.panelLeft.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelTop
            // 
            this.panelTop.Controls.Add(this.pictureSkinShow);
            this.panelTop.Controls.Add(this.panelBottom);
            this.panelTop.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelTop.Location = new System.Drawing.Point(130, 0);
            this.panelTop.Name = "panelTop";
            this.panelTop.Size = new System.Drawing.Size(295, 330);
            this.panelTop.TabIndex = 7;
            // 
            // pictureSkinShow
            // 
            this.pictureSkinShow.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureSkinShow.Location = new System.Drawing.Point(0, 0);
            this.pictureSkinShow.Name = "pictureSkinShow";
            this.pictureSkinShow.Size = new System.Drawing.Size(295, 286);
            this.pictureSkinShow.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureSkinShow.TabIndex = 0;
            this.pictureSkinShow.TabStop = false;
            // 
            // panelBottom
            // 
            this.panelBottom.Controls.Add(this.btnCancel);
            this.panelBottom.Controls.Add(this.btnOK);
            this.panelBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panelBottom.Location = new System.Drawing.Point(0, 286);
            this.panelBottom.Name = "panelBottom";
            this.panelBottom.Size = new System.Drawing.Size(295, 44);
            this.panelBottom.TabIndex = 8;
            // 
            // btnCancel
            // 
            this.btnCancel.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnCancel.Location = new System.Drawing.Point(172, 10);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(65, 23);
            this.btnCancel.TabIndex = 2;
            this.btnCancel.Text = "关闭(&C)";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnOK
            // 
            this.btnOK.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnOK.Location = new System.Drawing.Point(65, 10);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(65, 23);
            this.btnOK.TabIndex = 1;
            this.btnOK.Text = "确定(&O)";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // panelLeft
            // 
            this.panelLeft.Controls.Add(this.listViewSkinList);
            this.panelLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelLeft.Location = new System.Drawing.Point(0, 0);
            this.panelLeft.Name = "panelLeft";
            this.panelLeft.Size = new System.Drawing.Size(130, 330);
            this.panelLeft.TabIndex = 6;
            // 
            // listViewSkinList
            // 
            this.listViewSkinList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listViewSkinList.Location = new System.Drawing.Point(0, 0);
            this.listViewSkinList.Name = "listViewSkinList";
            this.listViewSkinList.Size = new System.Drawing.Size(130, 330);
            this.listViewSkinList.TabIndex = 0;
            this.listViewSkinList.TileSize = new System.Drawing.Size(110, 25);
            this.listViewSkinList.UseCompatibleStateImageBehavior = false;
            this.listViewSkinList.View = System.Windows.Forms.View.Tile;
            this.listViewSkinList.SelectedIndexChanged += new System.EventHandler(this.listViewSkinList_SelectedIndexChanged);
            // 
            // FormSkin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(425, 330);
            this.Controls.Add(this.panelTop);
            this.Controls.Add(this.panelLeft);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormSkin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "窗体外观设置";
            this.panelTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureSkinShow)).EndInit();
            this.panelBottom.ResumeLayout(false);
            this.panelLeft.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelTop;
        private System.Windows.Forms.PictureBox pictureSkinShow;
        private System.Windows.Forms.Panel panelLeft;
        private System.Windows.Forms.ListView listViewSkinList;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Panel panelBottom;

    }
}