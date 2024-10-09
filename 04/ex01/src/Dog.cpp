#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog Constructor Called" << std::endl;
	_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Default Dog Destructor Called" << std::endl;
	delete _brain;
}

Dog::Dog( const Dog& other ) : Animal(other) {
	std::cout << "Default Dog Copy Constructor Called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=( const Dog& other ) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "au au" << std::endl;
}