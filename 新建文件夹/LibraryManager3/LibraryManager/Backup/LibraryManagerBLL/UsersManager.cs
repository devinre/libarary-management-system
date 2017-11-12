using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerDAL;
using LibraryManagerModels;

namespace LibraryManagerBLL
{
    public class UsersManager
    {
        UsersService us = new UsersService();
        /// <summary>
        /// ��ȡ����Ա����Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<Users> GetAllUsers()
        {
            return us.GetAllUsers();
        }
        /// <summary>
        /// �޸�Ա����Ϣ
        /// </summary>
        /// <param name="u"></param>
        /// <returns></returns>
        public string UpdateUsers(Users u)
        {
            return us.UpdateUsers(u);
        }
        /// <summary>
        /// ��ȡ��ɫ��Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<Roles> GetRolesMess()
        {
            return us.GetRolesMess();
        }
        /// <summary>
        /// ���Ա����Ϣ
        /// </summary>
        /// <param name="u"></param>
        /// <returns></returns>
        public string AddUsersMess(Users u,string id)
        {
            return us.AddUserMess(u,id);
        }
        /// <summary>
        /// ɾ��Ա����Ϣ
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public string DeleteUserMess(int id)
        {
            return us.DeleteUserMess(id);
        }
        /// <summary>
        /// ����˺��Ƿ����
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public string JudgeUser(string id)
        {
            return us.JudgeUsers(id);
        }
        /// <summary>
        /// ��¼��Ϣ���
        /// </summary>
        /// <param name="uid"></param>
        /// <param name="pwd"></param>
        /// <param name="rid"></param>
        /// <returns></returns>
        public string JudgeLogin(string uid,string pwd,int rid)
        {
            return us.JudgeUserLogin(uid, pwd, rid);
        }
        /// <summary>
        /// ͨ��Ա���˺Ų�ѯԱ������
        /// </summary>
        /// <param name="uid"></param>
        /// <returns></returns>
        public string GetUserNameBuUID(string uid)
        {
            return us.GetUserNameByUID(uid);
        }
        /// <summary>
        /// �޸ĵ�¼��Ա����
        /// </summary>
        /// <param name="pwd"></param>
        /// <param name="id"></param>
        /// <returns></returns>
        public string UpdateUserPWD(string pwd, string id)
        {
            return us.UpdateUserPWD(pwd,id);
        }
    }
}
