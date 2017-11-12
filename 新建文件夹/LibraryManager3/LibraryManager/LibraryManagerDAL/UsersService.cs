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
        /// ��ȡ����Ա����Ϣ
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
        /// �޸�Ա����Ϣ
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
                mess = "Ա����Ϣ�޸ĳɹ���";
            }
            else
            {
                mess = "Ա����Ϣ�޸�ʧ��!";
            }
            return mess;
        }
        /// <summary>
        /// ��ȡ��ɫ��Ϣ
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
        /// ���Ա����Ϣ
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
                mess = "���˺��Ѵ��ڣ�";
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
                    mess = "Ա����Ϣ��ӳɹ���";
                }
                else
                {
                    mess = "Ա����Ϣ���ʧ��!";
                }
            }
            return mess;
        }
        /// <summary>
        /// ����Ա�Ƿ����
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
                mess = "���˺��Ѵ��ڣ�";
            }
            else
            {
                mess = "���˺ſ���ʹ�ã�";
            }
            return mess;
        }
        /// <summary>
        /// ɾ��Ա����Ϣ
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
                mess = "Ա����Ϣɾ���ɹ���";
            }
            else
            {
                mess = "Ա����Ϣɾ��ʧ�ܣ�";
            }
            return mess;
        }
        /// <summary>
        /// ��¼��Ϣ���
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
                mess = "��¼�ɹ���";
            }
            else
            {
                mess = "��¼ʧ�ܣ�";
            }
            return mess;
        }
        /// <summary>
        /// ͨ��Ա���˺Ų�ѯԱ������
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
        /// �޸ĵ�¼��Ա����
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
                mess = "�����޸ĳɹ���";
            }
            else
            {
                mess = "�����޸�ʧ�ܣ�";
            }
            return mess;
        }
    }
}
