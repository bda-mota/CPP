#include "../includes/Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "The Zombie " << GREEN << this->_name << RESET << " was born." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "The zombie " << RED << this->_name << RESET << " was killed." << std::endl;
}

std::string	Zombie::getName() const { return _name; }

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce() {
	std::cout << MAGENT << this->_name << ": " << RESET << "BraiiiiiiinnnzzzZ..." << std::endl;
}
