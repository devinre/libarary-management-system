using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using LibraryManagerDAL;

namespace LibraryManagerBLL
{
    public class UserTableManager
    {
        UserTableService uts = new UserTableService();
        CardTypeService cts = new CardTypeService();
        /// <summary>
        /// 全部会员信息
        /// </summary>
        /// <returns></returns>
        public IList<UserTable> GetUserMess()
        {
            IList<UserTable> il = new List<UserTable>();
            il = uts.GetUserMess();
            return il;
        }
        /// <summary>
        /// 按条件获取会员信息
        /// </summary>
        /// <param name="mess"></param>
        /// <returns></returns>
        public IList<UserTable> GetUserMess(string type,string mess)
        {
            IList<UserTable> il = new List<UserTable>();
            foreach (UserTable v in uts.GetUserMess())
            {
                switch (type)
                {
                    case "按会员号":
                        if (v.UserID == Convert.ToInt32(mess))
                            il.Add(v);
                        break;
                    case "按会员姓名":
                        if (v.UserName == mess)
                            il.Add(v);
                        break;
                    case "按会员生日":
                        if (v.UserBrith == Convert.ToDateTime(mess))
                            il.Add(v);
                        break;
                    case"按开户时间":
                        if (v.UserDate == Convert.ToDateTime(mess))
                            il.Add(v);
                        break;
                }
            }
            return il;
        }
        /// <summary>
        /// 获取会员卡类型
        /// </summary>
        /// <returns></returns>
        public IList<CardType> GetCardType()
        {
            IList<CardType> il = new List<CardType>();
            il = cts.GetCardType();
            return il;
        }
        /// <summary>
        /// 添加新会员
        /// </summary>
        /// <param name="ut"></param>
        /// <returns></returns>
        public string AddNewUser(UserTable ut)
        {
            return uts.AddNewUser(ut);
        }
        /// <summary>
        /// 修改会员信息
        /// </summary>
        /// <param name="ut"></param>
        /// <returns></returns>
        public string UpdateUser(UserTable ut)
        {
            return uts.UpdateUser(ut);
        }
        /// <summary>
        /// 删除会员信息
        /// </summary>
        /// <param name="ut"></param>
        /// <returns></returns>
        public string DeleteUser(UserTable ut)
        {
            return uts.DeleteUser(ut);
        }

        public string UpdateUserMoney(double money,int id)
        {
            return uts.UpdateUserMoney(money, id);
        }
    }
}
