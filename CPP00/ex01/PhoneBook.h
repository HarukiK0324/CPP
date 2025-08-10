#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>

class Contract
{
    private:
        std::string firstName = "";
        std::string lastName = "";
        std::string nickname = "";
        std::string phoneNumber = "";
        std::string darkestSecret = "";
        void getInput(std::string &field, std::string input);
    public:
        Contract create();
        void display(int index);

};

class PhoneBook
{
    private:
        Contract contracts[8];
        int count;
    public:
        void addContract(Contract contract);
        void searchContract(int index);
};

#endif
