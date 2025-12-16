#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(0), next_index(0) {}

std::string PhoneBook::formatField(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

static std::string getInput(const std::string& prompt)
{
    std::string input;
    while (input.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, input);
    }
    return input;
}

void PhoneBook::addContact()
{
    std::string fn = getInput("First name: ");
    std::string ln = getInput("Last name: ");
    std::string nn = getInput("Nickname: ");
    std::string pn = getInput("Phone number: ");
    std::string ds = getInput("Darkest secret: ");

    contacts[next_index].setContact(fn, ln, nn, pn, ds);

    if (count < 8)
        count++;

    next_index = (next_index + 1) % 8;
}

void PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty\n";
        return;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << "|"
                  << std::setw(10) << i << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickname()) << "|\n";
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "Enter index: ";

    int index;
    std::cin >> index;
    std::cin.ignore(10000, '\n');

    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index\n";
        return;
    }

    std::cout << "First name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << "\n";
}