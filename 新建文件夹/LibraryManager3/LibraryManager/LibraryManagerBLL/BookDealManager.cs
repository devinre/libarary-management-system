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
        /// ��������¼
        /// </summary>
        /// <param name="bd"></param>
        /// <returns></returns>
        public string AddBookDeal(BooksDeal bd)
        {
            return bds.AddBookDeal(bd);
        }
        /// <summary>
        /// ͨ��ͼ��۸��ȡ�۸�����
        /// </summary>
        /// <param name="price"></param>
        /// <returns></returns>
        public int GetPriceID(string name)
        {
            return bds.GetPriceTypeByBookPrice(name);
        }
        /// <summary>
        /// �жϻ�Աʱ�����
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public bool JudgeUser(int id)
        {
            return bds.JudgeUser(id);
        }
        /// <summary>
        /// ��ѯ�ѳ����ͼ�������Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<BooksDeal> GetBookMess()
        {
            return bds.GetBookMess();
        }
        /// <summary>
        /// ͨ��ͼ�����Ʋ�ѯ�ѳ����ͼ�������Ϣ
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<BooksDeal> GetBookMessByName(string name)
        {
            return bds.GetBookMessByName(name);
        }
        /// <summary>
        /// ���飨�޸�ͼ��״̬��
        /// </summary>
        /// <param name="bd"></param>
        /// <returns></returns>
        public string ReturnBook(string name)
        {
            return bds.ReturnBook(name);
        }
        /// <summary>
        /// ͨ��ͼ��ID�����û�ID
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
