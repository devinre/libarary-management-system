using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Data;
using LibraryManagerModels;

namespace LibraryManagerDAL
{
    public class UsersService
    {
        /// <summary>
        /// 获取所有员工信息
        /// </summary>
        /// <returns></returns>
        public IList<Users> GetAllUsers()
        {
            IList<Users> il=new List<Users>();
            string sql = "proc_GetAllUsers";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Users user = new Users();
                    user.UserID = Convert.ToInt32(reader[0]);
                    user.UserUID = reader[1].ToString();
                    user.UserPwd = reader[2].ToString();
                    user.UserName = reader[3].ToString();
                    user.RolesName = reader[4].ToString();
                    user.UserSex = reader[5].ToString();
                    il.Add(user);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// 修改员工信息
        /// </summary>
        /// <param name="u"></param>
        /// <returns></returns>
        public string UpdateUsers(Users u)
        {
            string mess = "";
            string sql = "proc_UpdateUsers";
            SqlParameter p1 = new SqlParameter("@uid",u.UserUID);
            SqlParameter p2 = new SqlParameter("@pwd",u.UserPwd);
            SqlParameter p3 = new SqlParameter("@name",u.UserName);
            SqlParameter p4 = new SqlParameter("@rid",u.RoleID);
            SqlParameter p5 = new SqlParameter("@sex",u.UserSex);
            SqlParameter p6 = new SqlParameter("@id",u.UserID);
            int n = DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1,p2,p3,p4,p5,p6);
            if (n>0)
            {
                mess = "员工信息修改成功！";
            }
            else
            {
                mess = "员工信息修改失败!";
            }
            return mess;
        }
        /// <summary>
        /// 获取角色信息
        /// </summary>
        /// <returns></returns>
        public IList<Roles> GetRolesMess()
        {
            IList<Roles> il = new List<Roles>();
            string sql = "GetRolesMess";
            SqlDataReader reader = DBHelp.GetReader(sql,CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    Roles r = new Roles();
                    r.RolesID = Convert.ToInt32(reader[0]);
                    r.RolesName = reader[1].ToString();
                    il.Add(r);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// 添加员工信息
        /// </summary>
        /// <param name="u"></param>
        /// <returns></returns>
        public string AddUserMess(Users u,string id)
        {
            string mess = "";
            string sql = "proc_JudgeUser";
            SqlParameter p = new SqlParameter("@id",id);
            int m = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p));
            if (m>0)
            {
                mess = "此账号已存在！";
            }
            else
            {
                string sql1 = "proc_AddUsersMess";
                SqlParameter p1 = new SqlParameter("@uid", u.UserUID);
                SqlParameter p2 = new SqlParameter("@pwd", u.UserPwd);
                SqlParameter p3 = new SqlParameter("@name", u.UserName);
                SqlParameter p4 = new SqlParameter("@rid", u.RoleID);
                SqlParameter p5 = new SqlParameter("@sex", u.UserSex);
                int n = DBHelp.GetNonquery(sql1, CommandType.StoredProcedure, p1, p2, p3, p4, p5);
                if (n > 0)
                {
                    mess = "员工信息添加成功！";
                }
                else
                {
                    mess = "员工信息添加失败!";
                }
            }
            return mess;
        }
        /// <summary>
        /// 检测会员是否存在
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public string JudgeUsers(string id)
        {
            string mess = "";
            string sql = "proc_JudgeUser";
            SqlParameter p1 = new SqlParameter("@id", id);
            int n = Convert.ToInt32(DBHelp.GetScalar(sql, CommandType.StoredProcedure, p1));
            if (n > 0)
            {
                mess = "此账号已存在！";
            }
            else
            {
                mess = "此账号可以使用！";
            }
            return mess;
        }
        /// <summary>
        /// 删除员工信息
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public string DeleteUserMess(int id)
        {
            string mess = "";
            string sql = "proc_DeleteUsersMess";
            SqlParameter p1 = new SqlParameter("@id",id);
            int n = DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1);
            if (n>0)
            {
                mess = "员工信息删除成功！";
            }
            else
            {
                mess = "员工信息删除失败！";
            }
            return mess;
        }
        /// <summary>
        /// 登录信息检测
        /// </summary>
        /// <param name="uid"></param>
        /// <param name="pwd"></param>
        /// <param name="rid"></param>
        /// <returns></returns>
        public string JudgeUserLogin(string uid,string pwd,int rid)
        {
            string mess = "";
            string sql = "proc_JudgeUserLogin";
            SqlParameter p1 = new SqlParameter("@uid",uid);
            SqlParameter p2 = new SqlParameter("@pwd",pwd);
            SqlParameter p3 = new SqlParameter("@rid",rid);
            int n = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1,p2,p3));
            UserHelp.FunctionID.Clear();
            if (n>0)
            {
                SqlDataReader read = DBHelp.GetReader("proc_GetFunctionID", CommandType.StoredProcedure, new SqlParameter("@UserUID", uid));
                while (read.Read())
                {
                    UserHelp.FunctionID.Add(Convert.ToInt32(read[0]));
                
                }
                read.Close();
                mess = "登录成功！";
            }
            else
            {
                mess = "登录失败！";
            }
            return mess;
        }
        /// <summary>
        /// 通过员工账号查询员工姓名
        /// </summary>
        /// <param name="uid"></param>
        /// <returns></returns>
        public string GetUserNameByUID(string uid)
        {
            string name = "";
            string sql = "proc_GetUserNameByUID";
            SqlParameter p1 = new SqlParameter("@uid",uid);
            name=DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1).ToString();
            return name;
        }
        /// <summary>
        /// 修改登录人员密码
        /// </summary>
        /// <param name="pwd"></param>
        /// <returns></returns>
        public string UpdateUserPWD(string pwd,string id)
        {
            string mess = "";
            string sql = "proc_UpdateUserPWD";
            SqlParameter p1 = new SqlParameter("@pwd",pwd);
            SqlParameter p2 = new SqlParameter("@id",id);
            int n = DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1,p2);
            if (n>0)
            {
                mess = "密码修改成功！";
            }
            else
            {
                mess = "密码修改失败！";
            }
            return mess;
        }
    }
}
