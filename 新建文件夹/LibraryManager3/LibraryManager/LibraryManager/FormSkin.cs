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
        //当前目录路径下的SSK文件夹路径
        /// <summary>
        /// 当前目录路径下的SSK文件夹路径
        /// </summary>
        string SkinFilesPath = Application.StartupPath + "\\SkinFiles";
        public FormSkin(FormMain main)
        {
            InitializeComponent();
            this.frmmain = main;
            this.LoadSkinFileName();    //加载系统目录下的ssk文件名称
        }
        private void btnOK_Click(object sender, EventArgs e)
        {
            if (this.listViewSkinList.SelectedItems.Count >= 1)
            {
                if (this.listViewSkinList.SelectedItems[0].Text == "无样式")
                {
                    this.frmmain.skePiFu.Active = false;
                    this.frmmain.skePiFu.SkinFile = "";
                    this.frmmain.skePiFu.Enable3rdControl = false;
                    this.DelSkinFile();    //删除当前目录下的ssk文件名称
                }
                else
                {
                    this.DelSkinFile(this.listViewSkinList.SelectedItems[0].Text + ".ssk");    //删除已经有的皮肤文件,并复制新的ssk文件
                    this.frmmain.LoadSkinSSKName();    //让主窗体重新加载ssk文件
                }
            }
            this.Close();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //选择SSK文件名称
        private void listViewSkinList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.listViewSkinList.SelectedItems.Count >= 1)
            {
                this.pictureSkinShow.ImageLocation = this.SkinFilesPath + "\\" + this.listViewSkinList.SelectedItems[0].Text + ".gif";
            }
        }

        //删除已经有的皮肤文件
        /// <summary>
        /// 删除已经有的皮肤文件
        /// </summary>
        private void DelSkinFile()
        {
            //获取存放文件的目录 
            string directoryPath = Application.StartupPath;
            //创建目录对象 
            DirectoryInfo dir = new DirectoryInfo(directoryPath);
            //获取目录下的所有文件 
            FileSystemInfo[] infos = dir.GetFileSystemInfos();

            //遍历文件集合，将所有的文件用listbox显示 
            foreach (FileSystemInfo myfile in infos)
            {
                if (myfile.Extension == ".ssk")
                {
                    File.Delete(directoryPath + "\\" + Convert.ToString(myfile));  //删除系统图片文件夹中选择的图片
                }
            }
        }

        //删除已经有的皮肤文件,并复制新的ssk文件
        /// <summary>
        /// 删除已经有的皮肤文件,并复制新的ssk文件
        /// </summary>
        /// <param name="SelectSkinFile">选择的皮肤文件名称</param>
        private void DelSkinFile(string SelectSkinFile)
        {
            //获取存放文件的目录 
            string directoryPath = Application.StartupPath;
            //创建目录对象 
            DirectoryInfo dir = new DirectoryInfo(directoryPath);
            //获取目录下的所有文件 
            FileSystemInfo[] infos = dir.GetFileSystemInfos();

            //遍历文件集合，将所有的文件用listbox显示 
            foreach (FileSystemInfo myfile in infos)
            {
                if (myfile.Extension == ".ssk")
                {
                    File.Delete(directoryPath + "\\" + Convert.ToString(myfile));  //删除系统图片文件夹中选择的图片
                }
            }
            File.Copy(this.SkinFilesPath + "\\" + SelectSkinFile, Application.StartupPath + "\\" + SelectSkinFile);
        }

        //加载当前路径下面的ssk文件名称....
        /// <summary>
        /// 加载当前路径下面的ssk文件名称
        /// </summary>
        private void LoadSkinFileName()
        {
            this.listViewSkinList.Items.Clear();
            this.listViewSkinList.Items.Add("无样式");
            this.listViewSkinList.Items[0].Selected = true;
            this.pictureSkinShow.ImageLocation = this.SkinFilesPath + "\\" + "无样式.gif";
            //创建目录对象 
            DirectoryInfo dir = new DirectoryInfo(this.SkinFilesPath);
            //获取目录下的所有文件 
            FileSystemInfo[] infos = dir.GetFileSystemInfos();

            //遍历文件集合，将所有的文件用listbox显示 
            foreach (FileSystemInfo myfile in infos)
            {
                if (myfile.Extension == ".ssk")
                {
                    this.listViewSkinList.Items.Add(myfile.Name.Substring(0, myfile.Name.IndexOf('.')));   //添加ssk文件名称
                }
            }
        }
    }
}