#include <iostream>
#include "user.h"
#include "book.h"

int Borrower::usersCreated = 0001;

User::User(std::string firstName, std::string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}

User::User() {}
User::~User() {}
std::string User::GetFirstName() const { return this->firstName; }
std::string User::GetLastName() const { return this->lastName; }

Borrower::Borrower(std::string firstName, std::string lastName, int maxBorrowedBooks)
    : User (firstName, lastName)
{
    this->maxBorrowedBooks = maxBorrowedBooks;
    this->currentBorrowedBooks = 0;
    this->borrowerID = Borrower::usersCreated++;
    this->borrowerBooks = new Book[maxBorrowedBooks];
}

Borrower::~Borrower() {}
int Borrower::GetCurrentBorrowedBooks() const { return this->currentBorrowedBooks; }
int Borrower::GetMaxBorrowedBooks() const { return this->maxBorrowedBooks; }
int Borrower::GetBorrowerID() const { return this->borrowerID; }

void Borrower::AddBook(const Book& bookToAdd)
{
    if (this->GetCurrentBorrowedBooks() < this->GetMaxBorrowedBooks())
    {
        this->borrowerBooks[this->GetCurrentBorrowedBooks()] = bookToAdd;
        this->currentBorrowedBooks++;
    }
}

void Borrower::IncrementBorrowedBooks() { this->currentBorrowedBooks++; }
void Borrower::DecrementBorrowedBooks() { this->currentBorrowedBooks--; }

void Borrower::ReturnBook(Library& mainLibrary, int listNumber)
{
    if (this->GetCurrentBorrowedBooks() > 0
        && listNumber - 1 < this->GetCurrentBorrowedBooks())
    {
        //loop that finds a match for borrowed book to set it to available
        for (int i = 0; i < mainLibrary.GetCurrentBookCount(); i++)
        {
            if (this->GetBorrowedBook(i).GetID() == mainLibrary.GetBook(i).GetID())
            {
                mainLibrary.GetBook(listNumber - 1).SetBookReturned();
            }
        }
    }
}

Book& Borrower::GetBorrowedBook(int index)
{
    if (index < this->GetCurrentBorrowedBooks())
        return this->borrowerBooks[index];
    else
        return this->borrowerBooks[0];
}

void Borrower::ShowBorrowedBooks()
{
    for (int index = 0; index < this->GetCurrentBorrowedBooks(); index++)
    {
        std::cout << "Book #: " << index + 1 << std::endl;
        std::cout << "Title: " << this->GetBorrowedBook(index).GetTitle() << std::endl;
        std::cout << "Author: " << this->GetBorrowedBook(index).GetAuthor() << std::endl;
        std::cout << "Year: " << this->GetBorrowedBook(index).GetYearPublished() << std::endl;
    }
}

Librarian::Librarian(std::string firstName, std::string lastName, int maxBorrowedBooks)
    : Borrower (firstName, lastName, maxBorrowedBooks)
{}

Librarian::~Librarian() {}

void Librarian::LendBook(Library& mainLibrary, Borrower& borrower, int index)
{
    if (mainLibrary.GetCurrentBookCount() > 0)
    {
        if (borrower.GetCurrentBorrowedBooks() < borrower.GetMaxBorrowedBooks()
            && index < mainLibrary.GetCurrentBookCount())
        {
            borrower.AddBook(mainLibrary.GetBook(index));
            mainLibrary.GetBook(index).SetBookBorrowed();
            mainLibrary.DecrementBooksAvailable();
        }
    }
}
