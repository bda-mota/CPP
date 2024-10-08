#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

// Colors
# define GREEN	"\033[92m"
# define RED		"\033[91m"
# define CYAN		"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE		"\033[94m"
# define MAGENT	"\033[95m"
# define RESET		"\033[0m"

class	Zombie {

public:

	Zombie(std::string name);
	~Zombie();

	void		announce( void );
	std::string	getName() const;

private:

	std::string	_name;

};

	void	randomChump( std::string name );
	Zombie*	newZombie( std::string name );

#endif
