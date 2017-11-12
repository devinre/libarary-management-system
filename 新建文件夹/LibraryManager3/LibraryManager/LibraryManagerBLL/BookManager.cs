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
        /// ͨ������ID��ȡͼ����Ϣ
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public IList<Books> GetBookMessByTypeID(int id)
        {
            return bs.GetBookMessByTypeID(id);
        }
        /// <summary>
        /// �����ͼ��
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string AddNewBook(Books b)
        {
            return bs.AddNewBook(b);
        }
        /// <summary>
        /// ͼ���޸�
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string UpdateBook(Books b)
        {
            return bs.UpdateBook(b);
        }
        /// <summary>
        /// ɾ��ͼ����Ϣ
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string DeleteBook(int id)
        {
            return bs.DeleteBook(id);
        }
        /// <summary>
        /// ͨ��ͼ�����ƺ�ID��ѯͼ����Ϣ
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookByBookName(int id,string name)
        {
            return bs.GetBookMessByName(id, name);
        }
        /// <summary>
        /// ��ȡ����ͼ����Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<Books> GetAllBook()
        {
            return bs.GetAllBook();
        }
        /// <summary>
        /// ͨ��ͼ�����Ʋ�ѯͼ����Ϣ
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookMessByName(string name)
        {
            return bs.GetBookByName(name);
        }
        /// <summary>
        /// ͨ��ͼ��״̬�����Ʋ���ͼ��(֧��ģ������)
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookByState(int id, string name)
        { 
            return bs.GetBookByState(id,name);
        }
        /// <summary>
        /// ͨ��ͼ�����Ʋ�ѯͼ��ID
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public int GetBookIDByName(string name)
        {
            return bs.GetBookIDByName(name);
        }
        /// <summary>
        /// ͨ��ͼ�����ƻ�ȡͼ��۸�
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public double GetBookPriceByName(string name)
        {
            return bs.GetBookPriceByName(name);
        }
    }
}
