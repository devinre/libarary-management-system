using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class UserTable
    {
        int userID;
        /// <summary>
        /// ��ԱID
        /// </summary>
        public int UserID
        {
            get { return userID; }
            set { userID = value; }
        }
        string userName;
        /// <summary>
        /// ��Ա����
        /// </summary>
        public string UserName
        {
            get { return userName; }
            set { userName = value; }
        }
        string userSex;
        /// <summary>
        /// ��Ա�Ա�
        /// </summary>
        public string UserSex
        {
            get { return userSex; }
            set { userSex = value; }
        }
        string userTel;
        /// <summary>
        /// ��Ա��ϵ�绰
        /// </summary>
        public string UserTel
        {
            get { return userTel; }
            set { userTel = value; }
        }
        DateTime userBrith;
        /// <summary>
        /// ��Ա����
        /// </summary>
        public DateTime UserBrith
        {
            get { return userBrith; }
            set { userBrith = value; }
        }
        double userMoney;
        /// <summary>
        /// ��Ա����ʣ����
        /// </summary>
        public double UserMoney
        {
            get { return userMoney; }
            set { userMoney = value; }
        }
        DateTime userDate;
        /// <summary>
        /// ��Աע������
        /// </summary>
        public DateTime UserDate
        {
            get { return userDate; }
            set { userDate = value; }
        }
        int cardTypeID;
        /// <summary>
        /// ��Ա������
        /// </summary>
        public int CardTypeID
        {
            get { return cardTypeID; }
            set { cardTypeID = value; }
        }

        protected string cardName;
        /// <summary>
        /// ��Ա����������
        /// </summary>
        public string CardName
        {
            get { return cardName; }
            set { cardName = value; }
        }
    }
}
