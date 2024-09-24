#include "../includes/Fixed.hpp"

int main( void ) {
	{
		std::cout << YELLOW << " -- Test subject: -- \n" << RESET << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << " -- Test 1: -- \n" << RESET << std::endl;
		Fixed a = 10;
		Fixed const b( Fixed( 5.05f ) * Fixed( 5 ) );
		std::cout << GREEN << "value of a in fixed-point: " << a.getRawBits() << RESET << std::endl;
		std::cout << GREEN << "value of b in fixed-point: " << b.getRawBits() << RESET << std::endl;
		std::cout << GREEN << "value of a as integer: " << a.toInt() << RESET << std::endl;
		std::cout << GREEN << "value of b as integer: " << b.toInt() << RESET << std::endl;
		std::cout << GREEN << "value of a as float: " << a.toFloat() << RESET << std::endl;
		std::cout << GREEN << "value of b as float: " << b.toFloat() << RESET << std::endl;
		std::cout << MAGENT << " * * * Min and Max * * * " << std::endl;
		std::cout << CYAN << "Max: " << RESET << Fixed::max( a, b ) << std::endl;
		std::cout << CYAN << "Min: " << RESET << Fixed::min( a, b ) << std::endl;
		std::cout << MAGENT << " * * * Operations * * * " << std::endl;
		std::cout << CYAN << "Sum: " << RESET << a.operator+(b) << std::endl;
		std::cout << CYAN << "Sub: " << RESET << a.operator-(b)<< std::endl;
		std::cout << CYAN << "Mult: " << RESET << a.operator*(b) << std::endl;
		std::cout << CYAN << "Div: " << RESET << a.operator/(b) << std::endl;

		std::cout << std::endl;
	}
	return 0;
}