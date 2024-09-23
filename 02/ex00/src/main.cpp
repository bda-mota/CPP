#include "../includes/Fixed.hpp"

int main( void ) {
	{
		std::cout << YELLOW << " -- Test subject: -- \n" << RESET << std::endl;
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << " -- Test 1 : change derived object after copy  -- \n" << RESET << std::endl;

		Fixed d;
		Fixed e(d);

		std::cout << GREEN << "original object: d" << std::endl;
		std::cout << "derived object: e\n" << RESET << std::endl;

		std::cout << CYAN << "Before d: " << RESET << d.getRawBits() << std::endl;
		std::cout << CYAN << "Before e: " << RESET << e.getRawBits() << std::endl;
		std::cout << MAGENT << " * * * set 'e' to 42 * * * " << RESET << std::endl;
		e.setRawBits(42);
		std::cout << CYAN << "After d: "<< RESET  << d.getRawBits() << std::endl;
		std::cout << CYAN << "After e: " << RESET << e.getRawBits() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << " -- Test 2: change original object after copy -- \n" << RESET << std::endl;

		Fixed f;
		Fixed g(f);

		std::cout << GREEN << "original object: f" << std::endl;
		std::cout << "derived object: g\n" << RESET << std::endl;

		std::cout << CYAN << "Before f: " << RESET << f.getRawBits() << std::endl;
		std::cout << CYAN << "Before g: " << RESET << g.getRawBits() << std::endl;
		std::cout << MAGENT << " * * * set 'f' to 42 * * * " << RESET << std::endl;
		f.setRawBits(42);
		std::cout << CYAN << "After f: " << RESET << f.getRawBits() << std::endl;
		std::cout << CYAN << "After g: " << RESET << g.getRawBits() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << " -- Test 3 : change both objects after copy  -- \n" << RESET << std::endl;

		Fixed h;
		Fixed i(h);

		std::cout << GREEN << "original object: h " << std::endl;
		std::cout << "derived object: i\n" << RESET << std::endl;

		std::cout << CYAN << "Before h: " << RESET << h.getRawBits() << std::endl;
		std::cout << CYAN << "Before i: " << RESET << i.getRawBits() << std::endl;
		std::cout << MAGENT << " * * * set 'h' to 42 * * * " << RESET << std::endl;
		h.setRawBits(42);
		std::cout << MAGENT << " * * * set 'i' to 24 * * * " << RESET << std::endl;
		i.setRawBits(24);
		std::cout << CYAN << "After h: "<< RESET  << h.getRawBits() << std::endl;
		std::cout << CYAN << "After i: " << RESET << i.getRawBits() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}