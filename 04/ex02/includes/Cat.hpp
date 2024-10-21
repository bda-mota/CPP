#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal {

public:

	Cat();
	Cat( const Cat& other);
	Cat& operator=( const Cat& other);
	~Cat();

	void	makeSound( void ) const;
	Brain*	getBrain() const;

private:

	Brain* _brain;

};

#endif