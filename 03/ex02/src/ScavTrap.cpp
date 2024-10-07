#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	_name = "scavtrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called | " << this->_name << " hit points: " << this->_hitPoints << ", energy points: "
	<< this->_energyPoints << ", attack damage: " << this->_attackDamage << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called | " << this->_name << " hit points: " << this->_hitPoints << ", energy points: "
	<< this->_energyPoints << ", attack damage: " << this->_attackDamage << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0) {
		std::cout << MAGENT << "ScavTrap " << RESET << this->_name << " has no energy to attack " << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0) {
		std::cout << MAGENT << "ScavTrap " << RESET << this->_name << " is died and can't attack " << std::endl;
		return ;
	}
	std::cout << MAGENT << "ScavTrap " << RESET << this->_name << RED <<" attacks " << RESET << target << ", causing "
	<< this->_attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate( void ) {
	if (_hitPoints > 0)
		std::cout << MAGENT << "ScavTrap " << RESET << this->_name << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << RED << "ScavTrap " << RESET << this->_name << " is died and can't be in Gate keeper mode" << std::endl;
}

