
#include "book.h" // Include the header file for Book class
#include "member.h" // Include the header file for Member class
#include "transaction.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int ID, int year, int quantity, const std::string& location, const std::string& category)
    : title(title)
    , author(author)
    , ID(ID)
    , year(year)
    , quantity(quantity)
    , location(location)
    , category(category)
{
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

int Book::getID() const
{
    return ID;
}

int Book::getQuantity() const
{
    return quantity;
}
int Book::getBookID() const
{
    return ID;
}

std::string Book::getLocation() const
{
    return location;
}

int Book::getYear() const
{
    return year;
}

std::string Book::getCategory() const
{
    return category;
}

void Book::view() const
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Location: " << location << std::endl;
}

void Book::listBooks(const std::vector<Book>& books)
{
    for (const auto& book : books) {
        book.view();
        std::cout << "=============================" << std::endl;
    }
}

void Book::searchBook(const std::vector<Book>& books, const std::string& searchCriteria)
{
    for (const auto& book : books) {
        if (book.getTitle() == searchCriteria || book.getAuthor() == searchCriteria || std::to_string(book.getBookID()) == searchCriteria) {
            book.view();
            std::cout << "=============================" << std::endl;
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}

void Book::addNewBook(std::vector<Book>& books)
{
    std::string title, author, location, category;
    int ID, year, quantity;

    std::cout << "Enter book title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter ID: ";
    std::cin >> ID;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    std::cout << "Enter year: ";
    std::cin >> year;

    std::cin.ignore();
    std::cout << "Enter category: ";
    std::getline(std::cin, category);

    books.emplace_back(title, author, ID, year, quantity, location, category);
    std::cout << "Book added successfully!" << std::endl;
}

void Book::deleteBook(std::vector<Book>& books, int bookID)
{
    auto it = std::find_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.getBookID() == bookID;
    });
    if (it != books.end()) {
        books.erase(it);
        std::cout << "Book deleted successfully!" << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }
}