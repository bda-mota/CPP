#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	return 0;
}