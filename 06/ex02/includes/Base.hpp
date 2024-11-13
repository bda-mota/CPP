#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <stdexcept>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	Base {

public:

	virtual ~Base( void );

};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif