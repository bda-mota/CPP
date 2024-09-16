#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& typeWeapon) : _name(name), _weapon(typeWeapon) {}

HumanA::~HumanA() {};

void	HumanA::attack() {
	std::cout << MAGENT << _name << RESET << " attacks with their " << CYAN << _weapon.getType() << RESET << std::endl;
}
