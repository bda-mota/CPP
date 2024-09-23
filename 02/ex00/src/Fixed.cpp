#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) : _fixedNumberValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {\
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedNumberValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed( void ) { std::cout << "Default destructor called" << std::endl; }

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl; 
	return _fixedNumberValue;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedNumberValue = raw;
}