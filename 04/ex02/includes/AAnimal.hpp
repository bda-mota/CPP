#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	AAnimal {

public:

	AAnimal();
	AAnimal(std::string type);
	AAnimal( const AAnimal& other);
	AAnimal& operator=( const AAnimal& other);
	virtual ~AAnimal();

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;

protected:

	std::string	_type;

};

#endif