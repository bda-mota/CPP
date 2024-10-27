#include "../includes/Intern.hpp"

Intern::Intern( void ){
	std::cout  << "Intern is available."  << std::endl;
}

Intern::Intern( const Intern &other ) { 
	*this = other;
}

Intern& Intern::operator=( const Intern &other ) { 
	(void)other;
	return *this;
}

Intern::~Intern( void ) {};

AForm	*Intern::makeForm(const std::string formName, const std::string target) {

}