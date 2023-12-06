#include "catalog.h"
#include <iostream>

Catalog::Catalog(const std::vector<Book>& books) : booksRef(books) {}

void Catalog::viewBooksByAuthor(const std::string& author) const
{
    listBooksByAuthor(booksRef, author);
}

void Catalog::viewBooksByTitle(const std::string& title) const
{
    listBooksByTitle(booksRef, title);
}

void Catalog::viewBooksByYear(int year) const
{
    listBooksByYear(booksRef, year);
}

void Catalog::viewBooksByCategory(const std::string& category) const
{
    listBooksByCategory(booksRef, category);
}

void Catalog::listBooksByAuthor(const std::vector<Book>& books, const std::string& author)
{
    std::cout << "Books by author " << author << ":" << std::endl;
    for (const auto& book : books)
    {
        if (book.getAuthor() == author)
        {
            book.view();
        }
    }
}

void Catalog::listBooksByTitle(const std::vector<Book>& books, const std::string& title)
{
    std::cout << "Books with title " << title << ":" << std::endl;
    for (const auto& book : books)
    {
        if (book.getTitle() == title)
        {
            book.view();
        }
    }
}

void Catalog::listBooksByYear(const std::vector<Book>& books, int year)
{
    std::cout << "Books published in year " << year << ":" << std::endl;
    for (const auto& book : books)
    {
        if (book.getYear() == year)
        {
            book.view();
        }
    }
}

void Catalog::listBooksByCategory(const std::vector<Book>& books, const std::string& category)
{
    std::cout << "Books in category " << category << ":" << std::endl;
    for (const auto& book : books)
    {
        if (book.getCategory() == category)
        {
            book.view();
        }
    }
}
