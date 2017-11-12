using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Data;
using LibraryManagerModels;

namespace LibraryManagerDAL
{
    public class BookDealService
    {
        /// <summary>
        /// ��������¼
        /// </summary>
        /// <param name="bd"></param>
        /// <returns></returns>
        public string AddBookDeal(BooksDeal bd)
        {
            string mess = "";
            string sql = "proc_JudgeBookDeal";
            SqlParameter p = new SqlParameter("@name",bd.BookName);
            int m = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p));
            if (m>0)
            {
                mess = "�����������";
            }
            else
            {
                string sql1 = "proc_AddBookDeal";
                SqlParameter p1 = new SqlParameter("@UserID", bd.UserID);
                SqlParameter p2 = new SqlParameter("@BookID", bd.BookID);
                SqlParameter p3 = new SqlParameter("@DealDate", bd.DealDate);
                SqlParameter p4 = new SqlParameter("@PriceID", bd.PriceID);
                SqlParameter p5 = new SqlParameter("@Price", bd.Book.Price);
                SqlParameter p6 = new SqlParameter("@BackDate", bd.BackDate);
                SqlParameter p7 = new SqlParameter("@YaJin", bd.YaJin);
                int n = DBHelp.GetNonquery(sql1, CommandType.StoredProcedure, p1, p2, p3, p4, p5, p6, p7);
                if (n > 0)
                {
                    mess = "����ɹ���";
                }
                else
                {
                    mess = "����ʧ�ܣ�";
                }
            }
            return mess;
        }
        /// <summary>
        /// ͨ��ͼ��۸��ȡ�۸�����
        /// </summary>
        /// <param name="price"></param>
        /// <returns></returns>
        public int GetPriceTypeByBookPrice(string name)
        {
            int n = -1;
            string sql = "proc_GetPriceTypeByPrice";
            SqlParameter p1 = new SqlParameter("@name",name);
            n = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1));
            return n;
        }
        /// <summary>
        /// �жϻ�Ա���Ƿ����
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public bool JudgeUser(int id)
        {
            bool f = false;
            string sql = "proc_JudgeUser";
            SqlParameter p1 = new SqlParameter("@id", id);
            int n = Convert.ToInt32(DBHelp.GetScalar(sql, CommandType.StoredProcedure, p1));
            if (n>0)
            {
                f = true;
            }
            return f;
        }
        /// <summary>
        /// ��ѯ�ѳ����ͼ�������Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<BooksDeal> GetBookMess()
        {
            IList<BooksDeal> il = new List<BooksDeal>();

            string sql = "proc_GetBookedMess";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    BooksDeal bd = new BooksDeal();
                    bd.Book= new Books();
                    bd.Book.BookName = reader[0].ToString();
                    bd.YaJin = Convert.ToDouble(reader[1]);
                    bd.ZuJin = Convert.ToDouble(reader[2]);
                    bd.Book.Price = Convert.ToDouble(reader[3]);
                    bd.DealDate = Convert.ToDateTime(reader[4]);
                    il.Add(bd);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ͨ��ͼ�����Ʋ�ѯ�ѳ����ͼ�������Ϣ
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<BooksDeal> GetBookMessByName(string name)
        {
            IList<BooksDeal> il = new List<BooksDeal>();

            string sql = "proc_GetBookedMessByName";
            SqlParameter p1 = new SqlParameter("@name",name);
            SqlDataReader reader = DBHelp.GetReader(sql, CommandType.StoredProcedure,p1);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    BooksDeal bd = new BooksDeal();
                    bd.Book = new Books();
                    bd.Book.BookName = reader[0].ToString();
                    bd.YaJin = Convert.ToDouble(reader[1]);
                    bd.ZuJin = Convert.ToDouble(reader[2]);
                    bd.Book.Price = Convert.ToDouble(reader[3]);
                    bd.DealDate = Convert.ToDateTime(reader[4]);
                    il.Add(bd);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ���飨�޸�ͼ��״̬��
        /// </summary>
        /// <param name="bd"></param>
        /// <returns></returns>
        public string ReturnBook(string name)
        {
            string mess = "";
            string sql = "proc_UpdateBooksState";
            SqlParameter p1 = new SqlParameter("@BookName", name);
            int n = Convert.ToInt32(DBHelp.GetNonquery(sql, CommandType.StoredProcedure, p1));
            if (n > 0)
            {
                mess = "����ɹ���";
            }
            return mess;
        }
        /// <summary>
        /// ͨ��ͼ��ID�����û�ID
        /// </summary>
        /// <param name="bookID"></param>
        /// <returns></returns>
        public int GetUserIDByBookID(int bookID)
        {
            int userID = -1;
            string sql = "proc_GetUserIDByBookID";
            SqlParameter p1 = new SqlParameter("@BookID",bookID);
            userID = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1));
            return userID;
        }

        public double GetZuJin(int id,out double lendPrice )
        {
            double zujin = 0d;
            string sql = "proc_GetZuJin";
            string sql1 = "proc_GetLendPrice";
            SqlParameter p1 = new SqlParameter("@id",id);
            SqlParameter p2 = new SqlParameter("@id",id);
            zujin = Convert.ToDouble(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1));
            lendPrice = Convert.ToDouble(DBHelp.GetScalar(sql1, CommandType.StoredProcedure, p2));
            return zujin;
        }
    }
}
