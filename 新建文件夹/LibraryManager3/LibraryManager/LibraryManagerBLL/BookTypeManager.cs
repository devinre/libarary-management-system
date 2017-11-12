using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using LibraryManagerDAL;

namespace LibraryManagerBLL
{
    public class BookTypeManager
    {
        BookTypeService bts = new BookTypeService();
        /// <summary>
        /// 获取图书类型
        /// </summary>
        /// <returns></returns>
        public IList<BookType> GetBookType()
        { 
            return bts.GetBookType();
        }
        /// <summary>
        /// 添加图书类型
        /// </summary>
        /// <param name="bt"></param>
        /// <returns></returns>
        public string AddNewBookType(BookType bt)
        {
            return bts.AddNewBookType(bt);
        }
    }
}
