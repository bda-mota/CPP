#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

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

		Dog anotherDog;
		std::cout << MAGENT << "Assignment " << RESET << std::endl;
		anotherDog = dog;
		std::cout << "Another Dog Type: " << anotherDog.getType() << std::endl;
		anotherDog.makeSound();
	}
    return 0;
}