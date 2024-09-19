#include <iostream>
#define GREEN	"\033[92m"
#define RED		"\033[91m"
#define CYAN	"\033[96m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[94m"
#define MAGENT	"\033[95m"
#define RESET	"\033[0m"

int	main(void)
{
	std::string	strBrain = "HI THIS IS BRAIN";

	std::string*	stringPTR = &strBrain;
	std::string&	stringREF = strBrain;

	std::cout << YELLOW << "\n--- Test: addresses ---\n\n" << RESET;
	std::cout << MAGENT << "Adress of strBrain: " << RESET << &strBrain << std::endl;
	std::cout << MAGENT << "Adress held by stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << MAGENT << "Adress held by stringREF: " << RESET << &stringREF << std::endl;

	std::cout << YELLOW << "\n--- Test: values ---\n\n" << RESET;
	std::cout << MAGENT << "Value of strBrain: " << RESET << strBrain << std::endl;
	std::cout << MAGENT << "Value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << MAGENT << "Value pointed to by stringREF: " << RESET << stringREF << std::endl;

	std::cout << YELLOW << "\n--- Test: Modifying values ---\n\n" << RESET;

	std::cout << MAGENT "string before modified *strPTR: " RESET << strBrain << std::endl;
	*stringPTR = "Hi! Value changed with *strPTR";
	std::cout << MAGENT"string after dereferencing: " RESET << strBrain << std::endl;
	std::cout << MAGENT "string before modified string REF: " RESET << strBrain << std::endl;
	stringREF = "Hi! Value changed with strREF";
	std::cout << MAGENT "string after modified string REF: " RESET << strBrain << std::endl;

	std::cout << std::endl;

	return (0);
}
