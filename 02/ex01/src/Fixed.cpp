#include "../includes/Fixed.hpp"

Fixed::Fixed ( void ) : _fixedNumberValue(0) { std::cout << "Default constructor called" << std::endl; };

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

Fixed::~Fixed( void ) { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed( const int intFixedNumber ) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNumberValue = intFixedNumber << _fractionalBits;
}

Fixed::Fixed( const float floatFixedNumber ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNumberValue = static_cast<int>(roundf(floatFixedNumber * (1 << _fractionalBits)));
}

int	Fixed::getRawBits( void ) const { return _fixedNumberValue; }

void	Fixed::setRawBits( int const raw ) { _fixedNumberValue = raw; }

float	Fixed::toFloat( void ) const {
	return static_cast<float>(_fixedNumberValue) / (1 << _fractionalBits);
}

int	Fixed::toInt ( void ) const {
	return _fixedNumberValue >> _fractionalBits; 
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}