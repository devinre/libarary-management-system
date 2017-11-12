using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using System.Data.SqlClient;
using System.Data;

namespace LibraryManagerDAL
{
    public class BookService
    {
        /// <summary>
        /// ͨ������ID��ȡͼ����Ϣ
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public IList<Books> GetBookMessByTypeID(int id)
        {
            IList<Books> il = new List<Books>();
            string sql = "proc_GetBookMess";
            SqlParameter p1=new SqlParameter("@id",id);
            SqlDataReader reader = DBHelp.GetReader(sql, CommandType.StoredProcedure, p1);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Books book = new Books();
                    book.BookID = Convert.ToInt32(reader[0]);
                    book.BookName = reader[1].ToString();
                    book.TypeID=Convert.ToInt32(reader[2]);
                    book.TypeName = reader[3].ToString();
                    book.Price = Convert.ToDouble(reader[4]);
                    book.Publish = reader[5].ToString();
                    book.StateID = Convert.ToInt32(reader[6]);
                    book.State = reader[7].ToString();
                    il.Add(book);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ���ͼ��
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string AddNewBook(Books b)
        {
            string mess = "";
            string sql = "proc_JudgeBook";
            SqlParameter p = new SqlParameter("@name",b.BookName);
            int n = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p));
            if (n>0)
            {
                mess = "��ͼ���Ѵ��ڣ�";
            }
            else
            {
                string sql1 = "proc_AddNewBook";
                SqlParameter p1 = new SqlParameter("@name", b.BookName);
                SqlParameter p2 = new SqlParameter("@typeID", b.TypeID);
                SqlParameter p3 = new SqlParameter("@price", b.Price);
                SqlParameter p4 = new SqlParameter("@publish", b.Publish);
                SqlParameter p5 = new SqlParameter("@stateID", b.StateID);
                int m = DBHelp.GetNonquery(sql1,CommandType.StoredProcedure,p1,p2,p3,p4,p5);
                if (m>0)
                {
                    mess = "���ͼ��ɹ���";
                }
                else
                {
                    mess = "���ͼ��ʧ�ܣ�";
                }
            }
            return mess;
        }
        /// <summary>
        /// �޸�ͼ��
        /// </summary>
        /// <returns></returns>
        public string UpdateBook(Books b)
        {
            string mess = "";
            string sql = "proc_UpdateBook";
            SqlParameter p1 = new SqlParameter("@name", b.BookName);
            SqlParameter p2 = new SqlParameter("@typeID", b.TypeID);
            SqlParameter p3 = new SqlParameter("@price", b.Price);
            SqlParameter p4 = new SqlParameter("@publish", b.Publish);
            SqlParameter p5 = new SqlParameter("@stateID", b.StateID);
            SqlParameter p6 = new SqlParameter("@bookID",b.BookID);
            int n = DBHelp.GetNonquery(sql, CommandType.StoredProcedure, p1, p2, p3, p4, p5,p6);
            if (n > 0)
            {
                mess = "ͼ���޸ĳɹ���";
            }
            else
            {
                mess = "ͼ���޸�ʧ�ܣ�";
            }
            return mess;
        }
        /// <summary>
        /// ɾ��ͼ����Ϣ
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        public string DeleteBook(int id)
        {
            string mess = "";
            string sql = "proc_DeleteBook";
            SqlParameter p1 = new SqlParameter("@id",id);
            int n = DBHelp.GetNonquery(sql, CommandType.StoredProcedure, p1);
            if (n>0)
            {
                mess = "ɾ����Ϣ�ɹ���";
            }
            else
            {
                mess = "ɾ����Ϣʧ�ܣ�";
            }
            return mess;
        }
        /// <summary>
        /// ͨ��ͼ�����ƺ�ID����ͼ����Ϣ(֧��ģ������)
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookMessByName(int id,string name)
        {
            IList<Books> il = new List<Books>();
            string sql = "proc_SearchBookByBookName";
            SqlParameter p1 = new SqlParameter("@id", id);
            SqlParameter p2 = new SqlParameter("@name", name);
            SqlDataReader reader = DBHelp.GetReader(sql, CommandType.StoredProcedure, p1,p2);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Books book = new Books();
                    book.BookID = Convert.ToInt32(reader[0]);
                    book.BookName = reader[1].ToString();
                    book.TypeID = Convert.ToInt32(reader[2]);
                    book.TypeName = reader[3].ToString();
                    book.Price = Convert.ToDouble(reader[4]);
                    book.Publish = reader[5].ToString();
                    book.StateID = Convert.ToInt32(reader[6]);
                    book.State = reader[7].ToString();
                    il.Add(book);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ��ȡ����ͼ����Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<Books> GetAllBook()
        {
            IList<Books> il = new List<Books>();
            string sql = "pro_GetAllBook";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Books book = new Books();
                    book.BookID = Convert.ToInt32(reader[0]);
                    book.BookName = reader[1].ToString();
                    book.TypeID = Convert.ToInt32(reader[2]);
                    book.TypeName = reader[3].ToString();
                    book.Price = Convert.ToDouble(reader[4]);
                    book.Publish = reader[5].ToString();
                    book.StateID = Convert.ToInt32(reader[6]);
                    book.State = reader[7].ToString();
                    il.Add(book);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ͨ��ͼ�����Ʋ���ͼ����Ϣ(֧��ģ������)
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookByName(string name)
        {
            IList<Books> il = new List<Books>();
            string sql = "proc_GetBookMessByName";
            SqlParameter p1 = new SqlParameter("@name", name);
            SqlDataReader reader = DBHelp.GetReader(sql, CommandType.StoredProcedure, p1);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Books book = new Books();
                    book.BookID = Convert.ToInt32(reader[0]);
                    book.BookName = reader[1].ToString();
                    book.TypeID = Convert.ToInt32(reader[2]);
                    book.TypeName = reader[3].ToString();
                    book.Price = Convert.ToDouble(reader[4]);
                    book.Publish = reader[5].ToString();
                    book.StateID = Convert.ToInt32(reader[6]);
                    book.State = reader[7].ToString();
                    il.Add(book);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ͨ��ͼ��״̬�����Ʋ���ͼ��(֧��ģ������)
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        /// <returns></returns>
        public IList<Books> GetBookByState(int id, string name)
        {
            IList<Books> il = new List<Books>();
            string sql = "proc_GetBookMessByState";
            SqlParameter p1 = new SqlParameter("@stateid", id);
            SqlParameter p2 = new SqlParameter("@name", name);
            SqlDataReader reader = DBHelp.GetReader(sql, CommandType.StoredProcedure, p1, p2);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Books book = new Books();
                    book.BookID = Convert.ToInt32(reader[0]);
                    book.BookName = reader[1].ToString();
                    book.TypeID = Convert.ToInt32(reader[2]);
                    book.TypeName = reader[3].ToString();
                    book.Price = Convert.ToDouble(reader[4]);
                    book.Publish = reader[5].ToString();
                    book.StateID = Convert.ToInt32(reader[6]);
                    book.State = reader[7].ToString();
                    il.Add(book);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ͨ��ͼ�����Ʋ�ѯͼ��ID
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public int GetBookIDByName(string name)
        {
            int id = -1;
            string sql = "proc_GetBookIDByName";
            SqlParameter p1 = new SqlParameter("@name",name);
            id = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1));
            return id;
        }
        /// <summary>
        /// ͨ��ͼ�����ƻ�ȡͼ��۸�
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public double GetBookPriceByName(string name)
        {
            double price = 0d;
            string sql = "proc_GetBookPriceByName";
            SqlParameter p1 = new SqlParameter("@name",name);
            price = Convert.ToDouble(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1));
            return price;
        }
    }
}
