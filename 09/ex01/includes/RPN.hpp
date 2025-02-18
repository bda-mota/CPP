#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>

class RPN {

private:
	std::stack<int>	_stack;

public:
	RPN(void);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void	run(std::string expression);
	bool	isValidInput(std::string str);


	class InvalidExpression : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

bool	isOperator(std::string slice);
bool	isValidNumber(std::string slice);
int		applyOperation(int a, int b, char op);

#endif