#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <string>
#include <iostream>
#include <ctime>
#include "library.h"

class Book
{
        int idNumber;
        std::string title;
        std::string author;
        int yearPublished;
        bool isBorrowed;


    public:
        Book(const Book&);
        Book(std::string, std::string, int);
        Book();
        ~Book();

        static int booksCreated;

        int GetID() const;
        std::string GetTitle() const;
        std::string GetAuthor() const;
        int GetYearPublished() const;
        bool GetBorrowedStatus() const;

        void SetBookBorrowed();
        void SetBookReturned();
};


#endif // BOOK_H_INCLUDED
