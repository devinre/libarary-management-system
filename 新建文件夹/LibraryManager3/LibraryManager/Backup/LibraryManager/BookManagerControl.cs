using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace LibraryManager
{
    public partial class BookManagerControl : UserControl
    {
        public BookManagerControl()
        {
            InitializeComponent();
        }

        private void btnLendBook_Click(object sender, EventArgs e)
        {
            FormLendManager fl = FormLendManager.CreateForm();
            fl.Show();
            fl.BringToFront();
        }

        private void btnBookManager_Click(object sender, EventArgs e)
        {
            FormBookManager fb = FormBookManager.CreateForm();
            fb.Show();
            fb.BringToFront();
        }

        private void btnReturnBook_Click(object sender, EventArgs e)
        {
            FormReturnBook fr = FormReturnBook.CreateForm();
            fr.Show();
            fr.BringToFront();
        }
    }
}
