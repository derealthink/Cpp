#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
        bool initialized;
    
    public:
        Contact() : initialized(false) {};
        void setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
        
        void printContact(); 

        int contactExists();

        std::string getFirstName();

        std::string getLastName();

        std::string getNickName();
}

#endif