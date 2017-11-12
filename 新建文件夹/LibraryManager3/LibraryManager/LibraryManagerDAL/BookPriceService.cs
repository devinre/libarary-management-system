using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Data;
using LibraryManagerModels;

namespace LibraryManagerDAL
{
    public class BookPriceService
    {
        /// <summary>
        /// 获取图书价格信息
        /// </summary>
        /// <returns></returns>
        public IList<BooksPrice> GetBookPrice()
        {
            IList<BooksPrice> il = new List<BooksPrice>();
            string sql = "proc_GetBookPrice";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    BooksPrice bp = new BooksPrice();
                    bp.BookPriceID = Convert.ToInt32(reader[0]);
                    bp.BookUpPrice = Convert.ToDouble(reader[1]);
                    bp.BookDownPrice = Convert.ToDouble(reader[2]);
                    bp.BookPrice = Convert.ToDouble(reader[3]);
                    bp.BackDate = Convert.ToInt32(reader[4]);
                    il.Add(bp);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// 修改图书价格
        /// </summary>
        /// <param name="bp"></param>
        /// <returns></returns>
        public string UpdateBookPrice(BooksPrice bp)
        {
            string mess = "";
            string sql = "proc_UpdateBookPrice";
            SqlParameter p1 = new SqlParameter("@BookPriceID",bp.BookPriceID);
            SqlParameter p2 = new SqlParameter("@UpPrice",bp.BookUpPrice);
            SqlParameter p3 = new SqlParameter("@DownPrice",bp.BookDownPrice);
            SqlParameter p4 = new SqlParameter("@Price",bp.BookPrice);
            SqlParameter p5 = new SqlParameter("@BackDate",bp.BackDate);
            int n = DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1,p2,p3,p4,p5);
            if (n>0)
            {
                mess = "修改成功！";
            }
            else
            {
                mess = "修改失败！";
            }
            return mess;
        }
    }
}
