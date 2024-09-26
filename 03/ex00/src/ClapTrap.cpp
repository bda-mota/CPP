#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = "claptrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "ClapTrap constructor called" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return *this;
}

std::string	ClapTrap::getName() const { return _name; }
int	ClapTrap::getHitPoints() const { return _hitPoints; }
int	ClapTrap::getEnergyPoints() const { return _energyPoints; }
int	ClapTrap::getAttackDamage() const { return _attackDamage; }

void	ClapTrap::attack( const std::string& target ) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << RED <<" attacks " << RESET << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points or hit points to attack " << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << RED << " is died" << RESET << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << YELLOW << " takes " << RESET << amount << " points of damage and now has "
	<< this->_hitPoints << " hit points" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energyPoints == 0 ) {
		std::cout << "ClapTrap " << this->_name << " has no energy points to repair itself " << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " has no hit points to repair itself " << std::endl;
		return ;
	}
	_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << GREEN << " repaired " << RESET << amount << " of hit points and now has "
	<< this->_hitPoints << " hit points!"<< std::endl;
}


