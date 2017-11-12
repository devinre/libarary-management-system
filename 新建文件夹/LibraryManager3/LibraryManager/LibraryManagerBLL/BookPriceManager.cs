using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerDAL;
using LibraryManagerModels;

namespace LibraryManagerBLL
{
    public class BookPriceManager
    {
        BookPriceService bps = new BookPriceService();
        /// <summary>
        /// 获取图书价格信息
        /// </summary>
        /// <returns></returns>
        public IList<BooksPrice> GetBookPrice()
        {
            return bps.GetBookPrice();
        }
        /// <summary>
        /// 修改图书价格
        /// </summary>
        /// <param name="bp"></param>
        /// <returns></returns>
        public string UpdateBookPrice(BooksPrice bp)
        {
            return bps.UpdateBookPrice(bp);
        }
    }
}
