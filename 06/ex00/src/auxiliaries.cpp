#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

Type	identifyType(const std::string& data) {
	if (isChar(data)) {
		return CHAR; }
	if (isInt(data)) {
		return INT; }
	if (isFloat(data)) {
		return FLOAT; }
	if (isDouble(data)) {
		return DOUBLE; }
	if (isPseudoLiteral(data)) {
		return PSEUDOLITERAL; }
	return UNKNOWN;
}

static bool	isChar(const std::string& data) {
	return data.length() == 1 && std::isalpha(data[0]);
}

static bool	isInt(const std::string& data) {
	int	intValue;
	std::istringstream iss(data);

	iss >> intValue;
	if (!iss.eof() || iss.fail()) {
		return false;
	}
	return true;
}

static bool	isFloat(const std::string& data) {
	if (data[data.length() - 1] != 'f') {
		return false;
	}

	int dot = 0;
	for (size_t i = 0; i < data.length(); i++) {
		if (data[i] == '.') {
			dot++;
		}
	}

	if (dot != 1) {
		return false;
	}

	int	floatValue;
	std::istringstream iss(data);

	iss >> floatValue;
	if (!iss.eof() || iss.fail()) {
		return false;
	}
	return true;
}


static bool	isDouble(const std::string& data) {
	if (data[data.length() - 1] == 'f') {
		return false; 
	}

	int dot = 0;
	for (size_t i = 0; i < data.length(); i++) {
		if (data[i] == '.') {
			dot++;
		}
	}

	if (dot != 1) {
		return false;
	}

	int	doubleValue;
	std::istringstream iss(data);

	iss >> doubleValue;
	if (!iss.eof() || iss.fail()) {
		return false;
	}
	return true;
}


static bool	isPseudoLiteral(const std::string &input)
{
    if (input == "+inf" || input == "-inf" || input == "nan"
    || input == "+inff" || input == "-inff" || input == "nanf")
        return (true);
    return (false);
}