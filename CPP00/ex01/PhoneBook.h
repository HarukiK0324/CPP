#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        
    public:
        Contact();
        Contact create();
        void display(int index);
        
    private:
        void getInput(std::string &field, std::string prompt);
        void displayString(std::string str);
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
        
    public:
        PhoneBook();
        void addContact(Contact contact);
        void searchContact(int index);
};

#endif