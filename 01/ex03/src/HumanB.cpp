#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string& name) {
	this->_name = name;
	this->_weapon = NULL;
};

HumanB::~HumanB() { std::cout << RED << "Destructor HumanB called " << RESET << std::endl; }

void	HumanB::setWeapon(Weapon& typeWeapon) { _weapon = &typeWeapon; }

void	HumanB::attack() {
	std::cout << MAGENT << _name << RESET << " attacks with ";

	if (_weapon)
		std::cout << "their " << CYAN << _weapon->getType() << "." << RESET << std::endl;
	else
		std::cout << CYAN << "own fists." << RESET << std::endl;
}
