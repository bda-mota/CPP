#include "../includes/Zombie.hpp"

int main(void)
{
	int	N = 8;
	std::cout << YELLOW << "\n--- Test: Creating a horde of Zombies ---\n\n" << RESET;
	Zombie* arrayHorde = zombieHorde(8, "horde");

	if (arrayHorde) {

		for (int i = 0; i < N; i++) {
			arrayHorde[i].announce();
		}

		delete [] arrayHorde;
	}

	std::cout << YELLOW << "\n--- Test: Creating an empty zombie horde ---\n\n" << RESET;
	Zombie* emptyHorde = zombieHorde(0, "horde");
	if (emptyHorde) {

		for (int i = 0; i < N; i++) {
			emptyHorde[i].announce();
		}

		delete [] emptyHorde;
	}

	std::cout << std::endl;
	return 0;
}
