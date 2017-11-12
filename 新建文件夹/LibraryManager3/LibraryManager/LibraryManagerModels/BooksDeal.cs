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
        /// 用户ID
        /// </summary>
        public int UserID
        {
            get { return userID; }
            set { userID = value; }
        }
        protected int bookID;
        /// <summary>
        /// 图书ID
        /// </summary>
        public int BookID
        {
            get { return bookID; }
            set { bookID = value; }
        }
        protected DateTime dealDate;
        /// <summary>
        /// 借书日期
        /// </summary>
        public DateTime DealDate
        {
            get { return dealDate; }
            set { dealDate = value; }
        }
        //protected DateTime detailBackDate;
        ///// <summary>
        ///// 预期归还日期
        ///// </summary>
        //public DateTime DetailBackDate
        //{
        //    get { return detailBackDate; }
        //    set { detailBackDate = value; }
        //}
        protected int priceID;
        /// <summary>
        /// 价格计算方式ID
        /// </summary>
        public int PriceID
        {
            get { return priceID; }
            set { priceID = value; }
        }
        protected double bookLendPrice;
        /// <summary>
        /// 超出时间的租金
        /// </summary>
        public double BookLendPrice
        {
            get { return bookLendPrice; }
            set { bookLendPrice = value; }
        }
        protected string dealFlag;
        /// <summary>
        /// 是否归还
        /// </summary>
        public string DealFlag
        {
            get { return dealFlag; }
            set { dealFlag = value; }
        }
        protected DateTime backDate;
        /// <summary>
        /// 实际归还日期
        /// </summary>
        public DateTime BackDate
        {
            get { return backDate; }
            set { backDate = value; }
        }
        protected double yaJin;
        /// <summary>
        /// 押金
        /// </summary>
        public double YaJin
        {
            get { return yaJin; }
            set { yaJin = value; }
        }
        protected double zuJin;
        /// <summary>
        /// 实际应付租金
        /// </summary>
        public double ZuJin
        {
            get { return zuJin; }
            set { zuJin = value; }
        }
        protected string bookName;
        /// <summary>
        /// 图书名称
        /// </summary>
        public string BookName
        {
            get { return bookName; }
            set { bookName = value; }
        }

        protected Books book;
        /// <summary>
        /// 引用类型BOOKS类属性
        /// </summary>
        public Books Book
        {
            get { return book; }
            set { book = value; }
        }
    }
}
