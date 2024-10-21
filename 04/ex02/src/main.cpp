#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

int main()
{
	std::cout << YELLOW << " * * * Test * * *" << RESET << std::endl;
	//Trying create a Animal (abstract class) 
	//AAnimal animal;

	std::cout << MAGENT << "Creating a Dog and a Cat" << RESET << std::endl;
	Dog* dog = new Dog();
	Cat* cat = new Cat();

	std::cout << "Animal Type: " << dog->getType() << " makes sound: ";
	dog->makeSound();

	std::cout << "Animal Type: " << cat->getType() << " makes sound: ";
	cat->makeSound();

	delete dog;
	delete cat;
	return 0;
}