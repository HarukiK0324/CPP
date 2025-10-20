#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	void getInput(std::string &field, std::string prompt);
	void getNumberInput(std::string &field, std::string prompt);
	void displayNumber(int index);
	void displayString(std::string str);

  public:
	Contact();
	static Contact create();
	void displaySimple(int index);
	void display(int index);
	bool isValid(const Contact &contact);
};

#endif