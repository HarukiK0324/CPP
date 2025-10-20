#include "PhoneBook.h"

PhoneBook::PhoneBook() : count(0)
{
}

void PhoneBook::addContact(Contact contact)
{
	if (!contact.isValid(contact))
		return ;
	if (count < 8)
	{
		contacts[count] = contact;
		count++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = contact;
	}
}

void PhoneBook::displayContacts()
{
	std::cout << "|" << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << "First Name";
	std::cout << "|" << std::setw(10) << std::right << "Last Name";
	std::cout << "|" << std::setw(10) << std::right << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (int i = 0; i < count; i++)
	{
		contacts[i].displaySimple(i);
	}
}

void PhoneBook::searchContact()
{
	int	index;

	std::string input;
	if (count == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	displayContacts();
	std::cout << "Enter index to search: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << "\nEOF detected, exiting search" << std::endl;
		std::exit(0);
		return ;
	}
	try
	{
		index = std::atoi(input.c_str());
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid input." << std::endl;
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (index < 0 || index >= count)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	contacts[index].display(index);
}
