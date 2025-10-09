#include "PhoneBook.h"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, command))
        {
            std::cout << "\nEOF detected, exiting program" << std::endl;
            break;
        }
        if (command == "ADD")
        {
            command.clear();
            phoneBook.addContact(Contact::create());
        }
        else if(command == "SEARCH")
        {
            command.clear();
            phoneBook.searchContact();
        }
        else if(command == "EXIT")
            break;
    }
    return 0;
}
