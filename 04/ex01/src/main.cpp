#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

int main()
{
	{
		std::cout << YELLOW << " * * * Test 1: Subject  * * * " << RESET << std::endl;
		std::cout << MAGENT << "Create Dog" << RESET << std::endl;
		const Animal* j = new Dog();
		std::cout << MAGENT << "Create Cat" << RESET << std::endl;
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << YELLOW << " * * * Test 2: Array  * * * " << RESET << std::endl;
		const int animalCount = 10;
		Animal* animals[animalCount];

			std::cout << MAGENT << "Creating Dogs" << RESET << std::endl;
		for (int i = 0; i < animalCount / 2; ++i) {
			animals[i] = new Dog();
		}
		std::cout << MAGENT << "Creating Cats" << RESET << std::endl;
		for (int i = animalCount / 2; i < animalCount; ++i) {
			animals[i] = new Cat();
		}
		std::cout << CYAN << "--- Deleting Animals ---" << RESET << std::endl;
		for (int i = 0; i < animalCount; ++i) {
			delete animals[i];
		}
	}
	{
		std::cout << YELLOW << " * * * Test 3: Deep Copy With Assignment * * *" << RESET << std::endl;
		Dog originalDog;
		originalDog.getBrain()->setBrain("Original Idea", 0);

		std::cout << MAGENT << "Create a copy of OriginalDog" << RESET << std::endl;
		Dog copyDog = originalDog;
		std::cout << "Original Dog Brain: " << originalDog.getBrain()->getBrain(0) << std::endl;
		std::cout << "Copy Dog Brain: " << copyDog.getBrain()->getBrain(0) << std::endl;

		std::cout << MAGENT << "Change Idea" << RESET << std::endl;
		originalDog.getBrain()->setBrain("Changed Idea", 0);
		std::cout << "After change - Original Dog Brain: " << originalDog.getBrain()->getBrain(0) << std::endl;
		std::cout << "After change - Copy Dog Brain: " << copyDog.getBrain()->getBrain(0) << std::endl;
	}
	{
		std::cout << YELLOW << " * * * Test 4: Deep Copy With Copy Constructor * * *" << RESET << std::endl;

		Dog originalDog;
		originalDog.getBrain()->setBrain("Original Idea", 0);

		std::cout << MAGENT << "Creating a copy of OriginalDog" << RESET << std::endl;
		Dog copyDog(originalDog);

		std::cout << "Original Dog Brain: " << originalDog.getBrain()->getBrain(0) << std::endl;
		std::cout << "Copy Dog Brain: " << copyDog.getBrain()->getBrain(0) << std::endl;

		std::cout << MAGENT << "Changing Idea" << RESET << std::endl;
		originalDog.getBrain()->setBrain("Changed Idea", 0);

		std::cout << "After change - Original Dog Brain: " << originalDog.getBrain()->getBrain(0) << std::endl;
		std::cout << "After change - Copy Dog Brain: " << copyDog.getBrain()->getBrain(0) << std::endl;
	}
	return 0;
}