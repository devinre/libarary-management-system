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
        /// ��Ա������ID
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
        protected double cardAgio;
        /// <summary>
        /// ��Ա�ۿ�
        /// </summary>
        public double CardAgio
        {
            get { return cardAgio; }
            set { cardAgio = value; }
        }
    }
}
