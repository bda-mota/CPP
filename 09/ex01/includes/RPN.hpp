#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>


class RPN {

private:
	std::stack<float>	_stack;

public:
	RPN(void);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void	run(std::string expression);
	bool	isValidInput(std::string str);
	float	calculator(float a, float b, const char op);

	class InvalidExpression : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

bool	isOperator(std::string slice);
bool	isValidNumber(std::string slice);

#endif