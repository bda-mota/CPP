#include <iostream>
#include "../includes/Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructor Called" << std::endl;
	return ;
}

Contact::~Contact(void) {
	std::cout << "Destructor Called" << std::endl;
	return ;
}

void	Contact::add(void) {
	std::cout << "Member Function Called" << std::endl;
	return ;
}
