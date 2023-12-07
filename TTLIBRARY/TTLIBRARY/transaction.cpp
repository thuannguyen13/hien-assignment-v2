#include "transaction.h"
#include "member.h"
#include <iostream>

Transaction::Transaction(const std::vector<Book>& books, const std::vector<Member>& members)
    : booksRef(&books)
    , membersRef(&members)
{
    // Khởi tạo các thành viên và sách ở đây nếu cần
}

std::vector<std::pair<int, int>> Transaction::transactions;

void Transaction::borrowBook(int memberID, int bookID)
{
    bool memberExists = false;
    bool bookExists = false;

    // Kiểm tra xem thành viên và sách có tồn tại không
    for (const Member& member : *membersRef) {
        if (member.getID() == memberID) {
            memberExists = true;
            break;
        }
    }

    for (const Book& book : *booksRef) {
        if (book.getBookID() == bookID) {
            bookExists = true;
            break;
        }
    }

    if (!memberExists || !bookExists) {
        std::cout << "Không thể mượn sách. Thành viên hoặc sách không tồn tại." << std::endl;
        return;
    }

    // Truy cập borrowedBooks thông qua đối tượng Transaction hiện tại bằng "this"

    this->borrowedBooks.push_back(std::make_pair(memberID, bookID));
    addTransaction(memberID, bookID);

    std::cout << "Sách đã được mượn thành công." << std::endl;
}

void Transaction::returnBook(int memberID, int bookID)
{
    auto it = std::find_if(borrowedBooks.begin(), borrowedBooks.end(),
        [memberID, bookID](const std::pair<int, int>& item) {
            return item.first == memberID && item.second == bookID;
        });

    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        std::cout << "The book has been returned successfully." << std::endl;
    } else {
        std::cout << "No matching borrowing information was found." << std::endl;
    }

    // xoá transaction khỏi transactions list
    it = std::find_if(transactions.begin(), transactions.end(),
        [memberID, bookID](const std::pair<int, int>& item) {
            return item.first == memberID && item.second == bookID;
        });

    if (it != transactions.end()) {
        transactions.erase(it);
    }
}

void Transaction::addTransaction(int memberID, int bookID)
{
    transactions.push_back(std::make_pair(memberID, bookID));
}

void Transaction::listTransactions()
{
    if (transactions.empty()) {
        std::cout << "No transactions." << std::endl;
        return;
    }

    std::cout << "List of transactions: " << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << "Member ID: " << transaction.first << ", Book ID: " << transaction.second << std::endl;
    }
}

int Transaction::getID() const
{
    // Cài đặt logic để trả về ID tương ứng của Transaction
    return this->transactionID; // Ví dụ: Trả về transactionID, giả sử transactionID là một biến thành viên trong lớp Transaction
}

std::string Transaction::getTransactionInfo() const
{
    // Cài đặt logic để trả về thông tin giao dịch tương ứng của Transaction
    return this->transactionInfo; // Ví dụ: Trả về transactionInfo, giả sử transactionInfo là một biến thành viên trong lớp Transaction
}
void Transaction::searchTransaction(const std::vector<Transaction>& transactions, const std::string& searchCriteria)
{
    bool found = false;

    for (const auto& transaction : transactions) {
        // Giả sử có một trường có thể tìm kiếm trong Transaction là 'transactionInfo'
        // Bạn có thể thay thế 'transactionInfo' bằng trường dữ liệu thực tế bạn muốn tìm kiếm
        if (transaction.getTransactionInfo() == searchCriteria) {
            found = true;
            std::cout << "Thông tin giao dịch được tìm thấy: " << transaction.getTransactionInfo() << std::endl;
            // Nếu bạn muốn hiển thị thông tin cụ thể của giao dịch được tìm thấy, bạn có thể thêm mã ở đây
        }
    }

    if (!found) {
        std::cout << "Không tìm thấy thông tin giao dịch phù hợp." << std::endl;
    }
}

void Transaction::deleteTransaction(std::vector<Transaction>& transactions, int transactionID)
{
    // Xóa thông tin giao dịch theo ID
    auto it = std::remove_if(transactions.begin(), transactions.end(),
        [transactionID](const Transaction& transaction) {
            // Logic kiểm tra xem transaction có ID phù hợp để xóa không
            // Giả sử có một phương thức 'getID()' trong Transaction để lấy ID của giao dịch
            return transaction.getID() == transactionID; // Thay 'getID()' bằng phương thức hoặc trường thực tế trong Transaction
        });

    if (it != transactions.end()) {
        transactions.erase(it, transactions.end());
        std::cout << "Đã xóa giao dịch thành công." << std::endl;
    } else {
        std::cout << "Không tìm thấy giao dịch để xóa." << std::endl;
    }
}
