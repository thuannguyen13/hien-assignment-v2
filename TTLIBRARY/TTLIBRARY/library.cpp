#include "library.h"

// Constructor
Library::Library()
{
    // Khởi tạo các biến hoặc cấu trúc dữ liệu cần thiết ở đây
}

// Quản lý thành viên
void Library::addMember(const Member& member)
{
    members.push_back(member);
}

void Library::removeMember(int memberID)
{
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& member) {
        return member.getID() == memberID;
    });

    if (it != members.end()) {
        members.erase(it);
        std::cout << "Thành viên đã được xóa thành công." << std::endl;
    } else {
        std::cout << "Không tìm thấy thành viên để xóa." << std::endl;
    }
}
void Library::listMembers() const
{
    if (members.empty()) {
        std::cout << "Không có thành viên nào." << std::endl;
        return;
    }

    std::cout << "Danh sách thành viên: " << std::endl;
    for (const auto& member : members) {
        member.displayInfo(); // Assumed displayInfo is a member function in the Member class to display member information
    }
}
void Library::addBook(const Book& book)
{
    books.push_back(book);
}

void Library::removeBook(int bookID)
{
    auto it = std::find_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.getID() == bookID;
    });

    if (it != books.end()) {
        books.erase(it);
        std::cout << "Sách đã được xóa thành công." << std::endl;
    } else {
        std::cout << "Không tìm thấy sách để xóa." << std::endl;
    }
}
void Library::listBooks() const
{
    if (books.empty()) {
        std::cout << "Không có sách nào." << std::endl;
        return;
    }

    std::cout << "Danh sách sách: " << std::endl;
    for (const auto& book : books) {
        book.displayInfo(); // Assumed displayInfo is a member function in the Book class to display book information
    }
}
// Quản lý giao dịch
void Library::addTransaction(const Transaction& transaction)
{
    transactions.push_back(transaction);
}

void Library::removeTransaction(int transactionID)
{
    auto it = std::find_if(transactions.begin(), transactions.end(), [transactionID](const Transaction& transaction) {
        return transaction.getID() == transactionID;
    });

    if (it != transactions.end()) {
        transactions.erase(it);
        std::cout << "Giao dịch đã được xóa thành công." << std::endl;
    } else {
        std::cout << "Không tìm thấy giao dịch để xóa." << std::endl;
    }
}
void Library::listTransactions() const
{
    if (transactions.empty()) {
        std::cout << "Không có giao dịch nào." << std::endl;
        return;
    }

    std::cout << "Danh sách giao dịch: " << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << transaction.getTransactionInfo() << std::endl;
    }
}
