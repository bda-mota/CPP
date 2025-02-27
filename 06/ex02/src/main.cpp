#include "../includes/Base.hpp"
#include "../includes/functions.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main( void )
{
	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << MAGENT;
	std::cout << "******************* DYNAMIC CAST TEST *******************\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	 for (int i = 0; i < 5; i++)
	 {
		std::cout << CYAN;
		std::cout << "-> TEST " << i + 1 << std::endl;
		std::cout << BLUE;
		std::cout << "---------------------------------------------------------\n";
		std::cout << YELLOW << "Generating random class...\n" << GREEN ;
		Base *base = generate();

		std::cout << YELLOW << "\nIdentifying class with pointer...\n" << GREEN;
		identify(base);

		std::cout << YELLOW << "\nIdentifying class with reference...\n" << GREEN;
		identify(*base);
		std::cout << std::endl;

		delete base;

		std::cout << BLUE;
		std::cout << "---------------------------------------------------------\n";
	}

	std::cout << "-> TEST 6" << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << YELLOW <<"Generating base class..." << GREEN << std::endl;
	Base *base = new Base();

	std::cout << YELLOW << "\nIdentifying class with pointer...\n" << GREEN;
	identify(base);

	std::cout << YELLOW << "\nIdentifying class with reference...\n" << GREEN;
	identify(*base);
	std::cout << std::endl;

	delete base;

	return 0;
}
