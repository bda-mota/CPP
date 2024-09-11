#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/Defines.hpp"

/* - - - - UTILS - - - - */
namespace utilsPhoneBook {

	void	clearBuffer(void) {
		if (std::cin.eof()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "EOF detected and input stream cleared." << std::endl;
		}
	}

	bool	validateIndex(std::string& index) {
		if (index.empty()) {
			std::cerr << RED << "Index cannot be empty!" << RESET << std::endl;
			return false;
		}
		else if (index.length() > 1) {
			std::cerr << RED << "Index must be a single digit!" << RESET << std::endl;
			return false ;
		}
		else if (!std::isdigit(index[0])) {
			std::cerr << RED << "Index must be a digit!" << RESET << std::endl;
			return false;
		}
		else if (index[0] == '0' || index[0] == '9') {
			std::cerr << RED << "Index invalid! (allowed 1 to 8)" << RESET << std::endl;
			return false;
		}
		return true;
	}

	bool	validateInputs(std::string& input) {
		int	i = 0;

		if (input.empty())
			return false;
		while (input[i])
		{
			if (!isalpha(input[i]))
				return false;
			i++;
		}
		return true;
	}

	bool	validatePhoneNumber(std::string& number) {
		int	i = 0;

		if (number.empty())
			return false;
		if (number.length() < 8 || number.length() > 11)
			return false;
		while (number[i])
		{
			if (!isdigit(number[i]))
				return false;
			i++;
		}
		return true;
	}

	int	convertIndex(const std::string& index) {
		int			convertedIndex;
		const char	*str;

		str = index.c_str();
		convertedIndex = atoi(str);
		return convertedIndex;
	}

	void	printHeader() {
		std::cout << MAGENT << "-------------------------------------------" << std::endl;
		std::cout << "  INDEX:  | F_NAME:  | L_NAME:  | NICKNAME:"<< RESET << std::endl;
		return ;
	}

	void	printFooter() {
		std::cout << MAGENT "-------------------------------------------" << std::endl;
		return ;
	}

	void	printContact(Contact* _contact, int index) {
		index--;

		if (_contact[index].getFirstName().empty()) {
			std::cout << RED << "There's no contact with this index." << RESET << std::endl;
			return;
		}
		std::cout << MAGENT << "First Name: " << RESET << _contact[index].getFirstName() << std::endl;
		std::cout << MAGENT << "Last Name: " << RESET << _contact[index].getLastName() << std::endl;
		std::cout << MAGENT << "Nickname: " << RESET << _contact[index].getNickname() << std::endl;
		std::cout << MAGENT << "Phone Number: " << RESET << _contact[index].getPhoneNumber() << std::endl;
		std::cout << MAGENT << "Darkest Secret: " << RESET << _contact[index].getDarkestSecret() << std::endl;
	}

	void	printTable(int contactsNbr, Contact *_contacts)
	{
		std::string	first;
		std::string	last;
		std::string	nick;

		int	contactsToPrint = (contactsNbr < 8) ? contactsNbr : 8;

		for (int i = 0; i < contactsToPrint; i++) {

			first = _contacts[i].getFirstName();
			if (first.length() > 10)
				first = first.substr(0, 9) + ".";

			last = _contacts[i].getLastName();
			if (last.length() > 10)
				last = last.substr(0, 9) + ".";

			nick = _contacts[i].getNickname();
			if (nick.length() > 10)
				nick = nick.substr(0, 9) + ".";

			std::cout << std::setw(10) << i + 1 << "|";
			std::cout << std::setw(10) << first << "|";
			std::cout << std::setw(10) << last << "|";
			std::cout << std::setw(10) << nick << std::endl;
		}
	}
}

/* - - - - CLASS METHODS - - - - */

PhoneBook::PhoneBook(void) :  _contactCount(0) {}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::searchContact() {

	if (_contactCount == 0) {
		std::cerr << RED << "No contacts available!" << RESET << std::endl;
		return ;
	}

	utilsPhoneBook::printHeader();
	utilsPhoneBook::printTable(_contactCount, _contacts);
	utilsPhoneBook::printFooter();

	std::string	contactIndex;

	std::cout << MAGENT << "Enter index contact: " << RESET;
	std::getline(std::cin, contactIndex);
	while (true) {
		if (utilsPhoneBook::validateIndex(contactIndex))
		{
			utilsPhoneBook::printContact(_contacts, utilsPhoneBook::convertIndex(contactIndex));
			break ;
		}
		else
		{
			std::cout << MAGENT << "Enter index contact: " << RESET;
			std::getline(std::cin, contactIndex);
		}
	}
	return ;
}

void	PhoneBook::addContact() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << MAGENT << " - - - - - - - - - - - - - - " << std::endl;
	std::cout << "|         Add Contact        |" << std::endl;
	std::cout << " - - - - - - - - - - - - - - " << RESET << std::endl;

	std::cout << MAGENT << "Enter First Name: " << RESET;
	std::getline(std::cin, firstName);
	while (true){
		if (!utilsPhoneBook::validateInputs(firstName))
			std::cerr << RED << "First name invalid." RESET << std::endl;
		else
			break ;
		std::cout << MAGENT << "Enter First Name: " << RESET;
		std::getline(std::cin, firstName);
	}

	std::cout << MAGENT <<"Enter Last Name: " << RESET;
	std::getline(std::cin, lastName);
	while (true) {
		if (!utilsPhoneBook::validateInputs(lastName))
			std::cerr << RED << "Last name invalid." RESET << std::endl;
		else
			break ;
		std::cout << MAGENT <<"Enter Last Name: " << RESET;
		std::getline(std::cin, lastName);
	}

	std::cout << MAGENT << "Enter Nickname: " << RESET;
	std::getline(std::cin, nickname);
	while (true) {
		if (!utilsPhoneBook::validateInputs(nickname))
			std::cerr << RED << "Nickname invalid." RESET << std::endl;
		else
			break ;
		std::cout << MAGENT << "Enter Nickname: " << RESET;
		std::getline(std::cin, nickname);
	}

	std::cout << MAGENT << "Enter Phone Number: " << RESET;
	std::getline(std::cin, phoneNumber);
	while (true) {
		if (!utilsPhoneBook::validatePhoneNumber(phoneNumber))
			std::cerr << RED << "Invalid phone number." << RESET << std::endl;
		else
			break ;
		std::cout << MAGENT << "Enter Phone Number: " << RESET;
		std::getline(std::cin, phoneNumber);
	}

	std::cout << MAGENT << "Enter Darkest Secret: " << RESET;
	std::getline(std::cin, darkestSecret);
	while (true) {
		if (!utilsPhoneBook::validateInputs(darkestSecret))
			std::cerr << RED << "Darkest secret invalid." RESET << std::endl;
		else
			break ;
		std::cout << MAGENT << "Enter Darkest Secret: " << RESET;
		std::getline(std::cin, darkestSecret);
	}

	int	index = _contactCount % 8;
	this->_contacts[index].setFirstName(firstName);
	this->_contacts[index].setLastName(lastName);
	this->_contacts[index].setNickname(nickname);
	this->_contacts[index].setPhoneNumber(phoneNumber);
	this->_contacts[index].setDarkestSecret(darkestSecret);

	_contactCount++;

	std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
	return ;
}

void	PhoneBook::exit(void) {
	std::cout << CYAN << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
	return ;
}
