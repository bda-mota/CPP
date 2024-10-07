#include "../includes/Cat.hpp"

Cat::Cat() {
	std::cout << "Default Cat Constructor Called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "Default Cat Destructor Called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other) {
	std::cout << "Default Cat Copy Constructor Called" << std::endl;
	*this = other;
}

Cat& Cat::operator=( const Cat& other ) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	return *this;
}

void	Cat::makeSound( void ) const {
	std::cout << "miau" << std::endl;
}