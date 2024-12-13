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
		case FLOAT:
			printFloat(data);
			break;
		case DOUBLE:
			printDouble(data);
			break;
		case PSEUDOLITERAL:
			printPseudoLiteral(data);
			break;
		case UNKNOWN:
			std::cout << "impossible to convert to any type." << std::endl;
	}
	
}

void	printChar(std::string data) {
	char c = data[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	printInt(std::string data) {
	int nbr;
	std::istringstream iss(data);

	iss >> nbr;
	
	charactersRange(static_cast<double>(nbr));
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void	printFloat(std::string data) {
	float nbr;
	std::istringstream iss(data);

	iss >> nbr;
	charactersRange(static_cast<double>(nbr));
	intsRange(static_cast<int>(nbr), static_cast<double>(nbr));
	floatsRange(static_cast<float>(nbr), static_cast<double>(nbr));
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void	printDouble(std::string data) {
	float nbr;
	std::istringstream iss(data);

	iss >> nbr;
	charactersRange(static_cast<double>(nbr));
	intsRange(static_cast<int>(nbr), static_cast<double>(nbr));
	floatsRange(static_cast<float>(nbr), static_cast<double>(nbr));
	std::cout << "double: " << nbr << std::endl;
}

void printPseudoLiteral(std::string input) {
    std::cout << "char: off limits, impossible to convert to char." << std::endl;
    std::cout << "int: off limits, impossible to convert to int." << std::endl;
    
    if (input == "+inff" || input == "+inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (input == "-inff" || input == "-inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}