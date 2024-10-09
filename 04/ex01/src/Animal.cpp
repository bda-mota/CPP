#include "../includes/Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal Constructor Called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(std::string type) {
	std::cout << "Animal Constructor Called" << std::endl;
	this->_type = type;
}

Animal::~Animal() {
	std::cout << "Default Animal Destructor Called" << std::endl;
}

Animal::Animal( const Animal& other ) {
	std::cout << "Default Animal Copy Constructor Called" << std::endl;
	*this = other;
}

Animal& Animal::operator=( const Animal& other ) {
	std::cout << "Animal Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

std::string	Animal::getType( void ) const { return this->_type; }

void	Animal::makeSound( void ) const {
	std::cout << "The " << this->_type << " make a sound." << std::endl;
}