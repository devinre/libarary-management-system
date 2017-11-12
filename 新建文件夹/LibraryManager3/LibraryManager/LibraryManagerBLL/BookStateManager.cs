using System;
using System.Collections.Generic;
using System.Text;
using LibraryManagerModels;
using LibraryManagerDAL;

namespace LibraryManagerBLL
{
    public class BookStateManager
    {
        BookStateService bs = new BookStateService();
        public IList<BookState> GetBookState()
        {
            return bs.GetBookState();
        }
    }
}
