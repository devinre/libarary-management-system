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
        /// 获取所有员工信息
        /// </summary>
        /// <returns></returns>
        public IList<Users> GetAllUsers()
        {
            return us.GetAllUsers();
        }
        /// <summary>
        /// 修改员工信息
        /// </summary>
        /// <param name="u"></param>
        /// <returns></returns>
        public string UpdateUsers(Users u)
        {
            return us.UpdateUsers(u);
        }
        /// <summary>
        /// 获取角色信息
        /// </summary>
        /// <returns></returns>
        public IList<Roles> GetRolesMess()
        {
            return us.GetRolesMess();
        }
        /// <summary>
        /// 添加员工信息
        /// </summary>
        /// <param name="u"></param>
        /// <returns></returns>
        public string AddUsersMess(Users u,string id)
        {
            return us.AddUserMess(u,id);
        }
        /// <summary>
        /// 删除员工信息
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public string DeleteUserMess(int id)
        {
            return us.DeleteUserMess(id);
        }
        /// <summary>
        /// 检测账号是否存在
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public string JudgeUser(string id)
        {
            return us.JudgeUsers(id);
        }
        /// <summary>
        /// 登录信息检测
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
        /// 通过员工账号查询员工姓名
        /// </summary>
        /// <param name="uid"></param>
        /// <returns></returns>
        public string GetUserNameBuUID(string uid)
        {
            return us.GetUserNameByUID(uid);
        }
        /// <summary>
        /// 修改登录人员密码
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
