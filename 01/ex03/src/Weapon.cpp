#include "../includes/Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon(std::string type) { this->_type = type; }

Weapon::~Weapon() { std::cout << RED << "Destructor Weapon called " << RESET << std::endl; }

const std::string&	Weapon::getType() const { return _type; }

void	Weapon::setType(std::string type) { this->_type = type; }
