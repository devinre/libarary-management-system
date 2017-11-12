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
        /// �۸�ID
        /// </summary>
        public int BookPriceID
        {
            get { return bookPriceID; }
            set { bookPriceID = value; }
        }
        protected double bookUpPrice;
        /// <summary>
        /// �۸�����(��Χ)
        /// </summary>
        public double BookUpPrice
        {
            get { return bookUpPrice; }
            set { bookUpPrice = value; }
        }
        protected double bookDownPrice;
        /// <summary>
        /// �۸�����(��Χ)
        /// </summary>
        public double BookDownPrice
        {
            get { return bookDownPrice; }
            set { bookDownPrice = value; }
        }
        protected double bookPrice;
        /// <summary>
        /// ͼ�����
        /// </summary>
        public double BookPrice
        {
            get { return bookPrice; }
            set { bookPrice = value; }
        }
        
        protected int backDate;
        /// <summary>
        /// �黹����
        /// </summary>
        public int BackDate
        {
            get { return backDate; }
            set { backDate = value; }
        }
    }
}
