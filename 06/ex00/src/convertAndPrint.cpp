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
			printImpossible(data);
			break;
	}
	
}

void	printImpossible(std::string data) {
	float tryFloat;
	double tryDouble;

	std::istringstream f(data);
	std::istringstream d(data);

	f >> tryFloat;
	d >> tryDouble;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	floatsRange(static_cast<float>(tryFloat), static_cast<double>(tryFloat));
	doublesRange(static_cast<double>(tryDouble));
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
	double nbr;
	std::istringstream iss(data);

	iss >> nbr;
	charactersRange(static_cast<double>(nbr));
	intsRange(static_cast<int>(nbr), static_cast<double>(nbr));
	floatsRange(static_cast<float>(nbr), static_cast<double>(nbr));
	std::cout << "double: " << nbr << std::endl;
}

void printPseudoLiteral(std::string input) {
    std::cout << "char: impossible " << std::endl;
    std::cout << "int: impossible " << std::endl;
    
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