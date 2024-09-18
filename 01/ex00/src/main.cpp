#include "../includes/Zombie.hpp"

int main(void)
{
	std::cout << YELLOW << "\n--- Test: Creating Zombie locally with randomChump (stack)---\n" << RESET;
	randomChump("LocalZombie");

	std::cout << YELLOW << "\n--- Test: Creating Zombie dynamically with newZombie (heap) ---\n" << RESET;
	Zombie* dynamicZombie = newZombie("DynamicZombie");
	dynamicZombie->announce();
	delete dynamicZombie;

	std::cout << YELLOW << "\n--- Test: Creating another Zombie locally (stack)---\n" << RESET;
	Zombie stackZombie("StackZombie");
	stackZombie.announce();

	std::cout << std::endl;
	return 0;
}
