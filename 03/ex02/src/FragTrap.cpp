#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called | " << this->_name << " hit points: " << this->_hitPoints << ", energy points: "
	<< this->_energyPoints << ", attack damage: " << this->_attackDamage << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called | " << this->_name << " hit points: " << this->_hitPoints << ", energy points: "
	<< this->_energyPoints << ", attack damage: " << this->_attackDamage << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	FragTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0) {
		std::cout << GREEN << "FragTrap " << RESET << this->_name << " has no energy to attack " << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0) {
		std::cout << GREEN << "FragTrap " << RESET << this->_name << " is died and can't attack " << std::endl;
		return ;
	}
	std::cout << GREEN << "FragTrap " << RESET << this->_name << RED <<" attacks " << RESET << target << ", causing "
	<< this->_attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	FragTrap::highFivesGuys( void ) {
	if (_hitPoints > 0)
		std::cout << GREEN << "FragTrap " << RESET << this->_name << " request a high Five!!!" << std::endl;
	else
		std::cout << RED << "FragTrap " << RESET << this->_name << " is died and can't request high five" << std::endl;
}

