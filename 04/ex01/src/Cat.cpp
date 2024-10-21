#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat Constructor Called" << std::endl;
	_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Default Cat Destructor Called" << std::endl;
	delete _brain;
}

Cat::Cat( const Cat& other ) : Animal(other) {
	std::cout << "Default Cat Copy Constructor Called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=( const Cat& other ) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Cat::makeSound( void ) const { std::cout << "miau" << std::endl; }

Brain*	Cat::getBrain() const { return _brain; }