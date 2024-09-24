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
		std::cout << YELLOW << " -- Test 1: Sum -- \n" << RESET << std::endl;
		Fixed a = 10;
		Fixed const b( Fixed( 5.05f ) + Fixed( 15 ) );
		std::cout << GREEN << " * * * b received 5.05f + 15 * * * " << std::endl;
		std::cout << CYAN << "value of a in fixed-point: " << RESET << a.getRawBits() << std::endl;
		std::cout << CYAN << "value of b in fixed-point: " << RESET << b.getRawBits() << std::endl;
		std::cout << CYAN << "value of a as integer: " << RESET << a.toInt() << std::endl;
		std::cout << CYAN << "value of b as integer: " << RESET << b.toInt() << std::endl;
		std::cout << CYAN << "value of a as float: " << RESET << a.toFloat() << std::endl;
		std::cout << CYAN << "value of b as float: " << RESET << b.toFloat() << std::endl;
		std::cout << MAGENT << " * * * Min and Max * * * " << std::endl;
		std::cout << CYAN << "Max: " << RESET << Fixed::max( a, b ) << std::endl;
		std::cout << CYAN << "Min: " << RESET << Fixed::min( a, b ) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << " -- Test 2: Mult -- \n" << RESET << std::endl;
		Fixed a = 10;
		Fixed const b( Fixed( 5.05f ) * Fixed( 3 ) );
		std::cout << GREEN << " * * * b received 5.05f * 3 * * * " << std::endl;
		std::cout << CYAN << "value of a in fixed-point: " << RESET << a.getRawBits() << std::endl;
		std::cout << CYAN << "value of b in fixed-point: " << RESET << b.getRawBits() << std::endl;
		std::cout << CYAN << "value of a as integer: " << RESET << a.toInt() << std::endl;
		std::cout << CYAN << "value of b as integer: " << RESET << b.toInt() << std::endl;
		std::cout << CYAN << "value of a as float: " << RESET << a.toFloat() << std::endl;
		std::cout << CYAN << "value of b as float: " << RESET << b.toFloat() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << " -- Test 3: Conditional Operators -- \n" << RESET << std::endl;
		Fixed	a(6);
		Fixed	b(Fixed(4) + Fixed(2));

		if (a != b)
			std::cout << CYAN << "Different | a: " << RESET << a << " and b: " << b << std::endl;
		else if (a == b)
			std::cout << CYAN << "Equals | a: " << RESET << a << " and b: " << b << std::endl;
		a = (Fixed(a) * Fixed(10));
		if (a > b)
			std::cout << CYAN << "A is greater than B |" << RESET << " a: "  << a << " and b: " << b << std::endl;
		else if (a < b)
			std::cout << CYAN << "B is greater than A |" << RESET << " a: "  << a << " and b: " << b << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW << " -- Test 4: Values -- \n" << RESET << std::endl;
		Fixed a = 10;
		Fixed b = 5.56f;
		std::cout << CYAN << "value of a in fixed-point: " << RESET << a.getRawBits() << std::endl;
		std::cout << CYAN << "value of b in fixed-point: " << RESET << b.getRawBits() << std::endl;
		std::cout << CYAN << "value of a as integer: " << RESET << a.toInt() << std::endl;
		std::cout << CYAN << "value of b as integer: " << RESET << b.toInt() << std::endl;
		std::cout << CYAN << "value of a as float: " << RESET << a.toFloat() << std::endl;
		std::cout << CYAN << "value of b as float: " << RESET << b.toFloat() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
