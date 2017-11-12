using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace LibraryManager
{
    public partial class UsuallyControl : UserControl
    {
        public UsuallyControl()
        {
            InitializeComponent();
        }

        private void btnZuJin_Click(object sender, EventArgs e)
        {
            FormPriceManager fp = FormPriceManager.CreateForm();
            fp.Show();
            fp.BringToFront();

        }

        private void btnCardType_Click(object sender, EventArgs e)
        {
            FormCardManager fc = FormCardManager.CreateForm();
            fc.Show();
            fc.BringToFront();
        }

        [System.Runtime.InteropServices.DllImportAttribute("user32.dll", EntryPoint = "MoveWindow")]
        public static extern bool MoveWindow(System.IntPtr hWnd, int X, int Y, int nWidth, int nHeight, bool bRepaint);
        
        private void btnCounter_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process p = System.Diagnostics.Process.Start(@"C:\Windows\System32\calc.exe");
            p.WaitForInputIdle();
            MoveWindow(p.MainWindowHandle, 500, 200, 300, 200, true);
        }
    }
}
