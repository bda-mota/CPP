#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

void	charactersRange(double nbr) {
	if (!isalpha(static_cast<char>(nbr))) {
		std::cout << "char: out of limits, impossible convert to char." << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	}
}

void	intsRange(int nbr, double doubleNbr) {
	if (doubleNbr < std::numeric_limits<int>::min() && doubleNbr > std::numeric_limits<int>::max()) {
		std::cout << "int: out of limits, impossible convert to int." << std::endl;
	} else {
		std::cout << "int: " << nbr << std::endl;
	}
}

void	floatsRange(float nbr, double doubleNbr) {
	if (doubleNbr < std::numeric_limits<float>::min() && doubleNbr > std::numeric_limits<float>::max()) {
		std::cout << "float: out of limits, impossible convert to double." << std::endl;
	} else {
		std::cout << "float: " << nbr << std::endl;
	}
}
