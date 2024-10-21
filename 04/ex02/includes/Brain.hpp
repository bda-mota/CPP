#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain {

public:

	Brain();
	Brain( const Brain& other);
	Brain& operator=( const Brain& other);
	~Brain();

	void	setBrain(std::string newIdea, unsigned int index);
	std::string	getBrain( unsigned int index ) const;
	void	printIdeas() const;

private:

	std::string	_ideas[100];

};

#endif