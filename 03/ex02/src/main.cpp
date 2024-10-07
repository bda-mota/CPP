#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"

int	main(void)
{
	std::cout << BLUE << "CREATING CLAPTRAP" << RESET << std::endl;
	ClapTrap ClapTrap1("JUAN");
	std::cout << BLUE << "CREATING SCAVTRAP" << RESET << std::endl;
	ScavTrap ScavTrap1("CARAMEL");
	std::cout << BLUE << "CREATING FRAGTRAP" << RESET << std::endl;
	FragTrap FragTrap1("TOKAKI");

	std::cout << BLUE << "ATTACKING CLAPTRAP" << RESET << std::endl;
	ClapTrap1.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ClapTrap1.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ClapTrap1.getName());
	ClapTrap1.takeDamage(ScavTrap1.getAttackDamage());
	ClapTrap1.beRepaired(5);
	ClapTrap1.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ClapTrap1.getAttackDamage());
	std::cout << BLUE << "ATTACKING SCAVTRAP" << RESET << std::endl;
	ScavTrap1.attack(FragTrap1.getName());
	FragTrap1.takeDamage(ScavTrap1.getAttackDamage());
	FragTrap1.beRepaired(5);
	FragTrap1.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(FragTrap1.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(FragTrap1.getName());
	FragTrap1.takeDamage(ScavTrap1.getAttackDamage());
	std::cout << BLUE << "ATTACKING FRAGTRAP" << RESET << std::endl;
	FragTrap1.attack(ClapTrap1.getName());
	ClapTrap1.takeDamage(FragTrap1.getAttackDamage());
	ClapTrap1.beRepaired(5);
	ClapTrap1.attack(FragTrap1.getName());
	FragTrap1.takeDamage(ClapTrap1.getAttackDamage());
	ClapTrap1.beRepaired(5);
	std::cout << BLUE << "./includes/FragTrap.hpp" << "WE ARE FRIEND GUYS" << RESET << std::endl;
	ScavTrap1.guardGate();
	FragTrap1.highFivesGuys();
	FragTrap1.highFivesGuys();
	FragTrap1.highFivesGuys();
	FragTrap1.highFivesGuys();
	return (0);
}
