using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class Books
    {
        protected int bookID;
        /// <summary>
        /// 书籍ID
        /// </summary>
        public int BookID
        {
            get { return bookID; }
            set { bookID = value; }
        }
        protected string bookName;
        /// <summary>
        /// 书名
        /// </summary>
        public string BookName
        {
            get { return bookName; }
            set { bookName = value; }
        }
        protected int typeID;
        /// <summary>
        /// 书籍类型ID
        /// </summary>
        public int TypeID
        {
            get { return typeID; }
            set { typeID = value; }
        }

        protected string typeName;
        /// <summary>
        /// 图书类型
        /// </summary>
        public string TypeName
        {
            get { return typeName; }
            set { typeName = value; }
        }
        protected double price;
        /// <summary>
        /// 图书价格
        /// </summary>
        public double Price
        {
            get { return price; }
            set { price = value; }
        }
        protected string publish;
        /// <summary>
        /// 出版社
        /// </summary>
        public string Publish
        {
            get { return publish; }
            set { publish = value; }
        }
        protected int stateID;
        /// <summary>
        /// 图书状态ID
        /// </summary>
        public int StateID
        {
            get { return stateID; }
            set { stateID = value; }
        }

        protected string state;
        /// <summary>
        /// 图书状态
        /// </summary>
        public string State
        {
            get { return state; }
            set { state = value; }
        }
    }
}
