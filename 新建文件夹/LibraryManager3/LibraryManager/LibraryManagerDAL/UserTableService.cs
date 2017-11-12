using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using System.Data.SqlClient;
using System.Data;

namespace LibraryManagerDAL
{
    public class UserTableService
    {
        /// <summary>
        /// 获取全部会员信息
        /// </summary>
        /// <returns></returns>
        public IList<UserTable> GetUserMess()
        {
            IList<UserTable> il = new List<UserTable>();
            string sql = "proc_SelectAllUser";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    UserTable ut = new UserTable();
                    ut.UserID = Convert.ToInt32(reader[0]);
                    ut.UserName = reader[1].ToString();
                    ut.UserSex = reader[2].ToString();
                    ut.UserTel = reader[3].ToString();
                    ut.UserBrith = Convert.ToDateTime(reader[4]);
                    ut.UserMoney = Convert.ToDouble(reader[5]);
                    ut.UserDate = Convert.ToDateTime(reader[6]);
                    ut.CardTypeID = Convert.ToInt32(reader[7]);
                    ut.CardName = reader[8].ToString();
                    il.Add(ut);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// 添加新会员
        /// </summary>
        /// <param name="ut"></param>
        /// <returns></returns>
        public string AddNewUser(UserTable ut)
        {
            string mess = "";
            string sql = "proc_AddNewUser";
            SqlParameter p1 = new SqlParameter("@name",ut.UserName);
            SqlParameter p2 = new SqlParameter("@sex", ut.UserSex);
            SqlParameter p3 = new SqlParameter("@tel", ut.UserTel);
            SqlParameter p4 = new SqlParameter("@brith", ut.UserBrith);
            SqlParameter p5 = new SqlParameter("@money", ut.UserMoney);
            SqlParameter p6 = new SqlParameter("@date", ut.UserDate);
            SqlParameter p7 = new SqlParameter("@id", ut.CardTypeID);
            int n = DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1,p2,p3,p4,p5,p6,p7);
            if (n>0)
            {
                mess = "会员信息添加成功！";
            }
            else
            {
                mess = "会员信息添加失败！";
            }
            return mess;
        }
        /// <summary>
        /// 修改会员信息
        /// </summary>
        /// <param name="ut"></param>
        /// <returns></returns>
        public string UpdateUser(UserTable ut)
        {
            string mess = "";
            string sql = "proc_UpdateUser";
            SqlParameter p1 = new SqlParameter("@name", ut.UserName);
            SqlParameter p2 = new SqlParameter("@sex", ut.UserSex);
            SqlParameter p3 = new SqlParameter("@tel", ut.UserTel);
            SqlParameter p4 = new SqlParameter("@brith", ut.UserBrith);
            SqlParameter p5 = new SqlParameter("@money", ut.UserMoney);
            SqlParameter p6 = new SqlParameter("@date", ut.UserDate);
            SqlParameter p7 = new SqlParameter("@id", ut.CardTypeID);
            SqlParameter p8 = new SqlParameter("@userID",ut.UserID);
            int n = DBHelp.GetNonquery(sql, CommandType.StoredProcedure, p1, p2, p3, p4, p5, p6, p7,p8);
            if (n > 0)
            {
                mess = "会员信息修改成功！";
            }
            else
            {
                mess = "会员信息修改失败！";
            }
            return mess;
        }
        /// <summary>
        /// 删除会员信息
        /// </summary>
        /// <param name="ut"></param>
        /// <returns></returns>
        public string DeleteUser(UserTable ut)
        {
            string mess = "";
            string sql = "proc_DeleteUser";
            SqlParameter p1 = new SqlParameter("@userID",ut.UserID);
            int n=DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1);
            if (n > 0)
            {
                mess = "会员信息删除成功！";
            }
            else
            {
                mess = "会员信息删除失败！";
            }
            return mess;
        }
        /// <summary>
        /// 会员充值
        /// </summary>
        /// <returns></returns>
        public string UpdateUserMoney(double money,int id)
        {
            string mess = "";
            string sql = "proc_UpdateUserMoney";
            SqlParameter p1 = new SqlParameter("@money",money);
            SqlParameter p2 = new SqlParameter("@id",id);
            int n = DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1,p2);
            if (n>0)
            {
                mess = "会员充值成功！";
            }
            else
            {
                mess = "会员充值失败！";
            }
            return mess;
        }
    }
}
