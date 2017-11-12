using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using System.Data.SqlClient;
using System.Data;

namespace LibraryManagerDAL
{
    public class BookStateService
    {
        /// <summary>
        /// »ñÈ¡Í¼Êé×´Ì¬
        /// </summary>
        /// <returns></returns>
        public IList<BookState> GetBookState()
        {
            IList<BookState> il = new List<BookState>();
            string sql = "proc_GetBookState";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    BookState bs = new BookState();
                    bs.StateID = Convert.ToInt32(reader[0]);
                    bs.State = reader[1].ToString();
                    il.Add(bs);
                }
            }
            reader.Close();
            return il;
        }
    }
}
