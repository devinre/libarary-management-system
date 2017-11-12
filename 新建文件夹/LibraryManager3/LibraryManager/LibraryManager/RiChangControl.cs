using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace LibraryManager
{
    public partial class RiChangControl : UserControl
    {
        public RiChangControl()
        {
            InitializeComponent();
        }

        private void btnHYManager_Click(object sender, EventArgs e)
        {
            FormUserTable fu = FormUserTable.CreateForm();
            fu.Show();
            fu.BringToFront();
        }

        private void btnUserManager_Click(object sender, EventArgs e)
        {
            FormUserManager fu = FormUserManager.CreateForm();
            fu.Show();
            fu.BringToFront();
        }

        private void btnBookMess_Click(object sender, EventArgs e)
        {
            FormBookMess fb = FormBookMess.CreateForm();
            fb.Show();
            fb.BringToFront();
        }
    }
}
