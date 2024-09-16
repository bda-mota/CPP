#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main()
{
	{
		std::cout << YELLOW << "\n--- Test: Human A (weapon mandatory) ---\n" << RESET;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << YELLOW << "\n--- Test: Human B ---\n" << RESET;
		Weapon club = Weapon("shotgun");
		HumanB jim("Sam");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << YELLOW << "\n--- Test: Human B (no weapon) ---\n" << RESET;
		Weapon colt = Weapon("colt");
		HumanB dean("Dean");
		dean.attack();
		dean.setWeapon(colt);
		dean.attack();
	}
	std::cout << std::endl;

	return 0;
}
