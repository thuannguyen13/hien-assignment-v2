#include "user.h"
#include <algorithm> // For std::find_if
#include <iostream>

// Constructors
User::User(const std::string& name, const std::string& address, const std::string& phone)
    : name(name)
    , address(address)
    , phone(phone)
{
}

User::User()
    : name("")
    , address("")
    , phone("")
{
}

// Member functions
int User::getUserID() const
{
    // Đoạn mã này có thể cần triển khai để trả về ID của người dùng
    return 0; // Đây chỉ là giá trị mẫu
}

void User::view() const
{
    std::cout << "User Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone: " << phone << std::endl;
}

bool User::searchByName(const std::string& searchName) const
{
    return name == searchName;
}

// Static functions
void User::listUsers(const std::vector<User>& users)
{
    std::cout << "List of Users:" << std::endl;
    for (const auto& user : users) {
        user.view();
        std::cout << "------------------------" << std::endl;
    }
}

void User::searchUser(const std::vector<User>& users, const std::string& searchCriteria)
{
    std::cout << "Search results:" << std::endl;
    bool found = false;
    for (const auto& user : users) {
        if (user.searchByName(searchCriteria)) {
            user.view();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No user found with the provided criteria." << std::endl;
    }
}

void User::viewUser(const User& user)
{
    user.view();
}

void User::addUser(std::vector<User>& users)
{
    std::string name, address, phone;
    std::cout << "Enter user name: ";
    std::cin >> name;
    std::cout << "Enter user address: ";
    std::cin >> address;
    std::cout << "Enter user phone: ";
    std::cin >> phone;

    users.emplace_back(name, address, phone);
    std::cout << "New user added successfully." << std::endl;
}

void User::deleteUser(std::vector<User>& users, const std::string& nameToDelete)
{
    auto it = std::find_if(users.begin(), users.end(),
        [&](const User& user) {
            return user.searchByName(nameToDelete);
        });

    if (it != users.end()) {
        users.erase(it);
        std::cout << "User deleted successfully." << std::endl;
    } else {
        std::cout << "User with the provided name not found." << std::endl;
    }
}

// Getters for user attributes
std::string User::getName() const
{
    return name;
}

std::string User::getAddress() const
{
    return address;
}

std::string User::getPhone() const
{
    return phone;
}
