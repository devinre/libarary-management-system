using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using System.Data.SqlClient;
using System.Data;

namespace LibraryManagerDAL
{
    public class CardTypeService
    {
        /// <summary>
        /// ��ȡ��Ա��������Ϣ
        /// </summary>
        /// <returns></returns>
        public IList<CardType> GetCardType()
        {
            IList<CardType> il = new List<CardType>();
            string sql = "proc_GetCardType";
            SqlDataReader reader = DBHelp.GetReader(sql, CommandType.StoredProcedure);
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    CardType ct = new CardType();
                    ct.CardTypeID = Convert.ToInt32(reader[0]);
                    ct.CardName = reader[1].ToString();
                    ct.CardAgio = Convert.ToDouble(reader[2]);
                    il.Add(ct);
                }
            }
            reader.Close();
            return il;
        }
        /// <summary>
        /// �жϻ�Ա���Ƿ����
        /// </summary>
        /// <returns></returns>
        public bool JudgeCard(string name)
        {
            bool f = false;
            string sql = "proc_JudgeCardType";
            SqlParameter p1 = new SqlParameter("@name",name);
            int n = Convert.ToInt32(DBHelp.GetScalar(sql,CommandType.StoredProcedure,p1));
            if (n>0)
            {
                f = true;
            }
            return f;
        }
        /// <summary>
        /// ����»�Ա����
        /// </summary>
        /// <param name="ct"></param>
        /// <returns></returns>
        public string AddNewCardType(CardType ct)
        {
            string mess = "";
            string sql = "proc_AddCarDType";
            SqlParameter p1 = new SqlParameter("@name",ct.CardName);
            SqlParameter p2 = new SqlParameter("@agio",ct.CardAgio);
            int n = Convert.ToInt32(DBHelp.GetNonquery(sql,CommandType.StoredProcedure,p1,p2));
            if (n>0)
            {
                mess = "��Ա������ӳɹ���";
            }
            else
            {
                mess = "��Ա�������ʧ�ܣ�";
            }
            return mess;
        }
        /// <summary>
        /// �޸Ļ�Ա����
        /// </summary>
        /// <param name="ct"></param>
        /// <returns></returns>
        public string UpdateCardType(CardType ct)
        {
            string mess = "";
            string sql = "proc_UpdateCarDType";
            SqlParameter p1 = new SqlParameter("@name", ct.CardName);
            SqlParameter p2 = new SqlParameter("@agio", ct.CardAgio);
            SqlParameter p3 = new SqlParameter("@id",ct.CardTypeID);
            int n = Convert.ToInt32(DBHelp.GetNonquery(sql, CommandType.StoredProcedure, p1, p2,p3));
            if (n > 0)
            {
                mess = "��Ա�����޸ĳɹ���";
            }
            else
            {
                mess = "��Ա�����޸�ʧ�ܣ�";
            }
            return mess;
        }
    }
}
