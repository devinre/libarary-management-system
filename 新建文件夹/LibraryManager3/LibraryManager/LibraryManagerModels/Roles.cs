using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class Roles
    {
        protected int rolesID;
        /// <summary>
        /// ��ɫID
        /// </summary>
        public int RolesID
        {
            get { return rolesID; }
            set { rolesID = value; }
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
    }
}
