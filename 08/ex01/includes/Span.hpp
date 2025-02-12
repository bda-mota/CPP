#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <limits>

# define CYAN	"\033[96m"
# define MAGENT	"\033[95m"
# define RESET   "\033[0m"

class Span {

private:
	unsigned int _size;
	std::vector<int> _numbers;

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span(void);

	void	addNumber(int n);
	int		shortestSpan(void);
	int		longestSpan(void);

	class ContainerIsFullException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class CantCalculateSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};


#endif
