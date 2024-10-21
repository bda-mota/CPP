#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "Default AAnimal Constructor Called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(std::string type) {
	std::cout << "AAnimal Constructor Called" << std::endl;
	this->_type = type;
}

AAnimal::~AAnimal() {
	std::cout << "Default AAnimal Destructor Called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& other ) {
	std::cout << "Default AAnimal Copy Constructor Called" << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=( const AAnimal& other ) {
	std::cout << "AAnimal Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

std::string	AAnimal::getType( void ) const { return this->_type; }
