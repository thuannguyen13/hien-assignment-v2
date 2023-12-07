#include "member.h"
#include "book.h" // Include the header file for Book class
#include "transaction.h"
#include "user.h"
#include <iostream>
#include <string>
#include <vector>

Member::Member(const std::string& name, const std::string& address, const std::string& phone,
    int _ID, const std::string& _contactInfo)
    : User(name, address, phone)
    , ID(_ID)
    , contactInfo(_contactInfo)
{
}

void Member::view() const
{
    User::view();
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Contact Info: " << contactInfo << std::endl;
}

int Member::getID() const
{
    return ID;
}

std::string Member::getContactInfo() const
{
    return contactInfo;
}

void Member::listMembers(const std::vector<Member>& members)
{
    std::cout << "List of Members:" << std::endl;
    for (const auto& member : members) {
        member.view();
        std::cout << "------------------------" << std::endl;
    }
}

void Member::searchMember(const std::vector<Member>& members, const std::string& searchCriteria)
{
    std::cout << "Search results:" << std::endl;
    bool found = false;
    for (const auto& member : members) {
        if (member.getName() == searchCriteria) {
            member.view();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "No member found with the provided name." << std::endl;
    }
}

void Member::addNewMember(std::vector<Member>& members)
{
    std::string name, address, phone, contactInfo;
    int ID = 0; // Khởi tạo ID với giá trị mặc định

    // Nhập thông tin cho thành viên mới (bạn có thể sử dụng std::cin hoặc các phương thức nhập liệu khác)
    // Ví dụ:
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter address: ";
    std::cin >> address;
    std::cout << "Enter phone: ";
    std::cin >> phone;
    std::cout << "Enter ID: ";
    std::cin >> ID; // Nhập giá trị cho ID

    // Tạo một đối tượng Member mới và thêm vào vector members
    members.push_back(Member(name, address, phone, ID, contactInfo));
    std::cout << "Member added successfully." << std::endl;
}

void Member::deleteMember(std::vector<Member>& members, int ID)
{
    auto it = std::find_if(members.begin(), members.end(),
        [ID](const Member& member) { return member.getID() == ID; });

    if (it != members.end()) {
        members.erase(it);
        std::cout << "Member deleted successfully." << std::endl;
    } else {
        std::cout << "Member with the provided ID not found." << std::endl;
    }
}
