#include "../includes/RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

// METHODS
void	RPN::run(std::string expression) {
	if (!isValidInput(expression)) {
		throw InvalidExpression();
	}
}

bool	RPN::isValidInput(std::string expression) {
	std::string str;
	std::istringstream iss(expression);

	while (iss >> str) {
		if (!isOperator(str) && !isValidNumber(str)) {
			return false;
		}
	}
	return true;
}

// EXCEPTIONS
const char* RPN::InvalidExpression::what() const throw() {
	return "invalid expression.";
}

// AUXILIARIES

bool	isOperator(std::string slice) {
	return (slice == "+" || slice == "-" || slice == "*" || slice == "/");
}

bool	isValidNumber(std::string slice) {
	int	nbr;
	std::istringstream iss(slice);

	iss >> nbr;
	if (iss.fail() || !iss.eof()) {
		return false;
	}
	if (nbr < 0 || nbr > 9) {
		return false;
	}
	return true;
}