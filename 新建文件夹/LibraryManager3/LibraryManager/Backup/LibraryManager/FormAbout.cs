using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace LibraryManager
{
    public partial class FormAbout : Form
    {
        private FormAbout()
        {
            InitializeComponent();
        }
        static FormAbout fa;
        public static FormAbout CreateForm()
        {
            if (fa==null)
            {
                fa = new FormAbout();
                fa.TopMost = true;
            }
            return fa;
        }
        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void FormAbout_FormClosed(object sender, FormClosedEventArgs e)
        {
            fa = null;
        }
    }
}