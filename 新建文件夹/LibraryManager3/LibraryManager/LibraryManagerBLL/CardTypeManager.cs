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
        /// ��ȡ��Ա������
        /// </summary>
        /// <returns></returns>
        public IList<CardType> GetCardType()
        {
            return cts.GetCardType();
        }
        /// <summary>
        /// �жϻ�Ա�����Ƿ����
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public bool JudgeCardType(string name)
        {
            return cts.JudgeCard(name);
        }
        /// <summary>
        /// ����»�Ա����
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
