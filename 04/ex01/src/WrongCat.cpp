#include "../includes/WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("Cat") {
	std::cout << "Default WrongCat Constructor Called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other) {
	std::cout << "Default WrongCat Copy Constructor Called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
	std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "roar" << std::endl;
}