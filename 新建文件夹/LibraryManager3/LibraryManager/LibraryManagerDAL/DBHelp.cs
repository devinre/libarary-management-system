using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;

namespace LibraryManagerDAL
{
    class DBHelp
    {
        private static string conStr = ConfigurationManager.ConnectionStrings["BookManager"].ToString();

        public static SqlDataReader GetReader(string sql,CommandType type,params SqlParameter[] p)
        {
            SqlDataReader reader = null;
            SqlConnection con = new SqlConnection(conStr);
            try
            {
                con.Open();
                SqlCommand com = new SqlCommand(sql,con);
                foreach (SqlParameter v in p)
                {
                    com.Parameters.Add(v);
                }
                com.CommandType=type;
                reader = com.ExecuteReader(CommandBehavior.CloseConnection);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            return reader;
        }

        public static int GetNonquery(string sql, CommandType type, params SqlParameter[] p)
        {
            int n = -1;
            using (SqlConnection con=new SqlConnection(conStr))
            {
                try
                {
                    con.Open();
                    SqlCommand com = new SqlCommand(sql,con);
                    foreach (SqlParameter v in p)
                    {
                        com.Parameters.Add(v);
                    }
                    com.CommandType = type;
                    n = com.ExecuteNonQuery();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
                finally
                {
                    con.Close();
                }
            }
            return n;
        }

        public static object GetScalar(string sql, CommandType type, params SqlParameter[] p)
        {
            object obj = null;
            using (SqlConnection con = new SqlConnection(conStr))
            {
                try
                {
                    con.Open();
                    SqlCommand com = new SqlCommand(sql, con);
                    foreach (SqlParameter v in p)
                    {
                        com.Parameters.Add(v);
                    }
                    com.CommandType = type;
                    obj = com.ExecuteScalar();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
                finally
                {
                    con.Close();
                }
            }
            return obj;
        }

        public static DataTable GetTable(string sql, CommandType type, params SqlParameter[] p)
        {
            DataTable dt = null;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(conStr);
            SqlDataAdapter da = new SqlDataAdapter(sql, con);
            foreach (SqlParameter v in p)
            {
                da.SelectCommand.Parameters.Add(v);
            }
            da.SelectCommand.CommandType = type;
            da.Fill(ds);
            dt = ds.Tables[0];
            return dt;
        }

        public static DataTable GetTable(string sql, CommandType type, out SqlDataAdapter d, params SqlParameter[] p)
        {
            DataTable dt = null;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(conStr);
            SqlDataAdapter da = new SqlDataAdapter(sql, con);
            d = da;
            foreach (SqlParameter v in p)
            {
                da.SelectCommand.Parameters.Add(v);
            }
            da.SelectCommand.CommandType = type;
            da.Fill(ds);
            dt = ds.Tables[0];
            return dt;
        }
    }
}
