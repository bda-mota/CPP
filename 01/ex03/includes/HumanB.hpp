#ifndef HUMAN_B
# define HUMAN_B

# include "Weapon.hpp"

class	HumanB {

public:

	HumanB(const std::string& name);
	~HumanB();

	void	setWeapon(Weapon& typeWeapon);
	void	attack();

private:

	std::string	_name;
	Weapon		*_weapon;

};

#endif
