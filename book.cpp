#include "book.h"
#include <iostream>

int Book::booksCreated = 1;

int Book::GetID() const { return this->idNumber; }
std::string Book::GetTitle() const { return this->title; }
std::string Book::GetAuthor() const { return this->author; }
int Book::GetYearPublished() const { return this->yearPublished; }
bool Book::GetBorrowedStatus() const { return this->isBorrowed; }
void Book::SetBookBorrowed() { this->isBorrowed = true; }
void Book::SetBookReturned() { this->isBorrowed = false; }

Book::Book(std::string title, std::string author, int year)
{
    this->title = title;
    this->author = author;
    this->yearPublished = year;
    this->idNumber = Book::booksCreated++;
    this->isBorrowed = false;
}

Book::Book(const Book& bookToCopy)
{
    this->title = bookToCopy.GetTitle();
    this->author = bookToCopy.GetAuthor();
    this->yearPublished = bookToCopy.GetYearPublished();
    this->idNumber = Book::booksCreated++;
    this->isBorrowed = false;
}

Book::Book() {}
Book::~Book() {}
