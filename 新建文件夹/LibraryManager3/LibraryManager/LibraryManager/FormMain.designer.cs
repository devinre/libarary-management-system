namespace LibraryManager
{
    partial class FormMain
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.tsTool = new System.Windows.Forms.ToolStrip();
            this.tsbtnXianShi = new System.Windows.Forms.ToolStripButton();
            this.ttssA = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnBookMess = new System.Windows.Forms.ToolStripButton();
            this.tssC = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnJIQ = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbtnExit = new System.Windows.Forms.ToolStripButton();
            this.msCD = new System.Windows.Forms.MenuStrip();
            this.tsmiSystem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiZhuXiao = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiUpdate = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiManager = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiVIPManager = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiUserManager = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiChangYong = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiPiFu = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.ilPic = new System.Windows.Forms.ImageList(this.components);
            this.skePiFu = new Sunisoft.IrisSkin.SkinEngine(((System.ComponentModel.Component)(this)));
            this.stsUser = new System.Windows.Forms.StatusStrip();
            this.tsslUserType = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.tsslTimeNow = new System.Windows.Forms.ToolStripStatusLabel();
            this.tmrTime = new System.Windows.Forms.Timer(this.components);
            this.pnlLeft1 = new System.Windows.Forms.Panel();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.btnBook = new System.Windows.Forms.Button();
            this.btnUsually = new System.Windows.Forms.Button();
            this.btnSystem = new System.Windows.Forms.Button();
            this.btnSystemManager = new System.Windows.Forms.Button();
            this.btnUsuallyManager = new System.Windows.Forms.Button();
            this.btnBookManager = new System.Windows.Forms.Button();
            this.btnRCManager = new System.Windows.Forms.Button();
            this.pnlBG = new System.Windows.Forms.Panel();
            this.pnlRight = new System.Windows.Forms.Panel();
            this.pnlBlue = new System.Windows.Forms.Panel();
            this.picJianTou = new System.Windows.Forms.PictureBox();
            this.tsTool.SuspendLayout();
            this.msCD.SuspendLayout();
            this.stsUser.SuspendLayout();
            this.pnlLeft1.SuspendLayout();
            this.pnlBG.SuspendLayout();
            this.pnlBlue.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picJianTou)).BeginInit();
            this.SuspendLayout();
            // 
            // tsTool
            // 
            this.tsTool.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("tsTool.BackgroundImage")));
            this.tsTool.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbtnXianShi,
            this.ttssA,
            this.tsbtnBookMess,
            this.tssC,
            this.tsbtnJIQ,
            this.toolStripSeparator1,
            this.tsbtnExit});
            this.tsTool.Location = new System.Drawing.Point(0, 25);
            this.tsTool.Name = "tsTool";
            this.tsTool.Size = new System.Drawing.Size(742, 40);
            this.tsTool.TabIndex = 0;
            this.tsTool.Text = "toolStrip1";
            // 
            // tsbtnXianShi
            // 
            this.tsbtnXianShi.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.tsbtnXianShi.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnXianShi.Image")));
            this.tsbtnXianShi.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnXianShi.Name = "tsbtnXianShi";
            this.tsbtnXianShi.Size = new System.Drawing.Size(60, 37);
            this.tsbtnXianShi.Text = "隐藏导航";
            this.tsbtnXianShi.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnXianShi.Click += new System.EventHandler(this.tsbtnXianShi_Click);
            // 
            // ttssA
            // 
            this.ttssA.Name = "ttssA";
            this.ttssA.Size = new System.Drawing.Size(6, 40);
            // 
            // tsbtnBookMess
            // 
            this.tsbtnBookMess.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnBookMess.Image")));
            this.tsbtnBookMess.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.tsbtnBookMess.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnBookMess.Name = "tsbtnBookMess";
            this.tsbtnBookMess.Size = new System.Drawing.Size(60, 37);
            this.tsbtnBookMess.Text = "图书查询";
            this.tsbtnBookMess.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnBookMess.Click += new System.EventHandler(this.tsbtnBookMess_Click);
            // 
            // tssC
            // 
            this.tssC.Name = "tssC";
            this.tssC.Size = new System.Drawing.Size(6, 40);
            // 
            // tsbtnJIQ
            // 
            this.tsbtnJIQ.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnJIQ.Image")));
            this.tsbtnJIQ.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnJIQ.Name = "tsbtnJIQ";
            this.tsbtnJIQ.Size = new System.Drawing.Size(48, 37);
            this.tsbtnJIQ.Text = "计算器";
            this.tsbtnJIQ.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnJIQ.Click += new System.EventHandler(this.tsbtnJSQ_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 40);
            // 
            // tsbtnExit
            // 
            this.tsbtnExit.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnExit.Image")));
            this.tsbtnExit.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnExit.Name = "tsbtnExit";
            this.tsbtnExit.Size = new System.Drawing.Size(60, 37);
            this.tsbtnExit.Text = "退出系统";
            this.tsbtnExit.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.tsbtnExit.Click += new System.EventHandler(this.tsbtnExit_Click);
            // 
            // msCD
            // 
            this.msCD.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("msCD.BackgroundImage")));
            this.msCD.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.msCD.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiSystem,
            this.tsmiManager,
            this.tsmiChangYong,
            this.tsmiHelp});
            this.msCD.Location = new System.Drawing.Point(0, 0);
            this.msCD.Name = "msCD";
            this.msCD.Size = new System.Drawing.Size(742, 25);
            this.msCD.TabIndex = 1;
            this.msCD.Text = "menuStrip1";
            // 
            // tsmiSystem
            // 
            this.tsmiSystem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiZhuXiao,
            this.tsmiUpdate});
            this.tsmiSystem.Name = "tsmiSystem";
            this.tsmiSystem.Size = new System.Drawing.Size(83, 21);
            this.tsmiSystem.Text = "系统设置(&S)";
            // 
            // tsmiZhuXiao
            // 
            this.tsmiZhuXiao.Name = "tsmiZhuXiao";
            this.tsmiZhuXiao.Size = new System.Drawing.Size(144, 22);
            this.tsmiZhuXiao.Text = "注销用户(&X)";
            this.tsmiZhuXiao.Click += new System.EventHandler(this.tsmiZhuXiao_Click);
            // 
            // tsmiUpdate
            // 
            this.tsmiUpdate.Name = "tsmiUpdate";
            this.tsmiUpdate.Size = new System.Drawing.Size(144, 22);
            this.tsmiUpdate.Text = "修改密码(&M)";
            this.tsmiUpdate.Click += new System.EventHandler(this.tsmiUpdate_Click);
            // 
            // tsmiManager
            // 
            this.tsmiManager.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiVIPManager,
            this.tsmiUserManager});
            this.tsmiManager.Name = "tsmiManager";
            this.tsmiManager.Size = new System.Drawing.Size(88, 21);
            this.tsmiManager.Text = "资料管理(&M)";
            // 
            // tsmiVIPManager
            // 
            this.tsmiVIPManager.Name = "tsmiVIPManager";
            this.tsmiVIPManager.Size = new System.Drawing.Size(140, 22);
            this.tsmiVIPManager.Text = "会员管理(&K)";
            this.tsmiVIPManager.Click += new System.EventHandler(this.tsmiVIPManager_Click);
            // 
            // tsmiUserManager
            // 
            this.tsmiUserManager.Name = "tsmiUserManager";
            this.tsmiUserManager.Size = new System.Drawing.Size(140, 22);
            this.tsmiUserManager.Text = "员工管理(&Y)";
            this.tsmiUserManager.Click += new System.EventHandler(this.tsmiUserManager_Click);
            // 
            // tsmiChangYong
            // 
            this.tsmiChangYong.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiPiFu});
            this.tsmiChangYong.Name = "tsmiChangYong";
            this.tsmiChangYong.Size = new System.Drawing.Size(85, 21);
            this.tsmiChangYong.Text = "常用操作(&U)";
            // 
            // tsmiPiFu
            // 
            this.tsmiPiFu.Name = "tsmiPiFu";
            this.tsmiPiFu.ShortcutKeyDisplayString = "ALT+V";
            this.tsmiPiFu.Size = new System.Drawing.Size(186, 22);
            this.tsmiPiFu.Text = "更换皮肤(&V)";
            this.tsmiPiFu.Click += new System.EventHandler(this.tsmiPiFu_Click);
            // 
            // tsmiHelp
            // 
            this.tsmiHelp.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiAbout});
            this.tsmiHelp.Name = "tsmiHelp";
            this.tsmiHelp.Size = new System.Drawing.Size(61, 21);
            this.tsmiHelp.Text = "帮助(&H)";
            // 
            // tsmiAbout
            // 
            this.tsmiAbout.Name = "tsmiAbout";
            this.tsmiAbout.Size = new System.Drawing.Size(180, 22);
            this.tsmiAbout.Text = "关于(图书管理系统)";
            this.tsmiAbout.Click += new System.EventHandler(this.tsmiAbout_Click);
            // 
            // ilPic
            // 
            this.ilPic.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("ilPic.ImageStream")));
            this.ilPic.TransparentColor = System.Drawing.Color.Transparent;
            this.ilPic.Images.SetKeyName(0, "arrow_up_green.png");
            this.ilPic.Images.SetKeyName(1, "arrow_up_green1.png");
            this.ilPic.Images.SetKeyName(2, "arrow_down_blue.png");
            this.ilPic.Images.SetKeyName(3, "arrow_down_blue1.png");
            // 
            // skePiFu
            // 
            this.skePiFu.SerialNumber = "";
            this.skePiFu.SkinFile = null;
            // 
            // stsUser
            // 
            this.stsUser.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsslUserType,
            this.toolStripStatusLabel1,
            this.toolStripStatusLabel2,
            this.tsslTimeNow});
            this.stsUser.Location = new System.Drawing.Point(0, 462);
            this.stsUser.Name = "stsUser";
            this.stsUser.Size = new System.Drawing.Size(742, 22);
            this.stsUser.TabIndex = 4;
            this.stsUser.Text = "statusStrip1";
            // 
            // tsslUserType
            // 
            this.tsslUserType.Name = "tsslUserType";
            this.tsslUserType.Size = new System.Drawing.Size(131, 17);
            this.tsslUserType.Text = "toolStripStatusLabel1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(68, 17);
            this.toolStripStatusLabel1.Text = "欢迎回来！";
            // 
            // toolStripStatusLabel2
            // 
            this.toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            this.toolStripStatusLabel2.Size = new System.Drawing.Size(68, 17);
            this.toolStripStatusLabel2.Text = "当前时间：";
            // 
            // tsslTimeNow
            // 
            this.tsslTimeNow.Name = "tsslTimeNow";
            this.tsslTimeNow.Size = new System.Drawing.Size(131, 17);
            this.tsslTimeNow.Text = "toolStripStatusLabel3";
            // 
            // tmrTime
            // 
            this.tmrTime.Interval = 1000;
            this.tmrTime.Tick += new System.EventHandler(this.tmrTime_Tick);
            // 
            // pnlLeft1
            // 
            this.pnlLeft1.BackColor = System.Drawing.Color.Transparent;
            this.pnlLeft1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pnlLeft1.BackgroundImage")));
            this.pnlLeft1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pnlLeft1.Controls.Add(this.pnlLeft);
            this.pnlLeft1.Controls.Add(this.btnBook);
            this.pnlLeft1.Controls.Add(this.btnUsually);
            this.pnlLeft1.Controls.Add(this.btnSystem);
            this.pnlLeft1.Controls.Add(this.btnSystemManager);
            this.pnlLeft1.Controls.Add(this.btnUsuallyManager);
            this.pnlLeft1.Controls.Add(this.btnBookManager);
            this.pnlLeft1.Controls.Add(this.btnRCManager);
            this.pnlLeft1.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft1.Location = new System.Drawing.Point(0, 65);
            this.pnlLeft1.Name = "pnlLeft1";
            this.pnlLeft1.Size = new System.Drawing.Size(138, 397);
            this.pnlLeft1.TabIndex = 5;
            // 
            // pnlLeft
            // 
            this.pnlLeft.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.pnlLeft.Location = new System.Drawing.Point(0, 23);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Size = new System.Drawing.Size(138, 305);
            this.pnlLeft.TabIndex = 7;
            // 
            // btnBook
            // 
            this.btnBook.BackColor = System.Drawing.Color.Transparent;
            this.btnBook.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnBook.ForeColor = System.Drawing.Color.Black;
            this.btnBook.Location = new System.Drawing.Point(0, 328);
            this.btnBook.Name = "btnBook";
            this.btnBook.Size = new System.Drawing.Size(138, 23);
            this.btnBook.TabIndex = 3;
            this.btnBook.Text = "图书管理";
            this.btnBook.UseVisualStyleBackColor = false;
            this.btnBook.Click += new System.EventHandler(this.btnBook_Click);
            // 
            // btnUsually
            // 
            this.btnUsually.BackColor = System.Drawing.Color.Transparent;
            this.btnUsually.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnUsually.ForeColor = System.Drawing.Color.Black;
            this.btnUsually.Location = new System.Drawing.Point(0, 351);
            this.btnUsually.Name = "btnUsually";
            this.btnUsually.Size = new System.Drawing.Size(138, 23);
            this.btnUsually.TabIndex = 2;
            this.btnUsually.Text = "常用操作";
            this.btnUsually.UseVisualStyleBackColor = false;
            this.btnUsually.Click += new System.EventHandler(this.btnUsually_Click);
            // 
            // btnSystem
            // 
            this.btnSystem.BackColor = System.Drawing.Color.Transparent;
            this.btnSystem.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnSystem.ForeColor = System.Drawing.Color.Black;
            this.btnSystem.Location = new System.Drawing.Point(0, 374);
            this.btnSystem.Name = "btnSystem";
            this.btnSystem.Size = new System.Drawing.Size(138, 23);
            this.btnSystem.TabIndex = 0;
            this.btnSystem.Text = "系统管理";
            this.btnSystem.UseVisualStyleBackColor = false;
            this.btnSystem.Click += new System.EventHandler(this.btnSystem_Click);
            // 
            // btnSystemManager
            // 
            this.btnSystemManager.BackColor = System.Drawing.Color.Transparent;
            this.btnSystemManager.ForeColor = System.Drawing.Color.Black;
            this.btnSystemManager.Location = new System.Drawing.Point(0, 69);
            this.btnSystemManager.Name = "btnSystemManager";
            this.btnSystemManager.Size = new System.Drawing.Size(138, 23);
            this.btnSystemManager.TabIndex = 0;
            this.btnSystemManager.Text = "系统管理";
            this.btnSystemManager.UseVisualStyleBackColor = false;
            this.btnSystemManager.Click += new System.EventHandler(this.btnSystemManager_Click);
            // 
            // btnUsuallyManager
            // 
            this.btnUsuallyManager.BackColor = System.Drawing.Color.Transparent;
            this.btnUsuallyManager.ForeColor = System.Drawing.Color.Black;
            this.btnUsuallyManager.Location = new System.Drawing.Point(0, 46);
            this.btnUsuallyManager.Name = "btnUsuallyManager";
            this.btnUsuallyManager.Size = new System.Drawing.Size(138, 23);
            this.btnUsuallyManager.TabIndex = 0;
            this.btnUsuallyManager.Text = "常用操作";
            this.btnUsuallyManager.UseVisualStyleBackColor = false;
            this.btnUsuallyManager.Click += new System.EventHandler(this.btnUsuallyManager_Click);
            // 
            // btnBookManager
            // 
            this.btnBookManager.BackColor = System.Drawing.Color.Transparent;
            this.btnBookManager.ForeColor = System.Drawing.Color.Black;
            this.btnBookManager.Location = new System.Drawing.Point(0, 23);
            this.btnBookManager.Name = "btnBookManager";
            this.btnBookManager.Size = new System.Drawing.Size(138, 23);
            this.btnBookManager.TabIndex = 0;
            this.btnBookManager.Text = "图书管理";
            this.btnBookManager.UseVisualStyleBackColor = false;
            this.btnBookManager.Click += new System.EventHandler(this.btnBookManager_Click);
            // 
            // btnRCManager
            // 
            this.btnRCManager.BackColor = System.Drawing.Color.Transparent;
            this.btnRCManager.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnRCManager.ForeColor = System.Drawing.Color.Black;
            this.btnRCManager.Location = new System.Drawing.Point(0, 0);
            this.btnRCManager.Name = "btnRCManager";
            this.btnRCManager.Size = new System.Drawing.Size(138, 23);
            this.btnRCManager.TabIndex = 0;
            this.btnRCManager.Text = "日常管理";
            this.btnRCManager.UseVisualStyleBackColor = false;
            this.btnRCManager.Click += new System.EventHandler(this.btnRCManager_Click);
            // 
            // pnlBG
            // 
            this.pnlBG.BackColor = System.Drawing.Color.Transparent;
            this.pnlBG.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pnlBG.Controls.Add(this.pnlRight);
            this.pnlBG.Controls.Add(this.pnlBlue);
            this.pnlBG.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlBG.Location = new System.Drawing.Point(138, 65);
            this.pnlBG.Name = "pnlBG";
            this.pnlBG.Size = new System.Drawing.Size(604, 397);
            this.pnlBG.TabIndex = 6;
            // 
            // pnlRight
            // 
            this.pnlRight.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.pnlRight.AutoScroll = true;
            this.pnlRight.AutoScrollMargin = new System.Drawing.Size(1, 1);
            this.pnlRight.AutoScrollMinSize = new System.Drawing.Size(1, 1);
            this.pnlRight.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pnlRight.Location = new System.Drawing.Point(20, 0);
            this.pnlRight.Name = "pnlRight";
            this.pnlRight.Size = new System.Drawing.Size(584, 397);
            this.pnlRight.TabIndex = 3;
            // 
            // pnlBlue
            // 
            this.pnlBlue.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.pnlBlue.BackColor = System.Drawing.Color.Transparent;
            this.pnlBlue.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pnlBlue.BackgroundImage")));
            this.pnlBlue.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pnlBlue.Controls.Add(this.picJianTou);
            this.pnlBlue.Location = new System.Drawing.Point(0, 0);
            this.pnlBlue.MaximumSize = new System.Drawing.Size(20, 651);
            this.pnlBlue.MinimumSize = new System.Drawing.Size(20, 397);
            this.pnlBlue.Name = "pnlBlue";
            this.pnlBlue.Size = new System.Drawing.Size(20, 397);
            this.pnlBlue.TabIndex = 1;
            // 
            // picJianTou
            // 
            this.picJianTou.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.picJianTou.BackColor = System.Drawing.Color.White;
            this.picJianTou.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picJianTou.Location = new System.Drawing.Point(0, 187);
            this.picJianTou.Name = "picJianTou";
            this.picJianTou.Size = new System.Drawing.Size(20, 22);
            this.picJianTou.TabIndex = 0;
            this.picJianTou.TabStop = false;
            this.picJianTou.MouseLeave += new System.EventHandler(this.picJianTou_MouseLeave);
            this.picJianTou.MouseMove += new System.Windows.Forms.MouseEventHandler(this.picJianTou_MouseMove);
            this.picJianTou.Click += new System.EventHandler(this.picJianTou_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(742, 484);
            this.Controls.Add(this.pnlBG);
            this.Controls.Add(this.pnlLeft1);
            this.Controls.Add(this.stsUser);
            this.Controls.Add(this.tsTool);
            this.Controls.Add(this.msCD);
            this.DoubleBuffered = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.msCD;
            this.MinimumSize = new System.Drawing.Size(758, 522);
            this.Name = "FormMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "图书管理系统";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormMain_FormClosed);
            this.tsTool.ResumeLayout(false);
            this.tsTool.PerformLayout();
            this.msCD.ResumeLayout(false);
            this.msCD.PerformLayout();
            this.stsUser.ResumeLayout(false);
            this.stsUser.PerformLayout();
            this.pnlLeft1.ResumeLayout(false);
            this.pnlBG.ResumeLayout(false);
            this.pnlBlue.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picJianTou)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip tsTool;
        private System.Windows.Forms.MenuStrip msCD;
        private System.Windows.Forms.ToolStripMenuItem tsmiSystem;
        private System.Windows.Forms.ToolStripMenuItem tsmiManager;
        private System.Windows.Forms.ToolStripMenuItem tsmiChangYong;
        private System.Windows.Forms.ToolStripMenuItem tsmiHelp;
        private System.Windows.Forms.ToolStripSeparator tssC;
        private System.Windows.Forms.ToolStripButton tsbtnXianShi;
        private System.Windows.Forms.ToolStripSeparator ttssA;
        private System.Windows.Forms.ImageList ilPic;
        private System.Windows.Forms.ToolStripButton tsbtnExit;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton tsbtnBookMess;
        private System.Windows.Forms.ToolStripButton tsbtnJIQ;
        private System.Windows.Forms.ToolStripMenuItem tsmiUpdate;
        private System.Windows.Forms.ToolStripMenuItem tsmiZhuXiao;
        private System.Windows.Forms.ToolStripMenuItem tsmiPiFu;
        public Sunisoft.IrisSkin.SkinEngine skePiFu;
        private System.Windows.Forms.ToolStripMenuItem tsmiVIPManager;
        private System.Windows.Forms.ToolStripMenuItem tsmiUserManager;
        private System.Windows.Forms.ToolStripMenuItem tsmiAbout;
        private System.Windows.Forms.StatusStrip stsUser;
        private System.Windows.Forms.ToolStripStatusLabel tsslUserType;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel2;
        private System.Windows.Forms.ToolStripStatusLabel tsslTimeNow;
        private System.Windows.Forms.Timer tmrTime;
        public System.Windows.Forms.Panel pnlLeft1;
        public System.Windows.Forms.Panel pnlLeft;
        private System.Windows.Forms.Button btnBook;
        private System.Windows.Forms.Button btnUsually;
        private System.Windows.Forms.Button btnSystem;
        private System.Windows.Forms.Button btnSystemManager;
        private System.Windows.Forms.Button btnUsuallyManager;
        private System.Windows.Forms.Button btnBookManager;
        private System.Windows.Forms.Button btnRCManager;
        public System.Windows.Forms.Panel pnlBG;
        public System.Windows.Forms.Panel pnlRight;
        private System.Windows.Forms.Panel pnlBlue;
        private System.Windows.Forms.PictureBox picJianTou;
    }
}