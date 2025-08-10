#include "PhoneBook.h"

Contact::Contact() : firstName(""), lastName(""), nickname(""), 
                    phoneNumber(""), darkestSecret("") {}

void Contact::getInput(std::string &field, std::string prompt)
{
    std::cout << prompt;
    std::getline(std::cin, field);
    if(field.empty())
        std::cout << "A saved contact can't have empty fields" << std::endl;
}

Contact Contact::create()
{
    Contact contact;
    while(contact.firstName.empty())
        getInput(contact.firstName, "Enter first name: ");
    while(contact.lastName.empty())
        getInput(contact.lastName, "Enter last name: ");
    while(contact.nickname.empty())
        getInput(contact.nickname, "Enter nickname: ");
    while(contact.phoneNumber.empty())
        getInput(contact.phoneNumber, "Enter phone number: ");
    while(contact.darkestSecret.empty())
        getInput(contact.darkestSecret, "Enter darkest secret: ");
    return contact;
}

void Contact::displayString(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    std::cout << std::right << std::setw(10) << str << "|";
}

void Contact::display(int index)
{
    std::cout << "|";
    displayString(std::to_string(index));
    displayString(firstName);
    displayString(lastName);
    displayString(nickname);
    std::cout << std::endl;
}
