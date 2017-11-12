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
        /// ��ȡͼ��۸���Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<BooksPrice> GetBookPrice()
        {
            return bps.GetBookPrice();
        }
        /// <summary>
        /// �޸�ͼ��۸�
        /// </summary>
        /// <param name="bp"></param>
        /// <returns></returns>
        public string UpdateBookPrice(BooksPrice bp)
        {
            return bps.UpdateBookPrice(bp);
        }
    }
}
