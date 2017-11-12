using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class BooksPrice
    {
        protected int bookPriceID;
        /// <summary>
        /// 价格ID
        /// </summary>
        public int BookPriceID
        {
            get { return bookPriceID; }
            set { bookPriceID = value; }
        }
        protected double bookUpPrice;
        /// <summary>
        /// 价格上限(范围)
        /// </summary>
        public double BookUpPrice
        {
            get { return bookUpPrice; }
            set { bookUpPrice = value; }
        }
        protected double bookDownPrice;
        /// <summary>
        /// 价格下限(范围)
        /// </summary>
        public double BookDownPrice
        {
            get { return bookDownPrice; }
            set { bookDownPrice = value; }
        }
        protected double bookPrice;
        /// <summary>
        /// 图书租金
        /// </summary>
        public double BookPrice
        {
            get { return bookPrice; }
            set { bookPrice = value; }
        }
        
        protected int backDate;
        /// <summary>
        /// 归还期限
        /// </summary>
        public int BackDate
        {
            get { return backDate; }
            set { backDate = value; }
        }
    }
}
