#include "PhoneBook.h"

PhoneBook::PhoneBook() : count(0) {}

void PhoneBook::addContact(Contact contact)
{
    if(count < 8)
    {
        contacts[count] = contact;
        count++;
    }
    else
    {
        for(int i = 0; i < 7; i++)
            contacts[i] = contacts[i + 1];
        contacts[7] = contact;
    }
}

void PhoneBook::searchContact(int index)
{
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    contacts[index].display(index);
}
