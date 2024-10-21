#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal( const WrongAnimal& other);
	WrongAnimal& operator=( const WrongAnimal& other);
	virtual ~WrongAnimal();

	std::string		getType( void ) const;
	void	makeSound( void ) const;

protected:

	std::string	_type;

};

#endif