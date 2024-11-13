#include "../includes/Base.hpp"

Base*	generate(void) {
	static bool onlyOne = true;

	if (onlyOne) {
		std::srand(std::time(0));
		onlyOne = false;
	}

	switch ( rand() % 3 )
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
	if (isA(p)) {
		std::cout << "is base A" << std::endl;
	} else if (isB(p)) {
		std::cout << "is base B" << std::endl;
	} else if (isC(p)) {	
		std::cout << "is base C" << std::endl;
	} else  {
		std::cout << "is invalid base" << std::endl;
	} 
}

void	identify(Base& p) {
	if (isA(p)) {
		std::cout << "is base A" << std::endl;
	} else if (isB(p)) {
		std::cout << "is base B" << std::endl;
	} else if (isC(p)) {
		std::cout << "is base C" << std::endl;
	} else  {
		std::cout << "is invalid base" << std::endl;
	} 
}

Base::~Base( void ) {}