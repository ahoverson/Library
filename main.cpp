#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include "library.h"
#include "book.h"
#include "user.h"

const int MAX_LIBRARY_BOOKS = 5;
const int MAX_BORROWED_BOOKS = 5;

void DisplayIntro();
void DisplayCurrentUser();
void DisplayMenu();
void RunLibrary();
int GetValidMenuOption();
bool AskToBorrowBook();
void LendBookToBorrower();
void ReturnBook();
bool AskToReturnMenu(); //Ask to perform another menu action at end of do while

//Instantiates library and books
Library mainLibrary(MAX_LIBRARY_BOOKS);
Librarian librarian1("Daisy", "Holland", MAX_BORROWED_BOOKS);
Book book1("The Gunslinger", "Stephen King", 1982);
Book book2("Homo Deus", "Yuval Noah Harari", 2017);
Book book3("Programming in Lua", "Roberto Ierusalimschy", 2016);

//Instantiates borrower
Borrower borrower1("Sunny", "Holland", MAX_BORROWED_BOOKS);

int main()
{
    mainLibrary.AddBook(book1);
    mainLibrary.AddBook(book2);
    mainLibrary.AddBook(book3);

    //variable for do while menu
    bool runLibraryProgram = true;

    do
    {
        system("CLS");
        DisplayIntro();
        DisplayCurrentUser();
        DisplayMenu();

        std::cin.clear();

        RunLibrary();
        runLibraryProgram = AskToReturnMenu();

    } while (runLibraryProgram);

    return 0;
}

void DisplayIntro()
{
    std::cout << "Welcome to the Library!" << std::endl;
}

void DisplayCurrentUser()
{
    std::cout << "The current user logged in is: " << borrower1.GetFirstName()
        << " " << borrower1.GetLastName() << ".\n\n";
}

void DisplayMenu()
{
    std::cout << "Select an option from the menu by entering a number.\n\n";
    std::cout << "[1] See books available for loan and borrow them.\n";
    std::cout << "[2] See all books in the library catalogue.\n";
    std::cout << "[3] Return a book.\n";
//    std::cout << "[4] Create borrower account (librarian only).\n";
//    std::cout << "[5] Add a book to the catalogue (librarian only).\n";
    std::cout << "[0] Exit the program.\n\n";

    std::cout << "What would you like to do? ";
}

void RunLibrary()
{
    switch(GetValidMenuOption())
    {
        case 1: //Show books available for loan
            {
                system("CLS");
                mainLibrary.ShowAvailableBooks();
//                std::cout << AskToBorrowBook() << std::endl;
                if (AskToBorrowBook())
                {
                    LendBookToBorrower();
                }
                break;
                }
        case 2: //Show all books owned by the library
            {
                system("CLS");
                mainLibrary.ShowAllBooks();
                system("PAUSE");
                break;
            }
        case 3: //Return a book
            {
                ReturnBook();
                break;
            }
        case 4: //Add a book to the library
            {
                //mainLibrary.AddBook()
            }
        case 5: //CreateUser
                break;
        case 0: //Ask to continue or end the program
            {

                break;
            }
    }
}

int GetValidMenuOption()
{

    bool isEnteredOptionValid = false;

    while (isEnteredOptionValid != true)
    {
        int enteredOption = -1;
        std::cout << std::endl;
        std::cin >> enteredOption;
        if (enteredOption < 0 || enteredOption > 5)
        {
            std::cout << "\nPlease enter a number option between 1 to 3 or 0 to exit.\n";
        }
        else
        {
            isEnteredOptionValid = true;
            return enteredOption;
        }
    }
}

bool AskToBorrowBook()
{
    char response = '\0';

    std::cout << "\nWould you like to borrow one of these books? (y/n) ";

    while (true)
    {
        if (std::cin >> response)
            break;
        else
        {
            std::cout << "Please type y or n.\n";
            std::cin.clear();
        }
    }
    return (response == 'y') || (response == 'Y');
}

void LendBookToBorrower()
{
    int idNumber = -1;

    std::cout << "Which book would you like to borrow? (Enter the list number) ";
    std::cin >> idNumber;
    idNumber--;

    librarian1.LendBook(mainLibrary, borrower1, idNumber);
    std::cout << std::endl;
    std::cout << mainLibrary.GetBook(idNumber).GetTitle() << " has been loaned out to "
        << borrower1.GetFirstName() << " " << borrower1.GetLastName() << ".\n";
/*
    //TODO borrower user search
    int borrowerID = 0;
    int bookID = 0;

    std::cout << "\nWho is borrowing the book? Enter your member ID number: ";
    std::cin >> borrowerID;

    //Find borrower
    for (int i = 0; i < )
        //check current book count

    std::cout << "\nWhich book would you like to borrow? Please enter the book ID #: ";
    std::cin >> bookID;

    //Find book
        //check available or not

    //add book to borrower list
    //set book to borrowed
*/
    return;
}

void ReturnBook()
{
    std::cout << "Which book would you like to return? (Enter the list number)\n";
    borrower1.ShowBorrowedBooks();

    int listNumber = -1;
    std::cin >> listNumber;
    borrower1.ReturnBook(mainLibrary, listNumber);
}


bool AskToReturnMenu()
{
    char response = '\0';

    std::cout << "\nWould you like to go to the main menu? (y/n)\n";

    while (true)
    {
        if (std::cin >> response)
            break;
        else
        {
            std::cout << "Please type y or n.\n";
            std::cin.clear();
        }
    }
    return (response == 'y') || (response == 'Y');
}
