using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerDAL;
using LibraryManagerModels;

namespace LibraryManagerBLL
{
    public class BookDealManager
    {
        BookDealService bds = new BookDealService();
        /// <summary>
        /// 添加租书记录
        /// </summary>
        /// <param name="bd"></param>
        /// <returns></returns>
        public string AddBookDeal(BooksDeal bd)
        {
            return bds.AddBookDeal(bd);
        }
        /// <summary>
        /// 通过图书价格获取价格类型
        /// </summary>
        /// <param name="price"></param>
        /// <returns></returns>
        public int GetPriceID(string name)
        {
            return bds.GetPriceTypeByBookPrice(name);
        }
        /// <summary>
        /// 判断会员时候存在
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public bool JudgeUser(int id)
        {
            return bds.JudgeUser(id);
        }
        /// <summary>
        /// 查询已出租的图书相关信息
        /// </summary>
        /// <returns></returns>
        public IList<BooksDeal> GetBookMess()
        {
            return bds.GetBookMess();
        }
        /// <summary>
        /// 通过图书名称查询已出租的图书相关信息
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<BooksDeal> GetBookMessByName(string name)
        {
            return bds.GetBookMessByName(name);
        }
        /// <summary>
        /// 还书（修改图书状态）
        /// </summary>
        /// <param name="bd"></param>
        /// <returns></returns>
        public string ReturnBook(string name)
        {
            return bds.ReturnBook(name);
        }
        /// <summary>
        /// 通过图书ID查找用户ID
        /// </summary>
        /// <param name="bookID"></param>
        /// <returns></returns>
        public int GetUserIDByBookID(int bookID)
        {
            return bds.GetUserIDByBookID(bookID);  
        }

        public double GetZuJin(int id, out double lendPrice)
        {
            return bds.GetZuJin(id,out lendPrice);
        }
    }
}
