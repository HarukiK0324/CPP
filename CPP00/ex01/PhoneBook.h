#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
        
    public:
        PhoneBook();
        void addContact(Contact contact);
        void displayContacts();
        void searchContact();
        
};

#endif