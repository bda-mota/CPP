#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog Constructor Called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Default Dog Destructor Called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other) {
	std::cout << "Default Dog Copy Constructor Called" << std::endl;
	*this = other;
}

Dog& Dog::operator=( const Dog& other ) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "au au" << std::endl;
}