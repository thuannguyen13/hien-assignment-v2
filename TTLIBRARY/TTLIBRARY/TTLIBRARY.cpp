#include "book.h"
#include "member.h"
#include "user.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "catalog.h"
#include "transaction.h"

using namespace std;

int mainChoice;

void bookSubMenu(std::vector<Book>& books)
{
    int choice;
    do {
        std::cout << "===== BOOK MENU =====" << std::endl;
        std::cout << "1. View Books" << std::endl;
        std::cout << "2. Search Book" << std::endl;
        std::cout << "3. Add New Book" << std::endl;
        std::cout << "4. Delete Book" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            Book::listBooks(books);
            break;
        case 2: {
            std::string searchCriteria;
            std::cout << "Enter search criteria (title, author, or ID): ";
            std::cin.ignore();
            std::getline(std::cin, searchCriteria);
            Book::searchBook(books, searchCriteria);
            break;
        }
        case 3:
            Book::addNewBook(books);
            break;
        case 4: {
            int deleteID;
            std::cout << "Enter book ID to delete: ";
            std::cin >> deleteID;
            Book::deleteBook(books, deleteID);
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}

void displayMemberMenu(std::vector<Member>& members)
{
    int choice;
    do {
        std::cout << "----- Member Menu -----" << std::endl;
        std::cout << "1. Add Member" << std::endl;
        std::cout << "2. Delete Member" << std::endl;
        std::cout << "3. View All Members" << std::endl;
        std::cout << "4. Search Member by Name" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            Member::addNewMember(members);
            break;
        case 2: {
            int memberID;
            std::cout << "Enter Member ID to delete: ";
            std::cin >> memberID;
            Member::deleteMember(members, memberID);
            break;
        }
        case 3:
            Member::listMembers(members);
            break;
        case 4: {
            std::string searchName;
            std::cout << "Enter name to search: ";
            std::cin >> searchName;
            Member::searchMember(members, searchName);
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 0);
}
void catalogSubMenu(const Catalog& catalog)
{
    int choice;
    do {
        std::cout << "===== CATALOG SUBMENU =====" << std::endl;
        std::cout << "1. View Books by Author" << std::endl;
        std::cout << "2. View Books by Title" << std::endl;
        std::cout << "3. View Books by Year" << std::endl;
        std::cout << "4. View Books by Category" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string author;
            std::cout << "Enter author's name: ";
            std::cin.ignore();
            std::getline(std::cin, author);
            catalog.viewBooksByAuthor(author);
            break;
        }
        case 2: {
            std::string title;
            std::cout << "Enter book title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            catalog.viewBooksByTitle(title);
            break;
        }
        case 3: {
            int year;
            std::cout << "Enter publication year: ";
            std::cin >> year;
            catalog.viewBooksByYear(year);
            break;
        }
        case 4: {
            std::string category;
            std::cout << "Enter category: ";
            std::cin.ignore();
            std::getline(std::cin, category);
            catalog.viewBooksByCategory(category);
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}

void transactionSubMenu(Transaction& transaction, std::vector<Transaction>& transactions)
{
    int choice;
    do {
        std::cout << "===== TRANSACTION SUBMENU =====" << std::endl;
        std::cout << "1. Borrow Book" << std::endl;
        std::cout << "2. Return Book" << std::endl;
        std::cout << "3. List Transactions" << std::endl;
        std::cout << "4. Search Transaction" << std::endl;
        std::cout << "5. Delete Transaction" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int memberID, bookID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Book ID: ";
            std::cin >> bookID;
            transaction.borrowBook(memberID, bookID);
            Transaction::listTransactions();
            break;
        }
        case 2: {
            int memberID, bookID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Book ID: ";
            std::cin >> bookID;
            transaction.returnBook(memberID, bookID);
            break;
        }
        case 3: {
            Transaction::listTransactions();
            break;
        }
        case 4: {
            std::string searchCriteria;
            std::cout << "Enter search criteria: ";
            std::cin.ignore();
            std::getline(std::cin, searchCriteria);
            Transaction::searchTransaction(transactions, searchCriteria);
            break;
        }
        case 5: {
            int transactionID;
            std::cout << "Enter Transaction ID to delete: ";
            std::cin >> transactionID;
            transaction.deleteTransaction(transactions, transactionID);
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}

int main()
{
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Transaction> transactions;

    // Tạo một Catalog và khởi tạo nó với vector books
    Catalog catalog(books);

    int choice;
    do {
        std::cout << "===== MAIN MENU =====" << std::endl;
        std::cout << "1. Book Management" << std::endl;
        std::cout << "2. Member Management" << std::endl;
        std::cout << "3. Catalog Management" << std::endl;
        std::cout << "4. Transaction Management" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            bookSubMenu(books);
            break;
        case 2:
            displayMemberMenu(members);
            break;
        case 3:
            catalogSubMenu(catalog);
            break;
        case 4: {
            Transaction transaction(books, members);
            transactionSubMenu(transaction, transactions);
            break;
        }
        case 0:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);

    return 0;
}
