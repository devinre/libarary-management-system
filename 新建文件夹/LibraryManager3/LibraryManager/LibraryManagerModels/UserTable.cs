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
        /// 会员ID
        /// </summary>
        public int UserID
        {
            get { return userID; }
            set { userID = value; }
        }
        string userName;
        /// <summary>
        /// 会员名字
        /// </summary>
        public string UserName
        {
            get { return userName; }
            set { userName = value; }
        }
        string userSex;
        /// <summary>
        /// 会员性别
        /// </summary>
        public string UserSex
        {
            get { return userSex; }
            set { userSex = value; }
        }
        string userTel;
        /// <summary>
        /// 会员联系电话
        /// </summary>
        public string UserTel
        {
            get { return userTel; }
            set { userTel = value; }
        }
        DateTime userBrith;
        /// <summary>
        /// 会员生日
        /// </summary>
        public DateTime UserBrith
        {
            get { return userBrith; }
            set { userBrith = value; }
        }
        double userMoney;
        /// <summary>
        /// 会员卡内剩余金额
        /// </summary>
        public double UserMoney
        {
            get { return userMoney; }
            set { userMoney = value; }
        }
        DateTime userDate;
        /// <summary>
        /// 会员注册日期
        /// </summary>
        public DateTime UserDate
        {
            get { return userDate; }
            set { userDate = value; }
        }
        int cardTypeID;
        /// <summary>
        /// 会员卡类型
        /// </summary>
        public int CardTypeID
        {
            get { return cardTypeID; }
            set { cardTypeID = value; }
        }

        protected string cardName;
        /// <summary>
        /// 会员卡类型名称
        /// </summary>
        public string CardName
        {
            get { return cardName; }
            set { cardName = value; }
        }
    }
}
