#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

void	charactersRange(double nbr) {
	if ((nbr >= 0 && nbr <= 31 ) || nbr == 127) {
		std::cout << "char: non displayable" << std::endl;
	} else if (!isalpha(static_cast<char>(nbr))) {
		std::cout << "char: impossible" << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	}
}

void	intsRange(int nbr, double doubleNbr) {
	if (doubleNbr < std::numeric_limits<int>::min() && doubleNbr > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible " << std::endl;
	} else {
		std::cout << "int: " << nbr << std::endl;
	}
}

void	floatsRange(float nbr, double doubleNbr) {
	if ((doubleNbr < std::numeric_limits<float>::min() && doubleNbr > std::numeric_limits<float>::max())
	|| doubleNbr == 0) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << nbr << "f"  << std::endl;
	}
}

void	doublesRange(double doubleNbr) {
	if ((doubleNbr < std::numeric_limits<double>::min() && doubleNbr > std::numeric_limits<double>::max())
	|| doubleNbr == 0) {
		std::cout << "double: impossible " << std::endl;
	}
	else {
		std::cout << "double: " << doubleNbr << std::endl;
	}
}

