#include <iostream>
#include "../includes/Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
	const std::string& phoneNumber, const std::string& darkestSecret) : _firstName(firstName), _lastName(lastName),
	_nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {}

Contact::~Contact(void) {}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

void	Contact::setFirstName(const std::string& firstName) {
	if (!firstName.empty())
		this->_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName) {
	if (!lastName.empty())
		this->_lastName = lastName;
}

void	Contact::setNickname(const std::string& nickname) {
	if (!nickname.empty())
		this->_nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber) {
	if (!phoneNumber.empty())
		this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret) {
	if (!darkestSecret.empty())
		this->_darkestSecret = darkestSecret;
}
