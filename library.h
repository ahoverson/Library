#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <iostream>
#include "book.h"

class Book;

class Library
{
        Book* books;
        int maxBookCount;
        int currentBooksAvailable;
        int currentBookCount;

    public:
        Library();
        Library(int);
        ~Library();

        Book& GetBook(int);
        int GetAvailableBookCount() const;
        int GetCurrentBookCount() const;
        int GetMaxBookCount() const;
        bool GetBorrowedStatus(int) const;
        void AddBook(const Book&);
        void RemoveBook(Book&); //remove book from library, remove gap in index
        void IncrementBookCount();
        void DecrementBookCount();
        void IncrementBooksAvailable();
        void DecrementBooksAvailable();
        void ShowAllBooks();
        void ShowAvailableBooks();
};


#endif // LIBRARY_H_INCLUDED
