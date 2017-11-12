using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using System.Data.SqlClient;
using System.Data;

namespace LibraryManagerDAL
{
    public class BookTypeService
    {
        /// <summary>
        /// ��ȡͼ������
        /// </summary>
        /// <returns></returns>
        public IList<BookType> GetBookType()
        {
            IList<BookType> il = new List<BookType>();
            string sql = "proc_GetBookType";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    BookType bt = new BookType();
                    bt.TypeID = Convert.ToInt32(reader[0]);
                    bt.TypeName = reader[1].ToString();
                    il.Add(bt);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// ���ͼ������
        /// </summary>
        /// <param name="bt"></param>
        /// <returns></returns>
        public string AddNewBookType(BookType bt)
        {
            string mess = "";
            string sql = "proc_JudgeType";
            SqlParameter p1 = new SqlParameter("@name", bt.TypeName);
            int n = Convert.ToInt32(DBHelp.GetScalar(sql, CommandType.StoredProcedure, p1));
            if (n > 0)
            {
                mess = "��ͼ�������Ѵ��ڣ�";
            }
            else
            {
                string sql1 = "proc_AddNewBookType";
                SqlParameter p2 = new SqlParameter("@name", bt.TypeName);
                int m = DBHelp.GetNonquery(sql1, CommandType.StoredProcedure, p2);
                if (m > 0)
                {
                    mess = "��ӳɹ���";
                }
                else
                {
                    mess = "���ʧ�ܣ�";
                }
            }
            return mess;
        }

    }
}
