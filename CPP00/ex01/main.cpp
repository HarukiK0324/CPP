#include "PhoneBook.h"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (command == "ADD")
        {
            Contact newContact;
            phoneBook.addContact(newContact.create());
        }
        else if(command == "SEARCH")
        {
            int index;
            std::cout << "Enter index to search: ";
            std::cin >> index;
            std::cin.ignore(); // Clear the newline character
            phoneBook.searchContact(index);
        }
        else if(command == "EXIT")
            break;
    }
    return 0;
}
