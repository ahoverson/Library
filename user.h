#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include "book.h"

class User
{
   protected:
        std::string firstName;
        std::string lastName;
    public:
        User(std::string, std::string);
        User();
        ~User();

        std::string GetFirstName() const;
        std::string GetLastName() const;
};

class Borrower : public User
{
    protected:
        int maxBorrowedBooks;
        int currentBorrowedBooks;
        int borrowerID;
        Book* borrowerBooks;

    public:
        Borrower(std::string, std::string, int);
        ~Borrower();

        static int usersCreated;

        Book& GetBorrowedBook(int);

        int GetMaxBorrowedBooks() const;
        int GetCurrentBorrowedBooks() const;
        void IncrementBorrowedBooks();
        void DecrementBorrowedBooks();
        int GetBorrowerID() const;
        void AddBook(const Book&);
        void ReturnBook(Library&, int);
        void ShowBorrowedBooks();

};

class Librarian : public Borrower
{
    protected:

    public:
        Librarian(std::string, std::string, int);
        ~Librarian();

        void LendBook(Library&, Borrower&, int);
};

#endif // USER_H_INCLUDED
