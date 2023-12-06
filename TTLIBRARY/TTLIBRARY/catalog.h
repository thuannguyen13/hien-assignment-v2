#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "book.h"

class Catalog
{
public:
    Catalog(const std::vector<Book>& books);

    void viewBooksByAuthor(const std::string& author) const;
    void viewBooksByTitle(const std::string& title) const;
    void viewBooksByYear(int year) const;
    void viewBooksByCategory(const std::string& category) const;

    static void listBooksByAuthor(const std::vector<Book>& books, const std::string& author);
    static void listBooksByTitle(const std::vector<Book>& books, const std::string& title);
    static void listBooksByYear(const std::vector<Book>& books, int year);
    static void listBooksByCategory(const std::vector<Book>& books, const std::string& category);

private:
    const std::vector<Book>& booksRef;
};

#endif // CATALOG_H
