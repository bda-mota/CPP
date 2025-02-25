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

	std::string str;
	std::istringstream iss(expression);
	while (iss >> str) {
		if (isValidNumber(str)) {
			_stack.push(std::atof(str.c_str()));
		} else if (isOperator(str)) {
			if (_stack.size() < 2) {
				throw InvalidExpression();
			}
			float a = _stack.top();
			_stack.pop();
			float b = _stack.top();
			_stack.pop();
			_stack.push(calculator(b, a, str[0]));
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Invalid expression.");
	}
	std::cout << _stack.top() << std::endl;
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

float	RPN::calculator(float a, float b, const char op) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0) {
				throw std::invalid_argument("division by zero.");
			}
			return a / b;
		default:
			throw std::invalid_argument("invalid operator.");
	}
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