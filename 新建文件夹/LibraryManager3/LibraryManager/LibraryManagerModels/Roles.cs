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
        /// ½ÇÉ«ID
        /// </summary>
        public int RolesID
        {
            get { return rolesID; }
            set { rolesID = value; }
        }

        protected string rolesName;
        /// <summary>
        /// ½ÇÉ«Ãû³Æ
        /// </summary>
        public string RolesName
        {
            get { return rolesName; }
            set { rolesName = value; }
        }
    }
}
