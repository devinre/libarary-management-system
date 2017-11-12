using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using LibraryManagerBLL;

namespace LibraryManager
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            //������ؼ��ػ���������˸
            this.SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.DoubleBuffer | ControlStyles.UserPaint, true);
            InitializeComponent();
        }
        //���Ƶ���������ʾ������
        private void tsbtnXianShi_Click(object sender, EventArgs e)
        {

            if (pnlLeft1.Visible == true)
            {
                pnlLeft1.Visible = false;
            }
            else
            {
                pnlLeft1.Visible = true;
            }
            aShow();
        }
        //�˳���ť
        private void tsbtnExit_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("ȷ���˳�ϵͳ��","ϵͳ��ʾ",MessageBoxButtons.OKCancel,MessageBoxIcon.Question);
            if (r == DialogResult.OK) 
            {
                Application.Exit();
            }
        }
        //��������ʾ�����صķ���
        public void aShow() 
        {
            if (pnlLeft1.Visible == true) 
            {
                tsbtnXianShi.Text = "���ص���";

            }
            else if (pnlLeft1.Visible == false) 
            {
                tsbtnXianShi.Text = "��ʾ����";
            }
            if (tsbtnXianShi.Text == "���ص���")
            {
                picJianTou.BackgroundImage = ilPic.Images[0];
            }
            else if (tsbtnXianShi.Text == "��ʾ����")
            {
                picJianTou.BackgroundImage = ilPic.Images[1];
            }
        }
        List<Control> c;
        //�����LOAD�¼�
        private void FormMain_Load(object sender, EventArgs e)
        {
            RiChangControl richang = new RiChangControl();
            BookManagerControl book = new BookManagerControl();
            UsuallyControl usually = new UsuallyControl();
            SystemControl sc = new SystemControl();
            c = new List<Control>();
            c.Add(richang);
            c.Add(book);
            c.Add(usually);
            c.Add(sc);
            pnlLeft.Controls.Add(c[0]);
            //sc.btnChange.Click += new EventHandler(btnChange_Click);
            string uid = this.Tag.ToString();
            tsslUserType.Text = uid;
            tsslTimeNow.Text = DateTime.Now.ToString("yyyy-MM-dd H:mm:ss");
            //����TIMER�ռ�
            tmrTime.Start();
            this.LoadSkinSSKName();
            //this.TopLevel = false;//ȡ���ô���Ķ����ؼ�����
            picJianTou.BackgroundImage = ilPic.Images[0];
            btnUsuallyManager.Visible = false;
            btnBookManager.Visible = false;
            btnSystemManager.Visible = false;
            btnUsually.Visible = true;
            btnBook.Visible = true;
            btnSystem.Visible = true;
            pnlLeft.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0, 23);
            aShow();

        }

        void btnChange_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("�Ƿ�ע���û���", "�� ʾ", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (r == DialogResult.Yes)
            {
                FormLogin fl = new FormLogin();
                fl.Show();
                this.Visible = false;
                
            }
        }
        //���ص�ǰϵͳĿ¼�µ�ssk�ļ�����
        /// <summary>
        /// ���ص�ǰϵͳĿ¼�µ�ssk�ļ�����
        /// </summary>
        public void LoadSkinSSKName()
        {
            //��ȡ����ļ���Ŀ¼ 
            string directoryPath = Application.StartupPath;
            //����Ŀ¼���� 
            DirectoryInfo dir = new DirectoryInfo(directoryPath);
            //��ȡĿ¼�µ������ļ� 
            FileSystemInfo[] infos = dir.GetFileSystemInfos();

            //�����ļ����ϣ������е��ļ���listbox��ʾ 
            foreach (FileSystemInfo myfile in infos)
            {
                if (myfile.Extension == ".ssk")
                {
                    this.skePiFu.SkinFile = directoryPath + "\\" + Convert.ToString(myfile);
                }
            }
        }
        /// <summary>
        /// ����button��visible���Դﵽ���������л�
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnRCManager_Click(object sender, EventArgs e)
        {
            //btnSystem.Location = new System.Drawing.Point(0,373);
            btnUsuallyManager.Visible = false;
            btnBookManager.Visible = false;
            btnSystemManager.Visible = false;
            btnUsually.Visible = true;
            btnBook.Visible = true;
            btnSystem.Visible = true;
            pnlLeft.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0, 23);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[0]);
            aShow();
        }

        private void btnBookManager_Click(object sender, EventArgs e)
        {
            btnUsually.Visible = true;
            btnSystem.Visible = true;
            btnUsuallyManager.Visible = false;
            btnSystemManager.Visible = false;
            pnlLeft.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0, 46);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[1]);
            Show();
        }

        private void btnUsuallyManager_Click(object sender, EventArgs e)
        {
            btnBookManager.Visible = true;
            btnUsuallyManager.Visible = true;
            btnSystemManager.Visible = false;
            btnSystem.Visible = true;
            btnBook.Visible = false;
            btnUsually.Visible = false;
            pnlLeft.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0, 69);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[2]);
            aShow();
        }

        private void btnSystemManager_Click(object sender, EventArgs e)
        {
            pnlLeft.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0, 92);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[3]);
            SystemControl sc=c[3] as SystemControl;
            if (sc!=null)
            {
                sc.btnChange.Click+=new EventHandler(btnChange_Click);
            }
            aShow();
        }

        private void btnBook_Click(object sender, EventArgs e)
        {
            btnBook.Visible = false;
            btnBookManager.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0,46);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[1]);
            Show();
        }

        private void btnUsually_Click(object sender, EventArgs e)
        {
            btnBook.Visible = false;
            btnUsually.Visible = false;
            btnBookManager.Visible = true;
            btnUsuallyManager.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0,69);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[2]);
            aShow();
        }

        private void btnSystem_Click(object sender, EventArgs e)
        {
            btnUsually.Visible = false;
            btnBook.Visible = false;
            btnSystem.Visible = false;
            btnUsuallyManager.Visible = true;
            btnBookManager.Visible = true;
            btnSystemManager.Visible = true;
            pnlLeft.Location = new System.Drawing.Point(0, 92);
            pnlLeft.Controls.Clear();
            pnlLeft.Controls.Add(c[3]);
            SystemControl sc = c[3] as SystemControl;
            if (sc != null)
            {
                sc.btnChange.Click += new EventHandler(btnChange_Click);
            }
            aShow();
        }

        [System.Runtime.InteropServices.DllImportAttribute("user32.dll", EntryPoint = "MoveWindow")]
        public static extern bool MoveWindow(System.IntPtr hWnd, int X, int Y, int nWidth, int nHeight, bool bRepaint);

        //�������ĵ���¼�
        private void tsbtnJSQ_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process p = System.Diagnostics.Process.Start(@"C:\Windows\System32\calc.exe");
            p.WaitForInputIdle();
            MoveWindow(p.MainWindowHandle,500,200,300,200,true);
        }
        private void picJianTou_Click(object sender, EventArgs e)
        {
            if (pnlLeft1.Visible == true)
            {
                pnlLeft1.Visible = false;
            }
            else
            {
                pnlLeft1.Visible = true;
            }
            aShow();
        }
        //����뿪�ؼ�ʱ
        private void picJianTou_MouseLeave(object sender, EventArgs e)
        {
            if (tsbtnXianShi.Text == "���ص���")
            {
                picJianTou.BackgroundImage = ilPic.Images[0];
            }
            else if (tsbtnXianShi.Text == "��ʾ����")
            {
                picJianTou.BackgroundImage = ilPic.Images[1];
            }
        }
        //��껮���ؼ�ʱ
        private void picJianTou_MouseMove(object sender, MouseEventArgs e)
        {
            if (tsbtnXianShi.Text == "���ص���")
            {
                picJianTou.BackgroundImage = ilPic.Images[2];
            }
            else if (tsbtnXianShi.Text == "��ʾ����")
            {
                picJianTou.BackgroundImage = ilPic.Images[3];
            }
        }

        private void tsmiPiFu_Click(object sender, EventArgs e)
        {
            FormSkin fs = new FormSkin(this);
            fs.ShowDialog(this);
        }

        private void tsmiVIPManager_Click(object sender, EventArgs e)
        {
            FormUserTable fu = FormUserTable.CreateForm();
            fu.Show();
            fu.BringToFront();
        }

        private void tsmiUserManager_Click(object sender, EventArgs e)
        {
            FormUserManager fu = FormUserManager.CreateForm();
            fu.Show();
            fu.BringToFront();
        }

        private void tsbtnBookMess_Click(object sender, EventArgs e)
        {
            FormBookMess fb = FormBookMess.CreateForm();
            fb.Show();
            fb.BringToFront();
        }

        private void tsmiAbout_Click(object sender, EventArgs e)
        {
            FormAbout fa = FormAbout.CreateForm();
            fa.Show();
            fa.BringToFront();
        }

        private void tsmiZhuXiao_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("�Ƿ�ע���û���", "�� ʾ", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (r == DialogResult.Yes)
            {
                ((FormMain)this.Parent.Parent.Parent).Close();
                ((FormMain)this.Parent.Parent.Parent).Owner.Visible = true;
                ((FormLogin)((FormMain)this.Parent.Parent.Parent).Owner).txtID.Text = "";
                ((FormLogin)((FormMain)this.Parent.Parent.Parent).Owner).txtPWD.Text = "";
            }
        }

        private void tsmiUpdate_Click(object sender, EventArgs e)
        {
            FormUpdataPWD fu = FormUpdataPWD.CreateForm();
            fu.Show();
            fu.BringToFront();
        }

        private void FormMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void tmrTime_Tick(object sender, EventArgs e)
        {
            tsslTimeNow.Text = DateTime.Now.ToString("yyyy-MM-dd H:mm:ss");
        }
    }
}