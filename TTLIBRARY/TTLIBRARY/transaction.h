#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "book.h"
#include "member.h"
#include <iostream>
#include <string>
#include <vector>

class Member;

class Transaction {
public:
    Transaction(const std::vector<Book>& books, const std::vector<Member>& members);
    void borrowBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    int getID() const;
    std::string getTransactionInfo() const;
    static void listTransactions(const std::vector<Transaction>& transactions);
    static void searchTransaction(const std::vector<Transaction>& transactions, const std::string& searchCriteria);
    static void deleteTransaction(std::vector<Transaction>& transactions, int transactionID);

private:
    int ID;
    int transactionID;
    std::vector<std::pair<int, int>> borrowedBooks;
    std::string transactionInfo;
    const std::vector<Book>* booksRef;
    const std::vector<Member>* membersRef;
    static std::vector<Transaction> transactions;
};

#endif // TRANSACTION_H
