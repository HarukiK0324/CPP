#include <iostream>
#include <sys/ioctl.h>
#include <iomanip>

class PhoneBook
{
    private:
        Contract contracts[8];
        int count;
    public:
        void addContract(Contract contract)
        {
            if(count < 8)
            {
                contracts[count] = contract;
                count++;
            }
            else
            {
                for(int i = 0; i < 7; i++)
                    contracts[i] = contracts[i + 1];
                contracts[7] = contract;
            }
        }
        void searchContract(int index)
        {
            if (index < 0 || index >= count)
            {
                std::cout << "Invalid index." << std::endl;
                return;
            }
            contracts[index].display(index);
        }
    
};

class Contract
{
    private:
        std::string firstName = "";
        std::string lastName = "";
        std::string nickname = "";
        std::string phoneNumber = "";
        std::string darkestSecret = "";

        void getInput(std::string &field, std::string input)
        {
            std::cout << input;
            std::getline(std::cin, field);
            if(field.empty())
                std::cout << "A saved contact can’t have empty fields" << std::endl;
        }
    public:
        Contract create()
        {
            Contract contract;
            while(contract.firstName.empty())
                getInput(contract.firstName, "Enter first name: ");
            while(contract.lastName.empty())
                getInput(contract.lastName, "Enter last name: ");
            while(contract.nickname.empty())
                getInput(contract.nickname, "Enter nickname: ");
            while(contract.phoneNumber.empty())
                getInput(contract.phoneNumber, "Enter phone number: ");
            while(contract.darkestSecret.empty())
                getInput(contract.darkestSecret, "Enter darkest secret: ");
            return contract;
        }
        void display(int index)
        {
            std::cout << "|";
            displayString(std::to_string(index));
            displayString(firstName);
            displayString(lastName);
            displayString(nickname);
            std::cout << std::endl;
        }
};

void displayString(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    std::cout << std::right << std::setw(10) << str << "|";
}

int main()
{
    PhoneBook phoneBook;
    while(1)
    {
        std::string command;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContract(Contract().create());
        else if(command == "SEARCH")
        {
            int index;
            std::cout << "Enter index to search: ";
            std::cin >> index;
            phoneBook.searchContract(index);
        }
        else if(command == "EXIT")
            break;
        else
            continue;
    }
    return 0;
}