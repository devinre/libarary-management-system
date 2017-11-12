using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace LibraryManager
{
    public partial class SystemControl : UserControl
    {
        public SystemControl()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("ȷ��Ҫ�˳���ϵͳ��", "������ʾ", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (r == DialogResult.Yes)
            {
                Application.Exit();
            }
        }

        private void btnChange_Click(object sender, EventArgs e)
        {
           
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            FormUpdataPWD fu = FormUpdataPWD.CreateForm();
            fu.Show(); 
            fu.BringToFront();
        }
    }
}
