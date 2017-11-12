using System;
using System.Collections.Generic;
using System.Text;

namespace LibraryManagerModels
{
    [Serializable]
    public class BookState
    {
        protected int stateID;
        /// <summary>
        /// ״̬ID
        /// </summary>
        public int StateID
        {
            get { return stateID; }
            set { stateID = value; }
        }
        protected string state;
        /// <summary>
        /// ͼ��״̬
        /// </summary>
        public string State
        {
            get { return state; }
            set { state = value; }
        }
    }
}
