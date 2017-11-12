using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace LibraryManager
{
    public partial class FormPicture : Form
    {
        public FormPicture()
        {
            InitializeComponent();
        }

        private void tmrPic_Tick(object sender, EventArgs e)
        {
            Opacity -= 0.05;
            if (Opacity==0)
            {
                tmrPic.Stop();
                FormLogin fl = new FormLogin();
                fl.Owner = this;
                fl.Show();
                this.Visible = false ;
            }
        }
    }
}