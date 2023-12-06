#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
    // Constructors
    User(const std::string& name, const std::string& address, const std::string& phone);
    User(); // Default constructor

    // Member functions
    int getUserID() const;
    virtual void view() const;
    bool searchByName(const std::string& searchName) const;

    // Static functions
    static void listUsers(const std::vector<User>& users);
    static void searchUser(const std::vector<User>& users, const std::string& searchCriteria);
    static void viewUser(const User& user);
    static void addUser(std::vector<User>& users);
    static void deleteUser(std::vector<User>& users, const std::string& nameToDelete);

    // Getters for user attributes
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;

private:
    std::string name;
    std::string address;
    std::string phone;
};

#endif // USER_H
