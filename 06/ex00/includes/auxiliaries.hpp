#ifndef AUXILIARIES_HPP
# define AUXILIARIES_HPP

# include "ScalarConverter.hpp"

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN,
	NON_DISP,
	PSEUDOLITERAL
};

Type	identifyType(std::string data);
void	convertAndPrint(Type type, std::string data);
void	charactersRange(double c);
void	intsRange(int nbrI, double nbrD);
void	floatsRange(float nbrI, double nbrD);


#endif
