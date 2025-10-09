#include "PhoneBook.h"

Contact::Contact() : firstName(""), lastName(""), nickname(""), 
                    phoneNumber(""), darkestSecret("") {}

void Contact::getInput(std::string &field, std::string prompt)
{
    while(field.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, field);
        if(std::cin.eof() || field.empty())
            std::cout << "A saved contact can't have empty fields" << std::endl;
    }
}

void Contact::getNumberInput(std::string &field, std::string prompt)
{
    while(field.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, field);
        if(std::cin.eof() || field.empty())
        {
            std::cout << "A saved contact can't have empty fields" << std::endl;
            continue;
        }
        try
        {
            std::stoll(field);
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "Invalid phone number format" << std::endl;
            field.clear();
        }
        catch(const std::out_of_range& e)
        {
            std::cout << "Invalid phone number format" << std::endl;
            field.clear();
        }
    }
}

Contact Contact::create()
{
    Contact contact;
    getInput(contact.firstName, "Enter first name: ");
    getInput(contact.lastName, "Enter last name: ");
    getInput(contact.nickname, "Enter nickname: ");
    getNumberInput(contact.phoneNumber, "Enter phone number: ");
    getInput(contact.darkestSecret, "Enter darkest secret: ");
    return contact;
}

void Contact::displayString(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    std::cout << std::right << std::setw(10) << str << "|";
}

void Contact::displaySimple(int index)
{
    std::cout << "|";
    displayString(std::to_string(index));
    displayString(firstName);
    displayString(lastName);
    displayString(nickname);
    std::cout << std::endl;
}

void Contact::display(int index)
{
    std::cout << "Contact Index: " << index << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
