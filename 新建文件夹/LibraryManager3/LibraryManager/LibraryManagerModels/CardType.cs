using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class CardType
    {
        protected int cardTypeID;
        /// <summary>
        /// 会员卡类型ID
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
        protected double cardAgio;
        /// <summary>
        /// 会员折扣
        /// </summary>
        public double CardAgio
        {
            get { return cardAgio; }
            set { cardAgio = value; }
        }
    }
}
