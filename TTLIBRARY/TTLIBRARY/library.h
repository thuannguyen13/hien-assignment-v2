#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "member.h"
#include "transaction.h"
#include <vector>

class Library {
private:
    std::vector<Member> members;
    std::vector<Book> books;
    std::vector<Transaction> transactions;

public:
    // Constructor
    Library();

    // Member management
    void addMember(const Member& member);
    void removeMember(int memberID);
    void listMembers() const;

    // Book management
    void addBook(const Book& book);
    void removeBook(int bookID);
    void listBooks() const;

    // Transaction management
    void addTransaction(const Transaction& transaction);
    void removeTransaction(int transactionID);
    void listTransactions() const;
};

#endif // LIBRARY_H
