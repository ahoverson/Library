#include <iostream>
#include "library.h"

Library::Library(int maxBookCount)
{
    this->maxBookCount = maxBookCount;
    this->books = new Book[maxBookCount];
    this->currentBookCount = 0;
    this->currentBooksAvailable = 0;
}

Library::Library() {}
Library::~Library() { delete[] books; }
int Library::GetAvailableBookCount() const { return this->currentBooksAvailable; }
void Library::IncrementBookCount() { this->currentBookCount++; }
void Library::DecrementBookCount() { this->currentBookCount--; }
void Library::IncrementBooksAvailable() { this->currentBooksAvailable++; }
void Library::DecrementBooksAvailable() { this->currentBooksAvailable--; }

void Library::AddBook(const Book& bookToAdd)
{
    if (currentBookCount < maxBookCount)
    {
        this->books[currentBookCount] = bookToAdd;
        this->IncrementBookCount();
        this->IncrementBooksAvailable();
    }
}

void Library::RemoveBook(Book& bookToRemove)
{
    if (currentBookCount > 0)
    {
            this->DecrementBookCount();
            this->DecrementBooksAvailable();
    }
    return;
}

Book& Library::GetBook(int index)
{
    if (index < this->currentBookCount)
        return this->books[index];
    else
        return this->books[0];
}

int Library::GetCurrentBookCount() const { return this->currentBookCount; }
int Library::GetMaxBookCount() const { return this->maxBookCount; }

void Library::ShowAvailableBooks()
{
    std::cout << "Books currently available for loan: " << this->GetAvailableBookCount() << "\n\n";

    for (int index = 0; index < this->currentBookCount; index++)
    {
        if (this->GetBook(index).GetBorrowedStatus() != true)
        {
            std::cout << "ID#: " << this->GetBook(index).GetID() << std::endl;
            std::cout << "Title: " << this->GetBook(index).GetTitle() << std::endl;
            std::cout << "Author: " << this->GetBook(index).GetAuthor() << std::endl;
            std::cout << "Year: " << this->GetBook(index).GetYearPublished() << std::endl << std::endl;
        }
    }

    return;
}

void Library::ShowAllBooks()
{
    std::cout << "Books currently owned by the library: " << this->GetCurrentBookCount() << "\n\n";

    for (int index = 0; index < this->currentBookCount; index++)
    {
        std::cout << "ID#: " << this->GetBook(index).GetID() << std::endl;
        std::cout << "Title: " << this->GetBook(index).GetTitle() << std::endl;
        std::cout << "Author: " << this->GetBook(index).GetAuthor() << std::endl;
        std::cout << "Year: " << this->GetBook(index).GetYearPublished() << std::endl;

        if (this->GetBook(index).GetBorrowedStatus() != true)
            std::cout << "Status: Available\n\n";
        else
            std::cout << "Status: On loan\n\n";
    }

    return;
}
