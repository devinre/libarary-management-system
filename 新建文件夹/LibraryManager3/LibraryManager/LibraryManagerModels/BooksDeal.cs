using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class BooksDeal
    {
        public BooksDeal()
        {
            Book = new Books();
        }
        protected int userID;
        /// <summary>
        /// �û�ID
        /// </summary>
        public int UserID
        {
            get { return userID; }
            set { userID = value; }
        }
        protected int bookID;
        /// <summary>
        /// ͼ��ID
        /// </summary>
        public int BookID
        {
            get { return bookID; }
            set { bookID = value; }
        }
        protected DateTime dealDate;
        /// <summary>
        /// ��������
        /// </summary>
        public DateTime DealDate
        {
            get { return dealDate; }
            set { dealDate = value; }
        }
        //protected DateTime detailBackDate;
        ///// <summary>
        ///// Ԥ�ڹ黹����
        ///// </summary>
        //public DateTime DetailBackDate
        //{
        //    get { return detailBackDate; }
        //    set { detailBackDate = value; }
        //}
        protected int priceID;
        /// <summary>
        /// �۸���㷽ʽID
        /// </summary>
        public int PriceID
        {
            get { return priceID; }
            set { priceID = value; }
        }
        protected double bookLendPrice;
        /// <summary>
        /// ����ʱ������
        /// </summary>
        public double BookLendPrice
        {
            get { return bookLendPrice; }
            set { bookLendPrice = value; }
        }
        protected string dealFlag;
        /// <summary>
        /// �Ƿ�黹
        /// </summary>
        public string DealFlag
        {
            get { return dealFlag; }
            set { dealFlag = value; }
        }
        protected DateTime backDate;
        /// <summary>
        /// ʵ�ʹ黹����
        /// </summary>
        public DateTime BackDate
        {
            get { return backDate; }
            set { backDate = value; }
        }
        protected double yaJin;
        /// <summary>
        /// Ѻ��
        /// </summary>
        public double YaJin
        {
            get { return yaJin; }
            set { yaJin = value; }
        }
        protected double zuJin;
        /// <summary>
        /// ʵ��Ӧ�����
        /// </summary>
        public double ZuJin
        {
            get { return zuJin; }
            set { zuJin = value; }
        }
        protected string bookName;
        /// <summary>
        /// ͼ������
        /// </summary>
        public string BookName
        {
            get { return bookName; }
            set { bookName = value; }
        }

        protected Books book;
        /// <summary>
        /// ��������BOOKS������
        /// </summary>
        public Books Book
        {
            get { return book; }
            set { book = value; }
        }
    }
}
