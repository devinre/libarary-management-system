using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class Users
    {
        protected int userID;
        /// <summary>
        /// 员工编号
        /// </summary>
        public int UserID
        {
            get { return userID; }
            set { userID = value; }
        }

        protected string userUID;
        /// <summary>
        /// 员工账号
        /// </summary>
        public string UserUID
        {
            get { return userUID; }
            set { userUID = value; }
        }

        protected string userPwd;
        /// <summary>
        /// 员工密码
        /// </summary>
        public string UserPwd
        {
            get { return userPwd; }
            set { userPwd = value; }
        }

        protected string userName;
        /// <summary>
        /// 员工姓名
        /// </summary>
        public string UserName
        {
            get { return userName; }
            set { userName = value; }
        }

        protected string rolesName;
        /// <summary>
        /// 角色名称
        /// </summary>
        public string RolesName
        {
            get { return rolesName; }
            set { rolesName = value; }
        }

        protected int roleID;
        /// <summary>
        /// 角色ID
        /// </summary>
        public int RoleID
        {
            get { return roleID; }
            set { roleID = value; }
        }
        protected string userSex;
        /// <summary>
        /// 员工性别
        /// </summary>
        public string UserSex
        {
            get { return userSex; }
            set { userSex = value; }
        }
    }
}
