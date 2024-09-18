#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

// Colors
# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	Zombie {

public:

	Zombie();
	Zombie(std::string name);
	~Zombie();

	std::string	getName() const;
	void		announce( void );
	void		setName(std::string name);

private:

	std::string	_name;

};

	Zombie*	zombieHorde( int N, std::string name );

#endif
