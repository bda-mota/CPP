#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void)
{
	std::cout << BLUE << "* * * CREATING SCAVTRAP * * *" << RESET << std::endl;
	ScavTrap ScavTrap1("CARAMEL");
	ScavTrap ScavTrap2("jorge");

	std::cout << BLUE << "* * * ATTACKING SCAVTRAP * * *" << RESET << std::endl;
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap2.beRepaired(5);
	ScavTrap2.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ScavTrap2.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap2.beRepaired(5);
	ScavTrap2.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ScavTrap2.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap2.beRepaired(5);
	ScavTrap2.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ScavTrap2.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap2.beRepaired(5);
	ScavTrap2.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ScavTrap2.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap2.beRepaired(5);
	ScavTrap2.attack(ScavTrap1.getName());
	ScavTrap1.takeDamage(ScavTrap2.getAttackDamage());
	ScavTrap1.beRepaired(5);
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap1.attack(ScavTrap2.getName());
	ScavTrap2.takeDamage(ScavTrap1.getAttackDamage());
	ScavTrap1.guardGate();
	ScavTrap2.attack(ScavTrap1.getName());

	return (0);
}
