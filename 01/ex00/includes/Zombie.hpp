#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

//includes

// Colors
# define GREEN	"\033[32;1m"
# define RED	"\033[31;1m"
# define CYAN	"\033[36;1m"
# define BOLD	"\033[37;1;4m"
# define WHITE	"\033[37;1m"
# define YELLOW	"\033[33;1m"
# define BLUE	"\033[34;1m"
# define MAGENT	"\033[35;1m"
# define RESET	"\033[0m"

class	Zombie {

public:

	Zombie();
	~Zombie();

	void	announce( void );
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );

private:

	std::string	_name;
};

#endif