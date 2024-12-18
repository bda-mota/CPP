#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {};

void	ScalarConverter::convert(std::string const& data) {
	std::string input;

	size_t start = data.find_first_not_of(" \t");
	size_t end = data.find_last_not_of(" \t");

	if (start != std::string::npos && end != std::string::npos) {
		input = data.substr(start, end - start + 1);
	} else if (start != std::string::npos) {
		input = data.substr(start);
	} else if (end != std::string::npos) {
		input = data.substr(0, end + 1);
	} else {
		input = "";
	}

	Type type = identifyType(input);
	convertAndPrint(type, input);
}
