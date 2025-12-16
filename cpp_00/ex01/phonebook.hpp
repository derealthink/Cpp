#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();

    void setContact(const std::string& fn,
                    const std::string& ln,
                    const std::string& nn,
                    const std::string& pn,
                    const std::string& ds);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    bool isEmpty() const;
};


class PhoneBook
{
private:
    Contact contacts[8];
    int     count;
    int     next_index;

    std::string formatField(const std::string& str) const;

public:
    PhoneBook();

    void addContact();
    void searchContacts() const;
};



#endif