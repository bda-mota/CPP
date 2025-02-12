#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>
# include <deque>

# define CYAN	"\033[96m"
# define MAGENT	"\033[95m"
# define RESET   "\033[0m"

template <typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack(void);
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack(void);

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void);
	iterator end(void);
};

# include "MutantStack.tpp"

#endif