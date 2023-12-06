#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book
{
public:
    Book() = default;
    Book(const std::string& title, const std::string& author, int ID, int year, int quantity, const std::string& location, const std::string& category);
    void displayInfo() const {
        // Hiển thị thông tin sách
    }
    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getID() const;
    int getQuantity() const;
    int getYear() const;
    int getBookID() const;
    std::string getCategory() const;
    std::string getLocation() const;

    void view() const;

    static void listBooks(const std::vector<Book>& books);
    static void searchBook(const std::vector<Book>& books, const std::string& searchCriteria);
    static void addNewBook(std::vector<Book>& books);
    static void deleteBook(std::vector<Book>& books, int bookID);

private:
    std::string title;
    std::string author;
    int ID = 0;
    int year = 0;
    int bookID = 0;
    std::string category;
    int quantity = 0;
    std::string location;
};

#endif // BOOK_H
