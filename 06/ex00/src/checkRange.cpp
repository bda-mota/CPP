#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

void	charactersRange(double nbr) {
	if (!isalpha(static_cast<char>(nbr))) {
		std::cout << "char: impossible" << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	}
}

//void	intsRange() {
//	//checar se e possivel
//	//imprimir
//}

//void	FloatsRange() {
//	//checar se e possivel
//	//imprimir
//}