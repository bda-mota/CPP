#include "../includes/Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	newHarl;
	
	switch (argc)
	{
		case 1:
			std::cout << "Missing argument." << std::endl;
			break;
		case 2:
			newHarl.complain(argv[1]);
			break ;
		default:
			std::cout << "Too many arguments." << std::endl;
			break;
	}
}