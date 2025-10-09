#include "PhoneBook.h"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    Contact newContact;
    
    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if(std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            break;
        }
        if (command == "ADD")
        {
            command.clear();
            phoneBook.addContact(newContact.create());
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
