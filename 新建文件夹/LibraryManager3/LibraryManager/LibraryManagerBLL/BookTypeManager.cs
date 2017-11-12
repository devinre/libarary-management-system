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
        /// ��ȡͼ������
        /// </summary>
        /// <returns></returns>
        public IList<BookType> GetBookType()
        { 
            return bts.GetBookType();
        }
        /// <summary>
        /// ���ͼ������
        /// </summary>
        /// <param name="bt"></param>
        /// <returns></returns>
        public string AddNewBookType(BookType bt)
        {
            return bts.AddNewBookType(bt);
        }
    }
}
