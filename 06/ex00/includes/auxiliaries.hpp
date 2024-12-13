#ifndef AUXILIARIES_HPP
# define AUXILIARIES_HPP

# include "ScalarConverter.hpp"

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN,
	PSEUDOLITERAL
};

Type	identifyType(const std::string& data);
bool	isChar(const std::string& data);
bool	isInt(const std::string& data);
bool	isFloat(const std::string& data);
bool	isDouble(const std::string& data);
bool	isPseudoLiteral(const std::string &input);
void	convertAndPrint(Type type, std::string data);
void	printChar(std::string data);
void	printInt(std::string data);
void	printFloat(std::string data);
void	printDouble(std::string data);
void	printPseudoLiteral(std::string input);
void	charactersRange(double c);
void	intsRange(int nbr, double doubleNbr);
void	floatsRange(float nbr, double doubleNbr);

#endif
