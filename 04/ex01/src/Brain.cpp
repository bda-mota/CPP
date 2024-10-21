#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Default Brain Constructor Called" << std::endl;
	 for (int i = 0; i < 100; ++i) {
        _ideas[i] = "";
    }
}

Brain::~Brain() {
	std::cout << "Default Brain Destructor Called" << std::endl;
}

Brain::Brain( const Brain& other ) {
	std::cout << "Default Brain Copy Constructor Called" << std::endl;
	*this = other;
}

Brain& Brain::operator=( const Brain& other ) {
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100 ; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

void		Brain::setBrain(std::string newIdea, unsigned int index) {
	if (index < 100) {
		_ideas[index] = newIdea;
	} else {
		std::cout << "Index out of range ( 0 - 100 )" << std::endl;
	}
}

std::string	Brain::getBrain( unsigned int index ) const {
	if (index < 100) {
		return _ideas[index];
	} else {
		return ("Nothing here");
	}
}
