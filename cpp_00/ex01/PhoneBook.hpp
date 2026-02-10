#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    
    private:
        Contact Contacts[id];

        std::string getFirstName(int id);

        std::string getLastName(int id);

        std::string getNickname(int id);

    public:
        void setContactId(int id, std::string first, std::string last, std::string nick, std::string phone, std::string secret);

        void printContactId(int id);

        int isContactUsed(int id);

        void listPhoneBook();
};


#endif