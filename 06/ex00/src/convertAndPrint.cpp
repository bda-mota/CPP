#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

void	convertAndPrint(Type type, std::string data) {
	switch (type) {
		case CHAR:
			printChar(data);
			break;
		case INT:
			printInt(data);
			break;
		//case FLOAT:
		//	printFloat(data);
		//	break;
		//case DOUBLE:
		//	printDouble(data);
		//	break;
		//case PSEUDOLITERAL:
		//	printPseudoLiteral(data);
		//	break;
		//case UNKNOWN:
		//	printUnknown(data);
	}
	
}

static void	printChar(std::string data) {
	char c = data[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	printInt(std::string data) {
	int nbr;
	std::istringstream iss(data);

	iss >> nbr;
	
	charactersRange(static_cast<double>(nbr));
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

