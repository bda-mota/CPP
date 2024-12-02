#include "../includes/Base.hpp"

Base*	generate(void) {
	static bool onlyOne = true;

	if (onlyOne) {
		std::srand(std::time(0));
		onlyOne = false;
	}

	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "is base A (pointer)." << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "is base B (pointer)." << std::endl;
	} else if (dynamic_cast<C*>(p)) {	
		std::cout << "is base C (pointer)." << std::endl;
	} else  {
		std::cout << RED << "dinamic_cast returned null, so is invalid base (pointer)." << RESET << std::endl;
	} 
}

void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "is base A (reference)." << std::endl; 
		return ;
	} catch (const std::exception& e) {}

	try {
		dynamic_cast<B&>(p);
		std::cout << "is base B (reference)." << std::endl; 
		return ;
	} catch (const std::exception& e) {}

	try {
		dynamic_cast<C&>(p);
		std::cout << "is base C (reference)." << std::endl; 
		return ;
	} catch (const std::exception& e) {}
 
	std::cout << RED << "is invalid base (reference)." << RESET << std::endl;
}

Base::~Base(void) {}