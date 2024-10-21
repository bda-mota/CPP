#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	{
		std::cout << YELLOW << " * * * Test 1: Subject * * * " << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		i->makeSound(); 
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout << YELLOW << " * * * Test 2: mix  * * * " << RESET << std::endl;

		std::cout << MAGENT << "Default Constructor" << RESET << std::endl;
		Animal genericAnimal;
		std::cout << "Generic Animal Type: " << genericAnimal.getType() << std::endl;
		genericAnimal.makeSound();

		std::cout << MAGENT << "Cat " << RESET << std::endl;
		Cat cat;
		std::cout << "Cat Type: " << cat.getType() << std::endl;
		cat.makeSound();

		std::cout << MAGENT << "Dog " << RESET << std::endl;
		Dog dog;
		std::cout << "Dog Type: " << dog.getType() << std::endl;
		dog.makeSound();

		std::cout << MAGENT << "Copy of objects " << RESET << std::endl;
		Cat anotherCat(cat);
		std::cout << "Another Cat Type: " << anotherCat.getType() << std::endl;
		anotherCat.makeSound();

		std::cout << MAGENT << "Assignment " << RESET << std::endl;
		Dog anotherDog;
		anotherDog = dog;
		std::cout << "Another Dog Type: " << anotherDog.getType() << std::endl;
		anotherDog.makeSound();
	}
	{
		std::cout << YELLOW << " * * * Test 3: WrongAnimal and WrongCat  * * * " << RESET << std::endl;

		WrongAnimal* animals[4];

		std::cout << MAGENT << "Fill WrongCat..." << RESET << std::endl;
		for (int i = 0; i < 2; i++) {
			animals[i] = new WrongCat();
		}

		std::cout << MAGENT << "Fill WrongAnimal..." << RESET << std::endl;
		for (int i = 2; i < 4; i++) {
			animals[i] = new WrongAnimal();
		}

		std::cout << MAGENT << "Make sound..." << RESET << std::endl;
		for (int i = 0; i < 4; i++) {
			animals[i]->makeSound();
		}

		std::cout << MAGENT << "Deleting animals..." << RESET << std::endl;
		for (int i = 0; i < 4; i++) {
			delete animals[i];
		}
	}
	{
		std::cout << YELLOW << " * * * Test 4: WrongCat as WrongCat * * * " << RESET << std::endl;
		WrongAnimal* animal = new WrongAnimal();
		WrongCat* cat = new WrongCat();

		std::cout << MAGENT << "Testing WrongAnimal:"<< RESET << std::endl;
		animal->makeSound();

		std::cout << MAGENT << "Testing WrongCat:"<< RESET << std::endl;
		cat->makeSound();

		std::cout << MAGENT << "Testing WrongCat as WrongAnimal:" << RESET << std::endl;
		WrongAnimal* wrongCatAsAnimal = cat;
		wrongCatAsAnimal->makeSound();

		delete animal;
		delete cat;
	}
	return 0;
}