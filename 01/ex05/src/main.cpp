#include "../includes/Harl.hpp"

int	main()
{
	Harl	newHarl;

	std::cout << YELLOW << "\n--- Test: Valid ---\n" << RESET;
	newHarl.complain("DEBUG");
	newHarl.complain("INFO");
	newHarl.complain("WARNING");
	newHarl.complain("ERROR");

	std::cout << YELLOW << "\n--- Test: Invalid ---\n" << RESET;
	newHarl.complain("BACON");
	std::cout << std::endl;
}
