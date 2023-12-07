#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include <iostream>
#include <string>
#include <vector>

class Member : public User {
public:
    Member(const std::string& name,
        const std::string& address,
        const std::string& phone,
        int ID,
        const std::string& contactInfo);

    void view() const override;
    void displayInfo() const { }
    int getID() const;
    std::string getContactInfo() const;

    static void listMembers(const std::vector<Member>& members);
    static void searchMember(const std::vector<Member>& members, const std::string& searchCriteria);
    static void addNewMember(std::vector<Member>& members);
    static void deleteMember(std::vector<Member>& members, int ID);

private:
    int ID;
    std::string contactInfo;
    std::string name;
};

#endif // MEMBER_H
