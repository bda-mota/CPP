#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal Constructor Called" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "WrongAnimal Constructor Called" << std::endl;
	this->_type = type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Default WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
	std::cout << "Default WrongAnimal Copy Constructor Called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

std::string	WrongAnimal::getType( void ) const { return this->_type; }

void	WrongAnimal::makeSound( void ) const {
	std::cout << "¨%*&#*" << std::endl;
}