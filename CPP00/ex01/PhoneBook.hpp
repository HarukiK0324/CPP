#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

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