using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace LibraryManager
{
    public partial class FormSkin : Form
    {
        FormMain frmmain;
        //��ǰĿ¼·���µ�SSK�ļ���·��
        /// <summary>
        /// ��ǰĿ¼·���µ�SSK�ļ���·��
        /// </summary>
        string SkinFilesPath = Application.StartupPath + "\\SkinFiles";
        public FormSkin(FormMain main)
        {
            InitializeComponent();
            this.frmmain = main;
            this.LoadSkinFileName();    //����ϵͳĿ¼�µ�ssk�ļ�����
        }
        private void btnOK_Click(object sender, EventArgs e)
        {
            if (this.listViewSkinList.SelectedItems.Count >= 1)
            {
                if (this.listViewSkinList.SelectedItems[0].Text == "����ʽ")
                {
                    this.frmmain.skePiFu.Active = false;
                    this.frmmain.skePiFu.SkinFile = "";
                    this.frmmain.skePiFu.Enable3rdControl = false;
                    this.DelSkinFile();    //ɾ����ǰĿ¼�µ�ssk�ļ�����
                }
                else
                {
                    this.DelSkinFile(this.listViewSkinList.SelectedItems[0].Text + ".ssk");    //ɾ���Ѿ��е�Ƥ���ļ�,�������µ�ssk�ļ�
                    this.frmmain.LoadSkinSSKName();    //�����������¼���ssk�ļ�
                }
            }
            this.Close();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //ѡ��SSK�ļ�����
        private void listViewSkinList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.listViewSkinList.SelectedItems.Count >= 1)
            {
                this.pictureSkinShow.ImageLocation = this.SkinFilesPath + "\\" + this.listViewSkinList.SelectedItems[0].Text + ".gif";
            }
        }

        //ɾ���Ѿ��е�Ƥ���ļ�
        /// <summary>
        /// ɾ���Ѿ��е�Ƥ���ļ�
        /// </summary>
        private void DelSkinFile()
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
                    File.Delete(directoryPath + "\\" + Convert.ToString(myfile));  //ɾ��ϵͳͼƬ�ļ�����ѡ���ͼƬ
                }
            }
        }

        //ɾ���Ѿ��е�Ƥ���ļ�,�������µ�ssk�ļ�
        /// <summary>
        /// ɾ���Ѿ��е�Ƥ���ļ�,�������µ�ssk�ļ�
        /// </summary>
        /// <param name="SelectSkinFile">ѡ���Ƥ���ļ�����</param>
        private void DelSkinFile(string SelectSkinFile)
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
                    File.Delete(directoryPath + "\\" + Convert.ToString(myfile));  //ɾ��ϵͳͼƬ�ļ�����ѡ���ͼƬ
                }
            }
            File.Copy(this.SkinFilesPath + "\\" + SelectSkinFile, Application.StartupPath + "\\" + SelectSkinFile);
        }

        //���ص�ǰ·�������ssk�ļ�����....
        /// <summary>
        /// ���ص�ǰ·�������ssk�ļ�����
        /// </summary>
        private void LoadSkinFileName()
        {
            this.listViewSkinList.Items.Clear();
            this.listViewSkinList.Items.Add("����ʽ");
            this.listViewSkinList.Items[0].Selected = true;
            this.pictureSkinShow.ImageLocation = this.SkinFilesPath + "\\" + "����ʽ.gif";
            //����Ŀ¼���� 
            DirectoryInfo dir = new DirectoryInfo(this.SkinFilesPath);
            //��ȡĿ¼�µ������ļ� 
            FileSystemInfo[] infos = dir.GetFileSystemInfos();

            //�����ļ����ϣ������е��ļ���listbox��ʾ 
            foreach (FileSystemInfo myfile in infos)
            {
                if (myfile.Extension == ".ssk")
                {
                    this.listViewSkinList.Items.Add(myfile.Name.Substring(0, myfile.Name.IndexOf('.')));   //���ssk�ļ�����
                }
            }
        }
    }
}