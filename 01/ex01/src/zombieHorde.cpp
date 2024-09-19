#include "../includes/Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	if (N <= 0) {
		std::cout << RED << "Cannot create an empty zombie horde" << RESET << std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N ; i++) {
		horde[i].setName(name);
		std::cout << "The Zombie " << GREEN << name << RESET << " was born." << std::endl;
	}
	return horde;
}
