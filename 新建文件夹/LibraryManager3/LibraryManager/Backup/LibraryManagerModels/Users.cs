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
        /// Ա�����
        /// </summary>
        public int UserID
        {
            get { return userID; }
            set { userID = value; }
        }

        protected string userUID;
        /// <summary>
        /// Ա���˺�
        /// </summary>
        public string UserUID
        {
            get { return userUID; }
            set { userUID = value; }
        }

        protected string userPwd;
        /// <summary>
        /// Ա������
        /// </summary>
        public string UserPwd
        {
            get { return userPwd; }
            set { userPwd = value; }
        }

        protected string userName;
        /// <summary>
        /// Ա������
        /// </summary>
        public string UserName
        {
            get { return userName; }
            set { userName = value; }
        }

        protected string rolesName;
        /// <summary>
        /// ��ɫ����
        /// </summary>
        public string RolesName
        {
            get { return rolesName; }
            set { rolesName = value; }
        }

        protected int roleID;
        /// <summary>
        /// ��ɫID
        /// </summary>
        public int RoleID
        {
            get { return roleID; }
            set { roleID = value; }
        }
        protected string userSex;
        /// <summary>
        /// Ա���Ա�
        /// </summary>
        public string UserSex
        {
            get { return userSex; }
            set { userSex = value; }
        }
    }
}
