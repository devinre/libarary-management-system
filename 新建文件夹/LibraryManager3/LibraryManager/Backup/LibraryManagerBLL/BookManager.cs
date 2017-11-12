using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerDAL;
using LibraryManagerModels;

namespace LibraryManagerBLL
{
    public class BookManager
    {
        BookService bs = new BookService();
        /// <summary>
        /// 通过类型ID获取图书信息
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public IList<Books> GetBookMessByTypeID(int id)
        {
            return bs.GetBookMessByTypeID(id);
        }
        /// <summary>
        /// 添加新图书
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string AddNewBook(Books b)
        {
            return bs.AddNewBook(b);
        }
        /// <summary>
        /// 图书修改
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string UpdateBook(Books b)
        {
            return bs.UpdateBook(b);
        }
        /// <summary>
        /// 删除图书信息
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string DeleteBook(int id)
        {
            return bs.DeleteBook(id);
        }
        /// <summary>
        /// 通过图书名称和ID查询图书信息
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookByBookName(int id,string name)
        {
            return bs.GetBookMessByName(id, name);
        }
        /// <summary>
        /// 获取所有图书信息
        /// </summary>
        /// <returns></returns>
        public IList<Books> GetAllBook()
        {
            return bs.GetAllBook();
        }
        /// <summary>
        /// 通过图书名称查询图书信息
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookMessByName(string name)
        {
            return bs.GetBookByName(name);
        }
        /// <summary>
        /// 通过图书状态和名称查找图书(支持模糊查找)
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookByState(int id, string name)
        { 
            return bs.GetBookByState(id,name);
        }
        /// <summary>
        /// 通过图书名称查询图书ID
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public int GetBookIDByName(string name)
        {
            return bs.GetBookIDByName(name);
        }
        /// <summary>
        /// 通过图书名称获取图书价格
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public double GetBookPriceByName(string name)
        {
            return bs.GetBookPriceByName(name);
        }
    }
}
