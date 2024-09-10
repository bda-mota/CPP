#include <iostream>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/Defines.hpp"

PhoneBook::PhoneBook(void) :  _contactCount(0) {
	std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor Called" << std::endl;
	return ;
}

void	PhoneBook::searchContact() {
	if ( _contactCount == 0) {
		std::cerr << RED "No contacts available!" << std::endl;
		return;
	}

	int	contactsToPrint = (_contactCount < 8) ? _contactCount : 8;

	for (int i = 0; i < contactsToPrint; i++) {
		int index = (_contactCount < 8) ? i : (_contactCount + i) % 8; 
		std::cout << "Contact " << i + 1 << std::endl;
		std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}
}


void	PhoneBook::addContact() {
	std::string firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	if (firstName.empty()) {
		std::cerr << RED "First name cannot be empty!" RESET << std::endl;
		return;
	}

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	if (lastName.empty()) {
		std::cerr << RED "Last name cannot be empty!" RESET << std::endl;
		return;
	}

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty()) {
		std::cerr << RED "Nickname cannot be empty!" RESET << std::endl;
		return;
	}

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty()) {
		std::cerr << RED "Phone number cannot be empty!" RESET << std::endl;
		return;
	}

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty()) {
		std::cerr << RED "Darkest secret cannot be empty!" RESET << std::endl;
		return;
	}
	
	int	index = _contactCount % 8;
	this->_contacts[index].setFirstName(firstName);
	this->_contacts[index].setLastName(lastName);
	this->_contacts[index].setNickname(nickname);
	this->_contacts[index].setPhoneNumber(phoneNumber);
	this->_contacts[index].setDarkestSecret(darkestSecret);

	_contactCount++;

	std::cout << GREEN "Contact added successfully!" RESET << std::endl;
}