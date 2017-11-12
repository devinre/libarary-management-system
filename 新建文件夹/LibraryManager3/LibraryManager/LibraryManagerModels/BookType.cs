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
        /// 图书类型ID
        /// </summary>
        public int TypeID
        {
            get { return typeID; }
            set { typeID = value; }
        }
        protected string typeName;
        /// <summary>
        /// 图书类型名称
        /// </summary>
        public string TypeName
        {
            get { return typeName; }
            set { typeName = value; }
        }
    }
}
