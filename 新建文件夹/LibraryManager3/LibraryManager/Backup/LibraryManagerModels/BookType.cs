using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class BookType
    {
        protected int typeID;
        /// <summary>
        /// ͼ������ID
        /// </summary>
        public int TypeID
        {
            get { return typeID; }
            set { typeID = value; }
        }
        protected string typeName;
        /// <summary>
        /// ͼ����������
        /// </summary>
        public string TypeName
        {
            get { return typeName; }
            set { typeName = value; }
        }
    }
}
