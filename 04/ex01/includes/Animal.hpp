#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	Animal {

public:

	Animal();
	Animal(std::string type);
	Animal( const Animal& other);
	Animal& operator=( const Animal& other);
	virtual ~Animal();

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;

protected:

	std::string	_type;

};

#endif