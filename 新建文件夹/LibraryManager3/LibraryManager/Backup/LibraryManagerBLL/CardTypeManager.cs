using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using LibraryManagerDAL;

namespace LibraryManagerBLL
{
    public class CardTypeManager
    {
        CardTypeService cts = new CardTypeService();
        /// <summary>
        /// 获取会员可类型
        /// </summary>
        /// <returns></returns>
        public IList<CardType> GetCardType()
        {
            return cts.GetCardType();
        }
        /// <summary>
        /// 判断会员类型是否存在
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public bool JudgeCardType(string name)
        {
            return cts.JudgeCard(name);
        }
        /// <summary>
        /// 添加新会员类型
        /// </summary>
        /// <param name="ct"></param>
        /// <returns></returns>
        public string AddNewCardType(CardType ct)
        {
            return cts.AddNewCardType(ct);
        }

        public string UpdateCardType(CardType ct)
        {
            return cts.UpdateCardType(ct);
        }
    }
}
